*****************************************************************************
** ChibiOS/HAL - USB-AUDIO driver demo for STM32.                            **
*****************************************************************************

** TARGET **

The demo runs on an ST STM32F4-Discovery board.

** The Demo **

The application demonstrates the use of the STM32 USB (OTG) driver in 
isochronous mode. Application provides playback throught external I2S DAC 
placed on STM32F4-Discovery board (CS43L22) using asynchronous endpoint with 
samplerate feedback. 

** Board Setup **

Connect PC7 (I2S3_MCK) to PA5 (TIM2_CH1_ETR) for samplerate feedback

** Build Procedure **

The demo has been tested using the free Codesourcery GCC-based toolchain
and YAGARTO.
Just modify the TRGT line in the makefile in order to use different GCC ports.

** Notes **

Some files used by the demo are not part of ChibiOS/RT but are copyright of
ST Microelectronics and are licensed under a different license.
Also note that not all the files present in the ST library are distributed
with ChibiOS/RT, you can find the whole library on the ST web site:

                             http://www.st.com
