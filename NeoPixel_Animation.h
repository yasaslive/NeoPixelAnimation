#include <Adafruit_NeoPixel.h>
#include "Arduino.h"
class NeoPixelAnimation{
	private:
		int pixel_count;
		Adafruit_NeoPixel* pixels;

	public:
		NeoPixelAnimation(uint16_t n, int16_t pin, neoPixelType type = NEO_GRB + NEO_KHZ800);
		~NeoPixelAnimation();

		void Fade(uint8_t r, uint8_t g, uint8_t b, uint16_t delay_t = 500, bool use_all = true);
		void Jump(uint8_t r, uint8_t g, uint8_t b,uint8_t count, uint16_t delay_t = 500, bool reverse = false);
		void Blink(uint8_t r, uint8_t g, uint8_t b, uint16_t delay_t = 500);
    void KnightRider(uint8_t r, uint8_t g, uint8_t b, uint16_t delay_t = 500, uint8_t count = 0);
};
