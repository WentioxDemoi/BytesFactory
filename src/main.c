#include <stdio.h>
#include <stdint.h>
#include "../includes/manipulationFactory.h"

int main (void)
{
    uint8_t OBSWStatus_ = 0x00;
    manipulationFactory(SWITCH_ON, &OBSWStatus_, (uint8_t) EmergencyMask);
    manipulationFactory(SWITCH_OFF, &OBSWStatus_, (uint8_t) EmergencyMask);
    manipulationFactory(TOGGLE, &OBSWStatus_, (uint8_t) EmergencyMask);
    manipulationFactory(GET_STATUS, &OBSWStatus_, AntennaMask);
    manipulationFactory(TOGGLE, &OBSWStatus_, (uint8_t) AntennaMask);
    manipulationFactory(GET_STATUS, &OBSWStatus_, AntennaMask);
}