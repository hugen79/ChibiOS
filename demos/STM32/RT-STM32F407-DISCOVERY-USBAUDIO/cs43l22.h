/*
    ChibiOS - Copyright (C) 2006..2015 Giovanni Di Sirio

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

        http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/

#ifndef _CS43L22_H_
#define _CS43L22_H_

#define CS43L22_I2C_ADDRESS 0x4a
#define CS43L22_I2C_TIMEOUT 100

/* Chip I.D. and revision register */
#define CS43L22_REG_GET_ID 0x01
/* Chip I.D. and revision register - Chip identifier */
#define CS43L22_CHIP_ID_MASK 0xf8
/* Chip I.D. and revision register - CS43L22 identifier */
#define CS43L22_CHIP_ID 0xe0
/* Chip I.D. and revision register - Revision level - Mask */
#define CS43L22_CHIP_REV_MASK 0x07
/* Chip I.D. and revision register - Revision level - A1 */
#define CS43L22_CHIP_REV_A1 0x01
/* Chip I.D. and revision register - Revision level - B1 */
#define CS43L22_CHIP_REV_B1 0x03
/* Chip I.D. and revision register - Revision level - A0 */
#define CS43L22_CHIP_REV_A0 0x00
/* Chip I.D. and revision register - Revision level - B0 */
#define CS43L22_CHIP_REV_B0 0x02

/* Power control 1 */
#define CS43L22_REG_PWR_CTL1 0x02
/* Power control 1 - Power up */
#define CS43L22_PWR1_UP 0x9e
/* Power control 1 - Power down */
#define CS43L22_PWR1_DOWN 0x01

/* Power control 2 */
#define CS43L22_REG_PWR_CTL2 0x04
/* Power control 2 - Speaker A - Mask */
#define CS43L22_PWR2_SPKA_MASK 0x03
/* Power control 2 - Speaker A - Enabled if switch high */
#define CS43L22_PWR2_SPKA_SWHI 0x01
/* Power control 2 - Speaker A - Disabled */
#define CS43L22_PWR2_SPKA_OFF 0x03
/* Power control 2 - Speaker A - Enabled if switch low */
#define CS43L22_PWR2_SPKA_SWLO 0x00
/* Power control 2 - Speaker A - Enabled */
#define CS43L22_PWR2_SPKA_ON 0x02
/* Power control 2 - Speaker B - Mask */
#define CS43L22_PWR2_SPKB_MASK 0x0c
/* Power control 2 - Speaker B - Enabled */
#define CS43L22_PWR2_SPKB_ON 0x08
/* Power control 2 - Speaker B - Enabled if switch high */
#define CS43L22_PWR2_SPKB_SWHI 0x04
/* Power control 2 - Speaker B - Enabled if switch low */
#define CS43L22_PWR2_SPKB_SWLO 0x00
/* Power control 2 - Speaker B - Disabled */
#define CS43L22_PWR2_SPKB_OFF 0x0c
/* Power control 2 - Headphone A - Mask */
#define CS43L22_PWR2_HDA_MASK 0x30
/* Power control 2 - Headphone A - Enabled */
#define CS43L22_PWR2_HDA_ON 0x20
/* Power control 2 - Headphone A - Enabled if switch low */
#define CS43L22_PWR2_HDA_SWLO 0x00
/* Power control 2 - Headphone A - Enabled if switch high */
#define CS43L22_PWR2_HDA_SWHI 0x10
/* Power control 2 - Headphone A - Disabled */
#define CS43L22_PWR2_HDA_OFF 0x30
/* Power control 2 - Headphone B - Mask */
#define CS43L22_PWR2_HDB_MASK 0xc0
/* Power control 2 - Headphone B - Enabled */
#define CS43L22_PWR2_HDB_ON 0x80
/* Power control 2 - Headphone B - Enabled if switch high */
#define CS43L22_PWR2_HDB_SWHI 0x40
/* Power control 2 - Headphone B - Enabled if switch low */
#define CS43L22_PWR2_HDB_SWLO 0x00
/* Power control 2 - Headphone B - Disabled */
#define CS43L22_PWR2_HDB_OFF 0xc0

