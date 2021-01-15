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

typedef enum ST7735S_Command_Type
{
    NOP = 0x00,
    SWRESET = 0x01,   /* Software Reset */
    RDDID = 0x04,     /* Read Display ID */
    RDDST = 0x09,     /* Read Display Status */
    RDDPM = 0x0a,     /* Read Display Power Mode */
    RDDMADCTL = 0x0b, /* Read Display MADCTL */
    RDDCOLMOD = 0x0c, /* Read Display Pixel Format */
    RDDIM = 0x0d,     /* Read Display Image Mode */
    RDDSM = 0x0e,     /* Read Display Signal Mode */
    RDDSDR = 0x0f,    /* Read Display Self-Diagnostic Result */
    SLPIN = 0x10,     /* Sleep In */
    SLPOUT = 0x11,    /* Sleep Out */
    PTLON = 0x12,     /* Partial Display Mode On */
    NORON = 0x13,     /* Normal Display Mode On */
    INVOFF = 0x20,    /* Display Inversion Off */
    INVON = 0x21,     /* Display Inversion On */
    GAMSET = 0x26,    /* Gamma Set */
    DISPOFF = 0x28,   /* Display Off */
    DISPON = 0x29,    /* Display On */
    CASET = 0x2a,     /* Column Address Set */
    RASET = 0x2b,     /* Row Address Set */
    RAMWR = 0x2c,     /* Memory Write */
    RGBSET = 0x2d,    /* Color Setting 4k, 65k, 262k */
    RAMRD = 0x2e,     /* Memory Read */
    PTLAR = 0x30,     /* Partial Area */
    SCRLAR = 0x33,    /* Scroll Area Set */
    TEOFF = 0x34,     /* Tearing Effect Line OFF */
    TEON = 0x35,      /* Tearing Effect Line ON */
    MADCTL = 0x36,    /* Memory Data Access Control */
    VSCSAD = 0x37,    /* Vertical Scroll Start Address of RAM */
    IDMOFF = 0x38,    /* Idle Mode Off */
    IDMON = 0x39,     /* Idle Mode On */
    COLMOD = 0x3a,    /* Interface Pixel Format */
    RDID1 = 0xda,     /* Read ID1 Value */
    RDID2 = 0xdb,     /* Read ID2 Value */
    RDID3 = 0xdc,     /* Read ID3 Value */
    FRMCTR1 = 0xb1,   /* Frame Rate Control in normal mode, full colors */
    FRMCTR2 = 0xb2,   /* Frame Rate Control in idle mode, 8 colors */
    FRMCTR3 = 0xb3,   /* Frame Rate Control in partial mode, full colors */
    INVCTR = 0xb4,    /* Display Inversion Control */
    PWCTR1 = 0xc0,    /* Power Control 1 */
    PWCTR2 = 0xc1,    /* Power Control 2 */
    PWCTR3 = 0xc2,    /* Power Control 3 in normal mode, full colors */
    PWCTR4 = 0xc3,    /* Power Control 4 in idle mode 8colors */
    PWCTR5 = 0xc4,    /* Power Control 5 in partial mode, full colors */
    VMCTR1 = 0xc5,    /* VCOM Control 1 */
    VMOFCTR = 0xc7,   /* VCOM Offset Control */
    WRID2 = 0xd1,     /* Write ID2 Value */
    WRID3 = 0xd2,     /* Write ID3 Value */
    NVFCTR1 = 0xd9,   /* NVM Control Status */
    NVFCTR2 = 0xde,   /* NVM Read Command */
    NVFCTR3 = 0xdf,   /* NVM Write Command */
    GMCTRP1 = 0xe0,   /* Gamma '+'Polarity Correction Characteristics Setting */
    GMCTRN1 = 0xe1,   /* Gamma '-'Polarity Correction Characteristics Setting */
    GCV = 0xfc,       /* Gate Pump Clock Frequency Variable */
} ST7735S_Command;

/*!
    \brief      set command
    \param[in]  none
    \param[out] none
    \retval     none
*/
void lcd_mode_cmd()
{
    gpio_bit_reset(GPIOB, GPIO_PIN_0);
}

