#pragma once
#include <sfml\Graphics.hpp>

class Bird
{
private:
	sf::Texture texture[2];
	const int gravity;
	const int flap_speed;
	float velocity_y;
	int anim_counter, texture_swap;
	bool should_fly;

public:
	sf::Sprite bird_sprite;
	Bird();
	void setShouldFly(bool);
	void flapBird(sf::Time&);
	void resetBirdPosition();
	void update(sf::Time&);
	float getRightBound();
};