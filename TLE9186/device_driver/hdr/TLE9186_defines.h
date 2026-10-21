/**
 *	@file TLE9186_defines.h
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
 * @defgroup defines Register Information
 * @brief The addresses, masks and bit-positions are necessary to access each an
 * every bit of the TLE9186 device.
 *
 * @defgroup addresses Register Addresses
 * @brief The addresses for all externally accessible registers are listed.
 *
 * @defgroup masks Register Bitmasks and Bit-positions
 * @brief In order to access the single bits of the registers the corresponding
 * masks and positions are listed.
 *
 */

#ifndef TLE9186_DEFINES_H
#define TLE9186_DEFINES_H

/**
 * @addtogroup device_driver
 * @{
 */
/**
 * @addtogroup defines
 * @{
 */
/**
 * @addtogroup addresses
 * @{
 */

/***************************************************************/
/*     Definitions for accessing the TLE9186 registers         */
/***************************************************************/
#define TLE9186_CONFIG_SECURED_ADDR                                            \
  (0x1u) /**< Power-up configuration protected register */
#define TLE9186_PWR_MOD_CFG_ADDR (0x2u) /**< Mode control register */
#define TLE9186_WD_CFG_ADDR (0x3u)      /**< Watchdog configuration register */
#define TLE9186_GEN_CFG1_ADDR (0x4u)    /**< General configuration register 1 */
#define TLE9186_GEN_CFG2_ADDR (0x5u)    /**< General configuration register 2 */
#define TLE9186_GEN_CFG3_ADDR (0x6u)    /**< General configuration register 3 */
#define TLE9186_GDRV_CFG1_ADDR                                                 \
  (0x7u) /**< Gate driver configuration register 1 */
#define TLE9186_GDRV_CFG2_ADDR                                                 \
  (0x8u) /**< Gate driver configuration register 2 */
#define TLE9186_GDRV_CFG3_ADDR                                                 \
  (0x9u) /**< Gate driver configuration register 3 */
#define TLE9186_TON_HS_ADDR                                                    \
  (0xau) /**< Gate Driver Configuration register - TON_HS  */
#define TLE9186_TON_LS_ADDR                                                    \
  (0xbu) /**< Gate Driver Configuration register - TON_LS  */
#define TLE9186_TOFF_HS_ADDR                                                   \
  (0xcu) /**< Gate Driver Configuration register - TOFF_HS  */
#define TLE9186_TOFF_LS_ADDR                                                   \
  (0xdu) /**< Gate Driver Configuration register - TOFF_LS  */
#define TLE9186_T3OFF_ADDR                                                     \
  (0xeu) /**< Gate Driver Configuration register - T3OFF */
#define TLE9186_ION_HS1_ADDR                                                   \
  (0xfu) /**< Gate driver Configuration register - ION_HS1 */
#define TLE9186_ION_LS1_ADDR                                                   \
  (0x10u) /**< Gate driver Configuration register - ION_LS1 */
#define TLE9186_ION_HS2_ADDR                                                   \
  (0x11u) /**< Gate driver Configuration register - ION_HS2 */
#define TLE9186_ION_LS2_ADDR                                                   \
  (0x12u) /**< Gate driver Configuration register - ION_LS2 */
#define TLE9186_ION_HS3_ADDR                                                   \
  (0x13u) /**< Gate driver Configuration register - ION_HS3 */
#define TLE9186_ION_LS3_ADDR                                                   \
  (0x14u) /**< Gate driver Configuration register - ION_LS3 */
#define TLE9186_I3ON_ADDR                                                      \
  (0x15u) /**< Gate driver Configuration register - I3ON */
#define TLE9186_ION_IOFF_DIDT_ADDR                                             \
  (0x16u) /**< Gate driver Configuration register - ION_IOFF_DIDT */
#define TLE9186_IOFF_HS1_ADDR                                                  \
  (0x17u) /**< Gate driver Configuration register - IOFF_HS1 */
#define TLE9186_IOFF_LS1_ADDR                                                  \
  (0x18u) /**< Gate driver Configuration register - IOFF_LS1 */
#define TLE9186_IOFF_HS2_ADDR                                                  \
  (0x19u) /**< Gate driver Configuration register - IOFF_HS2 */
#define TLE9186_IOFF_LS2_ADDR                                                  \
  (0x1au) /**< Gate driver Configuration register - IOFF_LS2 */
#define TLE9186_IOFF_HS3_ADDR                                                  \
  (0x1bu) /**< Gate driver Configuration register - IOFF_HS3 */
#define TLE9186_IOFF_LS3_ADDR                                                  \
  (0x1cu) /**< Gate driver Configuration register - IOFF_LS3 */
#define TLE9186_CSA_CFG_ADDR                                                   \
  (0x1du) /**< Current sense amplifier configuration register */
#define TLE9186_FAILURE_CFG_ADDR                                               \
  (0x1eu) /**< Failure reaction configuration register 1 */
#define TLE9186_SELF_TEST_CFG_ADDR                                             \
  (0x1fu) /**< Self-test configuration register  */
#define TLE9186_SUP_STAT_ADDR                                                  \
  (0x25u) /**< Supply monitoring status register                               \
           */
#define TLE9186_SPI_STAT_ADDR                                                  \
  (0x26u) /**< SPI status register (SPI and WD monitoring) */
#define TLE9186_DEV_STAT1_ADDR                                                 \
  (0x27u) /**< Device status register 1: Operation mode and digital            \
           * input pins                                                        \
           * levels */
#define TLE9186_DEV_STAT2_ADDR                                                 \
  (0x28u) /**< Device status register 2: Input pattern violation,              \
           * ERR_N, CSA, TSD                                                   \
           * monitoring */
#define TLE9186_LF_STAT_ADDR                                                   \
  (0x29u) /**< Latent faults and self-tests status register: internal          \
           * faults,                                                           \
           * self-tests results */
#define TLE9186_SH_LEVEL_STAT_ADDR (0x2au) /**< Phase pins monitoring */
#define TLE9186_BD_STAT_ADDR (0x2bu) /**< HS & LS Gate Drivers monitoring   */
#define TLE9186_WD_CLK_CNT_ADDR (0x2cu) /**< Watchdog clock counter */
#define TLE9186_PHASE1_CNT_ADDR (0x2du) /**< Phase 1 high time counter */
#define TLE9186_PHASE2_CNT_ADDR (0x2eu) /**< Phase 2 high time counter */
#define TLE9186_PHASE3_CNT_ADDR (0x2fu) /**< Phase 3 high time counter */
#define TLE9186_TDON_TDOFF_HS1_ADDR                                            \
  (0x30u) /**< Effective MOSFET turn-on/off delay time HS1 */
#define TLE9186_TDON_TDOFF_LS1_ADDR                                            \
  (0x31u) /**< Effective MOSFET turn-on/off delay time LS1 */
#define TLE9186_TDON_TDOFF_HS2_ADDR                                            \
  (0x32u) /**< Effective MOSFET turn-on/off delay time HS2 */
#define TLE9186_TDON_TDOFF_LS2_ADDR                                            \
  (0x33u) /**< Effective MOSFET turn-on/off delay time LS2 */
#define TLE9186_TDON_TDOFF_HS3_ADDR                                            \
  (0x34u) /**< Effective MOSFET turn-on/off delay time HS3 */
#define TLE9186_TDON_TDOFF_LS3_ADDR                                            \
  (0x35u) /**< Effective MOSFET turn-on/off delay time LS3 */
#define TLE9186_TSLEW_ON_OFF_HS1_ADDR                                          \
  (0x36u) /**< Effective MOSFET slew rate time HS1 */
#define TLE9186_TSLEW_ON_OFF_LS1_ADDR                                          \
  (0x37u) /**< Effective MOSFET slew rate time LS1 */
#define TLE9186_TSLEW_ON_OFF_HS2_ADDR                                          \
  (0x38u) /**< Effective MOSFET slew rate time HS2 */
#define TLE9186_TSLEW_ON_OFF_LS2_ADDR                                          \
  (0x39u) /**< Effective MOSFET slew rate time LS2 */
#define TLE9186_TSLEW_ON_OFF_HS3_ADDR                                          \
  (0x3au) /**< Effective MOSFET slew rate time HS3 */
#define TLE9186_TSLEW_ON_OFF_LS3_ADDR                                          \
  (0x3bu) /**< Effective MOSFET slew rate time LS3 */
#define TLE9186_DEVICE_VERSION_ADDR (0x40u) /**< Device version information */

/**
 * @}
 */
/**
 * @addtogroup masks
 * @{
 */

/** TLE9186_CONFIG_SECURED positions */
#define TLE9186_CONFIG_SECURED_FW_CFG_POS                                      \
  (0x0u) /*!< Freewheeling device charge/discharge phase                       \
          * configuration */
#define TLE9186_CONFIG_SECURED_OFF_CFG_POS                                     \
  (0x1u) /*!< Switch OFF behavior in case of detected faults leading           \
          * to gate driver OFF */
#define TLE9186_CONFIG_SECURED_GDRV_CFG_POS                                    \
  (0x2u) /*!< Gate Driver Operation Mode Configuration */
#define TLE9186_CONFIG_SECURED_GDRV_RNG_POS                                    \
  (0x3u) /*!< Gate Driver Output Current Range Configuration */
#define TLE9186_CONFIG_SECURED_VIO_CFG_POS                                     \
  (0x4u) /*!< VIO voltage level configuration bits */
#define TLE9186_CONFIG_SECURED_SPI_TYPE_POS                                    \
  (0x6u) /*!< SPI SDO response type configuration bits */
#define TLE9186_CONFIG_SECURED_INHN_L_CFG_POS                                  \
  (0x8u) /*!< INHN low detection wait time configuration */
#define TLE9186_CONFIG_SECURED_PWM_MAP_POS                                     \
  (0x9u) /*!< PWM mapping to gate drivers configuration */
#define TLE9186_CONFIG_SECURED_WD_EN_POS (0xau) /*!< Watchdog enable */
#define TLE9186_CONFIG_SECURED_CP_CFG_POS                                      \
  (0xbu) /*!< Charge pump Configuration  */
#define TLE9186_CONFIG_SECURED_CP_CLK_SEL_POS                                  \
  (0xcu) /*!< Charge Pump Clock selection */
/** TLE9186_CONFIG_SECURED masks */
#define TLE9186_CONFIG_SECURED_FW_CFG_MSK                                      \
  (0x1u) /*!< Freewheeling device charge/discharge phase                       \
          * configuration */
#define TLE9186_CONFIG_SECURED_OFF_CFG_MSK                                     \
  (0x2u) /*!< Switch OFF behavior in case of detected faults leading           \
          * to gate driver OFF */
#define TLE9186_CONFIG_SECURED_GDRV_CFG_MSK                                    \
  (0x4u) /*!< Gate Driver Operation Mode Configuration */
#define TLE9186_CONFIG_SECURED_GDRV_RNG_MSK                                    \
  (0x8u) /*!< Gate Driver Output Current Range Configuration */
#define TLE9186_CONFIG_SECURED_VIO_CFG_MSK                                     \
  (0x30u) /*!< VIO voltage level configuration bits */
#define TLE9186_CONFIG_SECURED_SPI_TYPE_MSK                                    \
  (0xc0u) /*!< SPI SDO response type configuration bits */
#define TLE9186_CONFIG_SECURED_INHN_L_CFG_MSK                                  \
  (0x100u) /*!< INHN low detection wait time configuration */
#define TLE9186_CONFIG_SECURED_PWM_MAP_MSK                                     \
  (0x200u) /*!< PWM mapping to gate drivers configuration */
#define TLE9186_CONFIG_SECURED_WD_EN_MSK (0x400u) /*!< Watchdog enable */
#define TLE9186_CONFIG_SECURED_CP_CFG_MSK                                      \
  (0x800u) /*!< Charge pump Configuration  */
#define TLE9186_CONFIG_SECURED_CP_CLK_SEL_MSK                                  \
  (0x3000u) /*!< Charge Pump Clock selection */
/** TLE9186_PWR_MOD_CFG positions */
#define TLE9186_PWR_MOD_CFG_MODE_CTRL_POS                                      \
  (0x0u) /*!< Device operation mode configuration */
#define TLE9186_PWR_MOD_CFG_CLR_STATS_POS                                      \
  (0xeu) /*!< Clear SPI device status registers */
#define TLE9186_PWR_MOD_CFG_CLR_CONFIG_POS                                     \
  (0xfu) /*!< Clear SPI device configuration registers */
/** TLE9186_PWR_MOD_CFG masks */
#define TLE9186_PWR_MOD_CFG_MODE_CTRL_MSK                                      \
  (0x3u) /*!< Device operation mode configuration */
