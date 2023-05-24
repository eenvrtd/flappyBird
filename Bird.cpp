#include "Bird.h"
#include "Header.h"

Bird::Bird() :
	gravity(10),
	flap_speed(250),
	anim_counter(0),
	texture_swap(1),
	should_fly(false)

{
	texture[0].loadFromFile("assets/birddown.png");
	texture[1].loadFromFile("assets/birdup.png");

	bird_sprite.setTexture(texture[0]);
	bird_sprite.setScale(SCALE_FACTOR, SCALE_FACTOR);
	resetBirdPosition();
}

void Bird::update(sf::Time&dt)
{
	if (bird_sprite.getGlobalBounds().top < 548 && should_fly)
	{
		if (anim_counter == 5)
		{
			bird_sprite.setTexture(texture[texture_swap]);
			if (texture_swap) texture_swap = 0;
			else texture_swap = 1;
			anim_counter = 0;
		}
		anim_counter++;

		velocity_y += gravity * dt.asSeconds();
		bird_sprite.move(0, velocity_y);

		if (bird_sprite.getGlobalBounds().top < 0)
			bird_sprite.setPosition(100, 0);
	}
}

void Bird::flapBird(sf::Time&dt)
{
	velocity_y = -flap_speed * dt.asSeconds();
}

float Bird::getRightBound()
{
	return bird_sprite.getGlobalBounds().left + bird_sprite.getGlobalBounds().width;
}

void Bird::resetBirdPosition()
{
	bird_sprite.setPosition(100, 50);
	velocity_y = 0;

}

void Bird::setShouldFly(bool should_fly)
{
	this->should_fly = should_fly;
}