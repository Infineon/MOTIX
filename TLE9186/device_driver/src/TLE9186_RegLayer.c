/**
 *	@file TLE9186_RegLayer.c
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
/**
 * @defgroup regLayer Register Layer
 * @brief The Register Layer offers API function for either writing to a
 * register or reading from a register.
 * @details It translates the calls given in @ref funcLayer to register level.
 * @details While generating a corresponding write function it updates the
 * internal register shadow.
 * @details Additionally it provides the possibility to update given registers
 * based on the received message. This corresponds to the cyclic update
 * functionality given in @ref appl_layer_cyclic.
 *
 */

#include "TLE9186_RegLayer.h"
#include "TLE9186.h"
#include "TLE9186_ServLayer.h"
#include "TLE9186_defines.h"
#include "TLE9186_init.h"
#include "stdio.h"

/**
 * @addtogroup device_driver
 * @{
 */
/**
 * @addtogroup regLayer
 * @{
 */
/**
 * @brief Init-function for the shadow register.
 *
 * This functions sets the shadow registers to reset values.
 *
 */
void TLE9186_RegLayer_init_ShadowRegister(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186->CONFIG_SECURED.reg = TLE9186_CONFIG_SECURED_Init;
  TLE9186->PWR_MOD_CFG.reg = TLE9186_PWR_MOD_CFG_Init;
  TLE9186->WD_CFG.reg = TLE9186_WD_CFG_Init;
  TLE9186->GEN_CFG1.reg = TLE9186_GEN_CFG1_Init;
  TLE9186->GEN_CFG2.reg = TLE9186_GEN_CFG2_Init;
  TLE9186->GEN_CFG3.reg = TLE9186_GEN_CFG3_Init;
  TLE9186->GDRV_CFG1.reg = TLE9186_GDRV_CFG1_Init;
  TLE9186->GDRV_CFG2.reg = TLE9186_GDRV_CFG2_Init;
  TLE9186->GDRV_CFG3.reg = TLE9186_GDRV_CFG3_Init;
  TLE9186->TON_HS.reg = TLE9186_TON_HS_Init;
  TLE9186->TON_LS.reg = TLE9186_TON_LS_Init;
  TLE9186->TOFF_HS.reg = TLE9186_TOFF_HS_Init;
  TLE9186->TOFF_LS.reg = TLE9186_TOFF_LS_Init;
  TLE9186->T3OFF.reg = TLE9186_T3OFF_Init;
  TLE9186->ION_HS1.reg = TLE9186_ION_HS1_Init;
  TLE9186->ION_LS1.reg = TLE9186_ION_LS1_Init;
  TLE9186->ION_HS2.reg = TLE9186_ION_HS2_Init;
  TLE9186->ION_LS2.reg = TLE9186_ION_LS2_Init;
  TLE9186->ION_HS3.reg = TLE9186_ION_HS3_Init;
  TLE9186->ION_LS3.reg = TLE9186_ION_LS3_Init;
  TLE9186->I3ON.reg = TLE9186_I3ON_Init;
  TLE9186->ION_IOFF_DIDT.reg = TLE9186_ION_IOFF_DIDT_Init;
  TLE9186->IOFF_HS1.reg = TLE9186_IOFF_HS1_Init;
  TLE9186->IOFF_LS1.reg = TLE9186_IOFF_LS1_Init;
  TLE9186->IOFF_HS2.reg = TLE9186_IOFF_HS2_Init;
  TLE9186->IOFF_LS2.reg = TLE9186_IOFF_LS2_Init;
  TLE9186->IOFF_HS3.reg = TLE9186_IOFF_HS3_Init;
  TLE9186->IOFF_LS3.reg = TLE9186_IOFF_LS3_Init;
  TLE9186->CSA_CFG.reg = TLE9186_CSA_CFG_Init;
  TLE9186->FAILURE_CFG.reg = TLE9186_FAILURE_CFG_Init;
  TLE9186->SELF_TEST_CFG.reg = TLE9186_SELF_TEST_CFG_Init;
  TLE9186->SUP_STAT.reg = TLE9186_SUP_STAT_Init;
  TLE9186->SPI_STAT.reg = TLE9186_SPI_STAT_Init;
  TLE9186->DEV_STAT1.reg = TLE9186_DEV_STAT1_Init;
  TLE9186->DEV_STAT2.reg = TLE9186_DEV_STAT2_Init;
  TLE9186->LF_STAT.reg = TLE9186_LF_STAT_Init;
  TLE9186->SH_LEVEL_STAT.reg = TLE9186_SH_LEVEL_STAT_Init;
  TLE9186->BD_STAT.reg = TLE9186_BD_STAT_Init;
  TLE9186->WD_CLK_CNT.reg = TLE9186_WD_CLK_CNT_Init;
  TLE9186->PHASE1_CNT.reg = TLE9186_PHASE1_CNT_Init;
  TLE9186->PHASE2_CNT.reg = TLE9186_PHASE2_CNT_Init;
  TLE9186->PHASE3_CNT.reg = TLE9186_PHASE3_CNT_Init;
  TLE9186->TDON_TDOFF_HS1.reg = TLE9186_TDON_TDOFF_HS1_Init;
  TLE9186->TDON_TDOFF_LS1.reg = TLE9186_TDON_TDOFF_LS1_Init;
  TLE9186->TDON_TDOFF_HS2.reg = TLE9186_TDON_TDOFF_HS2_Init;
  TLE9186->TDON_TDOFF_LS2.reg = TLE9186_TDON_TDOFF_LS2_Init;
  TLE9186->TDON_TDOFF_HS3.reg = TLE9186_TDON_TDOFF_HS3_Init;
  TLE9186->TDON_TDOFF_LS3.reg = TLE9186_TDON_TDOFF_LS3_Init;
  TLE9186->TSLEW_ON_OFF_HS1.reg = TLE9186_TSLEW_ON_OFF_HS1_Init;
  TLE9186->TSLEW_ON_OFF_LS1.reg = TLE9186_TSLEW_ON_OFF_LS1_Init;
  TLE9186->TSLEW_ON_OFF_HS2.reg = TLE9186_TSLEW_ON_OFF_HS2_Init;
  TLE9186->TSLEW_ON_OFF_LS2.reg = TLE9186_TSLEW_ON_OFF_LS2_Init;
  TLE9186->TSLEW_ON_OFF_HS3.reg = TLE9186_TSLEW_ON_OFF_HS3_Init;
  TLE9186->TSLEW_ON_OFF_LS3.reg = TLE9186_TSLEW_ON_OFF_LS3_Init;
  TLE9186->DEVICE_VERSION.reg = TLE9186_DEVICE_VERSION_Init;
}

