#include "pico/stdlib.h"
#include "pico-sh1106/sh1106.h"
#include "hardware/i2c.h"

#pragma ide diagnostic ignored "EndlessLoop"

// Use the namespace for convenience
using namespace pico_sh1106;

int main()
{
    // Init i2c0 controller
    i2c_init(i2c0, 1000000);
    // Set up pins 12 and 13
    gpio_set_function(12, GPIO_FUNC_I2C);
    gpio_set_function(13, GPIO_FUNC_I2C);
    gpio_pull_up(12);
    gpio_pull_up(13);

    // Create a new display object at address 0x3D and size of 128x64
    SH1106 display = SH1106(i2c0, 0x3D, Size::W128xH64);

    // Here we rotate the display by 180 degrees, so that it's not upside down from my perspective
    // If your screen is upside down try setting it to 1 or 0
    display.setOrientation(0);

    // variable to count on witch frame we are on
    uint32_t frame_counter = 0;
    // Infinite animation loop
    while (1)
    {

        // Draw pixels spaced 8 px apart, one px lower every frame
        for (uint8_t pass1 = 0; pass1 < 15; pass1++)
        {
            display.setPixel(pass1 * 8, frame_counter % 63);
        }
        // Send buffer to display
        display.sendBuffer();
        // Show the frame for 100ms
        sleep_ms(100);
        // Clear the buffer
        display.clear();
        // Increment frame counter
        frame_counter++;
    }
}
