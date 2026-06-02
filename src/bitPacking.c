#include "../includes/bitPacking.h"
#include <stdlib.h>

uint32_t compressionFactory(uint8_t temperature_, uint8_t radiation_, uint8_t battery_, uint16_t speed_)
{
    return ((uint32_t) temperature_ |
        (uint32_t) radiation_ << 7 |
        (uint32_t) battery_ << 12 |
        (uint32_t) speed_ << 19
    );
}

container_t decompressionFactory(uint32_t data_)
{
    container_t data;
    
    // Extraction des champs :
    // 1. Décalage à droite pour ramener le champ au bit 0.
    // 2. Application du masque pour ne conserver que les bits utiles.
    data.temperature = ( data_ >> TemperaturePos ) & TemperatureMask;
    data.radiation = ( data_ >> RadiationPos ) & RadiationMask;
    data.battery = ( data_ >> BatteryPos ) & BatteryMask;
    data.speed = ( data_ >> SpeedPos ) & SpeedMask;

    return data;
}