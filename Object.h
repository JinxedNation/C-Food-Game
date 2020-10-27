#include <iostream>
#include <fstream> 
#include <string>
#include <sstream>
#include <GL/glut.h>
#include <vector>
#include <cmath>
#include <glm.hpp>
#include "OBJLoader.h"
#include "BoundingBox.h"
#include "BoundingSphere.h"

/**
* @class Object
* @brief Storing the information for an asset
*
* This class holds a vertex which is used to draw a model, whilst also having a scale, 
* bounding box and postion for that model, it uses all of this information so that the object can be loaded in, 
* display and interacted with in the world
*
* @author Christopher Logan
* @version 01
* @date 30/08/2020
*
* @author Christopher Logan
* @version 02
* @date 2/09/2020
*
* @bug no known bugs, but there may be some out there...
*/

#pragma once
class Object
{
	public:
        Object();
        ~Object();
		Object(std::vector<vertex> verticies, glm::vec3 pos, glm::vec3 s, int textNum, glm::vec3 c);

            /**
            * @brief Setter for position
            *
            * Sets the position at the center of the object
            *
            * @return void
            */
        void SetPosition(glm::vec3 pos);

            /**
            * @brief Getter for the position
            *
            * Gets the position the object current is at the center
            *
            * @return vector3 positon
            */
		glm::vec3 GetPosition() const;

            /**
            * @brief Sets the scale
            *
            * Sets the scale for x, y, z positions
            *
            * @return void
            */
        void SetScale(glm::vec3 pos);

            /**
            * @brief Gets the scale
            *
            * Gets the scale which has x, y, z positions
            *
            * @return vec3 scale
            */
        glm::vec3 GetScale() const;

            /**
            * @brief Displays the object
            *
            * Displays the object at the position, with the scale, it has the vector position, texture co-ordinants and normals
            * for lighting if it is added
            *
            * @return void
            */
        void Display();

            /**
            * @brief Getter for axisBox
            *
            * Returns the axisBox bounding box from the class
            *
            * @return BoundingBox axisBox
            */
        BoundingBox GetBoundingBox() const;

            /**
            * @brief Setter for axisBox
            *
            * Sets the axisBox to value b
            *
            * @return void
            */
        void SetBoundingBox(BoundingBox b);

            /**
            * @brief Loads the model vertex, sets the position and scale
            *
            * This functon loads in the vertex for the model, sets it, sets the position, and sets the scale
            *
            * @return void
            */
        void LoadInModel(std::vector<vertex> verticies, glm::vec3 pos, glm::vec3 s, int textNum, glm::vec3 c);

            /**
            * @brief Setter for a model positon
            *
            * Sets a vertex to position i in the vertex
            *
            * @return void
            */
        void SetModel(vertex v, int i);

            /**
            * @brief Getter for model
            *
            * Gets the vertex from model position i
            *
            * @return vertex model[i]
            */
        vertex GetModel(int i);

            /**
            * @brief Gets the full model
            *
            * Gets the vertex model and returns it
            *
            * @return vector<vertex> model
            */
        std::vector<vertex> GetFullModel();

            /**
            * @brief Sets the texture number
            *
            * Sets the texture number used to set a texture
            *
            * @return void
            */
        void SetTextureNo(int no);

            /**
            * @brief Gets the texture number
            *
            * Gets the texture number used for binding the model
            *
            * @return int textureNo
            */
        int GetTextureNo() const;


            /**
            * @brief Sets the colour
            *
            * Takes in a colour set and sets to the colour
            *
            * @return void
            */
        void SetColour(glm::vec3 c);

            /**
            * @brief Gets the colour
            *
            * Gets the colour vector used
            *
            * @return vec3 colour
            */
        glm::vec3 GetColour() const;

            /**
            * @brief Clears the vertex vector
            *
            * @return void
            */
        void Clear();

            /**
            * @brief Gets the sphere
            *
            * Gets the bounding sphere and returns it
            *
            * @return BoundingSphere
            */
        BoundingSphere GetBoundingSphere() const;

            /**
            * @brief Sets the sphere
            *
            * Sets the 
            *
            * @return void
            */
        void SetBoundingSphere(BoundingSphere bs);

	private:

            ///The central position of the object
        glm::vec3 position;

            ///The scale of x, y, z
        glm::vec3 scale;

            ///The vector that holds the vertex model
        std::vector<vertex> model;

            ///The bounding box for the model
        BoundingBox axisBox;

        ///The bounding sphere for the model
        BoundingSphere sphere;

            ///The texture number to apply it
        int textureNo;
            ///The colour of the object
        glm::vec3 colour;
};

