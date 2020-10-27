#ifndef PLAINNODE_H
#define PLAINNODE_H
/**
* @class PlainNode
* @brief Stores the details for each plain in a node that also holds another plain
*
*
* @author Shay Leary
* @version 01
* @date March 2005
*
*
* @bug no known bugs, but there may be some out there...
*/

#include <iostream>
#include <cmath>
#include <gl/glut.h>

class PlainNode
{

public:
	PlainNode () {Clear();}
    virtual ~PlainNode () {Clear();}

			/**
			* @brief Clears the next node
			*
			* @return void
			*/
	void  Clear   ();

			/**
			* @brief Gets the type of the plain
			*
			* @return GLdouble m_type
			*/
	GLdouble GetType () {return m_type;}

			/**
			* @brief Gets x start of the plain
			*
			* @return m_xPlainStart
			*/
	GLdouble GetXstart () {return m_xPlainStart;}

			/**
			* @brief Gets x end of the plain
			*
			* @return m_xPlainEnd
			*/
	GLdouble GetXend () {return m_xPlainEnd;}

			/**
			* @brief Gets y start of the plain
			*
			* @return m_yPlainStart
			*/
	GLdouble GetYstart () {return m_yPlainStart;}

			/**
			* @brief Gets y end of the plain
			*
			* @return m_yPlainEnd
			*/
	GLdouble GetYend () {return m_yPlainEnd;}

			/**
			* @brief Gets z start of the plain
			*
			* @return m_zPlainStart
			*/
	GLdouble GetZstart () {return m_zPlainStart;}

			/**
			* @brief Gets z end of the plain
			*
			* @return m_zPlainEnd
			*/
	GLdouble GetZend () {return m_zPlainEnd;}

    		/**
			* @brief Gets the next node held by this plainNode
			*
			* @return m_next
			*/
    PlainNode *GetNext () const {return m_next;}

    		/**
			* @brief Sets the data for the whole plain node
			*
			* @return m_next
			*/
	void SetData(const int tempType,
				 const GLdouble tempXs, const GLdouble tempXe,
				 const GLdouble tempYs, const GLdouble tempYe,
				 const GLdouble tempZs, const GLdouble tempZe);

    		/**
			* @brief Sets the address to the next node
			*
			* @return m_next
			*/
    void SetNext (PlainNode *next) {m_next = next;}

private:
    ///The address of the next node in the list
    PlainNode *m_next;

	///Stores type of plain: (0: flat plane) (1: incline from z to y) (2: incline from x to y)
	GLdouble m_type;
	

	///stores start and end co-ordinates of plane on x
	GLdouble m_xPlainStart, m_xPlainEnd;
	///stores start and end co-ordinates of plane on y
	GLdouble m_yPlainStart, m_yPlainEnd;
	///stores start and end co-ordinates of plane on z
	GLdouble m_zPlainStart, m_zPlainEnd;

    // Privatised copy constructor and assignment operator
    PlainNode (const PlainNode &newNode) {};
    PlainNode &operator = (const PlainNode &newNode) {};
};

#endif