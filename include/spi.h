/* 
 * This file is part of the Ping Pong Game.
 * Copyright (c) 2021 Dionisio Molano Robledo.
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#include "gd32vf103.h"

#ifndef __GD32VF103_SPI_H
#define __GD32VF103_SPI_H

/*!
    \brief      set 8 bits
    \param[in]  none
    \param[out] none
    \retval     none
*/
void spi_wait_idle();

/*!
    \brief      set 8 bits
    \param[in]  none
    \param[out] none
    \retval     none
*/
void spi_wait_tbe();

/*!
    \brief      set 8 bits
    \param[in]  none
    \param[out] none
    \retval     none
*/
void spi_wait_rbne();

/*!
    \brief      set 8 bits
    \param[in]  none
    \param[out] none
    \retval     none
*/
void spi_set_8bit();

/*!
    \brief      set 16 bits
    \param[in]  none
    \param[out] none
    \retval     none
*/
void spi_set_16bit();

#endif