/**
 * @brief Set function for register CONFIG_SECURED.
 *
 * This function updates the register shadow for register CONFIG_SECURED and
 * generates the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register CONFIG_SECURED.
 *
 */
void TLE9186_RegLayer_set_CONFIG_SECURED(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->CONFIG_SECURED.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_CONFIG_SECURED_ADDR, u16_value);
}

/**
 * @brief Get function for register CONFIG_SECURED.
 *
 * This function generates the SPI message to read from the register
 * CONFIG_SECURED.
 *
 */
void TLE9186_RegLayer_get_CONFIG_SECURED(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186_ServLayer_getReg(TLE9186_CONFIG_SECURED_ADDR);
}

/**
 * @brief Set function for register PWR_MOD_CFG.
 *
 * This function updates the register shadow for register PWR_MOD_CFG and
 * generates the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register PWR_MOD_CFG.
 *
 */
void TLE9186_RegLayer_set_PWR_MOD_CFG(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->PWR_MOD_CFG.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_PWR_MOD_CFG_ADDR, u16_value);
}

/**
 * @brief Get function for register PWR_MOD_CFG.
 *
 * This function generates the SPI message to read from the register
 * PWR_MOD_CFG.
 *
 */
void TLE9186_RegLayer_get_PWR_MOD_CFG(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_ServLayer_getReg(TLE9186_PWR_MOD_CFG_ADDR);
}

/**
 * @brief Set function for register WD_CFG.
 *
 * This function updates the register shadow for register WD_CFG and generates
 * the corresponding SPI message. Furthermore it ensures that the parity of the
 * lower 16 bits is even.
 *
 * @param u16_value Value to be written into the register WD_CFG.
 *
 */
void TLE9186_RegLayer_set_WD_CFG(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  // Calculate the parity of the lower 15 bits
  uint16 u16_lower_15_bits = (uint16)(u16_value & 0x7FFFu);
  uint16 u16_parity = 0u;
  uint8 u8_index = 0u;
  uint16 u16_final_value = 0u;

  for (u8_index = 0u; u8_index < 15u; u8_index++) {
    u16_parity ^= (uint16)((u16_lower_15_bits >> u8_index) & 0x1u);
  }

  // Get the first 15 bits of the value
  u16_final_value = u16_lower_15_bits;

  // Adjust the 15th bit to ensure even parity
  if (u16_parity == 1u) {
    u16_final_value |= 0x8000u; // Set bit 15 to 1
  } else {
    u16_final_value &= 0x7FFFu; // Set bit 15 to 0
  }

  TLE9186->WD_CFG.reg = u16_final_value;
  TLE9186_ServLayer_setReg(TLE9186_WD_CFG_ADDR, u16_final_value);
}

/**
 * @brief Get function for register WD_CFG.
 *
 * This function generates the SPI message to read from the register WD_CFG.
 *
 */
void TLE9186_RegLayer_get_WD_CFG(void) /* polyspace MISRA2012:5.1 [Justified:
                                          Low] "Given due to register names" */
{
  TLE9186_ServLayer_getReg(TLE9186_WD_CFG_ADDR);
}

/**
 * @brief Set function for register GEN_CFG1.
 *
 * This function updates the register shadow for register GEN_CFG1 and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register GEN_CFG1.
 *
 */
void TLE9186_RegLayer_set_GEN_CFG1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->GEN_CFG1.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_GEN_CFG1_ADDR, u16_value);
}

/**
 * @brief Get function for register GEN_CFG1.
 *
 * This function generates the SPI message to read from the register GEN_CFG1.
 *
 */
void TLE9186_RegLayer_get_GEN_CFG1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_ServLayer_getReg(TLE9186_GEN_CFG1_ADDR);
}

/**
 * @brief Set function for register GEN_CFG2.
 *
 * This function updates the register shadow for register GEN_CFG2 and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register GEN_CFG2.
 *
 */
void TLE9186_RegLayer_set_GEN_CFG2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->GEN_CFG2.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_GEN_CFG2_ADDR, u16_value);
}

/**
 * @brief Get function for register GEN_CFG2.
 *
 * This function generates the SPI message to read from the register GEN_CFG2.
 *
 */
void TLE9186_RegLayer_get_GEN_CFG2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_ServLayer_getReg(TLE9186_GEN_CFG2_ADDR);
}

/**
 * @brief Set function for register GEN_CFG3.
 *
 * This function updates the register shadow for register GEN_CFG3 and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register GEN_CFG3.
 *
 */
void TLE9186_RegLayer_set_GEN_CFG3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->GEN_CFG3.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_GEN_CFG3_ADDR, u16_value);
}

/**
 * @brief Get function for register GEN_CFG3.
 *
 * This function generates the SPI message to read from the register GEN_CFG3.
 *
 */
void TLE9186_RegLayer_get_GEN_CFG3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_ServLayer_getReg(TLE9186_GEN_CFG3_ADDR);
}

/**
 * @brief Set function for register GDRV_CFG1.
 *
 * This function updates the register shadow for register GDRV_CFG1 and
 * generates the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register GDRV_CFG1.
 *
 */
void TLE9186_RegLayer_set_GDRV_CFG1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->GDRV_CFG1.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_GDRV_CFG1_ADDR, u16_value);
}

/**
 * @brief Get function for register GDRV_CFG1.
 *
 * This function generates the SPI message to read from the register GDRV_CFG1.
 *
 */
void TLE9186_RegLayer_get_GDRV_CFG1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_ServLayer_getReg(TLE9186_GDRV_CFG1_ADDR);
}

