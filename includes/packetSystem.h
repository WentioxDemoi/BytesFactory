#ifndef PACKETSYSTEM_H
#define PACKETSYSTEM_H

#include <stdbool.h>
#include <stdint.h>

#define BYTE_MASK 0xFF


typedef struct packet_s {
    uint8_t data[4];
    uint8_t checksum;
} packet_t ;

packet_t serialize(uint32_t data_);
uint32_t deserialize(packet_t packet_);

#endif