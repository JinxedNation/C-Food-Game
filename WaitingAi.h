#pragma once
#include<string.h>
#include"Object.h"
#include"FrameTimer.h"
#include"texturedPolygons.h"

/**
* @class WaitingAi
* @brief AI that has a timner and is waiting to recieve its food, it will get frustrated and change state otherwise
*
* @author Christopher Logan
* @version 01
* @date 10/10/2020
*
*
* @bug no known bugs, but there may be some out there...
*/

class WaitingAi
{
	public:
		
			///The waiting state of the ai
		enum WaitingState
		{
			Angry, Waiting, Done
		};

		WaitingAi() {}
		WaitingAi(int i, std::string s, Object o, float t, std::vector<int> texts);

            /**
            * @brief Sets the id for the ai
            *
            * @return void
            */
		void SetId(int i) { id = i; }


		int GetId() const { return id; }

            /**
            * @brief Sets the tag for the ai
            *
            * @return void
            */
		void SetTag(std::string s) { tag = s; }
		std::string GetTag() const { return tag; }

		bool CompareTag(std::string s);

            /**
            * @brief Sets the object for the ai
            *
            * @return void
            */
		void SetObj(Object o) { obj = o; }
		Object GetObj() const { return obj; }

            /**
            * @brief Sets the state of the ai
            *
            * @return void
            */
		void SetState(WaitingState state) { currentState = state; }
		WaitingState GetState() const { return currentState; }

            /**
            * @brief Set paused state
            *
            * @return void
            */
		void SetPaused(bool p) { paused = p; }
		bool GetPaused() const { return paused; }

		void SetNew(int i, std::string s, Object o, float t, std::vector<int> texts);

            /**
            * @brief Sets the timer for the ai
            *
            * @return void
            */
		void SetTimer(float t) { timer = t; }
		float GetTimer() const { return timer; }
		void TimerTake(float t) { timer -= t; }
		
            /**
            * @brief Sets the countdown value for the ai
            *
            * @return void
            */
		void SetCountdown(float c) { countdown = c; }
		float GetCountdown() const { return countdown; }

            /**
            * @brief Sets the current texture for the ai
            *
            * @return void
            */
		void SetCurrentTexture(int i) { currentTexture = i; }
		int GetCurrentTexture() const { return currentTexture; }

            /**
            * @brief Sets textures vector for the ai
            *
            * @return void
            */
		void SetTextures(std::vector<int> texts) { textures = texts; }
		std::vector<int> GetTextures() const { return textures; }

		void SetDone();

		bool IsDone();

		void Update(float takeTime);

		int Score();

		void Reset();


	private:
		
		void CheckTimer();

			///Time between frames
		FrameTimer time;

			///currentState of the ai
		WaitingState currentState;

			///Tag for the ais food
		std::string tag;

			///Ai id
		int id;

			///paused state
		bool paused;

			///The timer for the ai
		float timer;

			///The timer value but does not change
		float countdown;

			///The object for the ai
		Object obj;
		int currentTexture;
		std::vector<int> textures;
};