/**
 * @brief Set function for register GDRV_CFG2.
 *
 * This function updates the register shadow for register GDRV_CFG2 and
 * generates the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register GDRV_CFG2.
 *
 */
void TLE9186_RegLayer_set_GDRV_CFG2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->GDRV_CFG2.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_GDRV_CFG2_ADDR, u16_value);
}

/**
 * @brief Get function for register GDRV_CFG2.
 *
 * This function generates the SPI message to read from the register GDRV_CFG2.
 *
 */
void TLE9186_RegLayer_get_GDRV_CFG2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_ServLayer_getReg(TLE9186_GDRV_CFG2_ADDR);
}

/**
 * @brief Set function for register GDRV_CFG3.
 *
 * This function updates the register shadow for register GDRV_CFG3 and
 * generates the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register GDRV_CFG3.
 *
 */
void TLE9186_RegLayer_set_GDRV_CFG3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->GDRV_CFG3.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_GDRV_CFG3_ADDR, u16_value);
}

/**
 * @brief Get function for register GDRV_CFG3.
 *
 * This function generates the SPI message to read from the register GDRV_CFG3.
 *
 */
void TLE9186_RegLayer_get_GDRV_CFG3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_ServLayer_getReg(TLE9186_GDRV_CFG3_ADDR);
}

/**
 * @brief Set function for register TON_HS.
 *
 * This function updates the register shadow for register TON_HS and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register TON_HS.
 *
 */
void TLE9186_RegLayer_set_TON_HS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->TON_HS.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_TON_HS_ADDR, u16_value);
}

/**
 * @brief Get function for register TON_HS.
 *
 * This function generates the SPI message to read from the register TON_HS.
 *
 */
void TLE9186_RegLayer_get_TON_HS(void) /* polyspace MISRA2012:5.1 [Justified:
                                          Low] "Given due to register names" */
{
  TLE9186_ServLayer_getReg(TLE9186_TON_HS_ADDR);
}

/**
 * @brief Set function for register TON_LS.
 *
 * This function updates the register shadow for register TON_LS and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register TON_LS.
 *
 */
void TLE9186_RegLayer_set_TON_LS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->TON_LS.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_TON_LS_ADDR, u16_value);
}

/**
 * @brief Get function for register TON_LS.
 *
 * This function generates the SPI message to read from the register TON_LS.
 *
 */
void TLE9186_RegLayer_get_TON_LS(void) /* polyspace MISRA2012:5.1 [Justified:
                                          Low] "Given due to register names" */
{
  TLE9186_ServLayer_getReg(TLE9186_TON_LS_ADDR);
}

/**
 * @brief Set function for register TOFF_HS.
 *
 * This function updates the register shadow for register TOFF_HS and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register TOFF_HS.
 *
 */
void TLE9186_RegLayer_set_TOFF_HS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->TOFF_HS.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_TOFF_HS_ADDR, u16_value);
}

/**
 * @brief Get function for register TOFF_HS.
 *
 * This function generates the SPI message to read from the register TOFF_HS.
 *
 */
void TLE9186_RegLayer_get_TOFF_HS(void) /* polyspace MISRA2012:5.1 [Justified:
                                           Low] "Given due to register names" */
{
  TLE9186_ServLayer_getReg(TLE9186_TOFF_HS_ADDR);
}

/**
 * @brief Set function for register TOFF_LS.
 *
 * This function updates the register shadow for register TOFF_LS and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register TOFF_LS.
 *
 */
void TLE9186_RegLayer_set_TOFF_LS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->TOFF_LS.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_TOFF_LS_ADDR, u16_value);
}

/**
 * @brief Get function for register TOFF_LS.
 *
 * This function generates the SPI message to read from the register TOFF_LS.
 *
 */
void TLE9186_RegLayer_get_TOFF_LS(void) /* polyspace MISRA2012:5.1 [Justified:
                                           Low] "Given due to register names" */
{
  TLE9186_ServLayer_getReg(TLE9186_TOFF_LS_ADDR);
}

/**
 * @brief Set function for register T3OFF.
 *
 * This function updates the register shadow for register T3OFF and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register T3OFF.
 *
 */
void TLE9186_RegLayer_set_T3OFF(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->T3OFF.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_T3OFF_ADDR, u16_value);
}

/**
 * @brief Get function for register T3OFF.
 *
 * This function generates the SPI message to read from the register T3OFF.
 *
 */
void TLE9186_RegLayer_get_T3OFF(void) /* polyspace MISRA2012:5.1 [Justified:
                                         Low] "Given due to register names" */
{
  TLE9186_ServLayer_getReg(TLE9186_T3OFF_ADDR);
}

/**
 * @brief Set function for register ION_HS1.
 *
 * This function updates the register shadow for register ION_HS1 and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register ION_HS1.
 *
 */
void TLE9186_RegLayer_set_ION_HS1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->ION_HS1.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_ION_HS1_ADDR, u16_value);
}

/**
 * @brief Get function for register ION_HS1.
 *
 * This function generates the SPI message to read from the register ION_HS1.
 *
 */
void TLE9186_RegLayer_get_ION_HS1(void) /* polyspace MISRA2012:5.1 [Justified:
                                           Low] "Given due to register names" */
{
  TLE9186_ServLayer_getReg(TLE9186_ION_HS1_ADDR);
}

/**
 * @brief Set function for register ION_LS1.
 *
 * This function updates the register shadow for register ION_LS1 and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register ION_LS1.
 *
 */
void TLE9186_RegLayer_set_ION_LS1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->ION_LS1.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_ION_LS1_ADDR, u16_value);
}

/**
 * @brief Get function for register ION_LS1.
 *
 * This function generates the SPI message to read from the register ION_LS1.
 *
 */
void TLE9186_RegLayer_get_ION_LS1(void) /* polyspace MISRA2012:5.1 [Justified:
                                           Low] "Given due to register names" */
{
  TLE9186_ServLayer_getReg(TLE9186_ION_LS1_ADDR);
}

