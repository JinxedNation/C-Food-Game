#ifndef PLAINLINKED_LIST_H
#define PLAINLINKED_LIST_H


#include "PlainNode.h"

/**
* @class PlainLinkedList
* @brief Link list that is used to store nodes (PlainNode) which hold the co-ordinats of each plain used in the program
*
*
* @author Shay Leary
* @version 01
* @date March 2005
*
*
* @bug no known bugs, but there may be some out there...
*/

class PlainLinkedList
{
public:
	// constructor creates pointer to first node
	PlainLinkedList() {m_first = new PlainNode;}

	virtual ~PlainLinkedList() {Clear();}

			/**
			* @brief Clears the linked list, clearing memory
			*
			* @return void
			*/
	void Clear();

			/**
			* @brief Adds a node to the end of a linked list
			*
			* @return bool true or false
			*/
	bool AddToStart (const int tempType,
				     const GLdouble tempXs, const GLdouble tempXe,
				     const GLdouble tempYs, const GLdouble tempYe,
				     const GLdouble tempZs, const GLdouble tempZe);
	
			/**
			* @brief Sets value to a node
			*
			* @return void
			*/
	void SetData(const int &ptrCount, const int tempType,
				 const GLdouble tempXs, const GLdouble tempXe,
				 const GLdouble tempYs, const GLdouble tempYe,
				 const GLdouble tempZs, const GLdouble tempZe);

			/**
			* @brief Gets the type of the plain
			*
			* @return GLdouble m_type
			*/
	GLdouble GetType (int ptrCount);

			/**
			* @brief Gets x start of the plain
			*
			* @return m_xPlainStart
			*/
	GLdouble GetXstart (int ptrCount);

			/**
			* @brief Gets x end of the plain
			*
			* @return m_xPlainEnd
			*/
	GLdouble GetXend (int ptrCount);

			/**
			* @brief Gets y start of the plain
			*
			* @return m_yPlainStart
			*/
	GLdouble GetYstart (int ptrCount);


			/**
			* @brief Gets y end of the plain
			*
			* @return m_yPlainEnd
			*/
	GLdouble GetYend (int ptrCount);

			/**
			* @brief Gets z start of the plain
			*
			* @return m_zPlainStart
			*/
	GLdouble GetZstart (int ptrCount);

			/**
			* @brief Gets z end of the plain
			*
			* @return m_zPlainEnd
			*/
	GLdouble GetZend (int ptrCount);

			/**
			* @brief Gets the size of the linked list
			*
			* @return int size
			*/
	int GetListSize ();
	
			/**
			* @brief Gets the next node
			*
			* @return PlainNode
			*/
    PlainNode *GetNext () const {return m_first->GetNext();}

			/**
			* @brief Gets the first node
			*
			* @return PlainNode
			*/
	PlainNode *GetFirst() const {return m_first;}


//--------------------------------------------------------------------------------------

private:
	///pointer to first node in list
	PlainNode *m_first;

			/**
			* @brief Clears memory
			*
			* @return void
			*/
	void Delete (PlainNode *before);

	// Privatised copy constructor and assignment operator
	PlainLinkedList (const PlainLinkedList &array) {};
	PlainLinkedList &operator = (const PlainLinkedList &array) {};
};

#endif

//--------------------------------------------------------------------------------------