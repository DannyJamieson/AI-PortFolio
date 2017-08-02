#pragma once

#include "SFML\Graphics.hpp"

static sf::Vector2f Normalize(sf::Vector2f vector)
{
	float mag = sqrt(vector.x * vector.x + vector.y * vector.y);
	return sf::Vector2f(vector.x / mag, vector.y / mag);
}