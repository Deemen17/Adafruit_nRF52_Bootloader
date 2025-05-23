/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2025 Deemen17 for DEEMEN17 WORKS
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef _DEEMEN17_DEKY65_H
#define _DEEMEN17_DEKY65_H

#define _PINNUM(port, pin)    ((port)*32 + (pin))

/*------------------------------------------------------------------*/
/* LED
 *------------------------------------------------------------------*/
#define LEDS_NUMBER           1
#define LED_PRIMARY_PIN       _PINNUM(1, 10)  // Red
#define LED_STATE_ON          0

#define LED_RGB_RED_PIN       _PINNUM(1, 10)
#define LED_RGB_GREEN_PIN     _PINNUM(1, 11)
#define LED_RGB_BLUE_PIN      _PINNUM(0,  3)
#define BOARD_RGB_BRIGHTNESS  0x404040

/*------------------------------------------------------------------*/
/* BUTTON
 *------------------------------------------------------------------*/
#define BUTTONS_NUMBER        2
#define BUTTON_1              _PINNUM(0,  6) // ESC row
#define BUTTON_2              _PINNUM(0, 28) // ESC col
#define BUTTON_PULL           NRF_GPIO_PIN_PULLUP

//--------------------------------------------------------------------+
// BLE OTA
//--------------------------------------------------------------------+
#define BLEDIS_MANUFACTURER    "DEEMEN17 WORKS"
#define BLEDIS_MODEL           "DEKY65 PCB"

//--------------------------------------------------------------------+
// USB
//--------------------------------------------------------------------+
#define USB_DESC_VID           0xDE17
#define USB_DESC_UF2_PID       0x6514
#define USB_DESC_CDC_ONLY_PID  0x6514

//--------------------------------------------------------------------+
// UF2
//--------------------------------------------------------------------+
#define UF2_PRODUCT_NAME  "DEEMEN17 DEKY65 PCB"
#define UF2_VOLUME_LABEL  "DEEMEN17 DEKY65"
#define UF2_BOARD_ID      "DEEMEN17 DEKY65"
#define UF2_INDEX_URL     "https://github.com/Deemen17"

#endif // _DEEMEN17_DEKY65_H
