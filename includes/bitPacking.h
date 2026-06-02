#ifndef BITPACKING_H
#define BITPACKING_H

#include <stdbool.h>
#include <stdint.h>

// On uint32_t, we store 4 variables
#define TemperaturePos 0 
#define RadiationPos 7
#define BatteryPos 12
#define SpeedPos 19

#define TemperatureBits 7
#define RadiationBits   5
#define BatteryBits     7
#define SpeedBits       11

#define TemperatureMask ((1u << TemperatureBits) - 1)
#define RadiationMask   ((1u << RadiationBits) - 1)
#define BatteryMask     ((1u << BatteryBits) - 1)
#define SpeedMask       ((1u << SpeedBits) - 1)

typedef struct container_s {
    uint8_t temperature;
    uint8_t radiation;
    uint8_t battery;
    uint16_t speed;
} container_t ;

uint32_t compressionFactory(uint8_t temperature_, uint8_t radiation_, uint8_t battery_, uint16_t speed_);
container_t decompressionFactory(uint32_t data_);

#endif