/* Clocking control */
#define CS43L22_REG_CLOCK_CTL 0x05
/* Clocking control - Autodetection - Enabled */
#define CS43L22_CLK_AUTO_ON 0x80
/* Clocking control - Autodetection - Disabled */
#define CS43L22_CLK_AUTO_OFF 0x00
/* Clocking control - Speed mode - Mask */
#define CS43L22_CLK_SPD_MASK 0x60
/* Clocking control - Speed mode - Single speed */
#define CS43L22_CLK_SPD_SSM 0x20
/* Clocking control - Speed mode - Half speed */
#define CS43L22_CLK_SPD_HSM 0x40
/* Clocking control - Speed mode - Double speed */
#define CS43L22_CLK_SPD_DSM 0x00
/* Clocking control - Speed mode - Quarter speed */
#define CS43L22_CLK_SPD_QSM 0x60
/* Clocking control - 32KHz group - Disabled */
#define CS43L22_CLK_32K_OFF 0x00
/* Clocking control - 32KHz group - Enabled */
#define CS43L22_CLK_32K_ON 0x10
/* Clocking control - 27MHz video clock - Enabled */
#define CS43L22_CLK_VC_ON 0x08
/* Clocking control - 27MHz video clock - Disabled */
#define CS43L22_CLK_VC_OFF 0x00
/* Clocking control - Internal MCLK/LRCK ratio - Mask */
#define CS43L22_CLK_MLR_MASK 0x06
/* Clocking control - Internal MCLK/LRCK ratio - 68 */
#define CS43L22_CLK_MLR_68 0x06
/* Clocking control - Internal MCLK/LRCK ratio - 66 */
#define CS43L22_CLK_MLR_66 0x04
/* Clocking control - Internal MCLK/LRCK ratio - 64 */
#define CS43L22_CLK_MLR_64 0x00
/* Clocking control - Internal MCLK/LRCK ratio - 62 */
#define CS43L22_CLK_MLR_62 0x02
/* Clocking control - Master clock /= 2 - Enabled */
#define CS43L22_CLK_MCDIV_ON 0x01
/* Clocking control - Master clock /= 2 - Disabled */
#define CS43L22_CLK_MCDIV_OFF 0x00

/* Interface control 1 */
#define CS43L22_REG_INT_CTL1 0x06
/* Interface control 1 - Slave mode */
#define CS43L22_IC1_SLAVE 0x00
/* Interface control 1 - Master mode */
#define CS43L22_IC1_MASTER 0x80
/* Interface control 1 - SCLK inverted polarity - Enabled */
#define CS43L22_IC1_SCPOL_ON 0x40
/* Interface control 1 - SCLK inverted polarity - Disabled */
#define CS43L22_IC1_SCPOL_OFF 0x00
/* Interface control 1 - DSP - Disabled */
#define CS43L22_IC1_DSP_OFF 0x00
/* Interface control 1 - DSP - Enabled */
#define CS43L22_IC1_DSP_ON 0x10
/* Interface control 1 - DAC interface format - Right-justified */
#define CS43L22_IC1_DIF_RJ 0x08
/* Interface control 1 - DAC interface format - I2S, up to 24 bits */
#define CS43L22_IC1_DIF_I2S 0x04
/* Interface control 1 - DAC interface format - Left-justified, up to 24 bits */
#define CS43L22_IC1_DIF_LJ 0x00
/* Interface control 1 - Audio word length - 24-bit (DSP), 20-bit (RJ) */
#define CS43L22_IC1_AWL_24 0x01
/* Interface control 1 - Audio word length - 16-bit (DSP), 16-bit (RJ) */
#define CS43L22_IC1_AWL_16 0x03
/* Interface control 1 - Audio word length - 32-bit (DSP), 24-bit (RJ) */
#define CS43L22_IC1_AWL_32 0x00
/* Interface control 1 - Audio word length - 20-bit (DSP), 18-bit (RJ) */
#define CS43L22_IC1_AWL_20 0x02

