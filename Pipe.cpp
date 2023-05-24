#include "Pipe.h"
#include "Header.h"

Pipe::Pipe(int y_position)
{
	sprite_top.setTexture(texture_top);
	sprite_bottom.setTexture(texture_bottom);

	sprite_top.setScale(SCALE_FACTOR, SCALE_FACTOR);
	sprite_bottom.setScale(SCALE_FACTOR, SCALE_FACTOR);

	sprite_bottom.setPosition(WIN_WIDTH, y_position);
	sprite_top.setPosition(WIN_WIDTH, y_position + pipe_distance + sprite_top.getGlobalBounds().height);
}

void Pipe::update(sf::Time& dt)
{
	sprite_bottom.move(-move_speed * dt.asSeconds(), 0.f);
	sprite_top.move(-move_speed * dt.asSeconds(), 0.f);
}

void Pipe::loadTexture()
{
	texture_top.loadFromFile("assets/pipetop.png");
	texture_bottom.loadFromFile("assets/pipebottom.png");
}
float Pipe::getRightBound()
{
	return 0.0f;
}
sf::Texture Pipe::texture_top, Pipe::texture_bottom;
int Pipe::pipe_distance = 100, Pipe::move_speed = 400;