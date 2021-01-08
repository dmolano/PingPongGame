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
#include "dma.h"

/*!
    \brief      configure the DMA peripheral
    \param[in]  dma_const_data_value: image point
    \param[in]  count: frame size lcd
    \param[out] none
    \retval     none
*/
void dma_send_const_u8(uint32_t *dma_const_data_value, uint32_t count)
{
    spi_wait_idle();
    lcd_mode_data();
    spi_set_8bit();
    dma_channel_disable(DMA0, DMA_CH2);
    dma_memory_width_config(DMA0, DMA_CH2, DMA_MEMORY_WIDTH_8BIT);
    dma_periph_width_config(DMA0, DMA_CH2, DMA_PERIPHERAL_WIDTH_8BIT);
    dma_memory_address_config(DMA0, DMA_CH2, dma_const_data_value);
    dma_memory_increase_disable(DMA0, DMA_CH2);
    dma_transfer_number_config(DMA0, DMA_CH2, count);
    dma_channel_enable(DMA0, DMA_CH2);
}

/*!
    \brief      configure the DMA peripheral
    \param[in]  image: image point
    \param[in]  frame_size: frame size lcd
    \param[out] none
    \retval     none
*/
void dma_send_const_u16(uint32_t *dma_const_data_value, uint32_t count)
{
    spi_wait_idle();
    lcd_mode_data();
    spi_set_16bit();
    dma_channel_disable(DMA0, DMA_CH2);
    dma_memory_width_config(DMA0, DMA_CH2, DMA_MEMORY_WIDTH_16BIT);
    dma_periph_width_config(DMA0, DMA_CH2, DMA_PERIPHERAL_WIDTH_16BIT);
    dma_memory_address_config(DMA0, DMA_CH2, dma_const_data_value);
    dma_memory_increase_disable(DMA0, DMA_CH2);
    dma_transfer_number_config(DMA0, DMA_CH2, count);
    dma_channel_enable(DMA0, DMA_CH2);
}