/* Interface control 2 */
#define CS43L22_REG_INT_CTL2 0x07
/* Interface control 2 - SCLK = MCLK? - Equal */
#define CS43L22_IC2_SEM_ON 0x40
/* Interface control 2 - SCLK = MCLK? - Derived */
#define CS43L22_IC2_SEM_OFF 0x00
/* Interface control 2 - Speaker/Headphone switch invert - Enabled */
#define CS43L22_IC2_SHSI_ON 0x08
/* Interface control 2 - Speaker/Headphone switch invert - Disabled */
#define CS43L22_IC2_SHSI_OFF 0x00

/* Passthrough A select */
#define CS43L22_REG_PSELA 0x08
/* Passthrough A select - Mask */
#define CS43L22_PSELA_MASK 0x0f
/* Passthrough A select - AIN4 */
#define CS43L22_PSELA_AIN4 0x08
/* Passthrough A select - AIN3 */
#define CS43L22_PSELA_AIN3 0x04
/* Passthrough A select - AIN1 */
#define CS43L22_PSELA_AIN1 0x01
/* Passthrough A select - NONE */
#define CS43L22_PSELA_NONE 0x00
/* Passthrough A select - AIN2 */
#define CS43L22_PSELA_AIN2 0x02

/* Passthrough B select */
#define CS43L22_REG_PSELB 0x09
/* Passthrough B select - Mask */
#define CS43L22_PSELB_MASK 0x0f
/* Passthrough B select - AIN4 */
#define CS43L22_PSELB_AIN4 0x08
/* Passthrough B select - AIN3 */
#define CS43L22_PSELB_AIN3 0x04
/* Passthrough B select - AIN1 */
#define CS43L22_PSELB_AIN1 0x01
/* Passthrough B select - NONE */
#define CS43L22_PSELB_NONE 0x00
/* Passthrough B select - AIN2 */
#define CS43L22_PSELB_AIN2 0x02

/* Analog zero cross / soft ramp */
#define CS43L22_REG_AZCSR 0x0a
/* Analog zero cross / soft ramp - Channel B soft ramp - Enabled */
#define CS43L22_AZCSR_SRB_ON 0x08
/* Analog zero cross / soft ramp - Channel B soft ramp - Disabled */
#define CS43L22_AZCSR_SRB_OFF 0x00
/* Analog zero cross / soft ramp - Channel A soft ramp - Enabled */
#define CS43L22_AZCSR_SRA_ON 0x04
/* Analog zero cross / soft ramp - Channel A soft ramp - Disabled */
#define CS43L22_AZCSR_SRA_OFF 0x00
/* Analog zero cross / soft ramp - Channel B zero cross - Disabled */
#define CS43L22_AZCSR_ZCB_OFF 0x00
/* Analog zero cross / soft ramp - Channel B zero cross - Enabled */
#define CS43L22_AZCSR_ZCB_ON 0x02
/* Analog zero cross / soft ramp - Channel A zero cross - Enabled */
#define CS43L22_AZCSR_ZCA_ON 0x01
/* Analog zero cross / soft ramp - Channel A zero cross - Disabled */
#define CS43L22_AZCSR_ZCA_OFF 0x00

/* Passthrough gang control */
#define CS43L22_REG_PGC 0x0c
/* Passthrough gang control - Enabled */
#define CS43L22_PGC_ON 0x80
/* Passthrough gang control - Disabled */
#define CS43L22_PGC_OFF 0x00