/*!
    \brief      set command
    \param[in]  none
    \param[out] none
    \retval     none
*/
void lcd_mode_data()
{
    gpio_bit_set(GPIOB, GPIO_PIN_0);
}
/*!
    \brief      set command
    \param[in]  none
    \param[out] none
    \retval     none
*/
void lcd_cs_enable()
{
    gpio_bit_reset(GPIOB, GPIO_PIN_2);
}
/*!
    \brief      set command
    \param[in]  none
    \param[out] none
    \retval     none
*/
void lcd_cs_disable()
{
    gpio_bit_set(GPIOB, GPIO_PIN_2);
}
/*!
    \brief      set command
    \param[in]  command: ST7735S command
    \param[out] none
    \retval     none
*/
void lcd_reg(ST7735S_Command command)
{
    spi_wait_idle();
    spi_set_8bit();
    lcd_mode_cmd();
    spi_i2s_data_transmit(SPI0, command);
}

/*!
    \brief      set unsigned byte data
    \param[in]  data: data
    \param[out] none
    \retval     none
*/
void lcd_u8(uint8_t data)
{
    spi_wait_idle();
    spi_set_8bit();
    lcd_mode_data();
    spi_i2s_data_transmit(SPI0, data);
}

/*!
    \brief      set unsigned byte data
    \param[in]  data: data
    \param[out] none
    \retval     none
*/
void lcd_u8c(uint8_t data)
{
    spi_wait_tbe();
    spi_i2s_data_transmit(SPI0, data);
}

/*!
    \brief      set unsigned half word data
    \param[in]  data: data
    \param[out] none
    \retval     none
*/
void lcd_u16(uint16_t data)
{
    spi_wait_idle();
    spi_set_16bit();
    lcd_mode_data();
    spi_i2s_data_transmit(SPI0, data);
}

/*!
    \brief      set unsigned half word data
    \param[in]  data: data
    \param[out] none
    \retval     none
*/
void lcd_u16c(uint16_t data)
{
    spi_wait_tbe();
    spi_i2s_data_transmit(SPI0, data);
}

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
    lcd_reg(CASET);
    lcd_u16(x + 1);
    lcd_u16c(x + width);
    lcd_reg(RASET);
    lcd_u16(y + 26);
    lcd_u16c(y + height + 25);
    lcd_reg(RAMWR);
}

/*!
    \brief      wait read u24
    \param[in]  lcd:
     \param[out] none
    \retval     none
*/
void lcd_wait_read_u24(Lcd *lcd)
{
    if (lcd)
    {
        // Poll until reception is complete.
        while (dma_transfer_number_get(DMA0, DMA_CH1))
            ;

        // Reception is complete, reconfigure SPI for sending and toggle LCD CS to stop transmission.
        dma_channel_disable(DMA0, DMA_CH1);
        spi_disable(SPI0);
        lcd_cs_disable();
        SPI_CTL0(SPI0) = (uint32_t)(SPI_MASTER | SPI_TRANSMODE_FULLDUPLEX | SPI_FRAMESIZE_8BIT | SPI_NSS_SOFT | SPI_ENDIAN_MSB | SPI_CK_PL_LOW_PH_1EDGE | SPI_PSC_8);
        SPI_CTL1(SPI0) = (uint32_t)(SPI_CTL1_DMATEN);
        lcd_cs_enable();
        spi_enable(SPI0);

        // Return to normal color mode.
        lcd_reg(COLMOD); // COLMOD
        lcd_u8(0x55);    // RGB565 (transferred as 16b)

        // Clear wait status and return.
        lcd->wait_status = WAIT_NONE;
    }
}

/*!
    \brief      wait write u24
    \param[in]  lcd:
     \param[out] none
    \retval     none
*/
void lcd_wait_write_u24(Lcd *lcd)
{
    if (lcd)
    {
        // Wait until send is complete, then restore normal color mode.
        spi_wait_idle();
        lcd_reg(COLMOD); // COLMOD
        lcd_u8(0x55);    // RGB565 (transferred as 16b)

        // Clear wait status and return.
        lcd->wait_status = WAIT_NONE;
    }
}

