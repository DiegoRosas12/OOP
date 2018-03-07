#ifndef _IMAGE_H_
#define _IMAGE_H_

#include <string>

class Pixel {
	public:
	Pixel();
	Pixel(int red, int green, int blue, int alpha=255);
	private:
	unsigned char m_red;
	unsigned char m_green;
	unsigned char m_blue;
	unsigned char m_alpha;


}
class Imgage {
	public:
	Image();
            Image(std::string filename);
	private:
	int m_width;
	int m_height;
	Pixel* m_vector;
	// unsigned char* m_pixel;
}

#endif
