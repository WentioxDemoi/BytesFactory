#include "../includes/flagSystem.h"
#include <stdint.h>
#include <stdio.h>

void print_bits(uint32_t byte_, int8_t nb_bytes_)
{
    nb_bytes_--;

    while (nb_bytes_ >= 0)
    {
        printf("%d", (byte_ >> nb_bytes_) & 1);
        nb_bytes_--;
    }
    printf("\n");
}

bool turnOn(uint8_t *Status_, uint8_t Mask_)
{

    *Status_ |= Mask_;

    return ((*Status_ & Mask_) == Mask_);
}

bool turnOff(uint8_t *Status_, uint8_t Mask_)
{

    *Status_ &= ~Mask_;

    return ((*Status_ & Mask_) == 0);
}

bool toggle(uint8_t *Status_, uint8_t Mask_)
{
    uint8_t before = *Status_;

    *Status_ ^= Mask_;

    return ((*Status_ & Mask_) != (before & Mask_));
}

bool getStatus(uint8_t *Status_, uint8_t Mask_)
{
    return ((*Status_ & Mask_) != 0);
}

bool manipulationFactory(enum manipulationTC TC_, uint8_t *Status_, uint8_t Mask_)
{
    switch (TC_) {
        case SWITCH_ON:
            printf("SwitchOn asked for byte :");
            print_bits(Mask_, 8);
            (void) turnOn(Status_, Mask_);
            printf("\nStatus_ After SwitchOn : ");
            print_bits(*Status_, 8);
            printf("\n");
            break;
        case SWITCH_OFF:
            printf("SwitchOff asked for byte :");
            print_bits(Mask_, 8);
            (void) turnOff(Status_, Mask_);
            printf("\nStatus_ After SwitchOff : ");
            print_bits(*Status_, 8);
            printf("\n");
            break;
        case TOGGLE:
            printf("Toggle asked for byte :");
            print_bits(Mask_, 8);
            (void) toggle(Status_, Mask_);
            printf("\nStatus_ After Toggle : ");
            print_bits(*Status_, 8);
            printf("\n");
            break;
        case GET_STATUS:
            printf("GetStatus asked for byte :");
            print_bits(Mask_, 8);
            printf("\nResult : %d\n", getStatus(Status_, Mask_));
            break;
        default:
            printf("Unknown enum");
    }

    return true;
}