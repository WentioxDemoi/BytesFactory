#ifndef FLAGSYSTEM_H
#define FLAGSYSTEM_H

#include <stdint.h>
#include <stdbool.h>

enum manipulationTC {
    SWITCH_ON,
    SWITCH_OFF,
    TOGGLE,
    GET_STATUS
};

#define EngineMask (1 << 0) // Premier bit
#define ShieldMask (1 << 1) // Deuxième bit
#define AntennaMask (1 << 2) // Troisième bit
#define EmergencyMask (1 << 3) // Quatrième bit


bool turnOn(uint8_t *Status_, uint8_t Mask_);
bool turnOff(uint8_t *Status_, uint8_t Mask_);
bool toggle(uint8_t *Status_, uint8_t Mask_);
bool getStatus(uint8_t *Status_, uint8_t Mask_);

bool manipulationFactory(enum manipulationTC TC_, uint8_t *Status_, uint8_t Mask_);

void print_bits(uint32_t byte, int8_t nb_bytes_);

#endif