#include "evr.h"
#include "senku.h"
#define SENKU_MODULE 0
#define EVR_MODULE 1
typedef void (*parsers)(uint32_t, uint8_t);
parsers parser_array[] = {senku_parse, evr_parse};