/**
 * @brief Set function for register ION_HS2.
 *
 * This function updates the register shadow for register ION_HS2 and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register ION_HS2.
 *
 */
void TLE9186_RegLayer_set_ION_HS2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->ION_HS2.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_ION_HS2_ADDR, u16_value);
}

/**
 * @brief Get function for register ION_HS2.
 *
 * This function generates the SPI message to read from the register ION_HS2.
 *
 */
void TLE9186_RegLayer_get_ION_HS2(void) /* polyspace MISRA2012:5.1 [Justified:
                                           Low] "Given due to register names" */
{
  TLE9186_ServLayer_getReg(TLE9186_ION_HS2_ADDR);
}

/**
 * @brief Set function for register ION_LS2.
 *
 * This function updates the register shadow for register ION_LS2 and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register ION_LS2.
 *
 */
void TLE9186_RegLayer_set_ION_LS2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->ION_LS2.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_ION_LS2_ADDR, u16_value);
}

/**
 * @brief Get function for register ION_LS2.
 *
 * This function generates the SPI message to read from the register ION_LS2.
 *
 */
void TLE9186_RegLayer_get_ION_LS2(void) /* polyspace MISRA2012:5.1 [Justified:
                                           Low] "Given due to register names" */
{
  TLE9186_ServLayer_getReg(TLE9186_ION_LS2_ADDR);
}

/**
 * @brief Set function for register ION_HS3.
 *
 * This function updates the register shadow for register ION_HS3 and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register ION_HS3.
 *
 */
void TLE9186_RegLayer_set_ION_HS3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->ION_HS3.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_ION_HS3_ADDR, u16_value);
}

/**
 * @brief Get function for register ION_HS3.
 *
 * This function generates the SPI message to read from the register ION_HS3.
 *
 */
void TLE9186_RegLayer_get_ION_HS3(void) /* polyspace MISRA2012:5.1 [Justified:
                                           Low] "Given due to register names" */
{
  TLE9186_ServLayer_getReg(TLE9186_ION_HS3_ADDR);
}

/**
 * @brief Set function for register ION_LS3.
 *
 * This function updates the register shadow for register ION_LS3 and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register ION_LS3.
 *
 */
void TLE9186_RegLayer_set_ION_LS3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->ION_LS3.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_ION_LS3_ADDR, u16_value);
}

/**
 * @brief Get function for register ION_LS3.
 *
 * This function generates the SPI message to read from the register ION_LS3.
 *
 */
void TLE9186_RegLayer_get_ION_LS3(void) /* polyspace MISRA2012:5.1 [Justified:
                                           Low] "Given due to register names" */
{
  TLE9186_ServLayer_getReg(TLE9186_ION_LS3_ADDR);
}

/**
 * @brief Set function for register I3ON.
 *
 * This function updates the register shadow for register I3ON and generates the
 * corresponding SPI message.
 *
 * @param u16_value Value to be written into the register I3ON.
 *
 */
void TLE9186_RegLayer_set_I3ON(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names"
                       */
{
  TLE9186->I3ON.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_I3ON_ADDR, u16_value);
}

/**
 * @brief Get function for register I3ON.
 *
 * This function generates the SPI message to read from the register I3ON.
 *
 */
void TLE9186_RegLayer_get_I3ON(void) /* polyspace MISRA2012:5.1 [Justified: Low]
                                        "Given due to register names" */
{
  TLE9186_ServLayer_getReg(TLE9186_I3ON_ADDR);
}

/**
 * @brief Set function for register ION_IOFF_DIDT.
 *
 * This function updates the register shadow for register ION_IOFF_DIDT and
 * generates the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register ION_IOFF_DIDT.
 *
 */
void TLE9186_RegLayer_set_ION_IOFF_DIDT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->ION_IOFF_DIDT.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_ION_IOFF_DIDT_ADDR, u16_value);
}

/**
 * @brief Get function for register ION_IOFF_DIDT.
 *
 * This function generates the SPI message to read from the register
 * ION_IOFF_DIDT.
 *
 */
void TLE9186_RegLayer_get_ION_IOFF_DIDT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186_ServLayer_getReg(TLE9186_ION_IOFF_DIDT_ADDR);
}

/**
 * @brief Set function for register IOFF_HS1.
 *
 * This function updates the register shadow for register IOFF_HS1 and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register IOFF_HS1.
 *
 */
void TLE9186_RegLayer_set_IOFF_HS1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->IOFF_HS1.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_IOFF_HS1_ADDR, u16_value);
}

/**
 * @brief Get function for register IOFF_HS1.
 *
 * This function generates the SPI message to read from the register IOFF_HS1.
 *
 */
void TLE9186_RegLayer_get_IOFF_HS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_ServLayer_getReg(TLE9186_IOFF_HS1_ADDR);
}

/**
 * @brief Set function for register IOFF_LS1.
 *
 * This function updates the register shadow for register IOFF_LS1 and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register IOFF_LS1.
 *
 */
void TLE9186_RegLayer_set_IOFF_LS1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->IOFF_LS1.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_IOFF_LS1_ADDR, u16_value);
}

/**
 * @brief Get function for register IOFF_LS1.
 *
 * This function generates the SPI message to read from the register IOFF_LS1.
 *
 */
void TLE9186_RegLayer_get_IOFF_LS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_ServLayer_getReg(TLE9186_IOFF_LS1_ADDR);
}

/**
 * @brief Set function for register IOFF_HS2.
 *
 * This function updates the register shadow for register IOFF_HS2 and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register IOFF_HS2.
 *
 */
void TLE9186_RegLayer_set_IOFF_HS2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->IOFF_HS2.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_IOFF_HS2_ADDR, u16_value);
}

/**
 * @brief Get function for register IOFF_HS2.
 *
 * This function generates the SPI message to read from the register IOFF_HS2.
 *
 */
void TLE9186_RegLayer_get_IOFF_HS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_ServLayer_getReg(TLE9186_IOFF_HS2_ADDR);
}

/**
 * @brief Set function for register IOFF_LS2.
 *
 * This function updates the register shadow for register IOFF_LS2 and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register IOFF_LS2.
 *
 */
