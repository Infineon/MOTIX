/**
 *	@file TLE9186_ServLayer.c
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
 * @defgroup servLayer Service Layer
 * @brief The Service Layer is in charge of generating correct MOSI frames based
 *on the information received from the
 *@ref regLayer. While doing so it calculates the CRC checksum.
 *
 * @defgroup spi_com SPI Communication
 * @brief The generated frames are transmitted via SPI to the device.
 *
 * @defgroup frameGen Frame Generation
 * @brief The frame generation takes care of building-up frames as requested by
 *the functions defined in the @ref funcLayer.
 *
 * @defgroup crcCalc CRC8 Calculation
 * @brief Each frame includes a CRC8 checksum that is based on the SAE-J1850
 *standard.
 *
 */
/************************************************************************
**                             Includes                                **
************************************************************************/
#include "TLE9186_ServLayer.h"
#include "TLE9186_ApplLayer.h"
#include "TLE9186_HAL.h"

/**
 * @addtogroup device_driver
 * @{
 */
/**
 * @addtogroup servLayer
 * @{
 */
/************************************************************************
**                    Global Variable Definitions                      **
************************************************************************/
/**
 * @brief Global 8 bit unsigned integer buffer for the CRC data
 */
static uint8 u8_crcInBuffer[4];

/* CRC8 lookup table */
static const uint8 TLE9186_LOOKUP_CRC8_SAE_J1850[256] = {
    0x00, 0x1D, 0x3A, 0x27, 0x74, 0x69, 0x4E, 0x53, 0xE8, 0xF5, 0xD2, 0xCF,
    0x9C, 0x81, 0xA6, 0xBB, 0xCD, 0xD0, 0xF7, 0xEA, 0xB9, 0xA4, 0x83, 0x9E,
    0x25, 0x38, 0x1F, 0x02, 0x51, 0x4C, 0x6B, 0x76, 0x87, 0x9A, 0xBD, 0xA0,
    0xF3, 0xEE, 0xC9, 0xD4, 0x6F, 0x72, 0x55, 0x48, 0x1B, 0x06, 0x21, 0x3C,
    0x4A, 0x57, 0x70, 0x6D, 0x3E, 0x23, 0x04, 0x19, 0xA2, 0xBF, 0x98, 0x85,
    0xD6, 0xCB, 0xEC, 0xF1, 0x13, 0x0E, 0x29, 0x34, 0x67, 0x7A, 0x5D, 0x40,
    0xFB, 0xE6, 0xC1, 0xDC, 0x8F, 0x92, 0xB5, 0xA8, 0xDE, 0xC3, 0xE4, 0xF9,
    0xAA, 0xB7, 0x90, 0x8D, 0x36, 0x2B, 0x0C, 0x11, 0x42, 0x5F, 0x78, 0x65,
    0x94, 0x89, 0xAE, 0xB3, 0xE0, 0xFD, 0xDA, 0xC7, 0x7C, 0x61, 0x46, 0x5B,
    0x08, 0x15, 0x32, 0x2F, 0x59, 0x44, 0x63, 0x7E, 0x2D, 0x30, 0x17, 0x0A,
    0xB1, 0xAC, 0x8B, 0x96, 0xC5, 0xD8, 0xFF, 0xE2, 0x26, 0x3B, 0x1C, 0x01,
    0x52, 0x4F, 0x68, 0x75, 0xCE, 0xD3, 0xF4, 0xE9, 0xBA, 0xA7, 0x80, 0x9D,
    0xEB, 0xF6, 0xD1, 0xCC, 0x9F, 0x82, 0xA5, 0xB8, 0x03, 0x1E, 0x39, 0x24,
    0x77, 0x6A, 0x4D, 0x50, 0xA1, 0xBC, 0x9B, 0x86, 0xD5, 0xC8, 0xEF, 0xF2,
    0x49, 0x54, 0x73, 0x6E, 0x3D, 0x20, 0x07, 0x1A, 0x6C, 0x71, 0x56, 0x4B,
    0x18, 0x05, 0x22, 0x3F, 0x84, 0x99, 0xBE, 0xA3, 0xF0, 0xED, 0xCA, 0xD7,
    0x35, 0x28, 0x0F, 0x12, 0x41, 0x5C, 0x7B, 0x66, 0xDD, 0xC0, 0xE7, 0xFA,
    0xA9, 0xB4, 0x93, 0x8E, 0xF8, 0xE5, 0xC2, 0xDF, 0x8C, 0x91, 0xB6, 0xAB,
    0x10, 0x0D, 0x2A, 0x37, 0x64, 0x79, 0x5E, 0x43, 0xB2, 0xAF, 0x88, 0x95,
    0xC6, 0xDB, 0xFC, 0xE1, 0x5A, 0x47, 0x60, 0x7D, 0x2E, 0x33, 0x14, 0x09,
    0x7F, 0x62, 0x45, 0x58, 0x0B, 0x16, 0x31, 0x2C, 0x97, 0x8A, 0xAD, 0xB0,
    0xE3, 0xFE, 0xD9, 0xC4};
