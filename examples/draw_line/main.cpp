#include "pico/stdlib.h"
#include "pico-sh1106/sh1106.h"
#include "pico-sh1106/shapeRenderer/ShapeRenderer.h"
#include "hardware/i2c.h"

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

    // If you don't do anything before initializing a display pi pico is too fast and starts sending
    // commands before the screen controller had time to set itself up, so we add an artificial delay for
    // ssd1306 to set itself up
    sleep_ms(250);

    // Create a new display object at address 0x3D and size of 128x64
    SH1106 display = SH1106(i2c0, 0x3D, Size::W128xH64);

    // Draw a line on display from 0, 0 to 127, 63
    drawLine(&display, 0, 0, 127, 63);

    // Send buffer to the display
    display.sendBuffer();
}