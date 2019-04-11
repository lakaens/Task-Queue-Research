#include "j1App.h"
#include "j1Entity.h"
#include "j1Input.h"
#include "j1TaskQueue.h"



bool MoveLeft::Action()
{
	bool ret = false;
	if (entity->pos.x <= finalpos.x) {
		entity->pos.x = finalpos.x;
		ret = true;
	}
	else {
		entity->pos.x -= entity->speed.x;
	}

	return ret;
}

bool MoveRight::Action()
{
	bool ret = false;
	//TODO 4: Implement the code for the movility of the Right direction. Hint: You have already implemented the MoveLeft:Action method above
	
	
	return ret;
}

bool MoveUp::Action()
{
	bool ret = false;
	//TODO 4: Implement the code for the movility of the Up direction. Hint: You have already implemented the MoveLeft:Action method above
	
	
	return ret;
}

bool MoveDown::Action()
{
	bool ret = false;
	//TODO 4: Implement the code for the movility of the Down direction. Hint: You have already implemented the MoveLeft:Action method above
	
	
	return ret;
}

bool j1TaskQueue::Update(float dt)
{
	bool ret = false; 
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
	{
		
		if (auxiliar_task == nullptr && TaskQueue.size() != 0)
		{
			//TODO 5: Assign the first element of the queue to the auxiliar_task, call InitTask function for auxiliar_task and make a pop of the queue.
			
		}
	}

	ret = ExecuteTasks();

	return ret;
}

bool j1TaskQueue::CleanUp()
{
	//TODO 3: Pop queue tasks
	
	return true;
}

bool j1TaskQueue::AddTasktoQueue(Task* task)
{
	//TODO 1: Add task to Queue
	

	return true;
}

bool j1TaskQueue::ExecuteTasks()
{
	
	if (auxiliar_task != nullptr)
	{
		
		if (auxiliar_task->Action())
		{
			if (TaskQueue.size() != 0)
			{
				//TODO 2: Assign the first element of the queue to the auxiliar_task, call InitTask function for auxiliar_task and make a pop of the queue.
				
				
				
			}
			else 
				auxiliar_task = nullptr;

		}
	}
	return true;
}
