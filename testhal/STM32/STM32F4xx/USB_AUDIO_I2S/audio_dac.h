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

#ifndef _AUDIO_DAC_H_
#define _AUDIO_DAC_H_

#include "hal.h"
#include "audio.h"

/*
 * CS43L22 DAC registers operations
 */
void cs43l22_write(I2CDriver *i2cp, uint8_t reg , uint8_t value);
uint8_t cs43l22_read(I2CDriver *i2cp, uint8_t reg);

/*
 * Start/Stop I2S DAC
 */
void audio_dac_start(audio_state_t *ap);
void audio_dac_stop(audio_state_t *ap);

/*
 * Update volume/mute controls of DAC
 */
void audio_dac_update_volume(audio_state_t *ap);
void audio_dac_update_mute(audio_state_t *ap);

#endif // _AUDIO_DAC_H_
