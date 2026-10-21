/**
 *	@file TLE9186_ServLayer.h
 *	@author Infineon Technologies AG
 *	@date 10.2026
 *	@brief TLE9186 device driver from Infineon Technologies AG.
 *
 ************************************************************************
 *
 * Copyright (c) 2026, Infineon Technologies AG
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 ************************************************************************
 */

#ifndef TLE9186_SERVLAYER_H
#define TLE9186_SERVLAYER_H

/************************************************************************
**                             Includes                                **
************************************************************************/

#include "TLE9186_types.h"

/************************************************************************
**                    Global Variable Definitions                      **
************************************************************************/

#define TLE9186_CRC8_CALC_SEED                                                 \
  0xFFU /**< CRC-8 (according to CRC-8-AUTOSAR and                             \
         * SAEJ1850) seed */
#define TLE9186_CRC8_CALC_GENERATOR_POLYNOM                                    \
  0x1DU /**< CRC-8 (according to CRC-8-AUTOSAR and                             \
         * SAEJ1850) generator polynom value */
#define TLE9186_CRC8_CALC_XOR_VAL                                              \
  0xFFU                         /**< CRC-8 (according to CRC-8-AUTOSAR and     \
                                 * SAEJ1850) xor value */
#define TLE9186_CRC8_USE_LUT 1  /**< use CRC8 lookup table */
#define TLE9186_CRC8_USE_CALC 2 /**< use CRC8 calculation */

#define TLE9186_CRC8_CONF_ALGORITHM                                            \
  TLE9186_CRC8_USE_LUT /**< set configured CRC algorithm */

#define TLE9186_SPI_WRITE 1u /**< SPI write command */
#define TLE9186_SPI_READ 0u  /**< SPI read command */

/************************************************************************
**                    Global Function Definitions                      **
************************************************************************/
void TLE9186_ServLayer_setReg(uint8 u8_address, uint16 u16_data);
void TLE9186_ServLayer_getReg(uint8 u8_address);
void TLE9186_ServLayer_getSpiData(void);
void TLE9186_ServLayer_SpiInterfaceStatus(void);
void TLE9186_ServLayer_InitSpiInterface(void);
void TLE9186_ServLayer_InitGpio(void);
void TLE9186_ServLayer_SetINH_N(uint8 u8_state);
void TLE9186_ServLayer_Wait_us(uint16 u16_wait);
uint8 TLE9186_ServLayer_GetERR_N(void);

#endif /* TLE9166_SERVLAYER_H */
