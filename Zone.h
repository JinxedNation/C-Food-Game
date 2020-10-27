#pragma once
#include<glm.hpp>
#include<GL/glut.h>
#include"BoundingBox.h"
#include"Object.h"

class Zone
{
public:
	Zone() {}
	Zone(glm::vec3 mX, glm::vec3 mN);

	void SetMax(glm::vec3 pos) { max = pos; }
	void SetMin(glm::vec3 pos) { min = pos; }

	glm::vec3 GetMax() const { return max; }
	glm::vec3 GetMin() const { return min; }

	void SetZoneBox(BoundingBox b) { zoneBox = b; }
	BoundingBox GetZoneBox() const { return zoneBox; }

	void SetColour(glm::vec3 c) { colour = c; }
	glm::vec3 GetColour() const { return colour; }

	void SetPlayer(glm::vec3 p) { player = p; }
	glm::vec3 GetPlayer() const { return player; }

	void Update();

	void SetInZone(bool z) { inZone = z; }
	bool GetInZOne() const { return inZone; }

	void SetActive(bool z) { active = z; }
	bool GetActive() const { return active; }

	void Change(glm::vec3 mX, glm::vec3 mN);

private:

	bool active;
	glm::vec3 max;
	glm::vec3 min;
	BoundingBox zoneBox;
	glm::vec3 colour;
	glm::vec3 player;
	bool inZone;
};

