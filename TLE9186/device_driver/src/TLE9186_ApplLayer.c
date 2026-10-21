/**
 *	@file TLE9186_ApplLayer.c
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
 * @defgroup applLayer Application Layer
 * @brief The Application Layer is in charge of utilizing the API functions of
 * the device driver to an application code.
 * @details In this example the application layer offers pre-defined
 * initialization routines and cyclic update functions.
 *
 * @defgroup appl_layer_init Application Layer Initialization
 * @brief The device as well as the device driver needs an initialization. These
 * functions give an example on how this can be done.
 *
 * @defgroup appl_layer_cyclic Application Layer Cyclic Tasks
 * @brief The device driver offers the possibility of cyclicly reading out the
 * status and error registers of the TLE9186. These function enables such a
 * read-out.
 */
/************************************************************************
**                             Includes                                **
************************************************************************/
#include "TLE9186_ApplLayer.h"
#include "TLE9186.h"
#include "TLE9186_FuncLayer.h"
#include "TLE9186_RegLayer.h"
#include "TLE9186_ServLayer.h"
#include "TLE9186_defines.h"
#include "TLE9186_init.h"

/**
 * @addtogroup device_driver
 * @{
 */
/**
 * @addtogroup applLayer
 * @{
 */
/************************************************************************
**                     Local Definitions                               **
************************************************************************/
#define TLE9186_T_CORE_UP_US 1000u
#define TLE9186_WAIT_1_MS 1000u
#define TLE9186_SUCCESS 1u
#define TLE9186_ERROR 0u

/************************************************************************
**                     Local Type Definitions                          **
************************************************************************/
/**
 * @brief Function pointer for initialization of registers
 */
typedef uint8 (*fp_TLE9186_initDeviceReg)(uint16 u16_data);

/************************************************************************
**                    Local Variable Definitions                      **
************************************************************************/
extern s_TLE9186_deviceDriver s_deviceDriver_TLE9186 = {
    /* polyspace MISRA2012:8.5 [Justified: Low] "Given by
     * architecture" */
    TLE9186_DEVICEDRIVER_STATUS_INIT,   // u8_deviceDriverStatus
    TLE9186_DEVICEDRIVER_ERRORLOG_INIT, // u8_deviceDriverErrorLog
    0u,                                 // u8_statusSPI
    {0u, 0u, 0u, 0u},                   // u8_SpiRx[4]
    0u,                                 // u32_SpiRx
    0u,                                 // u32_SpiTx
    NULL,                               // fp_setReg
    NULL,                               // fp_getReg
    NULL,                               // fp_updateRamReg
    0u,                                 // u16_setBitValue
    0u,                                 // u8_crcResult
    0u                                  // u8_prev_addr
};

/**
 * @addtogroup appl_layer_cyclic
 * @{
 */