#define TLE9186_PWR_MOD_CFG_CLR_STATS_MSK                                      \
  (0x4000u) /*!< Clear SPI device status registers */
#define TLE9186_PWR_MOD_CFG_CLR_CONFIG_MSK                                     \
  (0x8000u) /*!< Clear SPI device configuration registers */
/** TLE9186_WD_CFG positions */
#define TLE9186_WD_CFG_WD_PER_POS (0x0u) /*!< Watchdog period configuration */
#define TLE9186_WD_CFG_WD_FAIL_POS                                             \
  (0x3u) /*!< Watchdog fails counter configuration */
#define TLE9186_WD_CFG_CHECKSUM_POS                                            \
  (0xfu) /*!< Watchdog configuration checksum bit */
/** TLE9186_WD_CFG masks */
#define TLE9186_WD_CFG_WD_PER_MSK (0x7u) /*!< Watchdog period configuration */
#define TLE9186_WD_CFG_WD_FAIL_MSK                                             \
  (0x38u) /*!< Watchdog fails counter configuration */
#define TLE9186_WD_CFG_CHECKSUM_MSK                                            \
  (0x8000u) /*!< Watchdog configuration checksum bit */
/** TLE9186_GEN_CFG1 positions */
#define TLE9186_GEN_CFG1_SOFF_ON_POS                                           \
  (0x0u) /*!< Safe State activation via SPI command */
#define TLE9186_GEN_CFG1_ERRN_ON_POS                                           \
  (0x1u) /*!< ERRN function activation via SPI command */
#define TLE9186_GEN_CFG1_TW_EN_POS                                             \
  (0x2u) /*!< ERRN function activation via SPI command */
#define TLE9186_GEN_CFG1_CSA_EN_POS                                            \
  (0x3u) /*!< Current sense amplifier enable */
#define TLE9186_GEN_CFG1_HBFREQ_POS                                            \
  (0x4u) /*!< Half-bridge synchronization frequency */
#define TLE9186_GEN_CFG1_HB1_EN_POS (0x5u) /*!< Half-bridge 1 enable */
#define TLE9186_GEN_CFG1_HB2_EN_POS (0x6u) /*!< Half-bridge 2 enable */
#define TLE9186_GEN_CFG1_HB3_EN_POS (0x7u) /*!< Half-bridge 3 enable */
#define TLE9186_GEN_CFG1_PFB_EN_POS                                            \
  (0x8u) /*!< Phase feedback monitoring enable */
#define TLE9186_GEN_CFG1_CP_REC_OV_POS                                         \
  (0x9u) /*!< Charge pump recovery in case of VSCP_OV_SD event */
#define TLE9186_GEN_CFG1_CP_REC_UV_POS                                         \
  (0xau) /*!< Charge pump recovery in case of VSCP_UV_SD event */
#define TLE9186_GEN_CFG1_CP_FMOD_POS                                           \
  (0xbu) /*!< Charge pump frequency modulation configuration */
#define TLE9186_GEN_CFG1_CP_MODE_POS                                           \
  (0xdu) /*!< Charge Pump Operation Mode configuration bits */
#define TLE9186_GEN_CFG1_CP_EN_POS (0xfu) /*!< Charge pump function enable */
/** TLE9186_GEN_CFG1 masks */
#define TLE9186_GEN_CFG1_SOFF_ON_MSK                                           \
  (0x1u) /*!< Safe State activation via SPI command */
#define TLE9186_GEN_CFG1_ERRN_ON_MSK                                           \
  (0x2u) /*!< ERRN function activation via SPI command */
#define TLE9186_GEN_CFG1_TW_EN_MSK                                             \
  (0x4u) /*!< ERRN function activation via SPI command */
#define TLE9186_GEN_CFG1_CSA_EN_MSK                                            \
  (0x8u) /*!< Current sense amplifier enable */
#define TLE9186_GEN_CFG1_HBFREQ_MSK                                            \
  (0x10u) /*!< Half-bridge synchronization frequency */
#define TLE9186_GEN_CFG1_HB1_EN_MSK (0x20u) /*!< Half-bridge 1 enable */
#define TLE9186_GEN_CFG1_HB2_EN_MSK (0x40u) /*!< Half-bridge 2 enable */
#define TLE9186_GEN_CFG1_HB3_EN_MSK (0x80u) /*!< Half-bridge 3 enable */
#define TLE9186_GEN_CFG1_PFB_EN_MSK                                            \
  (0x100u) /*!< Phase feedback monitoring enable */
#define TLE9186_GEN_CFG1_CP_REC_OV_MSK                                         \
  (0x200u) /*!< Charge pump recovery in case of VSCP_OV_SD event */
#define TLE9186_GEN_CFG1_CP_REC_UV_MSK                                         \
  (0x400u) /*!< Charge pump recovery in case of VSCP_UV_SD event */
#define TLE9186_GEN_CFG1_CP_FMOD_MSK                                           \
  (0x1800u) /*!< Charge pump frequency modulation configuration */
#define TLE9186_GEN_CFG1_CP_MODE_MSK                                           \
  (0x6000u) /*!< Charge Pump Operation Mode configuration bits */
#define TLE9186_GEN_CFG1_CP_EN_MSK                                             \
  (0x8000u) /*!< Charge pump function enable                                   \
             */
/** TLE9186_GEN_CFG2 positions */
#define TLE9186_GEN_CFG2_OFF_DIAG_EN_POS                                       \
  (0x0u) /*!< OFF-state diagnostic function enable */
#define TLE9186_GEN_CFG2_HB1IDIAG_POS                                          \
  (0x1u) /*!< OFF-state diagnostic control of HB1 pull-down current            \
          * */
#define TLE9186_GEN_CFG2_HB2IDIAG_POS                                          \
  (0x2u) /*!< OFF-state diagnostic control of HB2 pull-down current            \
          * */
#define TLE9186_GEN_CFG2_HB3IDIAG_POS                                          \
  (0x3u) /*!< OFF-state diagnostic control of HB3 pull-down current            \
          * */
#define TLE9186_GEN_CFG2_IPV_CCP_DIS_POS                                       \
  (0x4u) /*!< Disable input pattern violation for cross-current                \
          * protection */
#define TLE9186_GEN_CFG2_CSN_TO_DIS_POS                                        \
  (0x5u) /*!< CSN time-out disable option */
#define TLE9186_GEN_CFG2_CP_UV_TH_POS                                          \
  (0x6u) /*!< Charge Pump under-voltage threshold selection */
#define TLE9186_GEN_CFG2_TW_TH_POS                                             \
  (0xau) /*!< Temperature warning threshold selection */
#define TLE9186_GEN_CFG2_TPFB_POS                                              \
  (0xfu) /*!< PFB monitoring filter time configuration */
/** TLE9186_GEN_CFG2 masks */
#define TLE9186_GEN_CFG2_OFF_DIAG_EN_MSK                                       \
  (0x1u) /*!< OFF-state diagnostic function enable */
#define TLE9186_GEN_CFG2_HB1IDIAG_MSK                                          \
  (0x2u) /*!< OFF-state diagnostic control of HB1 pull-down current            \
          * */
#define TLE9186_GEN_CFG2_HB2IDIAG_MSK                                          \
  (0x4u) /*!< OFF-state diagnostic control of HB2 pull-down current            \
          * */
#define TLE9186_GEN_CFG2_HB3IDIAG_MSK                                          \
  (0x8u) /*!< OFF-state diagnostic control of HB3 pull-down current            \
          * */
#define TLE9186_GEN_CFG2_IPV_CCP_DIS_MSK                                       \
  (0x10u) /*!< Disable input pattern violation for cross-current               \
           * protection */
#define TLE9186_GEN_CFG2_CSN_TO_DIS_MSK                                        \
  (0x20u) /*!< CSN time-out disable option */
#define TLE9186_GEN_CFG2_CP_UV_TH_MSK                                          \
  (0x40u) /*!< Charge Pump under-voltage threshold selection */
#define TLE9186_GEN_CFG2_TW_TH_MSK                                             \
  (0xc00u) /*!< Temperature warning threshold selection */
#define TLE9186_GEN_CFG2_TPFB_MSK                                              \
  (0x8000u) /*!< PFB monitoring filter time configuration */
/** TLE9186_GEN_CFG3 positions */
#define TLE9186_GEN_CFG3_Spares_POS (0x0u) /*!< Spares registered bits */
/** TLE9186_GEN_CFG3 masks */
#define TLE9186_GEN_CFG3_Spares_MSK (0x1fu) /*!< Spares registered bits */
/** TLE9186_GDRV_CFG1 positions */
#define TLE9186_GDRV_CFG1_TCCP_FW_POS                                          \
  (0x0u) /*!< Cross-current protection time configuration of the               \
          * freewheeling MOSFET */
#define TLE9186_GDRV_CFG1_TCCP_POS                                             \
  (0x4u) /*!< Cross-current protection time configuration of the               \
          * active MOSFET */
#define TLE9186_GDRV_CFG1_TVDSBLK_FW_POS                                       \
  (0x8u) /*!< Blanking time configuration of the freewheeling MOSFET           \
          * */
#define TLE9186_GDRV_CFG1_TVDSBLK_POS                                          \
  (0xcu) /*!< Blanking time configuration of the active MOSFET */
/** TLE9186_GDRV_CFG1 masks */
#define TLE9186_GDRV_CFG1_TCCP_FW_MSK                                          \
  (0xfu) /*!< Cross-current protection time configuration of the               \
          * freewheeling MOSFET */
#define TLE9186_GDRV_CFG1_TCCP_MSK                                             \
  (0xf0u) /*!< Cross-current protection time configuration of the              \
           * active MOSFET */
#define TLE9186_GDRV_CFG1_TVDSBLK_FW_MSK                                       \
  (0xf00u) /*!< Blanking time configuration of the freewheeling MOSFET         \
            * */
#define TLE9186_GDRV_CFG1_TVDSBLK_MSK                                          \
  (0xf000u) /*!< Blanking time configuration of the active MOSFET */
/** TLE9186_GDRV_CFG2 positions */
#define TLE9186_GDRV_CFG2_LS_DSOVTH_POS                                        \
  (0x0u) /*!< LS MOSFETs drain-source threshold configuration */
#define TLE9186_GDRV_CFG2_HS_DSOVTH_POS                                        \
  (0x3u) /*!< HS MOSFETs drain-source threshold configuration */
#define TLE9186_GDRV_CFG2_TVDSFILT_POS                                         \
  (0x6u) /*!< Drain-source monitoring comparators filter time */
#define TLE9186_GDRV_CFG2_TFW_POS                                              \
  (0x8u) /*!< Freewheeling device charge/discharge time  */
#define TLE9186_GDRV_CFG2_PWM_CHCK_EN_POS                                      \
  (0xeu) /*!< Enable PWM alternation monitoring function */
#define TLE9186_GDRV_CFG2_TCCP_CFG_POS                                         \
  (0xfu) /*!< Cross-Current protection times clock selection */
/** TLE9186_GDRV_CFG2 masks */
#define TLE9186_GDRV_CFG2_LS_DSOVTH_MSK                                        \
  (0x7u) /*!< LS MOSFETs drain-source threshold configuration */
#define TLE9186_GDRV_CFG2_HS_DSOVTH_MSK                                        \
  (0x38u) /*!< HS MOSFETs drain-source threshold configuration */
#define TLE9186_GDRV_CFG2_TVDSFILT_MSK                                         \
  (0xc0u) /*!< Drain-source monitoring comparators filter time */
#define TLE9186_GDRV_CFG2_TFW_MSK                                              \
  (0x3f00u) /*!< Freewheeling device charge/discharge time  */
#define TLE9186_GDRV_CFG2_PWM_CHCK_EN_MSK                                      \
  (0x4000u) /*!< Enable PWM alternation monitoring function */
#define TLE9186_GDRV_CFG2_TCCP_CFG_MSK                                         \
  (0x8000u) /*!< Cross-Current protection times clock selection */
/** TLE9186_GDRV_CFG3 positions */
#define TLE9186_GDRV_CFG3_IDCHG_ST_POS                                         \
  (0x0u) /*!< Gate Driver static discharge current                             \
          * configuration(last 3 LSBs of ICHG = 111) */
#define TLE9186_GDRV_CFG3_IFW_POS                                              \
  (0x3u) /*!< Freewheeling charge and discharge current setting(last           \
          * 3 LSBs of ICHG = 111) */
#define TLE9186_GDRV_CFG3_IHOLD_POS                                            \
  (0x6u) /*!< Bridge Driver Hold Current configuration */
