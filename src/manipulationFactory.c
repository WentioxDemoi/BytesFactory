#include "../includes/manipulationFactory.h"
#include <stdio.h>

static void print_bits(uint8_t byte)
{
    int i;

    i = 7;
    while (i >= 0)
    {
        printf("%d", (byte >> i) & 1);
        i--;
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
            print_bits(Mask_);
            (void) turnOn(Status_, Mask_);
            printf("\nStatus_ After SwitchOn : ");
            print_bits(*Status_);
            printf("\n");
            break;
        case SWITCH_OFF:
            printf("SwitchOff asked for byte :");
            print_bits(Mask_);
            (void) turnOff(Status_, Mask_);
            printf("\nStatus_ After SwitchOff : ");
            print_bits(*Status_);
            printf("\n");
            break;
        case TOGGLE:
            printf("Toggle asked for byte :");
            print_bits(Mask_);
            (void) toggle(Status_, Mask_);
            printf("\nStatus_ After Toggle : ");
            print_bits(*Status_);
            printf("\n");
            break;
        case GET_STATUS:
            printf("GetStatus asked for byte :");
            print_bits(Mask_);
            printf("\nResult : %d\n", getStatus(Status_, Mask_));
            break;
        default:
            printf("Unknown enum");
    }

    return true;
}