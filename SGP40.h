//
// Created by Waffles on 3/22/23.
//

#ifndef CAPSTONESPRING2023_SGP40_H
#define CAPSTONESPRING2023_SGP40_H

#include <stdio.h>
#include <math.h>
#include "gas-index-algorithm/sensirion_gas_index_algorithm/sensirion_gas_index_algorithm.h"
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "hardware/i2c.h"


typedef struct{
    int32_t voc_raw;
    int32_t voc_index;
} SGP_Data;




class SGP40 {
private:
    int _I2CAddress;
    uint _SDAPin;
    uint _SCLPin;
    GasIndexAlgorithmParams params;


public:
    SGP40(uint SDAPin, uint SCLPin, int address = 0x59){
        _SDAPin = SDAPin;
        _SCLPin = SCLPin;
        _I2CAddress = address;



        gpio_set_function(_SDAPin, GPIO_FUNC_I2C);
        gpio_set_function(_SCLPin, GPIO_FUNC_I2C);
        gpio_pull_up(SDAPin);
        gpio_pull_up(SCLPin);
        // Make the I2C pins available to picotool
        bi_decl(bi_2pins_with_func(SDAPin,SCLPin, GPIO_FUNC_I2C));
        GasIndexAlgorithm_init(&params, GasIndexAlgorithm_ALGORITHM_TYPE_VOC);





    }

    void getData(SGP_Data& data);

    bool isReady();

    void intializeRegisters();





};


#endif //CAPSTONESPRING2023_SGP40_H
