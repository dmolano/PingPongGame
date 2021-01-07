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
    \brief      delay a time in milliseconds
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void delay_1ms(uint32_t count)
{
    uint64_t start_mtime, delta_mtime;

    // Don't start measuruing until we see an mtime tick
    uint64_t tmp = get_timer_value();
    do
    {
        start_mtime = get_timer_value();
    } while (start_mtime == tmp);

    do
    {
        delta_mtime = get_timer_value() - start_mtime;
    } while (delta_mtime < (SystemCoreClock / 4000.0 * count));
}

/*!
    \brief      led_init function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void led_init()
{
    /* enable the led clock */
    rcu_periph_clock_enable(RCU_GPIOC);
    rcu_periph_clock_enable(RCU_GPIOA);

    /* configure led GPIO port */
    gpio_init(GPIOC, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_13);
    gpio_init(GPIOA, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_1);
    gpio_init(GPIOA, GPIO_MODE_OUT_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_2);

    GPIO_BOP(GPIOC) = GPIO_PIN_13;
    GPIO_BOP(GPIOA) = GPIO_PIN_1;
    GPIO_BOP(GPIOA) = GPIO_PIN_2;
}

/*!
    Turn on the red part of the RGB LED
    by clearing PC13
*/
void red_on()
{
    GPIO_BC(GPIOC) = GPIO_PIN_13;
}
/*!
    Turn off the red part of the RGB LED
    by setting PC13
*/
void red_off()
{
    GPIO_BOP(GPIOC) = GPIO_PIN_13;
}
/*!
    Turn on the red part of the RGB LED
    by clearing PC13
*/
void red_flash(uint32_t count)
{
    red_on();
    delay_1ms(count);
    red_off();
}
/*!
    Turn on the blue part of the RGB LED
    by clearing PA1
*/
void green_on()
{
    GPIO_BC(GPIOA) = GPIO_PIN_1;
}
/*!
    Turn off the green part of the RGB LED
    by setting PA1
*/
void green_off()
{
    GPIO_BOP(GPIOA) = GPIO_PIN_1;
}
/*!
    Turn on the green part of the RGB LED
    by clearing PA1
*/
void green_flash(uint32_t count)
{
    green_on();
    delay_1ms(count);
    green_off();
}
/*!
    Turn on the blue part of the RGB LED
    by clearing PA2
*/
void blue_on()
{
    GPIO_BC(GPIOA) = GPIO_PIN_2;
}
/*!
    Turn off the blue part of the RGB LED
    by setting PA2
*/
void blue_off()
{
    GPIO_BOP(GPIOA) = GPIO_PIN_2;
}
/*!
    Turn on the blue part of the RGB LED
    by clearing PA1
*/
void blue_flash(uint32_t count)
{
    blue_on();
    delay_1ms(count);
    blue_off();
}

/*!
    \brief      input_port_ini function
    \param[in]  none
    \param[out] none
    \retval     none
*/
void input_port_ini() {
	gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_8);
}

/*!
    \brief      main function
    \param[in]  none
    \param[out] none
    \retval     none
*/
int main(void)
{
    led_init();
    red_off();
    green_off();
    blue_off();

    input_port_ini();

    lcd_init();

    while (1)
    {
        green_flash(10);
        delay_1ms(1000);
        blue_flash(10);
        delay_1ms(1000);
        red_flash(10);
        delay_1ms(1000);
    }
}