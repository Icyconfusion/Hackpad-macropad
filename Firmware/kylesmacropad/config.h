#pragma once

#include "config_common.h"

// Matrix size: 4 rows × 4 cols (16 buttons)
#define MATRIX_ROWS 4
#define MATRIX_COLS 4

// Charlieplex pins: P1=GPIO0, P2=GPIO1, P3=GPIO2, P4=GPIO4, P5=GPIO3
#define CHARLIE_PINS { GP0, GP1, GP2, GP4, GP3 }
#define NUM_CHARLIE_PINS 5

// Encoder pins (A and B for each)
#define ENCODER_LEFT_A GP28
#define ENCODER_LEFT_B GP29
#define ENCODER_RIGHT_A GP26
#define ENCODER_RIGHT_B GP27

// I2C pins for OLED SSD1306 128x32
#define OLED_SDA_PIN GP6
#define OLED_SCL_PIN GP7

// Layers
#define _SCHOOLWORK 0
#define _RACING     1
#define _GENERAL    2

// USB Device descriptor parameters
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6060
#define DEVICE_VER      0x0001
#define MANUFACTURER    Kyle Mason
#define PRODUCT         KylesMacropad
