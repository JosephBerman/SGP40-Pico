//
// Created by Waffles on 3/22/23.
//

#include "SGP40.h"



void SGP40::getData(SGP_Data &data) {
    uint8_t outBuf[8] = {0x26,0x0F, 0x80, 0x00, 0xA2, 0x66, 0x66, 0x93};

    i2c_write_blocking(i2c_default,_I2CAddress,outBuf, 8, false);

    uint8_t inBuf[3];
    i2c_read_blocking(i2c_default,_I2CAddress, inBuf, 3, false);


    data.voc_raw = (inBuf[0] << 8) + inBuf[1];

    GasIndexAlgorithm_process(&this->params, data.voc_raw, &data.voc_index);

}