void TLE9186_RegLayer_set_IOFF_LS2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->IOFF_LS2.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_IOFF_LS2_ADDR, u16_value);
}

/**
 * @brief Get function for register IOFF_LS2.
 *
 * This function generates the SPI message to read from the register IOFF_LS2.
 *
 */
void TLE9186_RegLayer_get_IOFF_LS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_ServLayer_getReg(TLE9186_IOFF_LS2_ADDR);
}

/**
 * @brief Set function for register IOFF_HS3.
 *
 * This function updates the register shadow for register IOFF_HS3 and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register IOFF_HS3.
 *
 */
void TLE9186_RegLayer_set_IOFF_HS3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->IOFF_HS3.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_IOFF_HS3_ADDR, u16_value);
}

/**
 * @brief Get function for register IOFF_HS3.
 *
 * This function generates the SPI message to read from the register IOFF_HS3.
 *
 */
void TLE9186_RegLayer_get_IOFF_HS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_ServLayer_getReg(TLE9186_IOFF_HS3_ADDR);
}

/**
 * @brief Set function for register IOFF_LS3.
 *
 * This function updates the register shadow for register IOFF_LS3 and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register IOFF_LS3.
 *
 */
void TLE9186_RegLayer_set_IOFF_LS3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->IOFF_LS3.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_IOFF_LS3_ADDR, u16_value);
}

/**
 * @brief Get function for register IOFF_LS3.
 *
 * This function generates the SPI message to read from the register IOFF_LS3.
 *
 */
void TLE9186_RegLayer_get_IOFF_LS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_ServLayer_getReg(TLE9186_IOFF_LS3_ADDR);
}

/**
 * @brief Set function for register CSA_CFG.
 *
 * This function updates the register shadow for register CSA_CFG and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register CSA_CFG.
 *
 */
void TLE9186_RegLayer_set_CSA_CFG(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->CSA_CFG.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_CSA_CFG_ADDR, u16_value);
}

/**
 * @brief Get function for register CSA_CFG.
 *
 * This function generates the SPI message to read from the register CSA_CFG.
 *
 */
void TLE9186_RegLayer_get_CSA_CFG(void) /* polyspace MISRA2012:5.1 [Justified:
                                           Low] "Given due to register names" */
{
  TLE9186_ServLayer_getReg(TLE9186_CSA_CFG_ADDR);
}

/**
 * @brief Set function for register FAILURE_CFG.
 *
 * This function updates the register shadow for register FAILURE_CFG and
 * generates the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register FAILURE_CFG.
 *
 */
void TLE9186_RegLayer_set_FAILURE_CFG(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->FAILURE_CFG.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_FAILURE_CFG_ADDR, u16_value);
}

/**
 * @brief Get function for register FAILURE_CFG.
 *
 * This function generates the SPI message to read from the register
 * FAILURE_CFG.
 *
 */
void TLE9186_RegLayer_get_FAILURE_CFG(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_ServLayer_getReg(TLE9186_FAILURE_CFG_ADDR);
}

/**
 * @brief Set function for register SELF_TEST_CFG.
 *
 * This function updates the register shadow for register SELF_TEST_CFG and
 * generates the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register SELF_TEST_CFG.
 *
 */
void TLE9186_RegLayer_set_SELF_TEST_CFG(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->SELF_TEST_CFG.reg = u16_value;
  TLE9186_ServLayer_setReg(TLE9186_SELF_TEST_CFG_ADDR, u16_value);
}

/**
 * @brief Get function for register SELF_TEST_CFG.
 *
 * This function generates the SPI message to read from the register
 * SELF_TEST_CFG.
 *
 */
void TLE9186_RegLayer_get_SELF_TEST_CFG(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186_ServLayer_getReg(TLE9186_SELF_TEST_CFG_ADDR);
}

/**
 * @brief Set function for register SUP_STAT.
 *
 * This function updates the register shadow for register SUP_STAT and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register SUP_STAT.
 *
 */
void TLE9186_RegLayer_set_SUP_STAT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  u16_temp_reg = TLE9186->SUP_STAT.reg;
  TLE9186->SUP_STAT.reg = (uint16)(u16_temp_reg ^ u16_value);
  TLE9186_ServLayer_setReg(TLE9186_SUP_STAT_ADDR, (uint16)(u16_value));
}

/**
 * @brief Get function for register SUP_STAT.
 *
 * This function generates the SPI message to read from the register SUP_STAT.
 *
 */
void TLE9186_RegLayer_get_SUP_STAT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_ServLayer_getReg(TLE9186_SUP_STAT_ADDR);
}

/**
 * @brief Update function for shadow register of SUP_STAT.
 *
 * This function updates the internal shadow register for the register SUP_STAT.
 *
 */
void TLE9186_RegLayer_update_SUP_STAT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->SUP_STAT.reg = u16_value;
}

/**
 * @brief Set function for register SPI_STAT.
 *
 * This function updates the register shadow for register SPI_STAT and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register SPI_STAT.
 *
 */
void TLE9186_RegLayer_set_SPI_STAT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  u16_temp_reg = TLE9186->SPI_STAT.reg;
  TLE9186->SPI_STAT.reg = (uint16)(u16_temp_reg ^ u16_value);
  TLE9186_ServLayer_setReg(TLE9186_SPI_STAT_ADDR, (uint16)(u16_value));
}

/**
 * @brief Get function for register SPI_STAT.
 *
 * This function generates the SPI message to read from the register SPI_STAT.
 *
 */
void TLE9186_RegLayer_get_SPI_STAT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_ServLayer_getReg(TLE9186_SPI_STAT_ADDR);
}

/**
 * @brief Update function for shadow register of SPI_STAT.
 *
 * This function updates the internal shadow register for the register SPI_STAT.
 *
 */
void TLE9186_RegLayer_update_SPI_STAT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->SPI_STAT.reg = u16_value;
}

/**
 * @brief Set function for register DEV_STAT1.
 *
 * This function updates the register shadow for register DEV_STAT1 and
 * generates the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register DEV_STAT1.
 *
 */
