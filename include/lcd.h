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

typedef enum ST7735S_Command_Type {
    NOP       = 0x00,
              SWRESET   = 0x01, /* Software Reset */
              RDDID     = 0x04, /* Read Display ID */
              RDDST     = 0x09, /* Read Display Status */
              RDDPM     = 0x0a, /* Read Display Power Mode */
              RDDMADCTL = 0x0b, /* Read Display MADCTL */
              RDDCOLMOD = 0x0c, /* Read Display Pixel Format */
              RDDIM     = 0x0d, /* Read Display Image Mode */
              RDDSM     = 0x0e, /* Read Display Signal Mode */
              RDDSDR    = 0x0f, /* Read Display Self-Diagnostic Result */
              SLPIN     = 0x10, /* Sleep In */
              SLPOUT    = 0x11, /* Sleep Out */
              PTLON     = 0x12, /* Partial Display Mode On */
              NORON     = 0x13, /* Normal Display Mode On */
              INVOFF    = 0x20, /* Display Inversion Off */
              INVON     = 0x21, /* Display Inversion On */
              GAMSET    = 0x26, /* Gamma Set */
              DISPOFF   = 0x28, /* Display Off */
              DISPON    = 0x29, /* Display On */
              CASET     = 0x2a, /* Column Address Set */
              RASET     = 0x2b, /* Row Address Set */
              RAMWR     = 0x2c, /* Memory Write */
              RGBSET    = 0x2d, /* Color Setting 4k, 65k, 262k */
              RAMRD     = 0x2e, /* Memory Read */
              PTLAR     = 0x30, /* Partial Area */
              SCRLAR    = 0x33, /* Scroll Area Set */
              TEOFF     = 0x34, /* Tearing Effect Line OFF */
              TEON      = 0x35, /* Tearing Effect Line ON */
              MADCTL    = 0x36, /* Memory Data Access Control */
              VSCSAD    = 0x37, /* Vertical Scroll Start Address of RAM */
              IDMOFF    = 0x38, /* Idle Mode Off */
              IDMON     = 0x39, /* Idle Mode On */
              COLMOD    = 0x3a, /* Interface Pixel Format */
              RDID1     = 0xda, /* Read ID1 Value */
              RDID2     = 0xdb, /* Read ID2 Value */
              RDID3     = 0xdc, /* Read ID3 Value */
              FRMCTR1   = 0xb1, /* Frame Rate Control in normal mode, full colors */
              FRMCTR2   = 0xb2, /* Frame Rate Control in idle mode, 8 colors */
              FRMCTR3   = 0xb3, /* Frame Rate Control in partial mode, full colors */
              INVCTR    = 0xb4, /* Display Inversion Control */
              PWCTR1    = 0xc0, /* Power Control 1 */
              PWCTR2    = 0xc1, /* Power Control 2 */
              PWCTR3    = 0xc2, /* Power Control 3 in normal mode, full colors */
              PWCTR4    = 0xc3, /* Power Control 4 in idle mode 8colors */
              PWCTR5    = 0xc4, /* Power Control 5 in partial mode, full colors */
              VMCTR1    = 0xc5, /* VCOM Control 1 */
              VMOFCTR   = 0xc7, /* VCOM Offset Control */
              WRID2     = 0xd1, /* Write ID2 Value */
              WRID3     = 0xd2, /* Write ID3 Value */
              NVFCTR1   = 0xd9, /* NVM Control Status */
              NVFCTR2   = 0xde, /* NVM Read Command */
              NVFCTR3   = 0xdf, /* NVM Write Command */
              GMCTRP1   = 0xe0, /* Gamma '+'Polarity Correction Characteristics Setting */
              GMCTRN1   = 0xe1, /* Gamma '-'Polarity Correction Characteristics Setting */
              GCV       = 0xfc, /* Gate Pump Clock Frequency Variable */
} ST7735S_Command;

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

#endif
