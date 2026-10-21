/**
 *	@file TLE9186_RegLayer.h
 *	@author Infineon Technologies AG
 *	@date 10.2026
 *	@brief TLE9186 device driver from Infineon Technologies AG.
 *
 ************************************************************************
 *
 * Copyright (c) 2026, Infineon Technologies AG
 *
 * SPDX-License-Identifier: BSD-3-Clause
 *
 ************************************************************************
 */

#ifndef TLE9186_REGLAYER_H
#define TLE9186_REGLAYER_H

/************************************************************************
**                             Includes                                **
************************************************************************/

#include "TLE9186_types.h"

/************************************************************************
**                    Global Function Definitions                      **
************************************************************************/
void TLE9186_RegLayer_init_ShadowRegister(void);
void TLE9186_RegLayer_set_CONFIG_SECURED(uint16 u16_value);
void TLE9186_RegLayer_get_CONFIG_SECURED(void);
void TLE9186_RegLayer_set_PWR_MOD_CFG(uint16 u16_value);
void TLE9186_RegLayer_get_PWR_MOD_CFG(void);
void TLE9186_RegLayer_set_WD_CFG(uint16 u16_value);
void TLE9186_RegLayer_get_WD_CFG(void);
void TLE9186_RegLayer_set_GEN_CFG1(uint16 u16_value);
void TLE9186_RegLayer_get_GEN_CFG1(void);
void TLE9186_RegLayer_set_GEN_CFG2(uint16 u16_value);
void TLE9186_RegLayer_get_GEN_CFG2(void);
void TLE9186_RegLayer_set_GEN_CFG3(uint16 u16_value);
void TLE9186_RegLayer_get_GEN_CFG3(void);
void TLE9186_RegLayer_set_GDRV_CFG1(uint16 u16_value);
void TLE9186_RegLayer_get_GDRV_CFG1(void);
void TLE9186_RegLayer_set_GDRV_CFG2(uint16 u16_value);
void TLE9186_RegLayer_get_GDRV_CFG2(void);
void TLE9186_RegLayer_set_GDRV_CFG3(uint16 u16_value);
void TLE9186_RegLayer_get_GDRV_CFG3(void);
void TLE9186_RegLayer_set_TON_HS(uint16 u16_value);
void TLE9186_RegLayer_get_TON_HS(void);
void TLE9186_RegLayer_set_TON_LS(uint16 u16_value);
void TLE9186_RegLayer_get_TON_LS(void);
void TLE9186_RegLayer_set_TOFF_HS(uint16 u16_value);
void TLE9186_RegLayer_get_TOFF_HS(void);
void TLE9186_RegLayer_set_TOFF_LS(uint16 u16_value);
void TLE9186_RegLayer_get_TOFF_LS(void);
void TLE9186_RegLayer_set_T3OFF(uint16 u16_value);
void TLE9186_RegLayer_get_T3OFF(void);
void TLE9186_RegLayer_set_ION_HS1(uint16 u16_value);
void TLE9186_RegLayer_get_ION_HS1(void);
void TLE9186_RegLayer_set_ION_LS1(uint16 u16_value);
void TLE9186_RegLayer_get_ION_LS1(void);
void TLE9186_RegLayer_set_ION_HS2(uint16 u16_value);
void TLE9186_RegLayer_get_ION_HS2(void);
void TLE9186_RegLayer_set_ION_LS2(uint16 u16_value);
void TLE9186_RegLayer_get_ION_LS2(void);
void TLE9186_RegLayer_set_ION_HS3(uint16 u16_value);
void TLE9186_RegLayer_get_ION_HS3(void);
void TLE9186_RegLayer_set_ION_LS3(uint16 u16_value);
void TLE9186_RegLayer_get_ION_LS3(void);
void TLE9186_RegLayer_set_I3ON(uint16 u16_value);
void TLE9186_RegLayer_get_I3ON(void);
void TLE9186_RegLayer_set_ION_IOFF_DIDT(uint16 u16_value);
void TLE9186_RegLayer_get_ION_IOFF_DIDT(void);
void TLE9186_RegLayer_set_IOFF_HS1(uint16 u16_value);
void TLE9186_RegLayer_get_IOFF_HS1(void);
void TLE9186_RegLayer_set_IOFF_LS1(uint16 u16_value);
void TLE9186_RegLayer_get_IOFF_LS1(void);
void TLE9186_RegLayer_set_IOFF_HS2(uint16 u16_value);
void TLE9186_RegLayer_get_IOFF_HS2(void);
void TLE9186_RegLayer_set_IOFF_LS2(uint16 u16_value);
void TLE9186_RegLayer_get_IOFF_LS2(void);
void TLE9186_RegLayer_set_IOFF_HS3(uint16 u16_value);
void TLE9186_RegLayer_get_IOFF_HS3(void);
void TLE9186_RegLayer_set_IOFF_LS3(uint16 u16_value);
void TLE9186_RegLayer_get_IOFF_LS3(void);
void TLE9186_RegLayer_set_CSA_CFG(uint16 u16_value);
void TLE9186_RegLayer_get_CSA_CFG(void);
void TLE9186_RegLayer_set_FAILURE_CFG(uint16 u16_value);
void TLE9186_RegLayer_get_FAILURE_CFG(void);
void TLE9186_RegLayer_set_SELF_TEST_CFG(uint16 u16_value);
void TLE9186_RegLayer_get_SELF_TEST_CFG(void);
void TLE9186_RegLayer_set_SUP_STAT(uint16 u16_value);
void TLE9186_RegLayer_get_SUP_STAT(void);
void TLE9186_RegLayer_update_SUP_STAT(uint16 u16_value);
void TLE9186_RegLayer_set_SPI_STAT(uint16 u16_value);
void TLE9186_RegLayer_get_SPI_STAT(void);
void TLE9186_RegLayer_update_SPI_STAT(uint16 u16_value);
void TLE9186_RegLayer_set_DEV_STAT1(uint16 u16_value);
void TLE9186_RegLayer_get_DEV_STAT1(void);
void TLE9186_RegLayer_update_DEV_STAT1(uint16 u16_value);
void TLE9186_RegLayer_set_DEV_STAT2(uint16 u16_value);
void TLE9186_RegLayer_get_DEV_STAT2(void);
void TLE9186_RegLayer_update_DEV_STAT2(uint16 u16_value);
void TLE9186_RegLayer_set_LF_STAT(uint16 u16_value);
void TLE9186_RegLayer_get_LF_STAT(void);
void TLE9186_RegLayer_update_LF_STAT(uint16 u16_value);
void TLE9186_RegLayer_get_SH_LEVEL_STAT(void);
void TLE9186_RegLayer_update_SH_LEVEL_STAT(uint16 u16_value);
void TLE9186_RegLayer_set_BD_STAT(uint16 u16_value);
void TLE9186_RegLayer_get_BD_STAT(void);
void TLE9186_RegLayer_update_BD_STAT(uint16 u16_value);
void TLE9186_RegLayer_get_WD_CLK_CNT(void);
void TLE9186_RegLayer_update_WD_CLK_CNT(uint16 u16_value);
void TLE9186_RegLayer_set_PHASE1_CNT(uint16 u16_value);
void TLE9186_RegLayer_get_PHASE1_CNT(void);
void TLE9186_RegLayer_update_PHASE1_CNT(uint16 u16_value);
void TLE9186_RegLayer_set_PHASE2_CNT(uint16 u16_value);
void TLE9186_RegLayer_get_PHASE2_CNT(void);
void TLE9186_RegLayer_update_PHASE2_CNT(uint16 u16_value);
void TLE9186_RegLayer_set_PHASE3_CNT(uint16 u16_value);
void TLE9186_RegLayer_get_PHASE3_CNT(void);
void TLE9186_RegLayer_update_PHASE3_CNT(uint16 u16_value);
void TLE9186_RegLayer_get_TDON_TDOFF_HS1(void);
void TLE9186_RegLayer_update_TDON_TDOFF_HS1(uint16 u16_value);
void TLE9186_RegLayer_get_TDON_TDOFF_LS1(void);
void TLE9186_RegLayer_update_TDON_TDOFF_LS1(uint16 u16_value);
void TLE9186_RegLayer_get_TDON_TDOFF_HS2(void);
void TLE9186_RegLayer_update_TDON_TDOFF_HS2(uint16 u16_value);
void TLE9186_RegLayer_get_TDON_TDOFF_LS2(void);
void TLE9186_RegLayer_update_TDON_TDOFF_LS2(uint16 u16_value);
void TLE9186_RegLayer_get_TDON_TDOFF_HS3(void);
void TLE9186_RegLayer_update_TDON_TDOFF_HS3(uint16 u16_value);
void TLE9186_RegLayer_get_TDON_TDOFF_LS3(void);
void TLE9186_RegLayer_update_TDON_TDOFF_LS3(uint16 u16_value);
void TLE9186_RegLayer_get_TSLEW_ON_OFF_HS1(void);
void TLE9186_RegLayer_update_TSLEW_ON_OFF_HS1(uint16 u16_value);
void TLE9186_RegLayer_get_TSLEW_ON_OFF_LS1(void);
void TLE9186_RegLayer_update_TSLEW_ON_OFF_LS1(uint16 u16_value);
void TLE9186_RegLayer_get_TSLEW_ON_OFF_HS2(void);
void TLE9186_RegLayer_update_TSLEW_ON_OFF_HS2(uint16 u16_value);
void TLE9186_RegLayer_get_TSLEW_ON_OFF_LS2(void);
void TLE9186_RegLayer_update_TSLEW_ON_OFF_LS2(uint16 u16_value);
void TLE9186_RegLayer_get_TSLEW_ON_OFF_HS3(void);
void TLE9186_RegLayer_update_TSLEW_ON_OFF_HS3(uint16 u16_value);
void TLE9186_RegLayer_get_TSLEW_ON_OFF_LS3(void);
void TLE9186_RegLayer_update_TSLEW_ON_OFF_LS3(uint16 u16_value);
void TLE9186_RegLayer_get_DEVICE_VERSION(void);
void TLE9186_RegLayer_update_GSB(uint8 u8_value);

#endif /* TLE9186_REGLAYER_H */
