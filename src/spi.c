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
#include "spi.h"

/*!
    \brief      set 8 bits
    \param[in]  none
    \param[out] none
    \retval     none
*/
void spi_set_8bit()
{
    if (SPI_CTL0(SPI0) & (uint32_t)(SPI_CTL0_FF16))
    {
        SPI_CTL0(SPI0) &= ~(uint32_t)(SPI_CTL0_SPIEN);
        // ---------------v
        SPI_CTL0(SPI0) &= ~(uint32_t)(SPI_CTL0_FF16);
        SPI_CTL0(SPI0) |= (uint32_t)(SPI_CTL0_SPIEN);
    }
}

/*!
    \brief      set 16 bits
    \param[in]  none
    \param[out] none
    \retval     none
*/
void spi_set_16bit()
{
    if (!(SPI_CTL0(SPI0) & (uint32_t)(SPI_CTL0_FF16)))
    {
        SPI_CTL0(SPI0) &= ~(uint32_t)(SPI_CTL0_SPIEN);
        SPI_CTL0(SPI0) |= (uint32_t)(SPI_CTL0_FF16);
        SPI_CTL0(SPI0) |= (uint32_t)(SPI_CTL0_SPIEN);
    }
}
