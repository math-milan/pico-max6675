#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "pico-max6675/max6675.h"

int main() {
    stdio_init_all();
    spi_init(spi0, 1000*1000);
    gpio_set_function(18, GPIO_FUNC_SPI);
    gpio_set_function(20, GPIO_FUNC_SPI);

    max6675 temp = max6675(spi0, 24);

    while (true){
        printf("Connectet: %s Temp: %f\n", temp.getStatus() ? "true" : "false", temp.getTemperature());
        sleep_ms(1000);
    }
    return 0;
};