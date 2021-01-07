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

#if HAS_BLK_CNTL
#define OLED_BLK_Clr() gpio_bit_reset(GPIOA, GPIO_PIN_5) //BLK
#define OLED_BLK_Set() gpio_bit_set(GPIOA, GPIO_PIN_5)
#else
#define OLED_BLK_Clr()
#define OLED_BLK_Set()
#endif

extern unsigned char image[12800];

#endif
