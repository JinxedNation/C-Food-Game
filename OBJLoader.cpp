#include "OBJLoader.h"

OBJLoader::OBJLoader()
{
	
}

OBJLoader::~OBJLoader()
{
	Clear();
}

OBJLoader:: OBJLoader(std::string name)
{
	LoadFile(name);
}

void OBJLoader::LoadFile(std::string name)
{
	std::vector<glm::vec3> tempPos;
	std::vector<glm::vec2> tempTexture;
	std::vector<glm::vec3> tempNorm;
	std::string store;
	verticies.clear();

	std::ifstream obj;
	obj.open(name);

	if (obj.is_open())
	{
		std::cout << "Loading model " << name << ".............." << std::endl;
		while (getline(obj, store))
		{
			std::istringstream ss(store);
			std::string prefix;
			ss >> prefix;

			if (prefix == "v")
			{
				float x, y, z;
				ss >> x >> y >> z;
				glm::vec3 t(x, y, z);
				tempPos.push_back(t);
			}
			else if (prefix == "vt")
			{
				float x, y;
				ss >> x >> y;
				glm::vec2 t(x, y);
				tempTexture.push_back(t);
			}
			else if (prefix == "vn")
			{
				float x, y, z;
				ss >> x >> y >> z;
				glm::vec3 t(x, y, z);
				tempNorm.push_back(t);
			}
			else if (prefix == "f")
			{
				std::string faceString[3], tempStr[3];
				ss >> faceString[0] >> faceString[1] >> faceString[2];
				int f[3];
				for (int i = 0; i < 3; i++)
				{
					std::stringstream fSS(faceString[i]);
					getline(fSS, tempStr[0], '/');
					getline(fSS, tempStr[1], '/');
					getline(fSS, tempStr[2], '/');
					int v = atoi(tempStr[0].c_str());
					int vt = atoi(tempStr[1].c_str());
					int vn = atoi(tempStr[2].c_str());
					glm::vec3 tPos = tempPos[v - 1];
					glm::vec2 tText = tempTexture[vt - 1];
					glm::vec3 tNorm = tempNorm[vn - 1];
					vertex tempV(tPos, tText, tNorm);
					verticies.push_back(tempV);
				}
			}
		}
	}
}

std::vector<vertex> OBJLoader::GetFullVertex()
{
	return verticies;
}

void OBJLoader::SetVertex(vertex v, int i)
{
	verticies[i] = v;
}

vertex OBJLoader::GetVertex(int i)
{
	return verticies[i];
}

void OBJLoader::Clear()
{
	verticies.clear();
}