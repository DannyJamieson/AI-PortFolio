#include "SteeringAgent.h"
#include "VectorUtil.h"


SteeringAgent::SteeringAgent()
{
}


SteeringAgent::~SteeringAgent()
{
}

void SteeringAgent::Think() {
	sf::Vector2f desired_velocity;
	sf::Vector2f desired_posistion = sf::Vector2f(100.f, 100.f);
	sf::Vector2f steer;
	int behave = 2;

	if (behave == 1) {
		float max_speed = 0.025f;
		desired_velocity = Normalize(desired_posistion - getPosition()) * 0.05f;

		steer = desired_velocity - velocity;

		velocity = velocity + steer;

		// build a new position vector by adding a scaled version of the velocity vector
		sf::Vector2f pos = getPosition() + velocity;

		// update our position
		setPosition(pos);

	}
	else if(behave == 2){
		float max_speed = 0.025f;
		desired_velocity = Normalize(desired_posistion - getPosition()) * 0.05f;

		steer = desired_velocity - velocity;

		velocity = velocity + steer;

		// build a new position vector by adding a scaled version of the velocity vector
		sf::Vector2f pos = getPosition() - velocity;

		// update our position
		setPosition(pos);
	}


	
}