static fp_TLE9186_getDeviceReg fp_cyclicStatGetFuncs[] = {
    &TLE9186_RegLayer_get_SUP_STAT,         //
    &TLE9186_RegLayer_get_SPI_STAT,         //
    &TLE9186_RegLayer_get_DEV_STAT1,        //
    &TLE9186_RegLayer_get_DEV_STAT2,        //
    &TLE9186_RegLayer_get_LF_STAT,          //
    &TLE9186_RegLayer_get_SH_LEVEL_STAT,    //
    &TLE9186_RegLayer_get_BD_STAT,          //
    &TLE9186_RegLayer_get_WD_CLK_CNT,       //
    &TLE9186_RegLayer_get_PHASE1_CNT,       //
    &TLE9186_RegLayer_get_PHASE2_CNT,       //
    &TLE9186_RegLayer_get_PHASE3_CNT,       //
    &TLE9186_RegLayer_get_TDON_TDOFF_HS1,   //
    &TLE9186_RegLayer_get_TDON_TDOFF_LS1,   //
    &TLE9186_RegLayer_get_TDON_TDOFF_HS2,   //
    &TLE9186_RegLayer_get_TDON_TDOFF_LS2,   //
    &TLE9186_RegLayer_get_TDON_TDOFF_HS3,   //
    &TLE9186_RegLayer_get_TDON_TDOFF_LS3,   //
    &TLE9186_RegLayer_get_TSLEW_ON_OFF_HS1, //
    &TLE9186_RegLayer_get_TSLEW_ON_OFF_LS1, //
    &TLE9186_RegLayer_get_TSLEW_ON_OFF_HS2, //
    &TLE9186_RegLayer_get_TSLEW_ON_OFF_LS2, //
    &TLE9186_RegLayer_get_TSLEW_ON_OFF_HS3, //
    &TLE9186_RegLayer_get_TSLEW_ON_OFF_LS3  //
};
static fp_TLE9186_updateRamReg fp_cyclicStatUpdateFuncs[] = {
    &TLE9186_RegLayer_update_SUP_STAT,         //
    &TLE9186_RegLayer_update_SPI_STAT,         //
    &TLE9186_RegLayer_update_DEV_STAT1,        //
    &TLE9186_RegLayer_update_DEV_STAT2,        //
    &TLE9186_RegLayer_update_LF_STAT,          //
    &TLE9186_RegLayer_update_SH_LEVEL_STAT,    //
    &TLE9186_RegLayer_update_BD_STAT,          //
    &TLE9186_RegLayer_update_WD_CLK_CNT,       //
    &TLE9186_RegLayer_update_PHASE1_CNT,       //
    &TLE9186_RegLayer_update_PHASE2_CNT,       //
    &TLE9186_RegLayer_update_PHASE3_CNT,       //
    &TLE9186_RegLayer_update_TDON_TDOFF_HS1,   //
    &TLE9186_RegLayer_update_TDON_TDOFF_LS1,   //
    &TLE9186_RegLayer_update_TDON_TDOFF_HS2,   //
    &TLE9186_RegLayer_update_TDON_TDOFF_LS2,   //
    &TLE9186_RegLayer_update_TDON_TDOFF_HS3,   //
    &TLE9186_RegLayer_update_TDON_TDOFF_LS3,   //
    &TLE9186_RegLayer_update_TSLEW_ON_OFF_HS1, //
    &TLE9186_RegLayer_update_TSLEW_ON_OFF_LS1, //
    &TLE9186_RegLayer_update_TSLEW_ON_OFF_HS2, //
    &TLE9186_RegLayer_update_TSLEW_ON_OFF_LS2, //
    &TLE9186_RegLayer_update_TSLEW_ON_OFF_HS3, //
    &TLE9186_RegLayer_update_TSLEW_ON_OFF_LS3  //
};

/************************************************************************
**                    Global Function Definitions                      **
************************************************************************/
/**
 * @brief Device Driver Cyclic Task
 *
 * This function needs to be called continuously by the application. By doing so
 * the device driver is either executing write/read commands issued by the user
 * or updating the device's status register to keep the register shadow
 * up-to-date.
 *
 * @return uint8 Device Driver ErrorLog (0: INIT, 1: STARTED, 2: BUSY, 3:
 * SPI_RECEIVE_ERR)
 */