/* Playback control 1 */
#define CS43L22_REG_PB_CTL1 0x0d
/* Playback control 1 - Headphone analog gain - Mask */
#define CS43L22_PB1_HGAIN_MASK 0xe0
/* Playback control 1 - Ganged volume control - Disabled */
#define CS43L22_PB1_SAMEVOLUME_OFF 0x00
/* Playback control 1 - Ganged volume control - Enabled */
#define CS43L22_PB1_SAMEVOLUME_ON 0x10
/* Playback control 1 - Invert channel B polarity - Enabled */
#define CS43L22_PB1_INVB_ON 0x08
/* Playback control 1 - Invert channel B polarity - Disabled */
#define CS43L22_PB1_INVB_OFF 0x00
/* Playback control 1 - Invert channel A polarity - Enabled */
#define CS43L22_PB1_INVA_ON 0x04
/* Playback control 1 - Invert channel A polarity - Disabled */
#define CS43L22_PB1_INVA_OFF 0x00
/* Playback control 1 - Channel B muted - Disabled */
#define CS43L22_PB1_MUTEB_OFF 0x00
/* Playback control 1 - Channel B muted - Enabled */
#define CS43L22_PB1_MUTEB_ON 0x02
/* Playback control 1 - Channel A muted - Enabled */
#define CS43L22_PB1_MUTEA_ON 0x01
/* Playback control 1 - Channel A muted - Disabled */
#define CS43L22_PB1_MUTEA_OFF 0x00

/* Miscellaneous controls */
#define CS43L22_REG_MISC_CTL 0x0e
/* Miscellaneous controls - Passthrough analog B - Enabled */
#define CS43L22_MISC_PTHRUB_ON 0x80
/* Miscellaneous controls - Passthrough analog B - Disabled */
#define CS43L22_MISC_PTHRUB_OFF 0x00
/* Miscellaneous controls - Passthrough analog A - Enabled */
#define CS43L22_MISC_PTHRUA_ON 0x40
/* Miscellaneous controls - Passthrough analog A - Disabled */
#define CS43L22_MISC_PTHRUA_OFF 0x00
/* Miscellaneous controls - Passthrough mute B - Enabled */
#define CS43L22_MISC_PTMUTEB_ON 0x20
/* Miscellaneous controls - Passthrough mute B - Disabled */
#define CS43L22_MISC_PTMUTEB_OFF 0x00
/* Miscellaneous controls - Passthrough mute A - Disabled */
#define CS43L22_MISC_PTMUTEA_OFF 0x00
/* Miscellaneous controls - Passthrough mute A - Enabled */
#define CS43L22_MISC_PTMUTEA_ON 0x10
/* Miscellaneous controls - Freeze registers - Enabled */
#define CS43L22_MISC_FREEZE_ON 0x08
/* Miscellaneous controls - Freeze registers - Disabled */
#define CS43L22_MISC_FREEZE_OFF 0x00
/* Miscellaneous controls - De-emphasis filter - Enabled */
#define CS43L22_MISC_DEEMPHASIS_ON 0x04
/* Miscellaneous controls - De-emphasis filter - Disabled */
#define CS43L22_MISC_DEEMPHASIS_OFF 0x00
/* Miscellaneous controls - Digital soft ramp - Disabled */
#define CS43L22_MISC_DSR_OFF 0x00
/* Miscellaneous controls - Digital soft ramp - Enabled */
#define CS43L22_MISC_DSR_ON 0x02
/* Miscellaneous controls - Digital zero cross - Enabled */
#define CS43L22_MISC_DZC_ON 0x01
/* Miscellaneous controls - Digital zero cross - Disabled */
#define CS43L22_MISC_DZC_OFF 0x00

