/**
 *	@file TLE9186_init.h
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
 * @defgroup initValues Initialization Values
 * @brief The initialization values are needed for the initialization of the
 * register shadow and are based on the reset value of each register.
 *
 */

#ifndef TLE9186_INIT_H
#define TLE9186_INIT_H

/**
 * @addtogroup device_driver
 * @{
 */
/**
 * @addtogroup initValues
 * @{
 */

/***************************************************************/
/*        Reset values for the TLE9186 registers         */
/***************************************************************/

#define TLE9186_CONFIG_SECURED_Init                                            \
  (0x40u) /**< Power-up configuration protected register reset/initialization  \
           * value */
#define TLE9186_PWR_MOD_CFG_Init                                               \
  (0x2u) /**< Mode control register reset/initialization value */
#define TLE9186_WD_CFG_Init                                                    \
  (0x1du) /**< Watchdog configuration register reset/initialization value */
#define TLE9186_GEN_CFG1_Init                                                  \
  (0x6904u) /**< General configuration register 1 reset/initialization value   \
             */
#define TLE9186_GEN_CFG2_Init                                                  \
  (0x800u) /**< General configuration register 2 reset/initialization value */
#define TLE9186_GEN_CFG3_Init                                                  \
  (0x800u) /**< General configuration register 3 reset/initialization value */
#define TLE9186_GDRV_CFG1_Init                                                 \
  (0x8888u) /**< Gate driver configuration register 1 reset/initialization     \
               value */
#define TLE9186_GDRV_CFG2_Init                                                 \
  (0x5989u) /**< Gate driver configuration register 2 reset/initialization     \
               value */
#define TLE9186_GDRV_CFG3_Init                                                 \
  (0x16au) /**< Gate driver configuration register 3 reset/initialization      \
              value */
#define TLE9186_TON_HS_Init                                                    \
  (0x717u) /**< Gate Driver Configuration register - TON_HS                    \
            * reset/initialization value */
#define TLE9186_TON_LS_Init                                                    \
  (0x717u) /**< Gate Driver Configuration register - TON_LS                    \
            * reset/initialization value */
#define TLE9186_TOFF_HS_Init                                                   \
  (0x717u) /**< Gate Driver Configuration register - TOFF_HS                   \
            * reset/initialization value */
#define TLE9186_TOFF_LS_Init                                                   \
  (0x717u) /**< Gate Driver Configuration register - TOFF_LS                   \
            * reset/initialization value */
#define TLE9186_T3OFF_Init                                                     \
  (0x1717u) /**< Gate Driver Configuration register - T3OFF                    \
             * reset/initialization value */
#define TLE9186_ION_HS1_Init                                                   \
  (0x2020u) /**< Gate driver Configuration register - ION_HS1                  \
             * reset/initialization value */
#define TLE9186_ION_LS1_Init                                                   \
  (0x2020u) /**< Gate driver Configuration register - ION_LS1                  \
             * reset/initialization value */
#define TLE9186_ION_HS2_Init                                                   \
  (0x2020u) /**< Gate driver Configuration register - ION_HS2                  \
             * reset/initialization value */
#define TLE9186_ION_LS2_Init                                                   \
  (0x2020u) /**< Gate driver Configuration register - ION_LS2                  \
             * reset/initialization value */
#define TLE9186_ION_HS3_Init                                                   \
  (0x2020u) /**< Gate driver Configuration register - ION_HS3                  \
             * reset/initialization value */
#define TLE9186_ION_LS3_Init                                                   \
  (0x2020u) /**< Gate driver Configuration register - ION_LS3                  \
             * reset/initialization value */
#define TLE9186_I3ON_Init                                                      \
  (0x2020u) /**< Gate driver Configuration register - I3ON                     \
             * reset/initialization value */
#define TLE9186_ION_IOFF_DIDT_Init                                             \
  (0x2020u) /**< Gate driver Configuration register - ION_IOFF_DIDT            \
             * reset/initialization value */
#define TLE9186_IOFF_HS1_Init                                                  \
  (0x2020u) /**< Gate driver Configuration register - IOFF_HS1                 \
             * reset/initialization value */
#define TLE9186_IOFF_LS1_Init                                                  \
  (0x2020u) /**< Gate driver Configuration register - IOFF_LS1                 \
             * reset/initialization value */
#define TLE9186_IOFF_HS2_Init                                                  \
  (0x2020u) /**< Gate driver Configuration register - IOFF_HS2                 \
             * reset/initialization value */
#define TLE9186_IOFF_LS2_Init                                                  \
  (0x2020u) /**< Gate driver Configuration register - IOFF_LS2                 \
             * reset/initialization value */
#define TLE9186_IOFF_HS3_Init                                                  \
  (0x2020u) /**< Gate driver Configuration register - IOFF_HS3                 \
             * reset/initialization value */
