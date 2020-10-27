#pragma once

#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
#include <glm.hpp>
#include<vector>

/**
* @class OBJLoader
* @brief Obtaining obj file information
*
* This class is used to gather information from an obj file, this is stored into a 
* vector of vertex, which holds the positions, texture postions and normals of the obj file.
* The LoadFile function is what stores and sorts the data from the file
*
* @author Christopher Logan
* @version 01
* @date 1/09/2020
*
*
* @bug no known bugs, but there may be some out there...
*/

	///Vertex struct that holds the postion, texture and normal vector 3s for a point
struct vertex
{
		///The position co-ordinant(v)
	glm::vec3 pos;
		///The texture co-ordinant(vt)
	glm::vec2 texture;
		///The normal co-ordinant(vn)
	glm::vec3 norm;

	vertex(glm::vec3 p, glm::vec2 t, glm::vec3 n)
	{
		pos = p;
		texture = t;
		norm = n;
	}
};

class OBJLoader
{
public:
	OBJLoader();
    ~OBJLoader();
	OBJLoader(std::string name);

            /**
            * @brief Setter for vertex point i
            *
            * Sets a vertex to the vector at point i
            *
            * @return void
            */
	void SetVertex(vertex v, int i);

            /**
            * @brief Getter for vertex at position i
            *
            * Returns the vertex at postion i of vector verticies
            *
            * @return void
            */
	vertex GetVertex(int i);

            /**
            * @brief Gets the full verticies
            *
            * Gets the vertex model and returns it
            *
            * @return vector<vertex> verticies
            */
	std::vector<vertex> GetFullVertex();

            /**
            * @brief Loads the obj file into the vertex
            *
            * Loads the obj file and put its contents into the vertex vector
            *
            * @return void
            */
	void LoadFile(std::string name);

            /**
            * @brief Clears the vertex vector
            * 
            * @return void
            */
    void Clear();

private:
	
        ///Vector that holds the verticies
	std::vector <vertex> verticies;
};

