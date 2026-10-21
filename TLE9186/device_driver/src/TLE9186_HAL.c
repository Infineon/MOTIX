/**
 *  @file TLE9186_HAL.c
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
/**
 * @defgroup hal Hardware Abstraction Layer
 * @brief The Hardware Abstraction Layer offers platform depended functionality
 * to the device driver. These functions are used by the @ref servLayer and the
 * @ref applLayer.
 *
 * @defgroup spi_hal SPI Hardware Abstraction Layer
 * @brief The SPI interface needs an initialization routine that initializes the
 * SPI peripheral. It also needs a status routine that returns the current
 * status of the SPI interface.
 *
 * @defgroup gpio_hal GPIO Hardware Abstraction Layer
 * @brief The microcontroller needs to be able to control one GPIO pin that
 * connects to the INH_N pin of the device.
 *
 */
/************************************************************************
**                             Includes                                **
************************************************************************/

#include "TLE9186_HAL.h"

/**
 * @addtogroup device_driver
 * @{
 */
/**
 * @addtogroup hal
 * @{
 */
/**
 * @addtogroup spi_hal
 * @{
 */
/************************************************************************
**                    Global Function Definitions                      **
************************************************************************/
/**
 * @brief Initialize the SPI Peripheral
 *
 * This function calls the microcontroller's SPI initialize function.
 *
 */
void TLE9186_HAL_InitSpiPeripheral(void) {
  /* Call here a function that initializes the SPI peripheral */
}

/**
 * @brief Read the SPI RX buffer
 *
 * This function reads the RX buffer of the SPI peripheral.
 *
 * @param u32_rxBuffer pointer to a 32bit variable to store the received data
 *
 */
void TLE9186_HAL_ReadRxBuffer(uint32 *u32_rxBuffer) {
  /* Read data from the receive buffer */
}

/**
 * @brief Transmit the Tx buffer
 *
 * This function transmits the tx-buffer via SPI.
 *
 * @param u32_txBuffer Value to be transmitted via SPI.
 *
 */
void TLE9186_HAL_TransmitTxBuffer(uint32 u32_txBuffer) {
  /* Transmit the u32_txBuffer via SPI */
}

/**
 * @brief Get the status of the SPI interface.
 *
 * This function returns the status of the SPI interface.
 *
 * @return Returns a 0 if the interface is busy and 1 if it is not busy.
 *
 */
uint8 TLE9186_HAL_SpiStatus(void) {
  /* Read the status of the SPI peripheral */
  uint8 u8_status = 0u;

  return u8_status;
}

/**
 * @} spi_hal
 */
/**
 * @addtogroup gpio_hal
 * @{
 */
/**
 * @brief Initialize INH_N pin
 *
 * This function initializes the GPIO pin that connects to the INH_N pin.
 *
 */
void TLE9186_HAL_Init_INH_N_pin(void) {
  /* Initialize the GPIO pin that connects to the INH_N pin */
}

/**
 * @brief Set INH_N pin
 *
 * This function sets the GPIO pin that connects to the INH_N pin.
 *
 * @param u8_state state of the INH_N pin. Valid values are:
 *  - 0: low - set the INH_N pin to logical low.
 *  - 1: high - set the INH_N pin to logical high.
 *
 */
void TLE9186_HAL_Set_INH_N_pin(uint8 u8_state) {
  /* Setting the INH_N pin */
  if (u8_state == 1u) {

  } else {
  }
}

/**
 * @brief Initialize ERR_N pin
 *
 * This function initializes the GPIO pin that connects to the ERR_N pin as
 * input.
 *
 */
void TLE9186_HAL_Init_ERR_N_pin(void) {
  /* Initialize the GPIO pin that connects to the ERR_N pin */
}

/**
 * @brief Read the ERR_N pin
 *
 * This function reads the GPIO pin that connects to the ERR_N pin.
 *
 * @return State of the ERR_N pin. Valid values are:
 *  - 0: ERR_N pin logical low
 *  - 1: ERR_N pin logical high
 *
 */
uint8 TLE9186_HAL_Get_ERR_N_pin(void) {
  uint8 u8_err_n_status;
  u8_err_n_status = 0u;

  /* Read ERR_N pin and store on u8_err_n_status */

  return u8_err_n_status;
}

/**
 * @brief Wait for given time in us
 *
 * This function pauses the execution of the code for a given time in
 * microseconds.
 *
 * @param u8_wait time in us that has to be waited.
 *
 */
void TLE9186_HAL_Wait_us(uint16 u16_wait) { /* Waiting for given time in us */ }

/**
 * @}
 */
/**
 * @}
 */
/**
 * @}
 */
