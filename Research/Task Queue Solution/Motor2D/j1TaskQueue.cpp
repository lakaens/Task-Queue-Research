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
	if (entity->pos.x >= finalpos.x) {
		entity->pos.x = finalpos.x;
		ret = true;
	}
	else {
		entity->pos.x += entity->speed.x;
	}
	return ret;
}

bool MoveUp::Action()
{
	bool ret = false;
	if (entity->pos.y <= finalpos.y) {
		entity->pos.y = finalpos.y;
		ret = true;
	}
	else {
		entity->pos.y -= entity->speed.y;
	}
	return ret;
}

bool MoveDown::Action()
{
	bool ret = false;
	if (entity->pos.y >= finalpos.y) {
		entity->pos.y = finalpos.y;
		ret = true;
	}
	else {
		entity->pos.y += entity->speed.y;
	}
	return ret;
}

bool j1TaskQueue::Update(float dt)
{
	bool ret = false; 
	if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
	{
		
		if (auxiliar_task == nullptr && TaskQueue.size() != 0)
		{
			auxiliar_task = TaskQueue.front();
			auxiliar_task->InitTask();
			TaskQueue.pop();
		}
	}

	ret = ExecuteTasks();

	return ret;
}

bool j1TaskQueue::CleanUp()
{
	while (TaskQueue.size() != 0)
	{
		TaskQueue.pop();
		
	}
	return true;
}

bool j1TaskQueue::AddTasktoQueue(Task* task)
{
	
	TaskQueue.push(task);

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
				
				auxiliar_task = TaskQueue.front();
				auxiliar_task->InitTask();
				TaskQueue.pop();
				
				
			}
			else 
				auxiliar_task = nullptr;

		}
	}
	return true;
}
