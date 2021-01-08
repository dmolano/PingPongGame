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
#include "spi.h"

/*!
    \brief      set address
    \param[in]  x: x position
    \param[in]  y: y position
    \param[in]  width: 
    \param[in]  height:
    \param[out] none
    \retval     none
*/
void lcd_set_addr(uint16_t x, uint16_t y, uint16_t width, uint16_t height)
{
    lcd_reg(ST7735S_Command_Type.CASET);
    lcd_u16(x + 1);
    lcd_u16c(x + width);
    lcd_reg(0x2b);
    lcd_u16(y + 26);
    lcd_u16c(y + height + 25);
    lcd_reg(0x2c);
}

/*!
    \brief      clear LCD
    \param[in]  lcd:
    \param[in]  color:
    \param[out] none
    \retval     none
*/
void lcd_clear(Lcd *lcd, uint16_t color)
{
    if ((lcd) && (lcd->fb_enabled == false))
    {
        lcd_wait();
        lcd_set_addr(0, 0, lcd.width, lcd.height);
        dma_send_const_u16(color, lcd.width * lcd.height);
    }
}

/*!
    \brief      disable FB LCD
    \param[in]  lcd:
    \param[out] none
    \retval     none
*/
void lcd_fb_disable(Lcd *lcd)
{
    if (lcd->fb_enabled)
    {

        // Disable and wait until handler disables the interrupt.
        lcd->fb_enabled = 0;
        while (DMA_CHCTL(DMA0, DMA_CH2) & DMA_CHXCTL_FTFIE)
            ;
    }
}

/*!
    \brief      init LCD
    \param[in]  lcd: Lcd point
    \param[out] none
    \retval     none
*/
void lcd_init(Lcd *lcd)
{
}