#define TLE9186_IOFF_LS3_Init                                                  \
  (0x2020u) /**< Gate driver Configuration register - IOFF_LS3                 \
             * reset/initialization value */
#define TLE9186_CSA_CFG_Init                                                   \
  (0x75u) /**< Current sense amplifier configuration register                  \
           * reset/initialization value */
#define TLE9186_FAILURE_CFG_Init                                               \
  (0x0u) /**< Failure reaction configuration register 1 reset/initialization   \
          * value */
#define TLE9186_SELF_TEST_CFG_Init                                             \
  (0x0u) /**< Self-test configuration register  reset/initialization value */
#define TLE9186_SUP_STAT_Init                                                  \
  (0x80u) /**< Supply monitoring status register reset/initialization value */
#define TLE9186_SPI_STAT_Init                                                  \
  (0x0u) /**< SPI status register (SPI and WD monitoring) reset/initialization \
          * value */
#define TLE9186_DEV_STAT1_Init                                                 \
  (0x6800u) /**< Device status register 1: Operation mode and digital input    \
             * pins levels reset/initialization value */
#define TLE9186_DEV_STAT2_Init                                                 \
  (0x0u) /**< Device status register 2: Input pattern violation, ERR_N, CSA,   \
          * TSD monitoring reset/initialization value */
#define TLE9186_LF_STAT_Init                                                   \
  (0x400u) /**< Latent faults and self-tests status register: internal faults, \
            * self-tests results reset/initialization value */
#define TLE9186_SH_LEVEL_STAT_Init                                             \
  (0x3bbfu) /**< Phase pins monitoring reset/initialization value */
#define TLE9186_BD_STAT_Init                                                   \
  (0x0u) /**< HS & LS Gate Drivers monitoring   reset/initialization value */
#define TLE9186_WD_CLK_CNT_Init                                                \
  (0x0u) /**< Watchdog clock counter reset/initialization value */
#define TLE9186_PHASE1_CNT_Init                                                \
  (0x8000u) /**< Phase 1 high time counter reset/initialization value */
#define TLE9186_PHASE2_CNT_Init                                                \
  (0x8000u) /**< Phase 2 high time counter reset/initialization value */
#define TLE9186_PHASE3_CNT_Init                                                \
  (0x8000u) /**< Phase 3 high time counter reset/initialization value */
#define TLE9186_TDON_TDOFF_HS1_Init                                            \
  (0x0u) /**< Effective MOSFET turn-on/off delay time HS1 reset/initialization \
          * value */
#define TLE9186_TDON_TDOFF_LS1_Init                                            \
  (0x0u) /**< Effective MOSFET turn-on/off delay time LS1 reset/initialization \
          * value */
#define TLE9186_TDON_TDOFF_HS2_Init                                            \
  (0x0u) /**< Effective MOSFET turn-on/off delay time HS2 reset/initialization \
          * value */
#define TLE9186_TDON_TDOFF_LS2_Init                                            \
  (0x0u) /**< Effective MOSFET turn-on/off delay time LS2 reset/initialization \
          * value */
#define TLE9186_TDON_TDOFF_HS3_Init                                            \
  (0x0u) /**< Effective MOSFET turn-on/off delay time HS3 reset/initialization \
          * value */
#define TLE9186_TDON_TDOFF_LS3_Init                                            \
  (0x0u) /**< Effective MOSFET turn-on/off delay time LS3 reset/initialization \
          * value */
#define TLE9186_TSLEW_ON_OFF_HS1_Init                                          \
  (0x0u) /**< Effective MOSFET slew rate time HS1 reset/initialization value   \
          */
#define TLE9186_TSLEW_ON_OFF_LS1_Init                                          \
  (0x0u) /**< Effective MOSFET slew rate time LS1 reset/initialization value   \
          */
#define TLE9186_TSLEW_ON_OFF_HS2_Init                                          \
  (0x0u) /**< Effective MOSFET slew rate time HS2 reset/initialization value   \
          */
#define TLE9186_TSLEW_ON_OFF_LS2_Init                                          \
  (0x0u) /**< Effective MOSFET slew rate time LS2 reset/initialization value   \
          */
#define TLE9186_TSLEW_ON_OFF_HS3_Init                                          \
  (0x0u) /**< Effective MOSFET slew rate time HS3 reset/initialization value   \
          */
#define TLE9186_TSLEW_ON_OFF_LS3_Init                                          \
  (0x0u) /**< Effective MOSFET slew rate time LS3 reset/initialization value   \
          */
#define TLE9186_DEVICE_VERSION_Init                                            \
  (0x0u) /**< Device version information reset/initialization value */

/**
 * @}
 */
/**
 * @}
 */

#endif /* TLE9186_INIT_H */
