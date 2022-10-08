// Generated by imageconverter. Please, do not edit!

#ifndef TOUCHGFX_BITMAPDATABASE_HPP
#define TOUCHGFX_BITMAPDATABASE_HPP

#include <touchgfx/hal/Types.hpp>
#include <touchgfx/Bitmap.hpp>

const uint16_t BITMAP_BLUE_CLOCKS_BACKGROUNDS_CLOCK_STANDARD_BACKGROUND_ID = 0;
const uint16_t BITMAP_BLUE_CLOCKS_HANDS_CLOCK_STANDARD_HOUR_HAND_ID = 1;
const uint16_t BITMAP_BLUE_CLOCKS_HANDS_CLOCK_STANDARD_MINUTE_HAND_ID = 2;
const uint16_t BITMAP_BLUE_CLOCKS_HANDS_CLOCK_STANDARD_SECOND_HAND_ID = 3;

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance();
uint16_t getInstanceSize();
} // namespace BitmapDatabase

#endif // TOUCHGFX_BITMAPDATABASE_HPP