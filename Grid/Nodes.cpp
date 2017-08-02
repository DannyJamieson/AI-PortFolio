#include "Nodes.h"



Nodes::Nodes()
{
	std::cout << "In Nodes Constructor" << std::endl;
	filename = "assets\\box.png";
	colourTint = sf::Color::White;
	//Initialize();
}


Nodes::~Nodes()
{
}

void Nodes::Initialize()
{

	std::cout << "In Nodes Initialize" << std::endl;

	// set a default position - could be randomised.
	setPosition(x * size, y * size);

	// load the texture into memory
	texture.loadFromFile(filename);	
	texture.setSmooth(true);
	// and provide the sprite with a pointer to the texture object
	// if the texture object is destroyed (goes out of scope etc) then the sprite will display weirdly
	sprite.setTexture(texture);
	// set up our colour tint
	sprite.setColor(colourTint);

	// add the entity to the list of renderables.
	Renderables.push_back(this);
}

