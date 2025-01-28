#include "PORT_CFG.h"

/*Pin data initialization*/
MPORT_gstPinCFG_t MPORT_garrPin_CFG[NO_OF_PINS * NO_OF_PORTS] = {
    /* Port A*/
    {.pin = PIN_A0, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_OUTPUT},
    {.pin = PIN_A1, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_OUTPUT},
    {.pin = PIN_A2, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_OUTPUT},
    {.pin = PIN_A3, .dir = MPORT_enu_dir_INPUT, .mode = MPORT_enu_INPUT_PULLUP},
    {.pin = PIN_A4, .dir = MPORT_enu_dir_INPUT, .mode = MPORT_enu_INPUT_PULLUP},
    {.pin = PIN_A5, .dir = MPORT_enu_dir_INPUT, .mode = MPORT_enu_INPUT_PULLUP},
    {.pin = PIN_A6, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},
    {.pin = PIN_A7, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},

    /* Port B*/
    {.pin = PIN_B0, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},
    {.pin = PIN_B1, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},
    {.pin = PIN_B2, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},
    {.pin = PIN_B3, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},
    {.pin = PIN_B4, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},
    {.pin = PIN_B5, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},
    {.pin = PIN_B6, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},
    {.pin = PIN_B7, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},

    /* Port C*/
    {.pin = PIN_C0, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},
    {.pin = PIN_C1, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},
    {.pin = PIN_C2, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},
    {.pin = PIN_C3, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},
    {.pin = PIN_C4, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},
    {.pin = PIN_C5, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},
    {.pin = PIN_C6, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},
    {.pin = PIN_C7, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},

    /* Port D*/
    {.pin = PIN_D0, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},
    {.pin = PIN_D1, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},
    {.pin = PIN_D2, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},
    {.pin = PIN_D3, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},
    {.pin = PIN_D4, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},
    {.pin = PIN_D5, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},
    {.pin = PIN_D6, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE},
    {.pin = PIN_D7, .dir = MPORT_enu_dir_OUTPUT, .mode = MPORT_enu_NOT_AVAILABLE}
};