void TLE9186_RegLayer_set_DEV_STAT1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  u16_temp_reg = TLE9186->DEV_STAT1.reg;
  TLE9186->DEV_STAT1.reg = (uint16)(u16_temp_reg ^ u16_value);
  TLE9186_ServLayer_setReg(TLE9186_DEV_STAT1_ADDR, (uint16)(u16_value));
}

/**
 * @brief Get function for register DEV_STAT1.
 *
 * This function generates the SPI message to read from the register DEV_STAT1.
 *
 */
void TLE9186_RegLayer_get_DEV_STAT1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_ServLayer_getReg(TLE9186_DEV_STAT1_ADDR);
}

/**
 * @brief Update function for shadow register of DEV_STAT1.
 *
 * This function updates the internal shadow register for the register
 * DEV_STAT1.
 *
 */
void TLE9186_RegLayer_update_DEV_STAT1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->DEV_STAT1.reg = u16_value;
}

/**
 * @brief Set function for register DEV_STAT2.
 *
 * This function updates the register shadow for register DEV_STAT2 and
 * generates the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register DEV_STAT2.
 *
 */
void TLE9186_RegLayer_set_DEV_STAT2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  u16_temp_reg = TLE9186->DEV_STAT2.reg;
  TLE9186->DEV_STAT2.reg = (uint16)(u16_temp_reg ^ u16_value);
  TLE9186_ServLayer_setReg(TLE9186_DEV_STAT2_ADDR, (uint16)(u16_value));
}

/**
 * @brief Get function for register DEV_STAT2.
 *
 * This function generates the SPI message to read from the register DEV_STAT2.
 *
 */
void TLE9186_RegLayer_get_DEV_STAT2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_ServLayer_getReg(TLE9186_DEV_STAT2_ADDR);
}

/**
 * @brief Update function for shadow register of DEV_STAT2.
 *
 * This function updates the internal shadow register for the register
 * DEV_STAT2.
 *
 */
void TLE9186_RegLayer_update_DEV_STAT2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->DEV_STAT2.reg = u16_value;
}

/**
 * @brief Set function for register LF_STAT.
 *
 * This function updates the register shadow for register LF_STAT and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register LF_STAT.
 *
 */
void TLE9186_RegLayer_set_LF_STAT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  u16_temp_reg = TLE9186->LF_STAT.reg;
  TLE9186->LF_STAT.reg = (uint16)(u16_temp_reg ^ u16_value);
  TLE9186_ServLayer_setReg(TLE9186_LF_STAT_ADDR, (uint16)(u16_value));
}

/**
 * @brief Get function for register LF_STAT.
 *
 * This function generates the SPI message to read from the register LF_STAT.
 *
 */
void TLE9186_RegLayer_get_LF_STAT(void) /* polyspace MISRA2012:5.1 [Justified:
                                           Low] "Given due to register names" */
{
  TLE9186_ServLayer_getReg(TLE9186_LF_STAT_ADDR);
}

/**
 * @brief Update function for shadow register of LF_STAT.
 *
 * This function updates the internal shadow register for the register LF_STAT.
 *
 */
void TLE9186_RegLayer_update_LF_STAT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->LF_STAT.reg = u16_value;
}

/**
 * @brief Get function for register SH_LEVEL_STAT.
 *
 * This function generates the SPI message to read from the register
 * SH_LEVEL_STAT.
 *
 */
void TLE9186_RegLayer_get_SH_LEVEL_STAT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186_ServLayer_getReg(TLE9186_SH_LEVEL_STAT_ADDR);
}

/**
 * @brief Update function for shadow register of SH_LEVEL_STAT.
 *
 * This function updates the internal shadow register for the register
 * SH_LEVEL_STAT.
 *
 */
void TLE9186_RegLayer_update_SH_LEVEL_STAT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->SH_LEVEL_STAT.reg = u16_value;
}

/**
 * @brief Set function for register BD_STAT.
 *
 * This function updates the register shadow for register BD_STAT and generates
 * the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register BD_STAT.
 *
 */
void TLE9186_RegLayer_set_BD_STAT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  u16_temp_reg = TLE9186->BD_STAT.reg;
  TLE9186->BD_STAT.reg = (uint16)(u16_temp_reg ^ u16_value);
  TLE9186_ServLayer_setReg(TLE9186_BD_STAT_ADDR, (uint16)(u16_value));
}

/**
 * @brief Get function for register BD_STAT.
 *
 * This function generates the SPI message to read from the register BD_STAT.
 *
 */
void TLE9186_RegLayer_get_BD_STAT(void) /* polyspace MISRA2012:5.1 [Justified:
                                           Low] "Given due to register names" */
{
  TLE9186_ServLayer_getReg(TLE9186_BD_STAT_ADDR);
}

/**
 * @brief Update function for shadow register of BD_STAT.
 *
 * This function updates the internal shadow register for the register BD_STAT.
 *
 */
void TLE9186_RegLayer_update_BD_STAT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->BD_STAT.reg = u16_value;
}

/**
 * @brief Get function for register WD_CLK_CNT.
 *
 * This function generates the SPI message to read from the register WD_CLK_CNT.
 *
 */
void TLE9186_RegLayer_get_WD_CLK_CNT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_ServLayer_getReg(TLE9186_WD_CLK_CNT_ADDR);
}

/**
 * @brief Update function for shadow register of WD_CLK_CNT.
 *
 * This function updates the internal shadow register for the register
 * WD_CLK_CNT.
 *
 */
void TLE9186_RegLayer_update_WD_CLK_CNT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->WD_CLK_CNT.reg = u16_value;
}

/**
 * @brief Set function for register PHASE1_CNT.
 *
 * This function updates the register shadow for register PHASE1_CNT and
 * generates the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register PHASE1_CNT.
 *
 */
void TLE9186_RegLayer_set_PHASE1_CNT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  u16_temp_reg = TLE9186->PHASE1_CNT.reg;
  TLE9186->PHASE1_CNT.reg = (uint16)(u16_temp_reg ^ u16_value);
  TLE9186_ServLayer_setReg(TLE9186_PHASE1_CNT_ADDR, (uint16)(u16_value));
}

