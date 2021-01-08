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

#ifndef __GD32VF103_LCD_H
#define __GD32VF103_LCD_H

#define LCD_WIDTH               160
#define LCD_HEIGHT              80
#define LCD_FRAMEBUFFER_PIXELS  (LCD_WIDTH * LCD_HEIGHT)
#define LCD_FRAMEBUFFER_BYTES   (LCD_WIDTH * LCD_HEIGHT * 2)
#define FRAME_SIZE 25600

#define USE_HORIZONTAL 2

#define HAS_BLK_CNTL 0

#define OLED_SCLK_Clr()
#define OLED_SCLK_Set()

#define OLED_SDIN_Clr()
#define OLED_SDIN_Set()

#define OLED_CS_Clr()
#define OLED_CS_Set()

#define OLED_RST_Clr() gpio_bit_reset(GPIOB, GPIO_PIN_1) //RES PB1
#define OLED_RST_Set() gpio_bit_set(GPIOB, GPIO_PIN_1)

#define OLED_DC_Clr() gpio_bit_reset(GPIOB, GPIO_PIN_0) //DC PB0
#define OLED_DC_Set() gpio_bit_set(GPIOB, GPIO_PIN_0)

#if HAS_BLK_CNTL
#define OLED_BLK_Clr() gpio_bit_reset(GPIOA, GPIO_PIN_5) //BLK
#define OLED_BLK_Set() gpio_bit_set(GPIOA, GPIO_PIN_5)
#else
#define OLED_BLK_Clr()
#define OLED_BLK_Set()
#endif

typedef enum
{
    WAIT_NONE = 0,
    WAIT_READ_U24 = 1,
    WAIT_WRITE_U24 = 2,
} LcdWaitStatus;

typedef struct
{
    LcdWaitStatus wait_status;
    uint32_t fb_address;
    int fb_enabled;
    uint32_t dma_const_value;
    uint16_t width;
    uint16_t height;
} Lcd;

/*!
    \brief      init LCD
    \param[in]  lcd: Lcd point
    \param[out] none
    \retval     none
*/
void lcd_init(Lcd *lcd);

/*!
    \brief      set command
    \param[in]  none
    \param[out] none
    \retval     none
*/
void lcd_mode_cmd();

/*!
    \brief      set command
    \param[in]  none
    \param[out] none
    \retval     none
*/
void lcd_mode_data();

#endif
