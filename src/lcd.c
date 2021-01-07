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

#include "lcd.h"

/*!
    \brief      configure the DMA peripheral
    \param[in]  none
    \param[out] none
    \retval     none
*/
void dma_config(void)
{
    dma_parameter_struct dma_init_struct;

    /* SPI0 transmit dma config:DMA0,DMA_CH2 */
    dma_deinit(DMA0, DMA_CH2);
    dma_struct_para_init(&dma_init_struct);

    dma_init_struct.periph_addr = (uint32_t)&SPI_DATA(SPI0);
    dma_init_struct.memory_addr = (uint32_t)image;
    dma_init_struct.direction = DMA_MEMORY_TO_PERIPHERAL;
    dma_init_struct.memory_width = DMA_MEMORY_WIDTH_8BIT;
    dma_init_struct.periph_width = DMA_PERIPHERAL_WIDTH_8BIT;
    dma_init_struct.priority = DMA_PRIORITY_LOW;
    dma_init_struct.number = FRAME_SIZE;
    dma_init_struct.periph_inc = DMA_PERIPH_INCREASE_DISABLE;
    dma_init_struct.memory_inc = DMA_MEMORY_INCREASE_ENABLE;
    dma_init(DMA0, DMA_CH2, &dma_init_struct);
    /* configure DMA mode */
    dma_circulation_disable(DMA0, DMA_CH2);
    dma_memory_to_memory_disable(DMA0, DMA_CH2);
}

/*!
    \brief      LCD init
    \param[in]  none
    \param[out] none
    \retval     none
*/
void lcd_init()
{
    // rcu_periph_clock_enable(RCU_GPIOA);
    // rcu_periph_clock_enable(RCU_GPIOB);
    // rcu_periph_clock_enable(RCU_DMA0);
    // rcu_periph_clock_enable(RCU_SPI0);

    // /* SPI0 GPIO config: NSS/PA4, SCK/PA5, MOSI/PA7 */
    // gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_7);
    // /* SPI0 GPIO config: MISO/PA6 */
    // gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_6);

    // dma_config();

    // dma_channel_enable(DMA0, DMA_CH2);
    // gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_0 | GPIO_PIN_1);
    // gpio_bit_reset(GPIOB, GPIO_PIN_0 | GPIO_PIN_1);

    // OLED_RST_Clr();
    // delay_1ms(200);
    // OLED_RST_Set();
    // delay_1ms(20);
    // OLED_BLK_Set();

    // LCD_WR_REG(0x11); // turn off sleep mode
    // delay_1ms(100);

    // LCD_WR_REG(0x21); // display inversion mode

    // LCD_WR_REG(0xB1);   // Set the frame frequency of the full colors normal mode
    //                     // Frame rate=fosc/((RTNA x 2 + 40) x (LINE + FPA + BPA +2))
    //                     // fosc = 850kHz
    // LCD_WR_DATA8(0x05); // RTNA
    // LCD_WR_DATA8(0x3A); // FPA
    // LCD_WR_DATA8(0x3A); // BPA

    // LCD_WR_REG(0xB2);   // Set the frame frequency of the Idle mode
    //                     // Frame rate=fosc/((RTNB x 2 + 40) x (LINE + FPB + BPB +2))
    //                     // fosc = 850kHz
    // LCD_WR_DATA8(0x05); // RTNB
    // LCD_WR_DATA8(0x3A); // FPB
    // LCD_WR_DATA8(0x3A); // BPB

    // LCD_WR_REG(0xB3); // Set the frame frequency of the Partial mode/ full colors
    // LCD_WR_DATA8(0x05);
    // LCD_WR_DATA8(0x3A);
    // LCD_WR_DATA8(0x3A);
    // LCD_WR_DATA8(0x05);
    // LCD_WR_DATA8(0x3A);
    // LCD_WR_DATA8(0x3A);

    // LCD_WR_REG(0xB4);
    // LCD_WR_DATA8(0x03);

    // LCD_WR_REG(0xC0);
    // LCD_WR_DATA8(0x62);
    // LCD_WR_DATA8(0x02);
    // LCD_WR_DATA8(0x04);

    // LCD_WR_REG(0xC1);
    // LCD_WR_DATA8(0xC0);

    // LCD_WR_REG(0xC2);
    // LCD_WR_DATA8(0x0D);
    // LCD_WR_DATA8(0x00);

    // LCD_WR_REG(0xC3);
    // LCD_WR_DATA8(0x8D);
    // LCD_WR_DATA8(0x6A);

    // LCD_WR_REG(0xC4);
    // LCD_WR_DATA8(0x8D);
    // LCD_WR_DATA8(0xEE);

    // LCD_WR_REG(0xC5); /*VCOM*/
    // LCD_WR_DATA8(0x0E);

    // LCD_WR_REG(0xE0);
    // LCD_WR_DATA8(0x10);
    // LCD_WR_DATA8(0x0E);
    // LCD_WR_DATA8(0x02);
    // LCD_WR_DATA8(0x03);
    // LCD_WR_DATA8(0x0E);
    // LCD_WR_DATA8(0x07);
    // LCD_WR_DATA8(0x02);
    // LCD_WR_DATA8(0x07);
    // LCD_WR_DATA8(0x0A);
    // LCD_WR_DATA8(0x12);
    // LCD_WR_DATA8(0x27);
    // LCD_WR_DATA8(0x37);
    // LCD_WR_DATA8(0x00);
    // LCD_WR_DATA8(0x0D);
    // LCD_WR_DATA8(0x0E);
    // LCD_WR_DATA8(0x10);

    // LCD_WR_REG(0xE1);
    // LCD_WR_DATA8(0x10);
    // LCD_WR_DATA8(0x0E);
    // LCD_WR_DATA8(0x03);
    // LCD_WR_DATA8(0x03);
    // LCD_WR_DATA8(0x0F);
    // LCD_WR_DATA8(0x06);
    // LCD_WR_DATA8(0x02);
    // LCD_WR_DATA8(0x08);
    // LCD_WR_DATA8(0x0A);
    // LCD_WR_DATA8(0x13);
    // LCD_WR_DATA8(0x26);
    // LCD_WR_DATA8(0x36);
    // LCD_WR_DATA8(0x00);
    // LCD_WR_DATA8(0x0D);
    // LCD_WR_DATA8(0x0E);
    // LCD_WR_DATA8(0x10);

    // LCD_WR_REG(0x3A);   // define the format of RGB picture data
    // LCD_WR_DATA8(0x05); // 16-bit/pixel

    // LCD_WR_REG(0x36);
    // if (USE_HORIZONTAL == 0)
    // {
    //     LCD_WR_DATA8(0x08);
    // }
    // else if (USE_HORIZONTAL == 1)
    // {
    //     LCD_WR_DATA8(0xC8);
    // }
    // else if (USE_HORIZONTAL == 2)
    // {
    //     LCD_WR_DATA8(0x78);
    // }
    // else
    // {
    //     LCD_WR_DATA8(0xA8);
    // }

    // LCD_WR_REG(0x29); // Display On
}
