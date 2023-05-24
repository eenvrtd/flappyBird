#pragma once
#include <SFML\Graphics.hpp>
class Pipe
{
public:
	Pipe(int);
	sf::Sprite sprite_top, sprite_bottom;
	static void loadTexture();
	void update(sf::Time&);
	float getRightBound();

private:
	static sf::Texture texture_bottom, texture_top;
	static int pipe_distance, move_speed;
};