/*!
    \brief      wait
    \param[in]  lcd:
     \param[out] none
    \retval     none
*/
void lcd_wait(Lcd *lcd)
{
    if (lcd && !lcd->fb_enabled)
    {
        switch (lcd->wait_status)
        {
        case WAIT_READ_U24:
            lcd_wait_read_u24(lcd);
            break;
        case WAIT_WRITE_U24:
            lcd_wait_write_u24(lcd);
            break;
        default:
            // WAIT_NONE
            break;
        }
    }
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
    if (lcd && !lcd->fb_enabled)
    {
        lcd_wait(lcd);
        lcd_set_addr(0, 0, lcd->width, lcd->height);
        dma_send_const_u16((uint32_t)&color, lcd->width * lcd->height);
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

    gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_5 | GPIO_PIN_7);
    gpio_init(GPIOB, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2);
    gpio_bit_reset(GPIOB, GPIO_PIN_0 | GPIO_PIN_1); // DC=0, RST=0
    lcd_cs_disable();

    time_delay_1ms(1);
    gpio_bit_set(GPIOB, GPIO_PIN_1); // RST=1
    time_delay_1ms(5);

    // Deinit SPI and DMA.
    spi_i2s_deinit(SPI0);
    dma_deinit(DMA0, DMA_CH1);
    dma_deinit(DMA0, DMA_CH2);

    // Configure DMA, do not enable.
    DMA_CHCTL(DMA0, DMA_CH1) = (uint32_t)(DMA_PRIORITY_ULTRA_HIGH | DMA_CHXCTL_MNAGA); // Receive.
    DMA_CHCTL(DMA0, DMA_CH2) = (uint32_t)(DMA_PRIORITY_ULTRA_HIGH | DMA_CHXCTL_DIR);   // Transmit.
    DMA_CHPADDR(DMA0, DMA_CH1) = (uint32_t)&SPI_DATA(SPI0);
    DMA_CHPADDR(DMA0, DMA_CH2) = (uint32_t)&SPI_DATA(SPI0);

    // Configure and enable SPI.
    SPI_CTL0(SPI0) = (uint32_t)(SPI_MASTER | SPI_TRANSMODE_FULLDUPLEX | SPI_FRAMESIZE_8BIT | SPI_NSS_SOFT | SPI_ENDIAN_MSB | SPI_CK_PL_LOW_PH_1EDGE | SPI_PSC_8);
    SPI_CTL1(SPI0) = (uint32_t)(SPI_CTL1_DMATEN);
    spi_enable(SPI0);

    // Enable lcd controller.
    lcd_cs_enable();

    // Initialization settings. Based on lcd.c in gd32v_lcd example.
    static const uint8_t init_sequence[] =
        {
            0x21, 0xff,
            0xb1, 0x05, 0x3a, 0x3a, 0xff,
            0xb2, 0x05, 0x3a, 0x3a, 0xff,
            0xb3, 0x05, 0x3a, 0x3a, 0x05, 0x3a, 0x3a, 0xff,
            0xb4, 0x03, 0xff,
            0xc0, 0x62, 0x02, 0x04, 0xff,
            0xc1, 0xc0, 0xff,
            0xc2, 0x0d, 0x00, 0xff,
            0xc3, 0x8d, 0x6a, 0xff,
            0xc4, 0x8d, 0xee, 0xff,
            0xc5, 0x0e, 0xff,
            0xe0, 0x10, 0x0e, 0x02, 0x03, 0x0e, 0x07, 0x02, 0x07, 0x0a, 0x12, 0x27, 0x37, 0x00, 0x0d, 0x0e, 0x10, 0xff,
            0xe1, 0x10, 0x0e, 0x03, 0x03, 0x0f, 0x06, 0x02, 0x08, 0x0a, 0x13, 0x26, 0x36, 0x00, 0x0d, 0x0e, 0x10, 0xff,
            0x3a, 0x55, 0xff,
            0x36, 0x78, 0xff,
            0x29, 0xff,
            0x11, 0xff,
            0xff};

    // Initialize the display.
    for (const uint8_t *p = init_sequence; *p != 0xff; p++)
    {
        lcd_reg(*p++);
        if (*p == 0xff)
        {
            continue;
        }
        spi_wait_idle();
        lcd_mode_data();
        while (*p != 0xff)
        {
            lcd_u8c(*p++);
        }
    }

    // Clear display.
    lcd_clear(lcd, 0x0000);

    // Init internal state.
    lcd->wait_status = WAIT_NONE;
    lcd->fb_address = 0;
    lcd->fb_enabled = 0;
    lcd->width = LCD_WIDTH;
    lcd->height = LCD_HEIGHT;
}

void lcd_setpixel(Lcd *lcd, int x, int y, unsigned short int color)
{
    if (lcd->fb_enabled) {
        return;
    }

    lcd_wait(lcd);
    lcd_set_addr(x, y, 1, 1);
    lcd_u8(color >> 8);
    lcd_u8c(color);
}
