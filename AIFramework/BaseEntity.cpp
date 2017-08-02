#include "BaseEntity.h"
#include "UtilRandom.h"

std::vector<BaseEntity*> BaseEntity::Renderables;
float angle;
int Behaviour = 2;
sf::Vector2f Normalise(sf::Vector2f vec){
	float mag = sqrt(vec.x*vec.x + vec.y*vec.y);
	return sf::Vector2f(vec.x / mag, vec.y / mag);
}


BaseEntity::BaseEntity()
{
	// with no further information, we make some assumptions and set default values.
	filename = "assets\\boid.png";
	colourTint = sf::Color::White;
	Initialize();
}

BaseEntity::BaseEntity(std::string file) : filename(file)
{
	// with just a texture file, we default to a white tint (so no tint at all).
	colourTint = sf::Color::White;
	Initialize();
}

BaseEntity::BaseEntity(std::string file, sf::Color colour) : filename(file), colourTint(colour)
{
	Initialize();
}

BaseEntity::~BaseEntity()
{
	
}

void BaseEntity::Think(sf::Vector2f Target)
{
	sf::Vector2f desired;
	// build a new position vector by adding a scaled version of the velocity vector

	if (Behaviour == 1) {
		desired = Normalise(Target - getPosition())*0.5f;
	}
	else if (Behaviour == 2) {
		desired = Normalise(getPosition() - Target)*0.5f;
	}

	else if (Behaviour == 3){
		sf::Vector2f CirclePos;
		float CircleAngle = UtilRandom::instance()->GetRange(0, 361);
		CirclePos.x = (getPosition().x + 100* velocity.x + 5 * sin(CircleAngle));
		CirclePos.y = (getPosition().y + 100*velocity.y + 5 * cos(CircleAngle));
		desired = Normalise( CirclePos - getPosition())*0.5f;
	}
	sf::Vector2f Steering = desired - velocity;
	velocity += Steering;

	// update our position
	//velocity = sf::Vector2f(cos(angle * M_PI / 180), sin(angle * M_PI / 180));
	sf::Vector2f pos = getPosition() + (velocity * 0.1f);
	setPosition(pos);
	setRotation(atan2f(velocity.y,velocity.x));

}

void BaseEntity::Initialize()
{
	// set a default position - could be randomised.
	setPosition(300.0f, 300.0f);

	// load the texture into memory
	texture.loadFromFile(filename);
	texture.setSmooth(true);
	// and provide the sprite with a pointer to the texture object
	// if the texture object is destroyed (goes out of scope etc) then the sprite will display weirdly
	sprite.setTexture(texture);
	// set up our colour tint
	sprite.setColor(colourTint);
	
	// select a random angle
	angle = UtilRandom::instance()->GetRange(0, 361);
	// set our rotation value
	setRotation(angle);
	// and assign a velocity, we need to convert angle to radians so it plays nicely with cos and sin.
	velocity = sf::Vector2f(cos(angle * M_PI / 180), sin(angle * M_PI / 180));

	// add the entity to the list of renderables.
	Renderables.push_back(this);
}