#define TLE9186_GDRV_CFG3_ION_TR_POS                                           \
  (0x8u) /*!< Configuration of the transition to post-charge                   \
          * phase(current) */

/** TLE9186_GDRV_CFG3 masks */
#define TLE9186_GDRV_CFG3_IDCHG_ST_MSK                                         \
  (0x7u) /*!< Gate Driver static discharge current                             \
          * configuration(last 3 LSBs of ICHG = 111) */
#define TLE9186_GDRV_CFG3_IFW_MSK                                              \
  (0x38u) /*!< Freewheeling charge and discharge current setting(last          \
           * 3 LSBs of ICHG = 111) */
#define TLE9186_GDRV_CFG3_IHOLD_MSK                                            \
  (0xc0u) /*!< Bridge Driver Hold Current configuration */
#define TLE9186_GDRV_CFG3_ION_TR_MSK                                           \
  (0x300u) /*!< Configuration of the transition to post-charge                 \
            * phase(current) */

/** TLE9186_TON_HS positions */
#define TLE9186_TON_HS_T2ON_HS_POS                                             \
  (0x0u) /*!< High Side gate driver charge time configuration */
#define TLE9186_TON_HS_T1ON_HS_POS                                             \
  (0x8u) /*!< High Side gate driver pre-charge time configuration */
/** TLE9186_TON_HS masks */
#define TLE9186_TON_HS_T2ON_HS_MSK                                             \
  (0x3fu) /*!< High Side gate driver charge time configuration */
#define TLE9186_TON_HS_T1ON_HS_MSK                                             \
  (0x3f00u) /*!< High Side gate driver pre-charge time configuration */
/** TLE9186_TON_LS positions */
#define TLE9186_TON_LS_T2ON_LS_POS                                             \
  (0x0u) /*!< Low Side gate driver charge time configuration */
#define TLE9186_TON_LS_T1ON_LS_POS                                             \
  (0x8u) /*!< Low Side gate driver pre-charge time configuration */
/** TLE9186_TON_LS masks */
#define TLE9186_TON_LS_T2ON_LS_MSK                                             \
  (0x3fu) /*!< Low Side gate driver charge time configuration */
#define TLE9186_TON_LS_T1ON_LS_MSK                                             \
  (0x3f00u) /*!< Low Side gate driver pre-charge time configuration */
/** TLE9186_TOFF_HS positions */
#define TLE9186_TOFF_HS_T2OFF_HS_POS                                           \
  (0x0u) /*!< High Side gate driver discharge time configuration */
#define TLE9186_TOFF_HS_T1OFF_HS_POS                                           \
  (0x8u) /*!< High Side gate driver pre-discharge time configuration           \
          * */

/** TLE9186_TOFF_HS masks */
#define TLE9186_TOFF_HS_T2OFF_HS_MSK                                           \
  (0x3fu) /*!< High Side gate driver discharge time configuration */
#define TLE9186_TOFF_HS_T1OFF_HS_MSK                                           \
  (0x3f00u) /*!< High Side gate driver pre-discharge time configuration        \
             * */

/** TLE9186_TOFF_LS positions */
#define TLE9186_TOFF_LS_T2OFF_LS_POS                                           \
  (0x0u) /*!< Low Side gate driver discharge time configuration */
#define TLE9186_TOFF_LS_T1OFF_LS_POS                                           \
  (0x8u) /*!< Low Side gate driver pre-discharge time configuration            \
          * */

/** TLE9186_TOFF_LS masks */
#define TLE9186_TOFF_LS_T2OFF_LS_MSK                                           \
  (0x3fu) /*!< Low Side gate driver discharge time configuration */
#define TLE9186_TOFF_LS_T1OFF_LS_MSK                                           \
  (0x3f00u) /*!< Low Side gate driver pre-discharge time configuration         \
             * */

/** TLE9186_T3OFF positions */
#define TLE9186_T3OFF_T3OFF_LS_POS                                             \
  (0x0u) /*!< Low Side gate driver post-discharge time configuration           \
          * */
#define TLE9186_T3OFF_T3OFF_HS_POS                                             \
  (0x8u) /*!< High Side gate driver post-discharge time                        \
          * configuration */

/** TLE9186_T3OFF masks */
#define TLE9186_T3OFF_T3OFF_LS_MSK                                             \
  (0x3fu) /*!< Low Side gate driver post-discharge time configuration          \
           * */
#define TLE9186_T3OFF_T3OFF_HS_MSK                                             \
  (0x3f00u) /*!< High Side gate driver post-discharge time                     \
             * configuration */

/** TLE9186_ION_HS1 positions */
#define TLE9186_ION_HS1_I2ON_HS1_POS                                           \
  (0x0u) /*!< HS1 Gate Driver charge current setting */
#define TLE9186_ION_HS1_I1ON_HS1_POS                                           \
  (0x8u) /*!< HS1 Gate Driver pre-charge current setting */
#define TLE9186_ION_HS1_ION_HS_BNK_POS                                         \
  (0xeu) /*!< Banking configuration of I1ON, I2ON HS charge current            \
          * */

/** TLE9186_ION_HS1 masks */
#define TLE9186_ION_HS1_I2ON_HS1_MSK                                           \
  (0x3fu) /*!< HS1 Gate Driver charge current setting */
#define TLE9186_ION_HS1_I1ON_HS1_MSK                                           \
  (0x3f00u) /*!< HS1 Gate Driver pre-charge current setting */
#define TLE9186_ION_HS1_ION_HS_BNK_MSK                                         \
  (0xc000u) /*!< Banking configuration of I1ON, I2ON HS charge current         \
             * */

/** TLE9186_ION_LS1 positions */
#define TLE9186_ION_LS1_I2ON_LS1_POS                                           \
  (0x0u) /*!< LS1 Gate Driver charge current setting */
#define TLE9186_ION_LS1_I1ON_LS1_POS                                           \
  (0x8u) /*!< LS1 Gate Driver pre-charge current setting */
#define TLE9186_ION_LS1_ION_LS_BNK_POS                                         \
  (0xeu) /*!< Banking configuration of I1ON, I2ON LS charge current            \
          * */

/** TLE9186_ION_LS1 masks */
#define TLE9186_ION_LS1_I2ON_LS1_MSK                                           \
  (0x3fu) /*!< LS1 Gate Driver charge current setting */
#define TLE9186_ION_LS1_I1ON_LS1_MSK                                           \
  (0x3f00u) /*!< LS1 Gate Driver pre-charge current setting */
#define TLE9186_ION_LS1_ION_LS_BNK_MSK                                         \
  (0xc000u) /*!< Banking configuration of I1ON, I2ON LS charge current         \
             * */

/** TLE9186_ION_HS2 positions */
#define TLE9186_ION_HS2_I2ON_HS2_POS                                           \
  (0x0u) /*!< HS2 Gate Driver charge current setting */
#define TLE9186_ION_HS2_I1ON_HS2_POS                                           \
  (0x8u) /*!< HS2 Gate Driver pre-charge current setting */
/** TLE9186_ION_HS2 masks */
#define TLE9186_ION_HS2_I2ON_HS2_MSK                                           \
  (0x3fu) /*!< HS2 Gate Driver charge current setting */
#define TLE9186_ION_HS2_I1ON_HS2_MSK                                           \
  (0x3f00u) /*!< HS2 Gate Driver pre-charge current setting */
/** TLE9186_ION_LS2 positions */
#define TLE9186_ION_LS2_I2ON_LS2_POS                                           \
  (0x0u) /*!< LS2 Gate Driver charge current setting */
#define TLE9186_ION_LS2_I1ON_LS2_POS                                           \
  (0x8u) /*!< LS2 Gate Driver pre-charge current setting */
/** TLE9186_ION_LS2 masks */
#define TLE9186_ION_LS2_I2ON_LS2_MSK                                           \
  (0x3fu) /*!< LS2 Gate Driver charge current setting */
#define TLE9186_ION_LS2_I1ON_LS2_MSK                                           \
  (0x3f00u) /*!< LS2 Gate Driver pre-charge current setting */
/** TLE9186_ION_HS3 positions */
#define TLE9186_ION_HS3_I2ON_HS3_POS                                           \
  (0x0u) /*!< HS3 Gate Driver charge current setting */
#define TLE9186_ION_HS3_I1ON_HS3_POS                                           \
  (0x8u) /*!< HS3 Gate Driver pre-charge current setting */
/** TLE9186_ION_HS3 masks */
#define TLE9186_ION_HS3_I2ON_HS3_MSK                                           \
  (0x3fu) /*!< HS3 Gate Driver charge current setting */
#define TLE9186_ION_HS3_I1ON_HS3_MSK                                           \
  (0x3f00u) /*!< HS3 Gate Driver pre-charge current setting */
/** TLE9186_ION_LS3 positions */
#define TLE9186_ION_LS3_I2ON_LS3_POS                                           \
  (0x0u) /*!< LS3 Gate Driver charge current setting */
#define TLE9186_ION_LS3_I1ON_LS3_POS                                           \
  (0x8u) /*!< LS3 Gate Driver pre-charge current setting */
/** TLE9186_ION_LS3 masks */
#define TLE9186_ION_LS3_I2ON_LS3_MSK                                           \
  (0x3fu) /*!< LS3 Gate Driver charge current setting */
#define TLE9186_ION_LS3_I1ON_LS3_MSK                                           \
  (0x3f00u) /*!< LS3 Gate Driver pre-charge current setting */
/** TLE9186_I3ON positions */
#define TLE9186_I3ON_I3ON_LS_POS                                               \
  (0x0u) /*!< Low Side gate driver post-charge current setting */
#define TLE9186_I3ON_I3ON_HS_POS                                               \
  (0x8u) /*!< High Side gate driver post-charge current setting */
/** TLE9186_I3ON masks */
#define TLE9186_I3ON_I3ON_LS_MSK                                               \
  (0x3fu) /*!< Low Side gate driver post-charge current setting */
#define TLE9186_I3ON_I3ON_HS_MSK                                               \
  (0x3f00u) /*!< High Side gate driver post-charge current setting */
/** TLE9186_ION_IOFF_DIDT positions */
#define TLE9186_ION_IOFF_DIDT_IOFF_POS                                         \
  (0x0u) /*!< Gate driver discharge current during dI/dT phase */
#define TLE9186_ION_IOFF_DIDT_ION_POS                                          \
  (0x8u) /*!< Gate driver charge current during dI/dT phase */
/** TLE9186_ION_IOFF_DIDT masks */
#define TLE9186_ION_IOFF_DIDT_IOFF_MSK                                         \
  (0x3fu) /*!< Gate driver discharge current during dI/dT phase */
#define TLE9186_ION_IOFF_DIDT_ION_MSK                                          \
  (0x3f00u) /*!< Gate driver charge current during dI/dT phase */
/** TLE9186_IOFF_HS1 positions */
#define TLE9186_IOFF_HS1_I2OFF_HS1_POS                                         \
  (0x0u) /*!< HS1 Gate Driver discharge current setting */
#define TLE9186_IOFF_HS1_I1OFF_HS1_POS                                         \
  (0x8u) /*!< HS1 Gate Driver pre-discharge current setting */
#define TLE9186_IOFF_HS1_ION_HS_BNK_POS                                        \
  (0xeu) /*!< Banking configuration of I1ON, I2ON HS charge current            \
          * */

/** TLE9186_IOFF_HS1 masks */
#define TLE9186_IOFF_HS1_I2OFF_HS1_MSK                                         \
  (0x3fu) /*!< HS1 Gate Driver discharge current setting */
#define TLE9186_IOFF_HS1_I1OFF_HS1_MSK                                         \
  (0x3f00u) /*!< HS1 Gate Driver pre-discharge current setting */
#define TLE9186_IOFF_HS1_ION_HS_BNK_MSK                                        \
  (0xc000u) /*!< Banking configuration of I1ON, I2ON HS charge current         \
             * */

/** TLE9186_IOFF_LS1 positions */
#define TLE9186_IOFF_LS1_I2OFF_LS1_POS                                         \
  (0x0u) /*!< LS1 Gate Driver discharge current setting */
#define TLE9186_IOFF_LS1_I1OFF_LS1_POS                                         \
  (0x8u) /*!< LS1 Gate Driver pre-discharge current setting */
#define TLE9186_IOFF_LS1_IOFF_LS_BNK_POS                                       \
  (0xeu) /*!< Banking configuration of I1OFF, I2OFF LS discharge               \
          * current */

/** TLE9186_IOFF_LS1 masks */
#define TLE9186_IOFF_LS1_I2OFF_LS1_MSK                                         \
  (0x3fu) /*!< LS1 Gate Driver discharge current setting */