uint8 TLE9186_ApplLayer_deviceDriverCyclicTask(
    void) /* polyspace MISRA2012:8.7 [Justified: Low] "Called by main
           * application" */
{
  static uint8 u8_cyclicStatUpdateCount = 0u;
  uint16 u16_tempRegData;

  switch (s_deviceDriver_TLE9186.u8_deviceDriverStatus) {
  case TLE9186_DEVICEDRIVER_STATUS_INIT:

    /* dynamic set register requests to write to control registers have highest
     * priority */
    if (s_deviceDriver_TLE9186.fp_setReg != NULL) {
      s_deviceDriver_TLE9186.u8_deviceDriverStatus =
          TLE9186_DEVICEDRIVER_STATUS_CYCLIC_UPDATE;
      s_deviceDriver_TLE9186.fp_setReg(s_deviceDriver_TLE9186.u16_setBitValue);
      s_deviceDriver_TLE9186.fp_setReg = NULL;
      s_deviceDriver_TLE9186.u8_deviceDriverErrorLog =
          TLE9186_DEVICEDRIVER_ERRORLOG_STARTED;
      break;
    }

    /* cyclic get register requests to update status registers have lowest
       priority */
    else if (s_deviceDriver_TLE9186.fp_getReg != NULL) {
      s_deviceDriver_TLE9186.u8_deviceDriverStatus =
          TLE9186_DEVICEDRIVER_STATUS_CYCLIC_UPDATE;
      s_deviceDriver_TLE9186.fp_getReg =
          fp_cyclicStatGetFuncs[u8_cyclicStatUpdateCount];
      s_deviceDriver_TLE9186.fp_updateRamReg =
          fp_cyclicStatUpdateFuncs[u8_cyclicStatUpdateCount];
      s_deviceDriver_TLE9186.fp_getReg();

      if (u8_cyclicStatUpdateCount < TLE9186_DEVICEDRIVER_CYCLICSTATUPDATENUM) {
        u8_cyclicStatUpdateCount++;
      } else {
        u8_cyclicStatUpdateCount = 0u;
      }

      s_deviceDriver_TLE9186.u8_deviceDriverErrorLog =
          TLE9186_DEVICEDRIVER_ERRORLOG_STARTED;
      break;
    } else {
      s_deviceDriver_TLE9186.u8_deviceDriverErrorLog =
          TLE9186_DEVICEDRIVER_ERRORLOG_INIT;
      s_deviceDriver_TLE9186.u8_deviceDriverStatus =
          TLE9186_DEVICEDRIVER_STATUS_INIT;
      break;
    }

    break;

  case TLE9186_DEVICEDRIVER_STATUS_CYCLIC_UPDATE:
    /* update SPI status */
    TLE9186_ServLayer_SpiInterfaceStatus();

    if (s_deviceDriver_TLE9186.u8_statusSPI ==
        TLE9186_DEVICEDRIVER_SPI_NEW_DATA) /* polyspace MISRA2012:14.3
                                            * [Justified: Low]
                                            * "u8_statusSPI from HAL" */
    {
      /* get SPI Data */
      TLE9186_ServLayer_getSpiData();

      /* clear device driver error log */
      s_deviceDriver_TLE9186.u8_deviceDriverErrorLog =
          TLE9186_DEVICEDRIVER_ERRORLOG_INIT;

      if (s_deviceDriver_TLE9186.u8_SpiRx[0u] ==
          s_deviceDriver_TLE9186.u8_crcResult) {
        /* update GSB */
        TLE9186_RegLayer_update_GSB(s_deviceDriver_TLE9186.u8_SpiRx[3u]);

        /* update status register, if provided */
        if (s_deviceDriver_TLE9186.fp_updateRamReg != NULL) {
          u16_tempRegData =
              (uint16)(((uint16)s_deviceDriver_TLE9186.u8_SpiRx[1u] << 8u) |
                       ((uint16)s_deviceDriver_TLE9186.u8_SpiRx[2u] << 8u));
          s_deviceDriver_TLE9186.fp_updateRamReg(u16_tempRegData);
          s_deviceDriver_TLE9186.fp_updateRamReg = NULL;
        }
      } else {
        s_deviceDriver_TLE9186.u8_deviceDriverErrorLog =
            TLE9186_DEVICEDRIVER_ERRORLOG_SPI_RECEIVE_ERR;
      }

      /* Start next SPI command */
      /* dynamic set register requests to write to control registers have
       * highest priority */
      if (s_deviceDriver_TLE9186.fp_setReg != NULL) {
        s_deviceDriver_TLE9186.u8_deviceDriverStatus =
            TLE9186_DEVICEDRIVER_STATUS_CYCLIC_UPDATE;
        s_deviceDriver_TLE9186.fp_setReg(
            s_deviceDriver_TLE9186.u16_setBitValue);
        s_deviceDriver_TLE9186.fp_setReg = NULL;
        s_deviceDriver_TLE9186.u8_deviceDriverErrorLog =
            s_deviceDriver_TLE9186.u8_deviceDriverErrorLog |
            TLE9186_DEVICEDRIVER_ERRORLOG_STARTED;
        break;
      }

      /* cyclic get register requests to update status registers have lowest
         priority */
      else if (s_deviceDriver_TLE9186.fp_getReg != NULL) {
        s_deviceDriver_TLE9186.u8_deviceDriverStatus =
            TLE9186_DEVICEDRIVER_STATUS_CYCLIC_UPDATE;
        s_deviceDriver_TLE9186.fp_getReg =
            fp_cyclicStatGetFuncs[u8_cyclicStatUpdateCount];
        s_deviceDriver_TLE9186.fp_updateRamReg =
            fp_cyclicStatUpdateFuncs[u8_cyclicStatUpdateCount];
        s_deviceDriver_TLE9186.fp_getReg();

        if (u8_cyclicStatUpdateCount <
            (TLE9186_DEVICEDRIVER_CYCLICSTATUPDATENUM - 1u)) {
          u8_cyclicStatUpdateCount++;
        } else {
          u8_cyclicStatUpdateCount = 0u;
        }

        s_deviceDriver_TLE9186.u8_deviceDriverErrorLog =
            s_deviceDriver_TLE9186.u8_deviceDriverErrorLog |
            TLE9186_DEVICEDRIVER_ERRORLOG_STARTED;
        break;
      } else {
        s_deviceDriver_TLE9186.u8_deviceDriverStatus =
            TLE9186_DEVICEDRIVER_STATUS_INIT;
        break;
      }
    } /* polyspace MISRA2012:2.1 [Justified: Low] "u8_statusSPI from HAL" */
    else {
      s_deviceDriver_TLE9186.u8_deviceDriverErrorLog =
          TLE9186_DEVICEDRIVER_ERRORLOG_BUSY;
    }

    break;

  default:
    /* invalid device driver status */
    break;
  }

  return s_deviceDriver_TLE9186.u8_deviceDriverErrorLog;
}

