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
#include "dma.h"
#include "time.h"

/*!
    \brief      send 8 bit byte to the LCD using the SPI bus
    \param[in]  none
    \param[out] none
    \retval     none
*/
void lcd_bus_write() 
{
	spi_dma_enable(SPI0, SPI_DMA_TRANSMIT);
}

/*!
    \brief      display 8 bit byte on the LCD
    \param[in]  none
    \param[out] none
    \retval     none
*/
void lcd_data8_write()
{
	OLED_DC_Set(); // set display in data mode
	lcd_bus_write();
}

/******************************************************************************
      Function description: display 16 bit word to the LCD
	  Parameter: 
        dat: word to write
      Return value: None
******************************************************************************/
void LCD_WR_DATA(u16 dat)
{
	OLED_DC_Set();//写数据 // set display in data mode
	LCD_Writ_Bus(dat>>8);
	LCD_Writ_Bus(dat);
}

/*!
    \brief      LCD init
    \param[in]  image: image point
    \param[in]  frame_size: frame size lcd
    \param[out] none
    \retval     none
*/
void lcd_init(unsigned char *image, uint32_t frame_size)
{
    rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_GPIOB);
    rcu_periph_clock_enable(RCU_DMA0);
    rcu_periph_clock_enable(RCU_SPI0);

    /* SPI0 GPIO config: NSS/PA4, SCK/PA5, MOSI/PA7 */
    gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_7);
    /* SPI0 GPIO config: MISO/PA6 */
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_6);

    dma_config(image, frame_size);

    dma_channel_enable(DMA0, DMA_CH2);
    gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_0 | GPIO_PIN_1);
    gpio_bit_reset(GPIOB, GPIO_PIN_0 | GPIO_PIN_1);

    OLED_RST_Clr();
    time_delay_1ms(200);
    OLED_RST_Set();
    time_delay_1ms(20);
    OLED_BLK_Set();

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

