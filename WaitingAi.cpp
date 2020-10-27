#include "WaitingAi.h"

bool WaitingAi::CompareTag(std::string s)
{
	return (s == tag);
}

void WaitingAi::SetNew(int i, std::string s, Object o, float t, std::vector<int> texts)
{
	SetId(i);
	SetTag(s);
	SetObj(o);
	SetTimer(t);
	countdown = t;
	paused = false;
	currentTexture = 0;
	SetState(WaitingState::Waiting);
	SetTextures(texts);
}

WaitingAi::WaitingAi(int i, std::string s, Object o, float t, std::vector<int> texts)
{
	SetNew(i, s, o, t, texts);
}

void WaitingAi::Update(float takeTime)
{
	obj.Display();

	if (GetState() == WaitingState::Done)
	{
		SetCurrentTexture(4);
		SetState(WaitingState::Done);
	}
		
	if (!paused)
	{
		if (GetState() != WaitingAi::Done)
		{
			TimerTake(takeTime);
			//std::cout << "Timer: " << GetTimer() << ", current texture: " << GetCurrentTexture() << ", Countdown: " << GetCountdown() << std::endl;
			CheckTimer();
		}
	}
}

void WaitingAi::CheckTimer()
{
	if (currentState == WaitingState::Waiting)
	{
		if (timer < countdown / 2 && timer > countdown / 4)
		{
			SetCurrentTexture(1);
		}
		else if (timer < countdown / 4 && timer > 0)
		{
			SetCurrentTexture(2);
		}
		else if(timer <= 0)
		{
			SetCurrentTexture(3);
			SetState(WaitingState::Angry);
		}
	}	
}

int WaitingAi::Score()
{
	if (currentTexture == 0)
		return 100;
	else if (currentTexture == 1)
		return 50;
	else if (currentTexture == 2)
		return 25;
	else if (currentTexture == 3)
		return 1;
}

void WaitingAi::SetDone()
{
	SetState(WaitingState::Done);
}

bool WaitingAi::IsDone()
{
	if (GetState() == WaitingState::Done)
		return true;
	else
		return false;
}

void WaitingAi::Reset()
{
	timer = countdown;
	currentState = WaitingState::Waiting;
	currentTexture = 0;
}