#define TLE9186_IOFF_LS1_I1OFF_LS1_MSK                                         \
  (0x3f00u) /*!< LS1 Gate Driver pre-discharge current setting */
#define TLE9186_IOFF_LS1_IOFF_LS_BNK_MSK                                       \
  (0xc000u) /*!< Banking configuration of I1OFF, I2OFF LS discharge            \
             * current */

/** TLE9186_IOFF_HS2 positions */
#define TLE9186_IOFF_HS2_I2OFF_HS2_POS                                         \
  (0x0u) /*!< HS2 Gate Driver discharge current setting */
#define TLE9186_IOFF_HS2_I1OFF_HS2_POS                                         \
  (0x8u) /*!< HS2 Gate Driver pre-discharge current setting */
/** TLE9186_IOFF_HS2 masks */
#define TLE9186_IOFF_HS2_I2OFF_HS2_MSK                                         \
  (0x3fu) /*!< HS2 Gate Driver discharge current setting */
#define TLE9186_IOFF_HS2_I1OFF_HS2_MSK                                         \
  (0x3f00u) /*!< HS2 Gate Driver pre-discharge current setting */
/** TLE9186_IOFF_LS2 positions */
#define TLE9186_IOFF_LS2_I2OFF_LS2_POS                                         \
  (0x0u) /*!< LS2 Gate Driver discharge current setting */
#define TLE9186_IOFF_LS2_I1OFF_LS2_POS                                         \
  (0x8u) /*!< LS2 Gate Driver pre-discharge current setting */
/** TLE9186_IOFF_LS2 masks */
#define TLE9186_IOFF_LS2_I2OFF_LS2_MSK                                         \
  (0x3fu) /*!< LS2 Gate Driver discharge current setting */
#define TLE9186_IOFF_LS2_I1OFF_LS2_MSK                                         \
  (0x3f00u) /*!< LS2 Gate Driver pre-discharge current setting */
/** TLE9186_IOFF_HS3 positions */
#define TLE9186_IOFF_HS3_I2OFF_HS3_POS                                         \
  (0x0u) /*!< HS3 Gate Driver discharge current setting */
#define TLE9186_IOFF_HS3_I1OFF_HS3_POS                                         \
  (0x8u) /*!< HS3 Gate Driver pre-discharge current setting */
/** TLE9186_IOFF_HS3 masks */
#define TLE9186_IOFF_HS3_I2OFF_HS3_MSK                                         \
  (0x3fu) /*!< HS3 Gate Driver discharge current setting */
#define TLE9186_IOFF_HS3_I1OFF_HS3_MSK                                         \
  (0x3f00u) /*!< HS3 Gate Driver pre-discharge current setting */
/** TLE9186_IOFF_LS3 positions */
#define TLE9186_IOFF_LS3_I2OFF_LS3_POS                                         \
  (0x0u) /*!< LS3 Gate Driver discharge current setting */
#define TLE9186_IOFF_LS3_I1OFF_LS3_POS                                         \
  (0x8u) /*!< LS3 Gate Driver pre-discharge current setting */
/** TLE9186_IOFF_LS3 masks */
#define TLE9186_IOFF_LS3_I2OFF_LS3_MSK                                         \
  (0x3fu) /*!< LS3 Gate Driver discharge current setting */
#define TLE9186_IOFF_LS3_I1OFF_LS3_MSK                                         \
  (0x3f00u) /*!< LS3 Gate Driver pre-discharge current setting */
/** TLE9186_CSA_CFG positions */
#define TLE9186_CSA_CFG_CSA_TFOC_POS                                           \
  (0x0u) /*!< Current sense amplifier overcurrent filter time                  \
          * setting */
#define TLE9186_CSA_CFG_CSA_OC_TH_POS                                          \
  (0x2u) /*!< Current sense amplifier overcurrent detection                    \
          * threshold */
#define TLE9186_CSA_CFG_CSA_CLOAD_POS                                          \
  (0x4u) /*!< Current sense amplifier output capacitive load range             \
          * */
#define TLE9186_CSA_CFG_CSA_DIR_POS                                            \
  (0x5u) /*!< Direction of current sense amplifier */
#define TLE9186_CSA_CFG_CSA_GAIN_POS                                           \
  (0x6u) /*!< Current sense amplifier differential gain                        \
          * configuration */
#define TLE9186_CSA_CFG_CSA_GAIN_TST_POS                                       \
  (0x9u) /*!< CSA gain accuracy check                                          \
          */
#define TLE9186_CSA_CFG_CSO_MUX_POS                                            \
  (0xau) /*!< Current Sense Amplifier Output redirection of digital            \
          * PFB signals */
#define TLE9186_CSA_CFG_CSA_REC_POS                                            \
  (0xdu) /*!< CSA recovery in case of VIO under-voltage event  */
/** TLE9186_CSA_CFG masks */
#define TLE9186_CSA_CFG_CSA_TFOC_MSK                                           \
  (0x3u) /*!< Current sense amplifier overcurrent filter time                  \
          * setting */
#define TLE9186_CSA_CFG_CSA_OC_TH_MSK                                          \
  (0xcu) /*!< Current sense amplifier overcurrent detection                    \
          * threshold */
#define TLE9186_CSA_CFG_CSA_CLOAD_MSK                                          \
  (0x10u) /*!< Current sense amplifier output capacitive load range            \
           * */
#define TLE9186_CSA_CFG_CSA_DIR_MSK                                            \
  (0x20u) /*!< Direction of current sense amplifier */
#define TLE9186_CSA_CFG_CSA_GAIN_MSK                                           \
  (0x1c0u) /*!< Current sense amplifier differential gain                      \
            * configuration */
#define TLE9186_CSA_CFG_CSA_GAIN_TST_MSK                                       \
  (0x200u) /*!< CSA gain accuracy check */
#define TLE9186_CSA_CFG_CSO_MUX_MSK                                            \
  (0x1c00u) /*!< Current Sense Amplifier Output redirection of digital         \
             * PFB signals */
#define TLE9186_CSA_CFG_CSA_REC_MSK                                            \
  (0x2000u) /*!< CSA recovery in case of VIO under-voltage event  */
/** TLE9186_FAILURE_CFG positions */
#define TLE9186_FAILURE_CFG_CSA_OC_FM_POS                                      \
  (0x0u) /*!< Current sense amplifiers overcurrent failure reaction            \
          * */
#define TLE9186_FAILURE_CFG_CSA_SUP_UV_FM_POS                                  \
  (0x2u) /*!< Internal supply of CSA module under-voltage failure              \
          * reaction */
#define TLE9186_FAILURE_CFG_PWM_CHK_FM_POS                                     \
  (0x4u) /*!< Failure reaction in case of missing PWM alternation              \
          * detection */
#define TLE9186_FAILURE_CFG_SDO_SHORT_FM_POS                                   \
  (0x5u) /*!< SDO short to supply or ground event , failure reaction           \
          *   */
#define TLE9186_FAILURE_CFG_INHN_REC_FM_POS                                    \
  (0x6u) /*!< INHN recovery after INHN low level reaction */
#define TLE9186_FAILURE_CFG_OTP_ERR_FM_POS                                     \
  (0x7u) /*!< OTP module error failure reaction configuration */
#define TLE9186_FAILURE_CFG_WD_FM_POS                                          \
  (0x8u) /*!< Window watchdog failure reaction */
#define TLE9186_FAILURE_CFG_TW_FM_POS                                          \
  (0x9u) /*!< Temperature warning failure reaction */
#define TLE9186_FAILURE_CFG_ERRN_FM_POS                                        \
  (0xau) /*!< ERRN short to supply failure reaction */
#define TLE9186_FAILURE_CFG_IPV_STP_FM_POS                                     \
  (0xbu) /*!< Shoot-through protection violation failure reaction */
#define TLE9186_FAILURE_CFG_IPV_CCP_FM_POS                                     \
  (0xcu) /*!< Input pattern violation due to TCCP violation failure            \
          * reaction */
#define TLE9186_FAILURE_CFG_PFB_FM_POS                                         \
  (0xdu) /*!< Phase feedback monitoring failure reaction */
#define TLE9186_FAILURE_CFG_DSOV_FM_POS                                        \
  (0xeu) /*!< Drain-source overvoltage failure reaction */
/** TLE9186_FAILURE_CFG masks */
#define TLE9186_FAILURE_CFG_CSA_OC_FM_MSK                                      \
  (0x3u) /*!< Current sense amplifiers overcurrent failure reaction            \
          * */
#define TLE9186_FAILURE_CFG_CSA_SUP_UV_FM_MSK                                  \
  (0xcu) /*!< Internal supply of CSA module under-voltage failure              \
          * reaction */
#define TLE9186_FAILURE_CFG_PWM_CHK_FM_MSK                                     \
  (0x10u) /*!< Failure reaction in case of missing PWM alternation             \
           * detection */
#define TLE9186_FAILURE_CFG_SDO_SHORT_FM_MSK                                   \
  (0x20u) /*!< SDO short to supply or ground event , failure reaction          \
           *   */
#define TLE9186_FAILURE_CFG_INHN_REC_FM_MSK                                    \
  (0x40u) /*!< INHN recovery after INHN low level reaction */
#define TLE9186_FAILURE_CFG_OTP_ERR_FM_MSK                                     \
  (0x80u) /*!< OTP module error failure reaction configuration */
#define TLE9186_FAILURE_CFG_WD_FM_MSK                                          \
  (0x100u) /*!< Window watchdog failure reaction */
#define TLE9186_FAILURE_CFG_TW_FM_MSK                                          \
  (0x200u) /*!< Temperature warning failure reaction */
#define TLE9186_FAILURE_CFG_ERRN_FM_MSK                                        \
  (0x400u) /*!< ERRN short to supply failure reaction */
#define TLE9186_FAILURE_CFG_IPV_STP_FM_MSK                                     \
  (0x800u) /*!< Shoot-through protection violation failure reaction */
#define TLE9186_FAILURE_CFG_IPV_CCP_FM_MSK                                     \
  (0x1000u) /*!< Input pattern violation due to TCCP violation failure         \
             * reaction */
#define TLE9186_FAILURE_CFG_PFB_FM_MSK                                         \
  (0x2000u) /*!< Phase feedback monitoring failure reaction */
#define TLE9186_FAILURE_CFG_DSOV_FM_MSK                                        \
  (0x4000u) /*!< Drain-source overvoltage failure reaction */
/** TLE9186_SELF_TEST_CFG positions */
#define TLE9186_SELF_TEST_CFG_LAT_FAULT_ST_POS                                 \
  (0x0u) /*!< Latent faults detector self-test enable */
#define TLE9186_SELF_TEST_CFG_CLK_MON_ST_POS                                   \
  (0x1u) /*!< Digital core clock monitoring self-test enable */
#define TLE9186_SELF_TEST_CFG_REG_UV_ST_POS                                    \
  (0x2u) /*!< Internal regulator under voltage self-test enable */
#define TLE9186_SELF_TEST_CFG_CSA_OC_ST_POS                                    \
  (0x3u) /*!< Current sense amplifier over-current supply self-test            \
          * enable */
#define TLE9186_SELF_TEST_CFG_CSA_SUP_ST_POS                                   \
  (0x4u) /*!< Current sense amplifier internal supply self-test                \
          * enable */
#define TLE9186_SELF_TEST_CFG_CPMON_ST_POS                                     \
  (0x5u) /*!< VCPH overdrive and undervoltage monitoring Self-test             \
          * enable */
#define TLE9186_SELF_TEST_CFG_VSCP_MON_ST_POS                                  \
  (0x6u) /*!< VSCP monitoring self-test enable */
#define TLE9186_SELF_TEST_CFG_SOFF_ST_POS                                      \
  (0x7u) /*!< Safe state activation path self-test enable */
#define TLE9186_SELF_TEST_CFG_TSD_ST_POS                                       \
  (0x8u) /*!< Overtemperature monitoring self-test enable */
#define TLE9186_SELF_TEST_CFG_PFB_ST_POS                                       \
  (0x9u) /*!< PFB logic self-test enable */
#define TLE9186_SELF_TEST_CFG_VIO_MON_ST_POS                                   \
  (0xau) /*!< VIO monitoring self-test enable */
#define TLE9186_SELF_TEST_CFG_DSOV_ST_POS                                      \
  (0xbu) /*!< Drain-source monitoring self-test enable */
/** TLE9186_SELF_TEST_CFG masks */
#define TLE9186_SELF_TEST_CFG_LAT_FAULT_ST_MSK                                 \
  (0x1u) /*!< Latent faults detector self-test enable */
