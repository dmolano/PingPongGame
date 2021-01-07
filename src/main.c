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

#include "main.h"

/*!
    \brief      input_port_init function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void input_port_init()
{
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_8);
}

/*!
    \brief      longan_nano_init function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void longan_nano_init(unsigned char *image, uint32_t frame_size)
{
    led_init();

    input_port_init();

    lcd_init(image, FRAME_SIZE);

    led_red_off();
    led_green_off();
    led_blue_off();
}

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    unsigned char image[12800];

    longan_nano_init(image, FRAME_SIZE);

    while (1)
    {
        led_green_flash_times(10, 2, 100);
        time_delay_1ms(1000);
        led_red_flash_times(10, 2, 100);
        time_delay_1ms(1000);
        led_blue_flash_times(10, 2, 100);
        time_delay_1ms(1000);
    }
}