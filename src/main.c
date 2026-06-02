#include <stdio.h>
#include <stdint.h>
#include "../includes/flagSystem.h"
#include "../includes/bitPacking.h"
#include "../includes/packetSystem.h"

int main (void)
{
    // uint8_t OBSWStatus_ = 0x00;
    // (void) manipulationFactory(SWITCH_ON, &OBSWStatus_, (uint8_t) EmergencyMask);
    // (void) manipulationFactory(SWITCH_OFF, &OBSWStatus_, (uint8_t) EmergencyMask);
    // (void) manipulationFactory(TOGGLE, &OBSWStatus_, (uint8_t) EmergencyMask);
    // (void) manipulationFactory(GET_STATUS, &OBSWStatus_, AntennaMask);
    // (void) manipulationFactory(TOGGLE, &OBSWStatus_, (uint8_t) AntennaMask);
    // (void) manipulationFactory(GET_STATUS, &OBSWStatus_, AntennaMask);

    // (0) correspond to a slot that is never used so we can fix the beginning of the next value to it
    uint8_t temperature = 32; // -8 c° --> (0)010 0000
    uint8_t radiation = 4; // --> (000)0 0100
    uint8_t battery = 87; // --> (0)101 0111
    uint16_t speed = 1347; // --> (00000)101 0100 0011
    
    uint32_t result = compressionFactory(temperature, radiation, battery, speed);
    printf("Result of the compression : ");
    print_bits(result, 32);

    container_t data = decompressionFactory(result);

    printf("Après extraction on a comme valeur :\npour la température : %d\npour le niveau de radiation : %d\npour la batterie : %d\npour la vitesse : %d\n", data.temperature, data.radiation, data.battery, data.speed * 10);

    packet_t packet = serialize(result);
    printf("Packet serialized\n");
    result = deserialize(packet);
    printf("Deserialize done : ");
    print_bits(result, 32);
}