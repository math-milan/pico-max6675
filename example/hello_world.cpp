// #include <stdio.h>
// #include "pico/stdlib.h"
// #include <string.h>
// #include "hardware/spi.h"

// // Define SPI interface
// #define SPI_PORT spi0
// #define SPI_SCK_PIN 18
// #define SPI_MISO_PIN 20
// #define SPI_CS_PIN 24

// // Define SPI clock speed (Hz)
// #define SPI_CLOCK_SPEED 1000000 // 1 MHz

// // Define buffer size
// #define BUFFER_SIZE 2

// int main() {
//     stdio_init_all(); // Initialize stdio UARTs

//     // Initialize SPI
//     spi_init(SPI_PORT, SPI_CLOCK_SPEED);
//     gpio_set_function(SPI_SCK_PIN, GPIO_FUNC_SPI);
//     gpio_set_function(SPI_MISO_PIN, GPIO_FUNC_SPI);
//     spi_set_format(SPI_PORT, 16, SPI_CPOL_0, SPI_CPHA_0, SPI_MSB_FIRST);
//     spi_set_slave(SPI_PORT, false); // Set as master
//     // Create buffer for data
//     uint8_t buffer[BUFFER_SIZE];
//     sleep_ms(1000);
//     // Read one block of SPI data
//     gpio_init(24);
//     gpio_set_dir(24, true);


//     gpio_put(24, true);

//     sleep_ms(1000);
//     gpio_put(24, false);
//     sleep_us(1);
//     spi_read_blocking(SPI_PORT, 0, buffer, 2);
//     gpio_put(24, true);

//     sleep_ms(1000);
//     while (true){
//         // Print received data
//         printf("Received data: ");
//         for (int i = 0; i < 3; i++) {
//             printf("%u ", buffer[i]);
//         }
//         printf("\n");
//         break;
//     }
//     return 0;
// }

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/spi.h"
#include "max6675/max6675.h"

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
}
