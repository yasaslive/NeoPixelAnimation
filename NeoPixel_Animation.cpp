#include "NeoPixel_Animation.h"

NeoPixelAnimation::NeoPixelAnimation(uint16_t n, int16_t pin, neoPixelType type){
	this->pixels = new Adafruit_NeoPixel(n , pin, type);
	this->pixels->begin();
	this->pixel_count = n;
}

void NeoPixelAnimation::Fade(uint8_t r, uint8_t g, uint8_t b, uint16_t delay_t, bool use_all){
  float r_factor = (r == 0) ? 0.0f : r/51;
  float g_factor = (g == 0) ? 0.0f : g/51;
  float b_factor = (b == 0) ? 0.0f : b/51;
  
	this->pixels->clear();
	if(use_all){
		for(int x = 0; x < 51; x++){
			this->pixels->fill(this->pixels->Color(x*r_factor, x*g_factor, x*b_factor));
			this->pixels->show();
			delay(delay_t);	
		}

    for(int x = 51; x > 0; x--){
      this->pixels->fill(this->pixels->Color(x*r_factor, x*g_factor, x*b_factor));
      this->pixels->show();
      delay(delay_t); 
    }
		pixels->clear();
	}else{
    for(int x = 0; x < this->pixel_count; x++){
      for(int y = 0; y < 52; y++){
        this->pixels->setPixelColor(x, this->pixels->Color(y*r_factor, y*g_factor, y*b_factor));
        this->pixels->show();
        delayMicroseconds(delay_t*1000);
      }
    }

    for(int x = 0; x < this->pixel_count; x++){
      for(int y = 52; y >= 0; y--){
        this->pixels->setPixelColor(x, this->pixels->Color(y*r_factor, y*g_factor, y*b_factor));
        this->pixels->show();
        delayMicroseconds(delay_t*1000);
      }
    }
		pixels->clear();
	}
}

void NeoPixelAnimation::Jump(uint8_t r, uint8_t g, uint8_t b, uint8_t count, uint16_t delay_t, bool reverse){
  if(reverse == true){
    int min_x = 0;
    if(count > 1)
      min_x = -1;
    for(int x = this->pixel_count-1; x > min_x; x--){
        this->pixels->fill(this->pixels->Color(r, g, b), (x-count)+1, count);
        this->pixels->show();
        delay(delay_t);
        this->pixels->fill(this->pixels->Color(0, 0, 0), (x-count)+1, count);
        this->pixels->show();
        delay(delay_t);
    }
  }else{
    for(int x = 0; x < this->pixel_count-count+1; x++){
      this->pixels->fill(this->pixels->Color(r, g, b), x, count);
      this->pixels->show();
      delay(delay_t);
      this->pixels->fill(this->pixels->Color(0, 0, 0), x, count);
      this->pixels->show();
      delay(delay_t);
    }
  }
  pixels->clear();
}

void NeoPixelAnimation::Blink(uint8_t r, uint8_t g, uint8_t b, uint16_t delay_t){

}

void NeoPixelAnimation::KnightRider(uint8_t r, uint8_t g, uint8_t b, uint16_t delay_t, uint8_t count){
  if(count == 0)
    count = this->pixel_count;
    
  float r_factorial = r/(count*count);
  float g_factorial = g/(count*count);
  float b_factorial = b/(count*count);
  
  for(int x = 0; x < this->pixel_count+count; x++){ 
    int p = count;
    for(int y = x; y >= x-count; y--){
      this->pixels->setPixelColor(y, this->pixels->Color(p*p*r_factorial, p*p*g_factorial, p*p*b_factorial));
      p--;
    }
    this->pixels->show();
    delay(delay_t);
  }

  for(int x = this->pixel_count+count; x > 0; x--){ 
    int p = count;
    for(int y = x-count; y <= x; y++){
      this->pixels->setPixelColor(y, this->pixels->Color(p*p*r_factorial, p*p*g_factorial, p*p*b_factorial));
      p--;
    }
    this->pixels->show();
    delay(delay_t);
  }
  this->pixels->clear();
}

NeoPixelAnimation::~NeoPixelAnimation(){

}
