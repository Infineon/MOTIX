/**
 *  @file TLE9186_HAL.h
 *  @author Infineon Technologies AG
 *  @date 10.2026
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

#ifndef TLE9186_HAL_H
#define TLE9186_HAL_H

/************************************************************************
**                             Includes                                **
************************************************************************/

#include "TLE9186_types.h"

/************************************************************************
**                    Global Function Definitions                      **
************************************************************************/
void TLE9186_HAL_InitSpiPeripheral(void);
void TLE9186_HAL_ReadRxBuffer(uint32 *u32_rxBuffer);
void TLE9186_HAL_TransmitTxBuffer(uint32 u32_txBuffer);
void TLE9186_HAL_Init_INH_N_pin(void);
void TLE9186_HAL_Set_INH_N_pin(uint8 u8_state);
void TLE9186_HAL_Wait_us(uint16 u16_wait);
void TLE9186_HAL_Init_ERR_N_pin(void);
uint8 TLE9186_HAL_SpiStatus(void);
uint8 TLE9186_HAL_Get_ERR_N_pin(void);

#endif /* TLE9186_HAL_H */
