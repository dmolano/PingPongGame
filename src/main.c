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
    \brief      init input port
    \param[in]  none
    \param[out] none
    \retval     none
*/
void input_port_init()
{
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_8);
}

/*!
    \brief      init longan nano
    \param[in]  lcd
    \param[out] none
    \retval     none
*/
void longan_nano_init(Lcd *lcd)
{
    rcu_init();
    
    led_init();

    input_port_init();

    lcd_init(lcd);

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
    Lcd lcd;

    longan_nano_init(&lcd);

    lcd_setpixel(lcd.width >> 2, lcd.height >> 2, 0b1111111111111111);

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