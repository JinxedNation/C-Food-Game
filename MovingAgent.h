#pragma once
#include "Object.h"

/**
* @class MovingAgent
* @brief Class used to create moving agents going in a certain direction
*
* @author Christopher Logan
* @version 01
* @date 2/10/2020
*
* @bug no known bugs, but there may be some out there...
*/


class MovingAgent
{

	public:

		MovingAgent(){}

            ///The states of an object
		enum State
		{
                ///Stating still
			Still = 0,	
                ///Moving in a positive direction 
            Positive = 1,
                ///Moving in a negative direction
            Negative = 2
		};

			/**
            * @brief Getter for the speer value
            *
            * @return float speed
            */
		float GetSpeed() const { return speed; }

			/**
            * @brief Returns the max value
            *
            * @return float max
            */
		float GetMax() const { return max; }

			/**
            * @brief Returns the min value
            *
            * @return float min
            */
		float GetMin() const { return min; }

			/**
            * @brief Returns the collision value
            *
            * @return bool collision
            */
		bool GetCollision() { return collision; }
	
			/**
            * @brief Sets the value for speed
            *
            * @return void
            */
		void SetSpeed(float x) { speed = x; }

			/**
            * @brief Sets the maximum value
            *
            * @return void
            */
		void SetMax(float x) { max = x; }

			/**
            * @brief Sets the minimum value
            *
            * @return void
            */
		void SetMin(float x) { min = x; }

			/**
            * @brief Sets the collision
            *
            * @return void
            */
		void SetCollision(bool col) { collision = col; }

			/**
            * @brief Gets the current state
            *
            * @return State currentState
            */
		State GetCurrentState() const { return currentState; }

			/**
            * @brief Sets the current state
            *
            * @return void
            */
		void SetCurrentState(State s) { currentState = s; }	

			/**
            * @brief Gets the previous state
            *
            * @return State previousState
            */
		State GetPreviousState() const { return previousState; }

			/**
            * @brief Sets the previous state
            *
            * @return void
            */
		void SetPreviousState(State s) { previousState = s; }

			/**
            * @brief Updates the class each time it is called
            *
            * @return void
            */
		void Update();

			/**
            * @brief Sets the speed, min and maximum of the object
            *
            * @return void
            */
		void SetMainValues(float s, float mX, float mN);

			/**
            * @brief Setter for the obj
            *
            * Sets the object to be o
            *
            * @return void
            */
		void UpdateCollision(glm::vec3 player);

			/**
            * @brief Setter for the obj
            *
            * Sets the object to be o
            *
            * @return void
            */
		void SetObj(Object o) {obj = o;}

		    /**
            * @brief Getter for the obj
            *
            * Gets the object
            *
            * @return Object obj
            */
		Object GetObj() const {return obj;}

		    /**
            * @brief Gets the id for the ai
            *
            * Getter for the ai
            *
            * @return int machineId
            */
		int ID() const {return machineId;}

		    /**
            * @brief Sets the id for the agent
            *
            * @return void
            */
        void SetID(int i) { machineId = i; }

		    /**
            * @brief Sets the players position
            *
            * @return void
            */
		void SetPlayer(glm::vec3 pos) { player = pos; }

		    /**
            * @brief Gets the players positon
            *
            * @return vec3 player
            */
		glm::vec3 GetPlayer() const { return player; }

private:

		    /**
            * @brief Virtual move function that moves the agent
            *
            * @return void
            */
	    virtual void Move() = 0;

		    /**
            * @brief Virtual Check player positive
            *
            * @return bool
            */
	    virtual bool CheckPlayerPos() = 0;

		    /**
            * @brief Virtual Check player negative
            *
            * @return bool
            */
	    virtual bool CheckPlayerNeg() = 0;

            ///Position of the player
	    glm::vec3 player;

            ///Id of the agent
	    int machineId;

            ///Model and collision information of the agent
	    Object obj;

            ///current state of the agent
	    State currentState;

            ///previous state
	    State previousState;

            ///Speed of the agent
	    float speed;

            ///Maximum position of the agent
	    float max;

            ///Minimum position of the agent
	    float min;

            ///Collision varaible
	    bool collision;
};

