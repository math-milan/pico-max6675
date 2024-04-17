# MAX6675 K-Thermocouple Library for RP2040

## 1. Importing the library
* Clone this project into your pico project
* Add this to your CMakeLists.txt
  ```cmake
    add_subdirectory(pico-max6675)
    target_link_libraries(your_project_name
    max6675
    # you will also need hardware spi library for communication with the ic
    hardware_spi)
  ```
* Import library in your code
  ```c++
  #include "pico-max6675/max6675.h"
  ```
## 2. Basic usage
```c++
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "pico-max6675/max6675.h"

#define CS 24
#define SCK 18
#define MISO 20
#define SPI spi0


int main() {
    stdio_init_all();
    spi_init(SPI, 1000*1000); // 1MHz but can go up to 4MHz
    gpio_set_function(SCK, GPIO_FUNC_SPI);
    gpio_set_function(MISO, GPIO_FUNC_SPI); 

    max6675 temp = max6675(SPI, CS);

    while (true){
        // temp.getStatus returns a bool that tells you if a Thermocouple is connected
        // temp.getTemperature returns the tempruter in C from 0-1023.75
        printf("Connectet: %s Temp: %f\n", temp.getStatus() ? "true" : "false", temp.getTemperature());
        sleep_ms(1000);
    }
    return 0;
};
```