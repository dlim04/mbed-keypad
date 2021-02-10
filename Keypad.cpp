//
// Created by drlim on 10/02/2021.
//

#include "Keypad.h"

Keypad::Keypad(PinName col1Pin, PinName col2Pin, PinName col3Pin, PinName row1Pin, PinName row2Pin,
               PinName row3Pin, PinName row4Pin) : outputs{DigitalOut(col1Pin), DigitalOut(col2Pin),
                                                          DigitalOut(col3Pin)},
                                                   inputs{DigitalIn(row1Pin), DigitalIn(row2Pin), DigitalIn(row3Pin),
                                                          DigitalIn(row4Pin)} {}

char Keypad::read(std::chrono::microseconds runtime) {
    char output = 0;
    for (auto digitalOutput : outputs) {
        digitalOutput.write(0);
    }

    outputs[column].write(1);

    for (int i = 0; i < 4; ++i) {
        if(buttonMatrix[column][i].isPressed(inputs[i].read(), runtime)) {
            output = characterMatrix[column][i];
        }
    }

    if (column++ >= 3) {
        column = 0;
    }
    return output;
}