/* Playback control 2 */
#define CS43L22_REG_PB_CTL2 0x0f
/* Playback control 2 - Headphone B mute - Enabled */
#define CS43L22_PB2_HPB_MUTE_ON 0x80
/* Playback control 2 - Headphone B mute - Disabled */
#define CS43L22_PB2_HPB_MUTE_OFF 0x00
/* Playback control 2 - Headphone A mute - Enabled */
#define CS43L22_PB2_HPA_MUTE_ON 0x40
/* Playback control 2 - Headphone A mute - Disabled */
#define CS43L22_PB2_HPA_MUTE_OFF 0x00
/* Playback control 2 - Speaker B mute - Enabled */
#define CS43L22_PB2_SPKB_MUTE_ON 0x20
/* Playback control 2 - Speaker B mute - Disabled */
#define CS43L22_PB2_SPKB_MUTE_OFF 0x00
/* Playback control 2 - Speaker A mute - Disabled */
#define CS43L22_PB2_SPKA_MUTE_OFF 0x00
/* Playback control 2 - Speaker A mute - Enabled */
#define CS43L22_PB2_SPKA_MUTE_ON 0x10
/* Playback control 2 - Ganged speaker volume settings - Enabled */
#define CS43L22_PB2_SPK_GANG_ON 0x08
/* Playback control 2 - Ganged speaker volume settings - Disabled */
#define CS43L22_PB2_SPK_GANG_OFF 0x00
/* Playback control 2 - Speaker channel swap - Enabled */
#define CS43L22_PB2_SPK_SWAP_ON 0x04
/* Playback control 2 - Speaker channel swap - Disabled */
#define CS43L22_PB2_SPK_SWAP_OFF 0x00
/* Playback control 2 - Speaker mono mode - Disabled */
#define CS43L22_PB2_SPK_MONO_OFF 0x00
/* Playback control 2 - Speaker mono mode - Enabled */
#define CS43L22_PB2_SPK_MONO_ON 0x02
/* Playback control 2 - Speaker mute 50/50 control - Enabled */
#define CS43L22_PB2_SPK_M50_ON 0x01
/* Playback control 2 - Speaker mute 50/50 control - Disabled */
#define CS43L22_PB2_SPK_M50_OFF 0x00

/* Passthrough volume (channel A) */
#define CS43L22_REG_PASS_A_VOL 0x14

/* Passthrough volume (channel B) */
#define CS43L22_REG_PASS_B_VOL 0x15

/* PCM channel A control */
#define CS43L22_REG_PCM_A 0x1a
/* PCM channel A control - Mute channel - Enabled */
#define CS43L22_PCM_A_MUTE_ON 0x80
/* PCM channel A control - Mute channel - Disabled */
#define CS43L22_PCM_A_MUTE_OFF 0x00
/* PCM channel A control - Channel volume - Mask */
#define CS43L22_PCM_A_VOLUME_MASK 0x7f

/* PCM channel B control */
#define CS43L22_REG_PCM_B 0x1b
/* PCM channel B control - Mute channel - Enabled */
#define CS43L22_PCM_B_MUTE_ON 0x80
/* PCM channel B control - Mute channel - Disabled */
#define CS43L22_PCM_B_MUTE_OFF 0x00
/* PCM channel B control - Channel volume - Mask */
#define CS43L22_PCM_B_VOLUME_MASK 0x7f

/* Beep control 1 */
#define CS43L22_REG_BEEP_CTL1 0x1c
/* Beep control 1 - Frequency - Mask */
#define CS43L22_BEEP_FREQ_MASK 0xf0
/* Beep control 1 - Duration - Mask */
#define CS43L22_BEEP_ONTIME_MASK 0x0f

/* Beep control 2 */
#define CS43L22_REG_BEEP_CTL2 0x1d
/* Beep control 2 - Off time - Mask */
#define CS43L22_BEEP_OFFTIME_MASK 0xf0
/* Beep control 2 - Volume - Mask */
#define CS43L22_BEEP_VOL_MASK 0x0f