/**
 * @brief Get function for register PHASE1_CNT.
 *
 * This function generates the SPI message to read from the register PHASE1_CNT.
 *
 */
void TLE9186_RegLayer_get_PHASE1_CNT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_ServLayer_getReg(TLE9186_PHASE1_CNT_ADDR);
}

/**
 * @brief Update function for shadow register of PHASE1_CNT.
 *
 * This function updates the internal shadow register for the register
 * PHASE1_CNT.
 *
 */
void TLE9186_RegLayer_update_PHASE1_CNT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->PHASE1_CNT.reg = u16_value;
}

/**
 * @brief Set function for register PHASE2_CNT.
 *
 * This function updates the register shadow for register PHASE2_CNT and
 * generates the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register PHASE2_CNT.
 *
 */
void TLE9186_RegLayer_set_PHASE2_CNT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  u16_temp_reg = TLE9186->PHASE2_CNT.reg;
  TLE9186->PHASE2_CNT.reg = (uint16)(u16_temp_reg ^ u16_value);
  TLE9186_ServLayer_setReg(TLE9186_PHASE2_CNT_ADDR, (uint16)(u16_value));
}

/**
 * @brief Get function for register PHASE2_CNT.
 *
 * This function generates the SPI message to read from the register PHASE2_CNT.
 *
 */
void TLE9186_RegLayer_get_PHASE2_CNT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_ServLayer_getReg(TLE9186_PHASE2_CNT_ADDR);
}

/**
 * @brief Update function for shadow register of PHASE2_CNT.
 *
 * This function updates the internal shadow register for the register
 * PHASE2_CNT.
 *
 */
void TLE9186_RegLayer_update_PHASE2_CNT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->PHASE2_CNT.reg = u16_value;
}

/**
 * @brief Set function for register PHASE3_CNT.
 *
 * This function updates the register shadow for register PHASE3_CNT and
 * generates the corresponding SPI message.
 *
 * @param u16_value Value to be written into the register PHASE3_CNT.
 *
 */
void TLE9186_RegLayer_set_PHASE3_CNT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  u16_temp_reg = TLE9186->PHASE3_CNT.reg;
  TLE9186->PHASE3_CNT.reg = (uint16)(u16_temp_reg ^ u16_value);
  TLE9186_ServLayer_setReg(TLE9186_PHASE3_CNT_ADDR, (uint16)(u16_value));
}

/**
 * @brief Get function for register PHASE3_CNT.
 *
 * This function generates the SPI message to read from the register PHASE3_CNT.
 *
 */
void TLE9186_RegLayer_get_PHASE3_CNT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_ServLayer_getReg(TLE9186_PHASE3_CNT_ADDR);
}

/**
 * @brief Update function for shadow register of PHASE3_CNT.
 *
 * This function updates the internal shadow register for the register
 * PHASE3_CNT.
 *
 */
void TLE9186_RegLayer_update_PHASE3_CNT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->PHASE3_CNT.reg = u16_value;
}

/**
 * @brief Get function for register TDON_TDOFF_HS1.
 *
 * This function generates the SPI message to read from the register
 * TDON_TDOFF_HS1.
 *
 */
void TLE9186_RegLayer_get_TDON_TDOFF_HS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186_ServLayer_getReg(TLE9186_TDON_TDOFF_HS1_ADDR);
}

/**
 * @brief Update function for shadow register of TDON_TDOFF_HS1.
 *
 * This function updates the internal shadow register for the register
 * TDON_TDOFF_HS1.
 *
 */
void TLE9186_RegLayer_update_TDON_TDOFF_HS1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->TDON_TDOFF_HS1.reg = u16_value;
}

/**
 * @brief Get function for register TDON_TDOFF_LS1.
 *
 * This function generates the SPI message to read from the register
 * TDON_TDOFF_LS1.
 *
 */
void TLE9186_RegLayer_get_TDON_TDOFF_LS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186_ServLayer_getReg(TLE9186_TDON_TDOFF_LS1_ADDR);
}

/**
 * @brief Update function for shadow register of TDON_TDOFF_LS1.
 *
 * This function updates the internal shadow register for the register
 * TDON_TDOFF_LS1.
 *
 */
void TLE9186_RegLayer_update_TDON_TDOFF_LS1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->TDON_TDOFF_LS1.reg = u16_value;
}

/**
 * @brief Get function for register TDON_TDOFF_HS2.
 *
 * This function generates the SPI message to read from the register
 * TDON_TDOFF_HS2.
 *
 */
void TLE9186_RegLayer_get_TDON_TDOFF_HS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186_ServLayer_getReg(TLE9186_TDON_TDOFF_HS2_ADDR);
}

/**
 * @brief Update function for shadow register of TDON_TDOFF_HS2.
 *
 * This function updates the internal shadow register for the register
 * TDON_TDOFF_HS2.
 *
 */
void TLE9186_RegLayer_update_TDON_TDOFF_HS2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->TDON_TDOFF_HS2.reg = u16_value;
}

/**
 * @brief Get function for register TDON_TDOFF_LS2.
 *
 * This function generates the SPI message to read from the register
 * TDON_TDOFF_LS2.
 *
 */
void TLE9186_RegLayer_get_TDON_TDOFF_LS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186_ServLayer_getReg(TLE9186_TDON_TDOFF_LS2_ADDR);
}

/**
 * @brief Update function for shadow register of TDON_TDOFF_LS2.
 *
 * This function updates the internal shadow register for the register
 * TDON_TDOFF_LS2.
 *
 */
void TLE9186_RegLayer_update_TDON_TDOFF_LS2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->TDON_TDOFF_LS2.reg = u16_value;
}

/**
 * @brief Get function for register TDON_TDOFF_HS3.
 *
 * This function generates the SPI message to read from the register
 * TDON_TDOFF_HS3.
 *
 */
void TLE9186_RegLayer_get_TDON_TDOFF_HS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186_ServLayer_getReg(TLE9186_TDON_TDOFF_HS3_ADDR);
}

