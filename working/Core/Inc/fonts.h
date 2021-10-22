#ifndef __FONT_H
#define __FONT_H

#include "stdint.h"

typedef struct {
    const uint8_t width;
    uint8_t height;
    const uint16_t *data;
} FontDef;

typedef struct {
    const uint8_t width;
    uint8_t height;
    const uint8_t *data;
} FontDef2;

typedef struct {
    const uint16_t width;
    uint16_t height;
    const uint32_t *data;
} FontDef1;


//Font lib.
extern FontDef Font_7x10;
extern FontDef1 Font_32x60;
extern FontDef1 Font_32x35;
extern FontDef Font_11x18;
extern FontDef Font_16x26;
extern FontDef Font_12x27;
extern FontDef Font_14x29;

//16-bit(RGB565) Image lib.
/*******************************************
 *             CAUTION:
 *   If the MCU onchip flash cannot
 *  store such huge image data,please
 *           do not use it.
 * These pics are for test purpose only.
 *******************************************/

/* 128x128 pixel RGB565 image */
extern const uint16_t btempty[][50];
extern const uint16_t lungs[][56];
extern const uint16_t lungs_75[][75];
extern const uint16_t lungs_1[][60];
extern const uint16_t unfillbattery [] [69];
extern const uint16_t  lowbattery [] [69];
extern const uint16_t  lowbattery_1 [] [69];
extern const uint16_t lowbattery_20 [] [20];

extern const uint16_t btfull[][50];
extern const uint16_t btfull_1[][69];
extern const uint16_t saber[][128];
extern const uint16_t cap150 [] [150];
extern const uint16_t cap145 [] [145];
extern const uint16_t cap160 [] [160];
extern const uint16_t cap160_1 [] [160];
extern const uint16_t bmp [] [160];
extern const uint16_t cap170 [] [170];
extern const uint16_t cap180 [] [180];
extern const uint16_t saber1[][128];
// 240x240 pixel RGB565 image
extern const uint16_t knky[][240];
extern const uint16_t tek[][240];
extern const uint16_t adi1[][240];

#endif