/* Beep & tone configuration */
#define CS43L22_REG_BEEP_TONE_CFG 0x1e
/* Beep & tone configuration - Beep configuration - Multiple */
#define CS43L22_B3_BEEP_CFG_MULTI 0x80
/* Beep & tone configuration - Beep configuration - Single */
#define CS43L22_B3_BEEP_CFG_SINGLE 0x40
/* Beep & tone configuration - Beep configuration - Off */
#define CS43L22_B3_BEEP_CFG_OFF 0x00
/* Beep & tone configuration - Beep configuration - Continuous */
#define CS43L22_B3_BEEP_CFG_CONT 0xc0
/* Beep & tone configuration - Beep mix disable - OFF */
#define CS43L22_B3_BEEP_NOMIX_OFF 0x20
/* Beep & tone configuration - Beep mix disable - ON */
#define CS43L22_B3_BEEP_NOMIX_ON 0x00
/* Beep & tone configuration - Treble corner frequency - 7KHZ */
#define CS43L22_B3_TREBLE_CF_7KHZ 0x08
/* Beep & tone configuration - Treble corner frequency - 5KHZ */
#define CS43L22_B3_TREBLE_CF_5KHZ 0x00
/* Beep & tone configuration - Treble corner frequency - 15KHZ */
#define CS43L22_B3_TREBLE_CF_15KHZ 0x18
/* Beep & tone configuration - Treble corner frequency - 10KHZ */
#define CS43L22_B3_TREBLE_CF_10KHZ 0x10
/* Beep & tone configuration - Bass corner frequency - 250HZ */
#define CS43L22_B3_BASS_CF_250HZ 0x06
/* Beep & tone configuration - Bass corner frequency - 200HZ */
#define CS43L22_B3_BASS_CF_200HZ 0x04
/* Beep & tone configuration - Bass corner frequency - 50HZ */
#define CS43L22_B3_BASS_CF_50HZ 0x00
/* Beep & tone configuration - Bass corner frequency - 100HZ */
#define CS43L22_B3_BASS_CF_100HZ 0x02
/* Beep & tone configuration - Tone control - Enabled */
#define CS43L22_B3_TONECTL_ON 0x01
/* Beep & tone configuration - Tone control - Disabled */
#define CS43L22_B3_TONECTL_OFF 0x00

/* Tone control */
#define CS43L22_REG_TONE_CTL 0x1f
/* Tone control - Treble gain - Mask */
#define CS43L22_TCTL_TREBLE_MASK 0xf0
/* Tone control - Bass gain - Mask */
#define CS43L22_TCTL_BASS_MASK 0x0f

/* Master volume control (channel A) */
#define CS43L22_REG_MASTER_VOLUME_A 0x20

/* Master volume control (channel B) */
#define CS43L22_REG_MASTER_VOLUME_B 0x21

/* Headphone volume control (channel A) */
#define CS43L22_REG_HP_VOLUME_A 0x22

/* Headphone volume control (channel B) */
#define CS43L22_REG_HP_VOLUME_B 0x23

/* Speaker volume control (channel A) */
#define CS43L22_REG_SPK_VOLUME_A 0x24

/* Speaker volume control (channel B) */
#define CS43L22_REG_SPK_VOLUME_B 0x25

/* PCM channel swap */
#define CS43L22_REG_PCM_SWAP 0x26
/* PCM channel swap - Channel A - (Left + Right) / 2 */
#define CS43L22_PCS_A_MIX 0x40
/* PCM channel swap - Channel A - Left */
#define CS43L22_PCS_A_LEFT 0x00
/* PCM channel swap - Channel A - Right */
#define CS43L22_PCS_A_RIGHT 0xc0
/* PCM channel swap - Channel B - Right */
#define CS43L22_PCS_B_RIGHT 0x00
/* PCM channel swap - Channel B - (Left + Right) / 2 */
#define CS43L22_PCS_B_MIX 0x10
/* PCM channel swap - Channel B - Left */
#define CS43L22_PCS_B_LEFT 0x30

