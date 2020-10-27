#include "MovingAgent.h"

void MovingAgent::SetMainValues(float s, float mX, float mN)

{
	speed = s;
	max = mX;
	min = mN;
}

void MovingAgent::UpdateCollision(glm::vec3 player)
{
	BoundingBox checkBox = GetObj().GetBoundingBox();
	SetCollision(checkBox.CheckCollision(player));
}

void MovingAgent::Update()
{
	State t;
	if ((GetCollision() || CheckPlayerNeg() || CheckPlayerPos()) && GetCurrentState() != Still)
	{
		//std::cout << "we here and collision and player neg is: " << GetCollision() << " " << CheckPlayerNeg() << std::endl;
		t = Still;
		SetPreviousState(GetCurrentState());
		SetCurrentState(t);
	}
	else if (!GetCollision() && GetCurrentState() == Still && !CheckPlayerNeg() && !CheckPlayerPos())
	{
		t = GetPreviousState();
		SetPreviousState(GetCurrentState());
		SetCurrentState(t);
	}

	Move();
	GetObj().Display();
}