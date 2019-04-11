#ifndef _J1PLAYER_H__
#define _J1PLAYER_H__

#include "p2Point.h"
#include "SDL/include/SDL.h"

#include <queue>
#include "j1Entity.h"


class j1Player : public Entity
{
public:
	j1Player(int x, int y, ENTITY_TYPES type);
	virtual ~j1Player();

	bool Awake();

	bool Start();

	bool PreUpdate();

	void Move(float dt);

	bool CleanUp();
	
	
};



#endif // !_J1PLAYER_H__

