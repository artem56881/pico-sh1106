#ifndef SH1106_TEXTRENDERER_H
#define SH1106_TEXTRENDERER_H

#include "../sh1106.h"

#include "5x8_font.h"
#include "8x8_font.h"
#include "12x16_font.h"
#include "16x32_font.h"

namespace pico_sh1106
{

    /// \enum pico_sh1106::Rotation
    enum class Rotation
    {
        /// deg0 - means no rotation
        deg0,
        /// deg 90 - means 90 deg rotation
        deg90,
    };

    /// \brief Draws a single glyph on the screen
    /// \param sh1106 - pointer to a SH1106 object aka initialised display
    /// \param font - pointer to a font data array
    /// \param c - char to be drawn
    /// \param anchor_x, anchor_y - coordinates setting where to put the glyph
    /// \param mode - mode describes setting behavior. See WriteMode doc for more information
    /// \param rotation - either rotates the char by 90 deg or leaves it unrotated
    void drawChar(pico_sh1106::SH1106 *sh1106, const unsigned char *font, char c, uint8_t anchor_x, uint8_t anchor_y, WriteMode mode = WriteMode::ADD, Rotation rotation = Rotation::deg0);

    /// \brief Draws text on screen
    /// \param sh1106 - pointer to a SH1106 object aka initialised display
    /// \param font - pointer to a font data array
    /// \param text - text to be drawn
    /// \param anchor_x, anchor_y - coordinates setting where to put the text
    /// \param mode - mode describes setting behavior. See WriteMode doc for more information
    /// \param rotation - either rotates the text by 90 deg or leaves it unrotated
    void drawText(pico_sh1106::SH1106 *sh1106, const unsigned char *font, const char *text, uint8_t anchor_x, uint8_t anchor_y, WriteMode mode = WriteMode::ADD, Rotation rotation = Rotation::deg0);
}

#endif // SH1106_TEXTRENDERER_H