/**
 * @brief Update function for shadow register of TDON_TDOFF_HS3.
 *
 * This function updates the internal shadow register for the register
 * TDON_TDOFF_HS3.
 *
 */
void TLE9186_RegLayer_update_TDON_TDOFF_HS3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->TDON_TDOFF_HS3.reg = u16_value;
}

/**
 * @brief Get function for register TDON_TDOFF_LS3.
 *
 * This function generates the SPI message to read from the register
 * TDON_TDOFF_LS3.
 *
 */
void TLE9186_RegLayer_get_TDON_TDOFF_LS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186_ServLayer_getReg(TLE9186_TDON_TDOFF_LS3_ADDR);
}

/**
 * @brief Update function for shadow register of TDON_TDOFF_LS3.
 *
 * This function updates the internal shadow register for the register
 * TDON_TDOFF_LS3.
 *
 */
void TLE9186_RegLayer_update_TDON_TDOFF_LS3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  TLE9186->TDON_TDOFF_LS3.reg = u16_value;
}

/**
 * @brief Get function for register TSLEW_ON_OFF_HS1.
 *
 * This function generates the SPI message to read from the register
 * TSLEW_ON_OFF_HS1.
 *
 */
void TLE9186_RegLayer_get_TSLEW_ON_OFF_HS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186_ServLayer_getReg(TLE9186_TSLEW_ON_OFF_HS1_ADDR);
}

/**
 * @brief Update function for shadow register of TSLEW_ON_OFF_HS1.
 *
 * This function updates the internal shadow register for the register
 * TSLEW_ON_OFF_HS1.
 *
 */
void TLE9186_RegLayer_update_TSLEW_ON_OFF_HS1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  TLE9186->TSLEW_ON_OFF_HS1.reg = u16_value;
}

/**
 * @brief Get function for register TSLEW_ON_OFF_LS1.
 *
 * This function generates the SPI message to read from the register
 * TSLEW_ON_OFF_LS1.
 *
 */
void TLE9186_RegLayer_get_TSLEW_ON_OFF_LS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186_ServLayer_getReg(TLE9186_TSLEW_ON_OFF_LS1_ADDR);
}

/**
 * @brief Update function for shadow register of TSLEW_ON_OFF_LS1.
 *
 * This function updates the internal shadow register for the register
 * TSLEW_ON_OFF_LS1.
 *
 */
void TLE9186_RegLayer_update_TSLEW_ON_OFF_LS1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  TLE9186->TSLEW_ON_OFF_LS1.reg = u16_value;
}

/**
 * @brief Get function for register TSLEW_ON_OFF_HS2.
 *
 * This function generates the SPI message to read from the register
 * TSLEW_ON_OFF_HS2.
 *
 */
void TLE9186_RegLayer_get_TSLEW_ON_OFF_HS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186_ServLayer_getReg(TLE9186_TSLEW_ON_OFF_HS2_ADDR);
}

/**
 * @brief Update function for shadow register of TSLEW_ON_OFF_HS2.
 *
 * This function updates the internal shadow register for the register
 * TSLEW_ON_OFF_HS2.
 *
 */
void TLE9186_RegLayer_update_TSLEW_ON_OFF_HS2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  TLE9186->TSLEW_ON_OFF_HS2.reg = u16_value;
}

/**
 * @brief Get function for register TSLEW_ON_OFF_LS2.
 *
 * This function generates the SPI message to read from the register
 * TSLEW_ON_OFF_LS2.
 *
 */
void TLE9186_RegLayer_get_TSLEW_ON_OFF_LS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186_ServLayer_getReg(TLE9186_TSLEW_ON_OFF_LS2_ADDR);
}

/**
 * @brief Update function for shadow register of TSLEW_ON_OFF_LS2.
 *
 * This function updates the internal shadow register for the register
 * TSLEW_ON_OFF_LS2.
 *
 */
void TLE9186_RegLayer_update_TSLEW_ON_OFF_LS2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  TLE9186->TSLEW_ON_OFF_LS2.reg = u16_value;
}

/**
 * @brief Get function for register TSLEW_ON_OFF_HS3.
 *
 * This function generates the SPI message to read from the register
 * TSLEW_ON_OFF_HS3.
 *
 */
void TLE9186_RegLayer_get_TSLEW_ON_OFF_HS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186_ServLayer_getReg(TLE9186_TSLEW_ON_OFF_HS3_ADDR);
}

/**
 * @brief Update function for shadow register of TSLEW_ON_OFF_HS3.
 *
 * This function updates the internal shadow register for the register
 * TSLEW_ON_OFF_HS3.
 *
 */
void TLE9186_RegLayer_update_TSLEW_ON_OFF_HS3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  TLE9186->TSLEW_ON_OFF_HS3.reg = u16_value;
}

/**
 * @brief Get function for register TSLEW_ON_OFF_LS3.
 *
 * This function generates the SPI message to read from the register
 * TSLEW_ON_OFF_LS3.
 *
 */
void TLE9186_RegLayer_get_TSLEW_ON_OFF_LS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186_ServLayer_getReg(TLE9186_TSLEW_ON_OFF_LS3_ADDR);
}

/**
 * @brief Update function for shadow register of TSLEW_ON_OFF_LS3.
 *
 * This function updates the internal shadow register for the register
 * TSLEW_ON_OFF_LS3.
 *
 */
void TLE9186_RegLayer_update_TSLEW_ON_OFF_LS3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  TLE9186->TSLEW_ON_OFF_LS3.reg = u16_value;
}

/**
 * @brief Get function for register DEVICE_VERSION.
 *
 * This function generates the SPI message to read from the register
 * DEVICE_VERSION.
 *
 */
void TLE9186_RegLayer_get_DEVICE_VERSION(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186_ServLayer_getReg(TLE9186_DEVICE_VERSION_ADDR);
}

/**
 * @brief Update function for shadow register of Global Status Byte.
 *
 * This function updates the internal shadow register for the Global Status
 * Byte.
 *
 */
void TLE9186_RegLayer_update_GSB(uint8 u8_value) {
  TLE9186->GSB.reg = u8_value;
}

/**
 * @}
 */
/**
 * @}
 */
