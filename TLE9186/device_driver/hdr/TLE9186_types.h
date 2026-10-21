/**
 *  @file TLE9186_types.h
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

#ifndef TLE9186_TYPES_H
#define TLE9186_TYPES_H

/**
 * @defgroup types Types
 * @brief The device driver uses AUTOSAR datatypes which need to be defined.
 * This file offers the possibility of either using the platform datatypes or
 * custom data types.
 *
 */
/**
 * @addtogroup device_driver
 * @{
 */
/**
 * @addtogroup types
 * @{
 */

#define USE_AURIX 1   /**< Pre-processor macro for using AURIX datatype */
#define USE_TRAVEO 2  /**< Pre-processor macro for using TRAVEO datatype */
#define USE_GENERIC 3 /**< Pre-processor macro for using generic datatype */
#define TLE9186_USE_PLATFORM_DATA_TYPES                                        \
  USE_GENERIC /**< Pre-processor macro to select which types shall be used */

#if (TLE9186_USE_PLATFORM_DATA_TYPES == USE_AURIX)

#include "Ifx_types.h"

#elif (TLE9186_USE_PLATFORM_DATA_TYPES == USE_TRAVEO)

#include "cy_project.h"
typedef uint8_t uint8;   /**< 8 bit unsigned value  */
typedef uint16_t uint16; /**< 16 bit unsigned value */
typedef uint32_t uint32; /**< 32 bit unsigned value */
typedef uint64_t uint64; /**< 64 bit unsigned value */

#elif (TLE9186_USE_PLATFORM_DATA_TYPES == USE_GENERIC)

typedef unsigned char uint8;       /**< 8 bit unsigned value  */
typedef unsigned short uint16;     /**< 16 bit unsigned value */
typedef unsigned long uint32;      /**< 32 bit unsigned value */
typedef unsigned long long uint64; /**< 64 bit unsigned value */
#define NULL ((void *)0) /**< Null pointer */

#endif

/**
 * @}
 */
/**
 * @}
 */

#endif /* TLE9186_TYPES_H */
