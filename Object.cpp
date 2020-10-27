#include "Object.h"

Object::Object()
{
	glm::vec3 pos(0, 0, 0);
	glm::vec3 s(0, 0, 0);
	position = pos;
	scale = s;
	textureNo = 0;
	colour = s;
}

Object::Object(std::vector<vertex> verticies, glm::vec3 pos, glm::vec3 s, int textNum, glm::vec3 c)
{
	LoadInModel(verticies, pos, s, textNum, c);
}

Object::~Object()
{
	model.clear();
}


void Object::Display()
{
	glPushMatrix();
	{
		glTranslatef(position.x, position.y, position.z);
		glScalef(scale.x, scale.y, scale.z);
		glColor3f(colour.x, colour.y, colour.z);
		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glVertexPointer(3, GL_FLOAT, sizeof(vertex), &model[0].pos);
		glTexCoordPointer(2, GL_FLOAT, sizeof(vertex), &model[0].texture);
		glNormalPointer(GL_FLOAT, sizeof(vertex), &model[0].norm);
		glDrawArrays(GL_TRIANGLES, 0, model.size());
		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
	}
	glPopMatrix();

	//sphere.Display();
	//axisBox.Display();
}

void Object::SetScale(glm::vec3 s)
{
	scale = s;
}

glm::vec3 Object::GetScale() const
{
	return scale;
}

void Object::SetPosition(glm::vec3 pos)
{
	position = pos;
}

glm::vec3 Object::GetPosition() const
{
	return position;
}

BoundingBox Object::GetBoundingBox() const
{
	return axisBox;
}

void Object::SetBoundingBox(BoundingBox b)
{
	axisBox = b;
}

void Object::LoadInModel(std::vector<vertex> verticies, glm::vec3 pos, glm::vec3 s, int textNum, glm::vec3 c)
{
	model.swap(verticies);
	position = pos;
	scale = s;
	BoundingBox tempB(model, scale, position);
	BoundingSphere tempS(model, scale, position);
	axisBox = tempB;
	sphere = tempS;
	textureNo = textNum;
	colour = c;
}

std::vector<vertex> Object::GetFullModel()
{
	return model;
}

void Object::SetModel(vertex v, int i)
{
	model[i] = v;
}

vertex Object::GetModel(int i)
{
	return model[i];
}

void Object::SetTextureNo(int no)
{
	textureNo = no;
}

int Object::GetTextureNo() const
{
	return textureNo;
}

void Object::SetColour(glm::vec3 c)
{
	colour = c;
}

glm::vec3 Object::GetColour() const
{
	return colour;
}

void Object::Clear()
{
	model.clear();
}

BoundingSphere Object::GetBoundingSphere() const
{
	return sphere;
}

void Object::SetBoundingSphere(BoundingSphere bs)
{
	sphere = bs;
}