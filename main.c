#include <stdio.h>
#include "pico/stdlib.h"

int main() {

    const uint led_pin = 6; 
    const uint led_pin_red = 25; 
    const uint led_pin_yellow = 15; 
    const uint led_pin_green = 16; 

    // Initialize LED pin
    gpio_init(led_pin);
    gpio_set_dir(led_pin, GPIO_OUT);
    gpio_init(led_pin_red);
    gpio_set_dir(led_pin_red, GPIO_OUT);
    gpio_init(led_pin_green);
    gpio_set_dir(led_pin_green, GPIO_OUT);
    gpio_init(led_pin_yellow);
    gpio_set_dir(led_pin_yellow, GPIO_OUT);

    // Initialize chosen serial port
    stdio_init_all();

    // Loop forever
    while (true) {

        // Blink LED
        printf("Blinking!\r\n");
        gpio_put(led_pin, true);
        gpio_put(led_pin_red, true);
        gpio_put(led_pin_yellow, false);
        gpio_put(led_pin_green, true);


        sleep_ms(3000);
        gpio_put(led_pin, false);
        gpio_put(led_pin_red, false);
        gpio_put(led_pin_yellow, true);
        gpio_put(led_pin_green, false);
        sleep_ms(3000);
    }
}