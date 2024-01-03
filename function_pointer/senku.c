#include <stdint.h>
#include <stdio.h>
#include "senku.h"
void senku_parse(uint32_t PGN, uint8_t address) {
    uint8_t u8PGN = (uint8_t) PGN;
    printf("SENKU : PGN = %d, address = %d\n", PGN, address);
}
