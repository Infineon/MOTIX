/**
 *	@file TLE9186.h
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
 *
 * @defgroup device_driver TLE9186 Device Driver
 * @brief A microcontroller independent device driver for the TLE9186 gate
 * driver IC from Infineon Technologies AG.
 * @details The MOTIX™ TLE9186 device driver is a microcontroller-independent
 * embedded software library that provides an easy-to-use API for configuring
 * and operating the TLE9186 gate driver IC. It is designed to be
 * microcontroller-independent, allowing it to be integrated into various
 * microcontroller platforms without modification to the core driver code. The
 * device driver is available in the Infineon Developer Center.
 *
 * @defgroup shadowRegs Shadow Registers
 * @brief The Shadow Register holds a copy of the internal registers of the
 * TLE9186.
 *
 */

#ifndef TLE9186_H
#define TLE9186_H

/************************************************************************
**                             Includes                                **
************************************************************************/

#include "TLE9186_types.h"

/**
 * @addtogroup device_driver
 * @{
 */
/**
 * @addtogroup shadowRegs
 * @{
 */
/**
 * @brief TLE9186 Register Shadow
 *
 * The register shadow holds a 1:1 copy of the TLE9186 registers and is updated
 * during runtime.
 *
 */
typedef struct /*!< TLE9186 structure */
{
  union {
    volatile uint16 reg; /*!< Register CONFIG_SECURED */
    struct {
      volatile uint16 FW_CFG : 1; /*!< [0..0] Freewheeling device
                                     charge/discharge phase configuration */
      volatile uint16
          OFF_CFG : 1; /*!< [1..1] Switch OFF behavior in case of detected
                        * faults leading to gate driver OFF */
      volatile uint16
          GDRV_CFG : 1; /*!< [2..2] Gate Driver Operation Mode Configuration */
      volatile uint16 GDRV_RNG : 1; /*!< [3..3] Gate Driver Output Current Range
                                       Configuration */
      volatile uint16
          VIO_CFG : 2; /*!< [4..5] VIO voltage level configuration bits */
      volatile uint16
          SPI_TYPE : 2; /*!< [6..7] SPI SDO response type configuration bits */
      volatile uint16 INHN_L_CFG : 1; /*!< [8..8] INHN low detection wait time
                                         configuration */
      volatile uint16
          PWM_MAP : 1; /*!< [9..9] PWM mapping to gate drivers configuration */
      volatile uint16 WD_EN : 1;  /*!< [10..10] Watchdog enable */
      volatile uint16 CP_CFG : 1; /*!< [11..11] Charge pump Configuration  */
      volatile uint16
          CP_CLK_SEL : 2; /*!< [12..13] Charge Pump Clock selection */
      uint16 : 2;         /*!< [14..15] Reserved */
    } bit;
  } CONFIG_SECURED;
  union {
    volatile uint16 reg; /*!< Register PWR_MOD_CFG */
    struct {
      volatile uint16
          MODE_CTRL : 2; /*!< [0..1] Device operation mode configuration */
      uint16 : 12;       /*!< [2..13] Reserved */
      volatile uint16
          CLR_STATS : 1; /*!< [14..14] Clear SPI device status registers */
      volatile uint16 CLR_CONFIG : 1; /*!< [15..15] Clear SPI device
                                         configuration registers */
    } bit;
  } PWR_MOD_CFG;
  union {
    volatile uint16 reg; /*!< Register WD_CFG */
    struct {
      volatile uint16 WD_PER : 3; /*!< [0..2] Watchdog period configuration */
      volatile uint16
          WD_FAIL : 3; /*!< [3..5] Watchdog fails counter configuration */
      uint16 : 9;      /*!< [6..14] Reserved */
      volatile uint16
          CHECKSUM : 1; /*!< [15..15] Watchdog configuration checksum bit */
    } bit;
  } WD_CFG;
  union {
    volatile uint16 reg; /*!< Register GEN_CFG1 */
    struct {
      volatile uint16
          SOFF_ON : 1; /*!< [0..0] Safe State activation via SPI command */
      volatile uint16
          ERRN_ON : 1; /*!< [1..1] ERRN function activation via SPI command */
      volatile uint16
          TW_EN : 1; /*!< [2..2] ERRN function activation via SPI command */
      volatile uint16 CSA_EN : 1; /*!< [3..3] Current sense amplifier enable */
      volatile uint16
          HBFREQ : 1; /*!< [4..4] Half-bridge synchronization frequency */
      volatile uint16 HB1_EN : 1; /*!< [5..5] Half-bridge 1 enable */
      volatile uint16 HB2_EN : 1; /*!< [6..6] Half-bridge 2 enable */
      volatile uint16 HB3_EN : 1; /*!< [7..7] Half-bridge 3 enable */
      volatile uint16
          PFB_EN : 1; /*!< [8..8] Phase feedback monitoring enable */
      volatile uint16 CP_REC_OV : 1; /*!< [9..9] Charge pump recovery in case of
                                        VSCP_OV_SD event */
      volatile uint16 CP_REC_UV : 1; /*!< [10..10] Charge pump recovery in case
                                        of VSCP_UV_SD event */
      volatile uint16 CP_FMOD : 2;   /*!< [11..12] Charge pump frequency
                                        modulation configuration */
      volatile uint16 CP_MODE : 2;   /*!< [13..14] Charge Pump Operation Mode
                                        configuration bits */
      volatile uint16 CP_EN : 1; /*!< [15..15] Charge pump function enable */
    } bit;
  } GEN_CFG1;
  union {
    volatile uint16 reg; /*!< Register GEN_CFG2 */
    struct {
      volatile uint16
          OFF_DIAG_EN : 1; /*!< [0..0] OFF-state diagnostic function enable */
      volatile uint16 HB1IDIAG : 1; /*!< [1..1] OFF-state diagnostic control of
                                       HB1 pull-down current */
      volatile uint16 HB2IDIAG : 1; /*!< [2..2] OFF-state diagnostic control of
                                       HB2 pull-down current */
      volatile uint16 HB3IDIAG : 1; /*!< [3..3] OFF-state diagnostic control of
                                       HB3 pull-down current */
      volatile uint16
          IPV_CCP_DIS : 1; /*!< [4..4] Disable input pattern violation for
                              cross-current protection */
      volatile uint16 CSN_TO_DIS : 1; /*!< [5..5] CSN time-out disable option */
      volatile uint16 CP_UV_TH : 1;   /*!< [6..6] Charge Pump under-voltage
                                         threshold selection */
      uint16 : 3;                     /*!< [7..9] Reserved */
      volatile uint16
          TW_TH : 2; /*!< [10..11] Temperature warning threshold selection */
      uint16 : 3;    /*!< [12..14] Reserved */
      volatile uint16
          TPFB : 1; /*!< [15..15] PFB monitoring filter time configuration */
    } bit;
  } GEN_CFG2;
  union {
    volatile uint16 reg; /*!< Register GEN_CFG3 */
    struct {
      volatile uint16 Spares : 5; /*!< [0..4] Spares registered bits */
      uint16 : 11;                /*!< [5..15] Reserved */
    } bit;
  } GEN_CFG3;
  union {
    volatile uint16 reg; /*!< Register GDRV_CFG1 */
    struct {
      volatile uint16
          TCCP_FW : 4; /*!< [0..3] Cross-current protection time configuration
                        * of the freewheeling MOSFET */
      volatile uint16 TCCP : 4;       /*!< [4..7] Cross-current protection time
                                       * configuration of the active MOSFET
                                       * */
      volatile uint16 TVDSBLK_FW : 4; /*!< [8..11] Blanking time configuration
                                         of the freewheeling MOSFET */
      volatile uint16 TVDSBLK : 4; /*!< [12..15] Blanking time configuration of
                                      the active MOSFET */
    } bit;
  } GDRV_CFG1;
  union {
    volatile uint16 reg; /*!< Register GDRV_CFG2 */
    struct {
      volatile uint16 LS_DSOVTH : 3; /*!< [0..2] LS MOSFETs drain-source
                                        threshold configuration */
      volatile uint16 HS_DSOVTH : 3; /*!< [3..5] HS MOSFETs drain-source
                                        threshold configuration */
      volatile uint16 TVDSFILT : 2;  /*!< [6..7] Drain-source monitoring
                                        comparators filter time */
      volatile uint16
          TFW : 6; /*!< [8..13] Freewheeling device charge/discharge time  */
      volatile uint16 PWM_CHCK_EN : 1; /*!< [14..14] Enable PWM alternation
                                          monitoring function */
      volatile uint16 TCCP_CFG : 1; /*!< [15..15] Cross-Current protection times
                                       clock selection */
    } bit;
  } GDRV_CFG2;
  union {
    volatile uint16 reg; /*!< Register GDRV_CFG3 */
    struct {
      volatile uint16
          IDCHG_ST : 3;        /*!< [0..2] Gate Driver static discharge current
                                * configuration(last 3 LSBs of        ICHG = 111) */
      volatile uint16 IFW : 3; /*!< [3..5] Freewheeling charge and discharge
                                * current setting(last 3 LSBs of ICHG = 111) */
      volatile uint16
          IHOLD : 2; /*!< [6..7] Bridge Driver Hold Current configuration */
      volatile uint16 ION_TR : 2; /*!< [8..9] Configuration of the transition to
                                     post-charge phase(current) */
      uint16 : 6;                 /*!< [10..15] Reserved */
    } bit;
  } GDRV_CFG3;
  union {
    volatile uint16 reg; /*!< Register TON_HS */
    struct {
      volatile uint16 T2ON_HS : 6; /*!< [0..5] High Side gate driver charge time
                                      configuration */
      uint16 : 2;                  /*!< [6..7] Reserved */
      volatile uint16 T1ON_HS : 6; /*!< [8..13] High Side gate driver pre-charge
                                      time configuration */
      uint16 : 2;                  /*!< [14..15] Reserved */
    } bit;
  } TON_HS;
  union {
    volatile uint16 reg; /*!< Register TON_LS */
    struct {
      volatile uint16 T2ON_LS : 6; /*!< [0..5] Low Side gate driver charge time
                                      configuration */
      uint16 : 2;                  /*!< [6..7] Reserved */
      volatile uint16 T1ON_LS : 6; /*!< [8..13] Low Side gate driver pre-charge
                                      time configuration */
      uint16 : 2;                  /*!< [14..15] Reserved */
    } bit;
  } TON_LS;
  union {
    volatile uint16 reg; /*!< Register TOFF_HS */
    struct {
      volatile uint16 T2OFF_HS : 6; /*!< [0..5] High Side gate driver discharge
                                       time configuration */
      uint16 : 2;                   /*!< [6..7] Reserved */
      volatile uint16 T1OFF_HS : 6; /*!< [8..13] High Side gate driver
                                       pre-discharge time configuration */
      uint16 : 2;                   /*!< [14..15] Reserved */
    } bit;
  } TOFF_HS;
  union {
    volatile uint16 reg; /*!< Register TOFF_LS */
    struct {
      volatile uint16 T2OFF_LS : 6; /*!< [0..5] Low Side gate driver discharge
                                       time configuration */
      uint16 : 2;                   /*!< [6..7] Reserved */
      volatile uint16 T1OFF_LS : 6; /*!< [8..13] Low Side gate driver
                                       pre-discharge time configuration */
      uint16 : 2;                   /*!< [14..15] Reserved */
    } bit;
  } TOFF_LS;
  union {
    volatile uint16 reg; /*!< Register T3OFF */
    struct {
      volatile uint16 T3OFF_LS : 6; /*!< [0..5] Low Side gate driver
                                       post-discharge time configuration */
      uint16 : 2;                   /*!< [6..7] Reserved */
      volatile uint16 T3OFF_HS : 6; /*!< [8..13] High Side gate driver
                                       post-discharge time configuration */
      uint16 : 2;                   /*!< [14..15] Reserved */
    } bit;
  } T3OFF;
  union {
    volatile uint16 reg; /*!< Register ION_HS1 */
    struct {
      volatile uint16
          I2ON_HS1 : 6; /*!< [0..5] HS1 Gate Driver charge current setting */
      uint16 : 2;       /*!< [6..7] Reserved */
      volatile uint16 I1ON_HS1 : 6;   /*!< [8..13] HS1 Gate Driver pre-charge
                                         current setting */
      volatile uint16 ION_HS_BNK : 2; /*!< [14..15] Banking configuration of
                                         I1ON, I2ON HS charge current */
    } bit;
  } ION_HS1;
  union {
    volatile uint16 reg; /*!< Register ION_LS1 */
    struct {
      volatile uint16
          I2ON_LS1 : 6; /*!< [0..5] LS1 Gate Driver charge current setting */
      uint16 : 2;       /*!< [6..7] Reserved */
      volatile uint16 I1ON_LS1 : 6;   /*!< [8..13] LS1 Gate Driver pre-charge
                                         current setting */
      volatile uint16 ION_LS_BNK : 2; /*!< [14..15] Banking configuration of
                                         I1ON, I2ON LS charge current */
    } bit;
  } ION_LS1;
  union {
    volatile uint16 reg; /*!< Register ION_HS2 */
    struct {
      volatile uint16
          I2ON_HS2 : 6; /*!< [0..5] HS2 Gate Driver charge current setting */
      uint16 : 2;       /*!< [6..7] Reserved */
      volatile uint16 I1ON_HS2 : 6; /*!< [8..13] HS2 Gate Driver pre-charge
                                       current setting */
      uint16 : 2;                   /*!< [14..15] Reserved */
    } bit;
  } ION_HS2;
  union {
    volatile uint16 reg; /*!< Register ION_LS2 */
    struct {
      volatile uint16
          I2ON_LS2 : 6; /*!< [0..5] LS2 Gate Driver charge current setting */
      uint16 : 2;       /*!< [6..7] Reserved */
      volatile uint16 I1ON_LS2 : 6; /*!< [8..13] LS2 Gate Driver pre-charge
                                       current setting */
      uint16 : 2;                   /*!< [14..15] Reserved */
    } bit;
  } ION_LS2;
  union {
    volatile uint16 reg; /*!< Register ION_HS3 */
    struct {
      volatile uint16
          I2ON_HS3 : 6; /*!< [0..5] HS3 Gate Driver charge current setting */
      uint16 : 2;       /*!< [6..7] Reserved */
      volatile uint16 I1ON_HS3 : 6; /*!< [8..13] HS3 Gate Driver pre-charge
                                       current setting */
      uint16 : 2;                   /*!< [14..15] Reserved */
    } bit;
  } ION_HS3;
  union {
    volatile uint16 reg; /*!< Register ION_LS3 */
    struct {
      volatile uint16
          I2ON_LS3 : 6; /*!< [0..5] LS3 Gate Driver charge current setting */
      uint16 : 2;       /*!< [6..7] Reserved */
      volatile uint16 I1ON_LS3 : 6; /*!< [8..13] LS3 Gate Driver pre-charge
                                       current setting */
      uint16 : 2;                   /*!< [14..15] Reserved */
    } bit;
  } ION_LS3;
  union {
    volatile uint16 reg; /*!< Register I3ON */
    struct {
      volatile uint16 I3ON_LS : 6; /*!< [0..5] Low Side gate driver post-charge
                                      current setting */
      uint16 : 2;                  /*!< [6..7] Reserved */
      volatile uint16 I3ON_HS : 6; /*!< [8..13] High Side gate driver
                                      post-charge current setting */
      uint16 : 2;                  /*!< [14..15] Reserved */
    } bit;
  } I3ON;
  union {
    volatile uint16 reg; /*!< Register ION_IOFF_DIDT */
    struct {
      volatile uint16 IOFF : 6; /*!< [0..5] Gate driver discharge current during
                                   dI/dT phase */
      uint16 : 2;               /*!< [6..7] Reserved */
      volatile uint16
          ION : 6; /*!< [8..13] Gate driver charge current during dI/dT phase */
      uint16 : 2;  /*!< [14..15] Reserved */
    } bit;
  } ION_IOFF_DIDT;
  union {
    volatile uint16 reg; /*!< Register IOFF_HS1 */
    struct {
      volatile uint16 I2OFF_HS1 : 6;  /*!< [0..5] HS1 Gate Driver discharge
                                         current setting */
      uint16 : 2;                     /*!< [6..7] Reserved */
      volatile uint16 I1OFF_HS1 : 6;  /*!< [8..13] HS1 Gate Driver pre-discharge
                                         current setting */
      volatile uint16 ION_HS_BNK : 2; /*!< [14..15] Banking configuration of
                                         I1ON, I2ON HS charge current */
    } bit;
  } IOFF_HS1;
  union {
    volatile uint16 reg; /*!< Register IOFF_LS1 */
    struct {
      volatile uint16 I2OFF_LS1 : 6; /*!< [0..5] LS1 Gate Driver discharge
                                        current setting */
      uint16 : 2;                    /*!< [6..7] Reserved */
      volatile uint16 I1OFF_LS1 : 6; /*!< [8..13] LS1 Gate Driver pre-discharge
                                        current setting */
      volatile uint16 IOFF_LS_BNK : 2; /*!< [14..15] Banking configuration of
                                          I1OFF, I2OFF LS discharge current */
    } bit;
  } IOFF_LS1;
  union {
    volatile uint16 reg; /*!< Register IOFF_HS2 */
    struct {
      volatile uint16 I2OFF_HS2 : 6; /*!< [0..5] HS2 Gate Driver discharge
                                        current setting */
      uint16 : 2;                    /*!< [6..7] Reserved */
      volatile uint16 I1OFF_HS2 : 6; /*!< [8..13] HS2 Gate Driver pre-discharge
                                        current setting */
      uint16 : 2;                    /*!< [14..15] Reserved */
    } bit;
  } IOFF_HS2;
  union {
    volatile uint16 reg; /*!< Register IOFF_LS2 */
    struct {
      volatile uint16 I2OFF_LS2 : 6; /*!< [0..5] LS2 Gate Driver discharge
                                        current setting */
      uint16 : 2;                    /*!< [6..7] Reserved */
      volatile uint16 I1OFF_LS2 : 6; /*!< [8..13] LS2 Gate Driver pre-discharge
                                        current setting */
      uint16 : 2;                    /*!< [14..15] Reserved */
    } bit;
  } IOFF_LS2;
  union {
    volatile uint16 reg; /*!< Register IOFF_HS3 */
    struct {
      volatile uint16 I2OFF_HS3 : 6; /*!< [0..5] HS3 Gate Driver discharge
                                        current setting */
      uint16 : 2;                    /*!< [6..7] Reserved */
      volatile uint16 I1OFF_HS3 : 6; /*!< [8..13] HS3 Gate Driver pre-discharge
                                        current setting */
      uint16 : 2;                    /*!< [14..15] Reserved */
    } bit;
  } IOFF_HS3;
  union {
    volatile uint16 reg; /*!< Register IOFF_LS3 */
    struct {
      volatile uint16 I2OFF_LS3 : 6; /*!< [0..5] LS3 Gate Driver discharge
                                        current setting */
      uint16 : 2;                    /*!< [6..7] Reserved */
      volatile uint16 I1OFF_LS3 : 6; /*!< [8..13] LS3 Gate Driver pre-discharge
                                        current setting */
      uint16 : 2;                    /*!< [14..15] Reserved */
    } bit;
  } IOFF_LS3;
  union {
    volatile uint16 reg; /*!< Register CSA_CFG */
    struct {
      volatile uint16 CSA_TFOC : 2;  /*!< [0..1] Current sense amplifier
                                        overcurrent filter time setting */
      volatile uint16 CSA_OC_TH : 2; /*!< [2..3] Current sense amplifier
                                        overcurrent detection threshold */
      volatile uint16 CSA_CLOAD : 1; /*!< [4..4] Current sense amplifier output
                                        capacitive load range */
      volatile uint16
          CSA_DIR : 1; /*!< [5..5] Direction of current sense amplifier */
      volatile uint16 CSA_GAIN : 3;     /*!< [6..8] Current sense amplifier
                                           differential gain configuration */
      volatile uint16 CSA_GAIN_TST : 1; /*!< [9..9] CSA gain accuracy check */
      volatile uint16 CSO_MUX : 3; /*!< [10..12] Current Sense Amplifier Output
                                    * redirection of digital PFB signals */
      volatile uint16 CSA_REC : 1; /*!< [13..13] CSA recovery in case of VIO
                                      under-voltage event  */
      uint16 : 2;                  /*!< [14..15] Reserved */
    } bit;
  } CSA_CFG;
  union {
    volatile uint16 reg; /*!< Register FAILURE_CFG */
    struct {
      volatile uint16 CSA_OC_FM : 2; /*!< [0..1] Current sense amplifiers
                                        overcurrent failure reaction */
      volatile uint16
          CSA_SUP_UV_FM : 2;          /*!< [2..3] Internal supply of CSA module
                                       * under-voltage failure reaction
                                       * */
      volatile uint16 PWM_CHK_FM : 1; /*!< [4..4] Failure reaction in case of
                                       * missing PWM alternation detection
                                       * */
      volatile uint16 SDO_SHORT_FM : 1; /*!< [5..5] SDO short to supply or
                                           ground event , failure reaction   */
      volatile uint16 INHN_REC_FM : 1;  /*!< [6..6] INHN recovery after INHN low
                                           level reaction */
      volatile uint16 OTP_ERR_FM : 1;   /*!< [7..7] OTP module error failure
                                           reaction configuration */
      volatile uint16 WD_FM : 1; /*!< [8..8] Window watchdog failure reaction */
      volatile uint16
          TW_FM : 1; /*!< [9..9] Temperature warning failure reaction */
      volatile uint16
          ERRN_FM : 1; /*!< [10..10] ERRN short to supply failure reaction */
      volatile uint16 IPV_STP_FM : 1; /*!< [11..11] Shoot-through protection
                                         violation failure reaction */
      volatile uint16 IPV_CCP_FM : 1; /*!< [12..12] Input pattern violation due
                                       * to TCCP violation failure reaction */
      volatile uint16 PFB_FM : 1;     /*!< [13..13] Phase feedback monitoring
                                         failure reaction */
      volatile uint16 DSOV_FM : 1;    /*!< [14..14] Drain-source overvoltage
                                         failure reaction */
      uint16 : 1;                     /*!< [15..15] Reserved */
    } bit;
  } FAILURE_CFG;
  union {
    volatile uint16 reg; /*!< Register SELF_TEST_CFG */
    struct {
      volatile uint16 LAT_FAULT_ST : 1; /*!< [0..0] Latent faults detector
                                           self-test enable */
      volatile uint16 CLK_MON_ST : 1; /*!< [1..1] Digital core clock monitoring
                                         self-test enable */
      volatile uint16 REG_UV_ST : 1;  /*!< [2..2] Internal regulator under
                                         voltage self-test enable */
      volatile uint16 CSA_OC_ST : 1;  /*!< [3..3] Current sense amplifier
                                       * over-current supply self-test enable
                                       * */
      volatile uint16 CSA_SUP_ST : 1; /*!< [4..4] Current sense amplifier
                                         internal supply self-test enable */
      volatile uint16 CPMON_ST : 1; /*!< [5..5] VCPH overdrive and undervoltage
                                       monitoring Self-test enable */
      volatile uint16
          VSCP_MON_ST : 1; /*!< [6..6] VSCP monitoring self-test enable */
      volatile uint16 SOFF_ST : 1; /*!< [7..7] Safe state activation path
                                      self-test enable */
      volatile uint16
          TSD_ST : 1; /*!< [8..8] Overtemperature monitoring self-test enable */
      volatile uint16 PFB_ST : 1; /*!< [9..9] PFB logic self-test enable */
      volatile uint16
          VIO_MON_ST : 1; /*!< [10..10] VIO monitoring self-test enable */
      volatile uint16
          DSOV_ST : 1; /*!< [11..11] Drain-source monitoring self-test enable */
      uint16 : 4;      /*!< [12..15] Reserved */
    } bit;
  } SELF_TEST_CFG;
  union {
    volatile uint16 reg; /*!< Register SUP_STAT */
    struct {
      volatile uint16 VIO_OV : 1;     /*!< [0..0] VIO overvoltage detection */
      volatile uint16 VIO_UV : 1;     /*!< [1..1] VIO undervoltage detection */
      volatile uint16 CSA_SUP_UV : 1; /*!< [2..2] Current sense amplifier
                                         internal supply undervoltage */
      volatile uint16 VDH_UV : 1; /*!< [3..3] VDH pin under-voltage detection */
      volatile uint16
          VSCP_H : 1; /*!< [4..4] VSCP High undervoltage detection  */
      volatile uint16 VSCP_L : 1; /*!< [5..5] VSCP Low undervoltage detection */
      volatile uint16 VCPH_UV : 1; /*!< [6..6] Charge pump output VCPH
                                      undervoltage detection */
      volatile uint16
          VSCP_OV_SD : 1; /*!< [7..7] VSCP overvoltage shutdown detection */
      volatile uint16
          VSCP_UV_SD : 1; /*!< [8..8] VSCP undervoltage shutdown detection */
      uint16 : 6;         /*!< [9..14] Reserved */
      volatile uint16 POR : 1; /*!< [15..15] Power on reset detection */
    } bit;
  } SUP_STAT;
  union {
    volatile uint16 reg; /*!< Register SPI_STAT */
    struct {
      volatile uint16 FRAME_ERR : 1; /*!< [0..0] SPI frame error detection */
      volatile uint16 SPI_IA : 1;    /*!< [1..1] Invalid SPI access detection */
      volatile uint16 CRC_FAIL : 1;  /*!< [2..2] CRC failure detection */
      volatile uint16 OFC : 1; /*!< [3..3] One SPI frame corrupted detection */
      volatile uint16 CSN_TO : 1; /*!< [4..4] CSN time-out detection */
      volatile uint16
          SDO_SHORT : 1; /*!< [5..5] SDO short to supply or ground detection */
      uint16 : 1;        /*!< [6..6] Reserved */
      volatile uint16 WDLE : 1; /*!< [7..7] Watchdog latched error detection */
      volatile uint16 WDE : 1;  /*!< [8..8] Watchdog error detection */
      volatile uint16 WD_CNT : 5; /*!< [9..13] Watchdog fails counter */
      uint16 : 1;                 /*!< [14..14] Reserved */
      volatile uint16
          OTP_ERR : 1; /*!< [15..15] OTP configuration error detection */
    } bit;
  } SPI_STAT;
  union {
    volatile uint16 reg; /*!< Register DEV_STAT1 */
    struct {
      volatile uint16
          ERR_N_LVL : 1; /*!< [0..0] ERR_N output pin level monitoring (real
                          * time input pin monitoring) */
      volatile uint16
          INH_N_LVL : 1; /*!< [1..1] INH_N input pin level monitoring (real time
                          * input pin monitoring) */
      volatile uint16 INHN_L_DET : 1; /*!< [2..2] INH_N input pin low level
                                       * detection (canceled power-down event)
                                       * */
      volatile uint16
          IL1_LVL : 1; /*!< [3..3] LS1 PWM input pin level monitoring (real time
                        * input pin monitoring) */
      volatile uint16
          IL2_LVL : 1; /*!< [4..4] LS2 PWM input pin level monitoring (real time
                        * input pin monitoring) */
      volatile uint16
          IL3_LVL : 1; /*!< [5..5] LS3 PWM input pin level monitoring (real time
                        * input pin monitoring) */
      volatile uint16
          IH1N_LVL : 1; /*!< [6..6] HS1 PWM input pin level monitoring (real
                         * time input pin monitoring) */
      volatile uint16
          IH2N_LVL : 1; /*!< [7..7] HS2 PWM input pin level monitoring (real
                         * time input pin monitoring) */
      volatile uint16
          IH3N_LVL : 1; /*!< [8..8] HS3 PWM input pin level monitoring (real
                         * time input pin monitoring) */
      uint16 : 1;       /*!< [9..9] Reserved */
      volatile uint16 ERRN_ACT : 1; /*!< [10..10] ERR_N pin active low */
      volatile uint16 SOFF_ACT : 1; /*!< [11..11] Safe state activation */
      uint16 : 2;                   /*!< [12..13] Reserved */
      volatile uint16 DEV_STAT : 2; /*!< [14..15] Device operation mode status
                                       information */
    } bit;
  } DEV_STAT1;
  union {
    volatile uint16 reg; /*!< Register DEV_STAT2 */
    struct {
      volatile uint16
          TSD_CP : 1; /*!< [0..0] Charge pump overtemperature detection */
      volatile uint16
          TSD_IC : 1; /*!< [1..1] General overtemperature shutdown detection */
      volatile uint16
          TSDW : 1; /*!< [2..2] Over temperature warning detection */
      volatile uint16 CSA_OC : 1; /*!< [3..3] CSA overcurrent detection */
      volatile uint16
          ERRN_SHORT : 1; /*!< [4..4] ERR_N pin short to supply detection */
      volatile uint16 PFB1_LE : 1; /*!< [5..5] Phase feedback monitoring of SH1
                                      latched error detection */
      volatile uint16 PFB2_LE : 1; /*!< [6..6] Phase feedback monitoring of SH2
                                      latched error detection */
      volatile uint16 PFB3_LE : 1; /*!< [7..7] Phase feedback monitoring of SH3
                                      latched error detection */
      uint16 : 1;                  /*!< [8..8] Reserved */
      volatile uint16
          IPV_STP_HB1 : 1; /*!< [9..9] Half-bridge 1 input pattern violation due
                            * to shoot-through protection */
      volatile uint16
          IPV_STP_HB2 : 1; /*!< [10..10] Half-bridge 2 input pattern violation
                            * due to shoot-through protection */
      volatile uint16
          IPV_STP_HB3 : 1; /*!< [11..11] Half-bridge 3 input pattern violation
                            * due to shoot-through protection */
      volatile uint16
          IPV_CCP_HB1 : 1; /*!< [12..12] Half-bridge 1 input pattern violation
                            * due to cross-current protection */
      volatile uint16
          IPV_CCP_HB2 : 1; /*!< [13..13] Half-bridge 2 input pattern violation
                            * due to cross-current protection */
      volatile uint16
          IPV_CCP_HB3 : 1; /*!< [14..14] Half-bridge 3 input pattern violation
                            * due to cross-current protection */
      uint16 : 1;          /*!< [15..15] Reserved */
    } bit;
  } DEV_STAT2;
  union {
    volatile uint16 reg; /*!< Register LF_STAT */
    struct {
      volatile uint16 ST_RES : 1; /*!< [0..0] Self-test result */
      volatile uint16 ST_RDY : 1; /*!< [1..1] Self-test status */
      volatile uint16
          LAT_FAULT : 1; /*!< [2..2] Internal latent fault detection */
      volatile uint16 DSOV_LF_HB1 : 1; /*!< [3..3] Half-bridge 1 drain-source
                                          monitor latent fault detection */
      volatile uint16 DSOV_LF_HB2 : 1; /*!< [4..4] Half-bridge 2 drain-source
                                          monitor latent fault detection */
      volatile uint16 DSOV_LF_HB3 : 1; /*!< [5..5] Half-bridge 3 drain-source
                                          monitor latent fault detection */
      uint16 : 3;                      /*!< [6..8] Reserved */
      volatile uint16 BIAS_LF : 1;   /*!< [9..9] Central bias monitoring latent
                                        fault detection */
      volatile uint16 SOFF_GDRV : 1; /*!< [10..10] Safe state entry indication
                                        with all 6 gate drivers */
      uint16 : 5;                    /*!< [11..15] Reserved */
    } bit;
  } LF_STAT;
  union {
    volatile uint16 reg; /*!< Register SH_LEVEL_STAT */
    struct {
      volatile uint16
          VSH1_L : 1; /*!< [0..0] Phase 1 voltage monitoring (SH1) VSHL */
      volatile uint16
          VSH1_H : 1; /*!< [1..1] Phase 1 voltage monitoring (SH1) VSHH */
      volatile uint16
          VSH2_L : 1; /*!< [2..2] Phase 2 voltage monitoring (SH2) VSHL */
      volatile uint16
          VSH2_H : 1; /*!< [3..3] Phase 2 voltage monitoring (SH2) VSHH */
      volatile uint16
          VSH3_L : 1; /*!< [4..4] Phase 3 voltage monitoring (SH3) VSHL */
      volatile uint16
          VSH3_H : 1; /*!< [5..5] Phase 3 voltage monitoring (SH3) VSHH */
      uint16 : 5;     /*!< [6..10] Reserved */
      volatile uint16 PFB1 : 1; /*!< [11..11] Phase feedback comparator level of
                                   SH1 phase */
      volatile uint16 PFB2 : 1; /*!< [12..12] Phase feedback comparator level of
                                   SH2 phase */
      volatile uint16 PFB3 : 1; /*!< [13..13] Phase feedback comparator level of
                                   SH3 phase */
      uint16 : 2;               /*!< [14..15] Reserved */
    } bit;
  } SH_LEVEL_STAT;
  union {
    volatile uint16 reg; /*!< Register BD_STAT */
    struct {
      uint16 : 3;                   /*!< [0..2] Reserved */
      volatile uint16 DSOV_LS1 : 1; /*!< [3..3] Drain-source overvoltage
                                       monitoring of LS1 */
      volatile uint16 DSOV_LS2 : 1; /*!< [4..4] Drain-source overvoltage
                                       monitoring of LS2 */
      volatile uint16 DSOV_LS3 : 1; /*!< [5..5] Drain-source overvoltage
                                       monitoring of LS3 */
      volatile uint16 DSOV_HS1 : 1; /*!< [6..6] Drain-source overvoltage
                                       monitoring of HS1 */
      volatile uint16 DSOV_HS2 : 1; /*!< [7..7] Drain-source overvoltage
                                       monitoring of HS2 */
      volatile uint16 DSOV_HS3 : 1; /*!< [8..8] Drain-source overvoltage
                                       monitoring of HS3 */
      volatile uint16 IL1_MISS : 1; /*!< [9..9] PWM alternation check -
                                       detection of stuck IL1 PWM input pin */
      volatile uint16 IL2_MISS : 1; /*!< [10..10] PWM alternation check -
                                       detection of stuck IL2 PWM input pin */
      volatile uint16 IL3_MISS : 1; /*!< [11..11] PWM alternation check -
                                       detection of stuck IL3 PWM input pin */
      volatile uint16 IH1_MISS : 1; /*!< [12..12] PWM alternation check -
                                     * detection of stuck IH1_N PWM input pin
                                     * */
      volatile uint16 IH2_MISS : 1; /*!< [13..13] PWM alternation check -
                                     * detection of stuck IH2_N PWM input pin
                                     * */
      volatile uint16 IH3_MISS : 1; /*!< [14..14] PWM alternation check -
                                     * detection of stuck IH3_N PWM input pin
                                     * */
      uint16 : 1;                   /*!< [15..15] Reserved */
    } bit;
  } BD_STAT;
  union {
    volatile uint16 reg; /*!< Register WD_CLK_CNT */
    struct {
      volatile uint16
          WD_CLK_CNT : 16; /*!< [0..15] Internal clock counter between two
                            * consecutive correct watchdog services. LSB of
                            * nominal 2.4us */
    } bit;
  } WD_CLK_CNT;
  union {
    volatile uint16 reg; /*!< Register PHASE1_CNT */
    struct {
      volatile uint16 PFB1_H_CNT : 13; /*!< [0..12] Phase 1 (SH1) high time
                                          counter, LSB of nominal 250ns */
      volatile uint16 CNT1_RDY : 1; /*!< [13..13] PFB1_H counter ready for read
                                       indication */
      volatile uint16
          PFB1_CNT_UPD : 1;     /*!< [14..14] PFB1 counter update indication */
      volatile uint16 PFB1 : 1; /*!< [15..15] Phase feedback comparator level of
                                   SH1 phase */
    } bit;
  } PHASE1_CNT;
  union {
    volatile uint16 reg; /*!< Register PHASE2_CNT */
    struct {
      volatile uint16 PFB2_H_CNT : 13; /*!< [0..12] Phase 2 (SH2) high time
                                          counter, LSB of nominal 250ns */
      volatile uint16 CNT2_RDY : 1; /*!< [13..13] PFB2_H counter ready for read
                                       indication */
      volatile uint16
          PFB2_CNT_UPD : 1;     /*!< [14..14] PFB2 counter update indication */
      volatile uint16 PFB2 : 1; /*!< [15..15] Phase feedback comparator level of
                                   SH2 phase */
    } bit;
  } PHASE2_CNT;
  union {
    volatile uint16 reg; /*!< Register PHASE3_CNT */
    struct {
      volatile uint16
          PFB3_H_CNT : 13; /*!< [0..12] Phase 3 (SH3) high time counter */
      volatile uint16 CNT3_RDY : 1; /*!< [13..13] PFB3_H counter ready for read
                                       indication */
      volatile uint16
          PFB3_CNT_UPD : 1;     /*!< [14..14] PFB3 counter update indication */
      volatile uint16 PFB3 : 1; /*!< [15..15] Phase feedback comparator level of
                                   SH3 phase */
    } bit;
  } PHASE3_CNT;
  union {
    volatile uint16 reg; /*!< Register TDON_TDOFF_HS1 */
    struct {
      volatile uint16 TDOFF_HS1 : 7; /*!< [0..6] Effective turn-off delay time
                                        of HS1 MOSFET */
      volatile uint16 TDON_HS1 : 8; /*!< [7..14] Effective turn-on delay time of
                                       HS1 MOSFET */
      volatile uint16 LS1_ACT : 1;  /*!< [14..14] LS1 detection as active MOSFET
                                       when turned ON */
      volatile uint16 HS1_ACT : 1;  /*!< [15..15] HS1 detection as active MOSFET
                                       when turned ON */
    } bit;
  } TDON_TDOFF_HS1;
  union {
    volatile uint16 reg; /*!< Register TDON_TDOFF_LS1 */
    struct {
      volatile uint16 TDOFF_LS1 : 7; /*!< [0..6] Effective turn-off delay time
                                        of LS1 MOSFET */
      volatile uint16 TDON_LS1 : 7; /*!< [7..13] Effective turn-on delay time of
                                       LS1 MOSFET */
      volatile uint16 LS1_ACT : 1;  /*!< [14..14] LS1 detection as active MOSFET
                                       when turned ON */
      volatile uint16 HS1_ACT : 1;  /*!< [15..15] HS1 detection as active MOSFET
                                       when turned ON */
    } bit;
  } TDON_TDOFF_LS1;
  union {
    volatile uint16 reg; /*!< Register TDON_TDOFF_HS2 */
    struct {
      volatile uint16 TDOFF_HS2 : 7; /*!< [0..6] Effective turn-off delay time
                                        of HS2 MOSFET */
      volatile uint16 TDON_HS2 : 7; /*!< [7..13] Effective turn-on delay time of
                                       HS2 MOSFET */
      volatile uint16 LS2_ACT : 1;  /*!< [14..14] LS2 detection as active MOSFET
                                       when turned ON */
      volatile uint16 HS2_ACT : 1;  /*!< [15..15] HS2 detection as active MOSFET
                                       when turned ON */
    } bit;
  } TDON_TDOFF_HS2;
  union {
    volatile uint16 reg; /*!< Register TDON_TDOFF_LS2 */
    struct {
      volatile uint16 TDOFF_LS2 : 7; /*!< [0..6] Effective turn-off delay time
                                        of LS2 MOSFET */
      volatile uint16 TDON_LS2 : 7; /*!< [7..13] Effective turn-on delay time of
                                       LS2 MOSFET */
      volatile uint16 LS2_ACT : 1;  /*!< [14..14] LS2 detection as active MOSFET
                                       when turned ON */
      volatile uint16 HS2_ACT : 1;  /*!< [15..15] HS2 detection as active MOSFET
                                       when turned ON */
    } bit;
  } TDON_TDOFF_LS2;
  union {
    volatile uint16 reg; /*!< Register TDON_TDOFF_HS3 */
    struct {
      volatile uint16 TDOFF_HS3 : 7; /*!< [0..6] Effective turn-off delay time
                                        of HS3 MOSFET */
      volatile uint16 TDON_HS3 : 7; /*!< [7..13] Effective turn-on delay time of
                                       HS3 MOSFET */
      volatile uint16 LS3_ACT : 1;  /*!< [14..14] LS3 detection as active MOSFET
                                       when turned ON */
      volatile uint16 HS3_ACT : 1;  /*!< [15..15] HS3 detection as active MOSFET
                                       when turned ON */
    } bit;
  } TDON_TDOFF_HS3;
  union {
    volatile uint16 reg; /*!< Register TDON_TDOFF_LS3 */
    struct {
      volatile uint16 TDOFF_LS3 : 7; /*!< [0..6] Effective turn-off delay time
                                        of LS3 MOSFET */
      volatile uint16 TDON_LS3 : 7; /*!< [7..13] Effective turn-on delay time of
                                       LS3 MOSFET */
      volatile uint16 LS3_ACT : 1;  /*!< [14..14] LS3 detection as active MOSFET
                                       when turned ON */
      volatile uint16 HS3_ACT : 1;  /*!< [15..15] HS3 detection as active MOSFET
                                       when turned ON */
    } bit;
  } TDON_TDOFF_LS3;
  union {
    volatile uint16 reg; /*!< Register TSLEW_ON_OFF_HS1 */
    struct {
      volatile uint16 TSLEW_OFF_HS1 : 7; /*!< [0..6] Effective turn-off slew
                                            rate time of HS1 MOSFET */
      volatile uint16 TSLEW_ON_HS1 : 7; /*!< [7..13] Effective turn-on slew rate
                                           time of HS1 MOSFET */
      volatile uint16 LS1_ACT : 1; /*!< [14..14] LS1 detection as active MOSFET
                                      when turned ON */
      volatile uint16 HS1_ACT : 1; /*!< [15..15] HS1 detection as active MOSFET
                                      when turned ON */
    } bit;
  } TSLEW_ON_OFF_HS1;
  union {
    volatile uint16 reg; /*!< Register TSLEW_ON_OFF_LS1 */
    struct {
      volatile uint16 TSLEW_OFF_LS1 : 7; /*!< [0..6] Effective turn-off slew
                                            rate time of LS1 MOSFET */
      volatile uint16 TSLEW_ON_LS1 : 7; /*!< [7..13] Effective turn-on slew rate
                                           time of LS1 MOSFET */
      volatile uint16 LS1_ACT : 1; /*!< [14..14] LS1 detection as active MOSFET
                                      when turned ON */
      volatile uint16 HS1_ACT : 1; /*!< [15..15] HS1 detection as active MOSFET
                                      when turned ON */
    } bit;
  } TSLEW_ON_OFF_LS1;
  union {
    volatile uint16 reg; /*!< Register TSLEW_ON_OFF_HS2 */
    struct {
      volatile uint16 TSLEW_OFF_HS2 : 7; /*!< [0..6] Effective turn-off slew
                                            rate time of HS2 MOSFET */
      volatile uint16 TSLEW_ON_HS2 : 7; /*!< [7..13] Effective turn-on slew rate
                                           time of HS2 MOSFET */
      volatile uint16 LS2_ACT : 1; /*!< [14..14] LS2 detection as active MOSFET
                                      when turned ON */
      volatile uint16 HS2_ACT : 1; /*!< [15..15] HS2 detection as active MOSFET
                                      when turned ON */
    } bit;
  } TSLEW_ON_OFF_HS2;
  union {
    volatile uint16 reg; /*!< Register TSLEW_ON_OFF_LS2 */
    struct {
      volatile uint16 TSLEW_OFF_LS2 : 7; /*!< [0..6] Effective turn-off slew
                                            rate time of LS2 MOSFET */
      volatile uint16 TSLEW_ON_LS2 : 7; /*!< [7..13] Effective turn-on slew rate
                                           time of LS2 MOSFET */
      volatile uint16 LS2_ACT : 1; /*!< [14..14] LS2 detection as active MOSFET
                                      when turned ON */
      volatile uint16 HS2_ACT : 1; /*!< [15..15] HS2 detection as active MOSFET
                                      when turned ON */
    } bit;
  } TSLEW_ON_OFF_LS2;
  union {
    volatile uint16 reg; /*!< Register TSLEW_ON_OFF_HS3 */
    struct {
      volatile uint16 TSLEW_OFF_HS3 : 7; /*!< [0..6] Effective turn-off slew
                                            rate time of HS3 MOSFET */
      volatile uint16 TSLEW_ON_HS3 : 7; /*!< [7..13] Effective turn-on slew rate
                                           time of HS3 MOSFET */
      volatile uint16 LS3_ACT : 1; /*!< [14..14] LS3 detection as active MOSFET
                                      when turned ON */
      volatile uint16 HS3_ACT : 1; /*!< [15..15] HS3 detection as active MOSFET
                                      when turned ON */
    } bit;
  } TSLEW_ON_OFF_HS3;
  union {
    volatile uint16 reg; /*!< Register TSLEW_ON_OFF_LS3 */
    struct {
      volatile uint16 TSLEW_OFF_LS3 : 7; /*!< [0..6] Effective turn-off slew
                                            rate time of LS3 MOSFET */
      volatile uint16 TSLEW_ON_LS3 : 7; /*!< [7..13] Effective turn-on slew rate
                                           time of LS3 MOSFET */
      volatile uint16 LS3_ACT : 1; /*!< [14..14] LS3 detection as active MOSFET
                                      when turned ON */
      volatile uint16 HS3_ACT : 1; /*!< [15..15] HS3 detection as active MOSFET
                                      when turned ON */
    } bit;
  } TSLEW_ON_OFF_LS3;
  union {
    volatile uint16 reg; /*!< Register DEVICE_VERSION */
    struct {
      uint16 : 4;               /*!< [0..3] Reserved */
      volatile uint16 PROD : 6; /*!< [4..9] Product Identifier */
      volatile uint16 FAM : 4;  /*!< [10..13] Family Identifier */
      uint16 : 2;               /*!< [14..15] Reserved */
    } bit;
  } DEVICE_VERSION;
  union {
    volatile uint8 reg; /*!< Global status byte */
    struct {
      volatile uint8 POR : 1; /*!< [0..0] Power on reset indication */
      volatile uint8
          DW : 1; /*!< [1..1] device warning indication using SPI register
                   * failure detection bits configured as warning */
      volatile uint8
          DE : 1; /*!< [2..2] device error indication using SPI register failure
                   * detection bits configured as error, auto restart (ARE),
                   * braking (BR) or latched error (LE1/LE2) */
      volatile uint8
          BDRE : 1; /*!< [3..3] Bridge driver signal path related status flag */
      volatile uint8 MISC : 1;  /*!< [4..4] SPI and GPIO related status flag */
      volatile uint8 VSUPE : 1; /*!< [5..5] Supply overview status flag */
      volatile uint8 LFOK : 1;  /*!< [6..6] Last received SDI frame correct */
      volatile uint8 OFC : 1;   /*!< [7..7] At least one SPI frame corrupted */
    } bit;
  } GSB;
} TLE9186_Type;
extern TLE9186_Type *TLE9186;

/**
 * @}
 */
/**
 * @}
 */

#endif /* TLE9186_H */
