#include "../includes/packetSystem.h"
#include <stdint.h>
#include <stdio.h>

packet_t serialize(uint32_t data_)
{
    packet_t packet;

    for (uint8_t i = 0; i < 4; i++)
    {
        packet.data[i] = (uint8_t) (data_ >> (i * 8)) & BYTE_MASK;
        packet.checksum ^= packet.data[i];
    }

    return packet;
}

uint32_t deserialize(packet_t packet_)
{
    uint32_t result;
    uint8_t checksum = 0;

    for (uint8_t i = 0; i < 4; i++)
    {
        result |= (uint32_t) packet_.data[i] << (i * 8);
        checksum ^= packet_.data[i];
    }

    if (checksum == packet_.checksum) {
        printf("Packet valid\n");
    } else {
        printf("Packet not valid\n");
    }
    return result;
}