#define TLE9186_SELF_TEST_CFG_CLK_MON_ST_MSK                                   \
  (0x2u) /*!< Digital core clock monitoring self-test enable */
#define TLE9186_SELF_TEST_CFG_REG_UV_ST_MSK                                    \
  (0x4u) /*!< Internal regulator under voltage self-test enable */
#define TLE9186_SELF_TEST_CFG_CSA_OC_ST_MSK                                    \
  (0x8u) /*!< Current sense amplifier over-current supply self-test            \
          * enable */
#define TLE9186_SELF_TEST_CFG_CSA_SUP_ST_MSK                                   \
  (0x10u) /*!< Current sense amplifier internal supply self-test               \
           * enable */
#define TLE9186_SELF_TEST_CFG_CPMON_ST_MSK                                     \
  (0x20u) /*!< VCPH overdrive and undervoltage monitoring Self-test            \
           * enable */
#define TLE9186_SELF_TEST_CFG_VSCP_MON_ST_MSK                                  \
  (0x40u) /*!< VSCP monitoring self-test enable */
#define TLE9186_SELF_TEST_CFG_SOFF_ST_MSK                                      \
  (0x80u) /*!< Safe state activation path self-test enable */
#define TLE9186_SELF_TEST_CFG_TSD_ST_MSK                                       \
  (0x100u) /*!< Overtemperature monitoring self-test enable */
#define TLE9186_SELF_TEST_CFG_PFB_ST_MSK                                       \
  (0x200u) /*!< PFB logic self-test enable */
#define TLE9186_SELF_TEST_CFG_VIO_MON_ST_MSK                                   \
  (0x400u) /*!< VIO monitoring self-test enable */
#define TLE9186_SELF_TEST_CFG_DSOV_ST_MSK                                      \
  (0x800u) /*!< Drain-source monitoring self-test enable */
/** TLE9186_SUP_STAT positions */
#define TLE9186_SUP_STAT_VIO_OV_POS (0x0u) /*!< VIO overvoltage detection */
#define TLE9186_SUP_STAT_VIO_UV_POS (0x1u) /*!< VIO undervoltage detection */
#define TLE9186_SUP_STAT_CSA_SUP_UV_POS                                        \
  (0x2u) /*!< Current sense amplifier internal supply undervoltage             \
          * */
#define TLE9186_SUP_STAT_VDH_UV_POS                                            \
  (0x3u) /*!< VDH pin under-voltage detection */
#define TLE9186_SUP_STAT_VSCP_H_POS                                            \
  (0x4u) /*!< VSCP High undervoltage detection  */
#define TLE9186_SUP_STAT_VSCP_L_POS                                            \
  (0x5u) /*!< VSCP Low undervoltage detection */
#define TLE9186_SUP_STAT_VCPH_UV_POS                                           \
  (0x6u) /*!< Charge pump output VCPH undervoltage detection */
#define TLE9186_SUP_STAT_VSCP_OV_SD_POS                                        \
  (0x7u) /*!< VSCP overvoltage shutdown detection */
#define TLE9186_SUP_STAT_VSCP_UV_SD_POS                                        \
  (0x8u) /*!< VSCP undervoltage shutdown detection */
#define TLE9186_SUP_STAT_POR_POS (0xfu) /*!< Power on reset detection */
/** TLE9186_SUP_STAT masks */
#define TLE9186_SUP_STAT_VIO_OV_MSK (0x1u) /*!< VIO overvoltage detection */
#define TLE9186_SUP_STAT_VIO_UV_MSK (0x2u) /*!< VIO undervoltage detection */
#define TLE9186_SUP_STAT_CSA_SUP_UV_MSK                                        \
  (0x4u) /*!< Current sense amplifier internal supply undervoltage             \
          * */
#define TLE9186_SUP_STAT_VDH_UV_MSK                                            \
  (0x8u) /*!< VDH pin under-voltage detection */
#define TLE9186_SUP_STAT_VSCP_H_MSK                                            \
  (0x10u) /*!< VSCP High undervoltage detection  */
#define TLE9186_SUP_STAT_VSCP_L_MSK                                            \
  (0x20u) /*!< VSCP Low undervoltage detection */
#define TLE9186_SUP_STAT_VCPH_UV_MSK                                           \
  (0x40u) /*!< Charge pump output VCPH undervoltage detection */
#define TLE9186_SUP_STAT_VSCP_OV_SD_MSK                                        \
  (0x80u) /*!< VSCP overvoltage shutdown detection */
#define TLE9186_SUP_STAT_VSCP_UV_SD_MSK                                        \
  (0x100u) /*!< VSCP undervoltage shutdown detection */
#define TLE9186_SUP_STAT_POR_MSK (0x8000u) /*!< Power on reset detection */
/** TLE9186_SPI_STAT positions */
#define TLE9186_SPI_STAT_FRAME_ERR_POS                                         \
  (0x0u) /*!< SPI frame error detection                                        \
          */
#define TLE9186_SPI_STAT_SPI_IA_POS                                            \
  (0x1u)                                     /*!< Invalid SPI access detection \
                                              */
#define TLE9186_SPI_STAT_CRC_FAIL_POS (0x2u) /*!< CRC failure detection */
#define TLE9186_SPI_STAT_OFC_POS                                               \
  (0x3u) /*!< One SPI frame corrupted detection */
#define TLE9186_SPI_STAT_CSN_TO_POS (0x4u) /*!< CSN time-out detection */
#define TLE9186_SPI_STAT_SDO_SHORT_POS                                         \
  (0x5u) /*!< SDO short to supply or ground detection */
#define TLE9186_SPI_STAT_WDLE_POS                                              \
  (0x7u)                                /*!< Watchdog latched error detection */
#define TLE9186_SPI_STAT_WDE_POS (0x8u) /*!< Watchdog error detection */
#define TLE9186_SPI_STAT_WD_CNT_POS (0x9u) /*!< Watchdog fails counter */
#define TLE9186_SPI_STAT_OTP_ERR_POS                                           \
  (0xfu) /*!< OTP configuration error detection */
/** TLE9186_SPI_STAT masks */
#define TLE9186_SPI_STAT_FRAME_ERR_MSK                                         \
  (0x1u) /*!< SPI frame error detection                                        \
          */
#define TLE9186_SPI_STAT_SPI_IA_MSK                                            \
  (0x2u)                                     /*!< Invalid SPI access detection \
                                              */
#define TLE9186_SPI_STAT_CRC_FAIL_MSK (0x4u) /*!< CRC failure detection */
#define TLE9186_SPI_STAT_OFC_MSK                                               \
  (0x8u) /*!< One SPI frame corrupted detection */
#define TLE9186_SPI_STAT_CSN_TO_MSK (0x10u) /*!< CSN time-out detection */
#define TLE9186_SPI_STAT_SDO_SHORT_MSK                                         \
  (0x20u) /*!< SDO short to supply or ground detection */
#define TLE9186_SPI_STAT_WDLE_MSK                                              \
  (0x80u) /*!< Watchdog latched error detection */
#define TLE9186_SPI_STAT_WDE_MSK (0x100u)     /*!< Watchdog error detection */
#define TLE9186_SPI_STAT_WD_CNT_MSK (0x3e00u) /*!< Watchdog fails counter */
#define TLE9186_SPI_STAT_OTP_ERR_MSK                                           \
  (0x8000u) /*!< OTP configuration error detection */
/** TLE9186_DEV_STAT1 positions */
#define TLE9186_DEV_STAT1_ERR_N_LVL_POS                                        \
  (0x0u) /*!< ERR_N output pin level monitoring (real time input pin           \
          * monitoring) */
#define TLE9186_DEV_STAT1_INH_N_LVL_POS                                        \
  (0x1u) /*!< INH_N input pin level monitoring (real time input pin            \
          * monitoring) */
#define TLE9186_DEV_STAT1_INHN_L_DET_POS                                       \
  (0x2u) /*!< INH_N input pin low level detection (canceled                    \
          * power-down event) */
#define TLE9186_DEV_STAT1_IL1_LVL_POS                                          \
  (0x3u) /*!< LS1 PWM input pin level monitoring (real time input              \
          * pin monitoring) */
#define TLE9186_DEV_STAT1_IL2_LVL_POS                                          \
  (0x4u) /*!< LS2 PWM input pin level monitoring (real time input              \
          * pin monitoring) */
#define TLE9186_DEV_STAT1_IL3_LVL_POS                                          \
  (0x5u) /*!< LS3 PWM input pin level monitoring (real time input              \
          * pin monitoring) */
#define TLE9186_DEV_STAT1_IH1N_LVL_POS                                         \
  (0x6u) /*!< HS1 PWM input pin level monitoring (real time input              \
          * pin monitoring) */
#define TLE9186_DEV_STAT1_IH2N_LVL_POS                                         \
  (0x7u) /*!< HS2 PWM input pin level monitoring (real time input              \
          * pin monitoring) */
#define TLE9186_DEV_STAT1_IH3N_LVL_POS                                         \
  (0x8u) /*!< HS3 PWM input pin level monitoring (real time input              \
          * pin monitoring) */
#define TLE9186_DEV_STAT1_ERRN_ACT_POS (0xau) /*!< ERR_N pin active low */
#define TLE9186_DEV_STAT1_SOFF_ACT_POS (0xbu) /*!< Safe state activation */
#define TLE9186_DEV_STAT1_DEV_STAT_POS                                         \
  (0xeu) /*!< Device operation mode status information */
/** TLE9186_DEV_STAT1 masks */
#define TLE9186_DEV_STAT1_ERR_N_LVL_MSK                                        \
  (0x1u) /*!< ERR_N output pin level monitoring (real time input pin           \
          * monitoring) */
#define TLE9186_DEV_STAT1_INH_N_LVL_MSK                                        \
  (0x2u) /*!< INH_N input pin level monitoring (real time input pin            \
          * monitoring) */
#define TLE9186_DEV_STAT1_INHN_L_DET_MSK                                       \
  (0x4u) /*!< INH_N input pin low level detection (canceled                    \
          * power-down event) */
#define TLE9186_DEV_STAT1_IL1_LVL_MSK                                          \
  (0x8u) /*!< LS1 PWM input pin level monitoring (real time input              \
          * pin monitoring) */
#define TLE9186_DEV_STAT1_IL2_LVL_MSK                                          \
  (0x10u) /*!< LS2 PWM input pin level monitoring (real time input             \
           * pin monitoring) */
#define TLE9186_DEV_STAT1_IL3_LVL_MSK                                          \
  (0x20u) /*!< LS3 PWM input pin level monitoring (real time input             \
           * pin monitoring) */
#define TLE9186_DEV_STAT1_IH1N_LVL_MSK                                         \
  (0x40u) /*!< HS1 PWM input pin level monitoring (real time input             \
           * pin monitoring) */
#define TLE9186_DEV_STAT1_IH2N_LVL_MSK                                         \
  (0x80u) /*!< HS2 PWM input pin level monitoring (real time input             \
           * pin monitoring) */
#define TLE9186_DEV_STAT1_IH3N_LVL_MSK                                         \
  (0x100u) /*!< HS3 PWM input pin level monitoring (real time input            \
            * pin monitoring) */
#define TLE9186_DEV_STAT1_ERRN_ACT_MSK (0x400u) /*!< ERR_N pin active low */
#define TLE9186_DEV_STAT1_SOFF_ACT_MSK (0x800u) /*!< Safe state activation */
#define TLE9186_DEV_STAT1_DEV_STAT_MSK                                         \
  (0xc000u) /*!< Device operation mode status information */
/** TLE9186_DEV_STAT2 positions */
#define TLE9186_DEV_STAT2_TSD_CP_POS                                           \
  (0x0u) /*!< Charge pump overtemperature detection */
#define TLE9186_DEV_STAT2_TSD_IC_POS                                           \
  (0x1u) /*!< General overtemperature shutdown detection */
#define TLE9186_DEV_STAT2_TSDW_POS                                             \
  (0x2u) /*!< Over temperature warning detection */
#define TLE9186_DEV_STAT2_CSA_OC_POS (0x3u) /*!< CSA overcurrent detection */
#define TLE9186_DEV_STAT2_ERRN_SHORT_POS                                       \
  (0x4u) /*!< ERR_N pin short to supply detection */
#define TLE9186_DEV_STAT2_PFB1_LE_POS                                          \
  (0x5u) /*!< Phase feedback monitoring of SH1 latched error                   \
          * detection */
#define TLE9186_DEV_STAT2_PFB2_LE_POS                                          \
  (0x6u) /*!< Phase feedback monitoring of SH2 latched error                   \
          * detection */
