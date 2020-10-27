#include "Zone.h"
Zone::Zone(glm::vec3 mX, glm::vec3 mN)
{
	SetMax(mX);
	SetMin(mN);
	zoneBox.SetMax(mX);
	zoneBox.SetMin(mN);
	SetActive(true);
}

void Zone::Change(glm::vec3 mX, glm::vec3 mN)
{
	SetMax(mX);
	SetMin(mN);
	zoneBox.SetMax(mX);
	zoneBox.SetMin(mN);
	SetActive(true);
}

void Zone::Update()
{
	if (active)
	{
		glColor3f(colour.x, colour.y, colour.z);
		zoneBox.DisplayFloor();
		inZone = zoneBox.CheckCollision(player);
	}
}