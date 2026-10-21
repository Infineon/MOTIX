/**
 *	@file TLE9186_FuncLayer.c
 *	@author Infineon Technologies AG
 *	@date 10.2026
 *	@brief TLE9186 device driver from Infineon Technologies AG..
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
 * @defgroup funcLayer Function Layer
 * @brief The Function Layer offers API function for either writing to a
 * register or reading from a register.
 * @details It additionally provides API functions to clear status bits on the
 * device.
 * @details The @ref applLayer uses these API function during initialization and
 * its cyclic task. A user is able to utilize these function for every specific
 * task.
 *
 */

#include "TLE9186_FuncLayer.h"
#include "TLE9186.h"
#include "TLE9186_ApplLayer.h"
#include "TLE9186_RegLayer.h"
#include "TLE9186_defines.h"

/**
 * @addtogroup device_driver
 * @{
 */
/**
 * @addtogroup funcLayer
 * @{
 */
/**
 * @brief Set function for register CONFIG_SECURED.
 *
 * This function sets the Power-up configuration protected register.
 *
 * @param u16_value Value to be written into the register CONFIG_SECURED.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_CONFIG_SECURED(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_CONFIG_SECURED;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for CONFIG_SECURED_FW_CFG.
 *
 * This function sets the bitfield Freewheeling device charge/discharge phase
 * configuration in register CONFIG_SECURED.
 *
 * @param u16_value Value to be written into CONFIG_SECURED_FW_CFG. Valid values
 * are:
 *      - 0: CONFIG_SECURED_FW_CFG_CONST_0 (Freewheeling device does not use
 * precharge/predischarge phase (Default)).
 *      - 1: CONFIG_SECURED_FW_CFG_CONST_1 (Freewheeling device uses
 * precharge/predischarge phase (t1ON_HS, t1ON_LS, t1OFF_HS,t1OFF_LS)).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_CONFIG_SECURED_FW_CFG(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->CONFIG_SECURED.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_CONFIG_SECURED_FW_CFG_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_CONFIG_SECURED_FW_CFG_POS) &
           (uint16)TLE9186_CONFIG_SECURED_FW_CFG_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_CONFIG_SECURED;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for CONFIG_SECURED_FW_CFG.
 *
 * This function returns the value of the bitfield Freewheeling device
 * charge/discharge phase configuration within register CONFIG_SECURED.
 *
 * @return Value of the bitfield CONFIG_SECURED_FW_CFG:
 *      - 0: CONFIG_SECURED_FW_CFG_CONST_0 (Freewheeling device does not use
 * precharge/predischarge phase (Default)).
 *      - 1: CONFIG_SECURED_FW_CFG_CONST_1 (Freewheeling device uses
 * precharge/predischarge phase (t1ON_HS, t1ON_LS, t1OFF_HS,t1OFF_LS)).
 */
uint16 TLE9186_FuncLayer_get_CONFIG_SECURED_FW_CFG(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->CONFIG_SECURED.bit.FW_CFG;
}

/**
 * @brief Set function for CONFIG_SECURED_OFF_CFG.
 *
 * This function sets the bitfield Switch OFF behavior in case of detected
 * faults leading to gate driver OFF in register CONFIG_SECURED.
 *
 * @param u16_value Value to be written into CONFIG_SECURED_OFF_CFG. Valid
 * values are:
 *      - 0: CONFIG_SECURED_OFF_CFG_CONST_0 (Turn-off gate drivers with active
 * turn-off settings (default)).
 *      - 1: CONFIG_SECURED_OFF_CFG_CONST_1 (Static using I1OFF for T1OFF and
 * IDCHG_ST for TCCP).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_CONFIG_SECURED_OFF_CFG(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->CONFIG_SECURED.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_CONFIG_SECURED_OFF_CFG_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_CONFIG_SECURED_OFF_CFG_POS) &
           (uint16)TLE9186_CONFIG_SECURED_OFF_CFG_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_CONFIG_SECURED;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for CONFIG_SECURED_OFF_CFG.
 *
 * This function returns the value of the bitfield Switch OFF behavior in case
 * of detected faults leading to gate driver OFF within register CONFIG_SECURED.
 *
 * @return Value of the bitfield CONFIG_SECURED_OFF_CFG:
 *      - 0: CONFIG_SECURED_OFF_CFG_CONST_0 (Turn-off gate drivers with active
 * turn-off settings (default)).
 *      - 1: CONFIG_SECURED_OFF_CFG_CONST_1 (Static using I1OFF for T1OFF and
 * IDCHG_ST for TCCP).
 */
uint16 TLE9186_FuncLayer_get_CONFIG_SECURED_OFF_CFG(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->CONFIG_SECURED.bit.OFF_CFG;
}

/**
 * @brief Set function for CONFIG_SECURED_GDRV_CFG.
 *
 * This function sets the bitfield Gate Driver Operation Mode Configuration in
 * register CONFIG_SECURED.
 *
 * @param u16_value Value to be written into CONFIG_SECURED_GDRV_CFG. Valid
 * values are:
 *      - 0: CONFIG_SECURED_GDRV_CFG_CONST_0 (Gate Driver SPI configured timing
 * for sequencer phase changes (Default)).
 *      - 1: CONFIG_SECURED_GDRV_CFG_CONST_1 (Gate Driver Automatic sequencer
 * phase transitions based on SHx sensing).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_CONFIG_SECURED_GDRV_CFG(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->CONFIG_SECURED.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_CONFIG_SECURED_GDRV_CFG_MSK)) |
         ((((uint16)(u16_value)
            << (uint16)TLE9186_CONFIG_SECURED_GDRV_CFG_POS) &
           (uint16)TLE9186_CONFIG_SECURED_GDRV_CFG_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_CONFIG_SECURED;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for CONFIG_SECURED_GDRV_CFG.
 *
 * This function returns the value of the bitfield Gate Driver Operation Mode
 * Configuration within register CONFIG_SECURED.
 *
 * @return Value of the bitfield CONFIG_SECURED_GDRV_CFG:
 *      - 0: CONFIG_SECURED_GDRV_CFG_CONST_0 (Gate Driver SPI configured timing
 * for sequencer phase changes (Default)).
 *      - 1: CONFIG_SECURED_GDRV_CFG_CONST_1 (Gate Driver Automatic sequencer
 * phase transitions based on SHx sensing).
 */
uint16 TLE9186_FuncLayer_get_CONFIG_SECURED_GDRV_CFG(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->CONFIG_SECURED.bit.GDRV_CFG;
}

/**
 * @brief Set function for CONFIG_SECURED_GDRV_RNG.
 *
 * This function sets the bitfield Gate Driver Output Current Range
 * Configuration in register CONFIG_SECURED.
 *
 * @param u16_value Value to be written into CONFIG_SECURED_GDRV_RNG. Valid
 * values are:
 *      - 0: CONFIG_SECURED_GDRV_RNG_CONST_0 (Gate Driver output current range
 * configured to 0.5mA...100mA (Default)).
 *      - 1: CONFIG_SECURED_GDRV_RNG_CONST_1 (Gate Driver output current range
 * configured to 1mA...150mA).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_CONFIG_SECURED_GDRV_RNG(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->CONFIG_SECURED.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_CONFIG_SECURED_GDRV_RNG_MSK)) |
         ((((uint16)(u16_value)
            << (uint16)TLE9186_CONFIG_SECURED_GDRV_RNG_POS) &
           (uint16)TLE9186_CONFIG_SECURED_GDRV_RNG_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_CONFIG_SECURED;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for CONFIG_SECURED_GDRV_RNG.
 *
 * This function returns the value of the bitfield Gate Driver Output Current
 * Range Configuration within register CONFIG_SECURED.
 *
 * @return Value of the bitfield CONFIG_SECURED_GDRV_RNG:
 *      - 0: CONFIG_SECURED_GDRV_RNG_CONST_0 (Gate Driver output current range
 * configured to 0.5mA...100mA (Default)).
 *      - 1: CONFIG_SECURED_GDRV_RNG_CONST_1 (Gate Driver output current range
 * configured to 1mA...150mA).
 */
uint16 TLE9186_FuncLayer_get_CONFIG_SECURED_GDRV_RNG(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->CONFIG_SECURED.bit.GDRV_RNG;
}

/**
 * @brief Set function for CONFIG_SECURED_VIO_CFG.
 *
 * This function sets the bitfield VIO voltage level configuration bits in
 * register CONFIG_SECURED.
 *
 * @param u16_value Value to be written into CONFIG_SECURED_VIO_CFG. Valid
 * values are:
 *      - 0: CONFIG_SECURED_VIO_CFG_CONST_0 (VIO not configured, monitoring VIO
 * thresholds (VIO_UV  threshold ~3V, VIO_OV threshold ~5.45V ) (Default)).
 *      - 1: CONFIG_SECURED_VIO_CFG_CONST_1 (VIO configured as 5V supply level).
 *      - 2: CONFIG_SECURED_VIO_CFG_CONST_2 (VIO configured as 3.3V supply
 * level).
 *      - 3: CONFIG_SECURED_VIO_CFG_CONST_3 (VIO not configured, monitoring VIO
 * thresholds (VIO_UV  threshold ~3V, VIO_OV threshold ~5.45V )).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_CONFIG_SECURED_VIO_CFG(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->CONFIG_SECURED.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_CONFIG_SECURED_VIO_CFG_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_CONFIG_SECURED_VIO_CFG_POS) &
           (uint16)TLE9186_CONFIG_SECURED_VIO_CFG_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_CONFIG_SECURED;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for CONFIG_SECURED_VIO_CFG.
 *
 * This function returns the value of the bitfield VIO voltage level
 * configuration bits within register CONFIG_SECURED.
 *
 * @return Value of the bitfield CONFIG_SECURED_VIO_CFG:
 *      - 0: CONFIG_SECURED_VIO_CFG_CONST_0 (VIO not configured, monitoring VIO
 * thresholds (VIO_UV  threshold ~3V, VIO_OV threshold ~5.45V ) (Default)).
 *      - 1: CONFIG_SECURED_VIO_CFG_CONST_1 (VIO configured as 5V supply level).
 *      - 2: CONFIG_SECURED_VIO_CFG_CONST_2 (VIO configured as 3.3V supply
 * level).
 *      - 3: CONFIG_SECURED_VIO_CFG_CONST_3 (VIO not configured, monitoring VIO
 * thresholds (VIO_UV  threshold ~3V, VIO_OV threshold ~5.45V )).
 */
uint16 TLE9186_FuncLayer_get_CONFIG_SECURED_VIO_CFG(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->CONFIG_SECURED.bit.VIO_CFG;
}

/**
 * @brief Set function for CONFIG_SECURED_SPI_TYPE.
 *
 * This function sets the bitfield SPI SDO response type configuration bits in
 * register CONFIG_SECURED.
 *
 * @param u16_value Value to be written into CONFIG_SECURED_SPI_TYPE. Valid
 * values are:
 *      - 0: CONFIG_SECURED_SPY_TYPE_CONST_0 (reserved).
 *      - 1: CONFIG_SECURED_SPY_TYPE_CONST_1 (SPI in-frame response configured
 * (Default)).
 *      - 2: CONFIG_SECURED_SPY_TYPE_CONST_2 (SPI out-of-frame response
 * configured).
 *      - 3: CONFIG_SECURED_SPY_TYPE_CONST_3 (reserved).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_CONFIG_SECURED_SPI_TYPE(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->CONFIG_SECURED.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_CONFIG_SECURED_SPI_TYPE_MSK)) |
         ((((uint16)(u16_value)
            << (uint16)TLE9186_CONFIG_SECURED_SPI_TYPE_POS) &
           (uint16)TLE9186_CONFIG_SECURED_SPI_TYPE_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_CONFIG_SECURED;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for CONFIG_SECURED_SPI_TYPE.
 *
 * This function returns the value of the bitfield SPI SDO response type
 * configuration bits within register CONFIG_SECURED.
 *
 * @return Value of the bitfield CONFIG_SECURED_SPI_TYPE:
 *      - 0: CONFIG_SECURED_SPY_TYPE_CONST_0 (reserved).
 *      - 1: CONFIG_SECURED_SPY_TYPE_CONST_1 (SPI in-frame response configured
 * (Default)).
 *      - 2: CONFIG_SECURED_SPY_TYPE_CONST_2 (SPI out-of-frame response
 * configured).
 *      - 3: CONFIG_SECURED_SPY_TYPE_CONST_3 (reserved).
 */
uint16 TLE9186_FuncLayer_get_CONFIG_SECURED_SPI_TYPE(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->CONFIG_SECURED.bit.SPI_TYPE;
}

/**
 * @brief Set function for CONFIG_SECURED_INHN_L_CFG.
 *
 * This function sets the bitfield INHN low detection wait time configuration in
 * register CONFIG_SECURED.
 *
 * @param u16_value Value to be written into CONFIG_SECURED_INHN_L_CFG. Valid
 * values are:
 *      - 0: CONFIG_SECURED_INHN_L_CFG_CONST_0 (tINHN_L_WAIT time is not
 * restarted after a SPI command while INHN is low and current tINHN_L_WAIT not
 * expired (Default)).
 *      - 1: CONFIG_SECURED_INHN_L_CFG_CONST_1 (tINHN_L_WAIT time is restarted
 * after a SPI command while INHN is low and current tINHN_L_WAIT not expired).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_CONFIG_SECURED_INHN_L_CFG(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low]
                       * "Given due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->CONFIG_SECURED.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_CONFIG_SECURED_INHN_L_CFG_MSK)) |
         ((((uint16)(u16_value)
            << (uint16)TLE9186_CONFIG_SECURED_INHN_L_CFG_POS) &
           (uint16)TLE9186_CONFIG_SECURED_INHN_L_CFG_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_CONFIG_SECURED;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for CONFIG_SECURED_INHN_L_CFG.
 *
 * This function returns the value of the bitfield INHN low detection wait time
 * configuration within register CONFIG_SECURED.
 *
 * @return Value of the bitfield CONFIG_SECURED_INHN_L_CFG:
 *      - 0: CONFIG_SECURED_INHN_L_CFG_CONST_0 (tINHN_L_WAIT time is not
 * restarted after a SPI command while INHN is low and current tINHN_L_WAIT not
 * expired (Default)).
 *      - 1: CONFIG_SECURED_INHN_L_CFG_CONST_1 (tINHN_L_WAIT time is restarted
 * after a SPI command while INHN is low and current tINHN_L_WAIT not expired).
 */
uint16 TLE9186_FuncLayer_get_CONFIG_SECURED_INHN_L_CFG(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->CONFIG_SECURED.bit.INHN_L_CFG;
}

/**
 * @brief Set function for CONFIG_SECURED_PWM_MAP.
 *
 * This function sets the bitfield PWM mapping to gate drivers configuration in
 *register CONFIG_SECURED.
 *
 * @param u16_value Value to be written into CONFIG_SECURED_PWM_MAP. Valid
 *values are:
 *      - 0: CONFIG_SECURED_PWM_MAP_CONST_0 (IHxN used for HS drivers control,
 *ILx used for LS drivers control (Default)).
 *      - 1: CONFIG_SECURED_PWM_MAP_CONST_1 (IHxN deactivated, ILx used for
 *corresponding half-bridge HBx control (one PWM input per half-bridge)).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_CONFIG_SECURED_PWM_MAP(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->CONFIG_SECURED.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_CONFIG_SECURED_PWM_MAP_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_CONFIG_SECURED_PWM_MAP_POS) &
           (uint16)TLE9186_CONFIG_SECURED_PWM_MAP_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_CONFIG_SECURED;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for CONFIG_SECURED_PWM_MAP.
 *
 * This function returns the value of the bitfield PWM mapping to gate drivers
 *configuration within register CONFIG_SECURED.
 *
 * @return Value of the bitfield CONFIG_SECURED_PWM_MAP:
 *      - 0: CONFIG_SECURED_PWM_MAP_CONST_0 (IHxN used for HS drivers control,
 *ILx used for LS drivers control (Default)).
 *      - 1: CONFIG_SECURED_PWM_MAP_CONST_1 (IHxN deactivated, ILx used for
 *corresponding half-bridge HBx control (one PWM input per half-bridge)).
 */
uint16 TLE9186_FuncLayer_get_CONFIG_SECURED_PWM_MAP(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->CONFIG_SECURED.bit.PWM_MAP;
}

/**
 * @brief Set function for CONFIG_SECURED_WD_EN.
 *
 * This function sets the bitfield Watchdog enable in register CONFIG_SECURED.
 *
 * @param u16_value Value to be written into CONFIG_SECURED_WD_EN. Valid values
 * are:
 *      - 0: CONFIG_SECURED_WD_EN_CONST_0 (Watchdog monitoring disabled
 * (Default)).
 *      - 1: CONFIG_SECURED_WD_EN_CONST_1 (Watchdog monitoring enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_CONFIG_SECURED_WD_EN(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->CONFIG_SECURED.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_CONFIG_SECURED_WD_EN_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_CONFIG_SECURED_WD_EN_POS) &
           (uint16)TLE9186_CONFIG_SECURED_WD_EN_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_CONFIG_SECURED;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for CONFIG_SECURED_WD_EN.
 *
 * This function returns the value of the bitfield Watchdog enable within
 * register CONFIG_SECURED.
 *
 * @return Value of the bitfield CONFIG_SECURED_WD_EN:
 *      - 0: CONFIG_SECURED_WD_EN_CONST_0 (Watchdog monitoring disabled
 * (Default)).
 *      - 1: CONFIG_SECURED_WD_EN_CONST_1 (Watchdog monitoring enabled).
 */
uint16 TLE9186_FuncLayer_get_CONFIG_SECURED_WD_EN(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->CONFIG_SECURED.bit.WD_EN;
}

/**
 * @brief Set function for CONFIG_SECURED_CP_CFG.
 *
 * This function sets the bitfield Charge pump Configuration  in register
 * CONFIG_SECURED.
 *
 * @param u16_value Value to be written into CONFIG_SECURED_CP_CFG. Valid values
 * are:
 *      - 0: CONFIG_SECURED_CP_CFG_CONST_0 (Two Stage Charge Pump configuration
 * at low VSCP (Default)).
 *      - 1: CONFIG_SECURED_CP_CFG_CONST_1 (Three-Stage Charge Pump
 * configuration at low VSCP).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_CONFIG_SECURED_CP_CFG(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->CONFIG_SECURED.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_CONFIG_SECURED_CP_CFG_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_CONFIG_SECURED_CP_CFG_POS) &
           (uint16)TLE9186_CONFIG_SECURED_CP_CFG_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_CONFIG_SECURED;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for CONFIG_SECURED_CP_CFG.
 *
 * This function returns the value of the bitfield Charge pump Configuration
 * within register CONFIG_SECURED.
 *
 * @return Value of the bitfield CONFIG_SECURED_CP_CFG:
 *      - 0: CONFIG_SECURED_CP_CFG_CONST_0 (Two Stage Charge Pump configuration
 * at low VSCP (Default)).
 *      - 1: CONFIG_SECURED_CP_CFG_CONST_1 (Three-Stage Charge Pump
 * configuration at low VSCP).
 */
uint16 TLE9186_FuncLayer_get_CONFIG_SECURED_CP_CFG(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->CONFIG_SECURED.bit.CP_CFG;
}

/**
 * @brief Set function for CONFIG_SECURED_CP_CLK_SEL.
 *
 * This function sets the bitfield Charge Pump Clock selection in register
 * CONFIG_SECURED.
 *
 * @param u16_value Value to be written into CONFIG_SECURED_CP_CLK_SEL. Valid
 * values are:
 *      - 0: CONFIG_SECURED_CP_CLK_SEL_CONST_0 (250kHz (Default)).
 *      - 1: CONFIG_SECURED_CP_CLK_SEL_CONST_1 (225kHz).
 *      - 2: CONFIG_SECURED_CP_CLK_SEL_CONST_2 (200kHz).
 *      - 3: CONFIG_SECURED_CP_CLK_SEL_CONST_3 (175kHz).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_CONFIG_SECURED_CP_CLK_SEL(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low]
                       * "Given due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->CONFIG_SECURED.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_CONFIG_SECURED_CP_CLK_SEL_MSK)) |
         ((((uint16)(u16_value)
            << (uint16)TLE9186_CONFIG_SECURED_CP_CLK_SEL_POS) &
           (uint16)TLE9186_CONFIG_SECURED_CP_CLK_SEL_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_CONFIG_SECURED;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for CONFIG_SECURED_CP_CLK_SEL.
 *
 * This function returns the value of the bitfield Charge Pump Clock selection
 * within register CONFIG_SECURED.
 *
 * @return Value of the bitfield CONFIG_SECURED_CP_CLK_SEL:
 *      - 0: CONFIG_SECURED_CP_CLK_SEL_CONST_0 (250kHz (Default)).
 *      - 1: CONFIG_SECURED_CP_CLK_SEL_CONST_1 (225kHz).
 *      - 2: CONFIG_SECURED_CP_CLK_SEL_CONST_2 (200kHz).
 *      - 3: CONFIG_SECURED_CP_CLK_SEL_CONST_3 (175kHz).
 */
uint16 TLE9186_FuncLayer_get_CONFIG_SECURED_CP_CLK_SEL(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->CONFIG_SECURED.bit.CP_CLK_SEL;
}

/**
 * @brief get function for register CONFIG_SECURED.
 *
 * This function reads the register Power-up configuration protected register.
 *
 */
void TLE9186_FuncLayer_get_CONFIG_SECURED(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  TLE9186_RegLayer_get_CONFIG_SECURED();
}

/**
 * @brief Set function for register PWR_MOD_CFG.
 *
 * This function sets the Mode control register.
 *
 * @param u16_value Value to be written into the register PWR_MOD_CFG.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_PWR_MOD_CFG(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_PWR_MOD_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for PWR_MOD_CFG_MODE_CTRL.
 *
 * This function sets the bitfield Device operation mode configuration in
 * register PWR_MOD_CFG.
 *
 * @param u16_value Value to be written into PWR_MOD_CFG_MODE_CTRL. Valid values
 * are:
 *      - 0: PWR_MOD_CFG_MODE_CTRL_CONST_0 (reserved).
 *      - 1: PWR_MOD_CFG_MODE_CTRL_CONST_1 (Normal operation mode selected).
 *      - 2: PWR_MOD_CFG_MODE_CTRL_CONST_2 (Power-up mode selected (Default)).
 *      - 3: PWR_MOD_CFG_MODE_CTRL_CONST_3 (reserved).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_PWR_MOD_CFG_MODE_CTRL(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->PWR_MOD_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_PWR_MOD_CFG_MODE_CTRL_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_PWR_MOD_CFG_MODE_CTRL_POS) &
           (uint16)TLE9186_PWR_MOD_CFG_MODE_CTRL_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_PWR_MOD_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for PWR_MOD_CFG_MODE_CTRL.
 *
 * This function returns the value of the bitfield Device operation mode
 * configuration within register PWR_MOD_CFG.
 *
 * @return Value of the bitfield PWR_MOD_CFG_MODE_CTRL:
 *      - 0: PWR_MOD_CFG_MODE_CTRL_CONST_0 (reserved).
 *      - 1: PWR_MOD_CFG_MODE_CTRL_CONST_1 (Normal operation mode selected).
 *      - 2: PWR_MOD_CFG_MODE_CTRL_CONST_2 (Power-up mode selected (Default)).
 *      - 3: PWR_MOD_CFG_MODE_CTRL_CONST_3 (reserved).
 */
uint16 TLE9186_FuncLayer_get_PWR_MOD_CFG_MODE_CTRL(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->PWR_MOD_CFG.bit.MODE_CTRL;
}

/**
 * @brief Set function for PWR_MOD_CFG_CLR_STATS.
 *
 * This function sets the bitfield Clear SPI device status registers in register
 * PWR_MOD_CFG.
 *
 * @param u16_value Value to be written into PWR_MOD_CFG_CLR_STATS. Valid values
 * are:
 *      - 0: PWR_MOD_CFG_CLR_STATS_CONST_0 (SPI status registers not cleared
 * (Default)).
 *      - 1: PWR_MOD_CFG_CLR_STATS_CONST_1 (Trigger SPI status registers clear).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_PWR_MOD_CFG_CLR_STATS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->PWR_MOD_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_PWR_MOD_CFG_CLR_STATS_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_PWR_MOD_CFG_CLR_STATS_POS) &
           (uint16)TLE9186_PWR_MOD_CFG_CLR_STATS_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_PWR_MOD_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for PWR_MOD_CFG_CLR_STATS.
 *
 * This function returns the value of the bitfield Clear SPI device status
 * registers within register PWR_MOD_CFG.
 *
 * @return Value of the bitfield PWR_MOD_CFG_CLR_STATS:
 *      - 0: PWR_MOD_CFG_CLR_STATS_CONST_0 (SPI status registers not cleared
 * (Default)).
 *      - 1: PWR_MOD_CFG_CLR_STATS_CONST_1 (Trigger SPI status registers clear).
 */
uint16 TLE9186_FuncLayer_get_PWR_MOD_CFG_CLR_STATS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->PWR_MOD_CFG.bit.CLR_STATS;
}

/**
 * @brief Set function for PWR_MOD_CFG_CLR_CONFIG.
 *
 * This function sets the bitfield Clear SPI device configuration registers in
 * register PWR_MOD_CFG.
 *
 * @param u16_value Value to be written into PWR_MOD_CFG_CLR_CONFIG. Valid
 * values are:
 *      - 0: PWR_MOD_CFG_CLR_CONFIG_CONST_0 (SPI configuration registers not
 * cleared (Default)).
 *      - 1: PWR_MOD_CFG_CLR_CONFIG_CONST_1 (Trigger SPI configuration registers
 * clear).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_PWR_MOD_CFG_CLR_CONFIG(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->PWR_MOD_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_PWR_MOD_CFG_CLR_CONFIG_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_PWR_MOD_CFG_CLR_CONFIG_POS) &
           (uint16)TLE9186_PWR_MOD_CFG_CLR_CONFIG_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_PWR_MOD_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for PWR_MOD_CFG_CLR_CONFIG.
 *
 * This function returns the value of the bitfield Clear SPI device
 * configuration registers within register PWR_MOD_CFG.
 *
 * @return Value of the bitfield PWR_MOD_CFG_CLR_CONFIG:
 *      - 0: PWR_MOD_CFG_CLR_CONFIG_CONST_0 (SPI configuration registers not
 * cleared (Default)).
 *      - 1: PWR_MOD_CFG_CLR_CONFIG_CONST_1 (Trigger SPI configuration registers
 * clear).
 */
uint16 TLE9186_FuncLayer_get_PWR_MOD_CFG_CLR_CONFIG(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->PWR_MOD_CFG.bit.CLR_CONFIG;
}

/**
 * @brief get function for register PWR_MOD_CFG.
 *
 * This function reads the register Mode control register.
 *
 */
void TLE9186_FuncLayer_get_PWR_MOD_CFG(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186_RegLayer_get_PWR_MOD_CFG();
}

/**
 * @brief Set function for register WD_CFG.
 *
 * This function sets the Watchdog configuration register.
 *
 * @param u16_value Value to be written into the register WD_CFG.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_WD_CFG(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_WD_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for WD_CFG_WD_PER.
 *
 * This function sets the bitfield Watchdog period configuration in register
 * WD_CFG.
 *
 * @param u16_value Value to be written into WD_CFG_WD_PER. Valid values are:
 *      - 0: WD_CFG_WD_PER_CONST_0 (2ms).
 *      - 1: WD_CFG_WD_PER_CONST_1 (4ms).
 *      - 2: WD_CFG_WD_PER_CONST_2 (8ms).
 *      - 3: WD_CFG_WD_PER_CONST_3 (16ms).
 *      - 4: WD_CFG_WD_PER_CONST_4 (32ms).
 *      - 5: WD_CFG_WD_PER_CONST_5 (64ms  (Default)).
 *      - 6: WD_CFG_WD_PER_CONST_6 (128ms (Default)).
 *      - 7: WD_CFG_WD_PER_CONST_7 (256ms).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_WD_CFG_WD_PER(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->WD_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_WD_CFG_WD_PER_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_WD_CFG_WD_PER_POS) &
           (uint16)TLE9186_WD_CFG_WD_PER_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_WD_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for WD_CFG_WD_PER.
 *
 * This function returns the value of the bitfield Watchdog period configuration
 * within register WD_CFG.
 *
 * @return Value of the bitfield WD_CFG_WD_PER:
 *      - 0: WD_CFG_WD_PER_CONST_0 (2ms).
 *      - 1: WD_CFG_WD_PER_CONST_1 (4ms).
 *      - 2: WD_CFG_WD_PER_CONST_2 (8ms).
 *      - 3: WD_CFG_WD_PER_CONST_3 (16ms).
 *      - 4: WD_CFG_WD_PER_CONST_4 (32ms).
 *      - 5: WD_CFG_WD_PER_CONST_5 (64ms  (Default)).
 *      - 6: WD_CFG_WD_PER_CONST_6 (128ms (Default)).
 *      - 7: WD_CFG_WD_PER_CONST_7 (256ms).
 */
uint16 TLE9186_FuncLayer_get_WD_CFG_WD_PER(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->WD_CFG.bit.WD_PER;
}

/**
 * @brief Set function for WD_CFG_WD_FAIL.
 *
 * This function sets the bitfield Watchdog fails counter configuration in
 * register WD_CFG.
 *
 * @param u16_value Value to be written into WD_CFG_WD_FAIL. Valid values are:
 *      - 0: WD_CFG_WD_FAIL_CONST_0 (2).
 *      - 1: WD_CFG_WD_FAIL_CONST_1 (4).
 *      - 2: WD_CFG_WD_FAIL_CONST_2 (6).
 *      - 3: WD_CFG_WD_FAIL_CONST_3 (8 (Default)).
 *      - 4: WD_CFG_WD_FAIL_CONST_4 (10).
 *      - 5: WD_CFG_WD_FAIL_CONST_5 (12).
 *      - 6: WD_CFG_WD_FAIL_CONST_6 (14).
 *      - 7: WD_CFG_WD_FAIL_CONST_7 (15).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_WD_CFG_WD_FAIL(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->WD_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_WD_CFG_WD_FAIL_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_WD_CFG_WD_FAIL_POS) &
           (uint16)TLE9186_WD_CFG_WD_FAIL_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_WD_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for WD_CFG_WD_FAIL.
 *
 * This function returns the value of the bitfield Watchdog fails counter
 * configuration within register WD_CFG.
 *
 * @return Value of the bitfield WD_CFG_WD_FAIL:
 *      - 0: WD_CFG_WD_FAIL_CONST_0 (2).
 *      - 1: WD_CFG_WD_FAIL_CONST_1 (4).
 *      - 2: WD_CFG_WD_FAIL_CONST_2 (6).
 *      - 3: WD_CFG_WD_FAIL_CONST_3 (8 (Default)).
 *      - 4: WD_CFG_WD_FAIL_CONST_4 (10).
 *      - 5: WD_CFG_WD_FAIL_CONST_5 (12).
 *      - 6: WD_CFG_WD_FAIL_CONST_6 (14).
 *      - 7: WD_CFG_WD_FAIL_CONST_7 (15).
 */
uint16 TLE9186_FuncLayer_get_WD_CFG_WD_FAIL(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->WD_CFG.bit.WD_FAIL;
}

/**
 * @brief Set function for WD_CFG_CHECKSUM.
 *
 * This function sets the bitfield Watchdog configuration checksum bit in
 * register WD_CFG.
 *
 * @param u16_value Value to be written into WD_CFG_CHECKSUM. Valid values are:
 *      - 0: WD_CFG_CHECKSUM_CONST_0 (counts as 0 for checksum calculation
 * (Default)).
 *      - 1: WD_CFG_CHECKSUM_CONST_1 (counts as 1 for checksum calculation).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_WD_CFG_CHECKSUM(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->WD_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_WD_CFG_CHECKSUM_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_WD_CFG_CHECKSUM_POS) &
           (uint16)TLE9186_WD_CFG_CHECKSUM_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_WD_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for WD_CFG_CHECKSUM.
 *
 * This function returns the value of the bitfield Watchdog configuration
 * checksum bit within register WD_CFG.
 *
 * @return Value of the bitfield WD_CFG_CHECKSUM:
 *      - 0: WD_CFG_CHECKSUM_CONST_0 (counts as 0 for checksum calculation
 * (Default)).
 *      - 1: WD_CFG_CHECKSUM_CONST_1 (counts as 1 for checksum calculation).
 */
uint16 TLE9186_FuncLayer_get_WD_CFG_CHECKSUM(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->WD_CFG.bit.CHECKSUM;
}

/**
 * @brief get function for register WD_CFG.
 *
 * This function reads the register Watchdog configuration register.
 *
 */
void TLE9186_FuncLayer_get_WD_CFG(void) /* polyspace MISRA2012:5.1 [Justified:
                                           Low] "Given due to register names" */
{
  TLE9186_RegLayer_get_WD_CFG();
}

/**
 * @brief Set function for register GEN_CFG1.
 *
 * This function sets the General configuration register 1.
 *
 * @param u16_value Value to be written into the register GEN_CFG1.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for GEN_CFG1_SOFF_ON.
 *
 * This function sets the bitfield Safe State activation via SPI command in
 * register GEN_CFG1.
 *
 * @param u16_value Value to be written into GEN_CFG1_SOFF_ON. Valid values are:
 *      - 0: GEN_CFG1_SOFF_ON_CONST_0 (Safe State not forced active (Default) ).
 *      - 1: GEN_CFG1_SOFF_ON_CONST_1 (Safe State forced active ).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG1_SOFF_ON(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG1_SOFF_ON_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG1_SOFF_ON_POS) &
           (uint16)TLE9186_GEN_CFG1_SOFF_ON_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG1_SOFF_ON.
 *
 * This function returns the value of the bitfield Safe State activation via SPI
 * command within register GEN_CFG1.
 *
 * @return Value of the bitfield GEN_CFG1_SOFF_ON:
 *      - 0: GEN_CFG1_SOFF_ON_CONST_0 (Safe State not forced active (Default) ).
 *      - 1: GEN_CFG1_SOFF_ON_CONST_1 (Safe State forced active ).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG1_SOFF_ON(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GEN_CFG1.bit.SOFF_ON;
}

/**
 * @brief Set function for GEN_CFG1_ERRN_ON.
 *
 * This function sets the bitfield ERRN function activation via SPI command in
 * register GEN_CFG1.
 *
 * @param u16_value Value to be written into GEN_CFG1_ERRN_ON. Valid values are:
 *      - 0: GEN_CFG1_ERRN_ON_CONST_0 (ERRN not forced active (Default)).
 *      - 1: GEN_CFG1_ERRN_ON_CONST_1 (ERRN forced active).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG1_ERRN_ON(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG1_ERRN_ON_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG1_ERRN_ON_POS) &
           (uint16)TLE9186_GEN_CFG1_ERRN_ON_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG1_ERRN_ON.
 *
 * This function returns the value of the bitfield ERRN function activation via
 * SPI command within register GEN_CFG1.
 *
 * @return Value of the bitfield GEN_CFG1_ERRN_ON:
 *      - 0: GEN_CFG1_ERRN_ON_CONST_0 (ERRN not forced active (Default)).
 *      - 1: GEN_CFG1_ERRN_ON_CONST_1 (ERRN forced active).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG1_ERRN_ON(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GEN_CFG1.bit.ERRN_ON;
}

/**
 * @brief Set function for GEN_CFG1_TW_EN.
 *
 * This function sets the bitfield ERRN function activation via SPI command in
 * register GEN_CFG1.
 *
 * @param u16_value Value to be written into GEN_CFG1_TW_EN. Valid values are:
 *      - 0: GEN_CFG1_TW_EN_CONST_0 (Thermal warning monitoring disabled).
 *      - 1: GEN_CFG1_TW_EN_CONST_1 (Thermal warning monitoring enabled
 * (Default)).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG1_TW_EN(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG1_TW_EN_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG1_TW_EN_POS) &
           (uint16)TLE9186_GEN_CFG1_TW_EN_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG1_TW_EN.
 *
 * This function returns the value of the bitfield ERRN function activation via
 * SPI command within register GEN_CFG1.
 *
 * @return Value of the bitfield GEN_CFG1_TW_EN:
 *      - 0: GEN_CFG1_TW_EN_CONST_0 (Thermal warning monitoring disabled).
 *      - 1: GEN_CFG1_TW_EN_CONST_1 (Thermal warning monitoring enabled
 * (Default)).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG1_TW_EN(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GEN_CFG1.bit.TW_EN;
}

/**
 * @brief Set function for GEN_CFG1_CSA_EN.
 *
 * This function sets the bitfield Current sense amplifier enable in register
 * GEN_CFG1.
 *
 * @param u16_value Value to be written into GEN_CFG1_CSA_EN. Valid values are:
 *      - 0: GEN_CFG1_CSA_EN_CONST_0 (Current sense amplifier disabled
 * (Default)).
 *      - 1: GEN_CFG1_CSA_EN_CONST_1 (Current sense amplifier enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG1_CSA_EN(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG1_CSA_EN_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG1_CSA_EN_POS) &
           (uint16)TLE9186_GEN_CFG1_CSA_EN_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG1_CSA_EN.
 *
 * This function returns the value of the bitfield Current sense amplifier
 * enable within register GEN_CFG1.
 *
 * @return Value of the bitfield GEN_CFG1_CSA_EN:
 *      - 0: GEN_CFG1_CSA_EN_CONST_0 (Current sense amplifier disabled
 * (Default)).
 *      - 1: GEN_CFG1_CSA_EN_CONST_1 (Current sense amplifier enabled).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG1_CSA_EN(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GEN_CFG1.bit.CSA_EN;
}

/**
 * @brief Set function for GEN_CFG1_HBFREQ.
 *
 * This function sets the bitfield Half-bridge synchronization frequency in
 * register GEN_CFG1.
 *
 * @param u16_value Value to be written into GEN_CFG1_HBFREQ. Valid values are:
 *      - 0: GEN_CFG1_HBFREQ_CONST_0 (75MHz (Default)).
 *      - 1: GEN_CFG1_HBFREQ_CONST_1 (37.5MHz).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG1_HBFREQ(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG1_HBFREQ_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG1_HBFREQ_POS) &
           (uint16)TLE9186_GEN_CFG1_HBFREQ_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG1_HBFREQ.
 *
 * This function returns the value of the bitfield Half-bridge synchronization
 * frequency within register GEN_CFG1.
 *
 * @return Value of the bitfield GEN_CFG1_HBFREQ:
 *      - 0: GEN_CFG1_HBFREQ_CONST_0 (75MHz (Default)).
 *      - 1: GEN_CFG1_HBFREQ_CONST_1 (37.5MHz).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG1_HBFREQ(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GEN_CFG1.bit.HBFREQ;
}

/**
 * @brief Set function for GEN_CFG1_HB1_EN.
 *
 * This function sets the bitfield Half-bridge 1 enable in register GEN_CFG1.
 *
 * @param u16_value Value to be written into GEN_CFG1_HB1_EN. Valid values are:
 *      - 0: GEN_CFG1_HB1_EN_CONST_0 (Half-bridge 1 disabled (Default)).
 *      - 1: GEN_CFG1_HB1_EN_CONST_1 (Half-bridge 1 enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG1_HB1_EN(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG1_HB1_EN_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG1_HB1_EN_POS) &
           (uint16)TLE9186_GEN_CFG1_HB1_EN_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG1_HB1_EN.
 *
 * This function returns the value of the bitfield Half-bridge 1 enable within
 * register GEN_CFG1.
 *
 * @return Value of the bitfield GEN_CFG1_HB1_EN:
 *      - 0: GEN_CFG1_HB1_EN_CONST_0 (Half-bridge 1 disabled (Default)).
 *      - 1: GEN_CFG1_HB1_EN_CONST_1 (Half-bridge 1 enabled).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG1_HB1_EN(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GEN_CFG1.bit.HB1_EN;
}

/**
 * @brief Set function for GEN_CFG1_HB2_EN.
 *
 * This function sets the bitfield Half-bridge 2 enable in register GEN_CFG1.
 *
 * @param u16_value Value to be written into GEN_CFG1_HB2_EN. Valid values are:
 *      - 0: GEN_CFG1_HB2_EN_CONST_0 (Half-bridge 2 disabled (Default)).
 *      - 1: GEN_CFG1_HB2_EN_CONST_1 (Half-bridge 2 enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG1_HB2_EN(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG1_HB2_EN_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG1_HB2_EN_POS) &
           (uint16)TLE9186_GEN_CFG1_HB2_EN_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG1_HB2_EN.
 *
 * This function returns the value of the bitfield Half-bridge 2 enable within
 * register GEN_CFG1.
 *
 * @return Value of the bitfield GEN_CFG1_HB2_EN:
 *      - 0: GEN_CFG1_HB2_EN_CONST_0 (Half-bridge 2 disabled (Default)).
 *      - 1: GEN_CFG1_HB2_EN_CONST_1 (Half-bridge 2 enabled).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG1_HB2_EN(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GEN_CFG1.bit.HB2_EN;
}

/**
 * @brief Set function for GEN_CFG1_HB3_EN.
 *
 * This function sets the bitfield Half-bridge 3 enable in register GEN_CFG1.
 *
 * @param u16_value Value to be written into GEN_CFG1_HB3_EN. Valid values are:
 *      - 0: GEN_CFG1_HB3_EN_CONST_0 (Half-bridge 3 disabled (Default)).
 *      - 1: GEN_CFG1_HB3_EN_CONST_1 (Half-bridge 3 enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG1_HB3_EN(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG1_HB3_EN_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG1_HB3_EN_POS) &
           (uint16)TLE9186_GEN_CFG1_HB3_EN_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG1_HB3_EN.
 *
 * This function returns the value of the bitfield Half-bridge 3 enable within
 * register GEN_CFG1.
 *
 * @return Value of the bitfield GEN_CFG1_HB3_EN:
 *      - 0: GEN_CFG1_HB3_EN_CONST_0 (Half-bridge 3 disabled (Default)).
 *      - 1: GEN_CFG1_HB3_EN_CONST_1 (Half-bridge 3 enabled).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG1_HB3_EN(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GEN_CFG1.bit.HB3_EN;
}

/**
 * @brief Set function for GEN_CFG1_PFB_EN.
 *
 * This function sets the bitfield Phase feedback monitoring enable in register
 * GEN_CFG1.
 *
 * @param u16_value Value to be written into GEN_CFG1_PFB_EN. Valid values are:
 *      - 0: GEN_CFG1_PFB_EN_CONST_0 (PFB function disabled).
 *      - 1: GEN_CFG1_PFB_EN_CONST_1 (PFB function enabled (Default)).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG1_PFB_EN(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG1_PFB_EN_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG1_PFB_EN_POS) &
           (uint16)TLE9186_GEN_CFG1_PFB_EN_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG1_PFB_EN.
 *
 * This function returns the value of the bitfield Phase feedback monitoring
 * enable within register GEN_CFG1.
 *
 * @return Value of the bitfield GEN_CFG1_PFB_EN:
 *      - 0: GEN_CFG1_PFB_EN_CONST_0 (PFB function disabled).
 *      - 1: GEN_CFG1_PFB_EN_CONST_1 (PFB function enabled (Default)).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG1_PFB_EN(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GEN_CFG1.bit.PFB_EN;
}

/**
 * @brief Set function for GEN_CFG1_CP_REC_OV.
 *
 * This function sets the bitfield Charge pump recovery in case of VSCP_OV_SD
 * event in register GEN_CFG1.
 *
 * @param u16_value Value to be written into GEN_CFG1_CP_REC_OV. Valid values
 * are:
 *      - 0: GEN_CFG1_CP_REC_OV_CONST_0 (Automatic restart disabled (Default)).
 *      - 1: GEN_CFG1_CP_REC_OV_CONST_1 (Automatic restart enabled, Charge pump
 * restarts when  VSCP_OV_SD event not present anymore).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG1_CP_REC_OV(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG1_CP_REC_OV_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG1_CP_REC_OV_POS) &
           (uint16)TLE9186_GEN_CFG1_CP_REC_OV_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG1_CP_REC_OV.
 *
 * This function returns the value of the bitfield Charge pump recovery in case
 * of VSCP_OV_SD event within register GEN_CFG1.
 *
 * @return Value of the bitfield GEN_CFG1_CP_REC_OV:
 *      - 0: GEN_CFG1_CP_REC_OV_CONST_0 (Automatic restart disabled (Default)).
 *      - 1: GEN_CFG1_CP_REC_OV_CONST_1 (Automatic restart enabled, Charge pump
 * restarts when  VSCP_OV_SD event not present anymore).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG1_CP_REC_OV(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GEN_CFG1.bit.CP_REC_OV;
}

/**
 * @brief Set function for GEN_CFG1_CP_REC_UV.
 *
 * This function sets the bitfield Charge pump recovery in case of VSCP_UV_SD
 * event in register GEN_CFG1.
 *
 * @param u16_value Value to be written into GEN_CFG1_CP_REC_UV. Valid values
 * are:
 *      - 0: GEN_CFG1_CP_REC_UV_CONST_0 (Automatic restart disabled (Default)).
 *      - 1: GEN_CFG1_CP_REC_UV_CONST_1 (Automatic restart enabled, Charge pump
 * restarts when  VSCP_UV_SD event not present anymore).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG1_CP_REC_UV(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG1_CP_REC_UV_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG1_CP_REC_UV_POS) &
           (uint16)TLE9186_GEN_CFG1_CP_REC_UV_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG1_CP_REC_UV.
 *
 * This function returns the value of the bitfield Charge pump recovery in case
 * of VSCP_UV_SD event within register GEN_CFG1.
 *
 * @return Value of the bitfield GEN_CFG1_CP_REC_UV:
 *      - 0: GEN_CFG1_CP_REC_UV_CONST_0 (Automatic restart disabled (Default)).
 *      - 1: GEN_CFG1_CP_REC_UV_CONST_1 (Automatic restart enabled, Charge pump
 * restarts when  VSCP_UV_SD event not present anymore).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG1_CP_REC_UV(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GEN_CFG1.bit.CP_REC_UV;
}

/**
 * @brief Set function for GEN_CFG1_CP_FMOD.
 *
 * This function sets the bitfield Charge pump frequency modulation
 * configuration in register GEN_CFG1.
 *
 * @param u16_value Value to be written into GEN_CFG1_CP_FMOD. Valid values are:
 *      - 0: GEN_CFG1_CP_FMOD_CONST_0 (Frequency modulation disabled).
 *      - 1: GEN_CFG1_CP_FMOD_CONST_1 (Modulation frequency set to 15.6kHz
 * (Default)).
 *      - 2: GEN_CFG1_CP_FMOD_CONST_2 (Modulation frequency set to 31.2kHz).
 *      - 3: GEN_CFG1_CP_FMOD_CONST_3 (Modulation frequency set to 62.5kHz).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG1_CP_FMOD(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG1_CP_FMOD_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG1_CP_FMOD_POS) &
           (uint16)TLE9186_GEN_CFG1_CP_FMOD_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG1_CP_FMOD.
 *
 * This function returns the value of the bitfield Charge pump frequency
 * modulation configuration within register GEN_CFG1.
 *
 * @return Value of the bitfield GEN_CFG1_CP_FMOD:
 *      - 0: GEN_CFG1_CP_FMOD_CONST_0 (Frequency modulation disabled).
 *      - 1: GEN_CFG1_CP_FMOD_CONST_1 (Modulation frequency set to 15.6kHz
 * (Default)).
 *      - 2: GEN_CFG1_CP_FMOD_CONST_2 (Modulation frequency set to 31.2kHz).
 *      - 3: GEN_CFG1_CP_FMOD_CONST_3 (Modulation frequency set to 62.5kHz).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG1_CP_FMOD(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GEN_CFG1.bit.CP_FMOD;
}

/**
 * @brief Set function for GEN_CFG1_CP_MODE.
 *
 * This function sets the bitfield Charge Pump Operation Mode configuration bits
 * in register GEN_CFG1.
 *
 * @param u16_value Value to be written into GEN_CFG1_CP_MODE. Valid values are:
 *      - 0: GEN_CFG1_CP_CFG_CONST_0 (Charge Pump forced in double stage(if
 * CP_CFG=0) or three-stage (if CP_CFG=1) charge pump operation mode).
 *      - 1: GEN_CFG1_CP_CFG_CONST_1 (Charge pump forced in double stage charge
 * pump operation mode).
 *      - 2: GEN_CFG1_CP_CFG_CONST_2 (Charge pump forced in single stage charge
 * pump operation mode).
 *      - 3: GEN_CFG1_CP_CFG_CONST_3 (Charge pump automatic operation mode
 * change enabled (Default)).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG1_CP_MODE(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG1_CP_MODE_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG1_CP_MODE_POS) &
           (uint16)TLE9186_GEN_CFG1_CP_MODE_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG1_CP_MODE.
 *
 * This function returns the value of the bitfield Charge Pump Operation Mode
 * configuration bits within register GEN_CFG1.
 *
 * @return Value of the bitfield GEN_CFG1_CP_MODE:
 *      - 0: GEN_CFG1_CP_CFG_CONST_0 (Charge Pump forced in double stage(if
 * CP_CFG=0) or three-stage (if CP_CFG=1) charge pump operation mode).
 *      - 1: GEN_CFG1_CP_CFG_CONST_1 (Charge pump forced in double stage charge
 * pump operation mode).
 *      - 2: GEN_CFG1_CP_CFG_CONST_2 (Charge pump forced in single stage charge
 * pump operation mode).
 *      - 3: GEN_CFG1_CP_CFG_CONST_3 (Charge pump automatic operation mode
 * change enabled (Default)).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG1_CP_MODE(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GEN_CFG1.bit.CP_MODE;
}

/**
 * @brief Set function for GEN_CFG1_CP_EN.
 *
 * This function sets the bitfield Charge pump function enable in register
 * GEN_CFG1.
 *
 * @param u16_value Value to be written into GEN_CFG1_CP_EN. Valid values are:
 *      - 0: GEN_CFG1_CP_EN_CONST_0 (Charge pump disabled (Default)).
 *      - 1: GEN_CFG1_CP_EN_CONST_1 (Charge pump enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG1_CP_EN(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG1_CP_EN_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG1_CP_EN_POS) &
           (uint16)TLE9186_GEN_CFG1_CP_EN_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG1_CP_EN.
 *
 * This function returns the value of the bitfield Charge pump function enable
 * within register GEN_CFG1.
 *
 * @return Value of the bitfield GEN_CFG1_CP_EN:
 *      - 0: GEN_CFG1_CP_EN_CONST_0 (Charge pump disabled (Default)).
 *      - 1: GEN_CFG1_CP_EN_CONST_1 (Charge pump enabled).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG1_CP_EN(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GEN_CFG1.bit.CP_EN;
}

/**
 * @brief get function for register GEN_CFG1.
 *
 * This function reads the register General configuration register 1.
 *
 */
void TLE9186_FuncLayer_get_GEN_CFG1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_GEN_CFG1();
}

/**
 * @brief Set function for register GEN_CFG2.
 *
 * This function sets the General configuration register 2.
 *
 * @param u16_value Value to be written into the register GEN_CFG2.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for GEN_CFG2_OFF_DIAG_EN.
 *
 * This function sets the bitfield OFF-state diagnostic function enable in
 * register GEN_CFG2.
 *
 * @param u16_value Value to be written into GEN_CFG2_OFF_DIAG_EN. Valid values
 * are:
 *      - 0: GEN_CFG2_OFF_DIAG_EN_CONST_0 (OFF-state diagnostic disabled
 * (Default)).
 *      - 1: GEN_CFG2_OFF_DIAG_EN_CONST_1 (OFF-state diagnostic enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG2_OFF_DIAG_EN(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG2_OFF_DIAG_EN_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG2_OFF_DIAG_EN_POS) &
           (uint16)TLE9186_GEN_CFG2_OFF_DIAG_EN_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG2_OFF_DIAG_EN.
 *
 * This function returns the value of the bitfield OFF-state diagnostic function
 * enable within register GEN_CFG2.
 *
 * @return Value of the bitfield GEN_CFG2_OFF_DIAG_EN:
 *      - 0: GEN_CFG2_OFF_DIAG_EN_CONST_0 (OFF-state diagnostic disabled
 * (Default)).
 *      - 1: GEN_CFG2_OFF_DIAG_EN_CONST_1 (OFF-state diagnostic enabled).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG2_OFF_DIAG_EN(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->GEN_CFG2.bit.OFF_DIAG_EN;
}

/**
 * @brief Set function for GEN_CFG2_HB1IDIAG.
 *
 * This function sets the bitfield OFF-state diagnostic control of HB1 pull-down
 * current in register GEN_CFG2.
 *
 * @param u16_value Value to be written into GEN_CFG2_HB1IDIAG. Valid values
 * are:
 *      - 0: GEN_CFG2_HB1IDIAG_CONST_0 (Pull-down current for off-state
 * diagnostics disabled (Default)).
 *      - 1: GEN_CFG2_HB1IDIAG_CONST_1 (Pull-down current for off-state
 * diagnostics enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG2_HB1IDIAG(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG2_HB1IDIAG_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG2_HB1IDIAG_POS) &
           (uint16)TLE9186_GEN_CFG2_HB1IDIAG_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG2_HB1IDIAG.
 *
 * This function returns the value of the bitfield OFF-state diagnostic control
 * of HB1 pull-down current within register GEN_CFG2.
 *
 * @return Value of the bitfield GEN_CFG2_HB1IDIAG:
 *      - 0: GEN_CFG2_HB1IDIAG_CONST_0 (Pull-down current for off-state
 * diagnostics disabled (Default)).
 *      - 1: GEN_CFG2_HB1IDIAG_CONST_1 (Pull-down current for off-state
 * diagnostics enabled).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG2_HB1IDIAG(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GEN_CFG2.bit.HB1IDIAG;
}

/**
 * @brief Set function for GEN_CFG2_HB2IDIAG.
 *
 * This function sets the bitfield OFF-state diagnostic control of HB2 pull-down
 * current in register GEN_CFG2.
 *
 * @param u16_value Value to be written into GEN_CFG2_HB2IDIAG. Valid values
 * are:
 *      - 0: GEN_CFG2_HB2IDIAG_CONST_0 (Pull-down current for off-state
 * diagnostics disabled (Default)).
 *      - 1: GEN_CFG2_HB2IDIAG_CONST_1 (Pull-down current for off-state
 * diagnostics enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG2_HB2IDIAG(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG2_HB2IDIAG_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG2_HB2IDIAG_POS) &
           (uint16)TLE9186_GEN_CFG2_HB2IDIAG_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG2_HB2IDIAG.
 *
 * This function returns the value of the bitfield OFF-state diagnostic control
 * of HB2 pull-down current within register GEN_CFG2.
 *
 * @return Value of the bitfield GEN_CFG2_HB2IDIAG:
 *      - 0: GEN_CFG2_HB2IDIAG_CONST_0 (Pull-down current for off-state
 * diagnostics disabled (Default)).
 *      - 1: GEN_CFG2_HB2IDIAG_CONST_1 (Pull-down current for off-state
 * diagnostics enabled).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG2_HB2IDIAG(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GEN_CFG2.bit.HB2IDIAG;
}

/**
 * @brief Set function for GEN_CFG2_HB3IDIAG.
 *
 * This function sets the bitfield OFF-state diagnostic control of HB3 pull-down
 * current in register GEN_CFG2.
 *
 * @param u16_value Value to be written into GEN_CFG2_HB3IDIAG. Valid values
 * are:
 *      - 0: GEN_CFG2_HB3IDIAG_CONST_0 (Pull-down current for off-state
 * diagnostics disabled (Default)).
 *      - 1: GEN_CFG2_HB3IDIAG_CONST_1 (Pull-down current for off-state
 * diagnostics enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG2_HB3IDIAG(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG2_HB3IDIAG_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG2_HB3IDIAG_POS) &
           (uint16)TLE9186_GEN_CFG2_HB3IDIAG_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG2_HB3IDIAG.
 *
 * This function returns the value of the bitfield OFF-state diagnostic control
 * of HB3 pull-down current within register GEN_CFG2.
 *
 * @return Value of the bitfield GEN_CFG2_HB3IDIAG:
 *      - 0: GEN_CFG2_HB3IDIAG_CONST_0 (Pull-down current for off-state
 * diagnostics disabled (Default)).
 *      - 1: GEN_CFG2_HB3IDIAG_CONST_1 (Pull-down current for off-state
 * diagnostics enabled).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG2_HB3IDIAG(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GEN_CFG2.bit.HB3IDIAG;
}

/**
 * @brief Set function for GEN_CFG2_IPV_CCP_DIS.
 *
 * This function sets the bitfield Disable input pattern violation for
 * cross-current protection in register GEN_CFG2.
 *
 * @param u16_value Value to be written into GEN_CFG2_IPV_CCP_DIS. Valid values
 * are:
 *      - 0: GEN_CFG2_IPV_CCP_DIS_CONST_0 (Input pattern violation due to
 * cross-current protection error signalized by status bits IPV_CCP_HBx
 * (Default)).
 *      - 1: GEN_CFG2_IPV_CCP_DIS_CONST_1 (Input pattern violation due to
 * cross-current protection error not signalized by status bits IPV_CCP_HBx).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG2_IPV_CCP_DIS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG2_IPV_CCP_DIS_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG2_IPV_CCP_DIS_POS) &
           (uint16)TLE9186_GEN_CFG2_IPV_CCP_DIS_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG2_IPV_CCP_DIS.
 *
 * This function returns the value of the bitfield Disable input pattern
 * violation for cross-current protection within register GEN_CFG2.
 *
 * @return Value of the bitfield GEN_CFG2_IPV_CCP_DIS:
 *      - 0: GEN_CFG2_IPV_CCP_DIS_CONST_0 (Input pattern violation due to
 * cross-current protection error signalized by status bits IPV_CCP_HBx
 * (Default)).
 *      - 1: GEN_CFG2_IPV_CCP_DIS_CONST_1 (Input pattern violation due to
 * cross-current protection error not signalized by status bits IPV_CCP_HBx).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG2_IPV_CCP_DIS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->GEN_CFG2.bit.IPV_CCP_DIS;
}

/**
 * @brief Set function for GEN_CFG2_CSN_TO_DIS.
 *
 * This function sets the bitfield CSN time-out disable option in register
 * GEN_CFG2.
 *
 * @param u16_value Value to be written into GEN_CFG2_CSN_TO_DIS. Valid values
 * are:
 *      - 0: GEN_CFG2_CSN_TO_DIS_CONST_0 (CSN time-out is enabled (Default)).
 *      - 1: GEN_CFG2_CSN_TO_DIS_CONST_1 (CSN time-out is disabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG2_CSN_TO_DIS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG2_CSN_TO_DIS_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG2_CSN_TO_DIS_POS) &
           (uint16)TLE9186_GEN_CFG2_CSN_TO_DIS_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG2_CSN_TO_DIS.
 *
 * This function returns the value of the bitfield CSN time-out disable option
 * within register GEN_CFG2.
 *
 * @return Value of the bitfield GEN_CFG2_CSN_TO_DIS:
 *      - 0: GEN_CFG2_CSN_TO_DIS_CONST_0 (CSN time-out is enabled (Default)).
 *      - 1: GEN_CFG2_CSN_TO_DIS_CONST_1 (CSN time-out is disabled).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG2_CSN_TO_DIS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->GEN_CFG2.bit.CSN_TO_DIS;
}

/**
 * @brief Set function for GEN_CFG2_CP_UV_TH.
 *
 * This function sets the bitfield Charge Pump under-voltage threshold selection
 * in register GEN_CFG2.
 *
 * @param u16_value Value to be written into GEN_CFG2_CP_UV_TH. Valid values
 * are:
 *      - 0: GEN_CFG2_CP_UV_TH_CONST_0 (VCPH_UV 8.5V typical falling threshold
 * selected (Default)).
 *      - 1: GEN_CFG2_CP_UV_TH_CONST_1 (VCPH_UV 7V typical falling threshold
 * selected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG2_CP_UV_TH(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG2_CP_UV_TH_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG2_CP_UV_TH_POS) &
           (uint16)TLE9186_GEN_CFG2_CP_UV_TH_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG2_CP_UV_TH.
 *
 * This function returns the value of the bitfield Charge Pump under-voltage
 * threshold selection within register GEN_CFG2.
 *
 * @return Value of the bitfield GEN_CFG2_CP_UV_TH:
 *      - 0: GEN_CFG2_CP_UV_TH_CONST_0 (VCPH_UV 8.5V typical falling threshold
 * selected (Default)).
 *      - 1: GEN_CFG2_CP_UV_TH_CONST_1 (VCPH_UV 7V typical falling threshold
 * selected).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG2_CP_UV_TH(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GEN_CFG2.bit.CP_UV_TH;
}

/**
 * @brief Set function for GEN_CFG2_TW_TH.
 *
 * This function sets the bitfield Temperature warning threshold selection in
 * register GEN_CFG2.
 *
 * @param u16_value Value to be written into GEN_CFG2_TW_TH. Valid values are:
 *      - 0: GEN_CFG2_TW_TH_CONST_0 (Temperature warning at 130\xa0degC).
 *      - 1: GEN_CFG2_TW_TH_CONST_1 (Temperature warning at 140\xa0degC).
 *      - 2: GEN_CFG2_TW_TH_CONST_2 (Temperature warning at 150\xa0degC
 * (Default)).
 *      - 3: GEN_CFG2_TW_TH_CONST_3 (Temperature warning at 160\xa0degC).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG2_TW_TH(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG2_TW_TH_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG2_TW_TH_POS) &
           (uint16)TLE9186_GEN_CFG2_TW_TH_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG2_TW_TH.
 *
 * This function returns the value of the bitfield Temperature warning threshold
 * selection within register GEN_CFG2.
 *
 * @return Value of the bitfield GEN_CFG2_TW_TH:
 *      - 0: GEN_CFG2_TW_TH_CONST_0 (Temperature warning at 130\xa0degC).
 *      - 1: GEN_CFG2_TW_TH_CONST_1 (Temperature warning at 140\xa0degC).
 *      - 2: GEN_CFG2_TW_TH_CONST_2 (Temperature warning at 150\xa0degC
 * (Default)).
 *      - 3: GEN_CFG2_TW_TH_CONST_3 (Temperature warning at 160\xa0degC).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG2_TW_TH(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GEN_CFG2.bit.TW_TH;
}

/**
 * @brief Set function for GEN_CFG2_TPFB.
 *
 * This function sets the bitfield PFB monitoring filter time configuration in
 * register GEN_CFG2.
 *
 * @param u16_value Value to be written into GEN_CFG2_TPFB. Valid values are:
 *      - 0: GEN_CFG2_TPFB_CONST_0 (Filter time configured as 2 x tfVDS
 * (Default)).
 *      - 1: GEN_CFG2_TPFB_CONST_1 (Filter time configured as 4 x tfVDS).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG2_TPFB(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG2_TPFB_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG2_TPFB_POS) &
           (uint16)TLE9186_GEN_CFG2_TPFB_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG2_TPFB.
 *
 * This function returns the value of the bitfield PFB monitoring filter time
 * configuration within register GEN_CFG2.
 *
 * @return Value of the bitfield GEN_CFG2_TPFB:
 *      - 0: GEN_CFG2_TPFB_CONST_0 (Filter time configured as 2 x tfVDS
 * (Default)).
 *      - 1: GEN_CFG2_TPFB_CONST_1 (Filter time configured as 4 x tfVDS).
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG2_TPFB(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GEN_CFG2.bit.TPFB;
}

/**
 * @brief get function for register GEN_CFG2.
 *
 * This function reads the register General configuration register 2.
 *
 */
void TLE9186_FuncLayer_get_GEN_CFG2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_GEN_CFG2();
}

/**
 * @brief Set function for register GEN_CFG3.
 *
 * This function sets the General configuration register 3.
 *
 * @param u16_value Value to be written into the register GEN_CFG3.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG3;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for GEN_CFG3_Spares.
 *
 * This function sets the bitfield Spares registered bits in register GEN_CFG3.
 *
 * @param u16_value Value to be written into GEN_CFG3_Spares. Valid values are:
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GEN_CFG3_Spares(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GEN_CFG3.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GEN_CFG3_Spares_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GEN_CFG3_Spares_POS) &
           (uint16)TLE9186_GEN_CFG3_Spares_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GEN_CFG3;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GEN_CFG3_Spares.
 *
 * This function returns the value of the bitfield Spares registered bits within
 * register GEN_CFG3.
 *
 * @return Value of the bitfield GEN_CFG3_Spares:
 */
uint16 TLE9186_FuncLayer_get_GEN_CFG3_Spares(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GEN_CFG3.bit.Spares;
}

/**
 * @brief get function for register GEN_CFG3.
 *
 * This function reads the register General configuration register 3.
 *
 */
void TLE9186_FuncLayer_get_GEN_CFG3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_GEN_CFG3();
}

/**
 * @brief Set function for register GDRV_CFG1.
 *
 * This function sets the Gate driver configuration register 1.
 *
 * @param u16_value Value to be written into the register GDRV_CFG1.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GDRV_CFG1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GDRV_CFG1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for GDRV_CFG1_TCCP_FW.
 *
 * This function sets the bitfield Cross-current protection time configuration
 * of the freewheeling MOSFET in register GDRV_CFG1.
 *
 * @param u16_value Value to be written into GDRV_CFG1_TCCP_FW. Valid values
 * are:
 *      - 0: GDRV_CFG1_TCCP_FW_CONST_0 (1 * 18/fclk if TCCP_CFG=0 , 1*9/fclk if
 * TCCP = 1).
 *      - 1: GDRV_CFG1_TCCP_FW_CONST_1 (2 * 18/fclk if TCCP_CFG=0 , 2*9/fclk if
 * TCCP = 1).
 *      - 2: GDRV_CFG1_TCCP_FW_CONST_2 (3 * 18/fclk if TCCP_CFG=0 , 3*9/fclk if
 * TCCP = 1).
 *      - 3: GDRV_CFG1_TCCP_FW_CONST_3 (4 * 18/fclk if TCCP_CFG=0 , 4*9/fclk if
 * TCCP = 1).
 *      - 4: GDRV_CFG1_TCCP_FW_CONST_4 (5 * 18/fclk if TCCP_CFG=0 , 5*9/fclk if
 * TCCP = 1).
 *      - 5: GDRV_CFG1_TCCP_FW_CONST_5 (6 * 18/fclk if TCCP_CFG=0 , 6*9/fclk if
 * TCCP = 1).
 *      - 6: GDRV_CFG1_TCCP_FW_CONST_6 (7 * 18/fclk if TCCP_CFG=0 , 7*9/fclk if
 * TCCP = 1).
 *      - 7: GDRV_CFG1_TCCP_FW_CONST_7 (8 * 18/fclk if TCCP_CFG=0 , 8*9/fclk if
 * TCCP = 1).
 *      - 8: GDRV_CFG1_TCCP_FW_CONST_8 (9 * 18/fclk if TCCP_CFG=0 , 9*9/fclk if
 * TCCP = 1 (Default)).
 *      - 9: GDRV_CFG1_TCCP_FW_CONST_9 (10 * 18/fclk if TCCP_CFG=0 , 10*9/fclk
 * if TCCP = 1).
 *      - 10: GDRV_CFG1_TCCP_FW_CONST_10 (11 * 18/fclk if TCCP_CFG=0 , 11*9/fclk
 * if TCCP = 1).
 *      - 11: GDRV_CFG1_TCCP_FW_CONST_11 (12 * 18/fclk if TCCP_CFG=0 , 12*9/fclk
 * if TCCP = 1).
 *      - 12: GDRV_CFG1_TCCP_FW_CONST_12 (13 * 18/fclk if TCCP_CFG=0 , 13*9/fclk
 * if TCCP = 1).
 *      - 13: GDRV_CFG1_TCCP_FW_CONST_13 (14 * 18/fclk if TCCP_CFG=0 , 14*9/fclk
 * if TCCP = 1).
 *      - 14: GDRV_CFG1_TCCP_FW_CONST_14 (15 * 18/fclk if TCCP_CFG=0 , 15*9/fclk
 * if TCCP = 1).
 *      - 15: GDRV_CFG1_TCCP_FW_CONST_15 (16 * 18/fclk if TCCP_CFG=0 , 16*9/fclk
 * if TCCP = 1).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GDRV_CFG1_TCCP_FW(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GDRV_CFG1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GDRV_CFG1_TCCP_FW_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GDRV_CFG1_TCCP_FW_POS) &
           (uint16)TLE9186_GDRV_CFG1_TCCP_FW_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GDRV_CFG1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GDRV_CFG1_TCCP_FW.
 *
 * This function returns the value of the bitfield Cross-current protection time
 * configuration of the freewheeling MOSFET within register GDRV_CFG1.
 *
 * @return Value of the bitfield GDRV_CFG1_TCCP_FW:
 *      - 0: GDRV_CFG1_TCCP_FW_CONST_0 (1 * 18/fclk if TCCP_CFG=0 , 1*9/fclk if
 * TCCP = 1).
 *      - 1: GDRV_CFG1_TCCP_FW_CONST_1 (2 * 18/fclk if TCCP_CFG=0 , 2*9/fclk if
 * TCCP = 1).
 *      - 2: GDRV_CFG1_TCCP_FW_CONST_2 (3 * 18/fclk if TCCP_CFG=0 , 3*9/fclk if
 * TCCP = 1).
 *      - 3: GDRV_CFG1_TCCP_FW_CONST_3 (4 * 18/fclk if TCCP_CFG=0 , 4*9/fclk if
 * TCCP = 1).
 *      - 4: GDRV_CFG1_TCCP_FW_CONST_4 (5 * 18/fclk if TCCP_CFG=0 , 5*9/fclk if
 * TCCP = 1).
 *      - 5: GDRV_CFG1_TCCP_FW_CONST_5 (6 * 18/fclk if TCCP_CFG=0 , 6*9/fclk if
 * TCCP = 1).
 *      - 6: GDRV_CFG1_TCCP_FW_CONST_6 (7 * 18/fclk if TCCP_CFG=0 , 7*9/fclk if
 * TCCP = 1).
 *      - 7: GDRV_CFG1_TCCP_FW_CONST_7 (8 * 18/fclk if TCCP_CFG=0 , 8*9/fclk if
 * TCCP = 1).
 *      - 8: GDRV_CFG1_TCCP_FW_CONST_8 (9 * 18/fclk if TCCP_CFG=0 , 9*9/fclk if
 * TCCP = 1 (Default)).
 *      - 9: GDRV_CFG1_TCCP_FW_CONST_9 (10 * 18/fclk if TCCP_CFG=0 , 10*9/fclk
 * if TCCP = 1).
 *      - 10: GDRV_CFG1_TCCP_FW_CONST_10 (11 * 18/fclk if TCCP_CFG=0 , 11*9/fclk
 * if TCCP = 1).
 *      - 11: GDRV_CFG1_TCCP_FW_CONST_11 (12 * 18/fclk if TCCP_CFG=0 , 12*9/fclk
 * if TCCP = 1).
 *      - 12: GDRV_CFG1_TCCP_FW_CONST_12 (13 * 18/fclk if TCCP_CFG=0 , 13*9/fclk
 * if TCCP = 1).
 *      - 13: GDRV_CFG1_TCCP_FW_CONST_13 (14 * 18/fclk if TCCP_CFG=0 , 14*9/fclk
 * if TCCP = 1).
 *      - 14: GDRV_CFG1_TCCP_FW_CONST_14 (15 * 18/fclk if TCCP_CFG=0 , 15*9/fclk
 * if TCCP = 1).
 *      - 15: GDRV_CFG1_TCCP_FW_CONST_15 (16 * 18/fclk if TCCP_CFG=0 , 16*9/fclk
 * if TCCP = 1).
 */
uint16 TLE9186_FuncLayer_get_GDRV_CFG1_TCCP_FW(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GDRV_CFG1.bit.TCCP_FW;
}

/**
 * @brief Set function for GDRV_CFG1_TCCP.
 *
 * This function sets the bitfield Cross-current protection time configuration
 * of the active MOSFET in register GDRV_CFG1.
 *
 * @param u16_value Value to be written into GDRV_CFG1_TCCP. Valid values are:
 *      - 0: GDRV_CFG1_TCCP_CONST_0 (1 * 18/fclk if TCCP_CFG=0 , 1*9/fclk if
 * TCCP = 1).
 *      - 1: GDRV_CFG1_TCCP_CONST_1 (2 * 18/fclk if TCCP_CFG=0 , 2*9/fclk if
 * TCCP = 1).
 *      - 2: GDRV_CFG1_TCCP_CONST_2 (3 * 18/fclk if TCCP_CFG=0 , 3*9/fclk if
 * TCCP = 1).
 *      - 3: GDRV_CFG1_TCCP_CONST_3 (4 * 18/fclk if TCCP_CFG=0 , 4*9/fclk if
 * TCCP = 1).
 *      - 4: GDRV_CFG1_TCCP_CONST_4 (5 * 18/fclk if TCCP_CFG=0 , 5*9/fclk if
 * TCCP = 1).
 *      - 5: GDRV_CFG1_TCCP_CONST_5 (6 * 18/fclk if TCCP_CFG=0 , 6*9/fclk if
 * TCCP = 1).
 *      - 6: GDRV_CFG1_TCCP_CONST_6 (7 * 18/fclk if TCCP_CFG=0 , 7*9/fclk if
 * TCCP = 1).
 *      - 7: GDRV_CFG1_TCCP_CONST_7 (8 * 18/fclk if TCCP_CFG=0 , 8*9/fclk if
 * TCCP = 1).
 *      - 8: GDRV_CFG1_TCCP_CONST_8 (9 * 18/fclk if TCCP_CFG=0 , 9*9/fclk if
 * TCCP = 1 (Default)).
 *      - 9: GDRV_CFG1_TCCP_CONST_9 (10 * 18/fclk if TCCP_CFG=0 , 10*9/fclk if
 * TCCP = 1).
 *      - 10: GDRV_CFG1_TCCP_CONST_10 (11 * 18/fclk if TCCP_CFG=0 , 11*9/fclk if
 * TCCP = 1).
 *      - 11: GDRV_CFG1_TCCP_CONST_11 (12 * 18/fclk if TCCP_CFG=0 , 12*9/fclk if
 * TCCP = 1).
 *      - 12: GDRV_CFG1_TCCP_CONST_12 (13 * 18/fclk if TCCP_CFG=0 , 13*9/fclk if
 * TCCP = 1).
 *      - 13: GDRV_CFG1_TCCP_CONST_13 (14 * 18/fclk if TCCP_CFG=0 , 14*9/fclk if
 * TCCP = 1).
 *      - 14: GDRV_CFG1_TCCP_CONST_14 (15 * 18/fclk if TCCP_CFG=0 , 15*9/fclk if
 * TCCP = 1).
 *      - 15: GDRV_CFG1_TCCP_CONST_15 (16 * 18/fclk if TCCP_CFG=0 , 16*9/fclk if
 * TCCP = 1).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GDRV_CFG1_TCCP(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GDRV_CFG1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GDRV_CFG1_TCCP_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GDRV_CFG1_TCCP_POS) &
           (uint16)TLE9186_GDRV_CFG1_TCCP_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GDRV_CFG1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GDRV_CFG1_TCCP.
 *
 * This function returns the value of the bitfield Cross-current protection time
 * configuration of the active MOSFET within register GDRV_CFG1.
 *
 * @return Value of the bitfield GDRV_CFG1_TCCP:
 *      - 0: GDRV_CFG1_TCCP_CONST_0 (1 * 18/fclk if TCCP_CFG=0 , 1*9/fclk if
 * TCCP = 1).
 *      - 1: GDRV_CFG1_TCCP_CONST_1 (2 * 18/fclk if TCCP_CFG=0 , 2*9/fclk if
 * TCCP = 1).
 *      - 2: GDRV_CFG1_TCCP_CONST_2 (3 * 18/fclk if TCCP_CFG=0 , 3*9/fclk if
 * TCCP = 1).
 *      - 3: GDRV_CFG1_TCCP_CONST_3 (4 * 18/fclk if TCCP_CFG=0 , 4*9/fclk if
 * TCCP = 1).
 *      - 4: GDRV_CFG1_TCCP_CONST_4 (5 * 18/fclk if TCCP_CFG=0 , 5*9/fclk if
 * TCCP = 1).
 *      - 5: GDRV_CFG1_TCCP_CONST_5 (6 * 18/fclk if TCCP_CFG=0 , 6*9/fclk if
 * TCCP = 1).
 *      - 6: GDRV_CFG1_TCCP_CONST_6 (7 * 18/fclk if TCCP_CFG=0 , 7*9/fclk if
 * TCCP = 1).
 *      - 7: GDRV_CFG1_TCCP_CONST_7 (8 * 18/fclk if TCCP_CFG=0 , 8*9/fclk if
 * TCCP = 1).
 *      - 8: GDRV_CFG1_TCCP_CONST_8 (9 * 18/fclk if TCCP_CFG=0 , 9*9/fclk if
 * TCCP = 1 (Default)).
 *      - 9: GDRV_CFG1_TCCP_CONST_9 (10 * 18/fclk if TCCP_CFG=0 , 10*9/fclk if
 * TCCP = 1).
 *      - 10: GDRV_CFG1_TCCP_CONST_10 (11 * 18/fclk if TCCP_CFG=0 , 11*9/fclk if
 * TCCP = 1).
 *      - 11: GDRV_CFG1_TCCP_CONST_11 (12 * 18/fclk if TCCP_CFG=0 , 12*9/fclk if
 * TCCP = 1).
 *      - 12: GDRV_CFG1_TCCP_CONST_12 (13 * 18/fclk if TCCP_CFG=0 , 13*9/fclk if
 * TCCP = 1).
 *      - 13: GDRV_CFG1_TCCP_CONST_13 (14 * 18/fclk if TCCP_CFG=0 , 14*9/fclk if
 * TCCP = 1).
 *      - 14: GDRV_CFG1_TCCP_CONST_14 (15 * 18/fclk if TCCP_CFG=0 , 15*9/fclk if
 * TCCP = 1).
 *      - 15: GDRV_CFG1_TCCP_CONST_15 (16 * 18/fclk if TCCP_CFG=0 , 16*9/fclk if
 * TCCP = 1).
 */
uint16 TLE9186_FuncLayer_get_GDRV_CFG1_TCCP(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GDRV_CFG1.bit.TCCP;
}

/**
 * @brief Set function for GDRV_CFG1_TVDSBLK_FW.
 *
 * This function sets the bitfield Blanking time configuration of the
 * freewheeling MOSFET in register GDRV_CFG1.
 *
 * @param u16_value Value to be written into GDRV_CFG1_TVDSBLK_FW. Valid values
 * are:
 *      - 0: GDRV_CFG1_TVDSBLK_FW_CONST_0 (1 * 18/fclk).
 *      - 1: GDRV_CFG1_TVDSBLK_FW_CONST_1 (2 * 18/fclk).
 *      - 2: GDRV_CFG1_TVDSBLK_FW_CONST_2 (3 * 18/fclk).
 *      - 3: GDRV_CFG1_TVDSBLK_FW_CONST_3 (4 * 18/fclk).
 *      - 4: GDRV_CFG1_TVDSBLK_FW_CONST_4 (5 * 18/fclk).
 *      - 5: GDRV_CFG1_TVDSBLK_FW_CONST_5 (6 * 18/fclk).
 *      - 6: GDRV_CFG1_TVDSBLK_FW_CONST_6 (7 * 18/fclk).
 *      - 7: GDRV_CFG1_TVDSBLK_FW_CONST_7 (8 * 18/fclk).
 *      - 8: GDRV_CFG1_TVDSBLK_FW_CONST_8 (9 * 18/fclk (Default)).
 *      - 9: GDRV_CFG1_TVDSBLK_FW_CONST_9 (10 * 18/fclk).
 *      - 10: GDRV_CFG1_TVDSBLK_FW_CONST_10 (11 * 18/fclk).
 *      - 11: GDRV_CFG1_TVDSBLK_FW_CONST_11 (12 * 18/fclk).
 *      - 12: GDRV_CFG1_TVDSBLK_FW_CONST_12 (13 * 18/fclk).
 *      - 13: GDRV_CFG1_TVDSBLK_FW_CONST_13 (14 * 18/fclk).
 *      - 14: GDRV_CFG1_TVDSBLK_FW_CONST_14 (15 * 18/fclk).
 *      - 15: GDRV_CFG1_TVDSBLK_FW_CONST_15 (16 * 18/fclk).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GDRV_CFG1_TVDSBLK_FW(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GDRV_CFG1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GDRV_CFG1_TVDSBLK_FW_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GDRV_CFG1_TVDSBLK_FW_POS) &
           (uint16)TLE9186_GDRV_CFG1_TVDSBLK_FW_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GDRV_CFG1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GDRV_CFG1_TVDSBLK_FW.
 *
 * This function returns the value of the bitfield Blanking time configuration
 * of the freewheeling MOSFET within register GDRV_CFG1.
 *
 * @return Value of the bitfield GDRV_CFG1_TVDSBLK_FW:
 *      - 0: GDRV_CFG1_TVDSBLK_FW_CONST_0 (1 * 18/fclk).
 *      - 1: GDRV_CFG1_TVDSBLK_FW_CONST_1 (2 * 18/fclk).
 *      - 2: GDRV_CFG1_TVDSBLK_FW_CONST_2 (3 * 18/fclk).
 *      - 3: GDRV_CFG1_TVDSBLK_FW_CONST_3 (4 * 18/fclk).
 *      - 4: GDRV_CFG1_TVDSBLK_FW_CONST_4 (5 * 18/fclk).
 *      - 5: GDRV_CFG1_TVDSBLK_FW_CONST_5 (6 * 18/fclk).
 *      - 6: GDRV_CFG1_TVDSBLK_FW_CONST_6 (7 * 18/fclk).
 *      - 7: GDRV_CFG1_TVDSBLK_FW_CONST_7 (8 * 18/fclk).
 *      - 8: GDRV_CFG1_TVDSBLK_FW_CONST_8 (9 * 18/fclk (Default)).
 *      - 9: GDRV_CFG1_TVDSBLK_FW_CONST_9 (10 * 18/fclk).
 *      - 10: GDRV_CFG1_TVDSBLK_FW_CONST_10 (11 * 18/fclk).
 *      - 11: GDRV_CFG1_TVDSBLK_FW_CONST_11 (12 * 18/fclk).
 *      - 12: GDRV_CFG1_TVDSBLK_FW_CONST_12 (13 * 18/fclk).
 *      - 13: GDRV_CFG1_TVDSBLK_FW_CONST_13 (14 * 18/fclk).
 *      - 14: GDRV_CFG1_TVDSBLK_FW_CONST_14 (15 * 18/fclk).
 *      - 15: GDRV_CFG1_TVDSBLK_FW_CONST_15 (16 * 18/fclk).
 */
uint16 TLE9186_FuncLayer_get_GDRV_CFG1_TVDSBLK_FW(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->GDRV_CFG1.bit.TVDSBLK_FW;
}

/**
 * @brief Set function for GDRV_CFG1_TVDSBLK.
 *
 * This function sets the bitfield Blanking time configuration of the active
 * MOSFET in register GDRV_CFG1.
 *
 * @param u16_value Value to be written into GDRV_CFG1_TVDSBLK. Valid values
 * are:
 *      - 0: GDRV_CFG1_TVDSBLK_CONST_0 (1 * 18/fclk).
 *      - 1: GDRV_CFG1_TVDSBLK_CONST_1 (2 * 18/fclk).
 *      - 2: GDRV_CFG1_TVDSBLK_CONST_2 (3 * 18/fclk).
 *      - 3: GDRV_CFG1_TVDSBLK_CONST_3 (4 * 18/fclk).
 *      - 4: GDRV_CFG1_TVDSBLK_CONST_4 (5 * 18/fclk).
 *      - 5: GDRV_CFG1_TVDSBLK_CONST_5 (6 * 18/fclk).
 *      - 6: GDRV_CFG1_TVDSBLK_CONST_6 (7 * 18/fclk).
 *      - 7: GDRV_CFG1_TVDSBLK_CONST_7 (8 * 18/fclk).
 *      - 8: GDRV_CFG1_TVDSBLK_CONST_8 (9 * 18/fclk (Default)).
 *      - 9: GDRV_CFG1_TVDSBLK_CONST_9 (10 * 18/fclk).
 *      - 10: GDRV_CFG1_TVDSBLK_CONST_10 (11 * 18/fclk).
 *      - 11: GDRV_CFG1_TVDSBLK_CONST_11 (12 * 18/fclk).
 *      - 12: GDRV_CFG1_TVDSBLK_CONST_12 (13 * 18/fclk).
 *      - 13: GDRV_CFG1_TVDSBLK_CONST_13 (14 * 18/fclk).
 *      - 14: GDRV_CFG1_TVDSBLK_CONST_14 (15 * 18/fclk).
 *      - 15: GDRV_CFG1_TVDSBLK_CONST_15 (16 * 18/fclk).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GDRV_CFG1_TVDSBLK(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GDRV_CFG1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GDRV_CFG1_TVDSBLK_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GDRV_CFG1_TVDSBLK_POS) &
           (uint16)TLE9186_GDRV_CFG1_TVDSBLK_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GDRV_CFG1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GDRV_CFG1_TVDSBLK.
 *
 * This function returns the value of the bitfield Blanking time configuration
 * of the active MOSFET within register GDRV_CFG1.
 *
 * @return Value of the bitfield GDRV_CFG1_TVDSBLK:
 *      - 0: GDRV_CFG1_TVDSBLK_CONST_0 (1 * 18/fclk).
 *      - 1: GDRV_CFG1_TVDSBLK_CONST_1 (2 * 18/fclk).
 *      - 2: GDRV_CFG1_TVDSBLK_CONST_2 (3 * 18/fclk).
 *      - 3: GDRV_CFG1_TVDSBLK_CONST_3 (4 * 18/fclk).
 *      - 4: GDRV_CFG1_TVDSBLK_CONST_4 (5 * 18/fclk).
 *      - 5: GDRV_CFG1_TVDSBLK_CONST_5 (6 * 18/fclk).
 *      - 6: GDRV_CFG1_TVDSBLK_CONST_6 (7 * 18/fclk).
 *      - 7: GDRV_CFG1_TVDSBLK_CONST_7 (8 * 18/fclk).
 *      - 8: GDRV_CFG1_TVDSBLK_CONST_8 (9 * 18/fclk (Default)).
 *      - 9: GDRV_CFG1_TVDSBLK_CONST_9 (10 * 18/fclk).
 *      - 10: GDRV_CFG1_TVDSBLK_CONST_10 (11 * 18/fclk).
 *      - 11: GDRV_CFG1_TVDSBLK_CONST_11 (12 * 18/fclk).
 *      - 12: GDRV_CFG1_TVDSBLK_CONST_12 (13 * 18/fclk).
 *      - 13: GDRV_CFG1_TVDSBLK_CONST_13 (14 * 18/fclk).
 *      - 14: GDRV_CFG1_TVDSBLK_CONST_14 (15 * 18/fclk).
 *      - 15: GDRV_CFG1_TVDSBLK_CONST_15 (16 * 18/fclk).
 */
uint16 TLE9186_FuncLayer_get_GDRV_CFG1_TVDSBLK(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GDRV_CFG1.bit.TVDSBLK;
}

/**
 * @brief get function for register GDRV_CFG1.
 *
 * This function reads the register Gate driver configuration register 1.
 *
 */
void TLE9186_FuncLayer_get_GDRV_CFG1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_GDRV_CFG1();
}

/**
 * @brief Set function for register GDRV_CFG2.
 *
 * This function sets the Gate driver configuration register 2.
 *
 * @param u16_value Value to be written into the register GDRV_CFG2.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GDRV_CFG2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GDRV_CFG2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for GDRV_CFG2_LS_DSOVTH.
 *
 * This function sets the bitfield LS MOSFETs drain-source threshold
 * configuration in register GDRV_CFG2.
 *
 * @param u16_value Value to be written into GDRV_CFG2_LS_DSOVTH. Valid values
 * are:
 *      - 0: GDRV_CFG2_LS_DSOVTH_CONST_0 (150mV).
 *      - 1: GDRV_CFG2_LS_DSOVTH_CONST_1 (200mV (Default)).
 *      - 2: GDRV_CFG2_LS_DSOVTH_CONST_2 (250mV).
 *      - 3: GDRV_CFG2_LS_DSOVTH_CONST_3 (300mV).
 *      - 4: GDRV_CFG2_LS_DSOVTH_CONST_4 (350mV).
 *      - 5: GDRV_CFG2_LS_DSOVTH_CONST_5 (400mV).
 *      - 6: GDRV_CFG2_LS_DSOVTH_CONST_6 (500mV).
 *      - 7: GDRV_CFG2_LS_DSOVTH_CONST_7 (600mV).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GDRV_CFG2_LS_DSOVTH(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GDRV_CFG2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GDRV_CFG2_LS_DSOVTH_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GDRV_CFG2_LS_DSOVTH_POS) &
           (uint16)TLE9186_GDRV_CFG2_LS_DSOVTH_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GDRV_CFG2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GDRV_CFG2_LS_DSOVTH.
 *
 * This function returns the value of the bitfield LS MOSFETs drain-source
 * threshold configuration within register GDRV_CFG2.
 *
 * @return Value of the bitfield GDRV_CFG2_LS_DSOVTH:
 *      - 0: GDRV_CFG2_LS_DSOVTH_CONST_0 (150mV).
 *      - 1: GDRV_CFG2_LS_DSOVTH_CONST_1 (200mV (Default)).
 *      - 2: GDRV_CFG2_LS_DSOVTH_CONST_2 (250mV).
 *      - 3: GDRV_CFG2_LS_DSOVTH_CONST_3 (300mV).
 *      - 4: GDRV_CFG2_LS_DSOVTH_CONST_4 (350mV).
 *      - 5: GDRV_CFG2_LS_DSOVTH_CONST_5 (400mV).
 *      - 6: GDRV_CFG2_LS_DSOVTH_CONST_6 (500mV).
 *      - 7: GDRV_CFG2_LS_DSOVTH_CONST_7 (600mV).
 */
uint16 TLE9186_FuncLayer_get_GDRV_CFG2_LS_DSOVTH(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->GDRV_CFG2.bit.LS_DSOVTH;
}

/**
 * @brief Set function for GDRV_CFG2_HS_DSOVTH.
 *
 * This function sets the bitfield HS MOSFETs drain-source threshold
 * configuration in register GDRV_CFG2.
 *
 * @param u16_value Value to be written into GDRV_CFG2_HS_DSOVTH. Valid values
 * are:
 *      - 0: GDRV_CFG2_HS_DSOVTH_CONST_0 (150mV).
 *      - 1: GDRV_CFG2_HS_DSOVTH_CONST_1 (200mV (Default)).
 *      - 2: GDRV_CFG2_HS_DSOVTH_CONST_2 (250mV).
 *      - 3: GDRV_CFG2_HS_DSOVTH_CONST_3 (300mV).
 *      - 4: GDRV_CFG2_HS_DSOVTH_CONST_4 (350mV).
 *      - 5: GDRV_CFG2_HS_DSOVTH_CONST_5 (400mV).
 *      - 6: GDRV_CFG2_HS_DSOVTH_CONST_6 (500mV).
 *      - 7: GDRV_CFG2_HS_DSOVTH_CONST_7 (600mV).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GDRV_CFG2_HS_DSOVTH(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GDRV_CFG2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GDRV_CFG2_HS_DSOVTH_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GDRV_CFG2_HS_DSOVTH_POS) &
           (uint16)TLE9186_GDRV_CFG2_HS_DSOVTH_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GDRV_CFG2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GDRV_CFG2_HS_DSOVTH.
 *
 * This function returns the value of the bitfield HS MOSFETs drain-source
 * threshold configuration within register GDRV_CFG2.
 *
 * @return Value of the bitfield GDRV_CFG2_HS_DSOVTH:
 *      - 0: GDRV_CFG2_HS_DSOVTH_CONST_0 (150mV).
 *      - 1: GDRV_CFG2_HS_DSOVTH_CONST_1 (200mV (Default)).
 *      - 2: GDRV_CFG2_HS_DSOVTH_CONST_2 (250mV).
 *      - 3: GDRV_CFG2_HS_DSOVTH_CONST_3 (300mV).
 *      - 4: GDRV_CFG2_HS_DSOVTH_CONST_4 (350mV).
 *      - 5: GDRV_CFG2_HS_DSOVTH_CONST_5 (400mV).
 *      - 6: GDRV_CFG2_HS_DSOVTH_CONST_6 (500mV).
 *      - 7: GDRV_CFG2_HS_DSOVTH_CONST_7 (600mV).
 */
uint16 TLE9186_FuncLayer_get_GDRV_CFG2_HS_DSOVTH(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->GDRV_CFG2.bit.HS_DSOVTH;
}

/**
 * @brief Set function for GDRV_CFG2_TVDSFILT.
 *
 * This function sets the bitfield Drain-source monitoring comparators filter
 * time in register GDRV_CFG2.
 *
 * @param u16_value Value to be written into GDRV_CFG2_TVDSFILT. Valid values
 * are:
 *      - 0: GDRV_CFG2_TVDSFILT_CONST_0 (2 * 18/fclk).
 *      - 1: GDRV_CFG2_TVDSFILT_CONST_1 (4 * 18/fclk).
 *      - 2: GDRV_CFG2_TVDSFILT_CONST_2 (8 * 18/fclk (Default)).
 *      - 3: GDRV_CFG2_TVDSFILT_CONST_3 (12 * 18/fclk).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GDRV_CFG2_TVDSFILT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GDRV_CFG2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GDRV_CFG2_TVDSFILT_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GDRV_CFG2_TVDSFILT_POS) &
           (uint16)TLE9186_GDRV_CFG2_TVDSFILT_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GDRV_CFG2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GDRV_CFG2_TVDSFILT.
 *
 * This function returns the value of the bitfield Drain-source monitoring
 * comparators filter time within register GDRV_CFG2.
 *
 * @return Value of the bitfield GDRV_CFG2_TVDSFILT:
 *      - 0: GDRV_CFG2_TVDSFILT_CONST_0 (2 * 18/fclk).
 *      - 1: GDRV_CFG2_TVDSFILT_CONST_1 (4 * 18/fclk).
 *      - 2: GDRV_CFG2_TVDSFILT_CONST_2 (8 * 18/fclk (Default)).
 *      - 3: GDRV_CFG2_TVDSFILT_CONST_3 (12 * 18/fclk).
 */
uint16 TLE9186_FuncLayer_get_GDRV_CFG2_TVDSFILT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GDRV_CFG2.bit.TVDSFILT;
}

/**
 * @brief Set function for GDRV_CFG2_TFW.
 *
 * This function sets the bitfield Freewheeling device charge/discharge time  in
 * register GDRV_CFG2.
 *
 * @param u16_value Value to be written into GDRV_CFG2_TFW. Valid values are:
 *      - 0: GDRV_CFG2_TFW_CONST_0 (1 * 2/fclk).
 *      - 1: GDRV_CFG2_TFW_CONST_1 (2 * 2/fclk).
 *      - 2: GDRV_CFG2_TFW_CONST_2 (3 * 2/fclk).
 *      - 3: GDRV_CFG2_TFW_CONST_3 (4 * 2/fclk).
 *      - 4: GDRV_CFG2_TFW_CONST_4 (5 * 2/fclk).
 *      - 5: GDRV_CFG2_TFW_CONST_5 (6 * 2/fclk).
 *      - 6: GDRV_CFG2_TFW_CONST_6 (7 * 2/fclk).
 *      - 7: GDRV_CFG2_TFW_CONST_7 (8 * 2/fclk).
 *      - 8: GDRV_CFG2_TFW_CONST_8 (9 * 2/fclk).
 *      - 9: GDRV_CFG2_TFW_CONST_9 (10 * 2/fclk).
 *      - 10: GDRV_CFG2_TFW_CONST_10 (11 * 2/fclk).
 *      - 11: GDRV_CFG2_TFW_CONST_11 (12 * 2/fclk).
 *      - 12: GDRV_CFG2_TFW_CONST_12 (13 * 2/fclk).
 *      - 13: GDRV_CFG2_TFW_CONST_13 (14 * 2/fclk).
 *      - 14: GDRV_CFG2_TFW_CONST_14 (15 * 2/fclk).
 *      - 15: GDRV_CFG2_TFW_CONST_15 (16 * 2/fclk).
 *      - 16: GDRV_CFG2_TFW_CONST_16 (17 * 2/fclk).
 *      - 17: GDRV_CFG2_TFW_CONST_17 (18 * 2/fclk).
 *      - 18: GDRV_CFG2_TFW_CONST_18 (19 * 2/fclk).
 *      - 19: GDRV_CFG2_TFW_CONST_19 (20 * 2/fclk).
 *      - 20: GDRV_CFG2_TFW_CONST_20 (21 * 2/fclk).
 *      - 21: GDRV_CFG2_TFW_CONST_21 (22 * 2/fclk).
 *      - 22: GDRV_CFG2_TFW_CONST_22 (23 * 2/fclk).
 *      - 23: GDRV_CFG2_TFW_CONST_23 (24 * 2/fclk).
 *      - 24: GDRV_CFG2_TFW_CONST_24 (25 * 2/fclk).
 *      - 25: GDRV_CFG2_TFW_CONST_25 (26 * 2/fclk (Default)).
 *      - 26: GDRV_CFG2_TFW_CONST_26 (27 * 2/fclk).
 *      - 27: GDRV_CFG2_TFW_CONST_27 (28 * 2/fclk).
 *      - 28: GDRV_CFG2_TFW_CONST_28 (29 * 2/fclk).
 *      - 29: GDRV_CFG2_TFW_CONST_29 (30 * 2/fclk).
 *      - 30: GDRV_CFG2_TFW_CONST_30 (31 * 2/fclk).
 *      - 31: GDRV_CFG2_TFW_CONST_31 (32 * 2/fclk).
 *      - 32: GDRV_CFG2_TFW_CONST_32 (33 * 2/fclk).
 *      - 33: GDRV_CFG2_TFW_CONST_33 (34 * 2/fclk).
 *      - 34: GDRV_CFG2_TFW_CONST_34 (35 * 2/fclk).
 *      - 35: GDRV_CFG2_TFW_CONST_35 (36 * 2/fclk).
 *      - 36: GDRV_CFG2_TFW_CONST_36 (37 * 2/fclk).
 *      - 37: GDRV_CFG2_TFW_CONST_37 (38 * 2/fclk).
 *      - 38: GDRV_CFG2_TFW_CONST_38 (39 * 2/fclk).
 *      - 39: GDRV_CFG2_TFW_CONST_39 (40 * 2/fclk).
 *      - 40: GDRV_CFG2_TFW_CONST_40 (41 * 2/fclk).
 *      - 41: GDRV_CFG2_TFW_CONST_41 (42 * 2/fclk).
 *      - 42: GDRV_CFG2_TFW_CONST_42 (43 * 2/fclk).
 *      - 43: GDRV_CFG2_TFW_CONST_43 (44 * 2/fclk).
 *      - 44: GDRV_CFG2_TFW_CONST_44 (45 * 2/fclk).
 *      - 45: GDRV_CFG2_TFW_CONST_45 (46 * 2/fclk).
 *      - 46: GDRV_CFG2_TFW_CONST_46 (47 * 2/fclk).
 *      - 47: GDRV_CFG2_TFW_CONST_47 (48 * 2/fclk).
 *      - 48: GDRV_CFG2_TFW_CONST_48 (49 * 2/fclk).
 *      - 49: GDRV_CFG2_TFW_CONST_49 (50 * 2/fclk).
 *      - 50: GDRV_CFG2_TFW_CONST_50 (51 * 2/fclk).
 *      - 51: GDRV_CFG2_TFW_CONST_51 (52 * 2/fclk).
 *      - 52: GDRV_CFG2_TFW_CONST_52 (53 * 2/fclk).
 *      - 53: GDRV_CFG2_TFW_CONST_53 (54 * 2/fclk).
 *      - 54: GDRV_CFG2_TFW_CONST_54 (55 * 2/fclk).
 *      - 55: GDRV_CFG2_TFW_CONST_55 (56 * 2/fclk).
 *      - 56: GDRV_CFG2_TFW_CONST_56 (57 * 2/fclk).
 *      - 57: GDRV_CFG2_TFW_CONST_57 (58 * 2/fclk).
 *      - 58: GDRV_CFG2_TFW_CONST_58 (59 * 2/fclk).
 *      - 59: GDRV_CFG2_TFW_CONST_59 (60 * 2/fclk).
 *      - 60: GDRV_CFG2_TFW_CONST_60 (61 * 2/fclk).
 *      - 61: GDRV_CFG2_TFW_CONST_61 (62 * 2/fclk).
 *      - 62: GDRV_CFG2_TFW_CONST_62 (63 * 2/fclk).
 *      - 63: GDRV_CFG2_TFW_CONST_63 (64 * 2/fclk).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GDRV_CFG2_TFW(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GDRV_CFG2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GDRV_CFG2_TFW_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GDRV_CFG2_TFW_POS) &
           (uint16)TLE9186_GDRV_CFG2_TFW_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GDRV_CFG2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GDRV_CFG2_TFW.
 *
 * This function returns the value of the bitfield Freewheeling device
 * charge/discharge time  within register GDRV_CFG2.
 *
 * @return Value of the bitfield GDRV_CFG2_TFW:
 *      - 0: GDRV_CFG2_TFW_CONST_0 (1 * 2/fclk).
 *      - 1: GDRV_CFG2_TFW_CONST_1 (2 * 2/fclk).
 *      - 2: GDRV_CFG2_TFW_CONST_2 (3 * 2/fclk).
 *      - 3: GDRV_CFG2_TFW_CONST_3 (4 * 2/fclk).
 *      - 4: GDRV_CFG2_TFW_CONST_4 (5 * 2/fclk).
 *      - 5: GDRV_CFG2_TFW_CONST_5 (6 * 2/fclk).
 *      - 6: GDRV_CFG2_TFW_CONST_6 (7 * 2/fclk).
 *      - 7: GDRV_CFG2_TFW_CONST_7 (8 * 2/fclk).
 *      - 8: GDRV_CFG2_TFW_CONST_8 (9 * 2/fclk).
 *      - 9: GDRV_CFG2_TFW_CONST_9 (10 * 2/fclk).
 *      - 10: GDRV_CFG2_TFW_CONST_10 (11 * 2/fclk).
 *      - 11: GDRV_CFG2_TFW_CONST_11 (12 * 2/fclk).
 *      - 12: GDRV_CFG2_TFW_CONST_12 (13 * 2/fclk).
 *      - 13: GDRV_CFG2_TFW_CONST_13 (14 * 2/fclk).
 *      - 14: GDRV_CFG2_TFW_CONST_14 (15 * 2/fclk).
 *      - 15: GDRV_CFG2_TFW_CONST_15 (16 * 2/fclk).
 *      - 16: GDRV_CFG2_TFW_CONST_16 (17 * 2/fclk).
 *      - 17: GDRV_CFG2_TFW_CONST_17 (18 * 2/fclk).
 *      - 18: GDRV_CFG2_TFW_CONST_18 (19 * 2/fclk).
 *      - 19: GDRV_CFG2_TFW_CONST_19 (20 * 2/fclk).
 *      - 20: GDRV_CFG2_TFW_CONST_20 (21 * 2/fclk).
 *      - 21: GDRV_CFG2_TFW_CONST_21 (22 * 2/fclk).
 *      - 22: GDRV_CFG2_TFW_CONST_22 (23 * 2/fclk).
 *      - 23: GDRV_CFG2_TFW_CONST_23 (24 * 2/fclk).
 *      - 24: GDRV_CFG2_TFW_CONST_24 (25 * 2/fclk).
 *      - 25: GDRV_CFG2_TFW_CONST_25 (26 * 2/fclk (Default)).
 *      - 26: GDRV_CFG2_TFW_CONST_26 (27 * 2/fclk).
 *      - 27: GDRV_CFG2_TFW_CONST_27 (28 * 2/fclk).
 *      - 28: GDRV_CFG2_TFW_CONST_28 (29 * 2/fclk).
 *      - 29: GDRV_CFG2_TFW_CONST_29 (30 * 2/fclk).
 *      - 30: GDRV_CFG2_TFW_CONST_30 (31 * 2/fclk).
 *      - 31: GDRV_CFG2_TFW_CONST_31 (32 * 2/fclk).
 *      - 32: GDRV_CFG2_TFW_CONST_32 (33 * 2/fclk).
 *      - 33: GDRV_CFG2_TFW_CONST_33 (34 * 2/fclk).
 *      - 34: GDRV_CFG2_TFW_CONST_34 (35 * 2/fclk).
 *      - 35: GDRV_CFG2_TFW_CONST_35 (36 * 2/fclk).
 *      - 36: GDRV_CFG2_TFW_CONST_36 (37 * 2/fclk).
 *      - 37: GDRV_CFG2_TFW_CONST_37 (38 * 2/fclk).
 *      - 38: GDRV_CFG2_TFW_CONST_38 (39 * 2/fclk).
 *      - 39: GDRV_CFG2_TFW_CONST_39 (40 * 2/fclk).
 *      - 40: GDRV_CFG2_TFW_CONST_40 (41 * 2/fclk).
 *      - 41: GDRV_CFG2_TFW_CONST_41 (42 * 2/fclk).
 *      - 42: GDRV_CFG2_TFW_CONST_42 (43 * 2/fclk).
 *      - 43: GDRV_CFG2_TFW_CONST_43 (44 * 2/fclk).
 *      - 44: GDRV_CFG2_TFW_CONST_44 (45 * 2/fclk).
 *      - 45: GDRV_CFG2_TFW_CONST_45 (46 * 2/fclk).
 *      - 46: GDRV_CFG2_TFW_CONST_46 (47 * 2/fclk).
 *      - 47: GDRV_CFG2_TFW_CONST_47 (48 * 2/fclk).
 *      - 48: GDRV_CFG2_TFW_CONST_48 (49 * 2/fclk).
 *      - 49: GDRV_CFG2_TFW_CONST_49 (50 * 2/fclk).
 *      - 50: GDRV_CFG2_TFW_CONST_50 (51 * 2/fclk).
 *      - 51: GDRV_CFG2_TFW_CONST_51 (52 * 2/fclk).
 *      - 52: GDRV_CFG2_TFW_CONST_52 (53 * 2/fclk).
 *      - 53: GDRV_CFG2_TFW_CONST_53 (54 * 2/fclk).
 *      - 54: GDRV_CFG2_TFW_CONST_54 (55 * 2/fclk).
 *      - 55: GDRV_CFG2_TFW_CONST_55 (56 * 2/fclk).
 *      - 56: GDRV_CFG2_TFW_CONST_56 (57 * 2/fclk).
 *      - 57: GDRV_CFG2_TFW_CONST_57 (58 * 2/fclk).
 *      - 58: GDRV_CFG2_TFW_CONST_58 (59 * 2/fclk).
 *      - 59: GDRV_CFG2_TFW_CONST_59 (60 * 2/fclk).
 *      - 60: GDRV_CFG2_TFW_CONST_60 (61 * 2/fclk).
 *      - 61: GDRV_CFG2_TFW_CONST_61 (62 * 2/fclk).
 *      - 62: GDRV_CFG2_TFW_CONST_62 (63 * 2/fclk).
 *      - 63: GDRV_CFG2_TFW_CONST_63 (64 * 2/fclk).
 */
uint16 TLE9186_FuncLayer_get_GDRV_CFG2_TFW(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GDRV_CFG2.bit.TFW;
}

/**
 * @brief Set function for GDRV_CFG2_PWM_CHCK_EN.
 *
 * This function sets the bitfield Enable PWM alternation monitoring function in
 * register GDRV_CFG2.
 *
 * @param u16_value Value to be written into GDRV_CFG2_PWM_CHCK_EN. Valid values
 * are:
 *      - 0: GEN_CFG2_PWM_CHCK_EN_CONST_0 (PWM alternation check disabled ).
 *      - 1: GEN_CFG2_PWM_CHCK_EN_CONST_1 (PWM alternation check
 * enabled(Default)).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GDRV_CFG2_PWM_CHCK_EN(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GDRV_CFG2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GDRV_CFG2_PWM_CHCK_EN_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GDRV_CFG2_PWM_CHCK_EN_POS) &
           (uint16)TLE9186_GDRV_CFG2_PWM_CHCK_EN_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GDRV_CFG2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GDRV_CFG2_PWM_CHCK_EN.
 *
 * This function returns the value of the bitfield Enable PWM alternation
 * monitoring function within register GDRV_CFG2.
 *
 * @return Value of the bitfield GDRV_CFG2_PWM_CHCK_EN:
 *      - 0: GEN_CFG2_PWM_CHCK_EN_CONST_0 (PWM alternation check disabled ).
 *      - 1: GEN_CFG2_PWM_CHCK_EN_CONST_1 (PWM alternation check
 * enabled(Default)).
 */
uint16 TLE9186_FuncLayer_get_GDRV_CFG2_PWM_CHCK_EN(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->GDRV_CFG2.bit.PWM_CHCK_EN;
}

/**
 * @brief Set function for GDRV_CFG2_TCCP_CFG.
 *
 * This function sets the bitfield Cross-Current protection times clock
 * selection in register GDRV_CFG2.
 *
 * @param u16_value Value to be written into GDRV_CFG2_TCCP_CFG. Valid values
 * are:
 *      - 0: GEN_CFG2_TCCP_CFG_CONST_0 (18/fclk LSB size (Default)).
 *      - 1: GEN_CFG2_TCCP_CFG_CONST_1 (9/fclk LSB size).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GDRV_CFG2_TCCP_CFG(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GDRV_CFG2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GDRV_CFG2_TCCP_CFG_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GDRV_CFG2_TCCP_CFG_POS) &
           (uint16)TLE9186_GDRV_CFG2_TCCP_CFG_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GDRV_CFG2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GDRV_CFG2_TCCP_CFG.
 *
 * This function returns the value of the bitfield Cross-Current protection
 * times clock selection within register GDRV_CFG2.
 *
 * @return Value of the bitfield GDRV_CFG2_TCCP_CFG:
 *      - 0: GEN_CFG2_TCCP_CFG_CONST_0 (18/fclk LSB size (Default)).
 *      - 1: GEN_CFG2_TCCP_CFG_CONST_1 (9/fclk LSB size).
 */
uint16 TLE9186_FuncLayer_get_GDRV_CFG2_TCCP_CFG(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GDRV_CFG2.bit.TCCP_CFG;
}

/**
 * @brief get function for register GDRV_CFG2.
 *
 * This function reads the register Gate driver configuration register 2.
 *
 */
void TLE9186_FuncLayer_get_GDRV_CFG2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_GDRV_CFG2();
}

/**
 * @brief Set function for register GDRV_CFG3.
 *
 * This function sets the Gate driver configuration register 3.
 *
 * @param u16_value Value to be written into the register GDRV_CFG3.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GDRV_CFG3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GDRV_CFG3;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for GDRV_CFG3_IDCHG_ST.
 *
 * This function sets the bitfield Gate Driver static discharge current
 * configuration(last 3 LSBs of ICHG = 111) in register GDRV_CFG3.
 *
 * @param u16_value Value to be written into GDRV_CFG3_IDCHG_ST. Valid values
 * are:
 *      - 0: GDRV_CFG3_IDCHG_ST_CONST_0 (IDCHG9).
 *      - 1: GDRV_CFG3_IDCHG_ST_CONST_1 (IDCHG15).
 *      - 2: GDRV_CFG3_IDCHG_ST_CONST_2 (IDCHG23 (Default)).
 *      - 3: GDRV_CFG3_IDCHG_ST_CONST_3 (IDCHG31).
 *      - 4: GDRV_CFG3_IDCHG_ST_CONST_4 (IDCHG39).
 *      - 5: GDRV_CFG3_IDCHG_ST_CONST_5 (IDCHG47).
 *      - 6: GDRV_CFG3_IDCHG_ST_CONST_6 (IDCHG55).
 *      - 7: GDRV_CFG3_IDCHG_ST_CONST_7 (IDCHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GDRV_CFG3_IDCHG_ST(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GDRV_CFG3.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GDRV_CFG3_IDCHG_ST_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GDRV_CFG3_IDCHG_ST_POS) &
           (uint16)TLE9186_GDRV_CFG3_IDCHG_ST_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GDRV_CFG3;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GDRV_CFG3_IDCHG_ST.
 *
 * This function returns the value of the bitfield Gate Driver static discharge
 * current configuration(last 3 LSBs of ICHG = 111) within register GDRV_CFG3.
 *
 * @return Value of the bitfield GDRV_CFG3_IDCHG_ST:
 *      - 0: GDRV_CFG3_IDCHG_ST_CONST_0 (IDCHG9).
 *      - 1: GDRV_CFG3_IDCHG_ST_CONST_1 (IDCHG15).
 *      - 2: GDRV_CFG3_IDCHG_ST_CONST_2 (IDCHG23 (Default)).
 *      - 3: GDRV_CFG3_IDCHG_ST_CONST_3 (IDCHG31).
 *      - 4: GDRV_CFG3_IDCHG_ST_CONST_4 (IDCHG39).
 *      - 5: GDRV_CFG3_IDCHG_ST_CONST_5 (IDCHG47).
 *      - 6: GDRV_CFG3_IDCHG_ST_CONST_6 (IDCHG55).
 *      - 7: GDRV_CFG3_IDCHG_ST_CONST_7 (IDCHG63).
 */
uint16 TLE9186_FuncLayer_get_GDRV_CFG3_IDCHG_ST(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GDRV_CFG3.bit.IDCHG_ST;
}

/**
 * @brief Set function for GDRV_CFG3_IFW.
 *
 * This function sets the bitfield Freewheeling charge and discharge current
 * setting(last 3 LSBs of ICHG = 111) in register GDRV_CFG3.
 *
 * @param u16_value Value to be written into GDRV_CFG3_IFW. Valid values are:
 *      - 0: GDRV_CFG3_IFW_ST_CONST_0 (IDCHG9).
 *      - 1: GDRV_CFG3_IFW_ST_CONST_1 (IDCHG15).
 *      - 2: GDRV_CFG3_IFW_ST_CONST_2 (IDCHG23 ).
 *      - 3: GDRV_CFG3_IFW_ST_CONST_3 (IDCHG31).
 *      - 4: GDRV_CFG3_IFW_ST_CONST_4 (IDCHG39).
 *      - 5: GDRV_CFG3_IFW_ST_CONST_5 (IDCHG47 (Default)).
 *      - 6: GDRV_CFG3_IFW_ST_CONST_6 (IDCHG55).
 *      - 7: GDRV_CFG3_IFW_ST_CONST_7 (IDCHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GDRV_CFG3_IFW(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GDRV_CFG3.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GDRV_CFG3_IFW_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GDRV_CFG3_IFW_POS) &
           (uint16)TLE9186_GDRV_CFG3_IFW_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GDRV_CFG3;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GDRV_CFG3_IFW.
 *
 * This function returns the value of the bitfield Freewheeling charge and
 *discharge current setting(last 3 LSBs of ICHG = 111) within register
 *GDRV_CFG3.
 *
 * @return Value of the bitfield GDRV_CFG3_IFW:
 *      - 0: GDRV_CFG3_IFW_ST_CONST_0 (IDCHG9).
 *      - 1: GDRV_CFG3_IFW_ST_CONST_1 (IDCHG15).
 *      - 2: GDRV_CFG3_IFW_ST_CONST_2 (IDCHG23 ).
 *      - 3: GDRV_CFG3_IFW_ST_CONST_3 (IDCHG31).
 *      - 4: GDRV_CFG3_IFW_ST_CONST_4 (IDCHG39).
 *      - 5: GDRV_CFG3_IFW_ST_CONST_5 (IDCHG47 (Default)).
 *      - 6: GDRV_CFG3_IFW_ST_CONST_6 (IDCHG55).
 *      - 7: GDRV_CFG3_IFW_ST_CONST_7 (IDCHG63).
 */
uint16 TLE9186_FuncLayer_get_GDRV_CFG3_IFW(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GDRV_CFG3.bit.IFW;
}

/**
 * @brief Set function for GDRV_CFG3_IHOLD.
 *
 * This function sets the bitfield Bridge Driver Hold Current configuration in
 * register GDRV_CFG3.
 *
 * @param u16_value Value to be written into GDRV_CFG3_IHOLD. Valid values are:
 *      - 0: GDRV_CFG3_IHOLD_ST_CONST_0 (ICHG18(GDRV_RNG=0) OR
 * ICHG12(GDRV_RNG=1) (10mA)).
 *      - 1: GDRV_CFG3_IHOLD_ST_CONST_1 (ICHG22(GDRV_RNG=0) OR
 * ICHG16(GDRV_RNG=1) (15mA) (Default)).
 *      - 2: GDRV_CFG3_IHOLD_ST_CONST_2 (ICHG26(GDRV_RNG=0) OR
 * ICHG18(GDRV_RNG=1) (20mA)).
 *      - 3: GDRV_CFG3_IHOLD_ST_CONST_3 (ICHG32(GDRV_RNG=0) OR
 * ICHG23(GDRV_RNG=1) (30mA)).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GDRV_CFG3_IHOLD(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GDRV_CFG3.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GDRV_CFG3_IHOLD_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GDRV_CFG3_IHOLD_POS) &
           (uint16)TLE9186_GDRV_CFG3_IHOLD_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GDRV_CFG3;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GDRV_CFG3_IHOLD.
 *
 * This function returns the value of the bitfield Bridge Driver Hold Current
 * configuration within register GDRV_CFG3.
 *
 * @return Value of the bitfield GDRV_CFG3_IHOLD:
 *      - 0: GDRV_CFG3_IHOLD_ST_CONST_0 (ICHG18(GDRV_RNG=0) OR
 * ICHG12(GDRV_RNG=1) (10mA)).
 *      - 1: GDRV_CFG3_IHOLD_ST_CONST_1 (ICHG22(GDRV_RNG=0) OR
 * ICHG16(GDRV_RNG=1) (15mA) (Default)).
 *      - 2: GDRV_CFG3_IHOLD_ST_CONST_2 (ICHG26(GDRV_RNG=0) OR
 * ICHG18(GDRV_RNG=1) (20mA)).
 *      - 3: GDRV_CFG3_IHOLD_ST_CONST_3 (ICHG32(GDRV_RNG=0) OR
 * ICHG23(GDRV_RNG=1) (30mA)).
 */
uint16 TLE9186_FuncLayer_get_GDRV_CFG3_IHOLD(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GDRV_CFG3.bit.IHOLD;
}

/**
 * @brief Set function for GDRV_CFG3_ION_TR.
 *
 * This function sets the bitfield Configuration of the transition to
 * post-charge phase(current) in register GDRV_CFG3.
 *
 * @param u16_value Value to be written into GDRV_CFG3_ION_TR. Valid values are:
 *      - 0: GDRV_CFG3_ION_TR_ST_CONST_0 (I3ON post-charge current is reached by
 * a ramp current from I2ON with a 2 current steps per HB_FREQ clock cycle).
 *      - 1: GDRV_CFG3_ION_TR_ST_CONST_1 (I3ON post-charge current is reached by
 * a ramp current from I2ON with a 4 current steps per HB_FREQ clock cycle
 * (Default)).
 *      - 2: GDRV_CFG3_ION_TR_ST_CONST_2 (I3ON post-charge current is reached by
 * a ramp current from I2ON with a 8 current steps per HB_FREQ clock cycle).
 *      - 3: GDRV_CFG3_ION_TR_ST_CONST_3 (I3ON post-charge current applied
 * directly after I2ON phase).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_GDRV_CFG3_ION_TR(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->GDRV_CFG3.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_GDRV_CFG3_ION_TR_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_GDRV_CFG3_ION_TR_POS) &
           (uint16)TLE9186_GDRV_CFG3_ION_TR_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_GDRV_CFG3;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for GDRV_CFG3_ION_TR.
 *
 * This function returns the value of the bitfield Configuration of the
 * transition to post-charge phase(current) within register GDRV_CFG3.
 *
 * @return Value of the bitfield GDRV_CFG3_ION_TR:
 *      - 0: GDRV_CFG3_ION_TR_ST_CONST_0 (I3ON post-charge current is reached by
 * a ramp current from I2ON with a 2 current steps per HB_FREQ clock cycle).
 *      - 1: GDRV_CFG3_ION_TR_ST_CONST_1 (I3ON post-charge current is reached by
 * a ramp current from I2ON with a 4 current steps per HB_FREQ clock cycle
 * (Default)).
 *      - 2: GDRV_CFG3_ION_TR_ST_CONST_2 (I3ON post-charge current is reached by
 * a ramp current from I2ON with a 8 current steps per HB_FREQ clock cycle).
 *      - 3: GDRV_CFG3_ION_TR_ST_CONST_3 (I3ON post-charge current applied
 * directly after I2ON phase).
 */
uint16 TLE9186_FuncLayer_get_GDRV_CFG3_ION_TR(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->GDRV_CFG3.bit.ION_TR;
}

/**
 * @brief get function for register GDRV_CFG3.
 *
 * This function reads the register Gate driver configuration register 3.
 *
 */
void TLE9186_FuncLayer_get_GDRV_CFG3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_GDRV_CFG3();
}

/**
 * @brief Set function for register TON_HS.
 *
 * This function sets the Gate Driver Configuration register - TON_HS .
 *
 * @param u16_value Value to be written into the register TON_HS.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_TON_HS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_TON_HS;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for TON_HS_T2ON_HS.
 *
 * This function sets the bitfield High Side gate driver charge time
 * configuration in register TON_HS.
 *
 * @param u16_value Value to be written into TON_HS_T2ON_HS. Valid values are:
 *      - 0: TON_HS_T2ON_HS_CONST_0 (1 * 2/fclk).
 *      - 1: TON_HS_T2ON_HS_CONST_1 (2 * 2/fclk).
 *      - 2: TON_HS_T2ON_HS_CONST_2 (3 * 2/fclk).
 *      - 3: TON_HS_T2ON_HS_CONST_3 (4 * 2/fclk).
 *      - 4: TON_HS_T2ON_HS_CONST_4 (5 * 2/fclk).
 *      - 5: TON_HS_T2ON_HS_CONST_5 (6 * 2/fclk).
 *      - 6: TON_HS_T2ON_HS_CONST_6 (7 * 2/fclk).
 *      - 7: TON_HS_T2ON_HS_CONST_7 (8 * 2/fclk).
 *      - 8: TON_HS_T2ON_HS_CONST_8 (9 * 2/fclk).
 *      - 9: TON_HS_T2ON_HS_CONST_9 (10 * 2/fclk).
 *      - 10: TON_HS_T2ON_HS_CONST_10 (11 * 2/fclk).
 *      - 11: TON_HS_T2ON_HS_CONST_11 (12 * 2/fclk).
 *      - 12: TON_HS_T2ON_HS_CONST_12 (13 * 2/fclk).
 *      - 13: TON_HS_T2ON_HS_CONST_13 (14 * 2/fclk).
 *      - 14: TON_HS_T2ON_HS_CONST_14 (15 * 2/fclk).
 *      - 15: TON_HS_T2ON_HS_CONST_15 (16 * 2/fclk).
 *      - 16: TON_HS_T2ON_HS_CONST_16 (17 * 2/fclk).
 *      - 17: TON_HS_T2ON_HS_CONST_17 (18 * 2/fclk).
 *      - 18: TON_HS_T2ON_HS_CONST_18 (19 * 2/fclk).
 *      - 19: TON_HS_T2ON_HS_CONST_19 (20 * 2/fclk).
 *      - 20: TON_HS_T2ON_HS_CONST_20 (21 * 2/fclk).
 *      - 21: TON_HS_T2ON_HS_CONST_21 (22 * 2/fclk).
 *      - 22: TON_HS_T2ON_HS_CONST_22 (23 * 2/fclk).
 *      - 23: TON_HS_T2ON_HS_CONST_23 (24 * 2/fclk (Default)).
 *      - 24: TON_HS_T2ON_HS_CONST_24 (25 * 2/fclk).
 *      - 25: TON_HS_T2ON_HS_CONST_25 (26 * 2/fclk ).
 *      - 26: TON_HS_T2ON_HS_CONST_26 (27 * 2/fclk).
 *      - 27: TON_HS_T2ON_HS_CONST_27 (28 * 2/fclk).
 *      - 28: TON_HS_T2ON_HS_CONST_28 (29 * 2/fclk).
 *      - 29: TON_HS_T2ON_HS_CONST_29 (30 * 2/fclk).
 *      - 30: TON_HS_T2ON_HS_CONST_30 (31 * 2/fclk).
 *      - 31: TON_HS_T2ON_HS_CONST_31 (32 * 2/fclk).
 *      - 32: TON_HS_T2ON_HS_CONST_32 (33 * 2/fclk).
 *      - 33: TON_HS_T2ON_HS_CONST_33 (34 * 2/fclk).
 *      - 34: TON_HS_T2ON_HS_CONST_34 (35 * 2/fclk).
 *      - 35: TON_HS_T2ON_HS_CONST_35 (36 * 2/fclk).
 *      - 36: TON_HS_T2ON_HS_CONST_36 (37 * 2/fclk).
 *      - 37: TON_HS_T2ON_HS_CONST_37 (38 * 2/fclk).
 *      - 38: TON_HS_T2ON_HS_CONST_38 (39 * 2/fclk).
 *      - 39: TON_HS_T2ON_HS_CONST_39 (40 * 2/fclk).
 *      - 40: TON_HS_T2ON_HS_CONST_40 (41 * 2/fclk).
 *      - 41: TON_HS_T2ON_HS_CONST_41 (42 * 2/fclk).
 *      - 42: TON_HS_T2ON_HS_CONST_42 (43 * 2/fclk).
 *      - 43: TON_HS_T2ON_HS_CONST_43 (44 * 2/fclk).
 *      - 44: TON_HS_T2ON_HS_CONST_44 (45 * 2/fclk).
 *      - 45: TON_HS_T2ON_HS_CONST_45 (46 * 2/fclk).
 *      - 46: TON_HS_T2ON_HS_CONST_46 (47 * 2/fclk).
 *      - 47: TON_HS_T2ON_HS_CONST_47 (48 * 2/fclk).
 *      - 48: TON_HS_T2ON_HS_CONST_48 (49 * 2/fclk).
 *      - 49: TON_HS_T2ON_HS_CONST_49 (50 * 2/fclk).
 *      - 50: TON_HS_T2ON_HS_CONST_50 (51 * 2/fclk).
 *      - 51: TON_HS_T2ON_HS_CONST_51 (52 * 2/fclk).
 *      - 52: TON_HS_T2ON_HS_CONST_52 (53 * 2/fclk).
 *      - 53: TON_HS_T2ON_HS_CONST_53 (54 * 2/fclk).
 *      - 54: TON_HS_T2ON_HS_CONST_54 (55 * 2/fclk).
 *      - 55: TON_HS_T2ON_HS_CONST_55 (56 * 2/fclk).
 *      - 56: TON_HS_T2ON_HS_CONST_56 (57 * 2/fclk).
 *      - 57: TON_HS_T2ON_HS_CONST_57 (58 * 2/fclk).
 *      - 58: TON_HS_T2ON_HS_CONST_58 (59 * 2/fclk).
 *      - 59: TON_HS_T2ON_HS_CONST_59 (60 * 2/fclk).
 *      - 60: TON_HS_T2ON_HS_CONST_60 (61 * 2/fclk).
 *      - 61: TON_HS_T2ON_HS_CONST_61 (62 * 2/fclk).
 *      - 62: TON_HS_T2ON_HS_CONST_62 (63 * 2/fclk).
 *      - 63: TON_HS_T2ON_HS_CONST_63 (64 * 2/fclk).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_TON_HS_T2ON_HS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->TON_HS.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_TON_HS_T2ON_HS_MSK)) |
         (((((uint16)(u16_value)) << ((uint16)TLE9186_TON_HS_T2ON_HS_POS)) &
           (uint16)TLE9186_TON_HS_T2ON_HS_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_TON_HS;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for TON_HS_T2ON_HS.
 *
 * This function returns the value of the bitfield High Side gate driver charge
 * time configuration within register TON_HS.
 *
 * @return Value of the bitfield TON_HS_T2ON_HS:
 *      - 0: TON_HS_T2ON_HS_CONST_0 (1 * 2/fclk).
 *      - 1: TON_HS_T2ON_HS_CONST_1 (2 * 2/fclk).
 *      - 2: TON_HS_T2ON_HS_CONST_2 (3 * 2/fclk).
 *      - 3: TON_HS_T2ON_HS_CONST_3 (4 * 2/fclk).
 *      - 4: TON_HS_T2ON_HS_CONST_4 (5 * 2/fclk).
 *      - 5: TON_HS_T2ON_HS_CONST_5 (6 * 2/fclk).
 *      - 6: TON_HS_T2ON_HS_CONST_6 (7 * 2/fclk).
 *      - 7: TON_HS_T2ON_HS_CONST_7 (8 * 2/fclk).
 *      - 8: TON_HS_T2ON_HS_CONST_8 (9 * 2/fclk).
 *      - 9: TON_HS_T2ON_HS_CONST_9 (10 * 2/fclk).
 *      - 10: TON_HS_T2ON_HS_CONST_10 (11 * 2/fclk).
 *      - 11: TON_HS_T2ON_HS_CONST_11 (12 * 2/fclk).
 *      - 12: TON_HS_T2ON_HS_CONST_12 (13 * 2/fclk).
 *      - 13: TON_HS_T2ON_HS_CONST_13 (14 * 2/fclk).
 *      - 14: TON_HS_T2ON_HS_CONST_14 (15 * 2/fclk).
 *      - 15: TON_HS_T2ON_HS_CONST_15 (16 * 2/fclk).
 *      - 16: TON_HS_T2ON_HS_CONST_16 (17 * 2/fclk).
 *      - 17: TON_HS_T2ON_HS_CONST_17 (18 * 2/fclk).
 *      - 18: TON_HS_T2ON_HS_CONST_18 (19 * 2/fclk).
 *      - 19: TON_HS_T2ON_HS_CONST_19 (20 * 2/fclk).
 *      - 20: TON_HS_T2ON_HS_CONST_20 (21 * 2/fclk).
 *      - 21: TON_HS_T2ON_HS_CONST_21 (22 * 2/fclk).
 *      - 22: TON_HS_T2ON_HS_CONST_22 (23 * 2/fclk).
 *      - 23: TON_HS_T2ON_HS_CONST_23 (24 * 2/fclk (Default)).
 *      - 24: TON_HS_T2ON_HS_CONST_24 (25 * 2/fclk).
 *      - 25: TON_HS_T2ON_HS_CONST_25 (26 * 2/fclk ).
 *      - 26: TON_HS_T2ON_HS_CONST_26 (27 * 2/fclk).
 *      - 27: TON_HS_T2ON_HS_CONST_27 (28 * 2/fclk).
 *      - 28: TON_HS_T2ON_HS_CONST_28 (29 * 2/fclk).
 *      - 29: TON_HS_T2ON_HS_CONST_29 (30 * 2/fclk).
 *      - 30: TON_HS_T2ON_HS_CONST_30 (31 * 2/fclk).
 *      - 31: TON_HS_T2ON_HS_CONST_31 (32 * 2/fclk).
 *      - 32: TON_HS_T2ON_HS_CONST_32 (33 * 2/fclk).
 *      - 33: TON_HS_T2ON_HS_CONST_33 (34 * 2/fclk).
 *      - 34: TON_HS_T2ON_HS_CONST_34 (35 * 2/fclk).
 *      - 35: TON_HS_T2ON_HS_CONST_35 (36 * 2/fclk).
 *      - 36: TON_HS_T2ON_HS_CONST_36 (37 * 2/fclk).
 *      - 37: TON_HS_T2ON_HS_CONST_37 (38 * 2/fclk).
 *      - 38: TON_HS_T2ON_HS_CONST_38 (39 * 2/fclk).
 *      - 39: TON_HS_T2ON_HS_CONST_39 (40 * 2/fclk).
 *      - 40: TON_HS_T2ON_HS_CONST_40 (41 * 2/fclk).
 *      - 41: TON_HS_T2ON_HS_CONST_41 (42 * 2/fclk).
 *      - 42: TON_HS_T2ON_HS_CONST_42 (43 * 2/fclk).
 *      - 43: TON_HS_T2ON_HS_CONST_43 (44 * 2/fclk).
 *      - 44: TON_HS_T2ON_HS_CONST_44 (45 * 2/fclk).
 *      - 45: TON_HS_T2ON_HS_CONST_45 (46 * 2/fclk).
 *      - 46: TON_HS_T2ON_HS_CONST_46 (47 * 2/fclk).
 *      - 47: TON_HS_T2ON_HS_CONST_47 (48 * 2/fclk).
 *      - 48: TON_HS_T2ON_HS_CONST_48 (49 * 2/fclk).
 *      - 49: TON_HS_T2ON_HS_CONST_49 (50 * 2/fclk).
 *      - 50: TON_HS_T2ON_HS_CONST_50 (51 * 2/fclk).
 *      - 51: TON_HS_T2ON_HS_CONST_51 (52 * 2/fclk).
 *      - 52: TON_HS_T2ON_HS_CONST_52 (53 * 2/fclk).
 *      - 53: TON_HS_T2ON_HS_CONST_53 (54 * 2/fclk).
 *      - 54: TON_HS_T2ON_HS_CONST_54 (55 * 2/fclk).
 *      - 55: TON_HS_T2ON_HS_CONST_55 (56 * 2/fclk).
 *      - 56: TON_HS_T2ON_HS_CONST_56 (57 * 2/fclk).
 *      - 57: TON_HS_T2ON_HS_CONST_57 (58 * 2/fclk).
 *      - 58: TON_HS_T2ON_HS_CONST_58 (59 * 2/fclk).
 *      - 59: TON_HS_T2ON_HS_CONST_59 (60 * 2/fclk).
 *      - 60: TON_HS_T2ON_HS_CONST_60 (61 * 2/fclk).
 *      - 61: TON_HS_T2ON_HS_CONST_61 (62 * 2/fclk).
 *      - 62: TON_HS_T2ON_HS_CONST_62 (63 * 2/fclk).
 *      - 63: TON_HS_T2ON_HS_CONST_63 (64 * 2/fclk).
 */
uint16 TLE9186_FuncLayer_get_TON_HS_T2ON_HS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->TON_HS.bit.T2ON_HS;
}

/**
 * @brief Set function for TON_HS_T1ON_HS.
 *
 * This function sets the bitfield High Side gate driver pre-charge time
 * configuration in register TON_HS.
 *
 * @param u16_value Value to be written into TON_HS_T1ON_HS. Valid values are:
 *      - 0: TON_HS_T1ON_HS_CONST_0 (1 * 2/fclk).
 *      - 1: TON_HS_T1ON_HS_CONST_1 (2 * 2/fclk).
 *      - 2: TON_HS_T1ON_HS_CONST_2 (3 * 2/fclk).
 *      - 3: TON_HS_T1ON_HS_CONST_3 (4 * 2/fclk).
 *      - 4: TON_HS_T1ON_HS_CONST_4 (5 * 2/fclk).
 *      - 5: TON_HS_T1ON_HS_CONST_5 (6 * 2/fclk).
 *      - 6: TON_HS_T1ON_HS_CONST_6 (7 * 2/fclk).
 *      - 7: TON_HS_T1ON_HS_CONST_7 (8 * 2/fclk (Default)).
 *      - 8: TON_HS_T1ON_HS_CONST_8 (9 * 2/fclk).
 *      - 9: TON_HS_T1ON_HS_CONST_9 (10 * 2/fclk).
 *      - 10: TON_HS_T1ON_HS_CONST_10 (11 * 2/fclk).
 *      - 11: TON_HS_T1ON_HS_CONST_11 (12 * 2/fclk).
 *      - 12: TON_HS_T1ON_HS_CONST_12 (13 * 2/fclk).
 *      - 13: TON_HS_T1ON_HS_CONST_13 (14 * 2/fclk).
 *      - 14: TON_HS_T1ON_HS_CONST_14 (15 * 2/fclk).
 *      - 15: TON_HS_T1ON_HS_CONST_15 (16 * 2/fclk).
 *      - 16: TON_HS_T1ON_HS_CONST_16 (17 * 2/fclk).
 *      - 17: TON_HS_T1ON_HS_CONST_17 (18 * 2/fclk).
 *      - 18: TON_HS_T1ON_HS_CONST_18 (19 * 2/fclk).
 *      - 19: TON_HS_T1ON_HS_CONST_19 (20 * 2/fclk).
 *      - 20: TON_HS_T1ON_HS_CONST_20 (21 * 2/fclk).
 *      - 21: TON_HS_T1ON_HS_CONST_21 (22 * 2/fclk).
 *      - 22: TON_HS_T1ON_HS_CONST_22 (23 * 2/fclk).
 *      - 23: TON_HS_T1ON_HS_CONST_23 (24 * 2/fclk ).
 *      - 24: TON_HS_T1ON_HS_CONST_24 (25 * 2/fclk).
 *      - 25: TON_HS_T1ON_HS_CONST_25 (26 * 2/fclk ).
 *      - 26: TON_HS_T1ON_HS_CONST_26 (27 * 2/fclk).
 *      - 27: TON_HS_T1ON_HS_CONST_27 (28 * 2/fclk).
 *      - 28: TON_HS_T1ON_HS_CONST_28 (29 * 2/fclk).
 *      - 29: TON_HS_T1ON_HS_CONST_29 (30 * 2/fclk).
 *      - 30: TON_HS_T1ON_HS_CONST_30 (31 * 2/fclk).
 *      - 31: TON_HS_T1ON_HS_CONST_31 (32 * 2/fclk).
 *      - 32: TON_HS_T1ON_HS_CONST_32 (33 * 2/fclk).
 *      - 33: TON_HS_T1ON_HS_CONST_33 (34 * 2/fclk).
 *      - 34: TON_HS_T1ON_HS_CONST_34 (35 * 2/fclk).
 *      - 35: TON_HS_T1ON_HS_CONST_35 (36 * 2/fclk).
 *      - 36: TON_HS_T1ON_HS_CONST_36 (37 * 2/fclk).
 *      - 37: TON_HS_T1ON_HS_CONST_37 (38 * 2/fclk).
 *      - 38: TON_HS_T1ON_HS_CONST_38 (39 * 2/fclk).
 *      - 39: TON_HS_T1ON_HS_CONST_39 (40 * 2/fclk).
 *      - 40: TON_HS_T1ON_HS_CONST_40 (41 * 2/fclk).
 *      - 41: TON_HS_T1ON_HS_CONST_41 (42 * 2/fclk).
 *      - 42: TON_HS_T1ON_HS_CONST_42 (43 * 2/fclk).
 *      - 43: TON_HS_T1ON_HS_CONST_43 (44 * 2/fclk).
 *      - 44: TON_HS_T1ON_HS_CONST_44 (45 * 2/fclk).
 *      - 45: TON_HS_T1ON_HS_CONST_45 (46 * 2/fclk).
 *      - 46: TON_HS_T1ON_HS_CONST_46 (47 * 2/fclk).
 *      - 47: TON_HS_T1ON_HS_CONST_47 (48 * 2/fclk).
 *      - 48: TON_HS_T1ON_HS_CONST_48 (49 * 2/fclk).
 *      - 49: TON_HS_T1ON_HS_CONST_49 (50 * 2/fclk).
 *      - 50: TON_HS_T1ON_HS_CONST_50 (51 * 2/fclk).
 *      - 51: TON_HS_T1ON_HS_CONST_51 (52 * 2/fclk).
 *      - 52: TON_HS_T1ON_HS_CONST_52 (53 * 2/fclk).
 *      - 53: TON_HS_T1ON_HS_CONST_53 (54 * 2/fclk).
 *      - 54: TON_HS_T1ON_HS_CONST_54 (55 * 2/fclk).
 *      - 55: TON_HS_T1ON_HS_CONST_55 (56 * 2/fclk).
 *      - 56: TON_HS_T1ON_HS_CONST_56 (57 * 2/fclk).
 *      - 57: TON_HS_T1ON_HS_CONST_57 (58 * 2/fclk).
 *      - 58: TON_HS_T1ON_HS_CONST_58 (59 * 2/fclk).
 *      - 59: TON_HS_T1ON_HS_CONST_59 (60 * 2/fclk).
 *      - 60: TON_HS_T1ON_HS_CONST_60 (61 * 2/fclk).
 *      - 61: TON_HS_T1ON_HS_CONST_61 (62 * 2/fclk).
 *      - 62: TON_HS_T1ON_HS_CONST_62 (63 * 2/fclk).
 *      - 63: TON_HS_T1ON_HS_CONST_63 (64 * 2/fclk).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_TON_HS_T1ON_HS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->TON_HS.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_TON_HS_T1ON_HS_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_TON_HS_T1ON_HS_POS) &
           (uint16)TLE9186_TON_HS_T1ON_HS_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_TON_HS;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for TON_HS_T1ON_HS.
 *
 * This function returns the value of the bitfield High Side gate driver
 * pre-charge time configuration within register TON_HS.
 *
 * @return Value of the bitfield TON_HS_T1ON_HS:
 *      - 0: TON_HS_T1ON_HS_CONST_0 (1 * 2/fclk).
 *      - 1: TON_HS_T1ON_HS_CONST_1 (2 * 2/fclk).
 *      - 2: TON_HS_T1ON_HS_CONST_2 (3 * 2/fclk).
 *      - 3: TON_HS_T1ON_HS_CONST_3 (4 * 2/fclk).
 *      - 4: TON_HS_T1ON_HS_CONST_4 (5 * 2/fclk).
 *      - 5: TON_HS_T1ON_HS_CONST_5 (6 * 2/fclk).
 *      - 6: TON_HS_T1ON_HS_CONST_6 (7 * 2/fclk).
 *      - 7: TON_HS_T1ON_HS_CONST_7 (8 * 2/fclk (Default)).
 *      - 8: TON_HS_T1ON_HS_CONST_8 (9 * 2/fclk).
 *      - 9: TON_HS_T1ON_HS_CONST_9 (10 * 2/fclk).
 *      - 10: TON_HS_T1ON_HS_CONST_10 (11 * 2/fclk).
 *      - 11: TON_HS_T1ON_HS_CONST_11 (12 * 2/fclk).
 *      - 12: TON_HS_T1ON_HS_CONST_12 (13 * 2/fclk).
 *      - 13: TON_HS_T1ON_HS_CONST_13 (14 * 2/fclk).
 *      - 14: TON_HS_T1ON_HS_CONST_14 (15 * 2/fclk).
 *      - 15: TON_HS_T1ON_HS_CONST_15 (16 * 2/fclk).
 *      - 16: TON_HS_T1ON_HS_CONST_16 (17 * 2/fclk).
 *      - 17: TON_HS_T1ON_HS_CONST_17 (18 * 2/fclk).
 *      - 18: TON_HS_T1ON_HS_CONST_18 (19 * 2/fclk).
 *      - 19: TON_HS_T1ON_HS_CONST_19 (20 * 2/fclk).
 *      - 20: TON_HS_T1ON_HS_CONST_20 (21 * 2/fclk).
 *      - 21: TON_HS_T1ON_HS_CONST_21 (22 * 2/fclk).
 *      - 22: TON_HS_T1ON_HS_CONST_22 (23 * 2/fclk).
 *      - 23: TON_HS_T1ON_HS_CONST_23 (24 * 2/fclk ).
 *      - 24: TON_HS_T1ON_HS_CONST_24 (25 * 2/fclk).
 *      - 25: TON_HS_T1ON_HS_CONST_25 (26 * 2/fclk ).
 *      - 26: TON_HS_T1ON_HS_CONST_26 (27 * 2/fclk).
 *      - 27: TON_HS_T1ON_HS_CONST_27 (28 * 2/fclk).
 *      - 28: TON_HS_T1ON_HS_CONST_28 (29 * 2/fclk).
 *      - 29: TON_HS_T1ON_HS_CONST_29 (30 * 2/fclk).
 *      - 30: TON_HS_T1ON_HS_CONST_30 (31 * 2/fclk).
 *      - 31: TON_HS_T1ON_HS_CONST_31 (32 * 2/fclk).
 *      - 32: TON_HS_T1ON_HS_CONST_32 (33 * 2/fclk).
 *      - 33: TON_HS_T1ON_HS_CONST_33 (34 * 2/fclk).
 *      - 34: TON_HS_T1ON_HS_CONST_34 (35 * 2/fclk).
 *      - 35: TON_HS_T1ON_HS_CONST_35 (36 * 2/fclk).
 *      - 36: TON_HS_T1ON_HS_CONST_36 (37 * 2/fclk).
 *      - 37: TON_HS_T1ON_HS_CONST_37 (38 * 2/fclk).
 *      - 38: TON_HS_T1ON_HS_CONST_38 (39 * 2/fclk).
 *      - 39: TON_HS_T1ON_HS_CONST_39 (40 * 2/fclk).
 *      - 40: TON_HS_T1ON_HS_CONST_40 (41 * 2/fclk).
 *      - 41: TON_HS_T1ON_HS_CONST_41 (42 * 2/fclk).
 *      - 42: TON_HS_T1ON_HS_CONST_42 (43 * 2/fclk).
 *      - 43: TON_HS_T1ON_HS_CONST_43 (44 * 2/fclk).
 *      - 44: TON_HS_T1ON_HS_CONST_44 (45 * 2/fclk).
 *      - 45: TON_HS_T1ON_HS_CONST_45 (46 * 2/fclk).
 *      - 46: TON_HS_T1ON_HS_CONST_46 (47 * 2/fclk).
 *      - 47: TON_HS_T1ON_HS_CONST_47 (48 * 2/fclk).
 *      - 48: TON_HS_T1ON_HS_CONST_48 (49 * 2/fclk).
 *      - 49: TON_HS_T1ON_HS_CONST_49 (50 * 2/fclk).
 *      - 50: TON_HS_T1ON_HS_CONST_50 (51 * 2/fclk).
 *      - 51: TON_HS_T1ON_HS_CONST_51 (52 * 2/fclk).
 *      - 52: TON_HS_T1ON_HS_CONST_52 (53 * 2/fclk).
 *      - 53: TON_HS_T1ON_HS_CONST_53 (54 * 2/fclk).
 *      - 54: TON_HS_T1ON_HS_CONST_54 (55 * 2/fclk).
 *      - 55: TON_HS_T1ON_HS_CONST_55 (56 * 2/fclk).
 *      - 56: TON_HS_T1ON_HS_CONST_56 (57 * 2/fclk).
 *      - 57: TON_HS_T1ON_HS_CONST_57 (58 * 2/fclk).
 *      - 58: TON_HS_T1ON_HS_CONST_58 (59 * 2/fclk).
 *      - 59: TON_HS_T1ON_HS_CONST_59 (60 * 2/fclk).
 *      - 60: TON_HS_T1ON_HS_CONST_60 (61 * 2/fclk).
 *      - 61: TON_HS_T1ON_HS_CONST_61 (62 * 2/fclk).
 *      - 62: TON_HS_T1ON_HS_CONST_62 (63 * 2/fclk).
 *      - 63: TON_HS_T1ON_HS_CONST_63 (64 * 2/fclk).
 */
uint16 TLE9186_FuncLayer_get_TON_HS_T1ON_HS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->TON_HS.bit.T1ON_HS;
}

/**
 * @brief get function for register TON_HS.
 *
 * This function reads the register Gate Driver Configuration register - TON_HS
 * .
 *
 */
void TLE9186_FuncLayer_get_TON_HS(void) /* polyspace MISRA2012:5.1 [Justified:
                                           Low] "Given due to register names" */
{
  TLE9186_RegLayer_get_TON_HS();
}

/**
 * @brief Set function for register TON_LS.
 *
 * This function sets the Gate Driver Configuration register - TON_LS .
 *
 * @param u16_value Value to be written into the register TON_LS.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_TON_LS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_TON_LS;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for TON_LS_T2ON_LS.
 *
 * This function sets the bitfield Low Side gate driver charge time
 * configuration in register TON_LS.
 *
 * @param u16_value Value to be written into TON_LS_T2ON_LS. Valid values are:
 *      - 0: TON_HS_T2ON_LS_CONST_0 (1 * 2/fclk).
 *      - 1: TON_LS_T2ON_LS_CONST_1 (2 * 2/fclk).
 *      - 2: TON_LS_T2ON_LS_CONST_2 (3 * 2/fclk).
 *      - 3: TON_LS_T2ON_LS_CONST_3 (4 * 2/fclk).
 *      - 4: TON_LS_T2ON_LS_CONST_4 (5 * 2/fclk).
 *      - 5: TON_LS_T2ON_LS_CONST_5 (6 * 2/fclk).
 *      - 6: TON_LS_T2ON_LS_CONST_6 (7 * 2/fclk).
 *      - 7: TON_LS_T2ON_LS_CONST_7 (8 * 2/fclk).
 *      - 8: TON_LS_T2ON_LS_CONST_8 (9 * 2/fclk).
 *      - 9: TON_LS_T2ON_LS_CONST_9 (10 * 2/fclk).
 *      - 10: TON_LS_T2ON_LS_CONST_10 (11 * 2/fclk).
 *      - 11: TON_LS_T2ON_LS_CONST_11 (12 * 2/fclk).
 *      - 12: TON_LS_T2ON_LS_CONST_12 (13 * 2/fclk).
 *      - 13: TON_LS_T2ON_LS_CONST_13 (14 * 2/fclk).
 *      - 14: TON_LS_T2ON_LS_CONST_14 (15 * 2/fclk).
 *      - 15: TON_LS_T2ON_LS_CONST_15 (16 * 2/fclk).
 *      - 16: TON_LS_T2ON_LS_CONST_16 (17 * 2/fclk).
 *      - 17: TON_LS_T2ON_LS_CONST_17 (18 * 2/fclk).
 *      - 18: TON_LS_T2ON_LS_CONST_18 (19 * 2/fclk).
 *      - 19: TON_LS_T2ON_LS_CONST_19 (20 * 2/fclk).
 *      - 20: TON_LS_T2ON_LS_CONST_20 (21 * 2/fclk).
 *      - 21: TON_LS_T2ON_LS_CONST_21 (22 * 2/fclk).
 *      - 22: TON_LS_T2ON_LS_CONST_22 (23 * 2/fclk).
 *      - 23: TON_LS_T2ON_LS_CONST_23 (24 * 2/fclk (Default)).
 *      - 24: TON_LS_T2ON_LS_CONST_24 (25 * 2/fclk).
 *      - 25: TON_LS_T2ON_LS_CONST_25 (26 * 2/fclk ).
 *      - 26: TON_LS_T2ON_LS_CONST_26 (27 * 2/fclk).
 *      - 27: TON_LS_T2ON_LS_CONST_27 (28 * 2/fclk).
 *      - 28: TON_LS_T2ON_LS_CONST_28 (29 * 2/fclk).
 *      - 29: TON_LS_T2ON_LS_CONST_29 (30 * 2/fclk).
 *      - 30: TON_LS_T2ON_LS_CONST_30 (31 * 2/fclk).
 *      - 31: TON_LS_T2ON_LS_CONST_31 (32 * 2/fclk).
 *      - 32: TON_LS_T2ON_LS_CONST_32 (33 * 2/fclk).
 *      - 33: TON_LS_T2ON_LS_CONST_33 (34 * 2/fclk).
 *      - 34: TON_LS_T2ON_LS_CONST_34 (35 * 2/fclk).
 *      - 35: TON_LS_T2ON_LS_CONST_35 (36 * 2/fclk).
 *      - 36: TON_LS_T2ON_LS_CONST_36 (37 * 2/fclk).
 *      - 37: TON_LS_T2ON_LS_CONST_37 (38 * 2/fclk).
 *      - 38: TON_LS_T2ON_LS_CONST_38 (39 * 2/fclk).
 *      - 39: TON_LS_T2ON_LS_CONST_39 (40 * 2/fclk).
 *      - 40: TON_LS_T2ON_LS_CONST_40 (41 * 2/fclk).
 *      - 41: TON_LS_T2ON_LS_CONST_41 (42 * 2/fclk).
 *      - 42: TON_LS_T2ON_LS_CONST_42 (43 * 2/fclk).
 *      - 43: TON_LS_T2ON_LS_CONST_43 (44 * 2/fclk).
 *      - 44: TON_LS_T2ON_LS_CONST_44 (45 * 2/fclk).
 *      - 45: TON_LS_T2ON_LS_CONST_45 (46 * 2/fclk).
 *      - 46: TON_LS_T2ON_LS_CONST_46 (47 * 2/fclk).
 *      - 47: TON_LS_T2ON_LS_CONST_47 (48 * 2/fclk).
 *      - 48: TON_LS_T2ON_LS_CONST_48 (49 * 2/fclk).
 *      - 49: TON_LS_T2ON_LS_CONST_49 (50 * 2/fclk).
 *      - 50: TON_LS_T2ON_LS_CONST_50 (51 * 2/fclk).
 *      - 51: TON_LS_T2ON_LS_CONST_51 (52 * 2/fclk).
 *      - 52: TON_LS_T2ON_LS_CONST_52 (53 * 2/fclk).
 *      - 53: TON_LS_T2ON_LS_CONST_53 (54 * 2/fclk).
 *      - 54: TON_LS_T2ON_LS_CONST_54 (55 * 2/fclk).
 *      - 55: TON_LS_T2ON_LS_CONST_55 (56 * 2/fclk).
 *      - 56: TON_LS_T2ON_LS_CONST_56 (57 * 2/fclk).
 *      - 57: TON_LS_T2ON_LS_CONST_57 (58 * 2/fclk).
 *      - 58: TON_LS_T2ON_LS_CONST_58 (59 * 2/fclk).
 *      - 59: TON_LS_T2ON_LS_CONST_59 (60 * 2/fclk).
 *      - 60: TON_LS_T2ON_LS_CONST_60 (61 * 2/fclk).
 *      - 61: TON_LS_T2ON_LS_CONST_61 (62 * 2/fclk).
 *      - 62: TON_LS_T2ON_LS_CONST_62 (63 * 2/fclk).
 *      - 63: TON_LS_T2ON_LS_CONST_63 (64 * 2/fclk).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_TON_LS_T2ON_LS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->TON_LS.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_TON_LS_T2ON_LS_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_TON_LS_T2ON_LS_POS) &
           (uint16)TLE9186_TON_LS_T2ON_LS_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_TON_LS;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for TON_LS_T2ON_LS.
 *
 * This function returns the value of the bitfield Low Side gate driver charge
 * time configuration within register TON_LS.
 *
 * @return Value of the bitfield TON_LS_T2ON_LS:
 *      - 0: TON_HS_T2ON_LS_CONST_0 (1 * 2/fclk).
 *      - 1: TON_LS_T2ON_LS_CONST_1 (2 * 2/fclk).
 *      - 2: TON_LS_T2ON_LS_CONST_2 (3 * 2/fclk).
 *      - 3: TON_LS_T2ON_LS_CONST_3 (4 * 2/fclk).
 *      - 4: TON_LS_T2ON_LS_CONST_4 (5 * 2/fclk).
 *      - 5: TON_LS_T2ON_LS_CONST_5 (6 * 2/fclk).
 *      - 6: TON_LS_T2ON_LS_CONST_6 (7 * 2/fclk).
 *      - 7: TON_LS_T2ON_LS_CONST_7 (8 * 2/fclk).
 *      - 8: TON_LS_T2ON_LS_CONST_8 (9 * 2/fclk).
 *      - 9: TON_LS_T2ON_LS_CONST_9 (10 * 2/fclk).
 *      - 10: TON_LS_T2ON_LS_CONST_10 (11 * 2/fclk).
 *      - 11: TON_LS_T2ON_LS_CONST_11 (12 * 2/fclk).
 *      - 12: TON_LS_T2ON_LS_CONST_12 (13 * 2/fclk).
 *      - 13: TON_LS_T2ON_LS_CONST_13 (14 * 2/fclk).
 *      - 14: TON_LS_T2ON_LS_CONST_14 (15 * 2/fclk).
 *      - 15: TON_LS_T2ON_LS_CONST_15 (16 * 2/fclk).
 *      - 16: TON_LS_T2ON_LS_CONST_16 (17 * 2/fclk).
 *      - 17: TON_LS_T2ON_LS_CONST_17 (18 * 2/fclk).
 *      - 18: TON_LS_T2ON_LS_CONST_18 (19 * 2/fclk).
 *      - 19: TON_LS_T2ON_LS_CONST_19 (20 * 2/fclk).
 *      - 20: TON_LS_T2ON_LS_CONST_20 (21 * 2/fclk).
 *      - 21: TON_LS_T2ON_LS_CONST_21 (22 * 2/fclk).
 *      - 22: TON_LS_T2ON_LS_CONST_22 (23 * 2/fclk).
 *      - 23: TON_LS_T2ON_LS_CONST_23 (24 * 2/fclk (Default)).
 *      - 24: TON_LS_T2ON_LS_CONST_24 (25 * 2/fclk).
 *      - 25: TON_LS_T2ON_LS_CONST_25 (26 * 2/fclk ).
 *      - 26: TON_LS_T2ON_LS_CONST_26 (27 * 2/fclk).
 *      - 27: TON_LS_T2ON_LS_CONST_27 (28 * 2/fclk).
 *      - 28: TON_LS_T2ON_LS_CONST_28 (29 * 2/fclk).
 *      - 29: TON_LS_T2ON_LS_CONST_29 (30 * 2/fclk).
 *      - 30: TON_LS_T2ON_LS_CONST_30 (31 * 2/fclk).
 *      - 31: TON_LS_T2ON_LS_CONST_31 (32 * 2/fclk).
 *      - 32: TON_LS_T2ON_LS_CONST_32 (33 * 2/fclk).
 *      - 33: TON_LS_T2ON_LS_CONST_33 (34 * 2/fclk).
 *      - 34: TON_LS_T2ON_LS_CONST_34 (35 * 2/fclk).
 *      - 35: TON_LS_T2ON_LS_CONST_35 (36 * 2/fclk).
 *      - 36: TON_LS_T2ON_LS_CONST_36 (37 * 2/fclk).
 *      - 37: TON_LS_T2ON_LS_CONST_37 (38 * 2/fclk).
 *      - 38: TON_LS_T2ON_LS_CONST_38 (39 * 2/fclk).
 *      - 39: TON_LS_T2ON_LS_CONST_39 (40 * 2/fclk).
 *      - 40: TON_LS_T2ON_LS_CONST_40 (41 * 2/fclk).
 *      - 41: TON_LS_T2ON_LS_CONST_41 (42 * 2/fclk).
 *      - 42: TON_LS_T2ON_LS_CONST_42 (43 * 2/fclk).
 *      - 43: TON_LS_T2ON_LS_CONST_43 (44 * 2/fclk).
 *      - 44: TON_LS_T2ON_LS_CONST_44 (45 * 2/fclk).
 *      - 45: TON_LS_T2ON_LS_CONST_45 (46 * 2/fclk).
 *      - 46: TON_LS_T2ON_LS_CONST_46 (47 * 2/fclk).
 *      - 47: TON_LS_T2ON_LS_CONST_47 (48 * 2/fclk).
 *      - 48: TON_LS_T2ON_LS_CONST_48 (49 * 2/fclk).
 *      - 49: TON_LS_T2ON_LS_CONST_49 (50 * 2/fclk).
 *      - 50: TON_LS_T2ON_LS_CONST_50 (51 * 2/fclk).
 *      - 51: TON_LS_T2ON_LS_CONST_51 (52 * 2/fclk).
 *      - 52: TON_LS_T2ON_LS_CONST_52 (53 * 2/fclk).
 *      - 53: TON_LS_T2ON_LS_CONST_53 (54 * 2/fclk).
 *      - 54: TON_LS_T2ON_LS_CONST_54 (55 * 2/fclk).
 *      - 55: TON_LS_T2ON_LS_CONST_55 (56 * 2/fclk).
 *      - 56: TON_LS_T2ON_LS_CONST_56 (57 * 2/fclk).
 *      - 57: TON_LS_T2ON_LS_CONST_57 (58 * 2/fclk).
 *      - 58: TON_LS_T2ON_LS_CONST_58 (59 * 2/fclk).
 *      - 59: TON_LS_T2ON_LS_CONST_59 (60 * 2/fclk).
 *      - 60: TON_LS_T2ON_LS_CONST_60 (61 * 2/fclk).
 *      - 61: TON_LS_T2ON_LS_CONST_61 (62 * 2/fclk).
 *      - 62: TON_LS_T2ON_LS_CONST_62 (63 * 2/fclk).
 *      - 63: TON_LS_T2ON_LS_CONST_63 (64 * 2/fclk).
 */
uint16 TLE9186_FuncLayer_get_TON_LS_T2ON_LS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->TON_LS.bit.T2ON_LS;
}

/**
 * @brief Set function for TON_LS_T1ON_LS.
 *
 * This function sets the bitfield Low Side gate driver pre-charge time
 * configuration in register TON_LS.
 *
 * @param u16_value Value to be written into TON_LS_T1ON_LS. Valid values are:
 *      - 0: TON_LS_T1ON_LS_CONST_0 (1 * 2/fclk).
 *      - 1: TON_LS_T1ON_LS_CONST_1 (2 * 2/fclk).
 *      - 2: TON_LS_T1ON_LS_CONST_2 (3 * 2/fclk).
 *      - 3: TON_LS_T1ON_LS_CONST_3 (4 * 2/fclk).
 *      - 4: TON_LS_T1ON_LS_CONST_4 (5 * 2/fclk).
 *      - 5: TON_LS_T1ON_LS_CONST_5 (6 * 2/fclk).
 *      - 6: TON_LS_T1ON_LS_CONST_6 (7 * 2/fclk).
 *      - 7: TON_LS_T1ON_LS_CONST_7 (8 * 2/fclk (Default)).
 *      - 8: TON_LS_T1ON_LS_CONST_8 (9 * 2/fclk).
 *      - 9: TON_LS_T1ON_LS_CONST_9 (10 * 2/fclk).
 *      - 10: TON_LS_T1ON_LS_CONST_10 (11 * 2/fclk).
 *      - 11: TON_LS_T1ON_LS_CONST_11 (12 * 2/fclk).
 *      - 12: TON_LS_T1ON_LS_CONST_12 (13 * 2/fclk).
 *      - 13: TON_LS_T1ON_LS_CONST_13 (14 * 2/fclk).
 *      - 14: TON_LS_T1ON_LS_CONST_14 (15 * 2/fclk).
 *      - 15: TON_LS_T1ON_LS_CONST_15 (16 * 2/fclk).
 *      - 16: TON_LS_T1ON_LS_CONST_16 (17 * 2/fclk).
 *      - 17: TON_LS_T1ON_LS_CONST_17 (18 * 2/fclk).
 *      - 18: TON_LS_T1ON_LS_CONST_18 (19 * 2/fclk).
 *      - 19: TON_LS_T1ON_LS_CONST_19 (20 * 2/fclk).
 *      - 20: TON_LS_T1ON_LS_CONST_20 (21 * 2/fclk).
 *      - 21: TON_LS_T1ON_LS_CONST_21 (22 * 2/fclk).
 *      - 22: TON_LS_T1ON_LS_CONST_22 (23 * 2/fclk).
 *      - 23: TON_LS_T1ON_LS_CONST_23 (24 * 2/fclk ).
 *      - 24: TON_LS_T1ON_LS_CONST_24 (25 * 2/fclk).
 *      - 25: TON_LS_T1ON_LS_CONST_25 (26 * 2/fclk ).
 *      - 26: TON_LS_T1ON_LS_CONST_26 (27 * 2/fclk).
 *      - 27: TON_LS_T1ON_LS_CONST_27 (28 * 2/fclk).
 *      - 28: TON_LS_T1ON_LS_CONST_28 (29 * 2/fclk).
 *      - 29: TON_LS_T1ON_LS_CONST_29 (30 * 2/fclk).
 *      - 30: TON_LS_T1ON_LS_CONST_30 (31 * 2/fclk).
 *      - 31: TON_LS_T1ON_LS_CONST_31 (32 * 2/fclk).
 *      - 32: TON_LS_T1ON_LS_CONST_32 (33 * 2/fclk).
 *      - 33: TON_LS_T1ON_LS_CONST_33 (34 * 2/fclk).
 *      - 34: TON_LS_T1ON_LS_CONST_34 (35 * 2/fclk).
 *      - 35: TON_LS_T1ON_LS_CONST_35 (36 * 2/fclk).
 *      - 36: TON_LS_T1ON_LS_CONST_36 (37 * 2/fclk).
 *      - 37: TON_LS_T1ON_LS_CONST_37 (38 * 2/fclk).
 *      - 38: TON_LS_T1ON_LS_CONST_38 (39 * 2/fclk).
 *      - 39: TON_LS_T1ON_LS_CONST_39 (40 * 2/fclk).
 *      - 40: TON_LS_T1ON_LS_CONST_40 (41 * 2/fclk).
 *      - 41: TON_LS_T1ON_LS_CONST_41 (42 * 2/fclk).
 *      - 42: TON_LS_T1ON_LS_CONST_42 (43 * 2/fclk).
 *      - 43: TON_LS_T1ON_LS_CONST_43 (44 * 2/fclk).
 *      - 44: TON_LS_T1ON_LS_CONST_44 (45 * 2/fclk).
 *      - 45: TON_LS_T1ON_LS_CONST_45 (46 * 2/fclk).
 *      - 46: TON_LS_T1ON_LS_CONST_46 (47 * 2/fclk).
 *      - 47: TON_LS_T1ON_LS_CONST_47 (48 * 2/fclk).
 *      - 48: TON_LS_T1ON_LS_CONST_48 (49 * 2/fclk).
 *      - 49: TON_LS_T1ON_LS_CONST_49 (50 * 2/fclk).
 *      - 50: TON_LS_T1ON_LS_CONST_50 (51 * 2/fclk).
 *      - 51: TON_LS_T1ON_LS_CONST_51 (52 * 2/fclk).
 *      - 52: TON_LS_T1ON_LS_CONST_52 (53 * 2/fclk).
 *      - 53: TON_LS_T1ON_LS_CONST_53 (54 * 2/fclk).
 *      - 54: TON_LS_T1ON_LS_CONST_54 (55 * 2/fclk).
 *      - 55: TON_LS_T1ON_LS_CONST_55 (56 * 2/fclk).
 *      - 56: TON_LS_T1ON_LS_CONST_56 (57 * 2/fclk).
 *      - 57: TON_LS_T1ON_LS_CONST_57 (58 * 2/fclk).
 *      - 58: TON_LS_T1ON_LS_CONST_58 (59 * 2/fclk).
 *      - 59: TON_LS_T1ON_LS_CONST_59 (60 * 2/fclk).
 *      - 60: TON_LS_T1ON_LS_CONST_60 (61 * 2/fclk).
 *      - 61: TON_LS_T1ON_LS_CONST_61 (62 * 2/fclk).
 *      - 62: TON_LS_T1ON_LS_CONST_62 (63 * 2/fclk).
 *      - 63: TON_LS_T1ON_LS_CONST_63 (64 * 2/fclk).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_TON_LS_T1ON_LS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->TON_LS.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_TON_LS_T1ON_LS_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_TON_LS_T1ON_LS_POS) &
           (uint16)TLE9186_TON_LS_T1ON_LS_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_TON_LS;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for TON_LS_T1ON_LS.
 *
 * This function returns the value of the bitfield Low Side gate driver
 * pre-charge time configuration within register TON_LS.
 *
 * @return Value of the bitfield TON_LS_T1ON_LS:
 *      - 0: TON_LS_T1ON_LS_CONST_0 (1 * 2/fclk).
 *      - 1: TON_LS_T1ON_LS_CONST_1 (2 * 2/fclk).
 *      - 2: TON_LS_T1ON_LS_CONST_2 (3 * 2/fclk).
 *      - 3: TON_LS_T1ON_LS_CONST_3 (4 * 2/fclk).
 *      - 4: TON_LS_T1ON_LS_CONST_4 (5 * 2/fclk).
 *      - 5: TON_LS_T1ON_LS_CONST_5 (6 * 2/fclk).
 *      - 6: TON_LS_T1ON_LS_CONST_6 (7 * 2/fclk).
 *      - 7: TON_LS_T1ON_LS_CONST_7 (8 * 2/fclk (Default)).
 *      - 8: TON_LS_T1ON_LS_CONST_8 (9 * 2/fclk).
 *      - 9: TON_LS_T1ON_LS_CONST_9 (10 * 2/fclk).
 *      - 10: TON_LS_T1ON_LS_CONST_10 (11 * 2/fclk).
 *      - 11: TON_LS_T1ON_LS_CONST_11 (12 * 2/fclk).
 *      - 12: TON_LS_T1ON_LS_CONST_12 (13 * 2/fclk).
 *      - 13: TON_LS_T1ON_LS_CONST_13 (14 * 2/fclk).
 *      - 14: TON_LS_T1ON_LS_CONST_14 (15 * 2/fclk).
 *      - 15: TON_LS_T1ON_LS_CONST_15 (16 * 2/fclk).
 *      - 16: TON_LS_T1ON_LS_CONST_16 (17 * 2/fclk).
 *      - 17: TON_LS_T1ON_LS_CONST_17 (18 * 2/fclk).
 *      - 18: TON_LS_T1ON_LS_CONST_18 (19 * 2/fclk).
 *      - 19: TON_LS_T1ON_LS_CONST_19 (20 * 2/fclk).
 *      - 20: TON_LS_T1ON_LS_CONST_20 (21 * 2/fclk).
 *      - 21: TON_LS_T1ON_LS_CONST_21 (22 * 2/fclk).
 *      - 22: TON_LS_T1ON_LS_CONST_22 (23 * 2/fclk).
 *      - 23: TON_LS_T1ON_LS_CONST_23 (24 * 2/fclk ).
 *      - 24: TON_LS_T1ON_LS_CONST_24 (25 * 2/fclk).
 *      - 25: TON_LS_T1ON_LS_CONST_25 (26 * 2/fclk ).
 *      - 26: TON_LS_T1ON_LS_CONST_26 (27 * 2/fclk).
 *      - 27: TON_LS_T1ON_LS_CONST_27 (28 * 2/fclk).
 *      - 28: TON_LS_T1ON_LS_CONST_28 (29 * 2/fclk).
 *      - 29: TON_LS_T1ON_LS_CONST_29 (30 * 2/fclk).
 *      - 30: TON_LS_T1ON_LS_CONST_30 (31 * 2/fclk).
 *      - 31: TON_LS_T1ON_LS_CONST_31 (32 * 2/fclk).
 *      - 32: TON_LS_T1ON_LS_CONST_32 (33 * 2/fclk).
 *      - 33: TON_LS_T1ON_LS_CONST_33 (34 * 2/fclk).
 *      - 34: TON_LS_T1ON_LS_CONST_34 (35 * 2/fclk).
 *      - 35: TON_LS_T1ON_LS_CONST_35 (36 * 2/fclk).
 *      - 36: TON_LS_T1ON_LS_CONST_36 (37 * 2/fclk).
 *      - 37: TON_LS_T1ON_LS_CONST_37 (38 * 2/fclk).
 *      - 38: TON_LS_T1ON_LS_CONST_38 (39 * 2/fclk).
 *      - 39: TON_LS_T1ON_LS_CONST_39 (40 * 2/fclk).
 *      - 40: TON_LS_T1ON_LS_CONST_40 (41 * 2/fclk).
 *      - 41: TON_LS_T1ON_LS_CONST_41 (42 * 2/fclk).
 *      - 42: TON_LS_T1ON_LS_CONST_42 (43 * 2/fclk).
 *      - 43: TON_LS_T1ON_LS_CONST_43 (44 * 2/fclk).
 *      - 44: TON_LS_T1ON_LS_CONST_44 (45 * 2/fclk).
 *      - 45: TON_LS_T1ON_LS_CONST_45 (46 * 2/fclk).
 *      - 46: TON_LS_T1ON_LS_CONST_46 (47 * 2/fclk).
 *      - 47: TON_LS_T1ON_LS_CONST_47 (48 * 2/fclk).
 *      - 48: TON_LS_T1ON_LS_CONST_48 (49 * 2/fclk).
 *      - 49: TON_LS_T1ON_LS_CONST_49 (50 * 2/fclk).
 *      - 50: TON_LS_T1ON_LS_CONST_50 (51 * 2/fclk).
 *      - 51: TON_LS_T1ON_LS_CONST_51 (52 * 2/fclk).
 *      - 52: TON_LS_T1ON_LS_CONST_52 (53 * 2/fclk).
 *      - 53: TON_LS_T1ON_LS_CONST_53 (54 * 2/fclk).
 *      - 54: TON_LS_T1ON_LS_CONST_54 (55 * 2/fclk).
 *      - 55: TON_LS_T1ON_LS_CONST_55 (56 * 2/fclk).
 *      - 56: TON_LS_T1ON_LS_CONST_56 (57 * 2/fclk).
 *      - 57: TON_LS_T1ON_LS_CONST_57 (58 * 2/fclk).
 *      - 58: TON_LS_T1ON_LS_CONST_58 (59 * 2/fclk).
 *      - 59: TON_LS_T1ON_LS_CONST_59 (60 * 2/fclk).
 *      - 60: TON_LS_T1ON_LS_CONST_60 (61 * 2/fclk).
 *      - 61: TON_LS_T1ON_LS_CONST_61 (62 * 2/fclk).
 *      - 62: TON_LS_T1ON_LS_CONST_62 (63 * 2/fclk).
 *      - 63: TON_LS_T1ON_LS_CONST_63 (64 * 2/fclk).
 */
uint16 TLE9186_FuncLayer_get_TON_LS_T1ON_LS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->TON_LS.bit.T1ON_LS;
}

/**
 * @brief get function for register TON_LS.
 *
 * This function reads the register Gate Driver Configuration register - TON_LS
 * .
 *
 */
void TLE9186_FuncLayer_get_TON_LS(void) /* polyspace MISRA2012:5.1 [Justified:
                                           Low] "Given due to register names" */
{
  TLE9186_RegLayer_get_TON_LS();
}

/**
 * @brief Set function for register TOFF_HS.
 *
 * This function sets the Gate Driver Configuration register - TOFF_HS .
 *
 * @param u16_value Value to be written into the register TOFF_HS.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_TOFF_HS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_TOFF_HS;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for TOFF_HS_T2OFF_HS.
 *
 * This function sets the bitfield High Side gate driver discharge time
 * configuration in register TOFF_HS.
 *
 * @param u16_value Value to be written into TOFF_HS_T2OFF_HS. Valid values are:
 *      - 0: TOFF_HS_T2OFF_HS_CONST_0 (1 * 2/fclk).
 *      - 1: TOFF_HS_T2OFF_HS_CONST_1 (2 * 2/fclk).
 *      - 2: TOFF_HS_T2OFF_HS_CONST_2 (3 * 2/fclk).
 *      - 3: TOFF_HS_T2OFF_HS_CONST_3 (4 * 2/fclk).
 *      - 4: TOFF_HS_T2OFF_HS_CONST_4 (5 * 2/fclk).
 *      - 5: TOFF_HS_T2OFF_HS_CONST_5 (6 * 2/fclk).
 *      - 6: TOFF_HS_T2OFF_HS_CONST_6 (7 * 2/fclk).
 *      - 7: TOFF_HS_T2OFF_HS_CONST_7 (8 * 2/fclk).
 *      - 8: TOFF_HS_T2OFF_HS_CONST_8 (9 * 2/fclk).
 *      - 9: TOFF_HS_T2OFF_HS_CONST_9 (10 * 2/fclk).
 *      - 10: TOFF_HS_T2OFF_HS_CONST_10 (11 * 2/fclk).
 *      - 11: TOFF_HS_T2OFF_HS_CONST_11 (12 * 2/fclk).
 *      - 12: TOFF_HS_T2OFF_HS_CONST_12 (13 * 2/fclk).
 *      - 13: TOFF_HS_T2OFF_HS_CONST_13 (14 * 2/fclk).
 *      - 14: TOFF_HS_T2OFF_HS_CONST_14 (15 * 2/fclk).
 *      - 15: TOFF_HS_T2OFF_HS_CONST_15 (16 * 2/fclk).
 *      - 16: TOFF_HS_T2OFF_HS_CONST_16 (17 * 2/fclk).
 *      - 17: TOFF_HS_T2OFF_HS_CONST_17 (18 * 2/fclk).
 *      - 18: TOFF_HS_T2OFF_HS_CONST_18 (19 * 2/fclk).
 *      - 19: TOFF_HS_T2OFF_HS_CONST_19 (20 * 2/fclk).
 *      - 20: TOFF_HS_T2OFF_HS_CONST_20 (21 * 2/fclk).
 *      - 21: TOFF_HS_T2OFF_HS_CONST_21 (22 * 2/fclk).
 *      - 22: TOFF_HS_T2OFF_HS_CONST_22 (23 * 2/fclk).
 *      - 23: TOFF_HS_T2OFF_HS_CONST_23 (24 * 2/fclk (Default)).
 *      - 24: TOFF_HS_T2OFF_HS_CONST_24 (25 * 2/fclk).
 *      - 25: TOFF_HS_T2OFF_HS_CONST_25 (26 * 2/fclk ).
 *      - 26: TOFF_HS_T2OFF_HS_CONST_26 (27 * 2/fclk).
 *      - 27: TOFF_HS_T2OFF_HS_CONST_27 (28 * 2/fclk).
 *      - 28: TOFF_HS_T2OFF_HS_CONST_28 (29 * 2/fclk).
 *      - 29: TOFF_HS_T2OFF_HS_CONST_29 (30 * 2/fclk).
 *      - 30: TOFF_HS_T2OFF_HS_CONST_30 (31 * 2/fclk).
 *      - 31: TOFF_HS_T2OFF_HS_CONST_31 (32 * 2/fclk).
 *      - 32: TOFF_HS_T2OFF_HS_CONST_32 (33 * 2/fclk).
 *      - 33: TOFF_HS_T2OFF_HS_CONST_33 (34 * 2/fclk).
 *      - 34: TOFF_HS_T2OFF_HS_CONST_34 (35 * 2/fclk).
 *      - 35: TOFF_HS_T2OFF_HS_CONST_35 (36 * 2/fclk).
 *      - 36: TOFF_HS_T2OFF_HS_CONST_36 (37 * 2/fclk).
 *      - 37: TOFF_HS_T2OFF_HS_CONST_37 (38 * 2/fclk).
 *      - 38: TOFF_HS_T2OFF_HS_CONST_38 (39 * 2/fclk).
 *      - 39: TOFF_HS_T2OFF_HS_CONST_39 (40 * 2/fclk).
 *      - 40: TOFF_HS_T2OFF_HS_CONST_40 (41 * 2/fclk).
 *      - 41: TOFF_HS_T2OFF_HS_CONST_41 (42 * 2/fclk).
 *      - 42: TOFF_HS_T2OFF_HS_CONST_42 (43 * 2/fclk).
 *      - 43: TOFF_HS_T2OFF_HS_CONST_43 (44 * 2/fclk).
 *      - 44: TOFF_HS_T2OFF_HS_CONST_44 (45 * 2/fclk).
 *      - 45: TOFF_HS_T2OFF_HS_CONST_45 (46 * 2/fclk).
 *      - 46: TOFF_HS_T2OFF_HS_CONST_46 (47 * 2/fclk).
 *      - 47: TOFF_HS_T2OFF_HS_CONST_47 (48 * 2/fclk).
 *      - 48: TOFF_HS_T2OFF_HS_CONST_48 (49 * 2/fclk).
 *      - 49: TOFF_HS_T2OFF_HS_CONST_49 (50 * 2/fclk).
 *      - 50: TOFF_HS_T2OFF_HS_CONST_50 (51 * 2/fclk).
 *      - 51: TOFF_HS_T2OFF_HS_CONST_51 (52 * 2/fclk).
 *      - 52: TOFF_HS_T2OFF_HS_CONST_52 (53 * 2/fclk).
 *      - 53: TOFF_HS_T2OFF_HS_CONST_53 (54 * 2/fclk).
 *      - 54: TOFF_HS_T2OFF_HS_CONST_54 (55 * 2/fclk).
 *      - 55: TOFF_HS_T2OFF_HS_CONST_55 (56 * 2/fclk).
 *      - 56: TOFF_HS_T2OFF_HS_CONST_56 (57 * 2/fclk).
 *      - 57: TOFF_HS_T2OFF_HS_CONST_57 (58 * 2/fclk).
 *      - 58: TOFF_HS_T2OFF_HS_CONST_58 (59 * 2/fclk).
 *      - 59: TOFF_HS_T2OFF_HS_CONST_59 (60 * 2/fclk).
 *      - 60: TOFF_HS_T2OFF_HS_CONST_60 (61 * 2/fclk).
 *      - 61: TOFF_HS_T2OFF_HS_CONST_61 (62 * 2/fclk).
 *      - 62: TOFF_HS_T2OFF_HS_CONST_62 (63 * 2/fclk).
 *      - 63: TOFF_HS_T2OFF_HS_CONST_63 (64 * 2/fclk).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_TOFF_HS_T2OFF_HS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->TOFF_HS.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_TOFF_HS_T2OFF_HS_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_TOFF_HS_T2OFF_HS_POS) &
           (uint16)TLE9186_TOFF_HS_T2OFF_HS_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_TOFF_HS;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for TOFF_HS_T2OFF_HS.
 *
 * This function returns the value of the bitfield High Side gate driver
 * discharge time configuration within register TOFF_HS.
 *
 * @return Value of the bitfield TOFF_HS_T2OFF_HS:
 *      - 0: TOFF_HS_T2OFF_HS_CONST_0 (1 * 2/fclk).
 *      - 1: TOFF_HS_T2OFF_HS_CONST_1 (2 * 2/fclk).
 *      - 2: TOFF_HS_T2OFF_HS_CONST_2 (3 * 2/fclk).
 *      - 3: TOFF_HS_T2OFF_HS_CONST_3 (4 * 2/fclk).
 *      - 4: TOFF_HS_T2OFF_HS_CONST_4 (5 * 2/fclk).
 *      - 5: TOFF_HS_T2OFF_HS_CONST_5 (6 * 2/fclk).
 *      - 6: TOFF_HS_T2OFF_HS_CONST_6 (7 * 2/fclk).
 *      - 7: TOFF_HS_T2OFF_HS_CONST_7 (8 * 2/fclk).
 *      - 8: TOFF_HS_T2OFF_HS_CONST_8 (9 * 2/fclk).
 *      - 9: TOFF_HS_T2OFF_HS_CONST_9 (10 * 2/fclk).
 *      - 10: TOFF_HS_T2OFF_HS_CONST_10 (11 * 2/fclk).
 *      - 11: TOFF_HS_T2OFF_HS_CONST_11 (12 * 2/fclk).
 *      - 12: TOFF_HS_T2OFF_HS_CONST_12 (13 * 2/fclk).
 *      - 13: TOFF_HS_T2OFF_HS_CONST_13 (14 * 2/fclk).
 *      - 14: TOFF_HS_T2OFF_HS_CONST_14 (15 * 2/fclk).
 *      - 15: TOFF_HS_T2OFF_HS_CONST_15 (16 * 2/fclk).
 *      - 16: TOFF_HS_T2OFF_HS_CONST_16 (17 * 2/fclk).
 *      - 17: TOFF_HS_T2OFF_HS_CONST_17 (18 * 2/fclk).
 *      - 18: TOFF_HS_T2OFF_HS_CONST_18 (19 * 2/fclk).
 *      - 19: TOFF_HS_T2OFF_HS_CONST_19 (20 * 2/fclk).
 *      - 20: TOFF_HS_T2OFF_HS_CONST_20 (21 * 2/fclk).
 *      - 21: TOFF_HS_T2OFF_HS_CONST_21 (22 * 2/fclk).
 *      - 22: TOFF_HS_T2OFF_HS_CONST_22 (23 * 2/fclk).
 *      - 23: TOFF_HS_T2OFF_HS_CONST_23 (24 * 2/fclk (Default)).
 *      - 24: TOFF_HS_T2OFF_HS_CONST_24 (25 * 2/fclk).
 *      - 25: TOFF_HS_T2OFF_HS_CONST_25 (26 * 2/fclk ).
 *      - 26: TOFF_HS_T2OFF_HS_CONST_26 (27 * 2/fclk).
 *      - 27: TOFF_HS_T2OFF_HS_CONST_27 (28 * 2/fclk).
 *      - 28: TOFF_HS_T2OFF_HS_CONST_28 (29 * 2/fclk).
 *      - 29: TOFF_HS_T2OFF_HS_CONST_29 (30 * 2/fclk).
 *      - 30: TOFF_HS_T2OFF_HS_CONST_30 (31 * 2/fclk).
 *      - 31: TOFF_HS_T2OFF_HS_CONST_31 (32 * 2/fclk).
 *      - 32: TOFF_HS_T2OFF_HS_CONST_32 (33 * 2/fclk).
 *      - 33: TOFF_HS_T2OFF_HS_CONST_33 (34 * 2/fclk).
 *      - 34: TOFF_HS_T2OFF_HS_CONST_34 (35 * 2/fclk).
 *      - 35: TOFF_HS_T2OFF_HS_CONST_35 (36 * 2/fclk).
 *      - 36: TOFF_HS_T2OFF_HS_CONST_36 (37 * 2/fclk).
 *      - 37: TOFF_HS_T2OFF_HS_CONST_37 (38 * 2/fclk).
 *      - 38: TOFF_HS_T2OFF_HS_CONST_38 (39 * 2/fclk).
 *      - 39: TOFF_HS_T2OFF_HS_CONST_39 (40 * 2/fclk).
 *      - 40: TOFF_HS_T2OFF_HS_CONST_40 (41 * 2/fclk).
 *      - 41: TOFF_HS_T2OFF_HS_CONST_41 (42 * 2/fclk).
 *      - 42: TOFF_HS_T2OFF_HS_CONST_42 (43 * 2/fclk).
 *      - 43: TOFF_HS_T2OFF_HS_CONST_43 (44 * 2/fclk).
 *      - 44: TOFF_HS_T2OFF_HS_CONST_44 (45 * 2/fclk).
 *      - 45: TOFF_HS_T2OFF_HS_CONST_45 (46 * 2/fclk).
 *      - 46: TOFF_HS_T2OFF_HS_CONST_46 (47 * 2/fclk).
 *      - 47: TOFF_HS_T2OFF_HS_CONST_47 (48 * 2/fclk).
 *      - 48: TOFF_HS_T2OFF_HS_CONST_48 (49 * 2/fclk).
 *      - 49: TOFF_HS_T2OFF_HS_CONST_49 (50 * 2/fclk).
 *      - 50: TOFF_HS_T2OFF_HS_CONST_50 (51 * 2/fclk).
 *      - 51: TOFF_HS_T2OFF_HS_CONST_51 (52 * 2/fclk).
 *      - 52: TOFF_HS_T2OFF_HS_CONST_52 (53 * 2/fclk).
 *      - 53: TOFF_HS_T2OFF_HS_CONST_53 (54 * 2/fclk).
 *      - 54: TOFF_HS_T2OFF_HS_CONST_54 (55 * 2/fclk).
 *      - 55: TOFF_HS_T2OFF_HS_CONST_55 (56 * 2/fclk).
 *      - 56: TOFF_HS_T2OFF_HS_CONST_56 (57 * 2/fclk).
 *      - 57: TOFF_HS_T2OFF_HS_CONST_57 (58 * 2/fclk).
 *      - 58: TOFF_HS_T2OFF_HS_CONST_58 (59 * 2/fclk).
 *      - 59: TOFF_HS_T2OFF_HS_CONST_59 (60 * 2/fclk).
 *      - 60: TOFF_HS_T2OFF_HS_CONST_60 (61 * 2/fclk).
 *      - 61: TOFF_HS_T2OFF_HS_CONST_61 (62 * 2/fclk).
 *      - 62: TOFF_HS_T2OFF_HS_CONST_62 (63 * 2/fclk).
 *      - 63: TOFF_HS_T2OFF_HS_CONST_63 (64 * 2/fclk).
 */
uint16 TLE9186_FuncLayer_get_TOFF_HS_T2OFF_HS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->TOFF_HS.bit.T2OFF_HS;
}

/**
 * @brief Set function for TOFF_HS_T1OFF_HS.
 *
 * This function sets the bitfield High Side gate driver pre-discharge time
 * configuration in register TOFF_HS.
 *
 * @param u16_value Value to be written into TOFF_HS_T1OFF_HS. Valid values are:
 *      - 0: TOFF_HS_T1OFF_HS_CONST_0 (1 * 2/fclk).
 *      - 1: TOFF_HS_T1OFF_HS_CONST_1 (2 * 2/fclk).
 *      - 2: TOFF_HS_T1OFF_HS_CONST_2 (3 * 2/fclk).
 *      - 3: TOFF_HS_T1OFF_HS_CONST_3 (4 * 2/fclk).
 *      - 4: TOFF_HS_T1OFF_HS_CONST_4 (5 * 2/fclk).
 *      - 5: TOFF_HS_T1OFF_HS_CONST_5 (6 * 2/fclk).
 *      - 6: TOFF_HS_T1OFF_HS_CONST_6 (7 * 2/fclk).
 *      - 7: TOFF_HS_T1OFF_HS_CONST_7 (8 * 2/fclk (Default)).
 *      - 8: TOFF_HS_T1OFF_HS_CONST_8 (9 * 2/fclk).
 *      - 9: TOFF_HS_T1OFF_HS_CONST_9 (10 * 2/fclk).
 *      - 10: TOFF_HS_T1OFF_HS_CONST_10 (11 * 2/fclk).
 *      - 11: TOFF_HS_T1OFF_HS_CONST_11 (12 * 2/fclk).
 *      - 12: TOFF_HS_T1OFF_HS_CONST_12 (13 * 2/fclk).
 *      - 13: TOFF_HS_T1OFF_HS_CONST_13 (14 * 2/fclk).
 *      - 14: TOFF_HS_T1OFF_HS_CONST_14 (15 * 2/fclk).
 *      - 15: TOFF_HS_T1OFF_HS_CONST_15 (16 * 2/fclk).
 *      - 16: TOFF_HS_T1OFF_HS_CONST_16 (17 * 2/fclk).
 *      - 17: TOFF_HS_T1OFF_HS_CONST_17 (18 * 2/fclk).
 *      - 18: TOFF_HS_T1OFF_HS_CONST_18 (19 * 2/fclk).
 *      - 19: TOFF_HS_T1OFF_HS_CONST_19 (20 * 2/fclk).
 *      - 20: TOFF_HS_T1OFF_HS_CONST_20 (21 * 2/fclk).
 *      - 21: TOFF_HS_T1OFF_HS_CONST_21 (22 * 2/fclk).
 *      - 22: TOFF_HS_T1OFF_HS_CONST_22 (23 * 2/fclk).
 *      - 23: TOFF_HS_T1OFF_HS_CONST_23 (24 * 2/fclk ).
 *      - 24: TOFF_HS_T1OFF_HS_CONST_24 (25 * 2/fclk).
 *      - 25: TOFF_HS_T1OFF_HS_CONST_25 (26 * 2/fclk ).
 *      - 26: TOFF_HS_T1OFF_HS_CONST_26 (27 * 2/fclk).
 *      - 27: TOFF_HS_T1OFF_HS_CONST_27 (28 * 2/fclk).
 *      - 28: TOFF_HS_T1OFF_HS_CONST_28 (29 * 2/fclk).
 *      - 29: TOFF_HS_T1OFF_HS_CONST_29 (30 * 2/fclk).
 *      - 30: TOFF_HS_T1OFF_HS_CONST_30 (31 * 2/fclk).
 *      - 31: TOFF_HS_T1OFF_HS_CONST_31 (32 * 2/fclk).
 *      - 32: TOFF_HS_T1OFF_HS_CONST_32 (33 * 2/fclk).
 *      - 33: TOFF_HS_T1OFF_HS_CONST_33 (34 * 2/fclk).
 *      - 34: TOFF_HS_T1OFF_HS_CONST_34 (35 * 2/fclk).
 *      - 35: TOFF_HS_T1OFF_HS_CONST_35 (36 * 2/fclk).
 *      - 36: TOFF_HS_T1OFF_HS_CONST_36 (37 * 2/fclk).
 *      - 37: TOFF_HS_T1OFF_HS_CONST_37 (38 * 2/fclk).
 *      - 38: TOFF_HS_T1OFF_HS_CONST_38 (39 * 2/fclk).
 *      - 39: TOFF_HS_T1OFF_HS_CONST_39 (40 * 2/fclk).
 *      - 40: TOFF_HS_T1OFF_HS_CONST_40 (41 * 2/fclk).
 *      - 41: TOFF_HS_T1OFF_HS_CONST_41 (42 * 2/fclk).
 *      - 42: TOFF_HS_T1OFF_HS_CONST_42 (43 * 2/fclk).
 *      - 43: TOFF_HS_T1OFF_HS_CONST_43 (44 * 2/fclk).
 *      - 44: TOFF_HS_T1OFF_HS_CONST_44 (45 * 2/fclk).
 *      - 45: TOFF_HS_T1OFF_HS_CONST_45 (46 * 2/fclk).
 *      - 46: TOFF_HS_T1OFF_HS_CONST_46 (47 * 2/fclk).
 *      - 47: TOFF_HS_T1OFF_HS_CONST_47 (48 * 2/fclk).
 *      - 48: TOFF_HS_T1OFF_HS_CONST_48 (49 * 2/fclk).
 *      - 49: TOFF_HS_T1OFF_HS_CONST_49 (50 * 2/fclk).
 *      - 50: TOFF_HS_T1OFF_HS_CONST_50 (51 * 2/fclk).
 *      - 51: TOFF_HS_T1OFF_HS_CONST_51 (52 * 2/fclk).
 *      - 52: TOFF_HS_T1OFF_HS_CONST_52 (53 * 2/fclk).
 *      - 53: TOFF_HS_T1OFF_HS_CONST_53 (54 * 2/fclk).
 *      - 54: TOFF_HS_T1OFF_HS_CONST_54 (55 * 2/fclk).
 *      - 55: TOFF_HS_T1OFF_HS_CONST_55 (56 * 2/fclk).
 *      - 56: TOFF_HS_T1OFF_HS_CONST_56 (57 * 2/fclk).
 *      - 57: TOFF_HS_T1OFF_HS_CONST_57 (58 * 2/fclk).
 *      - 58: TOFF_HS_T1OFF_HS_CONST_58 (59 * 2/fclk).
 *      - 59: TOFF_HS_T1OFF_HS_CONST_59 (60 * 2/fclk).
 *      - 60: TOFF_HS_T1OFF_HS_CONST_60 (61 * 2/fclk).
 *      - 61: TOFF_HS_T1OFF_HS_CONST_61 (62 * 2/fclk).
 *      - 62: TOFF_HS_T1OFF_HS_CONST_62 (63 * 2/fclk).
 *      - 63: TOFF_HS_T1OFF_HS_CONST_63 (64 * 2/fclk).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_TOFF_HS_T1OFF_HS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->TOFF_HS.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_TOFF_HS_T1OFF_HS_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_TOFF_HS_T1OFF_HS_POS) &
           (uint16)TLE9186_TOFF_HS_T1OFF_HS_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_TOFF_HS;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for TOFF_HS_T1OFF_HS.
 *
 * This function returns the value of the bitfield High Side gate driver
 * pre-discharge time configuration within register TOFF_HS.
 *
 * @return Value of the bitfield TOFF_HS_T1OFF_HS:
 *      - 0: TOFF_HS_T1OFF_HS_CONST_0 (1 * 2/fclk).
 *      - 1: TOFF_HS_T1OFF_HS_CONST_1 (2 * 2/fclk).
 *      - 2: TOFF_HS_T1OFF_HS_CONST_2 (3 * 2/fclk).
 *      - 3: TOFF_HS_T1OFF_HS_CONST_3 (4 * 2/fclk).
 *      - 4: TOFF_HS_T1OFF_HS_CONST_4 (5 * 2/fclk).
 *      - 5: TOFF_HS_T1OFF_HS_CONST_5 (6 * 2/fclk).
 *      - 6: TOFF_HS_T1OFF_HS_CONST_6 (7 * 2/fclk).
 *      - 7: TOFF_HS_T1OFF_HS_CONST_7 (8 * 2/fclk (Default)).
 *      - 8: TOFF_HS_T1OFF_HS_CONST_8 (9 * 2/fclk).
 *      - 9: TOFF_HS_T1OFF_HS_CONST_9 (10 * 2/fclk).
 *      - 10: TOFF_HS_T1OFF_HS_CONST_10 (11 * 2/fclk).
 *      - 11: TOFF_HS_T1OFF_HS_CONST_11 (12 * 2/fclk).
 *      - 12: TOFF_HS_T1OFF_HS_CONST_12 (13 * 2/fclk).
 *      - 13: TOFF_HS_T1OFF_HS_CONST_13 (14 * 2/fclk).
 *      - 14: TOFF_HS_T1OFF_HS_CONST_14 (15 * 2/fclk).
 *      - 15: TOFF_HS_T1OFF_HS_CONST_15 (16 * 2/fclk).
 *      - 16: TOFF_HS_T1OFF_HS_CONST_16 (17 * 2/fclk).
 *      - 17: TOFF_HS_T1OFF_HS_CONST_17 (18 * 2/fclk).
 *      - 18: TOFF_HS_T1OFF_HS_CONST_18 (19 * 2/fclk).
 *      - 19: TOFF_HS_T1OFF_HS_CONST_19 (20 * 2/fclk).
 *      - 20: TOFF_HS_T1OFF_HS_CONST_20 (21 * 2/fclk).
 *      - 21: TOFF_HS_T1OFF_HS_CONST_21 (22 * 2/fclk).
 *      - 22: TOFF_HS_T1OFF_HS_CONST_22 (23 * 2/fclk).
 *      - 23: TOFF_HS_T1OFF_HS_CONST_23 (24 * 2/fclk ).
 *      - 24: TOFF_HS_T1OFF_HS_CONST_24 (25 * 2/fclk).
 *      - 25: TOFF_HS_T1OFF_HS_CONST_25 (26 * 2/fclk ).
 *      - 26: TOFF_HS_T1OFF_HS_CONST_26 (27 * 2/fclk).
 *      - 27: TOFF_HS_T1OFF_HS_CONST_27 (28 * 2/fclk).
 *      - 28: TOFF_HS_T1OFF_HS_CONST_28 (29 * 2/fclk).
 *      - 29: TOFF_HS_T1OFF_HS_CONST_29 (30 * 2/fclk).
 *      - 30: TOFF_HS_T1OFF_HS_CONST_30 (31 * 2/fclk).
 *      - 31: TOFF_HS_T1OFF_HS_CONST_31 (32 * 2/fclk).
 *      - 32: TOFF_HS_T1OFF_HS_CONST_32 (33 * 2/fclk).
 *      - 33: TOFF_HS_T1OFF_HS_CONST_33 (34 * 2/fclk).
 *      - 34: TOFF_HS_T1OFF_HS_CONST_34 (35 * 2/fclk).
 *      - 35: TOFF_HS_T1OFF_HS_CONST_35 (36 * 2/fclk).
 *      - 36: TOFF_HS_T1OFF_HS_CONST_36 (37 * 2/fclk).
 *      - 37: TOFF_HS_T1OFF_HS_CONST_37 (38 * 2/fclk).
 *      - 38: TOFF_HS_T1OFF_HS_CONST_38 (39 * 2/fclk).
 *      - 39: TOFF_HS_T1OFF_HS_CONST_39 (40 * 2/fclk).
 *      - 40: TOFF_HS_T1OFF_HS_CONST_40 (41 * 2/fclk).
 *      - 41: TOFF_HS_T1OFF_HS_CONST_41 (42 * 2/fclk).
 *      - 42: TOFF_HS_T1OFF_HS_CONST_42 (43 * 2/fclk).
 *      - 43: TOFF_HS_T1OFF_HS_CONST_43 (44 * 2/fclk).
 *      - 44: TOFF_HS_T1OFF_HS_CONST_44 (45 * 2/fclk).
 *      - 45: TOFF_HS_T1OFF_HS_CONST_45 (46 * 2/fclk).
 *      - 46: TOFF_HS_T1OFF_HS_CONST_46 (47 * 2/fclk).
 *      - 47: TOFF_HS_T1OFF_HS_CONST_47 (48 * 2/fclk).
 *      - 48: TOFF_HS_T1OFF_HS_CONST_48 (49 * 2/fclk).
 *      - 49: TOFF_HS_T1OFF_HS_CONST_49 (50 * 2/fclk).
 *      - 50: TOFF_HS_T1OFF_HS_CONST_50 (51 * 2/fclk).
 *      - 51: TOFF_HS_T1OFF_HS_CONST_51 (52 * 2/fclk).
 *      - 52: TOFF_HS_T1OFF_HS_CONST_52 (53 * 2/fclk).
 *      - 53: TOFF_HS_T1OFF_HS_CONST_53 (54 * 2/fclk).
 *      - 54: TOFF_HS_T1OFF_HS_CONST_54 (55 * 2/fclk).
 *      - 55: TOFF_HS_T1OFF_HS_CONST_55 (56 * 2/fclk).
 *      - 56: TOFF_HS_T1OFF_HS_CONST_56 (57 * 2/fclk).
 *      - 57: TOFF_HS_T1OFF_HS_CONST_57 (58 * 2/fclk).
 *      - 58: TOFF_HS_T1OFF_HS_CONST_58 (59 * 2/fclk).
 *      - 59: TOFF_HS_T1OFF_HS_CONST_59 (60 * 2/fclk).
 *      - 60: TOFF_HS_T1OFF_HS_CONST_60 (61 * 2/fclk).
 *      - 61: TOFF_HS_T1OFF_HS_CONST_61 (62 * 2/fclk).
 *      - 62: TOFF_HS_T1OFF_HS_CONST_62 (63 * 2/fclk).
 *      - 63: TOFF_HS_T1OFF_HS_CONST_63 (64 * 2/fclk).
 */
uint16 TLE9186_FuncLayer_get_TOFF_HS_T1OFF_HS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->TOFF_HS.bit.T1OFF_HS;
}

/**
 * @brief get function for register TOFF_HS.
 *
 * This function reads the register Gate Driver Configuration register - TOFF_HS
 * .
 *
 */
void TLE9186_FuncLayer_get_TOFF_HS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_TOFF_HS();
}

/**
 * @brief Set function for register TOFF_LS.
 *
 * This function sets the Gate Driver Configuration register - TOFF_LS .
 *
 * @param u16_value Value to be written into the register TOFF_LS.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_TOFF_LS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_TOFF_LS;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for TOFF_LS_T2OFF_LS.
 *
 * This function sets the bitfield Low Side gate driver discharge time
 * configuration in register TOFF_LS.
 *
 * @param u16_value Value to be written into TOFF_LS_T2OFF_LS. Valid values are:
 *      - 0: TOFF_LS_T2OFF_LS_CONST_0 (1 * 2/fclk).
 *      - 1: TOFF_LS_T2OFF_LS_CONST_1 (2 * 2/fclk).
 *      - 2: TOFF_LS_T2OFF_LS_CONST_2 (3 * 2/fclk).
 *      - 3: TOFF_LS_T2OFF_LS_CONST_3 (4 * 2/fclk).
 *      - 4: TOFF_LS_T2OFF_LS_CONST_4 (5 * 2/fclk).
 *      - 5: TOFF_LS_T2OFF_LS_CONST_5 (6 * 2/fclk).
 *      - 6: TOFF_LS_T2OFF_LS_CONST_6 (7 * 2/fclk).
 *      - 7: TOFF_LS_T2OFF_LS_CONST_7 (8 * 2/fclk).
 *      - 8: TOFF_LS_T2OFF_LS_CONST_8 (9 * 2/fclk).
 *      - 9: TOFF_LS_T2OFF_LS_CONST_9 (10 * 2/fclk).
 *      - 10: TOFF_LS_T2OFF_LS_CONST_10 (11 * 2/fclk).
 *      - 11: TOFF_LS_T2OFF_LS_CONST_11 (12 * 2/fclk).
 *      - 12: TOFF_LS_T2OFF_LS_CONST_12 (13 * 2/fclk).
 *      - 13: TOFF_LS_T2OFF_LS_CONST_13 (14 * 2/fclk).
 *      - 14: TOFF_LS_T2OFF_LS_CONST_14 (15 * 2/fclk).
 *      - 15: TOFF_LS_T2OFF_LS_CONST_15 (16 * 2/fclk).
 *      - 16: TOFF_LS_T2OFF_LS_CONST_16 (17 * 2/fclk).
 *      - 17: TOFF_LS_T2OFF_LS_CONST_17 (18 * 2/fclk).
 *      - 18: TOFF_LS_T2OFF_LS_CONST_18 (19 * 2/fclk).
 *      - 19: TOFF_LS_T2OFF_LS_CONST_19 (20 * 2/fclk).
 *      - 20: TOFF_LS_T2OFF_LS_CONST_20 (21 * 2/fclk).
 *      - 21: TOFF_LS_T2OFF_LS_CONST_21 (22 * 2/fclk).
 *      - 22: TOFF_LS_T2OFF_LS_CONST_22 (23 * 2/fclk).
 *      - 23: TOFF_LS_T2OFF_LS_CONST_23 (24 * 2/fclk (Default)).
 *      - 24: TOFF_LS_T2OFF_LS_CONST_24 (25 * 2/fclk).
 *      - 25: TOFF_LS_T2OFF_LS_CONST_25 (26 * 2/fclk ).
 *      - 26: TOFF_LS_T2OFF_LS_CONST_26 (27 * 2/fclk).
 *      - 27: TOFF_LS_T2OFF_LS_CONST_27 (28 * 2/fclk).
 *      - 28: TOFF_LS_T2OFF_LS_CONST_28 (29 * 2/fclk).
 *      - 29: TOFF_LS_T2OFF_LS_CONST_29 (30 * 2/fclk).
 *      - 30: TOFF_LS_T2OFF_LS_CONST_30 (31 * 2/fclk).
 *      - 31: TOFF_LS_T2OFF_LS_CONST_31 (32 * 2/fclk).
 *      - 32: TOFF_LS_T2OFF_LS_CONST_32 (33 * 2/fclk).
 *      - 33: TOFF_LS_T2OFF_LS_CONST_33 (34 * 2/fclk).
 *      - 34: TOFF_LS_T2OFF_LS_CONST_34 (35 * 2/fclk).
 *      - 35: TOFF_LS_T2OFF_LS_CONST_35 (36 * 2/fclk).
 *      - 36: TOFF_LS_T2OFF_LS_CONST_36 (37 * 2/fclk).
 *      - 37: TOFF_LS_T2OFF_LS_CONST_37 (38 * 2/fclk).
 *      - 38: TOFF_LS_T2OFF_LS_CONST_38 (39 * 2/fclk).
 *      - 39: TOFF_LS_T2OFF_LS_CONST_39 (40 * 2/fclk).
 *      - 40: TOFF_LS_T2OFF_LS_CONST_40 (41 * 2/fclk).
 *      - 41: TOFF_LS_T2OFF_LS_CONST_41 (42 * 2/fclk).
 *      - 42: TOFF_LS_T2OFF_LS_CONST_42 (43 * 2/fclk).
 *      - 43: TOFF_LS_T2OFF_LS_CONST_43 (44 * 2/fclk).
 *      - 44: TOFF_LS_T2OFF_LS_CONST_44 (45 * 2/fclk).
 *      - 45: TOFF_LS_T2OFF_LS_CONST_45 (46 * 2/fclk).
 *      - 46: TOFF_LS_T2OFF_LS_CONST_46 (47 * 2/fclk).
 *      - 47: TOFF_LS_T2OFF_LS_CONST_47 (48 * 2/fclk).
 *      - 48: TOFF_LS_T2OFF_LS_CONST_48 (49 * 2/fclk).
 *      - 49: TOFF_LS_T2OFF_LS_CONST_49 (50 * 2/fclk).
 *      - 50: TOFF_LS_T2OFF_LS_CONST_50 (51 * 2/fclk).
 *      - 51: TOFF_LS_T2OFF_LS_CONST_51 (52 * 2/fclk).
 *      - 52: TOFF_LS_T2OFF_LS_CONST_52 (53 * 2/fclk).
 *      - 53: TOFF_LS_T2OFF_LS_CONST_53 (54 * 2/fclk).
 *      - 54: TOFF_LS_T2OFF_LS_CONST_54 (55 * 2/fclk).
 *      - 55: TOFF_LS_T2OFF_LS_CONST_55 (56 * 2/fclk).
 *      - 56: TOFF_LS_T2OFF_LS_CONST_56 (57 * 2/fclk).
 *      - 57: TOFF_LS_T2OFF_LS_CONST_57 (58 * 2/fclk).
 *      - 58: TOFF_LS_T2OFF_LS_CONST_58 (59 * 2/fclk).
 *      - 59: TOFF_LS_T2OFF_LS_CONST_59 (60 * 2/fclk).
 *      - 60: TOFF_LS_T2OFF_LS_CONST_60 (61 * 2/fclk).
 *      - 61: TOFF_LS_T2OFF_LS_CONST_61 (62 * 2/fclk).
 *      - 62: TOFF_LS_T2OFF_LS_CONST_62 (63 * 2/fclk).
 *      - 63: TOFF_LS_T2OFF_LS_CONST_63 (64 * 2/fclk).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_TOFF_LS_T2OFF_LS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->TOFF_LS.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_TOFF_LS_T2OFF_LS_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_TOFF_LS_T2OFF_LS_POS) &
           (uint16)TLE9186_TOFF_LS_T2OFF_LS_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_TOFF_LS;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for TOFF_LS_T2OFF_LS.
 *
 * This function returns the value of the bitfield Low Side gate driver
 * discharge time configuration within register TOFF_LS.
 *
 * @return Value of the bitfield TOFF_LS_T2OFF_LS:
 *      - 0: TOFF_LS_T2OFF_LS_CONST_0 (1 * 2/fclk).
 *      - 1: TOFF_LS_T2OFF_LS_CONST_1 (2 * 2/fclk).
 *      - 2: TOFF_LS_T2OFF_LS_CONST_2 (3 * 2/fclk).
 *      - 3: TOFF_LS_T2OFF_LS_CONST_3 (4 * 2/fclk).
 *      - 4: TOFF_LS_T2OFF_LS_CONST_4 (5 * 2/fclk).
 *      - 5: TOFF_LS_T2OFF_LS_CONST_5 (6 * 2/fclk).
 *      - 6: TOFF_LS_T2OFF_LS_CONST_6 (7 * 2/fclk).
 *      - 7: TOFF_LS_T2OFF_LS_CONST_7 (8 * 2/fclk).
 *      - 8: TOFF_LS_T2OFF_LS_CONST_8 (9 * 2/fclk).
 *      - 9: TOFF_LS_T2OFF_LS_CONST_9 (10 * 2/fclk).
 *      - 10: TOFF_LS_T2OFF_LS_CONST_10 (11 * 2/fclk).
 *      - 11: TOFF_LS_T2OFF_LS_CONST_11 (12 * 2/fclk).
 *      - 12: TOFF_LS_T2OFF_LS_CONST_12 (13 * 2/fclk).
 *      - 13: TOFF_LS_T2OFF_LS_CONST_13 (14 * 2/fclk).
 *      - 14: TOFF_LS_T2OFF_LS_CONST_14 (15 * 2/fclk).
 *      - 15: TOFF_LS_T2OFF_LS_CONST_15 (16 * 2/fclk).
 *      - 16: TOFF_LS_T2OFF_LS_CONST_16 (17 * 2/fclk).
 *      - 17: TOFF_LS_T2OFF_LS_CONST_17 (18 * 2/fclk).
 *      - 18: TOFF_LS_T2OFF_LS_CONST_18 (19 * 2/fclk).
 *      - 19: TOFF_LS_T2OFF_LS_CONST_19 (20 * 2/fclk).
 *      - 20: TOFF_LS_T2OFF_LS_CONST_20 (21 * 2/fclk).
 *      - 21: TOFF_LS_T2OFF_LS_CONST_21 (22 * 2/fclk).
 *      - 22: TOFF_LS_T2OFF_LS_CONST_22 (23 * 2/fclk).
 *      - 23: TOFF_LS_T2OFF_LS_CONST_23 (24 * 2/fclk (Default)).
 *      - 24: TOFF_LS_T2OFF_LS_CONST_24 (25 * 2/fclk).
 *      - 25: TOFF_LS_T2OFF_LS_CONST_25 (26 * 2/fclk ).
 *      - 26: TOFF_LS_T2OFF_LS_CONST_26 (27 * 2/fclk).
 *      - 27: TOFF_LS_T2OFF_LS_CONST_27 (28 * 2/fclk).
 *      - 28: TOFF_LS_T2OFF_LS_CONST_28 (29 * 2/fclk).
 *      - 29: TOFF_LS_T2OFF_LS_CONST_29 (30 * 2/fclk).
 *      - 30: TOFF_LS_T2OFF_LS_CONST_30 (31 * 2/fclk).
 *      - 31: TOFF_LS_T2OFF_LS_CONST_31 (32 * 2/fclk).
 *      - 32: TOFF_LS_T2OFF_LS_CONST_32 (33 * 2/fclk).
 *      - 33: TOFF_LS_T2OFF_LS_CONST_33 (34 * 2/fclk).
 *      - 34: TOFF_LS_T2OFF_LS_CONST_34 (35 * 2/fclk).
 *      - 35: TOFF_LS_T2OFF_LS_CONST_35 (36 * 2/fclk).
 *      - 36: TOFF_LS_T2OFF_LS_CONST_36 (37 * 2/fclk).
 *      - 37: TOFF_LS_T2OFF_LS_CONST_37 (38 * 2/fclk).
 *      - 38: TOFF_LS_T2OFF_LS_CONST_38 (39 * 2/fclk).
 *      - 39: TOFF_LS_T2OFF_LS_CONST_39 (40 * 2/fclk).
 *      - 40: TOFF_LS_T2OFF_LS_CONST_40 (41 * 2/fclk).
 *      - 41: TOFF_LS_T2OFF_LS_CONST_41 (42 * 2/fclk).
 *      - 42: TOFF_LS_T2OFF_LS_CONST_42 (43 * 2/fclk).
 *      - 43: TOFF_LS_T2OFF_LS_CONST_43 (44 * 2/fclk).
 *      - 44: TOFF_LS_T2OFF_LS_CONST_44 (45 * 2/fclk).
 *      - 45: TOFF_LS_T2OFF_LS_CONST_45 (46 * 2/fclk).
 *      - 46: TOFF_LS_T2OFF_LS_CONST_46 (47 * 2/fclk).
 *      - 47: TOFF_LS_T2OFF_LS_CONST_47 (48 * 2/fclk).
 *      - 48: TOFF_LS_T2OFF_LS_CONST_48 (49 * 2/fclk).
 *      - 49: TOFF_LS_T2OFF_LS_CONST_49 (50 * 2/fclk).
 *      - 50: TOFF_LS_T2OFF_LS_CONST_50 (51 * 2/fclk).
 *      - 51: TOFF_LS_T2OFF_LS_CONST_51 (52 * 2/fclk).
 *      - 52: TOFF_LS_T2OFF_LS_CONST_52 (53 * 2/fclk).
 *      - 53: TOFF_LS_T2OFF_LS_CONST_53 (54 * 2/fclk).
 *      - 54: TOFF_LS_T2OFF_LS_CONST_54 (55 * 2/fclk).
 *      - 55: TOFF_LS_T2OFF_LS_CONST_55 (56 * 2/fclk).
 *      - 56: TOFF_LS_T2OFF_LS_CONST_56 (57 * 2/fclk).
 *      - 57: TOFF_LS_T2OFF_LS_CONST_57 (58 * 2/fclk).
 *      - 58: TOFF_LS_T2OFF_LS_CONST_58 (59 * 2/fclk).
 *      - 59: TOFF_LS_T2OFF_LS_CONST_59 (60 * 2/fclk).
 *      - 60: TOFF_LS_T2OFF_LS_CONST_60 (61 * 2/fclk).
 *      - 61: TOFF_LS_T2OFF_LS_CONST_61 (62 * 2/fclk).
 *      - 62: TOFF_LS_T2OFF_LS_CONST_62 (63 * 2/fclk).
 *      - 63: TOFF_LS_T2OFF_LS_CONST_63 (64 * 2/fclk).
 */
uint16 TLE9186_FuncLayer_get_TOFF_LS_T2OFF_LS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->TOFF_LS.bit.T2OFF_LS;
}

/**
 * @brief Set function for TOFF_LS_T1OFF_LS.
 *
 * This function sets the bitfield Low Side gate driver pre-discharge time
 * configuration in register TOFF_LS.
 *
 * @param u16_value Value to be written into TOFF_LS_T1OFF_LS. Valid values are:
 *      - 0: TOFF_LS_T1OFF_LS_CONST_0 (1 * 2/fclk).
 *      - 1: TOFF_LS_T1OFF_LS_CONST_1 (2 * 2/fclk).
 *      - 2: TOFF_LS_T1OFF_LS_CONST_2 (3 * 2/fclk).
 *      - 3: TOFF_LS_T1OFF_LS_CONST_3 (4 * 2/fclk).
 *      - 4: TOFF_LS_T1OFF_LS_CONST_4 (5 * 2/fclk).
 *      - 5: TOFF_LS_T1OFF_LS_CONST_5 (6 * 2/fclk).
 *      - 6: TOFF_LS_T1OFF_LS_CONST_6 (7 * 2/fclk).
 *      - 7: TOFF_LS_T1OFF_LS_CONST_7 (8 * 2/fclk (Default)).
 *      - 8: TOFF_LS_T1OFF_LS_CONST_8 (9 * 2/fclk).
 *      - 9: TOFF_LS_T1OFF_LS_CONST_9 (10 * 2/fclk).
 *      - 10: TOFF_LS_T1OFF_LS_CONST_10 (11 * 2/fclk).
 *      - 11: TOFF_LS_T1OFF_LS_CONST_11 (12 * 2/fclk).
 *      - 12: TOFF_LS_T1OFF_LS_CONST_12 (13 * 2/fclk).
 *      - 13: TOFF_LS_T1OFF_LS_CONST_13 (14 * 2/fclk).
 *      - 14: TOFF_LS_T1OFF_LS_CONST_14 (15 * 2/fclk).
 *      - 15: TOFF_LS_T1OFF_LS_CONST_15 (16 * 2/fclk).
 *      - 16: TOFF_LS_T1OFF_LS_CONST_16 (17 * 2/fclk).
 *      - 17: TOFF_LS_T1OFF_LS_CONST_17 (18 * 2/fclk).
 *      - 18: TOFF_LS_T1OFF_LS_CONST_18 (19 * 2/fclk).
 *      - 19: TOFF_LS_T1OFF_LS_CONST_19 (20 * 2/fclk).
 *      - 20: TOFF_LS_T1OFF_LS_CONST_20 (21 * 2/fclk).
 *      - 21: TOFF_LS_T1OFF_LS_CONST_21 (22 * 2/fclk).
 *      - 22: TOFF_LS_T1OFF_LS_CONST_22 (23 * 2/fclk).
 *      - 23: TOFF_LS_T1OFF_LS_CONST_23 (24 * 2/fclk ).
 *      - 24: TOFF_LS_T1OFF_LS_CONST_24 (25 * 2/fclk).
 *      - 25: TOFF_LS_T1OFF_LS_CONST_25 (26 * 2/fclk ).
 *      - 26: TOFF_LS_T1OFF_LS_CONST_26 (27 * 2/fclk).
 *      - 27: TOFF_LS_T1OFF_LS_CONST_27 (28 * 2/fclk).
 *      - 28: TOFF_LS_T1OFF_LS_CONST_28 (29 * 2/fclk).
 *      - 29: TOFF_LS_T1OFF_LS_CONST_29 (30 * 2/fclk).
 *      - 30: TOFF_LS_T1OFF_LS_CONST_30 (31 * 2/fclk).
 *      - 31: TOFF_LS_T1OFF_LS_CONST_31 (32 * 2/fclk).
 *      - 32: TOFF_LS_T1OFF_LS_CONST_32 (33 * 2/fclk).
 *      - 33: TOFF_LS_T1OFF_LS_CONST_33 (34 * 2/fclk).
 *      - 34: TOFF_LS_T1OFF_LS_CONST_34 (35 * 2/fclk).
 *      - 35: TOFF_LS_T1OFF_LS_CONST_35 (36 * 2/fclk).
 *      - 36: TOFF_LS_T1OFF_LS_CONST_36 (37 * 2/fclk).
 *      - 37: TOFF_LS_T1OFF_LS_CONST_37 (38 * 2/fclk).
 *      - 38: TOFF_LS_T1OFF_LS_CONST_38 (39 * 2/fclk).
 *      - 39: TOFF_LS_T1OFF_LS_CONST_39 (40 * 2/fclk).
 *      - 40: TOFF_LS_T1OFF_LS_CONST_40 (41 * 2/fclk).
 *      - 41: TOFF_LS_T1OFF_LS_CONST_41 (42 * 2/fclk).
 *      - 42: TOFF_LS_T1OFF_LS_CONST_42 (43 * 2/fclk).
 *      - 43: TOFF_LS_T1OFF_LS_CONST_43 (44 * 2/fclk).
 *      - 44: TOFF_LS_T1OFF_LS_CONST_44 (45 * 2/fclk).
 *      - 45: TOFF_LS_T1OFF_LS_CONST_45 (46 * 2/fclk).
 *      - 46: TOFF_LS_T1OFF_LS_CONST_46 (47 * 2/fclk).
 *      - 47: TOFF_LS_T1OFF_LS_CONST_47 (48 * 2/fclk).
 *      - 48: TOFF_LS_T1OFF_LS_CONST_48 (49 * 2/fclk).
 *      - 49: TOFF_LS_T1OFF_LS_CONST_49 (50 * 2/fclk).
 *      - 50: TOFF_LS_T1OFF_LS_CONST_50 (51 * 2/fclk).
 *      - 51: TOFF_LS_T1OFF_LS_CONST_51 (52 * 2/fclk).
 *      - 52: TOFF_LS_T1OFF_LS_CONST_52 (53 * 2/fclk).
 *      - 53: TOFF_LS_T1OFF_LS_CONST_53 (54 * 2/fclk).
 *      - 54: TOFF_LS_T1OFF_LS_CONST_54 (55 * 2/fclk).
 *      - 55: TOFF_LS_T1OFF_LS_CONST_55 (56 * 2/fclk).
 *      - 56: TOFF_LS_T1OFF_LS_CONST_56 (57 * 2/fclk).
 *      - 57: TOFF_LS_T1OFF_LS_CONST_57 (58 * 2/fclk).
 *      - 58: TOFF_LS_T1OFF_LS_CONST_58 (59 * 2/fclk).
 *      - 59: TOFF_LS_T1OFF_LS_CONST_59 (60 * 2/fclk).
 *      - 60: TOFF_LS_T1OFF_LS_CONST_60 (61 * 2/fclk).
 *      - 61: TOFF_LS_T1OFF_LS_CONST_61 (62 * 2/fclk).
 *      - 62: TOFF_LS_T1OFF_LS_CONST_62 (63 * 2/fclk).
 *      - 63: TOFF_LS_T1OFF_LS_CONST_63 (64 * 2/fclk).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_TOFF_LS_T1OFF_LS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->TOFF_LS.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_TOFF_LS_T1OFF_LS_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_TOFF_LS_T1OFF_LS_POS) &
           (uint16)TLE9186_TOFF_LS_T1OFF_LS_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_TOFF_LS;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for TOFF_LS_T1OFF_LS.
 *
 * This function returns the value of the bitfield Low Side gate driver
 * pre-discharge time configuration within register TOFF_LS.
 *
 * @return Value of the bitfield TOFF_LS_T1OFF_LS:
 *      - 0: TOFF_LS_T1OFF_LS_CONST_0 (1 * 2/fclk).
 *      - 1: TOFF_LS_T1OFF_LS_CONST_1 (2 * 2/fclk).
 *      - 2: TOFF_LS_T1OFF_LS_CONST_2 (3 * 2/fclk).
 *      - 3: TOFF_LS_T1OFF_LS_CONST_3 (4 * 2/fclk).
 *      - 4: TOFF_LS_T1OFF_LS_CONST_4 (5 * 2/fclk).
 *      - 5: TOFF_LS_T1OFF_LS_CONST_5 (6 * 2/fclk).
 *      - 6: TOFF_LS_T1OFF_LS_CONST_6 (7 * 2/fclk).
 *      - 7: TOFF_LS_T1OFF_LS_CONST_7 (8 * 2/fclk (Default)).
 *      - 8: TOFF_LS_T1OFF_LS_CONST_8 (9 * 2/fclk).
 *      - 9: TOFF_LS_T1OFF_LS_CONST_9 (10 * 2/fclk).
 *      - 10: TOFF_LS_T1OFF_LS_CONST_10 (11 * 2/fclk).
 *      - 11: TOFF_LS_T1OFF_LS_CONST_11 (12 * 2/fclk).
 *      - 12: TOFF_LS_T1OFF_LS_CONST_12 (13 * 2/fclk).
 *      - 13: TOFF_LS_T1OFF_LS_CONST_13 (14 * 2/fclk).
 *      - 14: TOFF_LS_T1OFF_LS_CONST_14 (15 * 2/fclk).
 *      - 15: TOFF_LS_T1OFF_LS_CONST_15 (16 * 2/fclk).
 *      - 16: TOFF_LS_T1OFF_LS_CONST_16 (17 * 2/fclk).
 *      - 17: TOFF_LS_T1OFF_LS_CONST_17 (18 * 2/fclk).
 *      - 18: TOFF_LS_T1OFF_LS_CONST_18 (19 * 2/fclk).
 *      - 19: TOFF_LS_T1OFF_LS_CONST_19 (20 * 2/fclk).
 *      - 20: TOFF_LS_T1OFF_LS_CONST_20 (21 * 2/fclk).
 *      - 21: TOFF_LS_T1OFF_LS_CONST_21 (22 * 2/fclk).
 *      - 22: TOFF_LS_T1OFF_LS_CONST_22 (23 * 2/fclk).
 *      - 23: TOFF_LS_T1OFF_LS_CONST_23 (24 * 2/fclk ).
 *      - 24: TOFF_LS_T1OFF_LS_CONST_24 (25 * 2/fclk).
 *      - 25: TOFF_LS_T1OFF_LS_CONST_25 (26 * 2/fclk ).
 *      - 26: TOFF_LS_T1OFF_LS_CONST_26 (27 * 2/fclk).
 *      - 27: TOFF_LS_T1OFF_LS_CONST_27 (28 * 2/fclk).
 *      - 28: TOFF_LS_T1OFF_LS_CONST_28 (29 * 2/fclk).
 *      - 29: TOFF_LS_T1OFF_LS_CONST_29 (30 * 2/fclk).
 *      - 30: TOFF_LS_T1OFF_LS_CONST_30 (31 * 2/fclk).
 *      - 31: TOFF_LS_T1OFF_LS_CONST_31 (32 * 2/fclk).
 *      - 32: TOFF_LS_T1OFF_LS_CONST_32 (33 * 2/fclk).
 *      - 33: TOFF_LS_T1OFF_LS_CONST_33 (34 * 2/fclk).
 *      - 34: TOFF_LS_T1OFF_LS_CONST_34 (35 * 2/fclk).
 *      - 35: TOFF_LS_T1OFF_LS_CONST_35 (36 * 2/fclk).
 *      - 36: TOFF_LS_T1OFF_LS_CONST_36 (37 * 2/fclk).
 *      - 37: TOFF_LS_T1OFF_LS_CONST_37 (38 * 2/fclk).
 *      - 38: TOFF_LS_T1OFF_LS_CONST_38 (39 * 2/fclk).
 *      - 39: TOFF_LS_T1OFF_LS_CONST_39 (40 * 2/fclk).
 *      - 40: TOFF_LS_T1OFF_LS_CONST_40 (41 * 2/fclk).
 *      - 41: TOFF_LS_T1OFF_LS_CONST_41 (42 * 2/fclk).
 *      - 42: TOFF_LS_T1OFF_LS_CONST_42 (43 * 2/fclk).
 *      - 43: TOFF_LS_T1OFF_LS_CONST_43 (44 * 2/fclk).
 *      - 44: TOFF_LS_T1OFF_LS_CONST_44 (45 * 2/fclk).
 *      - 45: TOFF_LS_T1OFF_LS_CONST_45 (46 * 2/fclk).
 *      - 46: TOFF_LS_T1OFF_LS_CONST_46 (47 * 2/fclk).
 *      - 47: TOFF_LS_T1OFF_LS_CONST_47 (48 * 2/fclk).
 *      - 48: TOFF_LS_T1OFF_LS_CONST_48 (49 * 2/fclk).
 *      - 49: TOFF_LS_T1OFF_LS_CONST_49 (50 * 2/fclk).
 *      - 50: TOFF_LS_T1OFF_LS_CONST_50 (51 * 2/fclk).
 *      - 51: TOFF_LS_T1OFF_LS_CONST_51 (52 * 2/fclk).
 *      - 52: TOFF_LS_T1OFF_LS_CONST_52 (53 * 2/fclk).
 *      - 53: TOFF_LS_T1OFF_LS_CONST_53 (54 * 2/fclk).
 *      - 54: TOFF_LS_T1OFF_LS_CONST_54 (55 * 2/fclk).
 *      - 55: TOFF_LS_T1OFF_LS_CONST_55 (56 * 2/fclk).
 *      - 56: TOFF_LS_T1OFF_LS_CONST_56 (57 * 2/fclk).
 *      - 57: TOFF_LS_T1OFF_LS_CONST_57 (58 * 2/fclk).
 *      - 58: TOFF_LS_T1OFF_LS_CONST_58 (59 * 2/fclk).
 *      - 59: TOFF_LS_T1OFF_LS_CONST_59 (60 * 2/fclk).
 *      - 60: TOFF_LS_T1OFF_LS_CONST_60 (61 * 2/fclk).
 *      - 61: TOFF_LS_T1OFF_LS_CONST_61 (62 * 2/fclk).
 *      - 62: TOFF_LS_T1OFF_LS_CONST_62 (63 * 2/fclk).
 *      - 63: TOFF_LS_T1OFF_LS_CONST_63 (64 * 2/fclk).
 */
uint16 TLE9186_FuncLayer_get_TOFF_LS_T1OFF_LS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->TOFF_LS.bit.T1OFF_LS;
}

/**
 * @brief get function for register TOFF_LS.
 *
 * This function reads the register Gate Driver Configuration register - TOFF_LS
 * .
 *
 */
void TLE9186_FuncLayer_get_TOFF_LS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_TOFF_LS();
}

/**
 * @brief Set function for register T3OFF.
 *
 * This function sets the Gate Driver Configuration register - T3OFF.
 *
 * @param u16_value Value to be written into the register T3OFF.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_T3OFF(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_T3OFF;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for T3OFF_T3OFF_LS.
 *
 * This function sets the bitfield Low Side gate driver post-discharge time
 * configuration in register T3OFF.
 *
 * @param u16_value Value to be written into T3OFF_T3OFF_LS. Valid values are:
 *      - 0: T3OFF_T3OFF_LS_CONST_0 (1 * 2/fclk).
 *      - 1: T3OFF_T3OFF_LS_CONST_1 (2 * 2/fclk).
 *      - 2: T3OFF_T3OFF_LS_CONST_2 (3 * 2/fclk).
 *      - 3: T3OFF_T3OFF_LS_CONST_3 (4 * 2/fclk).
 *      - 4: T3OFF_T3OFF_LS_CONST_4 (5 * 2/fclk).
 *      - 5: T3OFF_T3OFF_LS_CONST_5 (6 * 2/fclk).
 *      - 6: T3OFF_T3OFF_LS_CONST_6 (7 * 2/fclk).
 *      - 7: T3OFF_T3OFF_LS_CONST_7 (8 * 2/fclk).
 *      - 8: T3OFF_T3OFF_LS_CONST_8 (9 * 2/fclk).
 *      - 9: T3OFF_T3OFF_LS_CONST_9 (10 * 2/fclk).
 *      - 10: T3OFF_T3OFF_LS_CONST_10 (11 * 2/fclk).
 *      - 11: T3OFF_T3OFF_LS_CONST_11 (12 * 2/fclk).
 *      - 12: T3OFF_T3OFF_LS_CONST_12 (13 * 2/fclk).
 *      - 13: T3OFF_T3OFF_LS_CONST_13 (14 * 2/fclk).
 *      - 14: T3OFF_T3OFF_LS_CONST_14 (15 * 2/fclk).
 *      - 15: T3OFF_T3OFF_LS_CONST_15 (16 * 2/fclk).
 *      - 16: T3OFF_T3OFF_LS_CONST_16 (17 * 2/fclk).
 *      - 17: T3OFF_T3OFF_LS_CONST_17 (18 * 2/fclk).
 *      - 18: T3OFF_T3OFF_LS_CONST_18 (19 * 2/fclk).
 *      - 19: T3OFF_T3OFF_LS_CONST_19 (20 * 2/fclk).
 *      - 20: T3OFF_T3OFF_LS_CONST_20 (21 * 2/fclk).
 *      - 21: T3OFF_T3OFF_LS_CONST_21 (22 * 2/fclk).
 *      - 22: T3OFF_T3OFF_LS_CONST_22 (23 * 2/fclk).
 *      - 23: T3OFF_T3OFF_LS_CONST_23 (24 * 2/fclk (Default)).
 *      - 24: T3OFF_T3OFF_LS_CONST_24 (25 * 2/fclk).
 *      - 25: T3OFF_T3OFF_LS_CONST_25 (26 * 2/fclk ).
 *      - 26: T3OFF_T3OFF_LS_CONST_26 (27 * 2/fclk).
 *      - 27: T3OFF_T3OFF_LS_CONST_27 (28 * 2/fclk).
 *      - 28: T3OFF_T3OFF_LS_CONST_28 (29 * 2/fclk).
 *      - 29: T3OFF_T3OFF_LS_CONST_29 (30 * 2/fclk).
 *      - 30: T3OFF_T3OFF_LS_CONST_30 (31 * 2/fclk).
 *      - 31: T3OFF_T3OFF_LS_CONST_31 (32 * 2/fclk).
 *      - 32: T3OFF_T3OFF_LS_CONST_32 (33 * 2/fclk).
 *      - 33: T3OFF_T3OFF_LS_CONST_33 (34 * 2/fclk).
 *      - 34: T3OFF_T3OFF_LS_CONST_34 (35 * 2/fclk).
 *      - 35: T3OFF_T3OFF_LS_CONST_35 (36 * 2/fclk).
 *      - 36: T3OFF_T3OFF_LS_CONST_36 (37 * 2/fclk).
 *      - 37: T3OFF_T3OFF_LS_CONST_37 (38 * 2/fclk).
 *      - 38: T3OFF_T3OFF_LS_CONST_38 (39 * 2/fclk).
 *      - 39: T3OFF_T3OFF_LS_CONST_39 (40 * 2/fclk).
 *      - 40: T3OFF_T3OFF_LS_CONST_40 (41 * 2/fclk).
 *      - 41: T3OFF_T3OFF_LS_CONST_41 (42 * 2/fclk).
 *      - 42: T3OFF_T3OFF_LS_CONST_42 (43 * 2/fclk).
 *      - 43: T3OFF_T3OFF_LS_CONST_43 (44 * 2/fclk).
 *      - 44: T3OFF_T3OFF_LS_CONST_44 (45 * 2/fclk).
 *      - 45: T3OFF_T3OFF_LS_CONST_45 (46 * 2/fclk).
 *      - 46: T3OFF_T3OFF_LS_CONST_46 (47 * 2/fclk).
 *      - 47: T3OFF_T3OFF_LS_CONST_47 (48 * 2/fclk).
 *      - 48: T3OFF_T3OFF_LS_CONST_48 (49 * 2/fclk).
 *      - 49: T3OFF_T3OFF_LS_CONST_49 (50 * 2/fclk).
 *      - 50: T3OFF_T3OFF_LS_CONST_50 (51 * 2/fclk).
 *      - 51: T3OFF_T3OFF_LS_CONST_51 (52 * 2/fclk).
 *      - 52: T3OFF_T3OFF_LS_CONST_52 (53 * 2/fclk).
 *      - 53: T3OFF_T3OFF_LS_CONST_53 (54 * 2/fclk).
 *      - 54: T3OFF_T3OFF_LS_CONST_54 (55 * 2/fclk).
 *      - 55: T3OFF_T3OFF_LS_CONST_55 (56 * 2/fclk).
 *      - 56: T3OFF_T3OFF_LS_CONST_56 (57 * 2/fclk).
 *      - 57: T3OFF_T3OFF_LS_CONST_57 (58 * 2/fclk).
 *      - 58: T3OFF_T3OFF_LS_CONST_58 (59 * 2/fclk).
 *      - 59: T3OFF_T3OFF_LS_CONST_59 (60 * 2/fclk).
 *      - 60: T3OFF_T3OFF_LS_CONST_60 (61 * 2/fclk).
 *      - 61: T3OFF_T3OFF_LS_CONST_61 (62 * 2/fclk).
 *      - 62: T3OFF_T3OFF_LS_CONST_62 (63 * 2/fclk).
 *      - 63: T3OFF_T3OFF_LS_CONST_63 (64 * 2/fclk).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_T3OFF_T3OFF_LS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->T3OFF.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_T3OFF_T3OFF_LS_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_T3OFF_T3OFF_LS_POS) &
           (uint16)TLE9186_T3OFF_T3OFF_LS_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_T3OFF;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for T3OFF_T3OFF_LS.
 *
 * This function returns the value of the bitfield Low Side gate driver
 * post-discharge time configuration within register T3OFF.
 *
 * @return Value of the bitfield T3OFF_T3OFF_LS:
 *      - 0: T3OFF_T3OFF_LS_CONST_0 (1 * 2/fclk).
 *      - 1: T3OFF_T3OFF_LS_CONST_1 (2 * 2/fclk).
 *      - 2: T3OFF_T3OFF_LS_CONST_2 (3 * 2/fclk).
 *      - 3: T3OFF_T3OFF_LS_CONST_3 (4 * 2/fclk).
 *      - 4: T3OFF_T3OFF_LS_CONST_4 (5 * 2/fclk).
 *      - 5: T3OFF_T3OFF_LS_CONST_5 (6 * 2/fclk).
 *      - 6: T3OFF_T3OFF_LS_CONST_6 (7 * 2/fclk).
 *      - 7: T3OFF_T3OFF_LS_CONST_7 (8 * 2/fclk).
 *      - 8: T3OFF_T3OFF_LS_CONST_8 (9 * 2/fclk).
 *      - 9: T3OFF_T3OFF_LS_CONST_9 (10 * 2/fclk).
 *      - 10: T3OFF_T3OFF_LS_CONST_10 (11 * 2/fclk).
 *      - 11: T3OFF_T3OFF_LS_CONST_11 (12 * 2/fclk).
 *      - 12: T3OFF_T3OFF_LS_CONST_12 (13 * 2/fclk).
 *      - 13: T3OFF_T3OFF_LS_CONST_13 (14 * 2/fclk).
 *      - 14: T3OFF_T3OFF_LS_CONST_14 (15 * 2/fclk).
 *      - 15: T3OFF_T3OFF_LS_CONST_15 (16 * 2/fclk).
 *      - 16: T3OFF_T3OFF_LS_CONST_16 (17 * 2/fclk).
 *      - 17: T3OFF_T3OFF_LS_CONST_17 (18 * 2/fclk).
 *      - 18: T3OFF_T3OFF_LS_CONST_18 (19 * 2/fclk).
 *      - 19: T3OFF_T3OFF_LS_CONST_19 (20 * 2/fclk).
 *      - 20: T3OFF_T3OFF_LS_CONST_20 (21 * 2/fclk).
 *      - 21: T3OFF_T3OFF_LS_CONST_21 (22 * 2/fclk).
 *      - 22: T3OFF_T3OFF_LS_CONST_22 (23 * 2/fclk).
 *      - 23: T3OFF_T3OFF_LS_CONST_23 (24 * 2/fclk (Default)).
 *      - 24: T3OFF_T3OFF_LS_CONST_24 (25 * 2/fclk).
 *      - 25: T3OFF_T3OFF_LS_CONST_25 (26 * 2/fclk ).
 *      - 26: T3OFF_T3OFF_LS_CONST_26 (27 * 2/fclk).
 *      - 27: T3OFF_T3OFF_LS_CONST_27 (28 * 2/fclk).
 *      - 28: T3OFF_T3OFF_LS_CONST_28 (29 * 2/fclk).
 *      - 29: T3OFF_T3OFF_LS_CONST_29 (30 * 2/fclk).
 *      - 30: T3OFF_T3OFF_LS_CONST_30 (31 * 2/fclk).
 *      - 31: T3OFF_T3OFF_LS_CONST_31 (32 * 2/fclk).
 *      - 32: T3OFF_T3OFF_LS_CONST_32 (33 * 2/fclk).
 *      - 33: T3OFF_T3OFF_LS_CONST_33 (34 * 2/fclk).
 *      - 34: T3OFF_T3OFF_LS_CONST_34 (35 * 2/fclk).
 *      - 35: T3OFF_T3OFF_LS_CONST_35 (36 * 2/fclk).
 *      - 36: T3OFF_T3OFF_LS_CONST_36 (37 * 2/fclk).
 *      - 37: T3OFF_T3OFF_LS_CONST_37 (38 * 2/fclk).
 *      - 38: T3OFF_T3OFF_LS_CONST_38 (39 * 2/fclk).
 *      - 39: T3OFF_T3OFF_LS_CONST_39 (40 * 2/fclk).
 *      - 40: T3OFF_T3OFF_LS_CONST_40 (41 * 2/fclk).
 *      - 41: T3OFF_T3OFF_LS_CONST_41 (42 * 2/fclk).
 *      - 42: T3OFF_T3OFF_LS_CONST_42 (43 * 2/fclk).
 *      - 43: T3OFF_T3OFF_LS_CONST_43 (44 * 2/fclk).
 *      - 44: T3OFF_T3OFF_LS_CONST_44 (45 * 2/fclk).
 *      - 45: T3OFF_T3OFF_LS_CONST_45 (46 * 2/fclk).
 *      - 46: T3OFF_T3OFF_LS_CONST_46 (47 * 2/fclk).
 *      - 47: T3OFF_T3OFF_LS_CONST_47 (48 * 2/fclk).
 *      - 48: T3OFF_T3OFF_LS_CONST_48 (49 * 2/fclk).
 *      - 49: T3OFF_T3OFF_LS_CONST_49 (50 * 2/fclk).
 *      - 50: T3OFF_T3OFF_LS_CONST_50 (51 * 2/fclk).
 *      - 51: T3OFF_T3OFF_LS_CONST_51 (52 * 2/fclk).
 *      - 52: T3OFF_T3OFF_LS_CONST_52 (53 * 2/fclk).
 *      - 53: T3OFF_T3OFF_LS_CONST_53 (54 * 2/fclk).
 *      - 54: T3OFF_T3OFF_LS_CONST_54 (55 * 2/fclk).
 *      - 55: T3OFF_T3OFF_LS_CONST_55 (56 * 2/fclk).
 *      - 56: T3OFF_T3OFF_LS_CONST_56 (57 * 2/fclk).
 *      - 57: T3OFF_T3OFF_LS_CONST_57 (58 * 2/fclk).
 *      - 58: T3OFF_T3OFF_LS_CONST_58 (59 * 2/fclk).
 *      - 59: T3OFF_T3OFF_LS_CONST_59 (60 * 2/fclk).
 *      - 60: T3OFF_T3OFF_LS_CONST_60 (61 * 2/fclk).
 *      - 61: T3OFF_T3OFF_LS_CONST_61 (62 * 2/fclk).
 *      - 62: T3OFF_T3OFF_LS_CONST_62 (63 * 2/fclk).
 *      - 63: T3OFF_T3OFF_LS_CONST_63 (64 * 2/fclk).
 */
uint16 TLE9186_FuncLayer_get_T3OFF_T3OFF_LS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->T3OFF.bit.T3OFF_LS;
}

/**
 * @brief Set function for T3OFF_T3OFF_HS.
 *
 * This function sets the bitfield High Side gate driver post-discharge time
 * configuration in register T3OFF.
 *
 * @param u16_value Value to be written into T3OFF_T3OFF_HS. Valid values are:
 *      - 0: T3OFF_T3OFF_HS_CONST_0 (1 * 2/fclk).
 *      - 1: T3OFF_T3OFF_HS_CONST_1 (2 * 2/fclk).
 *      - 2: T3OFF_T3OFF_HS_CONST_2 (3 * 2/fclk).
 *      - 3: T3OFF_T3OFF_HS_CONST_3 (4 * 2/fclk).
 *      - 4: T3OFF_T3OFF_HS_CONST_4 (5 * 2/fclk).
 *      - 5: T3OFF_T3OFF_HS_CONST_5 (6 * 2/fclk).
 *      - 6: T3OFF_T3OFF_HS_CONST_6 (7 * 2/fclk).
 *      - 7: T3OFF_T3OFF_HS_CONST_7 (8 * 2/fclk ).
 *      - 8: T3OFF_T3OFF_HS_CONST_8 (9 * 2/fclk).
 *      - 9: T3OFF_T3OFF_HS_CONST_9 (10 * 2/fclk).
 *      - 10: T3OFF_T3OFF_HS_CONST_10 (11 * 2/fclk).
 *      - 11: T3OFF_T3OFF_HS_CONST_11 (12 * 2/fclk).
 *      - 12: T3OFF_T3OFF_HS_CONST_12 (13 * 2/fclk).
 *      - 13: T3OFF_T3OFF_HS_CONST_13 (14 * 2/fclk).
 *      - 14: T3OFF_T3OFF_HS_CONST_14 (15 * 2/fclk).
 *      - 15: T3OFF_T3OFF_HS_CONST_15 (16 * 2/fclk).
 *      - 16: T3OFF_T3OFF_HS_CONST_16 (17 * 2/fclk).
 *      - 17: T3OFF_T3OFF_HS_CONST_17 (18 * 2/fclk).
 *      - 18: T3OFF_T3OFF_HS_CONST_18 (19 * 2/fclk).
 *      - 19: T3OFF_T3OFF_HS_CONST_19 (20 * 2/fclk).
 *      - 20: T3OFF_T3OFF_HS_CONST_20 (21 * 2/fclk).
 *      - 21: T3OFF_T3OFF_HS_CONST_21 (22 * 2/fclk).
 *      - 22: T3OFF_T3OFF_HS_CONST_22 (23 * 2/fclk).
 *      - 23: T3OFF_T3OFF_HS_CONST_23 (24 * 2/fclk (Default)).
 *      - 24: T3OFF_T3OFF_HS_CONST_24 (25 * 2/fclk).
 *      - 25: T3OFF_T3OFF_HS_CONST_25 (26 * 2/fclk ).
 *      - 26: T3OFF_T3OFF_HS_CONST_26 (27 * 2/fclk).
 *      - 27: T3OFF_T3OFF_HS_CONST_27 (28 * 2/fclk).
 *      - 28: T3OFF_T3OFF_HS_CONST_28 (29 * 2/fclk).
 *      - 29: T3OFF_T3OFF_HS_CONST_29 (30 * 2/fclk).
 *      - 30: T3OFF_T3OFF_HS_CONST_30 (31 * 2/fclk).
 *      - 31: T3OFF_T3OFF_HS_CONST_31 (32 * 2/fclk).
 *      - 32: T3OFF_T3OFF_HS_CONST_32 (33 * 2/fclk).
 *      - 33: T3OFF_T3OFF_HS_CONST_33 (34 * 2/fclk).
 *      - 34: T3OFF_T3OFF_HS_CONST_34 (35 * 2/fclk).
 *      - 35: T3OFF_T3OFF_HS_CONST_35 (36 * 2/fclk).
 *      - 36: T3OFF_T3OFF_HS_CONST_36 (37 * 2/fclk).
 *      - 37: T3OFF_T3OFF_HS_CONST_37 (38 * 2/fclk).
 *      - 38: T3OFF_T3OFF_HS_CONST_38 (39 * 2/fclk).
 *      - 39: T3OFF_T3OFF_HS_CONST_39 (40 * 2/fclk).
 *      - 40: T3OFF_T3OFF_HS_CONST_40 (41 * 2/fclk).
 *      - 41: T3OFF_T3OFF_HS_CONST_41 (42 * 2/fclk).
 *      - 42: T3OFF_T3OFF_HS_CONST_42 (43 * 2/fclk).
 *      - 43: T3OFF_T3OFF_HS_CONST_43 (44 * 2/fclk).
 *      - 44: T3OFF_T3OFF_HS_CONST_44 (45 * 2/fclk).
 *      - 45: T3OFF_T3OFF_HS_CONST_45 (46 * 2/fclk).
 *      - 46: T3OFF_T3OFF_HS_CONST_46 (47 * 2/fclk).
 *      - 47: T3OFF_T3OFF_HS_CONST_47 (48 * 2/fclk).
 *      - 48: T3OFF_T3OFF_HS_CONST_48 (49 * 2/fclk).
 *      - 49: T3OFF_T3OFF_HS_CONST_49 (50 * 2/fclk).
 *      - 50: T3OFF_T3OFF_HS_CONST_50 (51 * 2/fclk).
 *      - 51: T3OFF_T3OFF_HS_CONST_51 (52 * 2/fclk).
 *      - 52: T3OFF_T3OFF_HS_CONST_52 (53 * 2/fclk).
 *      - 53: T3OFF_T3OFF_HS_CONST_53 (54 * 2/fclk).
 *      - 54: T3OFF_T3OFF_HS_CONST_54 (55 * 2/fclk).
 *      - 55: T3OFF_T3OFF_HS_CONST_55 (56 * 2/fclk).
 *      - 56: T3OFF_T3OFF_HS_CONST_56 (57 * 2/fclk).
 *      - 57: T3OFF_T3OFF_HS_CONST_57 (58 * 2/fclk).
 *      - 58: T3OFF_T3OFF_HS_CONST_58 (59 * 2/fclk).
 *      - 59: T3OFF_T3OFF_HS_CONST_59 (60 * 2/fclk).
 *      - 60: T3OFF_T3OFF_HS_CONST_60 (61 * 2/fclk).
 *      - 61: TOFF_LS_T1OFF_LS_CONST_61 (62 * 2/fclk).
 *      - 62: T3OFF_T3OFF_HS_CONST_62 (63 * 2/fclk).
 *      - 63: T3OFF_T3OFF_HS_CONST_63 (64 * 2/fclk).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_T3OFF_T3OFF_HS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->T3OFF.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_T3OFF_T3OFF_HS_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_T3OFF_T3OFF_HS_POS) &
           (uint16)TLE9186_T3OFF_T3OFF_HS_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_T3OFF;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for T3OFF_T3OFF_HS.
 *
 * This function returns the value of the bitfield High Side gate driver
 * post-discharge time configuration within register T3OFF.
 *
 * @return Value of the bitfield T3OFF_T3OFF_HS:
 *      - 0: T3OFF_T3OFF_HS_CONST_0 (1 * 2/fclk).
 *      - 1: T3OFF_T3OFF_HS_CONST_1 (2 * 2/fclk).
 *      - 2: T3OFF_T3OFF_HS_CONST_2 (3 * 2/fclk).
 *      - 3: T3OFF_T3OFF_HS_CONST_3 (4 * 2/fclk).
 *      - 4: T3OFF_T3OFF_HS_CONST_4 (5 * 2/fclk).
 *      - 5: T3OFF_T3OFF_HS_CONST_5 (6 * 2/fclk).
 *      - 6: T3OFF_T3OFF_HS_CONST_6 (7 * 2/fclk).
 *      - 7: T3OFF_T3OFF_HS_CONST_7 (8 * 2/fclk ).
 *      - 8: T3OFF_T3OFF_HS_CONST_8 (9 * 2/fclk).
 *      - 9: T3OFF_T3OFF_HS_CONST_9 (10 * 2/fclk).
 *      - 10: T3OFF_T3OFF_HS_CONST_10 (11 * 2/fclk).
 *      - 11: T3OFF_T3OFF_HS_CONST_11 (12 * 2/fclk).
 *      - 12: T3OFF_T3OFF_HS_CONST_12 (13 * 2/fclk).
 *      - 13: T3OFF_T3OFF_HS_CONST_13 (14 * 2/fclk).
 *      - 14: T3OFF_T3OFF_HS_CONST_14 (15 * 2/fclk).
 *      - 15: T3OFF_T3OFF_HS_CONST_15 (16 * 2/fclk).
 *      - 16: T3OFF_T3OFF_HS_CONST_16 (17 * 2/fclk).
 *      - 17: T3OFF_T3OFF_HS_CONST_17 (18 * 2/fclk).
 *      - 18: T3OFF_T3OFF_HS_CONST_18 (19 * 2/fclk).
 *      - 19: T3OFF_T3OFF_HS_CONST_19 (20 * 2/fclk).
 *      - 20: T3OFF_T3OFF_HS_CONST_20 (21 * 2/fclk).
 *      - 21: T3OFF_T3OFF_HS_CONST_21 (22 * 2/fclk).
 *      - 22: T3OFF_T3OFF_HS_CONST_22 (23 * 2/fclk).
 *      - 23: T3OFF_T3OFF_HS_CONST_23 (24 * 2/fclk (Default)).
 *      - 24: T3OFF_T3OFF_HS_CONST_24 (25 * 2/fclk).
 *      - 25: T3OFF_T3OFF_HS_CONST_25 (26 * 2/fclk ).
 *      - 26: T3OFF_T3OFF_HS_CONST_26 (27 * 2/fclk).
 *      - 27: T3OFF_T3OFF_HS_CONST_27 (28 * 2/fclk).
 *      - 28: T3OFF_T3OFF_HS_CONST_28 (29 * 2/fclk).
 *      - 29: T3OFF_T3OFF_HS_CONST_29 (30 * 2/fclk).
 *      - 30: T3OFF_T3OFF_HS_CONST_30 (31 * 2/fclk).
 *      - 31: T3OFF_T3OFF_HS_CONST_31 (32 * 2/fclk).
 *      - 32: T3OFF_T3OFF_HS_CONST_32 (33 * 2/fclk).
 *      - 33: T3OFF_T3OFF_HS_CONST_33 (34 * 2/fclk).
 *      - 34: T3OFF_T3OFF_HS_CONST_34 (35 * 2/fclk).
 *      - 35: T3OFF_T3OFF_HS_CONST_35 (36 * 2/fclk).
 *      - 36: T3OFF_T3OFF_HS_CONST_36 (37 * 2/fclk).
 *      - 37: T3OFF_T3OFF_HS_CONST_37 (38 * 2/fclk).
 *      - 38: T3OFF_T3OFF_HS_CONST_38 (39 * 2/fclk).
 *      - 39: T3OFF_T3OFF_HS_CONST_39 (40 * 2/fclk).
 *      - 40: T3OFF_T3OFF_HS_CONST_40 (41 * 2/fclk).
 *      - 41: T3OFF_T3OFF_HS_CONST_41 (42 * 2/fclk).
 *      - 42: T3OFF_T3OFF_HS_CONST_42 (43 * 2/fclk).
 *      - 43: T3OFF_T3OFF_HS_CONST_43 (44 * 2/fclk).
 *      - 44: T3OFF_T3OFF_HS_CONST_44 (45 * 2/fclk).
 *      - 45: T3OFF_T3OFF_HS_CONST_45 (46 * 2/fclk).
 *      - 46: T3OFF_T3OFF_HS_CONST_46 (47 * 2/fclk).
 *      - 47: T3OFF_T3OFF_HS_CONST_47 (48 * 2/fclk).
 *      - 48: T3OFF_T3OFF_HS_CONST_48 (49 * 2/fclk).
 *      - 49: T3OFF_T3OFF_HS_CONST_49 (50 * 2/fclk).
 *      - 50: T3OFF_T3OFF_HS_CONST_50 (51 * 2/fclk).
 *      - 51: T3OFF_T3OFF_HS_CONST_51 (52 * 2/fclk).
 *      - 52: T3OFF_T3OFF_HS_CONST_52 (53 * 2/fclk).
 *      - 53: T3OFF_T3OFF_HS_CONST_53 (54 * 2/fclk).
 *      - 54: T3OFF_T3OFF_HS_CONST_54 (55 * 2/fclk).
 *      - 55: T3OFF_T3OFF_HS_CONST_55 (56 * 2/fclk).
 *      - 56: T3OFF_T3OFF_HS_CONST_56 (57 * 2/fclk).
 *      - 57: T3OFF_T3OFF_HS_CONST_57 (58 * 2/fclk).
 *      - 58: T3OFF_T3OFF_HS_CONST_58 (59 * 2/fclk).
 *      - 59: T3OFF_T3OFF_HS_CONST_59 (60 * 2/fclk).
 *      - 60: T3OFF_T3OFF_HS_CONST_60 (61 * 2/fclk).
 *      - 61: TOFF_LS_T1OFF_LS_CONST_61 (62 * 2/fclk).
 *      - 62: T3OFF_T3OFF_HS_CONST_62 (63 * 2/fclk).
 *      - 63: T3OFF_T3OFF_HS_CONST_63 (64 * 2/fclk).
 */
uint16 TLE9186_FuncLayer_get_T3OFF_T3OFF_HS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->T3OFF.bit.T3OFF_HS;
}

/**
 * @brief get function for register T3OFF.
 *
 * This function reads the register Gate Driver Configuration register - T3OFF.
 *
 */
void TLE9186_FuncLayer_get_T3OFF(void) /* polyspace MISRA2012:5.1 [Justified:
                                          Low] "Given due to register names" */
{
  TLE9186_RegLayer_get_T3OFF();
}

/**
 * @brief Set function for register ION_HS1.
 *
 * This function sets the Gate driver Configuration register - ION_HS1.
 *
 * @param u16_value Value to be written into the register ION_HS1.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_HS1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_HS1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for ION_HS1_I2ON_HS1.
 *
 * This function sets the bitfield HS1 Gate Driver charge current setting in
 * register ION_HS1.
 *
 * @param u16_value Value to be written into ION_HS1_I2ON_HS1. Valid values are:
 *      - 0: ION_HS1_I2ON_HS1_CONST_0 (ICHG0).
 *      - 63: ION_HS1_I2ON_HS1_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_HS1_I2ON_HS1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->ION_HS1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_ION_HS1_I2ON_HS1_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_ION_HS1_I2ON_HS1_POS) &
           (uint16)TLE9186_ION_HS1_I2ON_HS1_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_HS1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for ION_HS1_I2ON_HS1.
 *
 * This function returns the value of the bitfield HS1 Gate Driver charge
 * current setting within register ION_HS1.
 *
 * @return Value of the bitfield ION_HS1_I2ON_HS1:
 *      - 0: ION_HS1_I2ON_HS1_CONST_0 (ICHG0).
 *      - 63: ION_HS1_I2ON_HS1_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_ION_HS1_I2ON_HS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->ION_HS1.bit.I2ON_HS1;
}

/**
 * @brief Set function for ION_HS1_I1ON_HS1.
 *
 * This function sets the bitfield HS1 Gate Driver pre-charge current setting in
 * register ION_HS1.
 *
 * @param u16_value Value to be written into ION_HS1_I1ON_HS1. Valid values are:
 *      - 0: ION_HS1_I1ON_HS1_CONST_0 (ICHG0).
 *      - 63: ION_HS1_I1ON_HS1_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_HS1_I1ON_HS1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->ION_HS1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_ION_HS1_I1ON_HS1_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_ION_HS1_I1ON_HS1_POS) &
           (uint16)TLE9186_ION_HS1_I1ON_HS1_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_HS1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for ION_HS1_I1ON_HS1.
 *
 * This function returns the value of the bitfield HS1 Gate Driver pre-charge
 * current setting within register ION_HS1.
 *
 * @return Value of the bitfield ION_HS1_I1ON_HS1:
 *      - 0: ION_HS1_I1ON_HS1_CONST_0 (ICHG0).
 *      - 63: ION_HS1_I1ON_HS1_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_ION_HS1_I1ON_HS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->ION_HS1.bit.I1ON_HS1;
}

/**
 * @brief Set function for ION_HS1_ION_HS_BNK.
 *
 * This function sets the bitfield Banking configuration of I1ON, I2ON HS charge
 * current in register ION_HS1.
 *
 * @param u16_value Value to be written into ION_HS1_ION_HS_BNK. Valid values
 * are:
 *      - 0: ION_HS1_ION_HS_BNK_CONST_0 (I1ON_HS1 pre-charge current settings
 * applied for all 3x HS MOSFET gate drivers\nI2ON_HS1 charge current setting
 * applied only for all 3xHS MOSFET gate drivers (Default)).
 *      - 1: ION_HS1_ION_HS_BNK_CONST_1 (reserved).
 *      - 2: ION_HS1_ION_HS_BNK_CONST_2 (reserved).
 *      - 3: ION_HS1_ION_HS_BNK_CONST_3 (I1ON_HS1 pre-charge current setting
 * applied only for HS1 MOSFET gate driver\nI2ON_HS1 charge current setting
 * applied only for HS1 MOSFET gate driver).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_HS1_ION_HS_BNK(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->ION_HS1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_ION_HS1_ION_HS_BNK_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_ION_HS1_ION_HS_BNK_POS) &
           (uint16)TLE9186_ION_HS1_ION_HS_BNK_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_HS1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for ION_HS1_ION_HS_BNK.
 *
 * This function returns the value of the bitfield Banking configuration of
 * I1ON, I2ON HS charge current within register ION_HS1.
 *
 * @return Value of the bitfield ION_HS1_ION_HS_BNK:
 *      - 0: ION_HS1_ION_HS_BNK_CONST_0 (I1ON_HS1 pre-charge current settings
 * applied for all 3x HS MOSFET gate drivers\nI2ON_HS1 charge current setting
 * applied only for all 3xHS MOSFET gate drivers (Default)).
 *      - 1: ION_HS1_ION_HS_BNK_CONST_1 (reserved).
 *      - 2: ION_HS1_ION_HS_BNK_CONST_2 (reserved).
 *      - 3: ION_HS1_ION_HS_BNK_CONST_3 (I1ON_HS1 pre-charge current setting
 * applied only for HS1 MOSFET gate driver\nI2ON_HS1 charge current setting
 * applied only for HS1 MOSFET gate driver).
 */
uint16 TLE9186_FuncLayer_get_ION_HS1_ION_HS_BNK(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->ION_HS1.bit.ION_HS_BNK;
}

/**
 * @brief get function for register ION_HS1.
 *
 * This function reads the register Gate driver Configuration register -
 * ION_HS1.
 *
 */
void TLE9186_FuncLayer_get_ION_HS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_ION_HS1();
}

/**
 * @brief Set function for register ION_LS1.
 *
 * This function sets the Gate driver Configuration register - ION_LS1.
 *
 * @param u16_value Value to be written into the register ION_LS1.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_LS1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_LS1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for ION_LS1_I2ON_LS1.
 *
 * This function sets the bitfield LS1 Gate Driver charge current setting in
 * register ION_LS1.
 *
 * @param u16_value Value to be written into ION_LS1_I2ON_LS1. Valid values are:
 *      - 0: ION_LS1_I2ON_LS1_CONST_0 (ICHG0).
 *      - 63: ION_LS1_I2ON_LS1_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_LS1_I2ON_LS1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->ION_LS1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_ION_LS1_I2ON_LS1_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_ION_LS1_I2ON_LS1_POS) &
           (uint16)TLE9186_ION_LS1_I2ON_LS1_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_LS1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for ION_LS1_I2ON_LS1.
 *
 * This function returns the value of the bitfield LS1 Gate Driver charge
 * current setting within register ION_LS1.
 *
 * @return Value of the bitfield ION_LS1_I2ON_LS1:
 *      - 0: ION_LS1_I2ON_LS1_CONST_0 (ICHG0).
 *      - 63: ION_LS1_I2ON_LS1_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_ION_LS1_I2ON_LS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->ION_LS1.bit.I2ON_LS1;
}

/**
 * @brief Set function for ION_LS1_I1ON_LS1.
 *
 * This function sets the bitfield LS1 Gate Driver pre-charge current setting in
 * register ION_LS1.
 *
 * @param u16_value Value to be written into ION_LS1_I1ON_LS1. Valid values are:
 *      - 0: ION_LS1_I1ON_LS1_CONST_0 (ICHG0).
 *      - 63: ION_LS1_I1ON_LS1_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_LS1_I1ON_LS1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->ION_LS1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_ION_LS1_I1ON_LS1_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_ION_LS1_I1ON_LS1_POS) &
           (uint16)TLE9186_ION_LS1_I1ON_LS1_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_LS1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for ION_LS1_I1ON_LS1.
 *
 * This function returns the value of the bitfield LS1 Gate Driver pre-charge
 * current setting within register ION_LS1.
 *
 * @return Value of the bitfield ION_LS1_I1ON_LS1:
 *      - 0: ION_LS1_I1ON_LS1_CONST_0 (ICHG0).
 *      - 63: ION_LS1_I1ON_LS1_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_ION_LS1_I1ON_LS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->ION_LS1.bit.I1ON_LS1;
}

/**
 * @brief Set function for ION_LS1_ION_LS_BNK.
 *
 * This function sets the bitfield Banking configuration of I1ON, I2ON LS charge
 * current in register ION_LS1.
 *
 * @param u16_value Value to be written into ION_LS1_ION_LS_BNK. Valid values
 * are:
 *      - 0: ION_LS1_ION_LS_BNK_CONST_0 (I1ON_LS1 pre-charge current settings
 * applied for all 3x LS MOSFET gate drivers\nI2ON_LS1 charge current setting
 * applied only for all 3x LS MOSFET gate drivers (Default)).
 *      - 1: ION_LS1_ION_LS_BNK_CONST_1 (reserved).
 *      - 2: ION_LS1_ION_LS_BNK_CONST_2 (reserved).
 *      - 3: ION_LS1_ION_LS_BNK_CONST_3 (I1ON_LS1 pre-charge current setting
 * applied only for LS1 MOSFET gate driver\nI2ON_LS1 charge current setting
 * applied only for LS1 MOSFET gate driver).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_LS1_ION_LS_BNK(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->ION_LS1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_ION_LS1_ION_LS_BNK_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_ION_LS1_ION_LS_BNK_POS) &
           (uint16)TLE9186_ION_LS1_ION_LS_BNK_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_LS1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for ION_LS1_ION_LS_BNK.
 *
 * This function returns the value of the bitfield Banking configuration of
 * I1ON, I2ON LS charge current within register ION_LS1.
 *
 * @return Value of the bitfield ION_LS1_ION_LS_BNK:
 *      - 0: ION_LS1_ION_LS_BNK_CONST_0 (I1ON_LS1 pre-charge current settings
 * applied for all 3x LS MOSFET gate drivers\nI2ON_LS1 charge current setting
 * applied only for all 3x LS MOSFET gate drivers (Default)).
 *      - 1: ION_LS1_ION_LS_BNK_CONST_1 (reserved).
 *      - 2: ION_LS1_ION_LS_BNK_CONST_2 (reserved).
 *      - 3: ION_LS1_ION_LS_BNK_CONST_3 (I1ON_LS1 pre-charge current setting
 * applied only for LS1 MOSFET gate driver\nI2ON_LS1 charge current setting
 * applied only for LS1 MOSFET gate driver).
 */
uint16 TLE9186_FuncLayer_get_ION_LS1_ION_LS_BNK(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->ION_LS1.bit.ION_LS_BNK;
}

/**
 * @brief get function for register ION_LS1.
 *
 * This function reads the register Gate driver Configuration register -
 * ION_LS1.
 *
 */
void TLE9186_FuncLayer_get_ION_LS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_ION_LS1();
}

/**
 * @brief Set function for register ION_HS2.
 *
 * This function sets the Gate driver Configuration register - ION_HS2.
 *
 * @param u16_value Value to be written into the register ION_HS2.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_HS2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_HS2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for ION_HS2_I2ON_HS2.
 *
 * This function sets the bitfield HS2 Gate Driver charge current setting in
 * register ION_HS2.
 *
 * @param u16_value Value to be written into ION_HS2_I2ON_HS2. Valid values are:
 *      - 0: ION_HS2_I2ON_HS2_CONST_0 (ICHG0).
 *      - 63: ION_HS2_I2ON_HS2_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_HS2_I2ON_HS2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->ION_HS2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_ION_HS2_I2ON_HS2_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_ION_HS2_I2ON_HS2_POS) &
           (uint16)TLE9186_ION_HS2_I2ON_HS2_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_HS2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for ION_HS2_I2ON_HS2.
 *
 * This function returns the value of the bitfield HS2 Gate Driver charge
 * current setting within register ION_HS2.
 *
 * @return Value of the bitfield ION_HS2_I2ON_HS2:
 *      - 0: ION_HS2_I2ON_HS2_CONST_0 (ICHG0).
 *      - 63: ION_HS2_I2ON_HS2_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_ION_HS2_I2ON_HS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->ION_HS2.bit.I2ON_HS2;
}

/**
 * @brief Set function for ION_HS2_I1ON_HS2.
 *
 * This function sets the bitfield HS2 Gate Driver pre-charge current setting in
 * register ION_HS2.
 *
 * @param u16_value Value to be written into ION_HS2_I1ON_HS2. Valid values are:
 *      - 0: ION_HS2_I1ON_HS2_CONST_0 (ICHG0).
 *      - 63: ION_HS2_I1ON_HS2_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_HS2_I1ON_HS2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->ION_HS2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_ION_HS2_I1ON_HS2_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_ION_HS2_I1ON_HS2_POS) &
           (uint16)TLE9186_ION_HS2_I1ON_HS2_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_HS2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for ION_HS2_I1ON_HS2.
 *
 * This function returns the value of the bitfield HS2 Gate Driver pre-charge
 * current setting within register ION_HS2.
 *
 * @return Value of the bitfield ION_HS2_I1ON_HS2:
 *      - 0: ION_HS2_I1ON_HS2_CONST_0 (ICHG0).
 *      - 63: ION_HS2_I1ON_HS2_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_ION_HS2_I1ON_HS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->ION_HS2.bit.I1ON_HS2;
}

/**
 * @brief get function for register ION_HS2.
 *
 * This function reads the register Gate driver Configuration register -
 * ION_HS2.
 *
 */
void TLE9186_FuncLayer_get_ION_HS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_ION_HS2();
}

/**
 * @brief Set function for register ION_LS2.
 *
 * This function sets the Gate driver Configuration register - ION_LS2.
 *
 * @param u16_value Value to be written into the register ION_LS2.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_LS2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_LS2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for ION_LS2_I2ON_LS2.
 *
 * This function sets the bitfield LS2 Gate Driver charge current setting in
 * register ION_LS2.
 *
 * @param u16_value Value to be written into ION_LS2_I2ON_LS2. Valid values are:
 *      - 0: ION_LS2_I2ON_LS2_CONST_0 (ICHG0).
 *      - 63: ION_LS2_I2ON_LS2_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_LS2_I2ON_LS2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->ION_LS2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_ION_LS2_I2ON_LS2_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_ION_LS2_I2ON_LS2_POS) &
           (uint16)TLE9186_ION_LS2_I2ON_LS2_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_LS2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for ION_LS2_I2ON_LS2.
 *
 * This function returns the value of the bitfield LS2 Gate Driver charge
 * current setting within register ION_LS2.
 *
 * @return Value of the bitfield ION_LS2_I2ON_LS2:
 *      - 0: ION_LS2_I2ON_LS2_CONST_0 (ICHG0).
 *      - 63: ION_LS2_I2ON_LS2_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_ION_LS2_I2ON_LS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->ION_LS2.bit.I2ON_LS2;
}

/**
 * @brief Set function for ION_LS2_I1ON_LS2.
 *
 * This function sets the bitfield LS2 Gate Driver pre-charge current setting in
 * register ION_LS2.
 *
 * @param u16_value Value to be written into ION_LS2_I1ON_LS2. Valid values are:
 *      - 0: ION_LS2_I1ON_LS2_CONST_0 (ICHG0).
 *      - 63: ION_LS2_I1ON_LS2_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_LS2_I1ON_LS2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->ION_LS2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_ION_LS2_I1ON_LS2_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_ION_LS2_I1ON_LS2_POS) &
           (uint16)TLE9186_ION_LS2_I1ON_LS2_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_LS2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for ION_LS2_I1ON_LS2.
 *
 * This function returns the value of the bitfield LS2 Gate Driver pre-charge
 * current setting within register ION_LS2.
 *
 * @return Value of the bitfield ION_LS2_I1ON_LS2:
 *      - 0: ION_LS2_I1ON_LS2_CONST_0 (ICHG0).
 *      - 63: ION_LS2_I1ON_LS2_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_ION_LS2_I1ON_LS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->ION_LS2.bit.I1ON_LS2;
}

/**
 * @brief get function for register ION_LS2.
 *
 * This function reads the register Gate driver Configuration register -
 * ION_LS2.
 *
 */
void TLE9186_FuncLayer_get_ION_LS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_ION_LS2();
}

/**
 * @brief Set function for register ION_HS3.
 *
 * This function sets the Gate driver Configuration register - ION_HS3.
 *
 * @param u16_value Value to be written into the register ION_HS3.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_HS3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_HS3;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for ION_HS3_I2ON_HS3.
 *
 * This function sets the bitfield HS3 Gate Driver charge current setting in
 * register ION_HS3.
 *
 * @param u16_value Value to be written into ION_HS3_I2ON_HS3. Valid values are:
 *      - 0: ION_HS3_I2ON_HS3_CONST_0 (ICHG0).
 *      - 63: ION_HS3_I2ON_HS3_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_HS3_I2ON_HS3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->ION_HS3.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_ION_HS3_I2ON_HS3_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_ION_HS3_I2ON_HS3_POS) &
           (uint16)TLE9186_ION_HS3_I2ON_HS3_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_HS3;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for ION_HS3_I2ON_HS3.
 *
 * This function returns the value of the bitfield HS3 Gate Driver charge
 * current setting within register ION_HS3.
 *
 * @return Value of the bitfield ION_HS3_I2ON_HS3:
 *      - 0: ION_HS3_I2ON_HS3_CONST_0 (ICHG0).
 *      - 63: ION_HS3_I2ON_HS3_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_ION_HS3_I2ON_HS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->ION_HS3.bit.I2ON_HS3;
}

/**
 * @brief Set function for ION_HS3_I1ON_HS3.
 *
 * This function sets the bitfield HS3 Gate Driver pre-charge current setting in
 * register ION_HS3.
 *
 * @param u16_value Value to be written into ION_HS3_I1ON_HS3. Valid values are:
 *      - 0: ION_HS3_I1ON_HS3_CONST_0 (ICHG0).
 *      - 63: ION_HS3_I1ON_HS3_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_HS3_I1ON_HS3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->ION_HS3.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_ION_HS3_I1ON_HS3_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_ION_HS3_I1ON_HS3_POS) &
           (uint16)TLE9186_ION_HS3_I1ON_HS3_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_HS3;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for ION_HS3_I1ON_HS3.
 *
 * This function returns the value of the bitfield HS3 Gate Driver pre-charge
 * current setting within register ION_HS3.
 *
 * @return Value of the bitfield ION_HS3_I1ON_HS3:
 *      - 0: ION_HS3_I1ON_HS3_CONST_0 (ICHG0).
 *      - 63: ION_HS3_I1ON_HS3_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_ION_HS3_I1ON_HS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->ION_HS3.bit.I1ON_HS3;
}

/**
 * @brief get function for register ION_HS3.
 *
 * This function reads the register Gate driver Configuration register -
 * ION_HS3.
 *
 */
void TLE9186_FuncLayer_get_ION_HS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_ION_HS3();
}

/**
 * @brief Set function for register ION_LS3.
 *
 * This function sets the Gate driver Configuration register - ION_LS3.
 *
 * @param u16_value Value to be written into the register ION_LS3.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_LS3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_LS3;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for ION_LS3_I2ON_LS3.
 *
 * This function sets the bitfield LS3 Gate Driver charge current setting in
 * register ION_LS3.
 *
 * @param u16_value Value to be written into ION_LS3_I2ON_LS3. Valid values are:
 *      - 0: ION_LS3_I2ON_LS3_CONST_0 (ICHG0).
 *      - 63: ION_LS3_I2ON_LS3_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_LS3_I2ON_LS3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->ION_LS3.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_ION_LS3_I2ON_LS3_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_ION_LS3_I2ON_LS3_POS) &
           (uint16)TLE9186_ION_LS3_I2ON_LS3_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_LS3;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for ION_LS3_I2ON_LS3.
 *
 * This function returns the value of the bitfield LS3 Gate Driver charge
 * current setting within register ION_LS3.
 *
 * @return Value of the bitfield ION_LS3_I2ON_LS3:
 *      - 0: ION_LS3_I2ON_LS3_CONST_0 (ICHG0).
 *      - 63: ION_LS3_I2ON_LS3_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_ION_LS3_I2ON_LS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->ION_LS3.bit.I2ON_LS3;
}

/**
 * @brief Set function for ION_LS3_I1ON_LS3.
 *
 * This function sets the bitfield LS3 Gate Driver pre-charge current setting in
 * register ION_LS3.
 *
 * @param u16_value Value to be written into ION_LS3_I1ON_LS3. Valid values are:
 *      - 0: ION_LS3_I1ON_LS3_CONST_0 (ICHG0).
 *      - 63: ION_LS3_I1ON_LS3_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_LS3_I1ON_LS3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->ION_LS3.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_ION_LS3_I1ON_LS3_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_ION_LS3_I1ON_LS3_POS) &
           (uint16)TLE9186_ION_LS3_I1ON_LS3_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_LS3;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for ION_LS3_I1ON_LS3.
 *
 * This function returns the value of the bitfield LS3 Gate Driver pre-charge
 * current setting within register ION_LS3.
 *
 * @return Value of the bitfield ION_LS3_I1ON_LS3:
 *      - 0: ION_LS3_I1ON_LS3_CONST_0 (ICHG0).
 *      - 63: ION_LS3_I1ON_LS3_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_ION_LS3_I1ON_LS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->ION_LS3.bit.I1ON_LS3;
}

/**
 * @brief get function for register ION_LS3.
 *
 * This function reads the register Gate driver Configuration register -
 * ION_LS3.
 *
 */
void TLE9186_FuncLayer_get_ION_LS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_ION_LS3();
}

/**
 * @brief Set function for register I3ON.
 *
 * This function sets the Gate driver Configuration register - I3ON.
 *
 * @param u16_value Value to be written into the register I3ON.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_I3ON(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_I3ON;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for I3ON_I3ON_LS.
 *
 * This function sets the bitfield Low Side gate driver post-charge current
 * setting in register I3ON.
 *
 * @param u16_value Value to be written into I3ON_I3ON_LS. Valid values are:
 *      - 0: I3ON_I3ON_LS_CONST_0 (ICHG0).
 *      - 63: I3ON_I3ON_LS_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_I3ON_I3ON_LS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->I3ON.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_I3ON_I3ON_LS_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_I3ON_I3ON_LS_POS) &
           (uint16)TLE9186_I3ON_I3ON_LS_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_I3ON;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for I3ON_I3ON_LS.
 *
 * This function returns the value of the bitfield Low Side gate driver
 * post-charge current setting within register I3ON.
 *
 * @return Value of the bitfield I3ON_I3ON_LS:
 *      - 0: I3ON_I3ON_LS_CONST_0 (ICHG0).
 *      - 63: I3ON_I3ON_LS_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_I3ON_I3ON_LS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->I3ON.bit.I3ON_LS;
}

/**
 * @brief Set function for I3ON_I3ON_HS.
 *
 * This function sets the bitfield High Side gate driver post-charge current
 * setting in register I3ON.
 *
 * @param u16_value Value to be written into I3ON_I3ON_HS. Valid values are:
 *      - 0: I3ON_I3ON_HS_CONST_0 (ICHG0).
 *      - 63: I3ON_I3ON_HS_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_I3ON_I3ON_HS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->I3ON.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_I3ON_I3ON_HS_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_I3ON_I3ON_HS_POS) &
           (uint16)TLE9186_I3ON_I3ON_HS_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_I3ON;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for I3ON_I3ON_HS.
 *
 * This function returns the value of the bitfield High Side gate driver
 * post-charge current setting within register I3ON.
 *
 * @return Value of the bitfield I3ON_I3ON_HS:
 *      - 0: I3ON_I3ON_HS_CONST_0 (ICHG0).
 *      - 63: I3ON_I3ON_HS_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_I3ON_I3ON_HS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->I3ON.bit.I3ON_HS;
}

/**
 * @brief get function for register I3ON.
 *
 * This function reads the register Gate driver Configuration register - I3ON.
 *
 */
void TLE9186_FuncLayer_get_I3ON(void) /* polyspace MISRA2012:5.1 [Justified:
                                         Low] "Given due to register names" */
{
  TLE9186_RegLayer_get_I3ON();
}

/**
 * @brief Set function for register ION_IOFF_DIDT.
 *
 * This function sets the Gate driver Configuration register - ION_IOFF_DIDT.
 *
 * @param u16_value Value to be written into the register ION_IOFF_DIDT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_IOFF_DIDT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_IOFF_DIDT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for ION_IOFF_DIDT_IOFF.
 *
 * This function sets the bitfield Gate driver discharge current during dI/dT
 * phase in register ION_IOFF_DIDT.
 *
 * @param u16_value Value to be written into ION_IOFF_DIDT_IOFF. Valid values
 * are:
 *      - 0: ION_IOFF_DIDT_IOFF_CONST_0 (ICHG0).
 *      - 63: ION_IOFF_DIDT_IOFF_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_IOFF_DIDT_IOFF(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->ION_IOFF_DIDT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_ION_IOFF_DIDT_IOFF_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_ION_IOFF_DIDT_IOFF_POS) &
           (uint16)TLE9186_ION_IOFF_DIDT_IOFF_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_IOFF_DIDT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for ION_IOFF_DIDT_IOFF.
 *
 * This function returns the value of the bitfield Gate driver discharge current
 * during dI/dT phase within register ION_IOFF_DIDT.
 *
 * @return Value of the bitfield ION_IOFF_DIDT_IOFF:
 *      - 0: ION_IOFF_DIDT_IOFF_CONST_0 (ICHG0).
 *      - 63: ION_IOFF_DIDT_IOFF_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_ION_IOFF_DIDT_IOFF(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->ION_IOFF_DIDT.bit.IOFF;
}

/**
 * @brief Set function for ION_IOFF_DIDT_ION.
 *
 * This function sets the bitfield Gate driver charge current during dI/dT phase
 * in register ION_IOFF_DIDT.
 *
 * @param u16_value Value to be written into ION_IOFF_DIDT_ION. Valid values
 * are:
 *      - 0: ION_IOFF_DIDT_ION_CONST_0 (ICHG0).
 *      - 63: ION_IOFF_DIDT_ION_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_ION_IOFF_DIDT_ION(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->ION_IOFF_DIDT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_ION_IOFF_DIDT_ION_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_ION_IOFF_DIDT_ION_POS) &
           (uint16)TLE9186_ION_IOFF_DIDT_ION_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_ION_IOFF_DIDT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for ION_IOFF_DIDT_ION.
 *
 * This function returns the value of the bitfield Gate driver charge current
 * during dI/dT phase within register ION_IOFF_DIDT.
 *
 * @return Value of the bitfield ION_IOFF_DIDT_ION:
 *      - 0: ION_IOFF_DIDT_ION_CONST_0 (ICHG0).
 *      - 63: ION_IOFF_DIDT_ION_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_ION_IOFF_DIDT_ION(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->ION_IOFF_DIDT.bit.ION;
}

/**
 * @brief get function for register ION_IOFF_DIDT.
 *
 * This function reads the register Gate driver Configuration register -
 * ION_IOFF_DIDT.
 *
 */
void TLE9186_FuncLayer_get_ION_IOFF_DIDT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186_RegLayer_get_ION_IOFF_DIDT();
}

/**
 * @brief Set function for register IOFF_HS1.
 *
 * This function sets the Gate driver Configuration register - IOFF_HS1.
 *
 * @param u16_value Value to be written into the register IOFF_HS1.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_IOFF_HS1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_IOFF_HS1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for IOFF_HS1_I2OFF_HS1.
 *
 * This function sets the bitfield HS1 Gate Driver discharge current setting in
 * register IOFF_HS1.
 *
 * @param u16_value Value to be written into IOFF_HS1_I2OFF_HS1. Valid values
 * are:
 *      - 0: IOFF_HS1_I2OFF_HS1_CONST_0 (ICHG0).
 *      - 63: IOFF_HS1_I2OFF_HS1_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_IOFF_HS1_I2OFF_HS1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->IOFF_HS1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_IOFF_HS1_I2OFF_HS1_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_IOFF_HS1_I2OFF_HS1_POS) &
           (uint16)TLE9186_IOFF_HS1_I2OFF_HS1_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_IOFF_HS1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for IOFF_HS1_I2OFF_HS1.
 *
 * This function returns the value of the bitfield HS1 Gate Driver discharge
 * current setting within register IOFF_HS1.
 *
 * @return Value of the bitfield IOFF_HS1_I2OFF_HS1:
 *      - 0: IOFF_HS1_I2OFF_HS1_CONST_0 (ICHG0).
 *      - 63: IOFF_HS1_I2OFF_HS1_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_IOFF_HS1_I2OFF_HS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->IOFF_HS1.bit.I2OFF_HS1;
}

/**
 * @brief Set function for IOFF_HS1_I1OFF_HS1.
 *
 * This function sets the bitfield HS1 Gate Driver pre-discharge current setting
 * in register IOFF_HS1.
 *
 * @param u16_value Value to be written into IOFF_HS1_I1OFF_HS1. Valid values
 * are:
 *      - 0: IOFF_HS1_I1OFF_HS1_CONST_0 (ICHG0).
 *      - 63: IOFF_HS1_I1OFF_HS1_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_IOFF_HS1_I1OFF_HS1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->IOFF_HS1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_IOFF_HS1_I1OFF_HS1_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_IOFF_HS1_I1OFF_HS1_POS) &
           (uint16)TLE9186_IOFF_HS1_I1OFF_HS1_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_IOFF_HS1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for IOFF_HS1_I1OFF_HS1.
 *
 * This function returns the value of the bitfield HS1 Gate Driver pre-discharge
 * current setting within register IOFF_HS1.
 *
 * @return Value of the bitfield IOFF_HS1_I1OFF_HS1:
 *      - 0: IOFF_HS1_I1OFF_HS1_CONST_0 (ICHG0).
 *      - 63: IOFF_HS1_I1OFF_HS1_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_IOFF_HS1_I1OFF_HS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->IOFF_HS1.bit.I1OFF_HS1;
}

/**
 * @brief Set function for IOFF_HS1_ION_HS_BNK.
 *
 * This function sets the bitfield Banking configuration of I1ON, I2ON HS charge
 * current in register IOFF_HS1.
 *
 * @param u16_value Value to be written into IOFF_HS1_ION_HS_BNK. Valid values
 * are:
 *      - 0: IOFF_HS1_IOFF_HS_BNK_CONST_0 (I1OFF_HS1 pre-discharge current
 * settings applied for all 3x HS MOSFET gate drivers\nI2OFF_HS1 discharge
 * current setting applied only for all 3xHS MOSFET gate drivers (Default)).
 *      - 1: IOFF_HS1_IOFF_HS_BNK_CONST_1 (reserved).
 *      - 2: IOFF_HS1_IOFF_HS_BNK_CONST_2 (reserved).
 *      - 3: IOFF_HS1_IOFF_HS_BNK_CONST_3 (I1OFF_HS1 pre-discharge current
 * setting applied only for HS1 MOSFET gate driver\nI2OFF_HS1 discharge current
 * setting applied only for HS1 MOSFET gate driver).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_IOFF_HS1_ION_HS_BNK(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->IOFF_HS1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_IOFF_HS1_ION_HS_BNK_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_IOFF_HS1_ION_HS_BNK_POS) &
           (uint16)TLE9186_IOFF_HS1_ION_HS_BNK_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_IOFF_HS1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for IOFF_HS1_ION_HS_BNK.
 *
 * This function returns the value of the bitfield Banking configuration of
 * I1ON, I2ON HS charge current within register IOFF_HS1.
 *
 * @return Value of the bitfield IOFF_HS1_ION_HS_BNK:
 *      - 0: IOFF_HS1_IOFF_HS_BNK_CONST_0 (I1OFF_HS1 pre-discharge current
 * settings applied for all 3x HS MOSFET gate drivers\nI2OFF_HS1 discharge
 * current setting applied only for all 3xHS MOSFET gate drivers (Default)).
 *      - 1: IOFF_HS1_IOFF_HS_BNK_CONST_1 (reserved).
 *      - 2: IOFF_HS1_IOFF_HS_BNK_CONST_2 (reserved).
 *      - 3: IOFF_HS1_IOFF_HS_BNK_CONST_3 (I1OFF_HS1 pre-discharge current
 * setting applied only for HS1 MOSFET gate driver\nI2OFF_HS1 discharge current
 * setting applied only for HS1 MOSFET gate driver).
 */
uint16 TLE9186_FuncLayer_get_IOFF_HS1_ION_HS_BNK(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->IOFF_HS1.bit.ION_HS_BNK;
}

/**
 * @brief get function for register IOFF_HS1.
 *
 * This function reads the register Gate driver Configuration register -
 * IOFF_HS1.
 *
 */
void TLE9186_FuncLayer_get_IOFF_HS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_IOFF_HS1();
}

/**
 * @brief Set function for register IOFF_LS1.
 *
 * This function sets the Gate driver Configuration register - IOFF_LS1.
 *
 * @param u16_value Value to be written into the register IOFF_LS1.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_IOFF_LS1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_IOFF_LS1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for IOFF_LS1_I2OFF_LS1.
 *
 * This function sets the bitfield LS1 Gate Driver discharge current setting in
 * register IOFF_LS1.
 *
 * @param u16_value Value to be written into IOFF_LS1_I2OFF_LS1. Valid values
 * are:
 *      - 0: IOFF_LS1_I2OFF_LS1_CONST_0 (ICHG0).
 *      - 63: IOFF_LS1_I2OFF_LS1_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_IOFF_LS1_I2OFF_LS1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->IOFF_LS1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_IOFF_LS1_I2OFF_LS1_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_IOFF_LS1_I2OFF_LS1_POS) &
           (uint16)TLE9186_IOFF_LS1_I2OFF_LS1_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_IOFF_LS1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for IOFF_LS1_I2OFF_LS1.
 *
 * This function returns the value of the bitfield LS1 Gate Driver discharge
 * current setting within register IOFF_LS1.
 *
 * @return Value of the bitfield IOFF_LS1_I2OFF_LS1:
 *      - 0: IOFF_LS1_I2OFF_LS1_CONST_0 (ICHG0).
 *      - 63: IOFF_LS1_I2OFF_LS1_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_IOFF_LS1_I2OFF_LS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->IOFF_LS1.bit.I2OFF_LS1;
}

/**
 * @brief Set function for IOFF_LS1_I1OFF_LS1.
 *
 * This function sets the bitfield LS1 Gate Driver pre-discharge current setting
 * in register IOFF_LS1.
 *
 * @param u16_value Value to be written into IOFF_LS1_I1OFF_LS1. Valid values
 * are:
 *      - 0: IOFF_LS1_I1OFF_LS1_CONST_0 (ICHG0).
 *      - 63: IOFF_LS1_I1OFF_LS1_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_IOFF_LS1_I1OFF_LS1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->IOFF_LS1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_IOFF_LS1_I1OFF_LS1_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_IOFF_LS1_I1OFF_LS1_POS) &
           (uint16)TLE9186_IOFF_LS1_I1OFF_LS1_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_IOFF_LS1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for IOFF_LS1_I1OFF_LS1.
 *
 * This function returns the value of the bitfield LS1 Gate Driver pre-discharge
 * current setting within register IOFF_LS1.
 *
 * @return Value of the bitfield IOFF_LS1_I1OFF_LS1:
 *      - 0: IOFF_LS1_I1OFF_LS1_CONST_0 (ICHG0).
 *      - 63: IOFF_LS1_I1OFF_LS1_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_IOFF_LS1_I1OFF_LS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->IOFF_LS1.bit.I1OFF_LS1;
}

/**
 * @brief Set function for IOFF_LS1_IOFF_LS_BNK.
 *
 * This function sets the bitfield Banking configuration of I1OFF, I2OFF LS
 * discharge current in register IOFF_LS1.
 *
 * @param u16_value Value to be written into IOFF_LS1_IOFF_LS_BNK. Valid values
 * are:
 *      - 0: IOFF_LS1_IOFF_LS_BNK_CONST_0 (I1OFF_LS1 pre-discharge current
 * settings applied for all 3x LS MOSFET gate drivers\nI2OFF_LS1 discharge
 * current setting applied only for all 3x LS MOSFET gate drivers (Default)).
 *      - 1: IOFF_LS1_IOFF_LS_BNK_CONST_1 (reserved).
 *      - 2: IOFF_LS1_IOFF_LS_BNK_CONST_2 (reserved).
 *      - 3: IOFF_LS1_IOFF_LS_BNK_CONST_3 (I1OFF_LS1 pre-discharge current
 * setting applied only for LS1 MOSFET gate driver\nI2OFF_LS1 discharge current
 * setting applied only for LS1 MOSFET gate driver).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_IOFF_LS1_IOFF_LS_BNK(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->IOFF_LS1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_IOFF_LS1_IOFF_LS_BNK_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_IOFF_LS1_IOFF_LS_BNK_POS) &
           (uint16)TLE9186_IOFF_LS1_IOFF_LS_BNK_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_IOFF_LS1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for IOFF_LS1_IOFF_LS_BNK.
 *
 * This function returns the value of the bitfield Banking configuration of
 * I1OFF, I2OFF LS discharge current within register IOFF_LS1.
 *
 * @return Value of the bitfield IOFF_LS1_IOFF_LS_BNK:
 *      - 0: IOFF_LS1_IOFF_LS_BNK_CONST_0 (I1OFF_LS1 pre-discharge current
 * settings applied for all 3x LS MOSFET gate drivers\nI2OFF_LS1 discharge
 * current setting applied only for all 3x LS MOSFET gate drivers (Default)).
 *      - 1: IOFF_LS1_IOFF_LS_BNK_CONST_1 (reserved).
 *      - 2: IOFF_LS1_IOFF_LS_BNK_CONST_2 (reserved).
 *      - 3: IOFF_LS1_IOFF_LS_BNK_CONST_3 (I1OFF_LS1 pre-discharge current
 * setting applied only for LS1 MOSFET gate driver\nI2OFF_LS1 discharge current
 * setting applied only for LS1 MOSFET gate driver).
 */
uint16 TLE9186_FuncLayer_get_IOFF_LS1_IOFF_LS_BNK(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->IOFF_LS1.bit.IOFF_LS_BNK;
}

/**
 * @brief get function for register IOFF_LS1.
 *
 * This function reads the register Gate driver Configuration register -
 * IOFF_LS1.
 *
 */
void TLE9186_FuncLayer_get_IOFF_LS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_IOFF_LS1();
}

/**
 * @brief Set function for register IOFF_HS2.
 *
 * This function sets the Gate driver Configuration register - IOFF_HS2.
 *
 * @param u16_value Value to be written into the register IOFF_HS2.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_IOFF_HS2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_IOFF_HS2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for IOFF_HS2_I2OFF_HS2.
 *
 * This function sets the bitfield HS2 Gate Driver discharge current setting in
 * register IOFF_HS2.
 *
 * @param u16_value Value to be written into IOFF_HS2_I2OFF_HS2. Valid values
 * are:
 *      - 0: IOFF_HS2_I2OFF_HS2_CONST_0 (ICHG0).
 *      - 63: IOFF_HS2_I2OFF_HS2_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_IOFF_HS2_I2OFF_HS2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->IOFF_HS2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_IOFF_HS2_I2OFF_HS2_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_IOFF_HS2_I2OFF_HS2_POS) &
           (uint16)TLE9186_IOFF_HS2_I2OFF_HS2_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_IOFF_HS2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for IOFF_HS2_I2OFF_HS2.
 *
 * This function returns the value of the bitfield HS2 Gate Driver discharge
 * current setting within register IOFF_HS2.
 *
 * @return Value of the bitfield IOFF_HS2_I2OFF_HS2:
 *      - 0: IOFF_HS2_I2OFF_HS2_CONST_0 (ICHG0).
 *      - 63: IOFF_HS2_I2OFF_HS2_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_IOFF_HS2_I2OFF_HS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->IOFF_HS2.bit.I2OFF_HS2;
}

/**
 * @brief Set function for IOFF_HS2_I1OFF_HS2.
 *
 * This function sets the bitfield HS2 Gate Driver pre-discharge current setting
 * in register IOFF_HS2.
 *
 * @param u16_value Value to be written into IOFF_HS2_I1OFF_HS2. Valid values
 * are:
 *      - 0: IOFF_HS2_I1OFF_HS2_CONST_0 (ICHG0).
 *      - 63: IOFF_HS2_I1OFF_HS2_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_IOFF_HS2_I1OFF_HS2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->IOFF_HS2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_IOFF_HS2_I1OFF_HS2_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_IOFF_HS2_I1OFF_HS2_POS) &
           (uint16)TLE9186_IOFF_HS2_I1OFF_HS2_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_IOFF_HS2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for IOFF_HS2_I1OFF_HS2.
 *
 * This function returns the value of the bitfield HS2 Gate Driver pre-discharge
 * current setting within register IOFF_HS2.
 *
 * @return Value of the bitfield IOFF_HS2_I1OFF_HS2:
 *      - 0: IOFF_HS2_I1OFF_HS2_CONST_0 (ICHG0).
 *      - 63: IOFF_HS2_I1OFF_HS2_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_IOFF_HS2_I1OFF_HS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->IOFF_HS2.bit.I1OFF_HS2;
}

/**
 * @brief get function for register IOFF_HS2.
 *
 * This function reads the register Gate driver Configuration register -
 * IOFF_HS2.
 *
 */
void TLE9186_FuncLayer_get_IOFF_HS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_IOFF_HS2();
}

/**
 * @brief Set function for register IOFF_LS2.
 *
 * This function sets the Gate driver Configuration register - IOFF_LS2.
 *
 * @param u16_value Value to be written into the register IOFF_LS2.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_IOFF_LS2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_IOFF_LS2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for IOFF_LS2_I2OFF_LS2.
 *
 * This function sets the bitfield LS2 Gate Driver discharge current setting in
 * register IOFF_LS2.
 *
 * @param u16_value Value to be written into IOFF_LS2_I2OFF_LS2. Valid values
 * are:
 *      - 0: IOFF_LS2_I2OFF_LS2_CONST_0 (ICHG0).
 *      - 63: IOFF_LS2_I2OFF_LS2_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_IOFF_LS2_I2OFF_LS2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->IOFF_LS2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_IOFF_LS2_I2OFF_LS2_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_IOFF_LS2_I2OFF_LS2_POS) &
           (uint16)TLE9186_IOFF_LS2_I2OFF_LS2_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_IOFF_LS2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for IOFF_LS2_I2OFF_LS2.
 *
 * This function returns the value of the bitfield LS2 Gate Driver discharge
 * current setting within register IOFF_LS2.
 *
 * @return Value of the bitfield IOFF_LS2_I2OFF_LS2:
 *      - 0: IOFF_LS2_I2OFF_LS2_CONST_0 (ICHG0).
 *      - 63: IOFF_LS2_I2OFF_LS2_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_IOFF_LS2_I2OFF_LS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->IOFF_LS2.bit.I2OFF_LS2;
}

/**
 * @brief Set function for IOFF_LS2_I1OFF_LS2.
 *
 * This function sets the bitfield LS2 Gate Driver pre-discharge current setting
 * in register IOFF_LS2.
 *
 * @param u16_value Value to be written into IOFF_LS2_I1OFF_LS2. Valid values
 * are:
 *      - 0: IOFF_LS2_I1OFF_LS2_CONST_0 (ICHG0).
 *      - 63: IOFF_LS2_I1OFF_LS2_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_IOFF_LS2_I1OFF_LS2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->IOFF_LS2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_IOFF_LS2_I1OFF_LS2_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_IOFF_LS2_I1OFF_LS2_POS) &
           (uint16)TLE9186_IOFF_LS2_I1OFF_LS2_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_IOFF_LS2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for IOFF_LS2_I1OFF_LS2.
 *
 * This function returns the value of the bitfield LS2 Gate Driver pre-discharge
 * current setting within register IOFF_LS2.
 *
 * @return Value of the bitfield IOFF_LS2_I1OFF_LS2:
 *      - 0: IOFF_LS2_I1OFF_LS2_CONST_0 (ICHG0).
 *      - 63: IOFF_LS2_I1OFF_LS2_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_IOFF_LS2_I1OFF_LS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->IOFF_LS2.bit.I1OFF_LS2;
}

/**
 * @brief get function for register IOFF_LS2.
 *
 * This function reads the register Gate driver Configuration register -
 * IOFF_LS2.
 *
 */
void TLE9186_FuncLayer_get_IOFF_LS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_IOFF_LS2();
}

/**
 * @brief Set function for register IOFF_HS3.
 *
 * This function sets the Gate driver Configuration register - IOFF_HS3.
 *
 * @param u16_value Value to be written into the register IOFF_HS3.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_IOFF_HS3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_IOFF_HS3;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for IOFF_HS3_I2OFF_HS3.
 *
 * This function sets the bitfield HS3 Gate Driver discharge current setting in
 * register IOFF_HS3.
 *
 * @param u16_value Value to be written into IOFF_HS3_I2OFF_HS3. Valid values
 * are:
 *      - 0: IOFF_HS3_I2OFF_HS3_CONST_0 (ICHG0).
 *      - 63: IOFF_HS3_I2OFF_HS3_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_IOFF_HS3_I2OFF_HS3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->IOFF_HS3.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_IOFF_HS3_I2OFF_HS3_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_IOFF_HS3_I2OFF_HS3_POS) &
           (uint16)TLE9186_IOFF_HS3_I2OFF_HS3_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_IOFF_HS3;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for IOFF_HS3_I2OFF_HS3.
 *
 * This function returns the value of the bitfield HS3 Gate Driver discharge
 * current setting within register IOFF_HS3.
 *
 * @return Value of the bitfield IOFF_HS3_I2OFF_HS3:
 *      - 0: IOFF_HS3_I2OFF_HS3_CONST_0 (ICHG0).
 *      - 63: IOFF_HS3_I2OFF_HS3_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_IOFF_HS3_I2OFF_HS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->IOFF_HS3.bit.I2OFF_HS3;
}

/**
 * @brief Set function for IOFF_HS3_I1OFF_HS3.
 *
 * This function sets the bitfield HS3 Gate Driver pre-discharge current setting
 * in register IOFF_HS3.
 *
 * @param u16_value Value to be written into IOFF_HS3_I1OFF_HS3. Valid values
 * are:
 *      - 0: IOFF_HS3_I1OFF_HS3_CONST_0 (ICHG0).
 *      - 63: IOFF_HS3_I1OFF_HS3_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_IOFF_HS3_I1OFF_HS3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->IOFF_HS3.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_IOFF_HS3_I1OFF_HS3_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_IOFF_HS3_I1OFF_HS3_POS) &
           (uint16)TLE9186_IOFF_HS3_I1OFF_HS3_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_IOFF_HS3;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for IOFF_HS3_I1OFF_HS3.
 *
 * This function returns the value of the bitfield HS3 Gate Driver pre-discharge
 * current setting within register IOFF_HS3.
 *
 * @return Value of the bitfield IOFF_HS3_I1OFF_HS3:
 *      - 0: IOFF_HS3_I1OFF_HS3_CONST_0 (ICHG0).
 *      - 63: IOFF_HS3_I1OFF_HS3_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_IOFF_HS3_I1OFF_HS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->IOFF_HS3.bit.I1OFF_HS3;
}

/**
 * @brief get function for register IOFF_HS3.
 *
 * This function reads the register Gate driver Configuration register -
 * IOFF_HS3.
 *
 */
void TLE9186_FuncLayer_get_IOFF_HS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_IOFF_HS3();
}

/**
 * @brief Set function for register IOFF_LS3.
 *
 * This function sets the Gate driver Configuration register - IOFF_LS3.
 *
 * @param u16_value Value to be written into the register IOFF_LS3.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_IOFF_LS3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_IOFF_LS3;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for IOFF_LS3_I2OFF_LS3.
 *
 * This function sets the bitfield LS3 Gate Driver discharge current setting in
 * register IOFF_LS3.
 *
 * @param u16_value Value to be written into IOFF_LS3_I2OFF_LS3. Valid values
 * are:
 *      - 0: IOFF_LS3_I2OFF_LS3_CONST_0 (ICHG0).
 *      - 63: IOFF_LS3_I2OFF_LS3_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_IOFF_LS3_I2OFF_LS3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->IOFF_LS3.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_IOFF_LS3_I2OFF_LS3_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_IOFF_LS3_I2OFF_LS3_POS) &
           (uint16)TLE9186_IOFF_LS3_I2OFF_LS3_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_IOFF_LS3;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for IOFF_LS3_I2OFF_LS3.
 *
 * This function returns the value of the bitfield LS3 Gate Driver discharge
 * current setting within register IOFF_LS3.
 *
 * @return Value of the bitfield IOFF_LS3_I2OFF_LS3:
 *      - 0: IOFF_LS3_I2OFF_LS3_CONST_0 (ICHG0).
 *      - 63: IOFF_LS3_I2OFF_LS3_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_IOFF_LS3_I2OFF_LS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->IOFF_LS3.bit.I2OFF_LS3;
}

/**
 * @brief Set function for IOFF_LS3_I1OFF_LS3.
 *
 * This function sets the bitfield LS3 Gate Driver pre-discharge current setting
 * in register IOFF_LS3.
 *
 * @param u16_value Value to be written into IOFF_LS3_I1OFF_LS3. Valid values
 * are:
 *      - 0: IOFF_LS3_I1OFF_LS3_CONST_0 (ICHG0).
 *      - 63: IOFF_LS3_I1OFF_LS3_CONST_63 (ICHG63).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_IOFF_LS3_I1OFF_LS3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->IOFF_LS3.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_IOFF_LS3_I1OFF_LS3_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_IOFF_LS3_I1OFF_LS3_POS) &
           (uint16)TLE9186_IOFF_LS3_I1OFF_LS3_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_IOFF_LS3;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for IOFF_LS3_I1OFF_LS3.
 *
 * This function returns the value of the bitfield LS3 Gate Driver pre-discharge
 * current setting within register IOFF_LS3.
 *
 * @return Value of the bitfield IOFF_LS3_I1OFF_LS3:
 *      - 0: IOFF_LS3_I1OFF_LS3_CONST_0 (ICHG0).
 *      - 63: IOFF_LS3_I1OFF_LS3_CONST_63 (ICHG63).
 */
uint16 TLE9186_FuncLayer_get_IOFF_LS3_I1OFF_LS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->IOFF_LS3.bit.I1OFF_LS3;
}

/**
 * @brief get function for register IOFF_LS3.
 *
 * This function reads the register Gate driver Configuration register -
 * IOFF_LS3.
 *
 */
void TLE9186_FuncLayer_get_IOFF_LS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_IOFF_LS3();
}

/**
 * @brief Set function for register CSA_CFG.
 *
 * This function sets the Current sense amplifier configuration register.
 *
 * @param u16_value Value to be written into the register CSA_CFG.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_CSA_CFG(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_CSA_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for CSA_CFG_CSA_TFOC.
 *
 * This function sets the bitfield Current sense amplifier overcurrent filter
 * time setting in register CSA_CFG.
 *
 * @param u16_value Value to be written into CSA_CFG_CSA_TFOC. Valid values are:
 *      - 0: CSA_CFG_CSA_TFOC_CONST_0 (3us).
 *      - 1: CSA_CFG_CSA_TFOC_CONST_1 (6us (Default)).
 *      - 2: CSA_CFG_CSA_TFOC_CONST_2 (10us).
 *      - 3: CSA_CFG_CSA_TFOC_CONST_3 (50us).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_CSA_CFG_CSA_TFOC(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->CSA_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_CSA_CFG_CSA_TFOC_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_CSA_CFG_CSA_TFOC_POS) &
           (uint16)TLE9186_CSA_CFG_CSA_TFOC_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_CSA_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for CSA_CFG_CSA_TFOC.
 *
 * This function returns the value of the bitfield Current sense amplifier
 * overcurrent filter time setting within register CSA_CFG.
 *
 * @return Value of the bitfield CSA_CFG_CSA_TFOC:
 *      - 0: CSA_CFG_CSA_TFOC_CONST_0 (3us).
 *      - 1: CSA_CFG_CSA_TFOC_CONST_1 (6us (Default)).
 *      - 2: CSA_CFG_CSA_TFOC_CONST_2 (10us).
 *      - 3: CSA_CFG_CSA_TFOC_CONST_3 (50us).
 */
uint16 TLE9186_FuncLayer_get_CSA_CFG_CSA_TFOC(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->CSA_CFG.bit.CSA_TFOC;
}

/**
 * @brief Set function for CSA_CFG_CSA_OC_TH.
 *
 * This function sets the bitfield Current sense amplifier overcurrent detection
 * threshold in register CSA_CFG.
 *
 * @param u16_value Value to be written into CSA_CFG_CSA_OC_TH. Valid values
 * are:
 *      - 0: CSA_CFG_CSA_OC_TH_CONST_0 (0.75xVREF and 0.25xVREF threshold
 * settings (Default)).
 *      - 1: CSA_CFG_CS1_OC_TH_CONST_1 (0.8xVREF and 0.25xVREF threshold
 * settings).
 *      - 2: CSA_CFG_CSA_OC_TH_CONST_2 (0.85xVREF and 0.25xVREF threshold
 * settings).
 *      - 3: CSA_CFG_CSA_OC_TH_CONST_3 (0.9xVREF and 0.25xVREF threshold
 * settings).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_CSA_CFG_CSA_OC_TH(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->CSA_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_CSA_CFG_CSA_OC_TH_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_CSA_CFG_CSA_OC_TH_POS) &
           (uint16)TLE9186_CSA_CFG_CSA_OC_TH_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_CSA_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for CSA_CFG_CSA_OC_TH.
 *
 * This function returns the value of the bitfield Current sense amplifier
 * overcurrent detection threshold within register CSA_CFG.
 *
 * @return Value of the bitfield CSA_CFG_CSA_OC_TH:
 *      - 0: CSA_CFG_CSA_OC_TH_CONST_0 (0.75xVREF and 0.25xVREF threshold
 * settings (Default)).
 *      - 1: CSA_CFG_CS1_OC_TH_CONST_1 (0.8xVREF and 0.25xVREF threshold
 * settings).
 *      - 2: CSA_CFG_CSA_OC_TH_CONST_2 (0.85xVREF and 0.25xVREF threshold
 * settings).
 *      - 3: CSA_CFG_CSA_OC_TH_CONST_3 (0.9xVREF and 0.25xVREF threshold
 * settings).
 */
uint16 TLE9186_FuncLayer_get_CSA_CFG_CSA_OC_TH(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->CSA_CFG.bit.CSA_OC_TH;
}

/**
 * @brief Set function for CSA_CFG_CSA_CLOAD.
 *
 * This function sets the bitfield Current sense amplifier output capacitive
 * load range in register CSA_CFG.
 *
 * @param u16_value Value to be written into CSA_CFG_CSA_CLOAD. Valid values
 * are:
 *      - 0: CSA_CFG_CSA_CLOAD_CONST_0 (CSA output capacitive load CLOAD
 * <400pF).
 *      - 1: CSA_CFG_CSA_CLOAD_CONST_1 (CSA output capacitive load ~2.2nF
 * (Default)).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_CSA_CFG_CSA_CLOAD(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->CSA_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_CSA_CFG_CSA_CLOAD_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_CSA_CFG_CSA_CLOAD_POS) &
           (uint16)TLE9186_CSA_CFG_CSA_CLOAD_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_CSA_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for CSA_CFG_CSA_CLOAD.
 *
 * This function returns the value of the bitfield Current sense amplifier
 * output capacitive load range within register CSA_CFG.
 *
 * @return Value of the bitfield CSA_CFG_CSA_CLOAD:
 *      - 0: CSA_CFG_CSA_CLOAD_CONST_0 (CSA output capacitive load CLOAD
 * <400pF).
 *      - 1: CSA_CFG_CSA_CLOAD_CONST_1 (CSA output capacitive load ~2.2nF
 * (Default)).
 */
uint16 TLE9186_FuncLayer_get_CSA_CFG_CSA_CLOAD(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->CSA_CFG.bit.CSA_CLOAD;
}

/**
 * @brief Set function for CSA_CFG_CSA_DIR.
 *
 * This function sets the bitfield Direction of current sense amplifier in
 * register CSA_CFG.
 *
 * @param u16_value Value to be written into CSA_CFG_CSA_DIR. Valid values are:
 *      - 0: CSA_CFG_CSA_DIR_CONST_0 (unidirectional current measurement).
 *      - 1: CSA_CFG_CSA_DIR_CONST_1 (bidirectional current measurement
 * (Default)).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_CSA_CFG_CSA_DIR(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->CSA_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_CSA_CFG_CSA_DIR_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_CSA_CFG_CSA_DIR_POS) &
           (uint16)TLE9186_CSA_CFG_CSA_DIR_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_CSA_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for CSA_CFG_CSA_DIR.
 *
 * This function returns the value of the bitfield Direction of current sense
 * amplifier within register CSA_CFG.
 *
 * @return Value of the bitfield CSA_CFG_CSA_DIR:
 *      - 0: CSA_CFG_CSA_DIR_CONST_0 (unidirectional current measurement).
 *      - 1: CSA_CFG_CSA_DIR_CONST_1 (bidirectional current measurement
 * (Default)).
 */
uint16 TLE9186_FuncLayer_get_CSA_CFG_CSA_DIR(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->CSA_CFG.bit.CSA_DIR;
}

/**
 * @brief Set function for CSA_CFG_CSA_GAIN.
 *
 * This function sets the bitfield Current sense amplifier differential gain
 * configuration in register CSA_CFG.
 *
 * @param u16_value Value to be written into CSA_CFG_CSA_GAIN. Valid values are:
 *      - 0: CSA_CFG_CSA_GAIN_CONST_0 (Differential gain 6V/V selected).
 *      - 1: CSA_CFG_CSA_GAIN_CONST_1 (Differential gain 8V/V selected
 * (Default)).
 *      - 2: CSA_CFG_CSA_GAIN_CONST_2 (Differential gain 10V/V selected).
 *      - 3: CSA_CFG_CSA_GAIN_CONST_3 (Differential gain 15V/V selected ).
 *      - 4: CSA_CFG_CSA_GAIN_CONST_4 (Differential gain 24V/V selected).
 *      - 5: CSA_CFG_CSA_GAIN_CONST_5 (Differential gain 40V/V selected).
 *      - 6: CSA_CFG_CSA_GAIN_CONST_6 (reserved).
 *      - 7: CSA_CFG_CSA_GAIN_CONST_7 (reserved).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_CSA_CFG_CSA_GAIN(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->CSA_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_CSA_CFG_CSA_GAIN_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_CSA_CFG_CSA_GAIN_POS) &
           (uint16)TLE9186_CSA_CFG_CSA_GAIN_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_CSA_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for CSA_CFG_CSA_GAIN.
 *
 * This function returns the value of the bitfield Current sense amplifier
 * differential gain configuration within register CSA_CFG.
 *
 * @return Value of the bitfield CSA_CFG_CSA_GAIN:
 *      - 0: CSA_CFG_CSA_GAIN_CONST_0 (Differential gain 6V/V selected).
 *      - 1: CSA_CFG_CSA_GAIN_CONST_1 (Differential gain 8V/V selected
 * (Default)).
 *      - 2: CSA_CFG_CSA_GAIN_CONST_2 (Differential gain 10V/V selected).
 *      - 3: CSA_CFG_CSA_GAIN_CONST_3 (Differential gain 15V/V selected ).
 *      - 4: CSA_CFG_CSA_GAIN_CONST_4 (Differential gain 24V/V selected).
 *      - 5: CSA_CFG_CSA_GAIN_CONST_5 (Differential gain 40V/V selected).
 *      - 6: CSA_CFG_CSA_GAIN_CONST_6 (reserved).
 *      - 7: CSA_CFG_CSA_GAIN_CONST_7 (reserved).
 */
uint16 TLE9186_FuncLayer_get_CSA_CFG_CSA_GAIN(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->CSA_CFG.bit.CSA_GAIN;
}

/**
 * @brief Set function for CSA_CFG_CSA_GAIN_TST.
 *
 * This function sets the bitfield CSA gain accuracy check in register CSA_CFG.
 *
 * @param u16_value Value to be written into CSA_CFG_CSA_GAIN_TST. Valid values
 * are:
 *      - 0: CSA_CFG_CSA_GAIN_TST_CONST_0 (gain accuracy check disabled
 * (Default)).
 *      - 1: CSA_CFG_CSA_GAIN_TST_CONST_1 (gain accuracy check enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_CSA_CFG_CSA_GAIN_TST(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->CSA_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_CSA_CFG_CSA_GAIN_TST_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_CSA_CFG_CSA_GAIN_TST_POS) &
           (uint16)TLE9186_CSA_CFG_CSA_GAIN_TST_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_CSA_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for CSA_CFG_CSA_GAIN_TST.
 *
 * This function returns the value of the bitfield CSA gain accuracy check
 * within register CSA_CFG.
 *
 * @return Value of the bitfield CSA_CFG_CSA_GAIN_TST:
 *      - 0: CSA_CFG_CSA_GAIN_TST_CONST_0 (gain accuracy check disabled
 * (Default)).
 *      - 1: CSA_CFG_CSA_GAIN_TST_CONST_1 (gain accuracy check enabled).
 */
uint16 TLE9186_FuncLayer_get_CSA_CFG_CSA_GAIN_TST(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->CSA_CFG.bit.CSA_GAIN_TST;
}

/**
 * @brief Set function for CSA_CFG_CSO_MUX.
 *
 * This function sets the bitfield Current Sense Amplifier Output redirection of
 * digital PFB signals in register CSA_CFG.
 *
 * @param u16_value Value to be written into CSA_CFG_CSO_MUX. Valid values are:
 *      - 0: CSA_CFG_CSO_MUX_CONST_0 (CSA normal functionality (Default)).
 *      - 1: CSA_CFG_CSO_MUX_CONST_1 (PFB1 redirected to CSO output).
 *      - 2: CSA_CFG_CSO_MUX_CONST_2 (PFB2 redirected to CSO output).
 *      - 3: CSA_CFG_CSO_MUX_CONST_3 (PFB3 redirected to CSO output).
 *      - 4: CSA_CFG_CSO_MUX_CONST_4 (XOR of PFB1,2,3 redirected to CSO output).
 *      - 5: CSA_CFG_CSO_MUX_CONST_5 (reserved).
 *      - 6: CSA_CFG_CSO_MUX_CONST_6 (reserved).
 *      - 7: CSA_CFG_CSO_MUX_CONST_7 (reserved).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_CSA_CFG_CSO_MUX(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->CSA_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_CSA_CFG_CSO_MUX_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_CSA_CFG_CSO_MUX_POS) &
           (uint16)TLE9186_CSA_CFG_CSO_MUX_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_CSA_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for CSA_CFG_CSO_MUX.
 *
 * This function returns the value of the bitfield Current Sense Amplifier
 * Output redirection of digital PFB signals within register CSA_CFG.
 *
 * @return Value of the bitfield CSA_CFG_CSO_MUX:
 *      - 0: CSA_CFG_CSO_MUX_CONST_0 (CSA normal functionality (Default)).
 *      - 1: CSA_CFG_CSO_MUX_CONST_1 (PFB1 redirected to CSO output).
 *      - 2: CSA_CFG_CSO_MUX_CONST_2 (PFB2 redirected to CSO output).
 *      - 3: CSA_CFG_CSO_MUX_CONST_3 (PFB3 redirected to CSO output).
 *      - 4: CSA_CFG_CSO_MUX_CONST_4 (XOR of PFB1,2,3 redirected to CSO output).
 *      - 5: CSA_CFG_CSO_MUX_CONST_5 (reserved).
 *      - 6: CSA_CFG_CSO_MUX_CONST_6 (reserved).
 *      - 7: CSA_CFG_CSO_MUX_CONST_7 (reserved).
 */
uint16 TLE9186_FuncLayer_get_CSA_CFG_CSO_MUX(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->CSA_CFG.bit.CSO_MUX;
}

/**
 * @brief Set function for CSA_CFG_CSA_REC.
 *
 * This function sets the bitfield CSA recovery in case of VIO under-voltage
 *event  in register CSA_CFG.
 *
 * @param u16_value Value to be written into CSA_CFG_CSA_REC. Valid values are:
 *      - 0: CSA_CFG_CSA_REC_TST_CONST_0 (CSA automatic restart disabled
 *(default)).
 *      - 1: CSA_CFG_CSA_REC_TST_CONST_1 (CSA automatic restart enabled, CSA
 *restarts when VIO_UV event not present (independent of VIO_UV status bit)).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_CSA_CFG_CSA_REC(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->CSA_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_CSA_CFG_CSA_REC_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_CSA_CFG_CSA_REC_POS) &
           (uint16)TLE9186_CSA_CFG_CSA_REC_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_CSA_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for CSA_CFG_CSA_REC.
 *
 * This function returns the value of the bitfield CSA recovery in case of VIO
 *under-voltage event  within register CSA_CFG.
 *
 * @return Value of the bitfield CSA_CFG_CSA_REC:
 *      - 0: CSA_CFG_CSA_REC_TST_CONST_0 (CSA automatic restart disabled
 *(default)).
 *      - 1: CSA_CFG_CSA_REC_TST_CONST_1 (CSA automatic restart enabled, CSA
 *restarts when VIO_UV event not present (independent of VIO_UV status bit)).
 */
uint16 TLE9186_FuncLayer_get_CSA_CFG_CSA_REC(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->CSA_CFG.bit.CSA_REC;
}

/**
 * @brief get function for register CSA_CFG.
 *
 * This function reads the register Current sense amplifier configuration
 * register.
 *
 */
void TLE9186_FuncLayer_get_CSA_CFG(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_CSA_CFG();
}

/**
 * @brief Set function for register FAILURE_CFG.
 *
 * This function sets the Failure reaction configuration register 1.
 *
 * @param u16_value Value to be written into the register FAILURE_CFG.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_FAILURE_CFG(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_FAILURE_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for FAILURE_CFG_CSA_OC_FM.
 *
 * This function sets the bitfield Current sense amplifiers overcurrent failure
 * reaction in register FAILURE_CFG.
 *
 * @param u16_value Value to be written into FAILURE_CFG_CSA_OC_FM. Valid values
 * are:
 *      - 0: FAILURE_CFG_CSA_OC_FM_CONST_0 (latched error 1 (LE1) failure
 * reaction triggered (Default)).
 *      - 1: FAILURE_CFG_CSA_OC_FM_CONST_1 (error (E) failure reaction triggered
 * ).
 *      - 2: FAILURE_CFG_CSA_OC_FM_CONST_2 (warning (W) failure reaction
 * triggered).
 *      - 3: FAILURE_CFG_CSA_OC_FM_CONST_3 (latched error 1 (LE1) with automatic
 * PWM recovery when event is not present).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_FAILURE_CFG_CSA_OC_FM(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->FAILURE_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_FAILURE_CFG_CSA_OC_FM_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_FAILURE_CFG_CSA_OC_FM_POS) &
           (uint16)TLE9186_FAILURE_CFG_CSA_OC_FM_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_FAILURE_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for FAILURE_CFG_CSA_OC_FM.
 *
 * This function returns the value of the bitfield Current sense amplifiers
 * overcurrent failure reaction within register FAILURE_CFG.
 *
 * @return Value of the bitfield FAILURE_CFG_CSA_OC_FM:
 *      - 0: FAILURE_CFG_CSA_OC_FM_CONST_0 (latched error 1 (LE1) failure
 * reaction triggered (Default)).
 *      - 1: FAILURE_CFG_CSA_OC_FM_CONST_1 (error (E) failure reaction triggered
 * ).
 *      - 2: FAILURE_CFG_CSA_OC_FM_CONST_2 (warning (W) failure reaction
 * triggered).
 *      - 3: FAILURE_CFG_CSA_OC_FM_CONST_3 (latched error 1 (LE1) with automatic
 * PWM recovery when event is not present).
 */
uint16 TLE9186_FuncLayer_get_FAILURE_CFG_CSA_OC_FM(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->FAILURE_CFG.bit.CSA_OC_FM;
}

/**
 * @brief Set function for FAILURE_CFG_CSA_SUP_UV_FM.
 *
 * This function sets the bitfield Internal supply of CSA module under-voltage
 * failure reaction in register FAILURE_CFG.
 *
 * @param u16_value Value to be written into FAILURE_CFG_CSA_SUP_UV_FM. Valid
 * values are:
 *      - 0: FAILURE_CFG_CSA_SUP_UV_FM_CONST_0 (warning (W) failure reaction
 * triggered (Default)).
 *      - 1: FAILURE_CFG_CSA_SUP_UV_FM_CONST_1 (error (E) failure reaction
 * triggered).
 *      - 2: FAILURE_CFG_CSA_SUP_UV_FM_CONST_2 (latched error 1 (LE1) failure
 * reaction triggered).
 *      - 3: FAILURE_CFG_CSA_SUP_UV_FM_CONST_3 (reserved).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_FAILURE_CFG_CSA_SUP_UV_FM(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low]
                       * "Given due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->FAILURE_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_FAILURE_CFG_CSA_SUP_UV_FM_MSK)) |
         ((((uint16)(u16_value)
            << (uint16)TLE9186_FAILURE_CFG_CSA_SUP_UV_FM_POS) &
           (uint16)TLE9186_FAILURE_CFG_CSA_SUP_UV_FM_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_FAILURE_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for FAILURE_CFG_CSA_SUP_UV_FM.
 *
 * This function returns the value of the bitfield Internal supply of CSA module
 * under-voltage failure reaction within register FAILURE_CFG.
 *
 * @return Value of the bitfield FAILURE_CFG_CSA_SUP_UV_FM:
 *      - 0: FAILURE_CFG_CSA_SUP_UV_FM_CONST_0 (warning (W) failure reaction
 * triggered (Default)).
 *      - 1: FAILURE_CFG_CSA_SUP_UV_FM_CONST_1 (error (E) failure reaction
 * triggered).
 *      - 2: FAILURE_CFG_CSA_SUP_UV_FM_CONST_2 (latched error 1 (LE1) failure
 * reaction triggered).
 *      - 3: FAILURE_CFG_CSA_SUP_UV_FM_CONST_3 (reserved).
 */
uint16 TLE9186_FuncLayer_get_FAILURE_CFG_CSA_SUP_UV_FM(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->FAILURE_CFG.bit.CSA_SUP_UV_FM;
}

/**
 * @brief Set function for FAILURE_CFG_PWM_CHK_FM.
 *
 * This function sets the bitfield Failure reaction in case of missing PWM
 * alternation detection in register FAILURE_CFG.
 *
 * @param u16_value Value to be written into FAILURE_CFG_PWM_CHK_FM. Valid
 * values are:
 *      - 0: FAILURE_CFG_PWM_CHCK_FM_CONST_0 (error (E) failure reaction
 * triggered (Default)).
 *      - 1: FAILURE_CFG_PWM_CHCK_FM_CONST_1 (warning (W) failure reaction
 * triggered ).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_FAILURE_CFG_PWM_CHK_FM(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->FAILURE_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_FAILURE_CFG_PWM_CHK_FM_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_FAILURE_CFG_PWM_CHK_FM_POS) &
           (uint16)TLE9186_FAILURE_CFG_PWM_CHK_FM_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_FAILURE_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for FAILURE_CFG_PWM_CHK_FM.
 *
 * This function returns the value of the bitfield Failure reaction in case of
 * missing PWM alternation detection within register FAILURE_CFG.
 *
 * @return Value of the bitfield FAILURE_CFG_PWM_CHK_FM:
 *      - 0: FAILURE_CFG_PWM_CHCK_FM_CONST_0 (error (E) failure reaction
 * triggered (Default)).
 *      - 1: FAILURE_CFG_PWM_CHCK_FM_CONST_1 (warning (W) failure reaction
 * triggered ).
 */
uint16 TLE9186_FuncLayer_get_FAILURE_CFG_PWM_CHK_FM(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->FAILURE_CFG.bit.PWM_CHK_FM;
}

/**
 * @brief Set function for FAILURE_CFG_SDO_SHORT_FM.
 *
 * This function sets the bitfield SDO short to supply or ground event , failure
 * reaction   in register FAILURE_CFG.
 *
 * @param u16_value Value to be written into FAILURE_CFG_SDO_SHORT_FM. Valid
 * values are:
 *      - 0: FAILURE_CFG_SDO_SHORT_FM_CONST_0 (error (E) failure reaction
 * triggered (Default)).
 *      - 1: FAILURE_CFG_SDO_SHORT_FM_CONST_1 (latched error 1 (LE1) failure
 * reaction triggered ).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_FAILURE_CFG_SDO_SHORT_FM(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low]
                       * "Given due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->FAILURE_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_FAILURE_CFG_SDO_SHORT_FM_MSK)) |
         ((((uint16)(u16_value)
            << (uint16)TLE9186_FAILURE_CFG_SDO_SHORT_FM_POS) &
           (uint16)TLE9186_FAILURE_CFG_SDO_SHORT_FM_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_FAILURE_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for FAILURE_CFG_SDO_SHORT_FM.
 *
 * This function returns the value of the bitfield SDO short to supply or ground
 * event , failure reaction   within register FAILURE_CFG.
 *
 * @return Value of the bitfield FAILURE_CFG_SDO_SHORT_FM:
 *      - 0: FAILURE_CFG_SDO_SHORT_FM_CONST_0 (error (E) failure reaction
 * triggered (Default)).
 *      - 1: FAILURE_CFG_SDO_SHORT_FM_CONST_1 (latched error 1 (LE1) failure
 * reaction triggered ).
 */
uint16 TLE9186_FuncLayer_get_FAILURE_CFG_SDO_SHORT_FM(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->FAILURE_CFG.bit.SDO_SHORT_FM;
}

/**
 * @brief Set function for FAILURE_CFG_INHN_REC_FM.
 *
 * This function sets the bitfield INHN recovery after INHN low level reaction
 *in register FAILURE_CFG.
 *
 * @param u16_value Value to be written into FAILURE_CFG_INHN_REC_FM. Valid
 *values are:
 *      - 0: FAILURE_CFG_INHN_REC_FM_CONST_0 (once INHN high detected PWM
 *control automatic restart (Default) ).
 *      - 1: FAILURE_CFG_INHN_REC_FM_CONST_1 (once INHN high detected, forced
 *safe state kept until INHN_L_DET cleared
 *).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_FAILURE_CFG_INHN_REC_FM(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->FAILURE_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_FAILURE_CFG_INHN_REC_FM_MSK)) |
         ((((uint16)(u16_value)
            << (uint16)TLE9186_FAILURE_CFG_INHN_REC_FM_POS) &
           (uint16)TLE9186_FAILURE_CFG_INHN_REC_FM_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_FAILURE_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for FAILURE_CFG_INHN_REC_FM.
 *
 * This function returns the value of the bitfield INHN recovery after INHN low
 *level reaction within register FAILURE_CFG.
 *
 * @return Value of the bitfield FAILURE_CFG_INHN_REC_FM:
 *      - 0: FAILURE_CFG_INHN_REC_FM_CONST_0 (once INHN high detected PWM
 *control automatic restart (Default) ).
 *      - 1: FAILURE_CFG_INHN_REC_FM_CONST_1 (once INHN high detected, forced
 *safe state kept until INHN_L_DET cleared
 *).
 */
uint16 TLE9186_FuncLayer_get_FAILURE_CFG_INHN_REC_FM(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->FAILURE_CFG.bit.INHN_REC_FM;
}

/**
 * @brief Set function for FAILURE_CFG_OTP_ERR_FM.
 *
 * This function sets the bitfield OTP module error failure reaction
 * configuration in register FAILURE_CFG.
 *
 * @param u16_value Value to be written into FAILURE_CFG_OTP_ERR_FM. Valid
 * values are:
 *      - 0: FAILURE_CFG_OTP_ERR_FM_CONST_0 (latched error 1 (LE1) failure
 * reaction triggered (Default)).
 *      - 1: FAILURE_CFG_OTP_ERR_FM_CONST_1 (warning (W) failure reaction
 * triggered).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_FAILURE_CFG_OTP_ERR_FM(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->FAILURE_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_FAILURE_CFG_OTP_ERR_FM_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_FAILURE_CFG_OTP_ERR_FM_POS) &
           (uint16)TLE9186_FAILURE_CFG_OTP_ERR_FM_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_FAILURE_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for FAILURE_CFG_OTP_ERR_FM.
 *
 * This function returns the value of the bitfield OTP module error failure
 * reaction configuration within register FAILURE_CFG.
 *
 * @return Value of the bitfield FAILURE_CFG_OTP_ERR_FM:
 *      - 0: FAILURE_CFG_OTP_ERR_FM_CONST_0 (latched error 1 (LE1) failure
 * reaction triggered (Default)).
 *      - 1: FAILURE_CFG_OTP_ERR_FM_CONST_1 (warning (W) failure reaction
 * triggered).
 */
uint16 TLE9186_FuncLayer_get_FAILURE_CFG_OTP_ERR_FM(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->FAILURE_CFG.bit.OTP_ERR_FM;
}

/**
 * @brief Set function for FAILURE_CFG_WD_FM.
 *
 * This function sets the bitfield Window watchdog failure reaction in register
 * FAILURE_CFG.
 *
 * @param u16_value Value to be written into FAILURE_CFG_WD_FM. Valid values
 * are:
 *      - 0: FAILURE_CFG_WD_FM_CONST_0 (latched error 1 (LE1) failure reaction
 * triggered (Default)).
 *      - 1: FAILURE_CFG_WD_FM_CONST_1 (error (E) failure reaction triggered ).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_FAILURE_CFG_WD_FM(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->FAILURE_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_FAILURE_CFG_WD_FM_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_FAILURE_CFG_WD_FM_POS) &
           (uint16)TLE9186_FAILURE_CFG_WD_FM_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_FAILURE_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for FAILURE_CFG_WD_FM.
 *
 * This function returns the value of the bitfield Window watchdog failure
 * reaction within register FAILURE_CFG.
 *
 * @return Value of the bitfield FAILURE_CFG_WD_FM:
 *      - 0: FAILURE_CFG_WD_FM_CONST_0 (latched error 1 (LE1) failure reaction
 * triggered (Default)).
 *      - 1: FAILURE_CFG_WD_FM_CONST_1 (error (E) failure reaction triggered ).
 */
uint16 TLE9186_FuncLayer_get_FAILURE_CFG_WD_FM(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->FAILURE_CFG.bit.WD_FM;
}

/**
 * @brief Set function for FAILURE_CFG_TW_FM.
 *
 * This function sets the bitfield Temperature warning failure reaction in
 * register FAILURE_CFG.
 *
 * @param u16_value Value to be written into FAILURE_CFG_TW_FM. Valid values
 * are:
 *      - 0: FAILURE_CFG_TW_FM_CONST_0 (warning (W) failure reaction triggered
 * (Default)).
 *      - 1: FAILURE_CFG_TW_FM_CONST_1 (latched error 1 (LE1) failure reaction
 * triggered).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_FAILURE_CFG_TW_FM(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->FAILURE_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_FAILURE_CFG_TW_FM_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_FAILURE_CFG_TW_FM_POS) &
           (uint16)TLE9186_FAILURE_CFG_TW_FM_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_FAILURE_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for FAILURE_CFG_TW_FM.
 *
 * This function returns the value of the bitfield Temperature warning failure
 * reaction within register FAILURE_CFG.
 *
 * @return Value of the bitfield FAILURE_CFG_TW_FM:
 *      - 0: FAILURE_CFG_TW_FM_CONST_0 (warning (W) failure reaction triggered
 * (Default)).
 *      - 1: FAILURE_CFG_TW_FM_CONST_1 (latched error 1 (LE1) failure reaction
 * triggered).
 */
uint16 TLE9186_FuncLayer_get_FAILURE_CFG_TW_FM(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->FAILURE_CFG.bit.TW_FM;
}

/**
 * @brief Set function for FAILURE_CFG_ERRN_FM.
 *
 * This function sets the bitfield ERRN short to supply failure reaction in
 * register FAILURE_CFG.
 *
 * @param u16_value Value to be written into FAILURE_CFG_ERRN_FM. Valid values
 * are:
 *      - 0: FAILURE_CFG_ERRN_FM_CONST_0 (latched error 1 (LE1) failure reaction
 * triggered (Default)).
 *      - 1: FAILURE_CFG_ERRN_FM_CONST_1 (warning (W) failure reaction
 * triggered).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_FAILURE_CFG_ERRN_FM(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->FAILURE_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_FAILURE_CFG_ERRN_FM_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_FAILURE_CFG_ERRN_FM_POS) &
           (uint16)TLE9186_FAILURE_CFG_ERRN_FM_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_FAILURE_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for FAILURE_CFG_ERRN_FM.
 *
 * This function returns the value of the bitfield ERRN short to supply failure
 * reaction within register FAILURE_CFG.
 *
 * @return Value of the bitfield FAILURE_CFG_ERRN_FM:
 *      - 0: FAILURE_CFG_ERRN_FM_CONST_0 (latched error 1 (LE1) failure reaction
 * triggered (Default)).
 *      - 1: FAILURE_CFG_ERRN_FM_CONST_1 (warning (W) failure reaction
 * triggered).
 */
uint16 TLE9186_FuncLayer_get_FAILURE_CFG_ERRN_FM(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->FAILURE_CFG.bit.ERRN_FM;
}

/**
 * @brief Set function for FAILURE_CFG_IPV_STP_FM.
 *
 * This function sets the bitfield Shoot-through protection violation failure
 * reaction in register FAILURE_CFG.
 *
 * @param u16_value Value to be written into FAILURE_CFG_IPV_STP_FM. Valid
 * values are:
 *      - 0: FAILURE_CFG_IPV_STP_FM_CONST_0 (latched error 1 (LE1) failure
 * reaction triggered (Default)).
 *      - 1: FAILURE_CFG_IPV_STP_FM_CONST_1 (warning (W) failure reaction
 * triggered).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_FAILURE_CFG_IPV_STP_FM(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->FAILURE_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_FAILURE_CFG_IPV_STP_FM_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_FAILURE_CFG_IPV_STP_FM_POS) &
           (uint16)TLE9186_FAILURE_CFG_IPV_STP_FM_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_FAILURE_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for FAILURE_CFG_IPV_STP_FM.
 *
 * This function returns the value of the bitfield Shoot-through protection
 * violation failure reaction within register FAILURE_CFG.
 *
 * @return Value of the bitfield FAILURE_CFG_IPV_STP_FM:
 *      - 0: FAILURE_CFG_IPV_STP_FM_CONST_0 (latched error 1 (LE1) failure
 * reaction triggered (Default)).
 *      - 1: FAILURE_CFG_IPV_STP_FM_CONST_1 (warning (W) failure reaction
 * triggered).
 */
uint16 TLE9186_FuncLayer_get_FAILURE_CFG_IPV_STP_FM(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->FAILURE_CFG.bit.IPV_STP_FM;
}

/**
 * @brief Set function for FAILURE_CFG_IPV_CCP_FM.
 *
 * This function sets the bitfield Input pattern violation due to TCCP violation
 * failure reaction in register FAILURE_CFG.
 *
 * @param u16_value Value to be written into FAILURE_CFG_IPV_CCP_FM. Valid
 * values are:
 *      - 0: FAILURE_CFG_IPV_CCP_FM_CONST_0 (latched error 1 (LE1) failure
 * reaction triggered (Default)).
 *      - 1: FAILURE_CFG_IPV_CCP_FM_CONST_1 (warning (W) failure reaction
 * triggered).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_FAILURE_CFG_IPV_CCP_FM(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->FAILURE_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_FAILURE_CFG_IPV_CCP_FM_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_FAILURE_CFG_IPV_CCP_FM_POS) &
           (uint16)TLE9186_FAILURE_CFG_IPV_CCP_FM_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_FAILURE_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for FAILURE_CFG_IPV_CCP_FM.
 *
 * This function returns the value of the bitfield Input pattern violation due
 * to TCCP violation failure reaction within register FAILURE_CFG.
 *
 * @return Value of the bitfield FAILURE_CFG_IPV_CCP_FM:
 *      - 0: FAILURE_CFG_IPV_CCP_FM_CONST_0 (latched error 1 (LE1) failure
 * reaction triggered (Default)).
 *      - 1: FAILURE_CFG_IPV_CCP_FM_CONST_1 (warning (W) failure reaction
 * triggered).
 */
uint16 TLE9186_FuncLayer_get_FAILURE_CFG_IPV_CCP_FM(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->FAILURE_CFG.bit.IPV_CCP_FM;
}

/**
 * @brief Set function for FAILURE_CFG_PFB_FM.
 *
 * This function sets the bitfield Phase feedback monitoring failure reaction in
 * register FAILURE_CFG.
 *
 * @param u16_value Value to be written into FAILURE_CFG_PFB_FM. Valid values
 * are:
 *      - 0: FAILURE_CFG_PFB_FM_CONST_0 (latched error 1 (LE1) failure reaction
 * triggered (Default)).
 *      - 1: FAILURE_CFG_PFB_FM_CONST_1 (warning (W) failure reaction
 * triggered).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_FAILURE_CFG_PFB_FM(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->FAILURE_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_FAILURE_CFG_PFB_FM_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_FAILURE_CFG_PFB_FM_POS) &
           (uint16)TLE9186_FAILURE_CFG_PFB_FM_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_FAILURE_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for FAILURE_CFG_PFB_FM.
 *
 * This function returns the value of the bitfield Phase feedback monitoring
 * failure reaction within register FAILURE_CFG.
 *
 * @return Value of the bitfield FAILURE_CFG_PFB_FM:
 *      - 0: FAILURE_CFG_PFB_FM_CONST_0 (latched error 1 (LE1) failure reaction
 * triggered (Default)).
 *      - 1: FAILURE_CFG_PFB_FM_CONST_1 (warning (W) failure reaction
 * triggered).
 */
uint16 TLE9186_FuncLayer_get_FAILURE_CFG_PFB_FM(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->FAILURE_CFG.bit.PFB_FM;
}

/**
 * @brief Set function for FAILURE_CFG_DSOV_FM.
 *
 * This function sets the bitfield Drain-source overvoltage failure reaction in
 * register FAILURE_CFG.
 *
 * @param u16_value Value to be written into FAILURE_CFG_DSOV_FM. Valid values
 * are:
 *      - 0: FAILURE_CFG_DSOV_FM_CONST_0 (latched error 1 (LE1) failure reaction
 * triggered (Default)).
 *      - 1: FAILURE_CFG_DSOV_FM_CONST_1 (latched error 2 (LE2) failure reaction
 * triggered).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_FAILURE_CFG_DSOV_FM(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->FAILURE_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_FAILURE_CFG_DSOV_FM_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_FAILURE_CFG_DSOV_FM_POS) &
           (uint16)TLE9186_FAILURE_CFG_DSOV_FM_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_FAILURE_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for FAILURE_CFG_DSOV_FM.
 *
 * This function returns the value of the bitfield Drain-source overvoltage
 * failure reaction within register FAILURE_CFG.
 *
 * @return Value of the bitfield FAILURE_CFG_DSOV_FM:
 *      - 0: FAILURE_CFG_DSOV_FM_CONST_0 (latched error 1 (LE1) failure reaction
 * triggered (Default)).
 *      - 1: FAILURE_CFG_DSOV_FM_CONST_1 (latched error 2 (LE2) failure reaction
 * triggered).
 */
uint16 TLE9186_FuncLayer_get_FAILURE_CFG_DSOV_FM(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->FAILURE_CFG.bit.DSOV_FM;
}

/**
 * @brief get function for register FAILURE_CFG.
 *
 * This function reads the register Failure reaction configuration register 1.
 *
 */
void TLE9186_FuncLayer_get_FAILURE_CFG(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186_RegLayer_get_FAILURE_CFG();
}

/**
 * @brief Set function for register SELF_TEST_CFG.
 *
 * This function sets the Self-test configuration register .
 *
 * @param u16_value Value to be written into the register SELF_TEST_CFG.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SELF_TEST_CFG(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SELF_TEST_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for SELF_TEST_CFG_LAT_FAULT_ST.
 *
 * This function sets the bitfield Latent faults detector self-test enable in
 * register SELF_TEST_CFG.
 *
 * @param u16_value Value to be written into SELF_TEST_CFG_LAT_FAULT_ST. Valid
 * values are:
 *      - 0: SELF_TEST_CFG_LAT_FAULT_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG_LAT_FAULT_ST_CONST_1 (self-test enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SELF_TEST_CFG_LAT_FAULT_ST(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low]
                       * "Given due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SELF_TEST_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SELF_TEST_CFG_LAT_FAULT_ST_MSK)) |
         ((((uint16)(u16_value)
            << (uint16)TLE9186_SELF_TEST_CFG_LAT_FAULT_ST_POS) &
           (uint16)TLE9186_SELF_TEST_CFG_LAT_FAULT_ST_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SELF_TEST_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SELF_TEST_CFG_LAT_FAULT_ST.
 *
 * This function returns the value of the bitfield Latent faults detector
 * self-test enable within register SELF_TEST_CFG.
 *
 * @return Value of the bitfield SELF_TEST_CFG_LAT_FAULT_ST:
 *      - 0: SELF_TEST_CFG_LAT_FAULT_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG_LAT_FAULT_ST_CONST_1 (self-test enabled).
 */
uint16 TLE9186_FuncLayer_get_SELF_TEST_CFG_LAT_FAULT_ST(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->SELF_TEST_CFG.bit.LAT_FAULT_ST;
}

/**
 * @brief Set function for SELF_TEST_CFG_CLK_MON_ST.
 *
 * This function sets the bitfield Digital core clock monitoring self-test
 * enable in register SELF_TEST_CFG.
 *
 * @param u16_value Value to be written into SELF_TEST_CFG_CLK_MON_ST. Valid
 * values are:
 *      - 0: SELF_TEST_CFG_CLK_MON_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG_CLK_MON_ST_CONST_1 (self-test enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SELF_TEST_CFG_CLK_MON_ST(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low]
                       * "Given due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SELF_TEST_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SELF_TEST_CFG_CLK_MON_ST_MSK)) |
         ((((uint16)(u16_value)
            << (uint16)TLE9186_SELF_TEST_CFG_CLK_MON_ST_POS) &
           (uint16)TLE9186_SELF_TEST_CFG_CLK_MON_ST_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SELF_TEST_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SELF_TEST_CFG_CLK_MON_ST.
 *
 * This function returns the value of the bitfield Digital core clock monitoring
 * self-test enable within register SELF_TEST_CFG.
 *
 * @return Value of the bitfield SELF_TEST_CFG_CLK_MON_ST:
 *      - 0: SELF_TEST_CFG_CLK_MON_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG_CLK_MON_ST_CONST_1 (self-test enabled).
 */
uint16 TLE9186_FuncLayer_get_SELF_TEST_CFG_CLK_MON_ST(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->SELF_TEST_CFG.bit.CLK_MON_ST;
}

/**
 * @brief Set function for SELF_TEST_CFG_REG_UV_ST.
 *
 * This function sets the bitfield Internal regulator under voltage self-test
 * enable in register SELF_TEST_CFG.
 *
 * @param u16_value Value to be written into SELF_TEST_CFG_REG_UV_ST. Valid
 * values are:
 *      - 0: SELF_TEST_CFG_REG_UV_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG_REG_UV_ST_CONST_1 (self-test enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SELF_TEST_CFG_REG_UV_ST(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SELF_TEST_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SELF_TEST_CFG_REG_UV_ST_MSK)) |
         ((((uint16)(u16_value)
            << (uint16)TLE9186_SELF_TEST_CFG_REG_UV_ST_POS) &
           (uint16)TLE9186_SELF_TEST_CFG_REG_UV_ST_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SELF_TEST_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SELF_TEST_CFG_REG_UV_ST.
 *
 * This function returns the value of the bitfield Internal regulator under
 * voltage self-test enable within register SELF_TEST_CFG.
 *
 * @return Value of the bitfield SELF_TEST_CFG_REG_UV_ST:
 *      - 0: SELF_TEST_CFG_REG_UV_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG_REG_UV_ST_CONST_1 (self-test enabled).
 */
uint16 TLE9186_FuncLayer_get_SELF_TEST_CFG_REG_UV_ST(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->SELF_TEST_CFG.bit.REG_UV_ST;
}

/**
 * @brief Set function for SELF_TEST_CFG_CSA_OC_ST.
 *
 * This function sets the bitfield Current sense amplifier over-current supply
 * self-test enable in register SELF_TEST_CFG.
 *
 * @param u16_value Value to be written into SELF_TEST_CFG_CSA_OC_ST. Valid
 * values are:
 *      - 0: SELF_TEST_CFG_CSA_OC_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG_CSA_OC_ST_CONST_1 (self-test enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SELF_TEST_CFG_CSA_OC_ST(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SELF_TEST_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SELF_TEST_CFG_CSA_OC_ST_MSK)) |
         ((((uint16)(u16_value)
            << (uint16)TLE9186_SELF_TEST_CFG_CSA_OC_ST_POS) &
           (uint16)TLE9186_SELF_TEST_CFG_CSA_OC_ST_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SELF_TEST_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SELF_TEST_CFG_CSA_OC_ST.
 *
 * This function returns the value of the bitfield Current sense amplifier
 * over-current supply self-test enable within register SELF_TEST_CFG.
 *
 * @return Value of the bitfield SELF_TEST_CFG_CSA_OC_ST:
 *      - 0: SELF_TEST_CFG_CSA_OC_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG_CSA_OC_ST_CONST_1 (self-test enabled).
 */
uint16 TLE9186_FuncLayer_get_SELF_TEST_CFG_CSA_OC_ST(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->SELF_TEST_CFG.bit.CSA_OC_ST;
}

/**
 * @brief Set function for SELF_TEST_CFG_CSA_SUP_ST.
 *
 * This function sets the bitfield Current sense amplifier internal supply
 * self-test enable in register SELF_TEST_CFG.
 *
 * @param u16_value Value to be written into SELF_TEST_CFG_CSA_SUP_ST. Valid
 * values are:
 *      - 0: SELF_TEST_CFG_CSA_SUP_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG_CSA_SUP_ST_CONST_1 (self-test enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SELF_TEST_CFG_CSA_SUP_ST(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low]
                       * "Given due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SELF_TEST_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SELF_TEST_CFG_CSA_SUP_ST_MSK)) |
         ((((uint16)(u16_value)
            << (uint16)TLE9186_SELF_TEST_CFG_CSA_SUP_ST_POS) &
           (uint16)TLE9186_SELF_TEST_CFG_CSA_SUP_ST_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SELF_TEST_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SELF_TEST_CFG_CSA_SUP_ST.
 *
 * This function returns the value of the bitfield Current sense amplifier
 * internal supply self-test enable within register SELF_TEST_CFG.
 *
 * @return Value of the bitfield SELF_TEST_CFG_CSA_SUP_ST:
 *      - 0: SELF_TEST_CFG_CSA_SUP_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG_CSA_SUP_ST_CONST_1 (self-test enabled).
 */
uint16 TLE9186_FuncLayer_get_SELF_TEST_CFG_CSA_SUP_ST(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->SELF_TEST_CFG.bit.CSA_SUP_ST;
}

/**
 * @brief Set function for SELF_TEST_CFG_CPMON_ST.
 *
 * This function sets the bitfield VCPH overdrive and undervoltage monitoring
 * Self-test enable in register SELF_TEST_CFG.
 *
 * @param u16_value Value to be written into SELF_TEST_CFG_CPMON_ST. Valid
 * values are:
 *      - 0: SELF_TEST_CFG_CPMON_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG_CPMON_ST_CONST_1 (self-test enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SELF_TEST_CFG_CPMON_ST(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SELF_TEST_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SELF_TEST_CFG_CPMON_ST_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_SELF_TEST_CFG_CPMON_ST_POS) &
           (uint16)TLE9186_SELF_TEST_CFG_CPMON_ST_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SELF_TEST_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SELF_TEST_CFG_CPMON_ST.
 *
 * This function returns the value of the bitfield VCPH overdrive and
 * undervoltage monitoring Self-test enable within register SELF_TEST_CFG.
 *
 * @return Value of the bitfield SELF_TEST_CFG_CPMON_ST:
 *      - 0: SELF_TEST_CFG_CPMON_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG_CPMON_ST_CONST_1 (self-test enabled).
 */
uint16 TLE9186_FuncLayer_get_SELF_TEST_CFG_CPMON_ST(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->SELF_TEST_CFG.bit.CPMON_ST;
}

/**
 * @brief Set function for SELF_TEST_CFG_VSCP_MON_ST.
 *
 * This function sets the bitfield VSCP monitoring self-test enable in register
 * SELF_TEST_CFG.
 *
 * @param u16_value Value to be written into SELF_TEST_CFG_VSCP_MON_ST. Valid
 * values are:
 *      - 0: SELF_TEST_CFG_VSCP_MON_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG_VSCP_MON_ST_CONST_1 (self-test enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SELF_TEST_CFG_VSCP_MON_ST(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low]
                       * "Given due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SELF_TEST_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SELF_TEST_CFG_VSCP_MON_ST_MSK)) |
         ((((uint16)(u16_value)
            << (uint16)TLE9186_SELF_TEST_CFG_VSCP_MON_ST_POS) &
           (uint16)TLE9186_SELF_TEST_CFG_VSCP_MON_ST_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SELF_TEST_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SELF_TEST_CFG_VSCP_MON_ST.
 *
 * This function returns the value of the bitfield VSCP monitoring self-test
 * enable within register SELF_TEST_CFG.
 *
 * @return Value of the bitfield SELF_TEST_CFG_VSCP_MON_ST:
 *      - 0: SELF_TEST_CFG_VSCP_MON_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG_VSCP_MON_ST_CONST_1 (self-test enabled).
 */
uint16 TLE9186_FuncLayer_get_SELF_TEST_CFG_VSCP_MON_ST(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->SELF_TEST_CFG.bit.VSCP_MON_ST;
}

/**
 * @brief Set function for SELF_TEST_CFG_SOFF_ST.
 *
 * This function sets the bitfield Safe state activation path self-test enable
 * in register SELF_TEST_CFG.
 *
 * @param u16_value Value to be written into SELF_TEST_CFG_SOFF_ST. Valid values
 * are:
 *      - 0: SELF_TEST_CFG_SOFF_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG_SOFF_ST_CONST_1 (self-test enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SELF_TEST_CFG_SOFF_ST(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SELF_TEST_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SELF_TEST_CFG_SOFF_ST_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_SELF_TEST_CFG_SOFF_ST_POS) &
           (uint16)TLE9186_SELF_TEST_CFG_SOFF_ST_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SELF_TEST_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SELF_TEST_CFG_SOFF_ST.
 *
 * This function returns the value of the bitfield Safe state activation path
 * self-test enable within register SELF_TEST_CFG.
 *
 * @return Value of the bitfield SELF_TEST_CFG_SOFF_ST:
 *      - 0: SELF_TEST_CFG_SOFF_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG_SOFF_ST_CONST_1 (self-test enabled).
 */
uint16 TLE9186_FuncLayer_get_SELF_TEST_CFG_SOFF_ST(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->SELF_TEST_CFG.bit.SOFF_ST;
}

/**
 * @brief Set function for SELF_TEST_CFG_TSD_ST.
 *
 * This function sets the bitfield Overtemperature monitoring self-test enable
 * in register SELF_TEST_CFG.
 *
 * @param u16_value Value to be written into SELF_TEST_CFG_TSD_ST. Valid values
 * are:
 *      - 0: SELF_TEST_CFG_TSD_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG_TSD_ST_CONST_1 (self-test enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SELF_TEST_CFG_TSD_ST(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SELF_TEST_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SELF_TEST_CFG_TSD_ST_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_SELF_TEST_CFG_TSD_ST_POS) &
           (uint16)TLE9186_SELF_TEST_CFG_TSD_ST_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SELF_TEST_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SELF_TEST_CFG_TSD_ST.
 *
 * This function returns the value of the bitfield Overtemperature monitoring
 * self-test enable within register SELF_TEST_CFG.
 *
 * @return Value of the bitfield SELF_TEST_CFG_TSD_ST:
 *      - 0: SELF_TEST_CFG_TSD_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG_TSD_ST_CONST_1 (self-test enabled).
 */
uint16 TLE9186_FuncLayer_get_SELF_TEST_CFG_TSD_ST(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->SELF_TEST_CFG.bit.TSD_ST;
}

/**
 * @brief Set function for SELF_TEST_CFG_PFB_ST.
 *
 * This function sets the bitfield PFB logic self-test enable in register
 * SELF_TEST_CFG.
 *
 * @param u16_value Value to be written into SELF_TEST_CFG_PFB_ST. Valid values
 * are:
 *      - 0: SELF_TEST_CFG_PFB_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG_PFB_ST_CONST_1 (self-test enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SELF_TEST_CFG_PFB_ST(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SELF_TEST_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SELF_TEST_CFG_PFB_ST_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_SELF_TEST_CFG_PFB_ST_POS) &
           (uint16)TLE9186_SELF_TEST_CFG_PFB_ST_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SELF_TEST_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SELF_TEST_CFG_PFB_ST.
 *
 * This function returns the value of the bitfield PFB logic self-test enable
 * within register SELF_TEST_CFG.
 *
 * @return Value of the bitfield SELF_TEST_CFG_PFB_ST:
 *      - 0: SELF_TEST_CFG_PFB_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG_PFB_ST_CONST_1 (self-test enabled).
 */
uint16 TLE9186_FuncLayer_get_SELF_TEST_CFG_PFB_ST(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->SELF_TEST_CFG.bit.PFB_ST;
}

/**
 * @brief Set function for SELF_TEST_CFG_VIO_MON_ST.
 *
 * This function sets the bitfield VIO monitoring self-test enable in register
 * SELF_TEST_CFG.
 *
 * @param u16_value Value to be written into SELF_TEST_CFG_VIO_MON_ST. Valid
 * values are:
 *      - 0: SELF_TEST_CFG_VIO_MON_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG_VIO_MON_ST_CONST_1 (self-test enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SELF_TEST_CFG_VIO_MON_ST(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low]
                       * "Given due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SELF_TEST_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SELF_TEST_CFG_VIO_MON_ST_MSK)) |
         ((((uint16)(u16_value)
            << (uint16)TLE9186_SELF_TEST_CFG_VIO_MON_ST_POS) &
           (uint16)TLE9186_SELF_TEST_CFG_VIO_MON_ST_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SELF_TEST_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SELF_TEST_CFG_VIO_MON_ST.
 *
 * This function returns the value of the bitfield VIO monitoring self-test
 * enable within register SELF_TEST_CFG.
 *
 * @return Value of the bitfield SELF_TEST_CFG_VIO_MON_ST:
 *      - 0: SELF_TEST_CFG_VIO_MON_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG_VIO_MON_ST_CONST_1 (self-test enabled).
 */
uint16 TLE9186_FuncLayer_get_SELF_TEST_CFG_VIO_MON_ST(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->SELF_TEST_CFG.bit.VIO_MON_ST;
}

/**
 * @brief Set function for SELF_TEST_CFG_DSOV_ST.
 *
 * This function sets the bitfield Drain-source monitoring self-test enable in
 * register SELF_TEST_CFG.
 *
 * @param u16_value Value to be written into SELF_TEST_CFG_DSOV_ST. Valid values
 * are:
 *      - 0: SELF_TEST_CFG1_DSOV_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG1_DSOV_ST_CONST_1 (self-test enabled).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SELF_TEST_CFG_DSOV_ST(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SELF_TEST_CFG.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SELF_TEST_CFG_DSOV_ST_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_SELF_TEST_CFG_DSOV_ST_POS) &
           (uint16)TLE9186_SELF_TEST_CFG_DSOV_ST_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SELF_TEST_CFG;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SELF_TEST_CFG_DSOV_ST.
 *
 * This function returns the value of the bitfield Drain-source monitoring
 * self-test enable within register SELF_TEST_CFG.
 *
 * @return Value of the bitfield SELF_TEST_CFG_DSOV_ST:
 *      - 0: SELF_TEST_CFG1_DSOV_ST_CONST_0 (self-test disabled (Default)).
 *      - 1: SELF_TEST_CFG1_DSOV_ST_CONST_1 (self-test enabled).
 */
uint16 TLE9186_FuncLayer_get_SELF_TEST_CFG_DSOV_ST(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->SELF_TEST_CFG.bit.DSOV_ST;
}

/**
 * @brief get function for register SELF_TEST_CFG.
 *
 * This function reads the register Self-test configuration register .
 *
 */
void TLE9186_FuncLayer_get_SELF_TEST_CFG(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186_RegLayer_get_SELF_TEST_CFG();
}

/**
 * @brief Set function for register SUP_STAT.
 *
 * This function sets the Supply monitoring status register.
 *
 * @param u16_value Value to be written into the register SUP_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SUP_STAT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SUP_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for SUP_STAT_VIO_OV.
 *
 * This function sets the bitfield VIO overvoltage detection in register
 * SUP_STAT.
 *
 * @param u16_value Value to be written into SUP_STAT_VIO_OV. Valid values are:
 *      - 0: SUP_STAT_VIO_OV_CONST_0 (no VIO over-voltage detected).
 *      - 1: SUP_STAT_VIO_OV_CONST_1 (VIO over-voltage event detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SUP_STAT_VIO_OV(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SUP_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SUP_STAT_VIO_OV_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_SUP_STAT_VIO_OV_POS) &
           (uint16)TLE9186_SUP_STAT_VIO_OV_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SUP_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for SUP_STAT_VIO_OV.
 *
 * This function clears the bitfield VIO overvoltage detection in register
 * SUP_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_SUP_STAT_VIO_OV(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_SUP_STAT_VIO_OV_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SUP_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SUP_STAT_VIO_OV.
 *
 * This function returns the value of the bitfield VIO overvoltage detection
 * within register SUP_STAT.
 *
 * @return Value of the bitfield SUP_STAT_VIO_OV:
 *      - 0: SUP_STAT_VIO_OV_CONST_0 (no VIO over-voltage detected).
 *      - 1: SUP_STAT_VIO_OV_CONST_1 (VIO over-voltage event detected).
 */
uint16 TLE9186_FuncLayer_get_SUP_STAT_VIO_OV(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->SUP_STAT.bit.VIO_OV;
}

/**
 * @brief Set function for SUP_STAT_VIO_UV.
 *
 * This function sets the bitfield VIO undervoltage detection in register
 * SUP_STAT.
 *
 * @param u16_value Value to be written into SUP_STAT_VIO_UV. Valid values are:
 *      - 0: SUP_STAT_VIO_UV_CONST_0 (no VIO under-voltage detected).
 *      - 1: SUP_STAT_VIO_UV_CONST_1 (VIO under-voltage event detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SUP_STAT_VIO_UV(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SUP_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SUP_STAT_VIO_UV_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_SUP_STAT_VIO_UV_POS) &
           (uint16)TLE9186_SUP_STAT_VIO_UV_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SUP_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for SUP_STAT_VIO_UV.
 *
 * This function clears the bitfield VIO undervoltage detection in register
 * SUP_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_SUP_STAT_VIO_UV(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_SUP_STAT_VIO_UV_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SUP_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SUP_STAT_VIO_UV.
 *
 * This function returns the value of the bitfield VIO undervoltage detection
 * within register SUP_STAT.
 *
 * @return Value of the bitfield SUP_STAT_VIO_UV:
 *      - 0: SUP_STAT_VIO_UV_CONST_0 (no VIO under-voltage detected).
 *      - 1: SUP_STAT_VIO_UV_CONST_1 (VIO under-voltage event detected).
 */
uint16 TLE9186_FuncLayer_get_SUP_STAT_VIO_UV(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->SUP_STAT.bit.VIO_UV;
}

/**
 * @brief Set function for SUP_STAT_CSA_SUP_UV.
 *
 * This function sets the bitfield Current sense amplifier internal supply
 * undervoltage in register SUP_STAT.
 *
 * @param u16_value Value to be written into SUP_STAT_CSA_SUP_UV. Valid values
 * are:
 *      - 0: SUP_STAT_CSA_SUP_UV_CONST_0 (no under-voltage detected).
 *      - 1: SUP_STAT_CSA_SUP_UV_CONST_1 (CSA_SUP under-voltage detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SUP_STAT_CSA_SUP_UV(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SUP_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SUP_STAT_CSA_SUP_UV_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_SUP_STAT_CSA_SUP_UV_POS) &
           (uint16)TLE9186_SUP_STAT_CSA_SUP_UV_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SUP_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for SUP_STAT_CSA_SUP_UV.
 *
 * This function clears the bitfield Current sense amplifier internal supply
 * undervoltage in register SUP_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_SUP_STAT_CSA_SUP_UV(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_SUP_STAT_CSA_SUP_UV_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SUP_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SUP_STAT_CSA_SUP_UV.
 *
 * This function returns the value of the bitfield Current sense amplifier
 * internal supply undervoltage within register SUP_STAT.
 *
 * @return Value of the bitfield SUP_STAT_CSA_SUP_UV:
 *      - 0: SUP_STAT_CSA_SUP_UV_CONST_0 (no under-voltage detected).
 *      - 1: SUP_STAT_CSA_SUP_UV_CONST_1 (CSA_SUP under-voltage detected).
 */
uint16 TLE9186_FuncLayer_get_SUP_STAT_CSA_SUP_UV(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->SUP_STAT.bit.CSA_SUP_UV;
}

/**
 * @brief Set function for SUP_STAT_VDH_UV.
 *
 * This function sets the bitfield VDH pin under-voltage detection in register
 * SUP_STAT.
 *
 * @param u16_value Value to be written into SUP_STAT_VDH_UV. Valid values are:
 *      - 0: SUP_STAT_VDH_UV_CONST_0 (no VDH under voltage detected).
 *      - 1: SUP_STAT_VDH_UV_CONST_1 (VDH under voltage event detection).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SUP_STAT_VDH_UV(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SUP_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SUP_STAT_VDH_UV_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_SUP_STAT_VDH_UV_POS) &
           (uint16)TLE9186_SUP_STAT_VDH_UV_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SUP_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for SUP_STAT_VDH_UV.
 *
 * This function clears the bitfield VDH pin under-voltage detection in register
 * SUP_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_SUP_STAT_VDH_UV(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_SUP_STAT_VDH_UV_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SUP_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SUP_STAT_VDH_UV.
 *
 * This function returns the value of the bitfield VDH pin under-voltage
 * detection within register SUP_STAT.
 *
 * @return Value of the bitfield SUP_STAT_VDH_UV:
 *      - 0: SUP_STAT_VDH_UV_CONST_0 (no VDH under voltage detected).
 *      - 1: SUP_STAT_VDH_UV_CONST_1 (VDH under voltage event detection).
 */
uint16 TLE9186_FuncLayer_get_SUP_STAT_VDH_UV(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->SUP_STAT.bit.VDH_UV;
}

/**
 * @brief Get function for SUP_STAT_VSCP_H.
 *
 * This function returns the value of the bitfield VSCP High undervoltage
 * detection  within register SUP_STAT.
 *
 * @return Value of the bitfield SUP_STAT_VSCP_H:
 *      - 0: SUP_STAT_VSCP_H_CONST_0 (no VSCP_H under-voltage detected).
 *      - 1: SUP_STAT_VSCP_H_CONST_1 (VSCP_H under-voltage event detected).
 */
uint16 TLE9186_FuncLayer_get_SUP_STAT_VSCP_H(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->SUP_STAT.bit.VSCP_H;
}

/**
 * @brief Get function for SUP_STAT_VSCP_L.
 *
 * This function returns the value of the bitfield VSCP Low undervoltage
 * detection within register SUP_STAT.
 *
 * @return Value of the bitfield SUP_STAT_VSCP_L:
 *      - 0: SUP_STAT_VSCP_L_CONST_0 (no VSCP_L under-voltage detected).
 *      - 1: SUP_STAT_VSCP_L_CONST_1 (VSCP_L under-voltage detected).
 */
uint16 TLE9186_FuncLayer_get_SUP_STAT_VSCP_L(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->SUP_STAT.bit.VSCP_L;
}

/**
 * @brief Set function for SUP_STAT_VCPH_UV.
 *
 * This function sets the bitfield Charge pump output VCPH undervoltage
 * detection in register SUP_STAT.
 *
 * @param u16_value Value to be written into SUP_STAT_VCPH_UV. Valid values are:
 *      - 0: SUP_STAT_VCPH_UV_CONST_0 (no VCPH UV detected).
 *      - 1: SUP_STAT_VCPH_UV_CONST_1 (VCPH under-voltage event detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SUP_STAT_VCPH_UV(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SUP_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SUP_STAT_VCPH_UV_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_SUP_STAT_VCPH_UV_POS) &
           (uint16)TLE9186_SUP_STAT_VCPH_UV_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SUP_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for SUP_STAT_VCPH_UV.
 *
 * This function clears the bitfield Charge pump output VCPH undervoltage
 * detection in register SUP_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_SUP_STAT_VCPH_UV(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_SUP_STAT_VCPH_UV_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SUP_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SUP_STAT_VCPH_UV.
 *
 * This function returns the value of the bitfield Charge pump output VCPH
 * undervoltage detection within register SUP_STAT.
 *
 * @return Value of the bitfield SUP_STAT_VCPH_UV:
 *      - 0: SUP_STAT_VCPH_UV_CONST_0 (no VCPH UV detected).
 *      - 1: SUP_STAT_VCPH_UV_CONST_1 (VCPH under-voltage event detected).
 */
uint16 TLE9186_FuncLayer_get_SUP_STAT_VCPH_UV(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->SUP_STAT.bit.VCPH_UV;
}

/**
 * @brief Set function for SUP_STAT_VSCP_OV_SD.
 *
 * This function sets the bitfield VSCP overvoltage shutdown detection in
 * register SUP_STAT.
 *
 * @param u16_value Value to be written into SUP_STAT_VSCP_OV_SD. Valid values
 * are:
 *      - 0: SUP_STAT_VSCP_OV_SD_CONST_0 (no VSCP_OV_SD detected).
 *      - 1: SUP_STAT_VSCP_OV_SD_CONST_1 (VSCP_OV_SD over-voltage event
 * detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SUP_STAT_VSCP_OV_SD(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SUP_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SUP_STAT_VSCP_OV_SD_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_SUP_STAT_VSCP_OV_SD_POS) &
           (uint16)TLE9186_SUP_STAT_VSCP_OV_SD_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SUP_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for SUP_STAT_VSCP_OV_SD.
 *
 * This function clears the bitfield VSCP overvoltage shutdown detection in
 * register SUP_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_SUP_STAT_VSCP_OV_SD(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_SUP_STAT_VSCP_OV_SD_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SUP_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SUP_STAT_VSCP_OV_SD.
 *
 * This function returns the value of the bitfield VSCP overvoltage shutdown
 * detection within register SUP_STAT.
 *
 * @return Value of the bitfield SUP_STAT_VSCP_OV_SD:
 *      - 0: SUP_STAT_VSCP_OV_SD_CONST_0 (no VSCP_OV_SD detected).
 *      - 1: SUP_STAT_VSCP_OV_SD_CONST_1 (VSCP_OV_SD over-voltage event
 * detected).
 */
uint16 TLE9186_FuncLayer_get_SUP_STAT_VSCP_OV_SD(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->SUP_STAT.bit.VSCP_OV_SD;
}

/**
 * @brief Set function for SUP_STAT_VSCP_UV_SD.
 *
 * This function sets the bitfield VSCP undervoltage shutdown detection in
 * register SUP_STAT.
 *
 * @param u16_value Value to be written into SUP_STAT_VSCP_UV_SD. Valid values
 * are:
 *      - 0: SUP_STAT_VSCP_UV_SD_CONST_0 (no VSCP_UV_SD detected).
 *      - 1: SUP_STAT_VSCP_UV_SD_CONST_1 (VSCP_UV_SD under-voltage event
 * detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SUP_STAT_VSCP_UV_SD(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SUP_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SUP_STAT_VSCP_UV_SD_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_SUP_STAT_VSCP_UV_SD_POS) &
           (uint16)TLE9186_SUP_STAT_VSCP_UV_SD_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SUP_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for SUP_STAT_VSCP_UV_SD.
 *
 * This function clears the bitfield VSCP undervoltage shutdown detection in
 * register SUP_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_SUP_STAT_VSCP_UV_SD(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)((uint16)1u << (uint16)TLE9186_SUP_STAT_VSCP_UV_SD_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SUP_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SUP_STAT_VSCP_UV_SD.
 *
 * This function returns the value of the bitfield VSCP undervoltage shutdown
 * detection within register SUP_STAT.
 *
 * @return Value of the bitfield SUP_STAT_VSCP_UV_SD:
 *      - 0: SUP_STAT_VSCP_UV_SD_CONST_0 (no VSCP_UV_SD detected).
 *      - 1: SUP_STAT_VSCP_UV_SD_CONST_1 (VSCP_UV_SD under-voltage event
 * detected).
 */
uint16 TLE9186_FuncLayer_get_SUP_STAT_VSCP_UV_SD(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->SUP_STAT.bit.VSCP_UV_SD;
}

/**
 * @brief Set function for SUP_STAT_POR.
 *
 * This function sets the bitfield Power on reset detection in register
 * SUP_STAT.
 *
 * @param u16_value Value to be written into SUP_STAT_POR. Valid values are:
 *      - 0: SUP_STAT_POR_CONST_0 (no POR event (since last clear command)).
 *      - 1: SUP_STAT_POR_CONST_1 (POR event occured).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SUP_STAT_POR(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SUP_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SUP_STAT_POR_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_SUP_STAT_POR_POS) &
           (uint16)TLE9186_SUP_STAT_POR_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SUP_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for SUP_STAT_POR.
 *
 * This function clears the bitfield Power on reset detection in register
 * SUP_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_SUP_STAT_POR(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)((uint16)1u << (uint16)TLE9186_SUP_STAT_POR_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SUP_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SUP_STAT_POR.
 *
 * This function returns the value of the bitfield Power on reset detection
 * within register SUP_STAT.
 *
 * @return Value of the bitfield SUP_STAT_POR:
 *      - 0: SUP_STAT_POR_CONST_0 (no POR event (since last clear command)).
 *      - 1: SUP_STAT_POR_CONST_1 (POR event occured).
 */
uint16 TLE9186_FuncLayer_get_SUP_STAT_POR(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->SUP_STAT.bit.POR;
}

/**
 * @brief get function for register SUP_STAT.
 *
 * This function reads the register Supply monitoring status register.
 *
 */
void TLE9186_FuncLayer_get_SUP_STAT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_SUP_STAT();
}

/**
 * @brief Set function for register SPI_STAT.
 *
 * This function sets the SPI status register (SPI and WD monitoring).
 *
 * @param u16_value Value to be written into the register SPI_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SPI_STAT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SPI_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for SPI_STAT_FRAME_ERR.
 *
 * This function sets the bitfield SPI frame error detection in register
 * SPI_STAT.
 *
 * @param u16_value Value to be written into SPI_STAT_FRAME_ERR. Valid values
 * are:
 *      - 0: STAT_FRAME_ERR_CONST_0 (no frame error detected).
 *      - 1: STAT_FRAME_ERR_CONST_1 (SPI failure due to frame error detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SPI_STAT_FRAME_ERR(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SPI_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SPI_STAT_FRAME_ERR_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_SPI_STAT_FRAME_ERR_POS) &
           (uint16)TLE9186_SPI_STAT_FRAME_ERR_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SPI_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for SPI_STAT_FRAME_ERR.
 *
 * This function clears the bitfield SPI frame error detection in register
 * SPI_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_SPI_STAT_FRAME_ERR(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_SPI_STAT_FRAME_ERR_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SPI_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SPI_STAT_FRAME_ERR.
 *
 * This function returns the value of the bitfield SPI frame error detection
 * within register SPI_STAT.
 *
 * @return Value of the bitfield SPI_STAT_FRAME_ERR:
 *      - 0: STAT_FRAME_ERR_CONST_0 (no frame error detected).
 *      - 1: STAT_FRAME_ERR_CONST_1 (SPI failure due to frame error detected).
 */
uint16 TLE9186_FuncLayer_get_SPI_STAT_FRAME_ERR(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->SPI_STAT.bit.FRAME_ERR;
}

/**
 * @brief Set function for SPI_STAT_SPI_IA.
 *
 * This function sets the bitfield Invalid SPI access detection in register
 * SPI_STAT.
 *
 * @param u16_value Value to be written into SPI_STAT_SPI_IA. Valid values are:
 *      - 0: STAT_SPI_IA_CONST_0 (no invalid access detected).
 *      - 1: STAT_SPI_IA_CONST_1 (SPI failure due to invalid access detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SPI_STAT_SPI_IA(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SPI_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SPI_STAT_SPI_IA_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_SPI_STAT_SPI_IA_POS) &
           (uint16)TLE9186_SPI_STAT_SPI_IA_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SPI_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for SPI_STAT_SPI_IA.
 *
 * This function clears the bitfield Invalid SPI access detection in register
 * SPI_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_SPI_STAT_SPI_IA(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_SPI_STAT_SPI_IA_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SPI_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SPI_STAT_SPI_IA.
 *
 * This function returns the value of the bitfield Invalid SPI access detection
 * within register SPI_STAT.
 *
 * @return Value of the bitfield SPI_STAT_SPI_IA:
 *      - 0: STAT_SPI_IA_CONST_0 (no invalid access detected).
 *      - 1: STAT_SPI_IA_CONST_1 (SPI failure due to invalid access detected).
 */
uint16 TLE9186_FuncLayer_get_SPI_STAT_SPI_IA(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->SPI_STAT.bit.SPI_IA;
}

/**
 * @brief Set function for SPI_STAT_CRC_FAIL.
 *
 * This function sets the bitfield CRC failure detection in register SPI_STAT.
 *
 * @param u16_value Value to be written into SPI_STAT_CRC_FAIL. Valid values
 * are:
 *      - 0: STAT_CRC_FAIL_CONST_0 (no CRC failure detected).
 *      - 1: STAT_CRC_FAIL_CONST_1 (CRC failure detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SPI_STAT_CRC_FAIL(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SPI_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SPI_STAT_CRC_FAIL_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_SPI_STAT_CRC_FAIL_POS) &
           (uint16)TLE9186_SPI_STAT_CRC_FAIL_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SPI_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for SPI_STAT_CRC_FAIL.
 *
 * This function clears the bitfield CRC failure detection in register SPI_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_SPI_STAT_CRC_FAIL(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_SPI_STAT_CRC_FAIL_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SPI_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SPI_STAT_CRC_FAIL.
 *
 * This function returns the value of the bitfield CRC failure detection within
 * register SPI_STAT.
 *
 * @return Value of the bitfield SPI_STAT_CRC_FAIL:
 *      - 0: STAT_CRC_FAIL_CONST_0 (no CRC failure detected).
 *      - 1: STAT_CRC_FAIL_CONST_1 (CRC failure detected).
 */
uint16 TLE9186_FuncLayer_get_SPI_STAT_CRC_FAIL(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->SPI_STAT.bit.CRC_FAIL;
}

/**
 * @brief Set function for SPI_STAT_OFC.
 *
 * This function sets the bitfield One SPI frame corrupted detection in register
 * SPI_STAT.
 *
 * @param u16_value Value to be written into SPI_STAT_OFC. Valid values are:
 *      - 0: STAT_OFC_CONST_0 (no corrupted SPI frame detected since last clear
 * of OFC bit).
 *      - 1: STAT_OFC_CONST_1 (one corrupted SPI frame detected since last clear
 * of OFC bit).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SPI_STAT_OFC(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SPI_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SPI_STAT_OFC_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_SPI_STAT_OFC_POS) &
           (uint16)TLE9186_SPI_STAT_OFC_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SPI_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for SPI_STAT_OFC.
 *
 * This function clears the bitfield One SPI frame corrupted detection in
 * register SPI_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_SPI_STAT_OFC(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_SPI_STAT_OFC_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SPI_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SPI_STAT_OFC.
 *
 * This function returns the value of the bitfield One SPI frame corrupted
 * detection within register SPI_STAT.
 *
 * @return Value of the bitfield SPI_STAT_OFC:
 *      - 0: STAT_OFC_CONST_0 (no corrupted SPI frame detected since last clear
 * of OFC bit).
 *      - 1: STAT_OFC_CONST_1 (one corrupted SPI frame detected since last clear
 * of OFC bit).
 */
uint16 TLE9186_FuncLayer_get_SPI_STAT_OFC(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->SPI_STAT.bit.OFC;
}

/**
 * @brief Set function for SPI_STAT_CSN_TO.
 *
 * This function sets the bitfield CSN time-out detection in register SPI_STAT.
 *
 * @param u16_value Value to be written into SPI_STAT_CSN_TO. Valid values are:
 *      - 0: STAT_CSN_TO_CONST_0 (no CSN time-out detected).
 *      - 1: STAT_CSN_TO_CONST_1 (CSN time-out detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SPI_STAT_CSN_TO(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SPI_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SPI_STAT_CSN_TO_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_SPI_STAT_CSN_TO_POS) &
           (uint16)TLE9186_SPI_STAT_CSN_TO_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SPI_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for SPI_STAT_CSN_TO.
 *
 * This function clears the bitfield CSN time-out detection in register
 * SPI_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_SPI_STAT_CSN_TO(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_SPI_STAT_CSN_TO_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SPI_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SPI_STAT_CSN_TO.
 *
 * This function returns the value of the bitfield CSN time-out detection within
 * register SPI_STAT.
 *
 * @return Value of the bitfield SPI_STAT_CSN_TO:
 *      - 0: STAT_CSN_TO_CONST_0 (no CSN time-out detected).
 *      - 1: STAT_CSN_TO_CONST_1 (CSN time-out detected).
 */
uint16 TLE9186_FuncLayer_get_SPI_STAT_CSN_TO(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->SPI_STAT.bit.CSN_TO;
}

/**
 * @brief Set function for SPI_STAT_SDO_SHORT.
 *
 * This function sets the bitfield SDO short to supply or ground detection in
 * register SPI_STAT.
 *
 * @param u16_value Value to be written into SPI_STAT_SDO_SHORT. Valid values
 * are:
 *      - 0: STAT_SDO_SHORT_CONST_0 (no SDO short  detected).
 *      - 1: STAT_SDO_SHORT_CONST_1 (SDO short to supply or ground detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SPI_STAT_SDO_SHORT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SPI_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SPI_STAT_SDO_SHORT_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_SPI_STAT_SDO_SHORT_POS) &
           (uint16)TLE9186_SPI_STAT_SDO_SHORT_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SPI_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for SPI_STAT_SDO_SHORT.
 *
 * This function clears the bitfield SDO short to supply or ground detection in
 * register SPI_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_SPI_STAT_SDO_SHORT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_SPI_STAT_SDO_SHORT_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SPI_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SPI_STAT_SDO_SHORT.
 *
 * This function returns the value of the bitfield SDO short to supply or ground
 * detection within register SPI_STAT.
 *
 * @return Value of the bitfield SPI_STAT_SDO_SHORT:
 *      - 0: STAT_SDO_SHORT_CONST_0 (no SDO short  detected).
 *      - 1: STAT_SDO_SHORT_CONST_1 (SDO short to supply or ground detected).
 */
uint16 TLE9186_FuncLayer_get_SPI_STAT_SDO_SHORT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->SPI_STAT.bit.SDO_SHORT;
}

/**
 * @brief Set function for SPI_STAT_WDLE.
 *
 * This function sets the bitfield Watchdog latched error detection in register
 * SPI_STAT.
 *
 * @param u16_value Value to be written into SPI_STAT_WDLE. Valid values are:
 *      - 0: STAT_WDLE_CONST_0 (no watchdog latched error).
 *      - 1: STAT_WDLE_CONST_1 (watchdog latched error detected, WD_CNT reached
 * the WD_FAIL configured number of fails).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SPI_STAT_WDLE(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SPI_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SPI_STAT_WDLE_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_SPI_STAT_WDLE_POS) &
           (uint16)TLE9186_SPI_STAT_WDLE_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SPI_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for SPI_STAT_WDLE.
 *
 * This function clears the bitfield Watchdog latched error detection in
 * register SPI_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_SPI_STAT_WDLE(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_SPI_STAT_WDLE_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SPI_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SPI_STAT_WDLE.
 *
 * This function returns the value of the bitfield Watchdog latched error
 * detection within register SPI_STAT.
 *
 * @return Value of the bitfield SPI_STAT_WDLE:
 *      - 0: STAT_WDLE_CONST_0 (no watchdog latched error).
 *      - 1: STAT_WDLE_CONST_1 (watchdog latched error detected, WD_CNT reached
 * the WD_FAIL configured number of fails).
 */
uint16 TLE9186_FuncLayer_get_SPI_STAT_WDLE(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->SPI_STAT.bit.WDLE;
}

/**
 * @brief Get function for SPI_STAT_WDE.
 *
 * This function returns the value of the bitfield Watchdog error detection
 * within register SPI_STAT.
 *
 * @return Value of the bitfield SPI_STAT_WDE:
 *      - 0: STAT_WDE_CONST_0 (no incorrect watchdog service detected).
 *      - 1: STAT_WDE_CONST_1 (incorrect watchdog service detected).
 */
uint16 TLE9186_FuncLayer_get_SPI_STAT_WDE(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->SPI_STAT.bit.WDE;
}

/**
 * @brief Get function for SPI_STAT_WD_CNT.
 *
 * This function returns the value of the bitfield Watchdog fails counter within
 * register SPI_STAT.
 *
 * @return Value of the bitfield SPI_STAT_WD_CNT:
 *      - 0: STAT_WD_CNT_CONST_0 (no WD failure detected).
 *      - 1: STAT_WD_CNT_CONST_1 (1 WD failure detected).
 *      - 2: STAT_WD_CNT_CONST_2 (2 WD failures detected).
 *      - 3: STAT_WD_CNT_CONST_3 (3 WD failures detected).
 *      - 4: STAT_WD_CNT_CONST_4 (4 WD failures detected).
 *      - 5: STAT_WD_CNT_CONST_5 (5 WD failures detected).
 *      - 6: STAT_WD_CNT_CONST_6 (6 WD failures detected).
 *      - 7: STAT_WD_CNT_CONST_7 (7 WD failures detected).
 *      - 8: STAT_WD_CNT_CONST_8 (8 WD failures detected).
 *      - 9: STAT_WD_CNT_CONST_9 (9 WD failures detected).
 *      - 10: STAT_WD_CNT_CONST_10 (10 WD failures detected).
 *      - 11: STAT_WD_CNT_CONST_11 (11 WD failures detected).
 *      - 12: STAT_WD_CNT_CONST_12 (12 WD failures detected).
 *      - 13: STAT_WD_CNT_CONST_13 (13 WD failures detected).
 *      - 14: STAT_WD_CNT_CONST_14 (14 WD failures detected).
 *      - 15: STAT_WD_CNT_CONST_15 (15 WD failures detected).
 */
uint16 TLE9186_FuncLayer_get_SPI_STAT_WD_CNT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->SPI_STAT.bit.WD_CNT;
}

/**
 * @brief Set function for SPI_STAT_OTP_ERR.
 *
 * This function sets the bitfield OTP configuration error detection in register
 * SPI_STAT.
 *
 * @param u16_value Value to be written into SPI_STAT_OTP_ERR. Valid values are:
 *      - 0: STAT_OTP_ERR_CONST_0 (no OTP error detected during OTP readout).
 *      - 1: STAT_OTP_ERR_CONST_1 (OTP error detected during loading operation).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_SPI_STAT_OTP_ERR(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->SPI_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_SPI_STAT_OTP_ERR_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_SPI_STAT_OTP_ERR_POS) &
           (uint16)TLE9186_SPI_STAT_OTP_ERR_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SPI_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for SPI_STAT_OTP_ERR.
 *
 * This function clears the bitfield OTP configuration error detection in
 * register SPI_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_SPI_STAT_OTP_ERR(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)((uint16)1u << (uint16)TLE9186_SPI_STAT_OTP_ERR_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_SPI_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for SPI_STAT_OTP_ERR.
 *
 * This function returns the value of the bitfield OTP configuration error
 * detection within register SPI_STAT.
 *
 * @return Value of the bitfield SPI_STAT_OTP_ERR:
 *      - 0: STAT_OTP_ERR_CONST_0 (no OTP error detected during OTP readout).
 *      - 1: STAT_OTP_ERR_CONST_1 (OTP error detected during loading operation).
 */
uint16 TLE9186_FuncLayer_get_SPI_STAT_OTP_ERR(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->SPI_STAT.bit.OTP_ERR;
}

/**
 * @brief get function for register SPI_STAT.
 *
 * This function reads the register SPI status register (SPI and WD monitoring).
 *
 */
void TLE9186_FuncLayer_get_SPI_STAT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_SPI_STAT();
}

/**
 * @brief Set function for register DEV_STAT1.
 *
 * This function sets the Device status register 1: Operation mode and digital
 * input pins levels.
 *
 * @param u16_value Value to be written into the register DEV_STAT1.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_DEV_STAT1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for DEV_STAT1_ERR_N_LVL.
 *
 * This function returns the value of the bitfield ERR_N output pin level
 * monitoring (real time input pin monitoring) within register DEV_STAT1.
 *
 * @return Value of the bitfield DEV_STAT1_ERR_N_LVL:
 *      - 0: DEV_STAT1_ERR_N_LVL_CONST_0 (ERR_N pin voltage level detected as
 * low).
 *      - 1: DEV_STAT1_ERR_N_LVL_CONST_1 (ERR_N pin voltage level detected as
 * high).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT1_ERR_N_LVL(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->DEV_STAT1.bit.ERR_N_LVL;
}

/**
 * @brief Get function for DEV_STAT1_INH_N_LVL.
 *
 * This function returns the value of the bitfield INH_N input pin level
 * monitoring (real time input pin monitoring) within register DEV_STAT1.
 *
 * @return Value of the bitfield DEV_STAT1_INH_N_LVL:
 *      - 0: DEV_STAT1_INH_N_LVL_CONST_0 (INH_N pin voltage level detected as
 * low).
 *      - 1: DEV_STAT1_INH_N_LVL_CONST_1 (INH_N pin voltage level detected as
 * high).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT1_INH_N_LVL(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->DEV_STAT1.bit.INH_N_LVL;
}

/**
 * @brief Set function for DEV_STAT1_INHN_L_DET.
 *
 * This function sets the bitfield INH_N input pin low level detection (canceled
 * power-down event) in register DEV_STAT1.
 *
 * @param u16_value Value to be written into DEV_STAT1_INHN_L_DET. Valid values
 * are:
 *      - 0: DEV_STAT1_INHN_L_DET_CONST_0 (no INH_N pin voltage low level
 * detected during operation).
 *      - 1: DEV_STAT1_INHN_L_DET_CONST_1 (INH_N pin voltage low level detected
 * during operation).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_DEV_STAT1_INHN_L_DET(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->DEV_STAT1.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_DEV_STAT1_INHN_L_DET_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_DEV_STAT1_INHN_L_DET_POS) &
           (uint16)TLE9186_DEV_STAT1_INHN_L_DET_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for DEV_STAT1_INHN_L_DET.
 *
 * This function clears the bitfield INH_N input pin low level detection
 * (canceled power-down event) in register DEV_STAT1.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_DEV_STAT1_INHN_L_DET(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_DEV_STAT1_INHN_L_DET_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT1;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for DEV_STAT1_INHN_L_DET.
 *
 * This function returns the value of the bitfield INH_N input pin low level
 * detection (canceled power-down event) within register DEV_STAT1.
 *
 * @return Value of the bitfield DEV_STAT1_INHN_L_DET:
 *      - 0: DEV_STAT1_INHN_L_DET_CONST_0 (no INH_N pin voltage low level
 * detected during operation).
 *      - 1: DEV_STAT1_INHN_L_DET_CONST_1 (INH_N pin voltage low level detected
 * during operation).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT1_INHN_L_DET(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->DEV_STAT1.bit.INHN_L_DET;
}

/**
 * @brief Get function for DEV_STAT1_IL1_LVL.
 *
 * This function returns the value of the bitfield LS1 PWM input pin level
 * monitoring (real time input pin monitoring) within register DEV_STAT1.
 *
 * @return Value of the bitfield DEV_STAT1_IL1_LVL:
 *      - 0: DEV_STAT1_IL1_LVL_CONST_0 (IL1 pin voltage level detected as low).
 *      - 1: DEV_STAT1_IL1_LVL_CONST_1 (IL1 pin voltage level detected as high).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT1_IL1_LVL(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->DEV_STAT1.bit.IL1_LVL;
}

/**
 * @brief Get function for DEV_STAT1_IL2_LVL.
 *
 * This function returns the value of the bitfield LS2 PWM input pin level
 * monitoring (real time input pin monitoring) within register DEV_STAT1.
 *
 * @return Value of the bitfield DEV_STAT1_IL2_LVL:
 *      - 0: DEV_STAT1_IL2_LVL_CONST_0 (IL2 pin voltage level detected as low).
 *      - 1: DEV_STAT1_IL2_LVL_CONST_1 (IL2 pin voltage level detected as high).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT1_IL2_LVL(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->DEV_STAT1.bit.IL2_LVL;
}

/**
 * @brief Get function for DEV_STAT1_IL3_LVL.
 *
 * This function returns the value of the bitfield LS3 PWM input pin level
 * monitoring (real time input pin monitoring) within register DEV_STAT1.
 *
 * @return Value of the bitfield DEV_STAT1_IL3_LVL:
 *      - 0: DEV_STAT1_IL3_LVL_CONST_0 (IL3 pin voltage level detected as low).
 *      - 1: DEV_STAT1_IL3_LVL_CONST_1 (IL3 pin voltage level detected as high).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT1_IL3_LVL(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->DEV_STAT1.bit.IL3_LVL;
}

/**
 * @brief Get function for DEV_STAT1_IH1N_LVL.
 *
 * This function returns the value of the bitfield HS1 PWM input pin level
 * monitoring (real time input pin monitoring) within register DEV_STAT1.
 *
 * @return Value of the bitfield DEV_STAT1_IH1N_LVL:
 *      - 0: DEV_STAT1_IH1N_LVL_CONST_0 (IH1_N pin voltage level detected as
 * low).
 *      - 1: DEV_STAT1_IH1N_LVL_CONST_1 (IH1_N pin voltage level detected as
 * high).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT1_IH1N_LVL(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->DEV_STAT1.bit.IH1N_LVL;
}

/**
 * @brief Get function for DEV_STAT1_IH2N_LVL.
 *
 * This function returns the value of the bitfield HS2 PWM input pin level
 * monitoring (real time input pin monitoring) within register DEV_STAT1.
 *
 * @return Value of the bitfield DEV_STAT1_IH2N_LVL:
 *      - 0: DEV_STAT1_IH2N_LVL_CONST_0 (IH2_N pin voltage level detected as
 * low).
 *      - 1: DEV_STAT1_IH2N_LVL_CONST_1 (IH2_N pin voltage level detected as
 * high).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT1_IH2N_LVL(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->DEV_STAT1.bit.IH2N_LVL;
}

/**
 * @brief Get function for DEV_STAT1_IH3N_LVL.
 *
 * This function returns the value of the bitfield HS3 PWM input pin level
 * monitoring (real time input pin monitoring) within register DEV_STAT1.
 *
 * @return Value of the bitfield DEV_STAT1_IH3N_LVL:
 *      - 0: DEV_STAT1_IH3N_LVL_CONST_0 (IH3_N pin voltage level detected as
 * low).
 *      - 1: DEV_STAT1_IH3N_LVL_CONST_1 (IH3_N pin voltage level detected as
 * high).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT1_IH3N_LVL(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->DEV_STAT1.bit.IH3N_LVL;
}

/**
 * @brief Get function for DEV_STAT1_ERRN_ACT.
 *
 * This function returns the value of the bitfield ERR_N pin active low within
 * register DEV_STAT1.
 *
 * @return Value of the bitfield DEV_STAT1_ERRN_ACT:
 *      - 0: DEV_STAT1_ERRN_ACT_CONST_0 (ERRN pin not active).
 *      - 1: DEV_STAT1_ERRN_ACT_CONST_1 (ERRN pin activated ( active pull low)).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT1_ERRN_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->DEV_STAT1.bit.ERRN_ACT;
}

/**
 * @brief Get function for DEV_STAT1_SOFF_ACT.
 *
 * This function returns the value of the bitfield Safe state activation within
 * register DEV_STAT1.
 *
 * @return Value of the bitfield DEV_STAT1_SOFF_ACT:
 *      - 0: DEV_STAT1_SOFF_ACT_CONST_0 (safe state not active).
 *      - 1: DEV_STAT1_SOFF_ACT_CONST_1 (Safe state active).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT1_SOFF_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->DEV_STAT1.bit.SOFF_ACT;
}

/**
 * @brief Get function for DEV_STAT1_DEV_STAT.
 *
 * This function returns the value of the bitfield Device operation mode status
 * information within register DEV_STAT1.
 *
 * @return Value of the bitfield DEV_STAT1_DEV_STAT:
 *      - 0: DEV_STAT1_DEV_STAT_CONST_0 (invalid setting).
 *      - 1: DEV_STAT1_DEV_STAT_CONST_1 (device in power-up mode).
 *      - 2: DEV_STAT1_DEV_STAT_CONST_2 (device in normal mode).
 *      - 3: DEV_STAT1_DEV_STAT_CONST_3 (invalid setting).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT1_DEV_STAT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->DEV_STAT1.bit.DEV_STAT;
}

/**
 * @brief get function for register DEV_STAT1.
 *
 * This function reads the register Device status register 1: Operation mode and
 * digital input pins levels.
 *
 */
void TLE9186_FuncLayer_get_DEV_STAT1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_DEV_STAT1();
}

/**
 * @brief Set function for register DEV_STAT2.
 *
 * This function sets the Device status register 2: Input pattern violation,
 * ERR_N, CSA, TSD monitoring.
 *
 * @param u16_value Value to be written into the register DEV_STAT2.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_DEV_STAT2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for DEV_STAT2_TSD_CP.
 *
 * This function sets the bitfield Charge pump overtemperature detection in
 * register DEV_STAT2.
 *
 * @param u16_value Value to be written into DEV_STAT2_TSD_CP. Valid values are:
 *      - 0: DEV_STAT2_TSD_CP_CONST_0 (no charge pump over-temperature
 * detected).
 *      - 1: DEV_STAT2_TSD_CP_CONST_1 (charge pump over-temperature detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_DEV_STAT2_TSD_CP(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->DEV_STAT2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_DEV_STAT2_TSD_CP_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_DEV_STAT2_TSD_CP_POS) &
           (uint16)TLE9186_DEV_STAT2_TSD_CP_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for DEV_STAT2_TSD_CP.
 *
 * This function clears the bitfield Charge pump overtemperature detection in
 * register DEV_STAT2.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_DEV_STAT2_TSD_CP(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_DEV_STAT2_TSD_CP_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for DEV_STAT2_TSD_CP.
 *
 * This function returns the value of the bitfield Charge pump overtemperature
 * detection within register DEV_STAT2.
 *
 * @return Value of the bitfield DEV_STAT2_TSD_CP:
 *      - 0: DEV_STAT2_TSD_CP_CONST_0 (no charge pump over-temperature
 * detected).
 *      - 1: DEV_STAT2_TSD_CP_CONST_1 (charge pump over-temperature detected).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT2_TSD_CP(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->DEV_STAT2.bit.TSD_CP;
}

/**
 * @brief Set function for DEV_STAT2_TSD_IC.
 *
 * This function sets the bitfield General overtemperature shutdown detection in
 * register DEV_STAT2.
 *
 * @param u16_value Value to be written into DEV_STAT2_TSD_IC. Valid values are:
 *      - 0: DEV_STAT2_TSD_IC_CONST_0 (no general IC over temperature detected).
 *      - 1: DEV_STAT2_TSD_IC_CONST_1 (general IC over temperature event
 * detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_DEV_STAT2_TSD_IC(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->DEV_STAT2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_DEV_STAT2_TSD_IC_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_DEV_STAT2_TSD_IC_POS) &
           (uint16)TLE9186_DEV_STAT2_TSD_IC_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for DEV_STAT2_TSD_IC.
 *
 * This function clears the bitfield General overtemperature shutdown detection
 * in register DEV_STAT2.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_DEV_STAT2_TSD_IC(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_DEV_STAT2_TSD_IC_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for DEV_STAT2_TSD_IC.
 *
 * This function returns the value of the bitfield General overtemperature
 * shutdown detection within register DEV_STAT2.
 *
 * @return Value of the bitfield DEV_STAT2_TSD_IC:
 *      - 0: DEV_STAT2_TSD_IC_CONST_0 (no general IC over temperature detected).
 *      - 1: DEV_STAT2_TSD_IC_CONST_1 (general IC over temperature event
 * detected).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT2_TSD_IC(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->DEV_STAT2.bit.TSD_IC;
}

/**
 * @brief Set function for DEV_STAT2_TSDW.
 *
 * This function sets the bitfield Over temperature warning detection in
 * register DEV_STAT2.
 *
 * @param u16_value Value to be written into DEV_STAT2_TSDW. Valid values are:
 *      - 0: DEV_STAT2_TSDW_CONST_0 (no over temperature warning detected).
 *      - 1: DEV_STAT2_TSDW_CONST_1 (over temperature warning detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_DEV_STAT2_TSDW(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->DEV_STAT2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_DEV_STAT2_TSDW_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_DEV_STAT2_TSDW_POS) &
           (uint16)TLE9186_DEV_STAT2_TSDW_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for DEV_STAT2_TSDW.
 *
 * This function clears the bitfield Over temperature warning detection in
 * register DEV_STAT2.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_DEV_STAT2_TSDW(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_DEV_STAT2_TSDW_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for DEV_STAT2_TSDW.
 *
 * This function returns the value of the bitfield Over temperature warning
 * detection within register DEV_STAT2.
 *
 * @return Value of the bitfield DEV_STAT2_TSDW:
 *      - 0: DEV_STAT2_TSDW_CONST_0 (no over temperature warning detected).
 *      - 1: DEV_STAT2_TSDW_CONST_1 (over temperature warning detected).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT2_TSDW(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->DEV_STAT2.bit.TSDW;
}

/**
 * @brief Set function for DEV_STAT2_CSA_OC.
 *
 * This function sets the bitfield CSA overcurrent detection in register
 * DEV_STAT2.
 *
 * @param u16_value Value to be written into DEV_STAT2_CSA_OC. Valid values are:
 *      - 0: DEV_STAT2_CSA_OC_CONST_0 (no CSA over current detected).
 *      - 1: DEV_STAT2_CSA_OC_CONST_1 (CSA over current detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_DEV_STAT2_CSA_OC(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->DEV_STAT2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_DEV_STAT2_CSA_OC_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_DEV_STAT2_CSA_OC_POS) &
           (uint16)TLE9186_DEV_STAT2_CSA_OC_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for DEV_STAT2_CSA_OC.
 *
 * This function clears the bitfield CSA overcurrent detection in register
 * DEV_STAT2.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_DEV_STAT2_CSA_OC(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_DEV_STAT2_CSA_OC_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for DEV_STAT2_CSA_OC.
 *
 * This function returns the value of the bitfield CSA overcurrent detection
 * within register DEV_STAT2.
 *
 * @return Value of the bitfield DEV_STAT2_CSA_OC:
 *      - 0: DEV_STAT2_CSA_OC_CONST_0 (no CSA over current detected).
 *      - 1: DEV_STAT2_CSA_OC_CONST_1 (CSA over current detected).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT2_CSA_OC(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->DEV_STAT2.bit.CSA_OC;
}

/**
 * @brief Set function for DEV_STAT2_ERRN_SHORT.
 *
 * This function sets the bitfield ERR_N pin short to supply detection in
 * register DEV_STAT2.
 *
 * @param u16_value Value to be written into DEV_STAT2_ERRN_SHORT. Valid values
 * are:
 *      - 0: DEV_STAT2_ERRN_SHORT_CONST_0 (no ERRN pin short to supply
 * detected).
 *      - 1: DEV_STAT2_ERRN_SHORT_CONST_1 (ERRN pin short to supply detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_DEV_STAT2_ERRN_SHORT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->DEV_STAT2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_DEV_STAT2_ERRN_SHORT_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_DEV_STAT2_ERRN_SHORT_POS) &
           (uint16)TLE9186_DEV_STAT2_ERRN_SHORT_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for DEV_STAT2_ERRN_SHORT.
 *
 * This function clears the bitfield ERR_N pin short to supply detection in
 * register DEV_STAT2.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_DEV_STAT2_ERRN_SHORT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_DEV_STAT2_ERRN_SHORT_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for DEV_STAT2_ERRN_SHORT.
 *
 * This function returns the value of the bitfield ERR_N pin short to supply
 * detection within register DEV_STAT2.
 *
 * @return Value of the bitfield DEV_STAT2_ERRN_SHORT:
 *      - 0: DEV_STAT2_ERRN_SHORT_CONST_0 (no ERRN pin short to supply
 * detected).
 *      - 1: DEV_STAT2_ERRN_SHORT_CONST_1 (ERRN pin short to supply detected).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT2_ERRN_SHORT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->DEV_STAT2.bit.ERRN_SHORT;
}

/**
 * @brief Set function for DEV_STAT2_PFB1_LE.
 *
 * This function sets the bitfield Phase feedback monitoring of SH1 latched
 * error detection in register DEV_STAT2.
 *
 * @param u16_value Value to be written into DEV_STAT2_PFB1_LE. Valid values
 * are:
 *      - 0: DEV_STAT2_PFB1_LE_CONST_0 (no phase feedback error detected).
 *      - 1: DEV_STAT2_PFB1_LE_CONST_1 (phase feedback latched error detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_DEV_STAT2_PFB1_LE(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->DEV_STAT2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_DEV_STAT2_PFB1_LE_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_DEV_STAT2_PFB1_LE_POS) &
           (uint16)TLE9186_DEV_STAT2_PFB1_LE_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for DEV_STAT2_PFB1_LE.
 *
 * This function clears the bitfield Phase feedback monitoring of SH1 latched
 * error detection in register DEV_STAT2.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_DEV_STAT2_PFB1_LE(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_DEV_STAT2_PFB1_LE_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for DEV_STAT2_PFB1_LE.
 *
 * This function returns the value of the bitfield Phase feedback monitoring of
 * SH1 latched error detection within register DEV_STAT2.
 *
 * @return Value of the bitfield DEV_STAT2_PFB1_LE:
 *      - 0: DEV_STAT2_PFB1_LE_CONST_0 (no phase feedback error detected).
 *      - 1: DEV_STAT2_PFB1_LE_CONST_1 (phase feedback latched error detected).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT2_PFB1_LE(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->DEV_STAT2.bit.PFB1_LE;
}

/**
 * @brief Set function for DEV_STAT2_PFB2_LE.
 *
 * This function sets the bitfield Phase feedback monitoring of SH2 latched
 * error detection in register DEV_STAT2.
 *
 * @param u16_value Value to be written into DEV_STAT2_PFB2_LE. Valid values
 * are:
 *      - 0: DEV_STAT2_PFB2_LE_CONST_0 (no phase feedback error detected).
 *      - 1: DEV_STAT2_PFB2_LE_CONST_1 (phase feedback latched error detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_DEV_STAT2_PFB2_LE(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->DEV_STAT2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_DEV_STAT2_PFB2_LE_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_DEV_STAT2_PFB2_LE_POS) &
           (uint16)TLE9186_DEV_STAT2_PFB2_LE_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for DEV_STAT2_PFB2_LE.
 *
 * This function clears the bitfield Phase feedback monitoring of SH2 latched
 * error detection in register DEV_STAT2.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_DEV_STAT2_PFB2_LE(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_DEV_STAT2_PFB2_LE_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for DEV_STAT2_PFB2_LE.
 *
 * This function returns the value of the bitfield Phase feedback monitoring of
 * SH2 latched error detection within register DEV_STAT2.
 *
 * @return Value of the bitfield DEV_STAT2_PFB2_LE:
 *      - 0: DEV_STAT2_PFB2_LE_CONST_0 (no phase feedback error detected).
 *      - 1: DEV_STAT2_PFB2_LE_CONST_1 (phase feedback latched error detected).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT2_PFB2_LE(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->DEV_STAT2.bit.PFB2_LE;
}

/**
 * @brief Set function for DEV_STAT2_PFB3_LE.
 *
 * This function sets the bitfield Phase feedback monitoring of SH3 latched
 * error detection in register DEV_STAT2.
 *
 * @param u16_value Value to be written into DEV_STAT2_PFB3_LE. Valid values
 * are:
 *      - 0: DEV_STAT2_PFB3_LE_CONST_0 (no phase feedback error detected).
 *      - 1: DEV_STAT2_PFB3_LE_CONST_1 (phase feedback latched error detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_DEV_STAT2_PFB3_LE(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->DEV_STAT2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_DEV_STAT2_PFB3_LE_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_DEV_STAT2_PFB3_LE_POS) &
           (uint16)TLE9186_DEV_STAT2_PFB3_LE_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for DEV_STAT2_PFB3_LE.
 *
 * This function clears the bitfield Phase feedback monitoring of SH3 latched
 * error detection in register DEV_STAT2.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_DEV_STAT2_PFB3_LE(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_DEV_STAT2_PFB3_LE_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for DEV_STAT2_PFB3_LE.
 *
 * This function returns the value of the bitfield Phase feedback monitoring of
 * SH3 latched error detection within register DEV_STAT2.
 *
 * @return Value of the bitfield DEV_STAT2_PFB3_LE:
 *      - 0: DEV_STAT2_PFB3_LE_CONST_0 (no phase feedback error detected).
 *      - 1: DEV_STAT2_PFB3_LE_CONST_1 (phase feedback latched error detected).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT2_PFB3_LE(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->DEV_STAT2.bit.PFB3_LE;
}

/**
 * @brief Set function for DEV_STAT2_IPV_STP_HB1.
 *
 * This function sets the bitfield Half-bridge 1 input pattern violation due to
 * shoot-through protection in register DEV_STAT2.
 *
 * @param u16_value Value to be written into DEV_STAT2_IPV_STP_HB1. Valid values
 * are:
 *      - 0: DEV_STAT2_IPV_STP_HB1_CONST_0 (no shoot-through protection pattern
 * violation for HB1).
 *      - 1: DEV_STAT2_IPV_STP_HB1_CONST_1 (shoot-through protection input
 * pattern violation for HB1).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_DEV_STAT2_IPV_STP_HB1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->DEV_STAT2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_DEV_STAT2_IPV_STP_HB1_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_DEV_STAT2_IPV_STP_HB1_POS) &
           (uint16)TLE9186_DEV_STAT2_IPV_STP_HB1_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for DEV_STAT2_IPV_STP_HB1.
 *
 * This function clears the bitfield Half-bridge 1 input pattern violation due
 * to shoot-through protection in register DEV_STAT2.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_DEV_STAT2_IPV_STP_HB1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)((uint16)1u << (uint16)TLE9186_DEV_STAT2_IPV_STP_HB1_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for DEV_STAT2_IPV_STP_HB1.
 *
 * This function returns the value of the bitfield Half-bridge 1 input pattern
 * violation due to shoot-through protection within register DEV_STAT2.
 *
 * @return Value of the bitfield DEV_STAT2_IPV_STP_HB1:
 *      - 0: DEV_STAT2_IPV_STP_HB1_CONST_0 (no shoot-through protection pattern
 * violation for HB1).
 *      - 1: DEV_STAT2_IPV_STP_HB1_CONST_1 (shoot-through protection input
 * pattern violation for HB1).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT2_IPV_STP_HB1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->DEV_STAT2.bit.IPV_STP_HB1;
}

/**
 * @brief Set function for DEV_STAT2_IPV_STP_HB2.
 *
 * This function sets the bitfield Half-bridge 2 input pattern violation due to
 * shoot-through protection in register DEV_STAT2.
 *
 * @param u16_value Value to be written into DEV_STAT2_IPV_STP_HB2. Valid values
 * are:
 *      - 0: DEV_STAT2_IPV_STP_HB2_CONST_0 (no shoot-through protection input
 * pattern violation for HB2).
 *      - 1: DEV_STAT2_IPV_STP_HB2_CONST_1 (shoot-through protection input
 * pattern violation for HB2).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_DEV_STAT2_IPV_STP_HB2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->DEV_STAT2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_DEV_STAT2_IPV_STP_HB2_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_DEV_STAT2_IPV_STP_HB2_POS) &
           (uint16)TLE9186_DEV_STAT2_IPV_STP_HB2_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for DEV_STAT2_IPV_STP_HB2.
 *
 * This function clears the bitfield Half-bridge 2 input pattern violation due
 * to shoot-through protection in register DEV_STAT2.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_DEV_STAT2_IPV_STP_HB2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)((uint16)1u << (uint16)TLE9186_DEV_STAT2_IPV_STP_HB2_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for DEV_STAT2_IPV_STP_HB2.
 *
 * This function returns the value of the bitfield Half-bridge 2 input pattern
 * violation due to shoot-through protection within register DEV_STAT2.
 *
 * @return Value of the bitfield DEV_STAT2_IPV_STP_HB2:
 *      - 0: DEV_STAT2_IPV_STP_HB2_CONST_0 (no shoot-through protection input
 * pattern violation for HB2).
 *      - 1: DEV_STAT2_IPV_STP_HB2_CONST_1 (shoot-through protection input
 * pattern violation for HB2).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT2_IPV_STP_HB2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->DEV_STAT2.bit.IPV_STP_HB2;
}

/**
 * @brief Set function for DEV_STAT2_IPV_STP_HB3.
 *
 * This function sets the bitfield Half-bridge 3 input pattern violation due to
 * shoot-through protection in register DEV_STAT2.
 *
 * @param u16_value Value to be written into DEV_STAT2_IPV_STP_HB3. Valid values
 * are:
 *      - 0: DEV_STAT2_IPV_STP_HB3_CONST_0 (no shoot-through protection input
 * pattern violation for HB3).
 *      - 1: DEV_STAT2_IPV_STP_HB3_CONST_1 (shoot-through protection input
 * pattern violation for HB3).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_DEV_STAT2_IPV_STP_HB3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->DEV_STAT2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_DEV_STAT2_IPV_STP_HB3_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_DEV_STAT2_IPV_STP_HB3_POS) &
           (uint16)TLE9186_DEV_STAT2_IPV_STP_HB3_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for DEV_STAT2_IPV_STP_HB3.
 *
 * This function clears the bitfield Half-bridge 3 input pattern violation due
 * to shoot-through protection in register DEV_STAT2.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_DEV_STAT2_IPV_STP_HB3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)((uint16)1u << (uint16)TLE9186_DEV_STAT2_IPV_STP_HB3_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for DEV_STAT2_IPV_STP_HB3.
 *
 * This function returns the value of the bitfield Half-bridge 3 input pattern
 * violation due to shoot-through protection within register DEV_STAT2.
 *
 * @return Value of the bitfield DEV_STAT2_IPV_STP_HB3:
 *      - 0: DEV_STAT2_IPV_STP_HB3_CONST_0 (no shoot-through protection input
 * pattern violation for HB3).
 *      - 1: DEV_STAT2_IPV_STP_HB3_CONST_1 (shoot-through protection input
 * pattern violation for HB3).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT2_IPV_STP_HB3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->DEV_STAT2.bit.IPV_STP_HB3;
}

/**
 * @brief Set function for DEV_STAT2_IPV_CCP_HB1.
 *
 * This function sets the bitfield Half-bridge 1 input pattern violation due to
 * cross-current protection in register DEV_STAT2.
 *
 * @param u16_value Value to be written into DEV_STAT2_IPV_CCP_HB1. Valid values
 * are:
 *      - 0: DEV_STAT2_IPV_CCP_HB1_CONST_0 (no cross-current input pattern
 * violation for HB1).
 *      - 1: DEV_STAT2_IPV_CCP_HB1_CONST_1 (cross-current input pattern
 * violation for HB1).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_DEV_STAT2_IPV_CCP_HB1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->DEV_STAT2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_DEV_STAT2_IPV_CCP_HB1_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_DEV_STAT2_IPV_CCP_HB1_POS) &
           (uint16)TLE9186_DEV_STAT2_IPV_CCP_HB1_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for DEV_STAT2_IPV_CCP_HB1.
 *
 * This function clears the bitfield Half-bridge 1 input pattern violation due
 * to cross-current protection in register DEV_STAT2.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_DEV_STAT2_IPV_CCP_HB1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)((uint16)1u << (uint16)TLE9186_DEV_STAT2_IPV_CCP_HB1_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for DEV_STAT2_IPV_CCP_HB1.
 *
 * This function returns the value of the bitfield Half-bridge 1 input pattern
 * violation due to cross-current protection within register DEV_STAT2.
 *
 * @return Value of the bitfield DEV_STAT2_IPV_CCP_HB1:
 *      - 0: DEV_STAT2_IPV_CCP_HB1_CONST_0 (no cross-current input pattern
 * violation for HB1).
 *      - 1: DEV_STAT2_IPV_CCP_HB1_CONST_1 (cross-current input pattern
 * violation for HB1).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT2_IPV_CCP_HB1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->DEV_STAT2.bit.IPV_CCP_HB1;
}

/**
 * @brief Set function for DEV_STAT2_IPV_CCP_HB2.
 *
 * This function sets the bitfield Half-bridge 2 input pattern violation due to
 * cross-current protection in register DEV_STAT2.
 *
 * @param u16_value Value to be written into DEV_STAT2_IPV_CCP_HB2. Valid values
 * are:
 *      - 0: DEV_STAT2_IPV_CCP_HB2_CONST_0 (no cross-current input pattern
 * violation for HB2).
 *      - 1: DEV_STAT2_IPV_CCP_HB2_CONST_1 (cross-current input pattern
 * violation for HB2).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_DEV_STAT2_IPV_CCP_HB2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->DEV_STAT2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_DEV_STAT2_IPV_CCP_HB2_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_DEV_STAT2_IPV_CCP_HB2_POS) &
           (uint16)TLE9186_DEV_STAT2_IPV_CCP_HB2_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for DEV_STAT2_IPV_CCP_HB2.
 *
 * This function clears the bitfield Half-bridge 2 input pattern violation due
 * to cross-current protection in register DEV_STAT2.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_DEV_STAT2_IPV_CCP_HB2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)((uint16)1u << (uint16)TLE9186_DEV_STAT2_IPV_CCP_HB2_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for DEV_STAT2_IPV_CCP_HB2.
 *
 * This function returns the value of the bitfield Half-bridge 2 input pattern
 * violation due to cross-current protection within register DEV_STAT2.
 *
 * @return Value of the bitfield DEV_STAT2_IPV_CCP_HB2:
 *      - 0: DEV_STAT2_IPV_CCP_HB2_CONST_0 (no cross-current input pattern
 * violation for HB2).
 *      - 1: DEV_STAT2_IPV_CCP_HB2_CONST_1 (cross-current input pattern
 * violation for HB2).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT2_IPV_CCP_HB2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->DEV_STAT2.bit.IPV_CCP_HB2;
}

/**
 * @brief Set function for DEV_STAT2_IPV_CCP_HB3.
 *
 * This function sets the bitfield Half-bridge 3 input pattern violation due to
 * cross-current protection in register DEV_STAT2.
 *
 * @param u16_value Value to be written into DEV_STAT2_IPV_CCP_HB3. Valid values
 * are:
 *      - 0: DEV_STAT2_IPV_CCP_HB3_CONST_0 (no cross-current input pattern
 * violation for HB3).
 *      - 1: DEV_STAT2_IPV_CCP_HB3_CONST_1 (cross-current input pattern
 * violation for HB3).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_DEV_STAT2_IPV_CCP_HB3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->DEV_STAT2.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_DEV_STAT2_IPV_CCP_HB3_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_DEV_STAT2_IPV_CCP_HB3_POS) &
           (uint16)TLE9186_DEV_STAT2_IPV_CCP_HB3_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for DEV_STAT2_IPV_CCP_HB3.
 *
 * This function clears the bitfield Half-bridge 3 input pattern violation due
 * to cross-current protection in register DEV_STAT2.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_DEV_STAT2_IPV_CCP_HB3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)((uint16)1u << (uint16)TLE9186_DEV_STAT2_IPV_CCP_HB3_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_DEV_STAT2;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for DEV_STAT2_IPV_CCP_HB3.
 *
 * This function returns the value of the bitfield Half-bridge 3 input pattern
 * violation due to cross-current protection within register DEV_STAT2.
 *
 * @return Value of the bitfield DEV_STAT2_IPV_CCP_HB3:
 *      - 0: DEV_STAT2_IPV_CCP_HB3_CONST_0 (no cross-current input pattern
 * violation for HB3).
 *      - 1: DEV_STAT2_IPV_CCP_HB3_CONST_1 (cross-current input pattern
 * violation for HB3).
 */
uint16 TLE9186_FuncLayer_get_DEV_STAT2_IPV_CCP_HB3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->DEV_STAT2.bit.IPV_CCP_HB3;
}

/**
 * @brief get function for register DEV_STAT2.
 *
 * This function reads the register Device status register 2: Input pattern
 * violation, ERR_N, CSA, TSD monitoring.
 *
 */
void TLE9186_FuncLayer_get_DEV_STAT2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_DEV_STAT2();
}

/**
 * @brief Set function for register LF_STAT.
 *
 * This function sets the Latent faults and self-tests status register: internal
 * faults, self-tests results.
 *
 * @param u16_value Value to be written into the register LF_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_LF_STAT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_LF_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for LF_STAT_ST_RES.
 *
 * This function returns the value of the bitfield Self-test result within
 * register LF_STAT.
 *
 * @return Value of the bitfield LF_STAT_ST_RES:
 *      - 0: LF_STAT_ST_RES_CONST_1 (no self-test enabled or at least one
 * self-test not successful).
 *      - 1: LF_STAT_ST_RES_CONST_0 (all self-test performed (in parallel) were
 * successful).
 */
uint16 TLE9186_FuncLayer_get_LF_STAT_ST_RES(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->LF_STAT.bit.ST_RES;
}

/**
 * @brief Set function for LF_STAT_ST_RDY.
 *
 * This function sets the bitfield Self-test status in register LF_STAT.
 *
 * @param u16_value Value to be written into LF_STAT_ST_RDY. Valid values are:
 *      - 0: LF_STAT_ST_RDY_CONST_1 (self-test not enabled or self-test
 * running).
 *      - 1: LF_STAT_ST_RDY_CONST_0 (self-test finished).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_LF_STAT_ST_RDY(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->LF_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_LF_STAT_ST_RDY_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_LF_STAT_ST_RDY_POS) &
           (uint16)TLE9186_LF_STAT_ST_RDY_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_LF_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for LF_STAT_ST_RDY.
 *
 * This function clears the bitfield Self-test status in register LF_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_LF_STAT_ST_RDY(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_LF_STAT_ST_RDY_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_LF_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for LF_STAT_ST_RDY.
 *
 * This function returns the value of the bitfield Self-test status within
 * register LF_STAT.
 *
 * @return Value of the bitfield LF_STAT_ST_RDY:
 *      - 0: LF_STAT_ST_RDY_CONST_1 (self-test not enabled or self-test
 * running).
 *      - 1: LF_STAT_ST_RDY_CONST_0 (self-test finished).
 */
uint16 TLE9186_FuncLayer_get_LF_STAT_ST_RDY(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->LF_STAT.bit.ST_RDY;
}

/**
 * @brief Set function for LF_STAT_LAT_FAULT.
 *
 * This function sets the bitfield Internal latent fault detection in register
 * LF_STAT.
 *
 * @param u16_value Value to be written into LF_STAT_LAT_FAULT. Valid values
 * are:
 *      - 0: LF_STAT_LAT_FAULT_CONST_1 (no internal latent fault detected).
 *      - 1: LF_STAT_LAT_FAULT_CONST_0 (internal latent fault detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_LF_STAT_LAT_FAULT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->LF_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_LF_STAT_LAT_FAULT_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_LF_STAT_LAT_FAULT_POS) &
           (uint16)TLE9186_LF_STAT_LAT_FAULT_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_LF_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for LF_STAT_LAT_FAULT.
 *
 * This function clears the bitfield Internal latent fault detection in register
 * LF_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_LF_STAT_LAT_FAULT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_LF_STAT_LAT_FAULT_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_LF_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for LF_STAT_LAT_FAULT.
 *
 * This function returns the value of the bitfield Internal latent fault
 * detection within register LF_STAT.
 *
 * @return Value of the bitfield LF_STAT_LAT_FAULT:
 *      - 0: LF_STAT_LAT_FAULT_CONST_1 (no internal latent fault detected).
 *      - 1: LF_STAT_LAT_FAULT_CONST_0 (internal latent fault detected).
 */
uint16 TLE9186_FuncLayer_get_LF_STAT_LAT_FAULT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->LF_STAT.bit.LAT_FAULT;
}

/**
 * @brief Set function for LF_STAT_DSOV_LF_HB1.
 *
 * This function sets the bitfield Half-bridge 1 drain-source monitor latent
 * fault detection in register LF_STAT.
 *
 * @param u16_value Value to be written into LF_STAT_DSOV_LF_HB1. Valid values
 * are:
 *      - 0: LF_STAT_DSOV_LF_HB1_CONST_0 (no Drain-Source monitoring latent
 * fault detected in HB1).
 *      - 1: LF_STAT_DSOV_LF_HB1_CONST_1 (Drain-Source monitoring latent fault
 * detected in HB1).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_LF_STAT_DSOV_LF_HB1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->LF_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_LF_STAT_DSOV_LF_HB1_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_LF_STAT_DSOV_LF_HB1_POS) &
           (uint16)TLE9186_LF_STAT_DSOV_LF_HB1_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_LF_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for LF_STAT_DSOV_LF_HB1.
 *
 * This function clears the bitfield Half-bridge 1 drain-source monitor latent
 * fault detection in register LF_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_LF_STAT_DSOV_LF_HB1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_LF_STAT_DSOV_LF_HB1_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_LF_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for LF_STAT_DSOV_LF_HB1.
 *
 * This function returns the value of the bitfield Half-bridge 1 drain-source
 * monitor latent fault detection within register LF_STAT.
 *
 * @return Value of the bitfield LF_STAT_DSOV_LF_HB1:
 *      - 0: LF_STAT_DSOV_LF_HB1_CONST_0 (no Drain-Source monitoring latent
 * fault detected in HB1).
 *      - 1: LF_STAT_DSOV_LF_HB1_CONST_1 (Drain-Source monitoring latent fault
 * detected in HB1).
 */
uint16 TLE9186_FuncLayer_get_LF_STAT_DSOV_LF_HB1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->LF_STAT.bit.DSOV_LF_HB1;
}

/**
 * @brief Set function for LF_STAT_DSOV_LF_HB2.
 *
 * This function sets the bitfield Half-bridge 2 drain-source monitor latent
 * fault detection in register LF_STAT.
 *
 * @param u16_value Value to be written into LF_STAT_DSOV_LF_HB2. Valid values
 * are:
 *      - 0: LF_STAT_DSOV_LF_HB2_CONST_0 (no Drain-Source monitoring latent
 * fault detected in HB2).
 *      - 1: LF_STAT_DSOV_LF_HB2_CONST_1 (Drain-Source monitoring latent fault
 * detected in HB2).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_LF_STAT_DSOV_LF_HB2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->LF_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_LF_STAT_DSOV_LF_HB2_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_LF_STAT_DSOV_LF_HB2_POS) &
           (uint16)TLE9186_LF_STAT_DSOV_LF_HB2_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_LF_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for LF_STAT_DSOV_LF_HB2.
 *
 * This function clears the bitfield Half-bridge 2 drain-source monitor latent
 * fault detection in register LF_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_LF_STAT_DSOV_LF_HB2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_LF_STAT_DSOV_LF_HB2_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_LF_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for LF_STAT_DSOV_LF_HB2.
 *
 * This function returns the value of the bitfield Half-bridge 2 drain-source
 * monitor latent fault detection within register LF_STAT.
 *
 * @return Value of the bitfield LF_STAT_DSOV_LF_HB2:
 *      - 0: LF_STAT_DSOV_LF_HB2_CONST_0 (no Drain-Source monitoring latent
 * fault detected in HB2).
 *      - 1: LF_STAT_DSOV_LF_HB2_CONST_1 (Drain-Source monitoring latent fault
 * detected in HB2).
 */
uint16 TLE9186_FuncLayer_get_LF_STAT_DSOV_LF_HB2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->LF_STAT.bit.DSOV_LF_HB2;
}

/**
 * @brief Set function for LF_STAT_DSOV_LF_HB3.
 *
 * This function sets the bitfield Half-bridge 3 drain-source monitor latent
 * fault detection in register LF_STAT.
 *
 * @param u16_value Value to be written into LF_STAT_DSOV_LF_HB3. Valid values
 * are:
 *      - 0: LF_STAT_DSOV_LF_HB3_CONST_0 (no Drain-Source monitoring latent
 * fault detected in HB3).
 *      - 1: LF_STAT_DSOV_LF_HB3_CONST_1 (Drain-Source monitoring latent fault
 * detected in HB3).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_LF_STAT_DSOV_LF_HB3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
                       * to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->LF_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_LF_STAT_DSOV_LF_HB3_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_LF_STAT_DSOV_LF_HB3_POS) &
           (uint16)TLE9186_LF_STAT_DSOV_LF_HB3_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_LF_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for LF_STAT_DSOV_LF_HB3.
 *
 * This function clears the bitfield Half-bridge 3 drain-source monitor latent
 * fault detection in register LF_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_LF_STAT_DSOV_LF_HB3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_LF_STAT_DSOV_LF_HB3_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_LF_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for LF_STAT_DSOV_LF_HB3.
 *
 * This function returns the value of the bitfield Half-bridge 3 drain-source
 * monitor latent fault detection within register LF_STAT.
 *
 * @return Value of the bitfield LF_STAT_DSOV_LF_HB3:
 *      - 0: LF_STAT_DSOV_LF_HB3_CONST_0 (no Drain-Source monitoring latent
 * fault detected in HB3).
 *      - 1: LF_STAT_DSOV_LF_HB3_CONST_1 (Drain-Source monitoring latent fault
 * detected in HB3).
 */
uint16 TLE9186_FuncLayer_get_LF_STAT_DSOV_LF_HB3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->LF_STAT.bit.DSOV_LF_HB3;
}

/**
 * @brief Set function for LF_STAT_BIAS_LF.
 *
 * This function sets the bitfield Central bias monitoring latent fault
 * detection in register LF_STAT.
 *
 * @param u16_value Value to be written into LF_STAT_BIAS_LF. Valid values are:
 *      - 0: LF_STAT_BIAS_LF_CONST_0 (no bias monitoring latent fault detected).
 *      - 1: LF_STAT_BIAS_LF_CONST_1 (central bias monitoring latent fault
 * detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_LF_STAT_BIAS_LF(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->LF_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_LF_STAT_BIAS_LF_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_LF_STAT_BIAS_LF_POS) &
           (uint16)TLE9186_LF_STAT_BIAS_LF_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_LF_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for LF_STAT_BIAS_LF.
 *
 * This function clears the bitfield Central bias monitoring latent fault
 * detection in register LF_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_LF_STAT_BIAS_LF(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)((uint16)1u << (uint16)TLE9186_LF_STAT_BIAS_LF_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_LF_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for LF_STAT_BIAS_LF.
 *
 * This function returns the value of the bitfield Central bias monitoring
 * latent fault detection within register LF_STAT.
 *
 * @return Value of the bitfield LF_STAT_BIAS_LF:
 *      - 0: LF_STAT_BIAS_LF_CONST_0 (no bias monitoring latent fault detected).
 *      - 1: LF_STAT_BIAS_LF_CONST_1 (central bias monitoring latent fault
 * detected).
 */
uint16 TLE9186_FuncLayer_get_LF_STAT_BIAS_LF(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->LF_STAT.bit.BIAS_LF;
}

/**
 * @brief Get function for LF_STAT_SOFF_GDRV.
 *
 * This function returns the value of the bitfield Safe state entry indication
 * with all 6 gate drivers within register LF_STAT.
 *
 * @return Value of the bitfield LF_STAT_SOFF_GDRV:
 *      - 0: LF_STAT_SOFF_GDRV_CONST_0 (device not in safe state (if SOFF_ACT=0)
 * or at least one gate driver cannot enter safe state ( if SOFF_ACT=1)).
 *      - 1: LF_STAT_SOFF_GDRV_CONST_1 (all 6 gate drivers have entered safe
 * state).
 */
uint16 TLE9186_FuncLayer_get_LF_STAT_SOFF_GDRV(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->LF_STAT.bit.SOFF_GDRV;
}

/**
 * @brief get function for register LF_STAT.
 *
 * This function reads the register Latent faults and self-tests status
 * register: internal faults, self-tests results.
 *
 */
void TLE9186_FuncLayer_get_LF_STAT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_LF_STAT();
}

/**
 * @brief Get function for SH_LEVEL_STAT_VSH1_L.
 *
 * This function returns the value of the bitfield Phase 1 voltage monitoring
 * (SH1) VSHL within register SH_LEVEL_STAT.
 *
 * @return Value of the bitfield SH_LEVEL_STAT_VSH1_L:
 *      - 0: SH_LEVEL_STAT_VSH1_L_CONST_0 (VSH1 < VSHL).
 *      - 1: SH_LEVEL_STAT_VSH1_L_CONST_1 (VSH1 > VSHL).
 */
uint16 TLE9186_FuncLayer_get_SH_LEVEL_STAT_VSH1_L(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->SH_LEVEL_STAT.bit.VSH1_L;
}

/**
 * @brief Get function for SH_LEVEL_STAT_VSH1_H.
 *
 * This function returns the value of the bitfield Phase 1 voltage monitoring
 * (SH1) VSHH within register SH_LEVEL_STAT.
 *
 * @return Value of the bitfield SH_LEVEL_STAT_VSH1_H:
 *      - 0: SH_LEVEL_STAT_VSH1_H_CONST_0 (VSH1 < VSHH).
 *      - 1: SH_LEVEL_STAT_VSH1_H_CONST_1 (VSH1 > VSHH).
 */
uint16 TLE9186_FuncLayer_get_SH_LEVEL_STAT_VSH1_H(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->SH_LEVEL_STAT.bit.VSH1_H;
}

/**
 * @brief Get function for SH_LEVEL_STAT_VSH2_L.
 *
 * This function returns the value of the bitfield Phase 2 voltage monitoring
 * (SH2) VSHL within register SH_LEVEL_STAT.
 *
 * @return Value of the bitfield SH_LEVEL_STAT_VSH2_L:
 *      - 0: SH_LEVEL_STAT_VSH2_L_CONST_0 (VSH2 < VSHL).
 *      - 1: SH_LEVEL_STAT_VSH2_L_CONST_1 (VSH2 > VSHL).
 */
uint16 TLE9186_FuncLayer_get_SH_LEVEL_STAT_VSH2_L(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->SH_LEVEL_STAT.bit.VSH2_L;
}

/**
 * @brief Get function for SH_LEVEL_STAT_VSH2_H.
 *
 * This function returns the value of the bitfield Phase 2 voltage monitoring
 * (SH2) VSHH within register SH_LEVEL_STAT.
 *
 * @return Value of the bitfield SH_LEVEL_STAT_VSH2_H:
 *      - 0: SH_LEVEL_STAT_VSH2_H_CONST_0 (VSH2 < VSHH).
 *      - 1: SH_LEVEL_STAT_VSH2_H_CONST_1 (VSH2 > VSHH).
 */
uint16 TLE9186_FuncLayer_get_SH_LEVEL_STAT_VSH2_H(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->SH_LEVEL_STAT.bit.VSH2_H;
}

/**
 * @brief Get function for SH_LEVEL_STAT_VSH3_L.
 *
 * This function returns the value of the bitfield Phase 3 voltage monitoring
 * (SH3) VSHL within register SH_LEVEL_STAT.
 *
 * @return Value of the bitfield SH_LEVEL_STAT_VSH3_L:
 *      - 0: SH_LEVEL_STAT_VSH3_L_CONST_0 (VSH3 < VSHL).
 *      - 1: SH_LEVEL_STAT_VSH3_L_CONST_1 (VSH3 > VSHL).
 */
uint16 TLE9186_FuncLayer_get_SH_LEVEL_STAT_VSH3_L(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->SH_LEVEL_STAT.bit.VSH3_L;
}

/**
 * @brief Get function for SH_LEVEL_STAT_VSH3_H.
 *
 * This function returns the value of the bitfield Phase 3 voltage monitoring
 * (SH3) VSHH within register SH_LEVEL_STAT.
 *
 * @return Value of the bitfield SH_LEVEL_STAT_VSH3_H:
 *      - 0: SH_LEVEL_STAT_VSH3_H_CONST_0 (VSH3 < VSHH).
 *      - 1: SH_LEVEL_STAT_VSH3_H_CONST_1 (VSH3 > VSHH).
 */
uint16 TLE9186_FuncLayer_get_SH_LEVEL_STAT_VSH3_H(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->SH_LEVEL_STAT.bit.VSH3_H;
}

/**
 * @brief Get function for SH_LEVEL_STAT_PFB1.
 *
 * This function returns the value of the bitfield Phase feedback comparator
 * level of SH1 phase within register SH_LEVEL_STAT.
 *
 * @return Value of the bitfield SH_LEVEL_STAT_PFB1:
 *      - 0: SH_LEVEL_STAT_PFB1_CONST_0 (SH1 low level detected).
 *      - 1: SH_LEVEL_STAT_PFB1_CONST_1 (SH1 high level detected).
 */
uint16 TLE9186_FuncLayer_get_SH_LEVEL_STAT_PFB1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->SH_LEVEL_STAT.bit.PFB1;
}

/**
 * @brief Get function for SH_LEVEL_STAT_PFB2.
 *
 * This function returns the value of the bitfield Phase feedback comparator
 * level of SH2 phase within register SH_LEVEL_STAT.
 *
 * @return Value of the bitfield SH_LEVEL_STAT_PFB2:
 *      - 0: SH_LEVEL_STAT_PFB2_CONST_0 (SH2 low level detected).
 *      - 1: SH_LEVEL_STAT_PFB2_CONST_1 (SH2 high level detected).
 */
uint16 TLE9186_FuncLayer_get_SH_LEVEL_STAT_PFB2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->SH_LEVEL_STAT.bit.PFB2;
}

/**
 * @brief Get function for SH_LEVEL_STAT_PFB3.
 *
 * This function returns the value of the bitfield Phase feedback comparator
 * level of SH3 phase within register SH_LEVEL_STAT.
 *
 * @return Value of the bitfield SH_LEVEL_STAT_PFB3:
 *      - 0: SH_LEVEL_STAT_PFB3_CONST_0 (SH3 low level detected).
 *      - 1: SH_LEVEL_STAT_PFB3_CONST_1 (SH3 high level detected).
 */
uint16 TLE9186_FuncLayer_get_SH_LEVEL_STAT_PFB3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->SH_LEVEL_STAT.bit.PFB3;
}

/**
 * @brief get function for register SH_LEVEL_STAT.
 *
 * This function reads the register Phase pins monitoring.
 *
 */
void TLE9186_FuncLayer_get_SH_LEVEL_STAT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names"
           */
{
  TLE9186_RegLayer_get_SH_LEVEL_STAT();
}

/**
 * @brief Set function for register BD_STAT.
 *
 * This function sets the HS & LS Gate Drivers monitoring  .
 *
 * @param u16_value Value to be written into the register BD_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_BD_STAT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Set function for BD_STAT_DSOV_LS1.
 *
 * This function sets the bitfield Drain-source overvoltage monitoring of LS1 in
 * register BD_STAT.
 *
 * @param u16_value Value to be written into BD_STAT_DSOV_LS1. Valid values are:
 *      - 0: BD_STAT_DSOV_LS1_CONST_0 (no drain-source overvoltage detected).
 *      - 1: BD_STAT_DSOV_LS1_CONST_1 (drain-source overvoltage detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_BD_STAT_DSOV_LS1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->BD_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_BD_STAT_DSOV_LS1_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_BD_STAT_DSOV_LS1_POS) &
           (uint16)TLE9186_BD_STAT_DSOV_LS1_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for BD_STAT_DSOV_LS1.
 *
 * This function clears the bitfield Drain-source overvoltage monitoring of LS1
 * in register BD_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_BD_STAT_DSOV_LS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_BD_STAT_DSOV_LS1_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for BD_STAT_DSOV_LS1.
 *
 * This function returns the value of the bitfield Drain-source overvoltage
 * monitoring of LS1 within register BD_STAT.
 *
 * @return Value of the bitfield BD_STAT_DSOV_LS1:
 *      - 0: BD_STAT_DSOV_LS1_CONST_0 (no drain-source overvoltage detected).
 *      - 1: BD_STAT_DSOV_LS1_CONST_1 (drain-source overvoltage detected).
 */
uint16 TLE9186_FuncLayer_get_BD_STAT_DSOV_LS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->BD_STAT.bit.DSOV_LS1;
}

/**
 * @brief Set function for BD_STAT_DSOV_LS2.
 *
 * This function sets the bitfield Drain-source overvoltage monitoring of LS2 in
 * register BD_STAT.
 *
 * @param u16_value Value to be written into BD_STAT_DSOV_LS2. Valid values are:
 *      - 0: BD_STAT_DSOV_LS2_CONST_0 (no drain-source overvoltage detected).
 *      - 1: BD_STAT_DSOV_LS2_CONST_1 (drain-source overvoltage detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_BD_STAT_DSOV_LS2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->BD_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_BD_STAT_DSOV_LS2_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_BD_STAT_DSOV_LS2_POS) &
           (uint16)TLE9186_BD_STAT_DSOV_LS2_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for BD_STAT_DSOV_LS2.
 *
 * This function clears the bitfield Drain-source overvoltage monitoring of LS2
 * in register BD_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_BD_STAT_DSOV_LS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_BD_STAT_DSOV_LS2_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for BD_STAT_DSOV_LS2.
 *
 * This function returns the value of the bitfield Drain-source overvoltage
 * monitoring of LS2 within register BD_STAT.
 *
 * @return Value of the bitfield BD_STAT_DSOV_LS2:
 *      - 0: BD_STAT_DSOV_LS2_CONST_0 (no drain-source overvoltage detected).
 *      - 1: BD_STAT_DSOV_LS2_CONST_1 (drain-source overvoltage detected).
 */
uint16 TLE9186_FuncLayer_get_BD_STAT_DSOV_LS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->BD_STAT.bit.DSOV_LS2;
}

/**
 * @brief Set function for BD_STAT_DSOV_LS3.
 *
 * This function sets the bitfield Drain-source overvoltage monitoring of LS3 in
 * register BD_STAT.
 *
 * @param u16_value Value to be written into BD_STAT_DSOV_LS3. Valid values are:
 *      - 0: BD_STAT_DSOV_LS3_CONST_0 (no drain-source overvoltage detected).
 *      - 1: BD_STAT_DSOV_LS3_CONST_1 (drain-source overvoltage detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_BD_STAT_DSOV_LS3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->BD_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_BD_STAT_DSOV_LS3_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_BD_STAT_DSOV_LS3_POS) &
           (uint16)TLE9186_BD_STAT_DSOV_LS3_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for BD_STAT_DSOV_LS3.
 *
 * This function clears the bitfield Drain-source overvoltage monitoring of LS3
 * in register BD_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_BD_STAT_DSOV_LS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_BD_STAT_DSOV_LS3_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for BD_STAT_DSOV_LS3.
 *
 * This function returns the value of the bitfield Drain-source overvoltage
 * monitoring of LS3 within register BD_STAT.
 *
 * @return Value of the bitfield BD_STAT_DSOV_LS3:
 *      - 0: BD_STAT_DSOV_LS3_CONST_0 (no drain-source overvoltage detected).
 *      - 1: BD_STAT_DSOV_LS3_CONST_1 (drain-source overvoltage detected).
 */
uint16 TLE9186_FuncLayer_get_BD_STAT_DSOV_LS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->BD_STAT.bit.DSOV_LS3;
}

/**
 * @brief Set function for BD_STAT_DSOV_HS1.
 *
 * This function sets the bitfield Drain-source overvoltage monitoring of HS1 in
 * register BD_STAT.
 *
 * @param u16_value Value to be written into BD_STAT_DSOV_HS1. Valid values are:
 *      - 0: BD_STAT_DSOV_HS1_CONST_0 (no drain-source over-voltage detected).
 *      - 1: BD_STAT_DSOV_HS1_CONST_1 (drain-source over-voltage detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_BD_STAT_DSOV_HS1(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->BD_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_BD_STAT_DSOV_HS1_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_BD_STAT_DSOV_HS1_POS) &
           (uint16)TLE9186_BD_STAT_DSOV_HS1_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for BD_STAT_DSOV_HS1.
 *
 * This function clears the bitfield Drain-source overvoltage monitoring of HS1
 * in register BD_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_BD_STAT_DSOV_HS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_BD_STAT_DSOV_HS1_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for BD_STAT_DSOV_HS1.
 *
 * This function returns the value of the bitfield Drain-source overvoltage
 * monitoring of HS1 within register BD_STAT.
 *
 * @return Value of the bitfield BD_STAT_DSOV_HS1:
 *      - 0: BD_STAT_DSOV_HS1_CONST_0 (no drain-source over-voltage detected).
 *      - 1: BD_STAT_DSOV_HS1_CONST_1 (drain-source over-voltage detected).
 */
uint16 TLE9186_FuncLayer_get_BD_STAT_DSOV_HS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->BD_STAT.bit.DSOV_HS1;
}

/**
 * @brief Set function for BD_STAT_DSOV_HS2.
 *
 * This function sets the bitfield Drain-source overvoltage monitoring of HS2 in
 * register BD_STAT.
 *
 * @param u16_value Value to be written into BD_STAT_DSOV_HS2. Valid values are:
 *      - 0: BD_STAT_DSOV_HS2_CONST_0 (no drain-source over-voltage detected).
 *      - 1: BD_STAT_DSOV_HS2_CONST_1 (drain-source over-voltage detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_BD_STAT_DSOV_HS2(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->BD_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_BD_STAT_DSOV_HS2_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_BD_STAT_DSOV_HS2_POS) &
           (uint16)TLE9186_BD_STAT_DSOV_HS2_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for BD_STAT_DSOV_HS2.
 *
 * This function clears the bitfield Drain-source overvoltage monitoring of HS2
 * in register BD_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_BD_STAT_DSOV_HS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)(1u << TLE9186_BD_STAT_DSOV_HS2_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for BD_STAT_DSOV_HS2.
 *
 * This function returns the value of the bitfield Drain-source overvoltage
 * monitoring of HS2 within register BD_STAT.
 *
 * @return Value of the bitfield BD_STAT_DSOV_HS2:
 *      - 0: BD_STAT_DSOV_HS2_CONST_0 (no drain-source over-voltage detected).
 *      - 1: BD_STAT_DSOV_HS2_CONST_1 (drain-source over-voltage detected).
 */
uint16 TLE9186_FuncLayer_get_BD_STAT_DSOV_HS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->BD_STAT.bit.DSOV_HS2;
}

/**
 * @brief Set function for BD_STAT_DSOV_HS3.
 *
 * This function sets the bitfield Drain-source overvoltage monitoring of HS3 in
 * register BD_STAT.
 *
 * @param u16_value Value to be written into BD_STAT_DSOV_HS3. Valid values are:
 *      - 0: BD_STAT_DSOV_HS3_CONST_0 (no drain-source over-voltage detected).
 *      - 1: BD_STAT_DSOV_HS3_CONST_1 (drain-source over-voltage detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_BD_STAT_DSOV_HS3(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->BD_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_BD_STAT_DSOV_HS3_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_BD_STAT_DSOV_HS3_POS) &
           (uint16)TLE9186_BD_STAT_DSOV_HS3_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for BD_STAT_DSOV_HS3.
 *
 * This function clears the bitfield Drain-source overvoltage monitoring of HS3
 * in register BD_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_BD_STAT_DSOV_HS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)((uint16)1u << (uint16)TLE9186_BD_STAT_DSOV_HS3_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for BD_STAT_DSOV_HS3.
 *
 * This function returns the value of the bitfield Drain-source overvoltage
 * monitoring of HS3 within register BD_STAT.
 *
 * @return Value of the bitfield BD_STAT_DSOV_HS3:
 *      - 0: BD_STAT_DSOV_HS3_CONST_0 (no drain-source over-voltage detected).
 *      - 1: BD_STAT_DSOV_HS3_CONST_1 (drain-source over-voltage detected).
 */
uint16 TLE9186_FuncLayer_get_BD_STAT_DSOV_HS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->BD_STAT.bit.DSOV_HS3;
}

/**
 * @brief Set function for BD_STAT_IL1_MISS.
 *
 * This function sets the bitfield PWM alternation check - detection of stuck
 * IL1 PWM input pin in register BD_STAT.
 *
 * @param u16_value Value to be written into BD_STAT_IL1_MISS. Valid values are:
 *      - 0: BD_STAT_IL1_MISS_CONST_0 (IL1 PWM pin functionality ok or PWM
 * alternation check disabled).
 *      - 1: BD_STAT_IL1_MISS_CONST_1 (IL1 PWM pin stuck low detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_BD_STAT_IL1_MISS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->BD_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_BD_STAT_IL1_MISS_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_BD_STAT_IL1_MISS_POS) &
           (uint16)TLE9186_BD_STAT_IL1_MISS_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for BD_STAT_IL1_MISS.
 *
 * This function clears the bitfield PWM alternation check - detection of stuck
 * IL1 PWM input pin in register BD_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_BD_STAT_IL1_MISS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)((uint16)1u << (uint16)TLE9186_BD_STAT_IL1_MISS_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for BD_STAT_IL1_MISS.
 *
 * This function returns the value of the bitfield PWM alternation check -
 * detection of stuck IL1 PWM input pin within register BD_STAT.
 *
 * @return Value of the bitfield BD_STAT_IL1_MISS:
 *      - 0: BD_STAT_IL1_MISS_CONST_0 (IL1 PWM pin functionality ok or PWM
 * alternation check disabled).
 *      - 1: BD_STAT_IL1_MISS_CONST_1 (IL1 PWM pin stuck low detected).
 */
uint16 TLE9186_FuncLayer_get_BD_STAT_IL1_MISS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->BD_STAT.bit.IL1_MISS;
}

/**
 * @brief Set function for BD_STAT_IL2_MISS.
 *
 * This function sets the bitfield PWM alternation check - detection of stuck
 * IL2 PWM input pin in register BD_STAT.
 *
 * @param u16_value Value to be written into BD_STAT_IL2_MISS. Valid values are:
 *      - 0: BD_STAT_IL2_MISS_CONST_0 (IL3 PWM pin functionality ok or PWM
 * alternation check disabled).
 *      - 1: BD_STAT_IL2_MISS_CONST_1 (IL2 PWM pin stuck low detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_BD_STAT_IL2_MISS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->BD_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_BD_STAT_IL2_MISS_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_BD_STAT_IL2_MISS_POS) &
           (uint16)TLE9186_BD_STAT_IL2_MISS_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for BD_STAT_IL2_MISS.
 *
 * This function clears the bitfield PWM alternation check - detection of stuck
 * IL2 PWM input pin in register BD_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_BD_STAT_IL2_MISS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)((uint16)1u << (uint16)TLE9186_BD_STAT_IL2_MISS_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for BD_STAT_IL2_MISS.
 *
 * This function returns the value of the bitfield PWM alternation check -
 * detection of stuck IL2 PWM input pin within register BD_STAT.
 *
 * @return Value of the bitfield BD_STAT_IL2_MISS:
 *      - 0: BD_STAT_IL2_MISS_CONST_0 (IL3 PWM pin functionality ok or PWM
 * alternation check disabled).
 *      - 1: BD_STAT_IL2_MISS_CONST_1 (IL2 PWM pin stuck low detected).
 */
uint16 TLE9186_FuncLayer_get_BD_STAT_IL2_MISS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->BD_STAT.bit.IL2_MISS;
}

/**
 * @brief Set function for BD_STAT_IL3_MISS.
 *
 * This function sets the bitfield PWM alternation check - detection of stuck
 * IL3 PWM input pin in register BD_STAT.
 *
 * @param u16_value Value to be written into BD_STAT_IL3_MISS. Valid values are:
 *      - 0: BD_STAT_IL3_MISS_CONST_0 (IL3 PWM pin functionality ok or PWM
 * alternation check disabled).
 *      - 1: BD_STAT_IL3_MISS_CONST_1 (IL3 PWM pin stuck low detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_BD_STAT_IL3_MISS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->BD_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_BD_STAT_IL3_MISS_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_BD_STAT_IL3_MISS_POS) &
           (uint16)TLE9186_BD_STAT_IL3_MISS_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for BD_STAT_IL3_MISS.
 *
 * This function clears the bitfield PWM alternation check - detection of stuck
 * IL3 PWM input pin in register BD_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_BD_STAT_IL3_MISS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)((uint16)1u << (uint16)TLE9186_BD_STAT_IL3_MISS_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for BD_STAT_IL3_MISS.
 *
 * This function returns the value of the bitfield PWM alternation check -
 * detection of stuck IL3 PWM input pin within register BD_STAT.
 *
 * @return Value of the bitfield BD_STAT_IL3_MISS:
 *      - 0: BD_STAT_IL3_MISS_CONST_0 (IL3 PWM pin functionality ok or PWM
 * alternation check disabled).
 *      - 1: BD_STAT_IL3_MISS_CONST_1 (IL3 PWM pin stuck low detected).
 */
uint16 TLE9186_FuncLayer_get_BD_STAT_IL3_MISS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->BD_STAT.bit.IL3_MISS;
}

/**
 * @brief Set function for BD_STAT_IH1_MISS.
 *
 * This function sets the bitfield PWM alternation check - detection of stuck
 * IH1_N PWM input pin in register BD_STAT.
 *
 * @param u16_value Value to be written into BD_STAT_IH1_MISS. Valid values are:
 *      - 0: BD_STAT_IH1_MISS_CONST_0 (IH1_N PWM pin functionality ok or PWM
 * alternation check disabled).
 *      - 1: BD_STAT_IH1_MISS_CONST_1 (IH1_N PWM pin stuck high detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_BD_STAT_IH1_MISS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->BD_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_BD_STAT_IH1_MISS_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_BD_STAT_IH1_MISS_POS) &
           (uint16)TLE9186_BD_STAT_IH1_MISS_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for BD_STAT_IH1_MISS.
 *
 * This function clears the bitfield PWM alternation check - detection of stuck
 * IH1_N PWM input pin in register BD_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_BD_STAT_IH1_MISS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)((uint16)1u << (uint16)TLE9186_BD_STAT_IH1_MISS_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for BD_STAT_IH1_MISS.
 *
 * This function returns the value of the bitfield PWM alternation check -
 * detection of stuck IH1_N PWM input pin within register BD_STAT.
 *
 * @return Value of the bitfield BD_STAT_IH1_MISS:
 *      - 0: BD_STAT_IH1_MISS_CONST_0 (IH1_N PWM pin functionality ok or PWM
 * alternation check disabled).
 *      - 1: BD_STAT_IH1_MISS_CONST_1 (IH1_N PWM pin stuck high detected).
 */
uint16 TLE9186_FuncLayer_get_BD_STAT_IH1_MISS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->BD_STAT.bit.IH1_MISS;
}

/**
 * @brief Set function for BD_STAT_IH2_MISS.
 *
 * This function sets the bitfield PWM alternation check - detection of stuck
 * IH2_N PWM input pin in register BD_STAT.
 *
 * @param u16_value Value to be written into BD_STAT_IH2_MISS. Valid values are:
 *      - 0: BD_STAT_IH2_MISS_CONST_0 (IH2_N PWM pin functionality ok or PWM
 * alternation check disabled).
 *      - 1: BD_STAT_IH2_MISS_CONST_1 (IH2_N PWM pin stuck high detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_BD_STAT_IH2_MISS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->BD_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_BD_STAT_IH2_MISS_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_BD_STAT_IH2_MISS_POS) &
           (uint16)TLE9186_BD_STAT_IH2_MISS_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for BD_STAT_IH2_MISS.
 *
 * This function clears the bitfield PWM alternation check - detection of stuck
 * IH2_N PWM input pin in register BD_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_BD_STAT_IH2_MISS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)((uint16)1u << (uint16)TLE9186_BD_STAT_IH2_MISS_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for BD_STAT_IH2_MISS.
 *
 * This function returns the value of the bitfield PWM alternation check -
 * detection of stuck IH2_N PWM input pin within register BD_STAT.
 *
 * @return Value of the bitfield BD_STAT_IH2_MISS:
 *      - 0: BD_STAT_IH2_MISS_CONST_0 (IH2_N PWM pin functionality ok or PWM
 * alternation check disabled).
 *      - 1: BD_STAT_IH2_MISS_CONST_1 (IH2_N PWM pin stuck high detected).
 */
uint16 TLE9186_FuncLayer_get_BD_STAT_IH2_MISS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->BD_STAT.bit.IH2_MISS;
}

/**
 * @brief Set function for BD_STAT_IH3_MISS.
 *
 * This function sets the bitfield PWM alternation check - detection of stuck
 * IH3_N PWM input pin in register BD_STAT.
 *
 * @param u16_value Value to be written into BD_STAT_IH3_MISS. Valid values are:
 *      - 0: BD_STAT_IH3_MISS_CONST_0 (IH3_N PWM pin functionality ok or PWM
 * alternation check disabled).
 *      - 1: BD_STAT_IH3_MISS_CONST_1 (IH3_N PWM pin stuck high detected).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_BD_STAT_IH3_MISS(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->BD_STAT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_BD_STAT_IH3_MISS_MSK)) |
         ((((uint16)(u16_value) << (uint16)TLE9186_BD_STAT_IH3_MISS_POS) &
           (uint16)TLE9186_BD_STAT_IH3_MISS_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for BD_STAT_IH3_MISS.
 *
 * This function clears the bitfield PWM alternation check - detection of stuck
 * IH3_N PWM input pin in register BD_STAT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_BD_STAT_IH3_MISS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)((uint16)1u << (uint16)TLE9186_BD_STAT_IH3_MISS_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_BD_STAT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for BD_STAT_IH3_MISS.
 *
 * This function returns the value of the bitfield PWM alternation check -
 * detection of stuck IH3_N PWM input pin within register BD_STAT.
 *
 * @return Value of the bitfield BD_STAT_IH3_MISS:
 *      - 0: BD_STAT_IH3_MISS_CONST_0 (IH3_N PWM pin functionality ok or PWM
 * alternation check disabled).
 *      - 1: BD_STAT_IH3_MISS_CONST_1 (IH3_N PWM pin stuck high detected).
 */
uint16 TLE9186_FuncLayer_get_BD_STAT_IH3_MISS(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->BD_STAT.bit.IH3_MISS;
}

/**
 * @brief get function for register BD_STAT.
 *
 * This function reads the register HS & LS Gate Drivers monitoring  .
 *
 */
void TLE9186_FuncLayer_get_BD_STAT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_BD_STAT();
}

/**
 * @brief Get function for WD_CLK_CNT_WD_CLK_CNT.
 *
 * This function returns the value of the bitfield Internal clock counter
 * between two consecutive correct watchdog services. LSB of nominal 2.4us
 * within register WD_CLK_CNT.
 *
 * @return Value of the bitfield WD_CLK_CNT_WD_CLK_CNT:
 *      - 0: WD_CLK_CNT_WD_CLK_CNT_CONST_0 (min. value: read-only data).
 *      - 65535: WD_CLK_CNT_WD_CLK_CNT_CONST_65535 (max. value: read-only data).
 */
uint16 TLE9186_FuncLayer_get_WD_CLK_CNT_WD_CLK_CNT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->WD_CLK_CNT.bit.WD_CLK_CNT;
}

/**
 * @brief get function for register WD_CLK_CNT.
 *
 * This function reads the register Watchdog clock counter.
 *
 */
void TLE9186_FuncLayer_get_WD_CLK_CNT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_WD_CLK_CNT();
}

/**
 * @brief Set function for register PHASE1_CNT.
 *
 * This function sets the Phase 1 high time counter.
 *
 * @param u16_value Value to be written into the register PHASE1_CNT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_PHASE1_CNT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_PHASE1_CNT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for PHASE1_CNT_PFB1_H_CNT.
 *
 * This function returns the value of the bitfield Phase 1 (SH1) high time
 * counter, LSB of nominal 250ns within register PHASE1_CNT.
 *
 * @return Value of the bitfield PHASE1_CNT_PFB1_H_CNT:
 *      - 0: PFB1_H_CNT_PFB1_H_CNT_CONST_0 (min. value: read-only data).
 *      - 4095: PFB1_H_CNT_PFB1_H_CNT_CONST_4095 (max. value: read-only data).
 */
uint16 TLE9186_FuncLayer_get_PHASE1_CNT_PFB1_H_CNT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->PHASE1_CNT.bit.PFB1_H_CNT;
}

/**
 * @brief Get function for PHASE1_CNT_CNT1_RDY.
 *
 * This function returns the value of the bitfield PFB1_H counter ready for read
 * indication within register PHASE1_CNT.
 *
 * @return Value of the bitfield PHASE1_CNT_CNT1_RDY:
 *      - 0: PFB1_H_CNT_CNT1_RDY_CONST_0 (PFB1 counter disabled or counter not
 * ready for read).
 *      - 1: PFB1_H_CNT_CNT1_RDY_CONST_1 (PFB1 counter ready for read).
 */
uint16 TLE9186_FuncLayer_get_PHASE1_CNT_CNT1_RDY(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->PHASE1_CNT.bit.CNT1_RDY;
}

/**
 * @brief Set function for PHASE1_CNT_PFB1_CNT_UPD.
 *
 * This function sets the bitfield PFB1 counter update indication in register
 * PHASE1_CNT.
 *
 * @param u16_value Value to be written into PHASE1_CNT_PFB1_CNT_UPD. Valid
 * values are:
 *      - 0: PFB1_H_CNT_PFB1_CNT_UPD_CONST_0 (PFB1 counter has not been updated
 * at least once since the last SPI read-out).
 *      - 1: PFB1_H_CNT_PFB1_CNT_UPD_CONST_1 (PFB1 counter has been updated at
 * least once since the last SPI read-out).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_PHASE1_CNT_PFB1_CNT_UPD(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->PHASE1_CNT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_PHASE1_CNT_PFB1_CNT_UPD_MSK)) |
         ((((uint16)(u16_value)
            << (uint16)TLE9186_PHASE1_CNT_PFB1_CNT_UPD_POS) &
           (uint16)TLE9186_PHASE1_CNT_PFB1_CNT_UPD_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_PHASE1_CNT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for PHASE1_CNT_PFB1_CNT_UPD.
 *
 * This function clears the bitfield PFB1 counter update indication in register
 * PHASE1_CNT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_PHASE1_CNT_PFB1_CNT_UPD(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)((uint16)1u << (uint16)TLE9186_PHASE1_CNT_PFB1_CNT_UPD_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_PHASE1_CNT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for PHASE1_CNT_PFB1_CNT_UPD.
 *
 * This function returns the value of the bitfield PFB1 counter update
 * indication within register PHASE1_CNT.
 *
 * @return Value of the bitfield PHASE1_CNT_PFB1_CNT_UPD:
 *      - 0: PFB1_H_CNT_PFB1_CNT_UPD_CONST_0 (PFB1 counter has not been updated
 * at least once since the last SPI read-out).
 *      - 1: PFB1_H_CNT_PFB1_CNT_UPD_CONST_1 (PFB1 counter has been updated at
 * least once since the last SPI read-out).
 */
uint16 TLE9186_FuncLayer_get_PHASE1_CNT_PFB1_CNT_UPD(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->PHASE1_CNT.bit.PFB1_CNT_UPD;
}

/**
 * @brief Get function for PHASE1_CNT_PFB1.
 *
 * This function returns the value of the bitfield Phase feedback comparator
 * level of SH1 phase within register PHASE1_CNT.
 *
 * @return Value of the bitfield PHASE1_CNT_PFB1:
 *      - 0: PFB1_H_CNT_PFB1_CONST_0 (SH1 low level detected).
 *      - 1: PFB1_H_CNT_PFB1_CONST_1 (SH1 high level detected).
 */
uint16 TLE9186_FuncLayer_get_PHASE1_CNT_PFB1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->PHASE1_CNT.bit.PFB1;
}

/**
 * @brief get function for register PHASE1_CNT.
 *
 * This function reads the register Phase 1 high time counter.
 *
 */
void TLE9186_FuncLayer_get_PHASE1_CNT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_PHASE1_CNT();
}

/**
 * @brief Set function for register PHASE2_CNT.
 *
 * This function sets the Phase 2 high time counter.
 *
 * @param u16_value Value to be written into the register PHASE2_CNT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_PHASE2_CNT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_PHASE2_CNT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for PHASE2_CNT_PFB2_H_CNT.
 *
 * This function returns the value of the bitfield Phase 2 (SH2) high time
 * counter, LSB of nominal 250ns within register PHASE2_CNT.
 *
 * @return Value of the bitfield PHASE2_CNT_PFB2_H_CNT:
 *      - 0: PFB2_H_CNT_PFB2_H_CNT_CONST_0 (min. value: read-only data).
 *      - 4095: PFB2_H_CNT_PFB2_H_CNT_CONST_4095 (max. value: read-only data).
 */
uint16 TLE9186_FuncLayer_get_PHASE2_CNT_PFB2_H_CNT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->PHASE2_CNT.bit.PFB2_H_CNT;
}

/**
 * @brief Get function for PHASE2_CNT_CNT2_RDY.
 *
 * This function returns the value of the bitfield PFB2_H counter ready for read
 * indication within register PHASE2_CNT.
 *
 * @return Value of the bitfield PHASE2_CNT_CNT2_RDY:
 *      - 0: PFB2_H_CNT_CNT2_RDY_CONST_0 (PFB2 counter disabled or counter not
 * ready for read).
 *      - 1: PFB2_H_CNT_CNT2_RDY_CONST_1 (PFB2 counter ready for read).
 */
uint16 TLE9186_FuncLayer_get_PHASE2_CNT_CNT2_RDY(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->PHASE2_CNT.bit.CNT2_RDY;
}

/**
 * @brief Set function for PHASE2_CNT_PFB2_CNT_UPD.
 *
 * This function sets the bitfield PFB2 counter update indication in register
 * PHASE2_CNT.
 *
 * @param u16_value Value to be written into PHASE2_CNT_PFB2_CNT_UPD. Valid
 * values are:
 *      - 0: PFB2_H_CNT_PFB2_CNT_UPD_CONST_0 (PFB2 counter has not been updated
 * at least once since the last SPI read-out).
 *      - 1: PFB2_H_CNT_PFB2_CNT_UPD_CONST_1 (PFB2 counter has been updated at
 * least once since the last SPI read-out).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_PHASE2_CNT_PFB2_CNT_UPD(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->PHASE2_CNT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_PHASE2_CNT_PFB2_CNT_UPD_MSK)) |
         ((((uint16)(u16_value)
            << (uint16)TLE9186_PHASE2_CNT_PFB2_CNT_UPD_POS) &
           (uint16)TLE9186_PHASE2_CNT_PFB2_CNT_UPD_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_PHASE2_CNT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for PHASE2_CNT_PFB2_CNT_UPD.
 *
 * This function clears the bitfield PFB2 counter update indication in register
 * PHASE2_CNT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_PHASE2_CNT_PFB2_CNT_UPD(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)((uint16)1u << (uint16)TLE9186_PHASE2_CNT_PFB2_CNT_UPD_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_PHASE2_CNT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for PHASE2_CNT_PFB2_CNT_UPD.
 *
 * This function returns the value of the bitfield PFB2 counter update
 * indication within register PHASE2_CNT.
 *
 * @return Value of the bitfield PHASE2_CNT_PFB2_CNT_UPD:
 *      - 0: PFB2_H_CNT_PFB2_CNT_UPD_CONST_0 (PFB2 counter has not been updated
 * at least once since the last SPI read-out).
 *      - 1: PFB2_H_CNT_PFB2_CNT_UPD_CONST_1 (PFB2 counter has been updated at
 * least once since the last SPI read-out).
 */
uint16 TLE9186_FuncLayer_get_PHASE2_CNT_PFB2_CNT_UPD(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->PHASE2_CNT.bit.PFB2_CNT_UPD;
}

/**
 * @brief Get function for PHASE2_CNT_PFB2.
 *
 * This function returns the value of the bitfield Phase feedback comparator
 * level of SH2 phase within register PHASE2_CNT.
 *
 * @return Value of the bitfield PHASE2_CNT_PFB2:
 *      - 0: PFB2_H_CNT_PFB2_CONST_0 (SH2 low level detected).
 *      - 1: PFB2_H_CNT_PFB2_CONST_1 (SH2 high level detected).
 */
uint16 TLE9186_FuncLayer_get_PHASE2_CNT_PFB2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->PHASE2_CNT.bit.PFB2;
}

/**
 * @brief get function for register PHASE2_CNT.
 *
 * This function reads the register Phase 2 high time counter.
 *
 */
void TLE9186_FuncLayer_get_PHASE2_CNT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_PHASE2_CNT();
}

/**
 * @brief Set function for register PHASE3_CNT.
 *
 * This function sets the Phase 3 high time counter.
 *
 * @param u16_value Value to be written into the register PHASE3_CNT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_PHASE3_CNT(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
                       * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue = u16_value;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_PHASE3_CNT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for PHASE3_CNT_PFB3_H_CNT.
 *
 * This function returns the value of the bitfield Phase 3 (SH3) high time
 * counter within register PHASE3_CNT.
 *
 * @return Value of the bitfield PHASE3_CNT_PFB3_H_CNT:
 *      - 0: PFB3_H_CNT_PFB3_H_CNT_CONST_0 (min. value: read-only data).
 *      - 4095: PFB3_H_CNT_PFB3_H_CNT_CONST_4095 (max. value: read-only data).
 */
uint16 TLE9186_FuncLayer_get_PHASE3_CNT_PFB3_H_CNT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->PHASE3_CNT.bit.PFB3_H_CNT;
}

/**
 * @brief Get function for PHASE3_CNT_CNT3_RDY.
 *
 * This function returns the value of the bitfield PFB3_H counter ready for read
 * indication within register PHASE3_CNT.
 *
 * @return Value of the bitfield PHASE3_CNT_CNT3_RDY:
 *      - 0: PFB3_H_CNT_CNT3_RDY_CONST_0 (PFB3 counter disabled or counter not
 * ready for read).
 *      - 1: PFB3_H_CNT_CNT3_RDY_CONST_1 (PFB3 counter ready for read).
 */
uint16 TLE9186_FuncLayer_get_PHASE3_CNT_CNT3_RDY(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->PHASE3_CNT.bit.CNT3_RDY;
}

/**
 * @brief Set function for PHASE3_CNT_PFB3_CNT_UPD.
 *
 * This function sets the bitfield PFB3 counter update indication in register
 * PHASE3_CNT.
 *
 * @param u16_value Value to be written into PHASE3_CNT_PFB3_CNT_UPD. Valid
 * values are:
 *      - 0: PFB3_H_CNT_PFB3_CNT_UPD_CONST_0 (PFB3 counter has not been updated
 * at least once since the last SPI read-out).
 *      - 1: PFB3_H_CNT_PFB3_CNT_UPD_CONST_1 (PFB3 counter has been updated at
 * least once since the last SPI read-out).
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_set_PHASE3_CNT_PFB3_CNT_UPD(
    uint16 u16_value) /* polyspace MISRA2012:5.1 [Justified: Low] "Given
                       * due to register names" */
{
  uint16 u16_temp_reg = 0u;
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    u16_temp_reg = (uint16)TLE9186->PHASE3_CNT.reg;
    u16_temp_reg =
        ((u16_temp_reg & (uint16)(~TLE9186_PHASE3_CNT_PFB3_CNT_UPD_MSK)) |
         ((((uint16)(u16_value)
            << (uint16)TLE9186_PHASE3_CNT_PFB3_CNT_UPD_POS) &
           (uint16)TLE9186_PHASE3_CNT_PFB3_CNT_UPD_MSK)));
    s_deviceDriver_TLE9186.u16_setBitValue = u16_temp_reg;
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_PHASE3_CNT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Clear function for PHASE3_CNT_PFB3_CNT_UPD.
 *
 * This function clears the bitfield PFB3 counter update indication in register
 * PHASE3_CNT.
 *
 * @return Status if request was added to queue. Valid values are:
 *      - 0: Request was not added to queue.
 *      - 1: Request was added to queue.
 *
 */
uint8 TLE9186_FuncLayer_clear_PHASE3_CNT_PFB3_CNT_UPD(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  uint8 u8_success = 0u;

  if (s_deviceDriver_TLE9186.fp_setReg == NULL) {
    s_deviceDriver_TLE9186.u16_setBitValue =
        (uint16)((uint16)1u << (uint16)TLE9186_PHASE3_CNT_PFB3_CNT_UPD_POS);
    s_deviceDriver_TLE9186.fp_setReg = &TLE9186_RegLayer_set_PHASE3_CNT;
    u8_success = 1u;
  }

  return u8_success;
}

/**
 * @brief Get function for PHASE3_CNT_PFB3_CNT_UPD.
 *
 * This function returns the value of the bitfield PFB3 counter update
 * indication within register PHASE3_CNT.
 *
 * @return Value of the bitfield PHASE3_CNT_PFB3_CNT_UPD:
 *      - 0: PFB3_H_CNT_PFB3_CNT_UPD_CONST_0 (PFB3 counter has not been updated
 * at least once since the last SPI read-out).
 *      - 1: PFB3_H_CNT_PFB3_CNT_UPD_CONST_1 (PFB3 counter has been updated at
 * least once since the last SPI read-out).
 */
uint16 TLE9186_FuncLayer_get_PHASE3_CNT_PFB3_CNT_UPD(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->PHASE3_CNT.bit.PFB3_CNT_UPD;
}

/**
 * @brief Get function for PHASE3_CNT_PFB3.
 *
 * This function returns the value of the bitfield Phase feedback comparator
 * level of SH3 phase within register PHASE3_CNT.
 *
 * @return Value of the bitfield PHASE3_CNT_PFB3:
 *      - 0: PFB3_H_CNT_PFB3_CONST_0 (SH3 low level detected).
 *      - 1: PFB3_H_CNT_PFB3_CONST_1 (SH3 high level detected).
 */
uint16 TLE9186_FuncLayer_get_PHASE3_CNT_PFB3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->PHASE3_CNT.bit.PFB3;
}

/**
 * @brief get function for register PHASE3_CNT.
 *
 * This function reads the register Phase 3 high time counter.
 *
 */
void TLE9186_FuncLayer_get_PHASE3_CNT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
             names" */
{
  TLE9186_RegLayer_get_PHASE3_CNT();
}

/**
 * @brief Get function for TDON_TDOFF_HS1_TDOFF_HS1.
 *
 * This function returns the value of the bitfield Effective turn-off delay time
 * of HS1 MOSFET within register TDON_TDOFF_HS1.
 *
 * @return Value of the bitfield TDON_TDOFF_HS1_TDOFF_HS1:
 *      - 0: TDON_TDOFF_HS1_TDOFF_HS1_CONST_0 (min. value: read-only data).
 *      - 127: TDON_TDOFF_HS1_TDOFF_HS1_CONST_127 (max. value: read-only data).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_HS1_TDOFF_HS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_HS1.bit.TDOFF_HS1;
}

/**
 * @brief Get function for TDON_TDOFF_HS1_TDON_HS1.
 *
 * This function returns the value of the bitfield Effective turn-on delay time
 * of HS1 MOSFET within register TDON_TDOFF_HS1.
 *
 * @return Value of the bitfield TDON_TDOFF_HS1_TDON_HS1:
 *      - 0: TDON_TDOFF_HS1_TDON_HS1_CONST_0 (min. value: read-only data).
 *      - 127: TDON_TDOFF_HS1_TDON_HS1_CONST_127 (max. value: read-only data).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_HS1_TDON_HS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_HS1.bit.TDON_HS1;
}

/**
 * @brief Get function for TDON_TDOFF_HS1_LS1_ACT.
 *
 * This function returns the value of the bitfield LS1 detection as active
 * MOSFET when turned ON within register TDON_TDOFF_HS1.
 *
 * @return Value of the bitfield TDON_TDOFF_HS1_LS1_ACT:
 *      - 0: TDON_TDOFF_HS1_LS1_ACT_CONST_0 (LS1 is not the active MOSFET).
 *      - 1: TDON_TDOFF_HS1_LS1_ACT_CONST_1 (LS1 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_HS1_LS1_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_HS1.bit.LS1_ACT;
}

/**
 * @brief Get function for TDON_TDOFF_HS1_HS1_ACT.
 *
 * This function returns the value of the bitfield HS1 detection as active
 * MOSFET when turned ON within register TDON_TDOFF_HS1.
 *
 * @return Value of the bitfield TDON_TDOFF_HS1_HS1_ACT:
 *      - 0: TDON_TDOFF_HS1_HS1_ACT_CONST_0 (HS1 is not the active MOSFET).
 *      - 1: TDON_TDOFF_HS1_HS1_ACT_CONST_1 (HS1 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_HS1_HS1_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_HS1.bit.HS1_ACT;
}

/**
 * @brief get function for register TDON_TDOFF_HS1.
 *
 * This function reads the register Effective MOSFET turn-on/off delay time HS1.
 *
 */
void TLE9186_FuncLayer_get_TDON_TDOFF_HS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  TLE9186_RegLayer_get_TDON_TDOFF_HS1();
}

/**
 * @brief Get function for TDON_TDOFF_LS1_TDOFF_LS1.
 *
 * This function returns the value of the bitfield Effective turn-off delay time
 * of LS1 MOSFET within register TDON_TDOFF_LS1.
 *
 * @return Value of the bitfield TDON_TDOFF_LS1_TDOFF_LS1:
 *      - 0: TDON_TDOFF_LS1_TDOFF_LS1_CONST_0 (min. Value: read-only data).
 *      - 127: TDON_TDOFF_LS1_TDOFF_LS1_CONST_127 (max. value: read-only data).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_LS1_TDOFF_LS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_LS1.bit.TDOFF_LS1;
}

/**
 * @brief Get function for TDON_TDOFF_LS1_TDON_LS1.
 *
 * This function returns the value of the bitfield Effective turn-on delay time
 * of LS1 MOSFET within register TDON_TDOFF_LS1.
 *
 * @return Value of the bitfield TDON_TDOFF_LS1_TDON_LS1:
 *      - 0: TDON_TDOFF_LS1_TDON_LS1_CONST_0 (min. Value: read-only data).
 *      - 127: TDON_TDOFF_LS1_TDON_LS1_CONST_127 (max. value: read-only data).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_LS1_TDON_LS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_LS1.bit.TDON_LS1;
}

/**
 * @brief Get function for TDON_TDOFF_LS1_LS1_ACT.
 *
 * This function returns the value of the bitfield LS1 detection as active
 * MOSFET when turned ON within register TDON_TDOFF_LS1.
 *
 * @return Value of the bitfield TDON_TDOFF_LS1_LS1_ACT:
 *      - 0: TDON_TDOFF_LS1_LS1_ACT_CONST_0 (LS1 is not the active MOSFET).
 *      - 1: TDON_TDOFF_LS1_LS1_ACT_CONST_1 (LS1 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_LS1_LS1_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_LS1.bit.LS1_ACT;
}

/**
 * @brief Get function for TDON_TDOFF_LS1_HS1_ACT.
 *
 * This function returns the value of the bitfield HS1 detection as active
 * MOSFET when turned ON within register TDON_TDOFF_LS1.
 *
 * @return Value of the bitfield TDON_TDOFF_LS1_HS1_ACT:
 *      - 0: TDON_TDOFF_LS1_HS1_ACT_CONST_0 (HS1 is not the active MOSFET).
 *      - 1: TDON_TDOFF_LS1_HS1_ACT_CONST_1 (HS1 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_LS1_HS1_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_LS1.bit.HS1_ACT;
}

/**
 * @brief get function for register TDON_TDOFF_LS1.
 *
 * This function reads the register Effective MOSFET turn-on/off delay time LS1.
 *
 */
void TLE9186_FuncLayer_get_TDON_TDOFF_LS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  TLE9186_RegLayer_get_TDON_TDOFF_LS1();
}

/**
 * @brief Get function for TDON_TDOFF_HS2_TDOFF_HS2.
 *
 * This function returns the value of the bitfield Effective turn-off delay time
 * of HS2 MOSFET within register TDON_TDOFF_HS2.
 *
 * @return Value of the bitfield TDON_TDOFF_HS2_TDOFF_HS2:
 *      - 0: TDON_TDOFF_HS2_TDOFF_HS2_CONST_0 (min. Value: read-only data).
 *      - 127: TDON_TDOFF_HS2_TDOFF_HS2_CONST_127 (max. value: read-only data).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_HS2_TDOFF_HS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_HS2.bit.TDOFF_HS2;
}

/**
 * @brief Get function for TDON_TDOFF_HS2_TDON_HS2.
 *
 * This function returns the value of the bitfield Effective turn-on delay time
 * of HS2 MOSFET within register TDON_TDOFF_HS2.
 *
 * @return Value of the bitfield TDON_TDOFF_HS2_TDON_HS2:
 *      - 0: TDON_TDOFF_HS2_TDON_HS2_CONST_0 (min. Value: read-only data).
 *      - 127: TDON_TDOFF_HS2_TDON_HS2_CONST_127 (max. value: read-only data).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_HS2_TDON_HS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_HS2.bit.TDON_HS2;
}

/**
 * @brief Get function for TDON_TDOFF_HS2_LS2_ACT.
 *
 * This function returns the value of the bitfield LS2 detection as active
 * MOSFET when turned ON within register TDON_TDOFF_HS2.
 *
 * @return Value of the bitfield TDON_TDOFF_HS2_LS2_ACT:
 *      - 0: TDON_TDOFF_HS2_LS2_ACT_CONST_0 (LS2 is not the active MOSFET).
 *      - 1: TDON_TDOFF_HS2_LS2_ACT_CONST_1 (LS2 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_HS2_LS2_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_HS2.bit.LS2_ACT;
}

/**
 * @brief Get function for TDON_TDOFF_HS2_HS2_ACT.
 *
 * This function returns the value of the bitfield HS2 detection as active
 * MOSFET when turned ON within register TDON_TDOFF_HS2.
 *
 * @return Value of the bitfield TDON_TDOFF_HS2_HS2_ACT:
 *      - 0: TDON_TDOFF_HS2_HS2_ACT_CONST_0 (HS2 is not the active MOSFET).
 *      - 1: TDON_TDOFF_HS2_HS2_ACT_CONST_1 (HS2 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_HS2_HS2_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_HS2.bit.HS2_ACT;
}

/**
 * @brief get function for register TDON_TDOFF_HS2.
 *
 * This function reads the register Effective MOSFET turn-on/off delay time HS2.
 *
 */
void TLE9186_FuncLayer_get_TDON_TDOFF_HS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  TLE9186_RegLayer_get_TDON_TDOFF_HS2();
}

/**
 * @brief Get function for TDON_TDOFF_LS2_TDOFF_LS2.
 *
 * This function returns the value of the bitfield Effective turn-off delay time
 * of LS2 MOSFET within register TDON_TDOFF_LS2.
 *
 * @return Value of the bitfield TDON_TDOFF_LS2_TDOFF_LS2:
 *      - 0: TDON_TDOFF_LS2_TDOFF_LS2_CONST_0 (min. Value: read-only data).
 *      - 127: TDON_TDOFF_LS2_TDOFF_LS2_CONST_127 (max. value: read-only data).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_LS2_TDOFF_LS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_LS2.bit.TDOFF_LS2;
}

/**
 * @brief Get function for TDON_TDOFF_LS2_TDON_LS2.
 *
 * This function returns the value of the bitfield Effective turn-on delay time
 * of LS2 MOSFET within register TDON_TDOFF_LS2.
 *
 * @return Value of the bitfield TDON_TDOFF_LS2_TDON_LS2:
 *      - 0: TDON_TDOFF_LS2_TDON_LS2_CONST_0 (min. Value: read-only data).
 *      - 127: TDON_TDOFF_LS2_TDON_LS2_CONST_127 (max. value: read-only data).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_LS2_TDON_LS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_LS2.bit.TDON_LS2;
}

/**
 * @brief Get function for TDON_TDOFF_LS2_LS2_ACT.
 *
 * This function returns the value of the bitfield LS2 detection as active
 * MOSFET when turned ON within register TDON_TDOFF_LS2.
 *
 * @return Value of the bitfield TDON_TDOFF_LS2_LS2_ACT:
 *      - 0: TDON_TDOFF_LS2_LS2_ACT_CONST_0 (LS2 is not the active MOSFET).
 *      - 1: TDON_TDOFF_LS2_LS2_ACT_CONST_1 (LS2 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_LS2_LS2_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_LS2.bit.LS2_ACT;
}

/**
 * @brief Get function for TDON_TDOFF_LS2_HS2_ACT.
 *
 * This function returns the value of the bitfield HS2 detection as active
 * MOSFET when turned ON within register TDON_TDOFF_LS2.
 *
 * @return Value of the bitfield TDON_TDOFF_LS2_HS2_ACT:
 *      - 0: TDON_TDOFF_LS2_HS2_ACT_CONST_0 (HS2 is not the active MOSFET).
 *      - 1: TDON_TDOFF_LS2_HS2_ACT_CONST_1 (HS2 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_LS2_HS2_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_LS2.bit.HS2_ACT;
}

/**
 * @brief get function for register TDON_TDOFF_LS2.
 *
 * This function reads the register Effective MOSFET turn-on/off delay time LS2.
 *
 */
void TLE9186_FuncLayer_get_TDON_TDOFF_LS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  TLE9186_RegLayer_get_TDON_TDOFF_LS2();
}

/**
 * @brief Get function for TDON_TDOFF_HS3_TDOFF_HS3.
 *
 * This function returns the value of the bitfield Effective turn-off delay time
 * of HS3 MOSFET within register TDON_TDOFF_HS3.
 *
 * @return Value of the bitfield TDON_TDOFF_HS3_TDOFF_HS3:
 *      - 0: TDON_TDOFF_HS3_TDOFF_HS3_CONST_0 (min. Value: read-only data).
 *      - 127: TDON_TDOFF_HS3_TDOFF_HS3_CONST_127 (max. value: read-only data).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_HS3_TDOFF_HS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_HS3.bit.TDOFF_HS3;
}

/**
 * @brief Get function for TDON_TDOFF_HS3_TDON_HS3.
 *
 * This function returns the value of the bitfield Effective turn-on delay time
 * of HS3 MOSFET within register TDON_TDOFF_HS3.
 *
 * @return Value of the bitfield TDON_TDOFF_HS3_TDON_HS3:
 *      - 0: TDON_TDOFF_HS3_TDON_HS3_CONST_0 (min. Value: read-only data).
 *      - 127: TDON_TDOFF_HS3_TDON_HS3_CONST_127 (max. value: read-only data).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_HS3_TDON_HS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_HS3.bit.TDON_HS3;
}

/**
 * @brief Get function for TDON_TDOFF_HS3_LS3_ACT.
 *
 * This function returns the value of the bitfield LS3 detection as active
 * MOSFET when turned ON within register TDON_TDOFF_HS3.
 *
 * @return Value of the bitfield TDON_TDOFF_HS3_LS3_ACT:
 *      - 0: TDON_TDOFF_HS3_LS3_ACT_CONST_0 (LS3 is not the active MOSFET).
 *      - 1: TDON_TDOFF_HS3_LS3_ACT_CONST_1 (LS3 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_HS3_LS3_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_HS3.bit.LS3_ACT;
}

/**
 * @brief Get function for TDON_TDOFF_HS3_HS3_ACT.
 *
 * This function returns the value of the bitfield HS3 detection as active
 * MOSFET when turned ON within register TDON_TDOFF_HS3.
 *
 * @return Value of the bitfield TDON_TDOFF_HS3_HS3_ACT:
 *      - 0: TDON_TDOFF_HS3_HS3_ACT_CONST_0 (HS3 is not the active MOSFET).
 *      - 1: TDON_TDOFF_HS3_HS3_ACT_CONST_1 (HS3 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_HS3_HS3_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_HS3.bit.HS3_ACT;
}

/**
 * @brief get function for register TDON_TDOFF_HS3.
 *
 * This function reads the register Effective MOSFET turn-on/off delay time HS3.
 *
 */
void TLE9186_FuncLayer_get_TDON_TDOFF_HS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  TLE9186_RegLayer_get_TDON_TDOFF_HS3();
}

/**
 * @brief Get function for TDON_TDOFF_LS3_TDOFF_LS3.
 *
 * This function returns the value of the bitfield Effective turn-off delay time
 * of LS3 MOSFET within register TDON_TDOFF_LS3.
 *
 * @return Value of the bitfield TDON_TDOFF_LS3_TDOFF_LS3:
 *      - 0: TDON_TDOFF_LS3_TDOFF_LS3_CONST_0 (min. Value: read-only data).
 *      - 127: TDON_TDOFF_LS3_TDOFF_LS3_CONST_127 (max. value: read-only data).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_LS3_TDOFF_LS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_LS3.bit.TDOFF_LS3;
}

/**
 * @brief Get function for TDON_TDOFF_LS3_TDON_LS3.
 *
 * This function returns the value of the bitfield Effective turn-on delay time
 * of LS3 MOSFET within register TDON_TDOFF_LS3.
 *
 * @return Value of the bitfield TDON_TDOFF_LS3_TDON_LS3:
 *      - 0: TDON_TDOFF_LS3_TDON_LS3_CONST_0 (min. Value: read-only data).
 *      - 127: TDON_TDOFF_LS3_TDON_LS3_CONST_127 (max. value: read-only data).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_LS3_TDON_LS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_LS3.bit.TDON_LS3;
}

/**
 * @brief Get function for TDON_TDOFF_LS3_LS3_ACT.
 *
 * This function returns the value of the bitfield LS3 detection as active
 * MOSFET when turned ON within register TDON_TDOFF_LS3.
 *
 * @return Value of the bitfield TDON_TDOFF_LS3_LS3_ACT:
 *      - 0: TDON_TDOFF_LS3_LS3_ACT_CONST_0 (LS3 is not the active MOSFET).
 *      - 1: TDON_TDOFF_LS3_LS3_ACT_CONST_1 (LS3 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_LS3_LS3_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_LS3.bit.LS3_ACT;
}

/**
 * @brief Get function for TDON_TDOFF_LS3_HS3_ACT.
 *
 * This function returns the value of the bitfield HS3 detection as active
 * MOSFET when turned ON within register TDON_TDOFF_LS3.
 *
 * @return Value of the bitfield TDON_TDOFF_LS3_HS3_ACT:
 *      - 0: TDON_TDOFF_LS3_HS3_ACT_CONST_0 (HS3 is not the active MOSFET).
 *      - 1: TDON_TDOFF_LS3_HS3_ACT_CONST_1 (HS3 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TDON_TDOFF_LS3_HS3_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TDON_TDOFF_LS3.bit.HS3_ACT;
}

/**
 * @brief get function for register TDON_TDOFF_LS3.
 *
 * This function reads the register Effective MOSFET turn-on/off delay time LS3.
 *
 */
void TLE9186_FuncLayer_get_TDON_TDOFF_LS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  TLE9186_RegLayer_get_TDON_TDOFF_LS3();
}

/**
 * @brief Get function for TSLEW_ON_OFF_HS1_TSLEW_OFF_HS1.
 *
 * This function returns the value of the bitfield Effective turn-off slew rate
 * time of HS1 MOSFET within register TSLEW_ON_OFF_HS1.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_HS1_TSLEW_OFF_HS1:
 *      - 0: TSLEW_ON_OFF_HS1_TSLEW_OFF_HS1_CONST_0 (min. Value: read-only
 * data).
 *      - 127: TSLEW_ON_OFF_HS1_TSLEW_OFF_HS1_CONST_127 (max. value: read-only
 * data).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_HS1_TSLEW_OFF_HS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
           * to register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_HS1.bit.TSLEW_OFF_HS1;
}

/**
 * @brief Get function for TSLEW_ON_OFF_HS1_TSLEW_ON_HS1.
 *
 * This function returns the value of the bitfield Effective turn-on slew rate
 * time of HS1 MOSFET within register TSLEW_ON_OFF_HS1.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_HS1_TSLEW_ON_HS1:
 *      - 0: TSLEW_ON_OFF_HS1_TSLEW_ON_HS1_CONST_0 (min. Value: read-only data).
 *      - 127: TSLEW_ON_OFF_HS1_TSLEW_ON_HS1_CONST_127 (max. value: read-only
 * data).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_HS1_TSLEW_ON_HS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
           * to register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_HS1.bit.TSLEW_ON_HS1;
}

/**
 * @brief Get function for TSLEW_ON_OFF_HS1_LS1_ACT.
 *
 * This function returns the value of the bitfield LS1 detection as active
 * MOSFET when turned ON within register TSLEW_ON_OFF_HS1.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_HS1_LS1_ACT:
 *      - 0: TSLEW_ON_OFF_HS1_LS1_ACT_CONST_0 (LS1 is not the active MOSFET).
 *      - 1: TSLEW_ON_OFF_HS1_LS1_ACT_CONST_1 (LS1 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_HS1_LS1_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_HS1.bit.LS1_ACT;
}

/**
 * @brief Get function for TSLEW_ON_OFF_HS1_HS1_ACT.
 *
 * This function returns the value of the bitfield HS1 detection as active
 * MOSFET when turned ON within register TSLEW_ON_OFF_HS1.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_HS1_HS1_ACT:
 *      - 0: TSLEW_ON_OFF_HS1_HS1_ACT_CONST_0 (HS1 is not the active MOSFET).
 *      - 1: TSLEW_ON_OFF_HS1_HS1_ACT_CONST_1 (HS1 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_HS1_HS1_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_HS1.bit.HS1_ACT;
}

/**
 * @brief get function for register TSLEW_ON_OFF_HS1.
 *
 * This function reads the register Effective MOSFET slew rate time HS1.
 *
 */
void TLE9186_FuncLayer_get_TSLEW_ON_OFF_HS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  TLE9186_RegLayer_get_TSLEW_ON_OFF_HS1();
}

/**
 * @brief Get function for TSLEW_ON_OFF_LS1_TSLEW_OFF_LS1.
 *
 * This function returns the value of the bitfield Effective turn-off slew rate
 * time of LS1 MOSFET within register TSLEW_ON_OFF_LS1.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_LS1_TSLEW_OFF_LS1:
 *      - 0: TSLEW_ON_OFF_LS1_TSLEW_OFF_LS1_CONST_0 (min. Value: read-only
 * data).
 *      - 127: TSLEW_ON_OFF_LS1_TSLEW_OFF_LS1_CONST_127 (max. value: read-only
 * data).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_LS1_TSLEW_OFF_LS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
           * to register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_LS1.bit.TSLEW_OFF_LS1;
}

/**
 * @brief Get function for TSLEW_ON_OFF_LS1_TSLEW_ON_LS1.
 *
 * This function returns the value of the bitfield Effective turn-on slew rate
 * time of LS1 MOSFET within register TSLEW_ON_OFF_LS1.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_LS1_TSLEW_ON_LS1:
 *      - 0: TSLEW_ON_OFF_LS1_TSLEW_ON_LS1_CONST_0 (min. Value: read-only data).
 *      - 127: TSLEW_ON_OFF_LS1_TSLEW_ON_LS1_CONST_127 (max. value: read-only
 * data).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_LS1_TSLEW_ON_LS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
           * to register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_LS1.bit.TSLEW_ON_LS1;
}

/**
 * @brief Get function for TSLEW_ON_OFF_LS1_LS1_ACT.
 *
 * This function returns the value of the bitfield LS1 detection as active
 * MOSFET when turned ON within register TSLEW_ON_OFF_LS1.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_LS1_LS1_ACT:
 *      - 0: TSLEW_ON_OFF_LS1_LS1_ACT_CONST_0 (LS1 is not the active MOSFET).
 *      - 1: TSLEW_ON_OFF_LS1_LS1_ACT_CONST_1 (LS1 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_LS1_LS1_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_LS1.bit.LS1_ACT;
}

/**
 * @brief Get function for TSLEW_ON_OFF_LS1_HS1_ACT.
 *
 * This function returns the value of the bitfield HS1 detection as active
 * MOSFET when turned ON within register TSLEW_ON_OFF_LS1.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_LS1_HS1_ACT:
 *      - 0: TSLEW_ON_OFF_LS1_HS1_ACT_CONST_0 (HS1 is not the active MOSFET).
 *      - 1: TSLEW_ON_OFF_LS1_HS1_ACT_CONST_1 (HS1 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_LS1_HS1_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_LS1.bit.HS1_ACT;
}

/**
 * @brief get function for register TSLEW_ON_OFF_LS1.
 *
 * This function reads the register Effective MOSFET slew rate time LS1.
 *
 */
void TLE9186_FuncLayer_get_TSLEW_ON_OFF_LS1(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  TLE9186_RegLayer_get_TSLEW_ON_OFF_LS1();
}

/**
 * @brief Get function for TSLEW_ON_OFF_HS2_TSLEW_OFF_HS2.
 *
 * This function returns the value of the bitfield Effective turn-off slew rate
 * time of HS2 MOSFET within register TSLEW_ON_OFF_HS2.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_HS2_TSLEW_OFF_HS2:
 *      - 0: TSLEW_ON_OFF_HS2_TSLEW_OFF_HS2_CONST_0 (min. Value: read-only
 * data).
 *      - 127: TSLEW_ON_OFF_HS2_TSLEW_OFF_HS2_CONST_127 (max. value: read-only
 * data).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_HS2_TSLEW_OFF_HS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
           * to register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_HS2.bit.TSLEW_OFF_HS2;
}

/**
 * @brief Get function for TSLEW_ON_OFF_HS2_TSLEW_ON_HS2.
 *
 * This function returns the value of the bitfield Effective turn-on slew rate
 * time of HS2 MOSFET within register TSLEW_ON_OFF_HS2.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_HS2_TSLEW_ON_HS2:
 *      - 0: TSLEW_ON_OFF_HS2_TSLEW_ON_HS2_CONST_0 (min. Value: read-only data).
 *      - 127: TSLEW_ON_OFF_HS2_TSLEW_ON_HS2_CONST_127 (max. value: read-only
 * data).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_HS2_TSLEW_ON_HS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
           * to register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_HS2.bit.TSLEW_ON_HS2;
}

/**
 * @brief Get function for TSLEW_ON_OFF_HS2_LS2_ACT.
 *
 * This function returns the value of the bitfield LS2 detection as active
 * MOSFET when turned ON within register TSLEW_ON_OFF_HS2.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_HS2_LS2_ACT:
 *      - 0: TSLEW_ON_OFF_HS2_LS2_ACT_CONST_0 (LS2 is not the active MOSFET).
 *      - 1: TSLEW_ON_OFF_HS2_LS2_ACT_CONST_1 (LS2 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_HS2_LS2_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_HS2.bit.LS2_ACT;
}

/**
 * @brief Get function for TSLEW_ON_OFF_HS2_HS2_ACT.
 *
 * This function returns the value of the bitfield HS2 detection as active
 * MOSFET when turned ON within register TSLEW_ON_OFF_HS2.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_HS2_HS2_ACT:
 *      - 0: TSLEW_ON_OFF_HS2_HS2_ACT_CONST_0 (HS2 is not the active MOSFET).
 *      - 1: TSLEW_ON_OFF_HS2_HS2_ACT_CONST_1 (HS2 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_HS2_HS2_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_HS2.bit.HS2_ACT;
}

/**
 * @brief get function for register TSLEW_ON_OFF_HS2.
 *
 * This function reads the register Effective MOSFET slew rate time HS2.
 *
 */
void TLE9186_FuncLayer_get_TSLEW_ON_OFF_HS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  TLE9186_RegLayer_get_TSLEW_ON_OFF_HS2();
}

/**
 * @brief Get function for TSLEW_ON_OFF_LS2_TSLEW_OFF_LS2.
 *
 * This function returns the value of the bitfield Effective turn-off slew rate
 * time of LS2 MOSFET within register TSLEW_ON_OFF_LS2.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_LS2_TSLEW_OFF_LS2:
 *      - 0: TSLEW_ON_OFF_LS2_TSLEW_OFF_LS2_CONST_0 (min. Value: read-only
 * data).
 *      - 127: TSLEW_ON_OFF_LS2_TSLEW_OFF_LS2_CONST_127 (max. value: read-only
 * data).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_LS2_TSLEW_OFF_LS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
           * to register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_LS2.bit.TSLEW_OFF_LS2;
}

/**
 * @brief Get function for TSLEW_ON_OFF_LS2_TSLEW_ON_LS2.
 *
 * This function returns the value of the bitfield Effective turn-on slew rate
 * time of LS2 MOSFET within register TSLEW_ON_OFF_LS2.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_LS2_TSLEW_ON_LS2:
 *      - 0: TSLEW_ON_OFF_LS2_TSLEW_ON_LS2_CONST_0 (min. Value: read-only data).
 *      - 127: TSLEW_ON_OFF_LS2_TSLEW_ON_LS2_CONST_127 (max. value: read-only
 * data).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_LS2_TSLEW_ON_LS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
           * to register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_LS2.bit.TSLEW_ON_LS2;
}

/**
 * @brief Get function for TSLEW_ON_OFF_LS2_LS2_ACT.
 *
 * This function returns the value of the bitfield LS2 detection as active
 * MOSFET when turned ON within register TSLEW_ON_OFF_LS2.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_LS2_LS2_ACT:
 *      - 0: TSLEW_ON_OFF_LS2_LS2_ACT_CONST_0 (LS2 is not the active MOSFET).
 *      - 1: TSLEW_ON_OFF_LS2_LS2_ACT_CONST_1 (LS2 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_LS2_LS2_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_LS2.bit.LS2_ACT;
}

/**
 * @brief Get function for TSLEW_ON_OFF_LS2_HS2_ACT.
 *
 * This function returns the value of the bitfield HS2 detection as active
 * MOSFET when turned ON within register TSLEW_ON_OFF_LS2.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_LS2_HS2_ACT:
 *      - 0: TSLEW_ON_OFF_LS2_HS2_ACT_CONST_0 (HS2 is not the active MOSFET).
 *      - 1: TSLEW_ON_OFF_LS2_HS2_ACT_CONST_1 (HS2 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_LS2_HS2_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_LS2.bit.HS2_ACT;
}

/**
 * @brief get function for register TSLEW_ON_OFF_LS2.
 *
 * This function reads the register Effective MOSFET slew rate time LS2.
 *
 */
void TLE9186_FuncLayer_get_TSLEW_ON_OFF_LS2(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  TLE9186_RegLayer_get_TSLEW_ON_OFF_LS2();
}

/**
 * @brief Get function for TSLEW_ON_OFF_HS3_TSLEW_OFF_HS3.
 *
 * This function returns the value of the bitfield Effective turn-off slew rate
 * time of HS3 MOSFET within register TSLEW_ON_OFF_HS3.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_HS3_TSLEW_OFF_HS3:
 *      - 0: TSLEW_ON_OFF_HS3_TSLEW_OFF_HS3_CONST_0 (min. Value: read-only
 * data).
 *      - 127: TSLEW_ON_OFF_HS3_TSLEW_OFF_HS3_CONST_127 (max. value: read-only
 * data).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_HS3_TSLEW_OFF_HS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
           * to register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_HS3.bit.TSLEW_OFF_HS3;
}

/**
 * @brief Get function for TSLEW_ON_OFF_HS3_TSLEW_ON_HS3.
 *
 * This function returns the value of the bitfield Effective turn-on slew rate
 * time of HS3 MOSFET within register TSLEW_ON_OFF_HS3.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_HS3_TSLEW_ON_HS3:
 *      - 0: TSLEW_ON_OFF_HS3_TSLEW_ON_HS3_CONST_0 (min. Value: read-only data).
 *      - 127: TSLEW_ON_OFF_HS3_TSLEW_ON_HS3_CONST_127 (max. value: read-only
 * data).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_HS3_TSLEW_ON_HS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
           * to register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_HS3.bit.TSLEW_ON_HS3;
}

/**
 * @brief Get function for TSLEW_ON_OFF_HS3_LS3_ACT.
 *
 * This function returns the value of the bitfield LS3 detection as active
 * MOSFET when turned ON within register TSLEW_ON_OFF_HS3.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_HS3_LS3_ACT:
 *      - 0: TDON_TDOFF_HS3_LS3_ACT_CONST_0 (LS3 is not the active MOSFET).
 *      - 1: TDON_TDOFF_HS3_LS3_ACT_CONST_1 (LS3 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_HS3_LS3_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_HS3.bit.LS3_ACT;
}

/**
 * @brief Get function for TSLEW_ON_OFF_HS3_HS3_ACT.
 *
 * This function returns the value of the bitfield HS3 detection as active
 * MOSFET when turned ON within register TSLEW_ON_OFF_HS3.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_HS3_HS3_ACT:
 *      - 0: TSLEW_ON_OFF_HS3_HS3_ACT_CONST_0 (HS3 is not the active MOSFET).
 *      - 1: TSLEW_ON_OFF_HS3_HS3_ACT_CONST_1 (HS3 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_HS3_HS3_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_HS3.bit.HS3_ACT;
}

/**
 * @brief get function for register TSLEW_ON_OFF_HS3.
 *
 * This function reads the register Effective MOSFET slew rate time HS3.
 *
 */
void TLE9186_FuncLayer_get_TSLEW_ON_OFF_HS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  TLE9186_RegLayer_get_TSLEW_ON_OFF_HS3();
}

/**
 * @brief Get function for TSLEW_ON_OFF_LS3_TSLEW_OFF_LS3.
 *
 * This function returns the value of the bitfield Effective turn-off slew rate
 * time of LS3 MOSFET within register TSLEW_ON_OFF_LS3.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_LS3_TSLEW_OFF_LS3:
 *      - 0: TSLEW_ON_OFF_LS3_TSLEW_OFF_LS3_CONST_0 (min. Value: read-only
 * data).
 *      - 127: TSLEW_ON_OFF_LS3_TSLEW_OFF_LS3_CONST_127 (max. value: read-only
 * data).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_LS3_TSLEW_OFF_LS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
           * to register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_LS3.bit.TSLEW_OFF_LS3;
}

/**
 * @brief Get function for TSLEW_ON_OFF_LS3_TSLEW_ON_LS3.
 *
 * This function returns the value of the bitfield Effective turn-on slew rate
 * time of LS3 MOSFET within register TSLEW_ON_OFF_LS3.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_LS3_TSLEW_ON_LS3:
 *      - 0: TSLEW_ON_OFF_LS3_TSLEW_ON_LS3_CONST_0 (min. Value: read-only data).
 *      - 127: TSLEW_ON_OFF_LS3_TSLEW_ON_LS3_CONST_127 (max. value: read-only
 * data).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_LS3_TSLEW_ON_LS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due
           * to register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_LS3.bit.TSLEW_ON_LS3;
}

/**
 * @brief Get function for TSLEW_ON_OFF_LS3_LS3_ACT.
 *
 * This function returns the value of the bitfield LS3 detection as active
 * MOSFET when turned ON within register TSLEW_ON_OFF_LS3.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_LS3_LS3_ACT:
 *      - 0: TSLEW_ON_OFF_LS3_LS3_ACT_CONST_0 (LS3 is not the active MOSFET).
 *      - 1: TSLEW_ON_OFF_LS3_LS3_ACT_CONST_1 (LS3 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_LS3_LS3_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_LS3.bit.LS3_ACT;
}

/**
 * @brief Get function for TSLEW_ON_OFF_LS3_HS3_ACT.
 *
 * This function returns the value of the bitfield HS3 detection as active
 * MOSFET when turned ON within register TSLEW_ON_OFF_LS3.
 *
 * @return Value of the bitfield TSLEW_ON_OFF_LS3_HS3_ACT:
 *      - 0: TSLEW_ON_OFF_LS3_HS3_ACT_CONST_0 (HS3 is not the active MOSFET).
 *      - 1: TSLEW_ON_OFF_LS3_HS3_ACT_CONST_1 (HS3 is the active MOSFET).
 */
uint16 TLE9186_FuncLayer_get_TSLEW_ON_OFF_LS3_HS3_ACT(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->TSLEW_ON_OFF_LS3.bit.HS3_ACT;
}

/**
 * @brief get function for register TSLEW_ON_OFF_LS3.
 *
 * This function reads the register Effective MOSFET slew rate time LS3.
 *
 */
void TLE9186_FuncLayer_get_TSLEW_ON_OFF_LS3(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  TLE9186_RegLayer_get_TSLEW_ON_OFF_LS3();
}

/**
 * @brief Get function for DEVICE_VERSION_PROD.
 *
 * This function returns the value of the bitfield Product Identifier within
 * register DEVICE_VERSION.
 *
 * @return Value of the bitfield DEVICE_VERSION_PROD:
 *      - 0: DEVICE_VERSION_PROD_CONST_0 (TLE9189 Mercury IC)).
 *      - 1: DEVICE_VERSION_PROD_CONST_1 (TLE9186 BLDC).
 *      - 2: DEVICE_VERSION_PROD_CONST_2 (TLE9186 DC (HB3 disabled)).
 *      - 3: DEVICE_VERSION_PROD_CONST_3 (T.B.D).
 *      - 63: DEVICE_VERSION_PROD_CONST_63 (T.B.D).
 */
uint16 TLE9186_FuncLayer_get_DEVICE_VERSION_PROD(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to
           * register names" */
{
  return (uint16)TLE9186->DEVICE_VERSION.bit.PROD;
}

/**
 * @brief Get function for DEVICE_VERSION_FAM.
 *
 * This function returns the value of the bitfield Family Identifier within
 * register DEVICE_VERSION.
 *
 * @return Value of the bitfield DEVICE_VERSION_FAM:
 *      - 0: DEVICE_VERSION_FAM_CONST_0 (EPS EBB  (TLE9189 Family)).
 *      - 1: DEVICE_VERSION_FAM_CONST_1 (TLE9186 Family).
 *      - 2: DEVICE_VERSION_FAM_CONST_2 (T.B.D).
 *      - 3: DEVICE_VERSION_FAM_CONST_3 (T.B.D).
 *      - 4: DEVICE_VERSION_FAM_CONST_4 (T.B.D).
 *      - 5: DEVICE_VERSION_FAM_CONST_5 (T.B.D).
 *      - 6: DEVICE_VERSION_FAM_CONST_6 (T.B.D).
 *      - 7: DEVICE_VERSION_FAM_CONST_7 (T.B.D).
 *      - 8: DEVICE_VERSION_FAM_CONST_8 (T.B.D).
 *      - 9: DEVICE_VERSION_FAM_CONST_9 (T.B.D).
 *      - 10: DEVICE_VERSION_FAM_CONST_10 (T.B.D).
 *      - 11: DEVICE_VERSION_FAM_CONST_11 (T.B.D).
 *      - 12: DEVICE_VERSION_FAM_CONST_12 (T.B.D).
 *      - 13: DEVICE_VERSION_FAM_CONST_13 (T.B.D).
 *      - 14: DEVICE_VERSION_FAM_CONST_14 (T.B.D).
 *      - 15: DEVICE_VERSION_FAM_CONST_15 (T.B.D).
 */
uint16 TLE9186_FuncLayer_get_DEVICE_VERSION_FAM(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  return (uint16)TLE9186->DEVICE_VERSION.bit.FAM;
}

/**
 * @brief get function for register DEVICE_VERSION.
 *
 * This function reads the register Device version information.
 *
 */
void TLE9186_FuncLayer_get_DEVICE_VERSION(
    void) /* polyspace MISRA2012:5.1 [Justified: Low] "Given due to register
           * names" */
{
  TLE9186_RegLayer_get_DEVICE_VERSION();
}

/**
 * @}
 */
/**
 * @}
 */