#define TLE9186_DEV_STAT2_PFB3_LE_POS                                          \
  (0x7u) /*!< Phase feedback monitoring of SH3 latched error                   \
          * detection */
#define TLE9186_DEV_STAT2_IPV_STP_HB1_POS                                      \
  (0x9u) /*!< Half-bridge 1 input pattern violation due to                     \
          * shoot-through protection */
#define TLE9186_DEV_STAT2_IPV_STP_HB2_POS                                      \
  (0xau) /*!< Half-bridge 2 input pattern violation due to                     \
          * shoot-through protection */
#define TLE9186_DEV_STAT2_IPV_STP_HB3_POS                                      \
  (0xbu) /*!< Half-bridge 3 input pattern violation due to                     \
          * shoot-through protection */
#define TLE9186_DEV_STAT2_IPV_CCP_HB1_POS                                      \
  (0xcu) /*!< Half-bridge 1 input pattern violation due to                     \
          * cross-current protection */
#define TLE9186_DEV_STAT2_IPV_CCP_HB2_POS                                      \
  (0xdu) /*!< Half-bridge 2 input pattern violation due to                     \
          * cross-current protection */
#define TLE9186_DEV_STAT2_IPV_CCP_HB3_POS                                      \
  (0xeu) /*!< Half-bridge 3 input pattern violation due to                     \
          * cross-current protection */

/** TLE9186_DEV_STAT2 masks */
#define TLE9186_DEV_STAT2_TSD_CP_MSK                                           \
  (0x1u) /*!< Charge pump overtemperature detection */
#define TLE9186_DEV_STAT2_TSD_IC_MSK                                           \
  (0x2u) /*!< General overtemperature shutdown detection */
#define TLE9186_DEV_STAT2_TSDW_MSK                                             \
  (0x4u) /*!< Over temperature warning detection */
#define TLE9186_DEV_STAT2_CSA_OC_MSK (0x8u) /*!< CSA overcurrent detection */
#define TLE9186_DEV_STAT2_ERRN_SHORT_MSK                                       \
  (0x10u) /*!< ERR_N pin short to supply detection */
#define TLE9186_DEV_STAT2_PFB1_LE_MSK                                          \
  (0x20u) /*!< Phase feedback monitoring of SH1 latched error                  \
           * detection */
#define TLE9186_DEV_STAT2_PFB2_LE_MSK                                          \
  (0x40u) /*!< Phase feedback monitoring of SH2 latched error                  \
           * detection */
#define TLE9186_DEV_STAT2_PFB3_LE_MSK                                          \
  (0x80u) /*!< Phase feedback monitoring of SH3 latched error                  \
           * detection */
#define TLE9186_DEV_STAT2_IPV_STP_HB1_MSK                                      \
  (0x200u) /*!< Half-bridge 1 input pattern violation due to                   \
            * shoot-through protection */
#define TLE9186_DEV_STAT2_IPV_STP_HB2_MSK                                      \
  (0x400u) /*!< Half-bridge 2 input pattern violation due to                   \
            * shoot-through protection */
#define TLE9186_DEV_STAT2_IPV_STP_HB3_MSK                                      \
  (0x800u) /*!< Half-bridge 3 input pattern violation due to                   \
            * shoot-through protection */
#define TLE9186_DEV_STAT2_IPV_CCP_HB1_MSK                                      \
  (0x1000u) /*!< Half-bridge 1 input pattern violation due to                  \
             * cross-current protection */
#define TLE9186_DEV_STAT2_IPV_CCP_HB2_MSK                                      \
  (0x2000u) /*!< Half-bridge 2 input pattern violation due to                  \
             * cross-current protection */
#define TLE9186_DEV_STAT2_IPV_CCP_HB3_MSK                                      \
  (0x4000u) /*!< Half-bridge 3 input pattern violation due to                  \
             * cross-current protection */

/** TLE9186_LF_STAT positions */
#define TLE9186_LF_STAT_ST_RES_POS (0x0u) /*!< Self-test result */
#define TLE9186_LF_STAT_ST_RDY_POS (0x1u) /*!< Self-test status */
#define TLE9186_LF_STAT_LAT_FAULT_POS                                          \
  (0x2u) /*!< Internal latent fault detection */
#define TLE9186_LF_STAT_DSOV_LF_HB1_POS                                        \
  (0x3u) /*!< Half-bridge 1 drain-source monitor latent fault                  \
          * detection */
#define TLE9186_LF_STAT_DSOV_LF_HB2_POS                                        \
  (0x4u) /*!< Half-bridge 2 drain-source monitor latent fault                  \
          * detection */
#define TLE9186_LF_STAT_DSOV_LF_HB3_POS                                        \
  (0x5u) /*!< Half-bridge 3 drain-source monitor latent fault                  \
          * detection */
#define TLE9186_LF_STAT_BIAS_LF_POS                                            \
  (0x9u) /*!< Central bias monitoring latent fault detection */
#define TLE9186_LF_STAT_SOFF_GDRV_POS                                          \
  (0xau) /*!< Safe state entry indication with all 6 gate drivers */
/** TLE9186_LF_STAT masks */
#define TLE9186_LF_STAT_ST_RES_MSK (0x1u) /*!< Self-test result */
#define TLE9186_LF_STAT_ST_RDY_MSK (0x2u) /*!< Self-test status */
#define TLE9186_LF_STAT_LAT_FAULT_MSK                                          \
  (0x4u) /*!< Internal latent fault detection */
#define TLE9186_LF_STAT_DSOV_LF_HB1_MSK                                        \
  (0x8u) /*!< Half-bridge 1 drain-source monitor latent fault                  \
          * detection */
#define TLE9186_LF_STAT_DSOV_LF_HB2_MSK                                        \
  (0x10u) /*!< Half-bridge 2 drain-source monitor latent fault                 \
           * detection */
#define TLE9186_LF_STAT_DSOV_LF_HB3_MSK                                        \
  (0x20u) /*!< Half-bridge 3 drain-source monitor latent fault                 \
           * detection */
#define TLE9186_LF_STAT_BIAS_LF_MSK                                            \
  (0x200u) /*!< Central bias monitoring latent fault detection */
#define TLE9186_LF_STAT_SOFF_GDRV_MSK                                          \
  (0x400u) /*!< Safe state entry indication with all 6 gate drivers */
/** TLE9186_SH_LEVEL_STAT positions */
#define TLE9186_SH_LEVEL_STAT_VSH1_L_POS                                       \
  (0x0u) /*!< Phase 1 voltage monitoring (SH1) VSHL */
#define TLE9186_SH_LEVEL_STAT_VSH1_H_POS                                       \
  (0x1u) /*!< Phase 1 voltage monitoring (SH1) VSHH */
#define TLE9186_SH_LEVEL_STAT_VSH2_L_POS                                       \
  (0x2u) /*!< Phase 2 voltage monitoring (SH2) VSHL */
#define TLE9186_SH_LEVEL_STAT_VSH2_H_POS                                       \
  (0x3u) /*!< Phase 2 voltage monitoring (SH2) VSHH */
#define TLE9186_SH_LEVEL_STAT_VSH3_L_POS                                       \
  (0x4u) /*!< Phase 3 voltage monitoring (SH3) VSHL */
#define TLE9186_SH_LEVEL_STAT_VSH3_H_POS                                       \
  (0x5u) /*!< Phase 3 voltage monitoring (SH3) VSHH */
#define TLE9186_SH_LEVEL_STAT_PFB1_POS                                         \
  (0xbu) /*!< Phase feedback comparator level of SH1 phase */
#define TLE9186_SH_LEVEL_STAT_PFB2_POS                                         \
  (0xcu) /*!< Phase feedback comparator level of SH2 phase */
#define TLE9186_SH_LEVEL_STAT_PFB3_POS                                         \
  (0xdu) /*!< Phase feedback comparator level of SH3 phase */
/** TLE9186_SH_LEVEL_STAT masks */
#define TLE9186_SH_LEVEL_STAT_VSH1_L_MSK                                       \
  (0x1u) /*!< Phase 1 voltage monitoring (SH1) VSHL */
#define TLE9186_SH_LEVEL_STAT_VSH1_H_MSK                                       \
  (0x2u) /*!< Phase 1 voltage monitoring (SH1) VSHH */
#define TLE9186_SH_LEVEL_STAT_VSH2_L_MSK                                       \
  (0x4u) /*!< Phase 2 voltage monitoring (SH2) VSHL */
#define TLE9186_SH_LEVEL_STAT_VSH2_H_MSK                                       \
  (0x8u) /*!< Phase 2 voltage monitoring (SH2) VSHH */
#define TLE9186_SH_LEVEL_STAT_VSH3_L_MSK                                       \
  (0x10u) /*!< Phase 3 voltage monitoring (SH3) VSHL */
#define TLE9186_SH_LEVEL_STAT_VSH3_H_MSK                                       \
  (0x20u) /*!< Phase 3 voltage monitoring (SH3) VSHH */
#define TLE9186_SH_LEVEL_STAT_PFB1_MSK                                         \
  (0x800u) /*!< Phase feedback comparator level of SH1 phase */
#define TLE9186_SH_LEVEL_STAT_PFB2_MSK                                         \
  (0x1000u) /*!< Phase feedback comparator level of SH2 phase */
#define TLE9186_SH_LEVEL_STAT_PFB3_MSK                                         \
  (0x2000u) /*!< Phase feedback comparator level of SH3 phase */
/** TLE9186_BD_STAT positions */
#define TLE9186_BD_STAT_DSOV_LS1_POS                                           \
  (0x3u) /*!< Drain-source overvoltage monitoring of LS1 */
#define TLE9186_BD_STAT_DSOV_LS2_POS                                           \
  (0x4u) /*!< Drain-source overvoltage monitoring of LS2 */
#define TLE9186_BD_STAT_DSOV_LS3_POS                                           \
  (0x5u) /*!< Drain-source overvoltage monitoring of LS3 */
#define TLE9186_BD_STAT_DSOV_HS1_POS                                           \
  (0x6u) /*!< Drain-source overvoltage monitoring of HS1 */
#define TLE9186_BD_STAT_DSOV_HS2_POS                                           \
  (0x7u) /*!< Drain-source overvoltage monitoring of HS2 */
#define TLE9186_BD_STAT_DSOV_HS3_POS                                           \
  (0x8u) /*!< Drain-source overvoltage monitoring of HS3 */
#define TLE9186_BD_STAT_IL1_MISS_POS                                           \
  (0x9u) /*!< PWM alternation check - detection of stuck IL1 PWM               \
          * input pin */
#define TLE9186_BD_STAT_IL2_MISS_POS                                           \
  (0xau) /*!< PWM alternation check - detection of stuck IL2 PWM               \
          * input pin */
#define TLE9186_BD_STAT_IL3_MISS_POS                                           \
  (0xbu) /*!< PWM alternation check - detection of stuck IL3 PWM               \
          * input pin */
#define TLE9186_BD_STAT_IH1_MISS_POS                                           \
  (0xcu) /*!< PWM alternation check - detection of stuck IH1_N PWM             \
          * input pin */
#define TLE9186_BD_STAT_IH2_MISS_POS                                           \
  (0xdu) /*!< PWM alternation check - detection of stuck IH2_N PWM             \
          * input pin */
#define TLE9186_BD_STAT_IH3_MISS_POS                                           \
  (0xeu) /*!< PWM alternation check - detection of stuck IH3_N PWM             \
          * input pin */

/** TLE9186_BD_STAT masks */
#define TLE9186_BD_STAT_DSOV_LS1_MSK                                           \
  (0x8u) /*!< Drain-source overvoltage monitoring of LS1 */
#define TLE9186_BD_STAT_DSOV_LS2_MSK                                           \
  (0x10u) /*!< Drain-source overvoltage monitoring of LS2 */
#define TLE9186_BD_STAT_DSOV_LS3_MSK                                           \
  (0x20u) /*!< Drain-source overvoltage monitoring of LS3 */
#define TLE9186_BD_STAT_DSOV_HS1_MSK                                           \
  (0x40u) /*!< Drain-source overvoltage monitoring of HS1 */
#define TLE9186_BD_STAT_DSOV_HS2_MSK                                           \
  (0x80u) /*!< Drain-source overvoltage monitoring of HS2 */
#define TLE9186_BD_STAT_DSOV_HS3_MSK                                           \
  (0x100u) /*!< Drain-source overvoltage monitoring of HS3 */
#define TLE9186_BD_STAT_IL1_MISS_MSK                                           \
  (0x200u) /*!< PWM alternation check - detection of stuck IL1 PWM             \
            * input pin */