/* Limiter control 1 */
#define CS43L22_REG_LIM_CTL1 0x27
/* Limiter control 1 - Maximum threshold - Mask */
#define CS43L22_LIM1_MAX_MASK 0xe0
/* Limiter control 1 - Cushion threshold - Mask */
#define CS43L22_LIM1_CUSHION_MASK 0x1c
/* Limiter control 1 - Soft ramp - Use digital soft ramp */
#define CS43L22_LIM1_SRD_OFF 0x00
/* Limiter control 1 - Soft ramp - Ignore digital soft ramp */
#define CS43L22_LIM1_SRD_ON 0x02
/* Limiter control 1 - Zero cross - Ignore digital zero cross */
#define CS43L22_LIM1_ZCD_ON 0x01
/* Limiter control 1 - Zero cross - Use digital zero cross */
#define CS43L22_LIM1_ZCD_OFF 0x00

/* Limiter control 2 */
#define CS43L22_REG_LIM_CTL2 0x28
/* Limiter control 2 - Peak detect and limiter - Enabled */
#define CS43L22_LIM2_ON 0x80
/* Limiter control 2 - Peak detect and limiter - Disabled */
#define CS43L22_LIM2_OFF 0x00
/* Limiter control 2 - Limit both channels - Enabled */
#define CS43L22_LIM2_LAC_ON 0x40
/* Limiter control 2 - Limit both channels - Disabled */
#define CS43L22_LIM2_LAC_OFF 0x00
/* Limiter control 2 - Release rate - Mask */
#define CS43L22_LIM2_RRATE_MASK 0x3f

/* Limiter control 3 */
#define CS43L22_REG_LIM_CTL3 0x29
/* Limiter control 3 - Attack rate - Mask */
#define CS43L22_LIM3_ARATE_MASK 0x3f

/* Status (RO) */
#define CS43L22_REG_STATUS 0x2e
/* Status (RO) - Serial port clock error */
#define CS43L22_STATUS_SERIAL_ERROR 0x40
/* Status (RO) - DSP A overflow */
#define CS43L22_STATUS_DSP_A_OVERFLOW 0x20
/* Status (RO) - DSP B overflow */
#define CS43L22_STATUS_DSP_B_OVERFLOW 0x10
/* Status (RO) - PCM A overflow */
#define CS43L22_STATUS_PCM_A_OVERFLOW 0x08
/* Status (RO) - PCM B overflow */
#define CS43L22_STATUS_PCM_B_OVERFLOW 0x04

/* Battery compensation */
#define CS43L22_REG_BATTERY_COMPENSATION 0x2f
/* Battery compensation - Enabled */
#define CS43L22_BC_ON 0x80
/* Battery compensation - Disabled */
#define CS43L22_BC_OFF 0x00
/* Battery compensation - VP voltage level monitor - Enabled */
#define CS43L22_BC_VPM_ON 0x40
/* Battery compensation - VP voltage level monitor - Disabled */
#define CS43L22_BC_VPM_OFF 0x00
/* Battery compensation - VP reference - Mask */
#define CS43L22_BC_VPREF_MASK 0x0f

/* Battery level (RO) */
#define CS43L22_REG_BATTERY_LEVEL 0x30

/* Speaker status (RO) */
#define CS43L22_REG_SPKR_STATUS 0x31
/* Speaker status (RO) - Channel A overload detected */
#define CS43L22_SPKS_OVERLOAD_A 0x20
/* Speaker status (RO) - Channel B overload detected */
#define CS43L22_SPKS_OVERLOAD_B 0x10
/* Speaker status (RO) - Speaker/headphones pin status */
#define CS43L22_SPKS_SPKHP_SWITCH   0x08

/* Charge pump frequency */
#define CS43L22_REG_CPFREQ 0x34
/* Charge pump frequency - Mask */
#define CS43L22_CPFREQ_MASK 0xf0

#endif // _CS43L22_H_

