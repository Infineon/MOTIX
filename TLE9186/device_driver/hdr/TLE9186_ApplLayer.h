/**
 *	@file TLE9186_ApplLayer.h
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

#ifndef TLE9186_APPLLAYER_H
#define TLE9186_APPLLAYER_H

/************************************************************************
**                             Includes                                **
************************************************************************/

#include "TLE9186_types.h"

/************************************************************************
**                      Global Macro Definitions                       **
************************************************************************/
/**
 * @brief Indication that the initialization process is currently ongoing.
 */
#define TLE9186_DEVICEDRIVER_STATUS_INIT (0u)

/**
 * @brief Indication that the cyclic update is currently ongoing.
 */
#define TLE9186_DEVICEDRIVER_STATUS_CYCLIC_UPDATE (1u)

/**
 * @brief Indication that the error log is initialized.
 */
#define TLE9186_DEVICEDRIVER_ERRORLOG_INIT (0u)

/**
 * @brief Indication that the error log is started.
 */
#define TLE9186_DEVICEDRIVER_ERRORLOG_STARTED (1u)

/**
 * @brief Indication that the device driver is still waiting for new data.
 */
#define TLE9186_DEVICEDRIVER_ERRORLOG_BUSY (2u)

/**
 * @brief Indication that an SPI error occured (e.g. CRC mismatch).
 */
#define TLE9186_DEVICEDRIVER_ERRORLOG_SPI_RECEIVE_ERR (3u)

/**
 * @brief Number of status registers to be updated by the cyclic function.
 */
#define TLE9186_DEVICEDRIVER_CYCLICSTATUPDATENUM (23u)

/**
 * @brief Indication that new SPI data are available.
 */
#define TLE9186_DEVICEDRIVER_SPI_NEW_DATA (1u)

/************************************************************************
**                      Global Function Definitions                       **
************************************************************************/
uint8 TLE9186_ApplLayer_deviceDriverCyclicTask(void);
uint8 TLE9186_ApplLayer_deviceDriverInit(void);

/************************************************************************
**                    Global Type Definitions                          **
************************************************************************/
/**
 * @brief function pointer fp_TLE9186_setDeviceReg
 *
 * Function pointer used to write into a register
 */
typedef void (*fp_TLE9186_setDeviceReg)(uint16);

/**
 * @brief function pointer fp_TLE9186_getDeviceReg
 *
 * Function pointer to read from a register
 */
typedef void (*fp_TLE9186_getDeviceReg)(void);

/**
 * @brief function pointer fp_TLE9186_updateRamReg
 *
 * Function pointer to update the shadow register
 */
typedef void (*fp_TLE9186_updateRamReg)(uint16);

/**
 * @brief Structure representing the TLE9186 Device Driver
 *
 * Structure that holds the current status of the device driver as well as tx
 * and rx buffer
 */
typedef struct {
  uint8 u8_deviceDriverStatus;   /*!<  device driver status */
  uint8 u8_deviceDriverErrorLog; /*!<  device driver error log */
  uint8 u8_statusSPI;            /*!<  status of the SPI interface */
  uint8 u8_SpiRx[4u];            /*!<  uint8 SPI receive buffer */
  uint32 u32_SpiRx;              /*!<  uint32 SPI receive buffer */
  uint32 u32_SpiTx;              /*!<  SPI transmit buffer */
  fp_TLE9186_setDeviceReg
      fp_setReg; /*!<  function pointer to next set register function */
  fp_TLE9186_getDeviceReg
      fp_getReg; /*!<  function pointer to next get register function */
  fp_TLE9186_updateRamReg fp_updateRamReg; /*!<  function pointer to next update
                                            * RAM register function
                                            * */
  uint16
      u16_setBitValue; /*!<  value to be used in next set register function */
  uint8 u8_crcResult;  /*!< holds the CRC calculated from the uC on the received
                        * message */
  uint8 u8_prev_addr;  /*!< holds the address from the last sent frame */
} s_TLE9186_deviceDriver;
extern s_TLE9186_deviceDriver s_deviceDriver_TLE9186;

#endif /* TLE9186_APPLLAYER_H */
