//
// Created by drlim on 10/02/2021.
//

#ifndef MBED_KEYPAD_KEYPAD_H
#define MBED_KEYPAD_KEYPAD_H


#include "mbed.h"
#include "Button.h"

/**
 * A 3x4 keypad.
 * @author - David Lim
 */
class Keypad {
public:
    /**
     * Constructor for the keypad object.
     * @param col1Pin - The pin connected to column 1 on the keypad from left to right as a PinName
     * @param col2Pin - The pin connected to column 2 on the keypad from left to right as a PinName
     * @param col3Pin - The pin connected to column 3 on the keypad from left to right as a PinName
     * @param row1Pin - The pin connected to row 1 on the keypad from top to bottom as a PinName
     * @param row2Pin - The pin connected to row 2 on the keypad from top to bottom as a PinName
     * @param row3Pin - The pin connected to row 3 on the keypad from top to bottom as a PinName
     * @param row4Pin - The pin connected to row 4 on the keypad from top to bottom as a PinName
     */
    Keypad(PinName col1Pin, PinName col2Pin, PinName col3Pin, PinName row1Pin, PinName row2Pin, PinName row3Pin,
           PinName row4Pin);

    /**
     * Read whether a key has been pressed on the keypad.
     * @param runtime - The time the program has been running for as a std::chrono::duration
     * @return - The character pressed on the keypad (returns 0 (null) if nothing is pressed)
     */
    char read(std::chrono::microseconds runtime);

private:
    DigitalOut outputs[3];
    DigitalIn inputs[4];
    Button buttonMatrix[3][4];
    char characterMatrix[3][4]{{'1', '4', '7', '*'},
                               {'2', '5', '8', '0'},
                               {'3', '6', '9', '#'}};
    int column = 0;
};


#endif //MBED_KEYPAD_KEYPAD_H