#define TLE9186_BD_STAT_IL2_MISS_MSK                                           \
  (0x400u) /*!< PWM alternation check - detection of stuck IL2 PWM             \
            * input pin */
#define TLE9186_BD_STAT_IL3_MISS_MSK                                           \
  (0x800u) /*!< PWM alternation check - detection of stuck IL3 PWM             \
            * input pin */
#define TLE9186_BD_STAT_IH1_MISS_MSK                                           \
  (0x1000u) /*!< PWM alternation check - detection of stuck IH1_N PWM          \
             * input pin */
#define TLE9186_BD_STAT_IH2_MISS_MSK                                           \
  (0x2000u) /*!< PWM alternation check - detection of stuck IH2_N PWM          \
             * input pin */
#define TLE9186_BD_STAT_IH3_MISS_MSK                                           \
  (0x4000u) /*!< PWM alternation check - detection of stuck IH3_N PWM          \
             * input pin */

/** TLE9186_WD_CLK_CNT positions */
#define TLE9186_WD_CLK_CNT_WD_CLK_CNT_POS                                      \
  (0x0u) /*!< Internal clock counter between two consecutive correct           \
          * watchdog services. LSB of nominal 2.4us */

/** TLE9186_WD_CLK_CNT masks */
#define TLE9186_WD_CLK_CNT_WD_CLK_CNT_MSK                                      \
  (0xffffu) /*!< Internal clock counter between two consecutive correct        \
             * watchdog services. LSB of nominal 2.4us */

/** TLE9186_PHASE1_CNT positions */
#define TLE9186_PHASE1_CNT_PFB1_H_CNT_POS                                      \
  (0x0u) /*!< Phase 1 (SH1) high time counter, LSB of nominal 250ns            \
          * */
#define TLE9186_PHASE1_CNT_CNT1_RDY_POS                                        \
  (0xdu) /*!< PFB1_H counter ready for read indication */
#define TLE9186_PHASE1_CNT_PFB1_CNT_UPD_POS                                    \
  (0xeu) /*!< PFB1 counter update indication */
#define TLE9186_PHASE1_CNT_PFB1_POS                                            \
  (0xfu) /*!< Phase feedback comparator level of SH1 phase */
/** TLE9186_PHASE1_CNT masks */
#define TLE9186_PHASE1_CNT_PFB1_H_CNT_MSK                                      \
  (0x1fffu) /*!< Phase 1 (SH1) high time counter, LSB of nominal 250ns         \
             * */
#define TLE9186_PHASE1_CNT_CNT1_RDY_MSK                                        \
  (0x2000u) /*!< PFB1_H counter ready for read indication */
#define TLE9186_PHASE1_CNT_PFB1_CNT_UPD_MSK                                    \
  (0x4000u) /*!< PFB1 counter update indication */
#define TLE9186_PHASE1_CNT_PFB1_MSK                                            \
  (0x8000u) /*!< Phase feedback comparator level of SH1 phase */
/** TLE9186_PHASE2_CNT positions */
#define TLE9186_PHASE2_CNT_PFB2_H_CNT_POS                                      \
  (0x0u) /*!< Phase 2 (SH2) high time counter, LSB of nominal 250ns            \
          * */
#define TLE9186_PHASE2_CNT_CNT2_RDY_POS                                        \
  (0xdu) /*!< PFB2_H counter ready for read indication */
#define TLE9186_PHASE2_CNT_PFB2_CNT_UPD_POS                                    \
  (0xeu) /*!< PFB2 counter update indication */
#define TLE9186_PHASE2_CNT_PFB2_POS                                            \
  (0xfu) /*!< Phase feedback comparator level of SH2 phase */
/** TLE9186_PHASE2_CNT masks */
#define TLE9186_PHASE2_CNT_PFB2_H_CNT_MSK                                      \
  (0x1fffu) /*!< Phase 2 (SH2) high time counter, LSB of nominal 250ns         \
             * */
#define TLE9186_PHASE2_CNT_CNT2_RDY_MSK                                        \
  (0x2000u) /*!< PFB2_H counter ready for read indication */
#define TLE9186_PHASE2_CNT_PFB2_CNT_UPD_MSK                                    \
  (0x4000u) /*!< PFB2 counter update indication */
#define TLE9186_PHASE2_CNT_PFB2_MSK                                            \
  (0x8000u) /*!< Phase feedback comparator level of SH2 phase */
/** TLE9186_PHASE3_CNT positions */
#define TLE9186_PHASE3_CNT_PFB3_H_CNT_POS                                      \
  (0x0u) /*!< Phase 3 (SH3) high time counter */
#define TLE9186_PHASE3_CNT_CNT3_RDY_POS                                        \
  (0xdu) /*!< PFB3_H counter ready for read indication */
#define TLE9186_PHASE3_CNT_PFB3_CNT_UPD_POS                                    \
  (0xeu) /*!< PFB3 counter update indication */
#define TLE9186_PHASE3_CNT_PFB3_POS                                            \
  (0xfu) /*!< Phase feedback comparator level of SH3 phase */
/** TLE9186_PHASE3_CNT masks */
#define TLE9186_PHASE3_CNT_PFB3_H_CNT_MSK                                      \
  (0x1fffu) /*!< Phase 3 (SH3) high time counter */
#define TLE9186_PHASE3_CNT_CNT3_RDY_MSK                                        \
  (0x2000u) /*!< PFB3_H counter ready for read indication */
#define TLE9186_PHASE3_CNT_PFB3_CNT_UPD_MSK                                    \
  (0x4000u) /*!< PFB3 counter update indication */
#define TLE9186_PHASE3_CNT_PFB3_MSK                                            \
  (0x8000u) /*!< Phase feedback comparator level of SH3 phase */
/** TLE9186_TDON_TDOFF_HS1 positions */
#define TLE9186_TDON_TDOFF_HS1_TDOFF_HS1_POS                                   \
  (0x0u) /*!< Effective turn-off delay time of HS1 MOSFET */
#define TLE9186_TDON_TDOFF_HS1_TDON_HS1_POS                                    \
  (0x7u) /*!< Effective turn-on delay time of HS1 MOSFET */
#define TLE9186_TDON_TDOFF_HS1_LS1_ACT_POS                                     \
  (0xeu) /*!< LS1 detection as active MOSFET when turned ON */
#define TLE9186_TDON_TDOFF_HS1_HS1_ACT_POS                                     \
  (0xfu) /*!< HS1 detection as active MOSFET when turned ON */
/** TLE9186_TDON_TDOFF_HS1 masks */
#define TLE9186_TDON_TDOFF_HS1_TDOFF_HS1_MSK                                   \
  (0x7fu) /*!< Effective turn-off delay time of HS1 MOSFET */
#define TLE9186_TDON_TDOFF_HS1_TDON_HS1_MSK                                    \
  (0x7f80u) /*!< Effective turn-on delay time of HS1 MOSFET */
#define TLE9186_TDON_TDOFF_HS1_LS1_ACT_MSK                                     \
  (0x4000u) /*!< LS1 detection as active MOSFET when turned ON */
#define TLE9186_TDON_TDOFF_HS1_HS1_ACT_MSK                                     \
  (0x8000u) /*!< HS1 detection as active MOSFET when turned ON */
/** TLE9186_TDON_TDOFF_LS1 positions */
#define TLE9186_TDON_TDOFF_LS1_TDOFF_LS1_POS                                   \
  (0x0u) /*!< Effective turn-off delay time of LS1 MOSFET */
#define TLE9186_TDON_TDOFF_LS1_TDON_LS1_POS                                    \
  (0x7u) /*!< Effective turn-on delay time of LS1 MOSFET */
#define TLE9186_TDON_TDOFF_LS1_LS1_ACT_POS                                     \
  (0xeu) /*!< LS1 detection as active MOSFET when turned ON */
#define TLE9186_TDON_TDOFF_LS1_HS1_ACT_POS                                     \
  (0xfu) /*!< HS1 detection as active MOSFET when turned ON */
/** TLE9186_TDON_TDOFF_LS1 masks */
#define TLE9186_TDON_TDOFF_LS1_TDOFF_LS1_MSK                                   \
  (0x7fu) /*!< Effective turn-off delay time of LS1 MOSFET */
#define TLE9186_TDON_TDOFF_LS1_TDON_LS1_MSK                                    \
  (0x3f80u) /*!< Effective turn-on delay time of LS1 MOSFET */
#define TLE9186_TDON_TDOFF_LS1_LS1_ACT_MSK                                     \
  (0x4000u) /*!< LS1 detection as active MOSFET when turned ON */
#define TLE9186_TDON_TDOFF_LS1_HS1_ACT_MSK                                     \
  (0x8000u) /*!< HS1 detection as active MOSFET when turned ON */
/** TLE9186_TDON_TDOFF_HS2 positions */
#define TLE9186_TDON_TDOFF_HS2_TDOFF_HS2_POS                                   \
  (0x0u) /*!< Effective turn-off delay time of HS2 MOSFET */
#define TLE9186_TDON_TDOFF_HS2_TDON_HS2_POS                                    \
  (0x7u) /*!< Effective turn-on delay time of HS2 MOSFET */
#define TLE9186_TDON_TDOFF_HS2_LS2_ACT_POS                                     \
  (0xeu) /*!< LS2 detection as active MOSFET when turned ON */
#define TLE9186_TDON_TDOFF_HS2_HS2_ACT_POS                                     \
  (0xfu) /*!< HS2 detection as active MOSFET when turned ON */
/** TLE9186_TDON_TDOFF_HS2 masks */
#define TLE9186_TDON_TDOFF_HS2_TDOFF_HS2_MSK                                   \
  (0x7fu) /*!< Effective turn-off delay time of HS2 MOSFET */
#define TLE9186_TDON_TDOFF_HS2_TDON_HS2_MSK                                    \
  (0x3f80u) /*!< Effective turn-on delay time of HS2 MOSFET */
#define TLE9186_TDON_TDOFF_HS2_LS2_ACT_MSK                                     \
  (0x4000u) /*!< LS2 detection as active MOSFET when turned ON */
#define TLE9186_TDON_TDOFF_HS2_HS2_ACT_MSK                                     \
  (0x8000u) /*!< HS2 detection as active MOSFET when turned ON */
/** TLE9186_TDON_TDOFF_LS2 positions */
#define TLE9186_TDON_TDOFF_LS2_TDOFF_LS2_POS                                   \
  (0x0u) /*!< Effective turn-off delay time of LS2 MOSFET */
#define TLE9186_TDON_TDOFF_LS2_TDON_LS2_POS                                    \
  (0x7u) /*!< Effective turn-on delay time of LS2 MOSFET */
#define TLE9186_TDON_TDOFF_LS2_LS2_ACT_POS                                     \
  (0xeu) /*!< LS2 detection as active MOSFET when turned ON */
#define TLE9186_TDON_TDOFF_LS2_HS2_ACT_POS                                     \
  (0xfu) /*!< HS2 detection as active MOSFET when turned ON */
/** TLE9186_TDON_TDOFF_LS2 masks */
#define TLE9186_TDON_TDOFF_LS2_TDOFF_LS2_MSK                                   \
  (0x7fu) /*!< Effective turn-off delay time of LS2 MOSFET */
#define TLE9186_TDON_TDOFF_LS2_TDON_LS2_MSK                                    \
  (0x3f80u) /*!< Effective turn-on delay time of LS2 MOSFET */
#define TLE9186_TDON_TDOFF_LS2_LS2_ACT_MSK                                     \
  (0x4000u) /*!< LS2 detection as active MOSFET when turned ON */
#define TLE9186_TDON_TDOFF_LS2_HS2_ACT_MSK                                     \
  (0x8000u) /*!< HS2 detection as active MOSFET when turned ON */
/** TLE9186_TDON_TDOFF_HS3 positions */
#define TLE9186_TDON_TDOFF_HS3_TDOFF_HS3_POS                                   \
  (0x0u) /*!< Effective turn-off delay time of HS3 MOSFET */
#define TLE9186_TDON_TDOFF_HS3_TDON_HS3_POS                                    \
  (0x7u) /*!< Effective turn-on delay time of HS3 MOSFET */
#define TLE9186_TDON_TDOFF_HS3_LS3_ACT_POS                                     \
  (0xeu) /*!< LS3 detection as active MOSFET when turned ON */
#define TLE9186_TDON_TDOFF_HS3_HS3_ACT_POS                                     \
  (0xfu) /*!< HS3 detection as active MOSFET when turned ON */
/** TLE9186_TDON_TDOFF_HS3 masks */
#define TLE9186_TDON_TDOFF_HS3_TDOFF_HS3_MSK                                   \
  (0x7fu) /*!< Effective turn-off delay time of HS3 MOSFET */
