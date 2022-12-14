#pragma once

#define BLACK           0x0000      /*   0,   0,   0 */
#define NAVY            0x000F      /*   0,   0, 128 */
#define DGREEN          0x03E0      /*   0, 128,   0 */
#define DCYAN           0x03EF      /*   0, 128, 128 */
#define MAROON          0x7800      /* 128,   0,   0 */
#define PURPLE          0x780F      /* 128,   0, 128 */
#define OLIVE           0x7BE0      /* 128, 128,   0 */
#define LGRAY           0xC618      /* 192, 192, 192 */
#define DGRAY           0x7BEF      /* 128, 128, 128 */
#define BLUE            0x001F      /*   0,   0, 255 */
#define GREEN           0x07E0      /*   0, 255,   0 */
#define RED             0xF800      /* 255,   0,   0 */
#define CYAN            0x07FF      /*   0, 255, 255 */
#define MAGENTA         0xF81F      /* 255,   0, 255 */
#define YELLOW          0xFFE0      /* 255, 255,   0 */
#define WHITE           0xFFFF      /* 255, 255, 255 */
#define ORANGE          0xFD20      /* 255, 165,   0 */
#define GREENYELLOW     0xAFE5      /* 173, 255,  47 */
#define BROWN           0XBC40 
#define BRRED           0XFC07 

// Grayscale Values
#define COLOR_GRAY_15                       (uint16_t)(0x0861)    //  15  15  15
#define COLOR_GRAY_30                       (uint16_t)(0x18E3)    //  30  30  30
#define COLOR_GRAY_50                       (uint16_t)(0x3186)    //  50  50  50
#define COLOR_GRAY_80                       (uint16_t)(0x528A)    //  80  80  80
#define COLOR_GRAY_128                      (uint16_t)(0x8410)    // 128 128 128
#define COLOR_GRAY_200                      (uint16_t)(0xCE59)    // 200 200 200
#define COLOR_GRAY_225                      (uint16_t)(0xE71C)    // 225 225 225

// Color Palettes
#define COLOR_THEME_LIMEGREEN_BASE          (uint16_t)(0xD7F0)    // 211 255 130
#define COLOR_THEME_LIMEGREEN_DARKER        (uint16_t)(0x8DE8)    // 137 188  69
#define COLOR_THEME_LIMEGREEN_LIGHTER       (uint16_t)(0xEFF9)    // 238 255 207
#define COLOR_THEME_LIMEGREEN_SHADOW        (uint16_t)(0x73EC)    // 119 127 103
#define COLOR_THEME_LIMEGREEN_ACCENT        (uint16_t)(0xAE6D)    // 169 204 104

#define COLOR_THEME_VIOLET_BASE             (uint16_t)(0x8AEF)    // 143  94 124
#define COLOR_THEME_VIOLET_DARKER           (uint16_t)(0x4187)    //  66  49  59
#define COLOR_THEME_VIOLET_LIGHTER          (uint16_t)(0xC475)    // 194 142 174
#define COLOR_THEME_VIOLET_SHADOW           (uint16_t)(0x40E6)    //  66  29  52
#define COLOR_THEME_VIOLET_ACCENT           (uint16_t)(0xC992)    // 204  50 144

#define COLOR_THEME_EARTHY_BASE             (uint16_t)(0x6269)    //  97  79  73
#define COLOR_THEME_EARTHY_DARKER           (uint16_t)(0x3103)    //  48  35  31
#define COLOR_THEME_EARTHY_LIGHTER          (uint16_t)(0x8C30)    // 140 135 129
#define COLOR_THEME_EARTHY_SHADOW           (uint16_t)(0xAB29)    // 173 102  79
#define COLOR_THEME_EARTHY_ACCENT           (uint16_t)(0xFE77)    // 250 204 188

#define COLOR_THEME_SKYBLUE_BASE            (uint16_t)(0x95BF)    // 150 180 255
#define COLOR_THEME_SKYBLUE_DARKER          (uint16_t)(0x73B0)    // 113 118 131
#define COLOR_THEME_SKYBLUE_LIGHTER         (uint16_t)(0xE75F)    // 227 235 255
#define COLOR_THEME_SKYBLUE_SHADOW          (uint16_t)(0x4ACF)    //  75  90 127
#define COLOR_THEME_SKYBLUE_ACCENT          (uint16_t)(0xB5F9)    // 182 188 204

// Using these values allows you to update the entire UI color scheme in one location
#define COLOR_THEME_DEFAULT_BASE            COLOR_THEME_LIMEGREEN_BASE
#define COLOR_THEME_DEFAULT_DARKER          COLOR_THEME_LIMEGREEN_DARKER
#define COLOR_THEME_DEFAULT_LIGHTER         COLOR_THEME_LIMEGREEN_LIGHTER
#define COLOR_THEME_DEFAULT_SHADOW          COLOR_THEME_LIMEGREEN_SHADOW
#define COLOR_THEME_DEFAULT_ACCENT          COLOR_THEME_LIMEGREEN_ACCENT
