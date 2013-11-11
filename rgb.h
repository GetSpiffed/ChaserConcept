#pragma once
struct rgb
{
	rgb(int red, int green, int blue)
		: green(green), red(red), blue(blue)
	{}

	rgb()
		: green(0), red(0), blue(0)
	{}

	int green;
	int red;
	int blue;
};

