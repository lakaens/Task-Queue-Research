#include "j1Player.h"
#include "j1Render.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Scene.h"
#include "j1Map.h"
#include "j1Entity.h"
#include "j1TaskQueue.h"

j1Player::j1Player(int x, int y, ENTITY_TYPES type) : Entity(x, y, type)
{

}

j1Player::~j1Player()
{
}

bool j1Player::Awake()
{
	
	return true;
}

bool j1Player::Start()
{
	



	return true;
}

bool j1Player::PreUpdate()
{
	return true;
}

void j1Player::Move(float dt)
{
	//TODO 6: Add a new movement task to the queue for each key pressed for the four directions.
	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_DOWN)
	{
		
	}
	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_DOWN)
	{
		
		

	}
	if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_DOWN)
	{
		
		
	}
	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_DOWN)
	{
		
		
	}

}


bool j1Player::CleanUp()
{
	
	
	return true;
}