#define TLE9186_TDON_TDOFF_HS3_TDON_HS3_MSK                                    \
  (0x3f80u) /*!< Effective turn-on delay time of HS3 MOSFET */
#define TLE9186_TDON_TDOFF_HS3_LS3_ACT_MSK                                     \
  (0x4000u) /*!< LS3 detection as active MOSFET when turned ON */
#define TLE9186_TDON_TDOFF_HS3_HS3_ACT_MSK                                     \
  (0x8000u) /*!< HS3 detection as active MOSFET when turned ON */
/** TLE9186_TDON_TDOFF_LS3 positions */
#define TLE9186_TDON_TDOFF_LS3_TDOFF_LS3_POS                                   \
  (0x0u) /*!< Effective turn-off delay time of LS3 MOSFET */
#define TLE9186_TDON_TDOFF_LS3_TDON_LS3_POS                                    \
  (0x7u) /*!< Effective turn-on delay time of LS3 MOSFET */
#define TLE9186_TDON_TDOFF_LS3_LS3_ACT_POS                                     \
  (0xeu) /*!< LS3 detection as active MOSFET when turned ON */
#define TLE9186_TDON_TDOFF_LS3_HS3_ACT_POS                                     \
  (0xfu) /*!< HS3 detection as active MOSFET when turned ON */
/** TLE9186_TDON_TDOFF_LS3 masks */
#define TLE9186_TDON_TDOFF_LS3_TDOFF_LS3_MSK                                   \
  (0x7fu) /*!< Effective turn-off delay time of LS3 MOSFET */
#define TLE9186_TDON_TDOFF_LS3_TDON_LS3_MSK                                    \
  (0x3f80u) /*!< Effective turn-on delay time of LS3 MOSFET */
#define TLE9186_TDON_TDOFF_LS3_LS3_ACT_MSK                                     \
  (0x4000u) /*!< LS3 detection as active MOSFET when turned ON */
#define TLE9186_TDON_TDOFF_LS3_HS3_ACT_MSK                                     \
  (0x8000u) /*!< HS3 detection as active MOSFET when turned ON */
/** TLE9186_TSLEW_ON_OFF_HS1 positions */
#define TLE9186_TSLEW_ON_OFF_HS1_TSLEW_OFF_HS1_POS                             \
  (0x0u) /*!< Effective turn-off slew rate time of HS1 MOSFET */
#define TLE9186_TSLEW_ON_OFF_HS1_TSLEW_ON_HS1_POS                              \
  (0x7u) /*!< Effective turn-on slew rate time of HS1 MOSFET */
#define TLE9186_TSLEW_ON_OFF_HS1_LS1_ACT_POS                                   \
  (0xeu) /*!< LS1 detection as active MOSFET when turned ON */
#define TLE9186_TSLEW_ON_OFF_HS1_HS1_ACT_POS                                   \
  (0xfu) /*!< HS1 detection as active MOSFET when turned ON */
/** TLE9186_TSLEW_ON_OFF_HS1 masks */
#define TLE9186_TSLEW_ON_OFF_HS1_TSLEW_OFF_HS1_MSK                             \
  (0x7fu) /*!< Effective turn-off slew rate time of HS1 MOSFET */
#define TLE9186_TSLEW_ON_OFF_HS1_TSLEW_ON_HS1_MSK                              \
  (0x3f80u) /*!< Effective turn-on slew rate time of HS1 MOSFET */
#define TLE9186_TSLEW_ON_OFF_HS1_LS1_ACT_MSK                                   \
  (0x4000u) /*!< LS1 detection as active MOSFET when turned ON */
#define TLE9186_TSLEW_ON_OFF_HS1_HS1_ACT_MSK                                   \
  (0x8000u) /*!< HS1 detection as active MOSFET when turned ON */
/** TLE9186_TSLEW_ON_OFF_LS1 positions */
#define TLE9186_TSLEW_ON_OFF_LS1_TSLEW_OFF_LS1_POS                             \
  (0x0u) /*!< Effective turn-off slew rate time of LS1 MOSFET */
#define TLE9186_TSLEW_ON_OFF_LS1_TSLEW_ON_LS1_POS                              \
  (0x7u) /*!< Effective turn-on slew rate time of LS1 MOSFET */
#define TLE9186_TSLEW_ON_OFF_LS1_LS1_ACT_POS                                   \
  (0xeu) /*!< LS1 detection as active MOSFET when turned ON */
#define TLE9186_TSLEW_ON_OFF_LS1_HS1_ACT_POS                                   \
  (0xfu) /*!< HS1 detection as active MOSFET when turned ON */
/** TLE9186_TSLEW_ON_OFF_LS1 masks */
#define TLE9186_TSLEW_ON_OFF_LS1_TSLEW_OFF_LS1_MSK                             \
  (0x7fu) /*!< Effective turn-off slew rate time of LS1 MOSFET */
#define TLE9186_TSLEW_ON_OFF_LS1_TSLEW_ON_LS1_MSK                              \
  (0x3f80u) /*!< Effective turn-on slew rate time of LS1 MOSFET */
#define TLE9186_TSLEW_ON_OFF_LS1_LS1_ACT_MSK                                   \
  (0x4000u) /*!< LS1 detection as active MOSFET when turned ON */
#define TLE9186_TSLEW_ON_OFF_LS1_HS1_ACT_MSK                                   \
  (0x8000u) /*!< HS1 detection as active MOSFET when turned ON */
/** TLE9186_TSLEW_ON_OFF_HS2 positions */
#define TLE9186_TSLEW_ON_OFF_HS2_TSLEW_OFF_HS2_POS                             \
  (0x0u) /*!< Effective turn-off slew rate time of HS2 MOSFET */
#define TLE9186_TSLEW_ON_OFF_HS2_TSLEW_ON_HS2_POS                              \
  (0x7u) /*!< Effective turn-on slew rate time of HS2 MOSFET */
#define TLE9186_TSLEW_ON_OFF_HS2_LS2_ACT_POS                                   \
  (0xeu) /*!< LS2 detection as active MOSFET when turned ON */
#define TLE9186_TSLEW_ON_OFF_HS2_HS2_ACT_POS                                   \
  (0xfu) /*!< HS2 detection as active MOSFET when turned ON */
/** TLE9186_TSLEW_ON_OFF_HS2 masks */
#define TLE9186_TSLEW_ON_OFF_HS2_TSLEW_OFF_HS2_MSK                             \
  (0x7fu) /*!< Effective turn-off slew rate time of HS2 MOSFET */
#define TLE9186_TSLEW_ON_OFF_HS2_TSLEW_ON_HS2_MSK                              \
  (0x3f80u) /*!< Effective turn-on slew rate time of HS2 MOSFET */
#define TLE9186_TSLEW_ON_OFF_HS2_LS2_ACT_MSK                                   \
  (0x4000u) /*!< LS2 detection as active MOSFET when turned ON */
#define TLE9186_TSLEW_ON_OFF_HS2_HS2_ACT_MSK                                   \
  (0x8000u) /*!< HS2 detection as active MOSFET when turned ON */
/** TLE9186_TSLEW_ON_OFF_LS2 positions */
#define TLE9186_TSLEW_ON_OFF_LS2_TSLEW_OFF_LS2_POS                             \
  (0x0u) /*!< Effective turn-off slew rate time of LS2 MOSFET */
#define TLE9186_TSLEW_ON_OFF_LS2_TSLEW_ON_LS2_POS                              \
  (0x7u) /*!< Effective turn-on slew rate time of LS2 MOSFET */
#define TLE9186_TSLEW_ON_OFF_LS2_LS2_ACT_POS                                   \
  (0xeu) /*!< LS2 detection as active MOSFET when turned ON */
#define TLE9186_TSLEW_ON_OFF_LS2_HS2_ACT_POS                                   \
  (0xfu) /*!< HS2 detection as active MOSFET when turned ON */
/** TLE9186_TSLEW_ON_OFF_LS2 masks */
#define TLE9186_TSLEW_ON_OFF_LS2_TSLEW_OFF_LS2_MSK                             \
  (0x7fu) /*!< Effective turn-off slew rate time of LS2 MOSFET */
#define TLE9186_TSLEW_ON_OFF_LS2_TSLEW_ON_LS2_MSK                              \
  (0x3f80u) /*!< Effective turn-on slew rate time of LS2 MOSFET */
#define TLE9186_TSLEW_ON_OFF_LS2_LS2_ACT_MSK                                   \
  (0x4000u) /*!< LS2 detection as active MOSFET when turned ON */
#define TLE9186_TSLEW_ON_OFF_LS2_HS2_ACT_MSK                                   \
  (0x8000u) /*!< HS2 detection as active MOSFET when turned ON */
/** TLE9186_TSLEW_ON_OFF_HS3 positions */
#define TLE9186_TSLEW_ON_OFF_HS3_TSLEW_OFF_HS3_POS                             \
  (0x0u) /*!< Effective turn-off slew rate time of HS3 MOSFET */
#define TLE9186_TSLEW_ON_OFF_HS3_TSLEW_ON_HS3_POS                              \
  (0x7u) /*!< Effective turn-on slew rate time of HS3 MOSFET */
#define TLE9186_TSLEW_ON_OFF_HS3_LS3_ACT_POS                                   \
  (0xeu) /*!< LS3 detection as active MOSFET when turned ON */
#define TLE9186_TSLEW_ON_OFF_HS3_HS3_ACT_POS                                   \
  (0xfu) /*!< HS3 detection as active MOSFET when turned ON */
/** TLE9186_TSLEW_ON_OFF_HS3 masks */
#define TLE9186_TSLEW_ON_OFF_HS3_TSLEW_OFF_HS3_MSK                             \
  (0x7fu) /*!< Effective turn-off slew rate time of HS3 MOSFET */
#define TLE9186_TSLEW_ON_OFF_HS3_TSLEW_ON_HS3_MSK                              \
  (0x3f80u) /*!< Effective turn-on slew rate time of HS3 MOSFET */
#define TLE9186_TSLEW_ON_OFF_HS3_LS3_ACT_MSK                                   \
  (0x4000u) /*!< LS3 detection as active MOSFET when turned ON */
#define TLE9186_TSLEW_ON_OFF_HS3_HS3_ACT_MSK                                   \
  (0x8000u) /*!< HS3 detection as active MOSFET when turned ON */
/** TLE9186_TSLEW_ON_OFF_LS3 positions */
#define TLE9186_TSLEW_ON_OFF_LS3_TSLEW_OFF_LS3_POS                             \
  (0x0u) /*!< Effective turn-off slew rate time of LS3 MOSFET */
#define TLE9186_TSLEW_ON_OFF_LS3_TSLEW_ON_LS3_POS                              \
  (0x7u) /*!< Effective turn-on slew rate time of LS3 MOSFET */
#define TLE9186_TSLEW_ON_OFF_LS3_LS3_ACT_POS                                   \
  (0xeu) /*!< LS3 detection as active MOSFET when turned ON */
#define TLE9186_TSLEW_ON_OFF_LS3_HS3_ACT_POS                                   \
  (0xfu) /*!< HS3 detection as active MOSFET when turned ON */
/** TLE9186_TSLEW_ON_OFF_LS3 masks */
#define TLE9186_TSLEW_ON_OFF_LS3_TSLEW_OFF_LS3_MSK                             \
  (0x7fu) /*!< Effective turn-off slew rate time of LS3 MOSFET */
#define TLE9186_TSLEW_ON_OFF_LS3_TSLEW_ON_LS3_MSK                              \
  (0x3f80u) /*!< Effective turn-on slew rate time of LS3 MOSFET */
#define TLE9186_TSLEW_ON_OFF_LS3_LS3_ACT_MSK                                   \
  (0x4000u) /*!< LS3 detection as active MOSFET when turned ON */
#define TLE9186_TSLEW_ON_OFF_LS3_HS3_ACT_MSK                                   \
  (0x8000u) /*!< HS3 detection as active MOSFET when turned ON */
/** TLE9186_DEVICE_VERSION positions */
#define TLE9186_DEVICE_VERSION_PROD_POS (0x4u) /*!< Product Identifier */
#define TLE9186_DEVICE_VERSION_FAM_POS (0xau)  /*!< Family Identifier */
/** TLE9186_DEVICE_VERSION masks */
#define TLE9186_DEVICE_VERSION_PROD_MSK (0x3f0u) /*!< Product Identifier */
#define TLE9186_DEVICE_VERSION_FAM_MSK (0x3c00u) /*!< Family Identifier */

/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */

#endif /* TLE9186_DEFINES_H */