/**
 * @}
 */
/**
 * @addtogroup appl_layer_init
 * @{
 */
/**
 * @brief Device Driver Initialization
 *
 * This function initializes the device driver and the connected TLE9186. The
 * initialization values for the registers are given in @ref initValues
 * "initialization values."
 *
 * @return Status if initialization was successful for not. Valid values are:
 *      - 0: Initialization failed.
 *      - 1: Initialization successful.
 *
 */
uint8 TLE9186_ApplLayer_deviceDriverInit(
    void) /* polyspace MISRA2012:15.5 [Justified: Low] "Init function has to
           * stop if error is detected."
           */
{
  uint8 u8_success = TLE9186_ERROR;
  fp_TLE9186_initDeviceReg fp_initRegTemp;
  uint16 u16_initRegValueTemp;
  uint8 u8_initRegisterCounter;
  uint8 u8_initRegisterNum;
  uint8 u8_initStatUpdateCount = 0u;
  fp_TLE9186_initDeviceReg fp_initRegAll[] = {
      &TLE9186_FuncLayer_set_WD_CFG,        //
      &TLE9186_FuncLayer_set_GEN_CFG1,      //
      &TLE9186_FuncLayer_set_GEN_CFG2,      //
      &TLE9186_FuncLayer_set_GEN_CFG3,      //
      &TLE9186_FuncLayer_set_GDRV_CFG1,     //
      &TLE9186_FuncLayer_set_GDRV_CFG2,     //
      &TLE9186_FuncLayer_set_GDRV_CFG3,     //
      &TLE9186_FuncLayer_set_TON_HS,        //
      &TLE9186_FuncLayer_set_TON_LS,        //
      &TLE9186_FuncLayer_set_TOFF_HS,       //
      &TLE9186_FuncLayer_set_TOFF_LS,       //
      &TLE9186_FuncLayer_set_T3OFF,         //
      &TLE9186_FuncLayer_set_ION_HS1,       //
      &TLE9186_FuncLayer_set_ION_LS1,       //
      &TLE9186_FuncLayer_set_ION_HS2,       //
      &TLE9186_FuncLayer_set_ION_LS2,       //
      &TLE9186_FuncLayer_set_ION_HS3,       //
      &TLE9186_FuncLayer_set_ION_LS3,       //
      &TLE9186_FuncLayer_set_I3ON,          //
      &TLE9186_FuncLayer_set_ION_IOFF_DIDT, //
      &TLE9186_FuncLayer_set_IOFF_HS1,      //
      &TLE9186_FuncLayer_set_IOFF_LS1,      //
      &TLE9186_FuncLayer_set_IOFF_HS2,      //
      &TLE9186_FuncLayer_set_IOFF_LS2,      //
      &TLE9186_FuncLayer_set_IOFF_HS3,      //
      &TLE9186_FuncLayer_set_IOFF_LS3,      //
      &TLE9186_FuncLayer_set_CSA_CFG,       //
      &TLE9186_FuncLayer_set_FAILURE_CFG,   //
      &TLE9186_FuncLayer_set_SELF_TEST_CFG  //
  };
  uint16 u16_initRegValueAll[] = {
      TLE9186_WD_CFG_Init,        //
      TLE9186_GEN_CFG1_Init,      //
      TLE9186_GEN_CFG2_Init,      //
      TLE9186_GEN_CFG3_Init,      //
      TLE9186_GDRV_CFG1_Init,     //
      TLE9186_GDRV_CFG2_Init,     //
      TLE9186_GDRV_CFG3_Init,     //
      TLE9186_TON_HS_Init,        //
      TLE9186_TON_LS_Init,        //
      TLE9186_TOFF_HS_Init,       //
      TLE9186_TOFF_LS_Init,       //
      TLE9186_T3OFF_Init,         //
      TLE9186_ION_HS1_Init,       //
      TLE9186_ION_LS1_Init,       //
      TLE9186_ION_HS2_Init,       //
      TLE9186_ION_LS2_Init,       //
      TLE9186_ION_HS3_Init,       //
      TLE9186_ION_LS3_Init,       //
      TLE9186_I3ON_Init,          //
      TLE9186_ION_IOFF_DIDT_Init, //
      TLE9186_IOFF_HS1_Init,      //
      TLE9186_IOFF_LS1_Init,      //
      TLE9186_IOFF_HS2_Init,      //
      TLE9186_IOFF_LS2_Init,      //
      TLE9186_IOFF_HS3_Init,      //
      TLE9186_IOFF_LS3_Init,      //
      TLE9186_CSA_CFG_Init,       //
      TLE9186_FAILURE_CFG_Init,   //
      TLE9186_SELF_TEST_CFG_Init  //
  };

  /* Initialize GPIO */
  TLE9186_ServLayer_InitGpio();

  /* Initialize shadow register */
  TLE9186_RegLayer_init_ShadowRegister();

  /* Enable device */
  TLE9186_ServLayer_SetINH_N(1u);

  /* Wait until SPI is ready on device */
  TLE9186_ServLayer_Wait_us(TLE9186_T_CORE_UP_US);

  /* Initialize SPI */
  TLE9186_ServLayer_InitSpiInterface();

  /* Set VIO */
  (void)TLE9186_FuncLayer_set_CONFIG_SECURED(0x50);

  /* Perform the request */
  (void)TLE9186_ApplLayer_deviceDriverCyclicTask();

  while (TLE9186_ApplLayer_deviceDriverCyclicTask() ==
         TLE9186_DEVICEDRIVER_ERRORLOG_BUSY) {
    // MISRA
  }

  /* Trigger clearing all status register */
  (void)TLE9186_FuncLayer_set_PWR_MOD_CFG(0x4002u);

  /* Perform the request */
  (void)TLE9186_ApplLayer_deviceDriverCyclicTask();
  TLE9186_ServLayer_Wait_us(TLE9186_WAIT_1_MS);

  while (TLE9186_ApplLayer_deviceDriverCyclicTask() ==
         TLE9186_DEVICEDRIVER_ERRORLOG_BUSY) {
    // MISRA
  }

  /* Initialize all control registers */
  u8_initRegisterNum =
      (uint8)(sizeof(u16_initRegValueAll) / sizeof(u16_initRegValueAll[0u]));

  for (u8_initRegisterCounter = 0u; u8_initRegisterCounter < u8_initRegisterNum;
       u8_initRegisterCounter++) {
    fp_initRegTemp = fp_initRegAll[u8_initRegisterCounter];
    u16_initRegValueTemp = u16_initRegValueAll[u8_initRegisterCounter];
    fp_initRegTemp(u16_initRegValueTemp);
    (void)TLE9186_ApplLayer_deviceDriverCyclicTask();

    while (TLE9186_ApplLayer_deviceDriverCyclicTask() ==
           TLE9186_DEVICEDRIVER_ERRORLOG_BUSY) {
      // MISRA
    }

    if ((s_deviceDriver_TLE9186.u8_deviceDriverErrorLog ==
         TLE9186_DEVICEDRIVER_ERRORLOG_SPI_RECEIVE_ERR) ||
        (TLE9186->GSB.bit.LFOK == 0u)) {
      u8_success = TLE9186_ERROR;

      return u8_success;
    }
  }

  /* Initialize cyclic update */
  s_deviceDriver_TLE9186.fp_getReg = fp_cyclicStatGetFuncs[0];
  s_deviceDriver_TLE9186.fp_updateRamReg = fp_cyclicStatUpdateFuncs[0];

  /* Read out all status registers */
  for (u8_initStatUpdateCount = 0u;
       u8_initStatUpdateCount < TLE9186_DEVICEDRIVER_CYCLICSTATUPDATENUM;
       u8_initStatUpdateCount++) {
    (void)TLE9186_ApplLayer_deviceDriverCyclicTask();

    while (TLE9186_ApplLayer_deviceDriverCyclicTask() ==
           TLE9186_DEVICEDRIVER_ERRORLOG_BUSY) {
      // MISRA
    }

    if ((s_deviceDriver_TLE9186.u8_deviceDriverErrorLog ==
         TLE9186_DEVICEDRIVER_ERRORLOG_SPI_RECEIVE_ERR) ||
        (TLE9186->GSB.bit.LFOK == 0u)) {
      u8_success = TLE9186_ERROR;

      return u8_success;
    }
  }

  /* Clear status registers SPI STAT */
  (void)TLE9186_FuncLayer_set_SPI_STAT(0x8000);
  (void)TLE9186_ApplLayer_deviceDriverCyclicTask();

  while (TLE9186_ApplLayer_deviceDriverCyclicTask() ==
         TLE9186_DEVICEDRIVER_ERRORLOG_BUSY) {
    // MISRA
  }

  /* Clear status registers SUP STAT */
  (void)TLE9186_FuncLayer_set_SUP_STAT(0x81CF);
  (void)TLE9186_ApplLayer_deviceDriverCyclicTask();

  while (TLE9186_ApplLayer_deviceDriverCyclicTask() ==
         TLE9186_DEVICEDRIVER_ERRORLOG_BUSY) {
    // MISRA
  }

  /* Clear status registers DEV STAT2 */
  (void)TLE9186_FuncLayer_set_DEV_STAT2(0x7EFF);
  (void)TLE9186_ApplLayer_deviceDriverCyclicTask();

  while (TLE9186_ApplLayer_deviceDriverCyclicTask() ==
         TLE9186_DEVICEDRIVER_ERRORLOG_BUSY) {
    // MISRA
  }

  /* Clear status registers BD STAT */
  (void)TLE9186_FuncLayer_set_BD_STAT(0x6FF8);
  (void)TLE9186_ApplLayer_deviceDriverCyclicTask();

  while (TLE9186_ApplLayer_deviceDriverCyclicTask() ==
         TLE9186_DEVICEDRIVER_ERRORLOG_BUSY) {
    // MISRA
  }

  (void)TLE9186_FuncLayer_set_LF_STAT(0x23A);
  (void)TLE9186_ApplLayer_deviceDriverCyclicTask();

  while (TLE9186_ApplLayer_deviceDriverCyclicTask() ==
         TLE9186_DEVICEDRIVER_ERRORLOG_BUSY) {
    // MISRA
  }

  /* If error detected stop initialization */
  if ((TLE9186_ServLayer_GetERR_N() == 0u) &&
      (TLE9186_FuncLayer_get_DEV_STAT1_ERRN_ACT() == 0u)) {
    u8_success = TLE9186_ERROR;

    return u8_success;
  }

  /* Read out all status registers */
  for (u8_initStatUpdateCount = 0u;
       u8_initStatUpdateCount < TLE9186_DEVICEDRIVER_CYCLICSTATUPDATENUM;
       u8_initStatUpdateCount++) {
    (void)TLE9186_ApplLayer_deviceDriverCyclicTask();

    while (TLE9186_ApplLayer_deviceDriverCyclicTask() ==
           TLE9186_DEVICEDRIVER_ERRORLOG_BUSY) {
      // MISRA
    }

    if ((s_deviceDriver_TLE9186.u8_deviceDriverErrorLog ==
         TLE9186_DEVICEDRIVER_ERRORLOG_SPI_RECEIVE_ERR) ||
        (TLE9186->GSB.bit.LFOK == 0u)) {
      u8_success = TLE9186_ERROR;

      return u8_success;
    }
  }

  /* Request normal mode */
  (void)TLE9186_FuncLayer_set_PWR_MOD_CFG(0x1u);

  /* Perform the request */
  (void)TLE9186_ApplLayer_deviceDriverCyclicTask();

  while (TLE9186_ApplLayer_deviceDriverCyclicTask() ==
         TLE9186_DEVICEDRIVER_ERRORLOG_BUSY) {
    // MISRA
  }

  /* Final check for error */
  if ((s_deviceDriver_TLE9186.u8_deviceDriverErrorLog ==
       TLE9186_DEVICEDRIVER_ERRORLOG_STARTED) &&
      (TLE9186->GSB.bit.LFOK == 1u)) {
    u8_success = TLE9186_SUCCESS;
  }

  return u8_success;
}

/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */
