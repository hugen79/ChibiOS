#include "audio_dac.h"
#include "cs43l22.h"

void cs43l22_write(I2CDriver *i2cp, uint8_t reg , uint8_t value) {
  uint8_t buf[2];
  buf[0] = reg;
  buf[1] = value;
  i2cMasterTransmitTimeout(i2cp, CS43L22_I2C_ADDRESS, buf, 2, NULL, 0,
                           CS43L22_I2C_TIMEOUT);
}

uint8_t cs43l22_read(I2CDriver *i2cp, uint8_t reg) {
    uint8_t data = 0;
    i2cMasterTransmitTimeout(i2cp, CS43L22_I2C_ADDRESS, &reg, 1, &data, 1,
                             CS43L22_I2C_TIMEOUT);
    return data;
}

void audio_dac_start(audio_state_t *ap) {
  uint8_t d;

  palSetPad(GPIOD, GPIOD_RESET);

  /* Some magic, from CS43L22 datasheet */
  cs43l22_write(ap->config->i2cp, 0x00, 0x99);
  cs43l22_write(ap->config->i2cp, 0x47, 0x80);
  d = cs43l22_read(ap->config->i2cp, 0x32);
  cs43l22_write(ap->config->i2cp, 0x32, d | 0x80);
  d = cs43l22_read(ap->config->i2cp, 0x32);
  cs43l22_write(ap->config->i2cp, 0x32, d & 0x7f);
  cs43l22_write(ap->config->i2cp, 0x00, 0x00);

  cs43l22_write(ap->config->i2cp, CS43L22_REG_PWR_CTL1, CS43L22_PWR1_UP);
  cs43l22_write(ap->config->i2cp, CS43L22_REG_PWR_CTL2, CS43L22_PWR2_SPKA_OFF |
                CS43L22_PWR2_SPKB_OFF | CS43L22_PWR2_HDA_ON |
                CS43L22_PWR2_HDB_ON);
  cs43l22_write(ap->config->i2cp, CS43L22_REG_INT_CTL1, CS43L22_IC1_DIF_I2S |
                CS43L22_IC1_AWL_16);

  audio_dac_update_volume(ap);
}

void audio_dac_stop(audio_state_t *ap) {
  cs43l22_write(ap->config->i2cp, CS43L22_REG_PWR_CTL1, CS43L22_PWR1_DOWN);

  chThdSleepMicroseconds(100);

  palClearPad(GPIOD, GPIOD_RESET);
}

void audio_dac_update_volume(audio_state_t *ap) {
  int8_t vol_l8 = ap->volume[0] / 128;
  int8_t vol_r8 = ap->volume[1] / 128;
  cs43l22_write(ap->config->i2cp, CS43L22_REG_HP_VOLUME_A, *((uint8_t*)&vol_l8));
  cs43l22_write(ap->config->i2cp, CS43L22_REG_HP_VOLUME_B, *((uint8_t*)&vol_r8));
}

void audio_dac_update_mute(audio_state_t *ap) {
  uint8_t pb = 0;
  if (ap->mute[0])
    pb |= CS43L22_PB2_HPA_MUTE_ON;
  if (ap->mute[1])
    pb |= CS43L22_PB2_HPB_MUTE_ON;
  cs43l22_write(ap->config->i2cp, CS43L22_REG_PB_CTL2, pb);
}
