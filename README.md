# mbed-keypad
A library to provide an interface for a 3x4 keypad in Mbed.

## Example
The following example was written for mbed-06 v6.7:
```c++
#include "mbed.h"
#include "Keypad.h"

static BufferedSerial serial_port(USBTX, USBRX, 9600);

int main() {
    Timer runtime;
    runtime.start();
    
    Keypad keypad(p26, p28, p24, p27, p22, p23, p25);

    while(true) {
        char keypadOutput = keypad.read(runtime.elapsed_time());
        if (keypadOutput != 0) {
            printf("Button pressed: %c\r\n", keypadOutput);
        }
    }
}

```
