/**
 *	@file TLE9186.c
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
/************************************************************************
**                             Includes                                **
************************************************************************/

#include "TLE9186.h"

/************************************************************************
**                    Global Variable Definitions                      **
************************************************************************/
/**
 * @addtogroup device_driver
 * @{
 */
/**
 * @addtogroup shadowRegs
 * @{
 */
static TLE9186_Type
    TLE9186_ram_copy; /*!< Instantiation of the Register Shadow */
TLE9186_Type *TLE9186 =
    &TLE9186_ram_copy; /*!< Pointer to the Register Shadow */

/**
 * @}
 */
/**
 * @}
 */