extern s_TLE9186_deviceDriver
    s_deviceDriver_TLE9186; /* polyspace MISRA2012:8.5 [Justified: Low] "Given
                             * by architecture" */
/************************************************************************
**                    Local Function Definitions                      **
************************************************************************/
static uint8 TLE9186_ServLayer_calcCrc8(uint8 *data_array, uint8 data_len);
static void TLE9186_ServLayer_ReadSpiRxBuffer(void);

/************************************************************************
**                    Global Function Definitions                      **
************************************************************************/
/**
 * @addtogroup spi_com
 * @{
 */
/**
 * @brief Initialize the SPI interface of the microcontroller
 *
 *  Within this function the microcontroller specific initialization for the SPI
 * interface can either be implemented or called.
 *
 */
void TLE9186_ServLayer_InitSpiInterface(void) {
  /* Call SPI Init function here */
  TLE9186_HAL_InitSpiPeripheral();
}

/**
 * @brief Read out the SPI RX buffer of the microcontroller
 *
 *  Within this function the microcontroller specific SPI buffer read out
 * function can be either implemented or called.
 *
 */
static void TLE9186_ServLayer_ReadSpiRxBuffer(void) {
  /* Call SPI Read function here and write into rxBuffer */
  TLE9186_HAL_ReadRxBuffer(&s_deviceDriver_TLE9186.u32_SpiRx);
}

/**
 * @brief Get the Status of the SPI interface
 *
 *  Within this function the microcontroller specific SPI status function has to
 * be implemented or called. The result has to be written to
 * s_deviceDriver.u8_statusSPI.
 *
 */
void TLE9186_ServLayer_SpiInterfaceStatus(void) {
  /* Call SPI status function here */
  s_deviceDriver_TLE9186.u8_statusSPI = TLE9186_HAL_SpiStatus();
}

/**
 * @brief Sends data via the microcontroller's SPI interface
 *
 *  Within this function the microcontroller specific SPI TX function has to be
 * called or implemented. The transmit function has to transmit the variable
 * u32_txBuffer that contains the SPI message.
 *
 */
static void TLE9186_ServLayer_SendSpiData(void) {
  /* Call SPI send function here */
  TLE9186_HAL_TransmitTxBuffer(s_deviceDriver_TLE9186.u32_SpiTx);
}

/**
 * @brief Get SPI data from the buffer
 *
 * This function reads the data from the SPI buffer into the global buffer for
 * further processing. It additionally calculates the CRC checksum of the
 * incoming frame.
 *
 */
void TLE9186_ServLayer_getSpiData(void) {
  TLE9186_ServLayer_ReadSpiRxBuffer();
  s_deviceDriver_TLE9186.u8_SpiRx[3u] =
      ((uint8)((uint8)(s_deviceDriver_TLE9186.u32_SpiRx >> 24u)) & 0xFFu);
  s_deviceDriver_TLE9186.u8_SpiRx[2u] =
      ((uint8)((uint8)(s_deviceDriver_TLE9186.u32_SpiRx >> 16u)) & 0xFFu);
  s_deviceDriver_TLE9186.u8_SpiRx[1u] =
      ((uint8)((uint8)(s_deviceDriver_TLE9186.u32_SpiRx >> 8u)) & 0xFFu);
  s_deviceDriver_TLE9186.u8_SpiRx[0u] =
      ((uint8)((uint8)(s_deviceDriver_TLE9186.u32_SpiRx)) & 0xFFu);
  u8_crcInBuffer[0] = (uint8)(s_deviceDriver_TLE9186.u8_prev_addr & 0x7Fu);
  u8_crcInBuffer[1] = s_deviceDriver_TLE9186.u8_SpiRx[3u];
  u8_crcInBuffer[2] = s_deviceDriver_TLE9186.u8_SpiRx[2u];
  u8_crcInBuffer[3] = s_deviceDriver_TLE9186.u8_SpiRx[1u];
  s_deviceDriver_TLE9186.u8_crcResult =
      TLE9186_ServLayer_calcCrc8(u8_crcInBuffer, 4u);
}

/**
 * @} spi_com
 */
/**
 * @brief Initialize GPIOs
 *
 * This function initializes the GPIO pin used for the INH_N.
 *
 */
void TLE9186_ServLayer_InitGpio(void) {
  TLE9186_HAL_Init_INH_N_pin();
  TLE9186_HAL_Init_ERR_N_pin();
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
void TLE9186_ServLayer_SetINH_N(uint8 u8_state) {
  TLE9186_HAL_Set_INH_N_pin(u8_state);
}

/**
 * @brief Status of ERR_N pin
 *
 * This function returns the state of the ERR_N pin that indicates if an error
 * is present or not.
 *
 * @return State of the ERR_N pin. Valid values are:
 *      - 0: ERR_N pin logical low, error detected.
 *      - 1: ERR_N pin logical high, no error detected.
 *
 */
uint8 TLE9186_ServLayer_GetERR_N(void) { return TLE9186_HAL_Get_ERR_N_pin(); }

/**
 * @brief Wait for given time in us
 *
 * This function sets the GPIO pin that connects to the INH_N pin.
 *
 * @param u16_wait time in us that has to be waited.
 *
 */
void TLE9186_ServLayer_Wait_us(uint16 u16_wait) {
  /* Waiting for given time in us */
  TLE9186_HAL_Wait_us(u16_wait);
}

/**
 * @addtogroup frameGen
 * @{
 */
/**
 * @brief Prepare a set-Register message and calls the corresponding
 * microcontroller SPI send function
 *
 *  Forming an SPI frame for writing to a register and calculation of the
 * corresponding CRC checksum.
 *
 *  @param u8_address address of the register to be written
 *  @param u16_data data to be written
 *
 *  @return void
 */
void TLE9186_ServLayer_setReg(uint8 u8_address, uint16 u16_data) {
  /* CRC data preparation */
  u8_crcInBuffer[0u] = ((uint8)(u8_address << 1u)) | TLE9186_SPI_WRITE;
  u8_crcInBuffer[1u] = (uint8)(u16_data >> 8u);
  u8_crcInBuffer[2u] = (uint8)(u16_data & 0x00FFu);
  u8_crcInBuffer[3u] = TLE9186_ServLayer_calcCrc8(u8_crcInBuffer, 3u);

  /* TX buffer preparation */
  s_deviceDriver_TLE9186.u32_SpiTx =
      (uint32)((((uint32)u8_address) << 25u) |
               ((uint32)TLE9186_SPI_WRITE << 24u) |
               (uint32)(((uint32)u16_data) << 8u) | u8_crcInBuffer[3]);

  /* Store address for MISO frame CRC calculation */
  s_deviceDriver_TLE9186.u8_prev_addr = u8_address;

  /* Trigger SPI transmission */
  TLE9186_ServLayer_SendSpiData();
}

/**
 *  @brief Prepare a get-Register message and calls the corresponding
 * microcontroller SPI send function
 *
 *  Forming an SPI frame for reading out a register and calculation of the
 * corresponding CRC checksum.
 *
 *  @param u8_address address of the register to be read out
 *
 *  @return void
 *
 */
void TLE9186_ServLayer_getReg(uint8 u8_address) {
  /* CRC data preparation */
  u8_crcInBuffer[0u] = ((uint8)(u8_address << 1u)) | TLE9186_SPI_READ;
  u8_crcInBuffer[1u] = 0u;
  u8_crcInBuffer[2u] = 0u;
  u8_crcInBuffer[3u] = TLE9186_ServLayer_calcCrc8(u8_crcInBuffer, 3u);

  /* TX buffer preparation */
  s_deviceDriver_TLE9186.u32_SpiTx =
      (uint32)((((uint32)u8_address) << 25u) | (TLE9186_SPI_READ << 24u) |
               u8_crcInBuffer[3]);

  /* Store address for MISO frame CRC calculation */
  s_deviceDriver_TLE9186.u8_prev_addr = u8_address;

  /* Trigger SPI transmission */
  TLE9186_ServLayer_SendSpiData();
}

/**
 * @} frameGen
 */
/**
 * @addtogroup crcCalc
 * @{
 */
/**
 * @brief Calculate CRC8
 *
 * This functions calculates the CRC8 based on the 8-SAE J1850 algorithm.
 * Here the possibility of using a lookup table or calculation variant is
 * provided.
 *
 * @param[in] uint8* pointer to data_array
 * @param[in] uint8 length of data array [0 ... 255]
 *
 * @return uint8 calculated CRC8 [0 ... 255]
 */
static uint8 TLE9186_ServLayer_calcCrc8(
    uint8 *data_array, uint8 data_len) /* polyspace MISRA2012:8.13 [Justified:
                                        * Low] "const not possible" */
{
  uint8 crc = TLE9186_CRC8_CALC_SEED;
  uint8 index = 0;
#if (TLE9186_CRC8_CONF_ALGORITHM == TLE9186_CRC8_USE_LUT)

  /* CRC-8-SAE J1850 algorithm */
  /* all elements of the data array */
  for (index = 0; index < data_len; index++) {
    /* use data bytes */
    crc = TLE9186_LOOKUP_CRC8_SAE_J1850[crc ^ data_array[index]];
  }

#elif (TLE9186_CRC8_CONF_ALGORITHM == TLE9186_CRC8_USE_CALC)
  uint8 bit = 0U;

  /* CRC-8-SAE J1850 algorithm */
  /* all elements of the data array */
  for (index = 0; index < data_len; index++) {
    /* use data bytes */
    crc ^= data_array[index];

    for (bit = 0; bit < 8; bit++) {
      if ((crc & 0x80U) != 0U) {
        crc <<= 1U;
        crc ^= TLE9186_CRC8_CALC_GENERATOR_POLYNOM;
      } else {
        crc <<= 1U;
      }
    }
  }

#endif
  crc = crc ^ TLE9186_CRC8_CALC_XOR_VAL;

  return crc;
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
