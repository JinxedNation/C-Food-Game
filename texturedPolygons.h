//  texturedPolygon.h
//  Header file for the texturedPolygon class
// 
//
//  Shay Leary, March 2005
//--------------------------------------------------------------------------------------

#ifndef TEXTURE_POLYGON_H
#define TEXTURE_POLYGON_H

//--------------------------------------------------------------------------------------

#include <gl/glut.h>
#include <iostream>

/**
* @class TexturedPolygons
* @brief loading in images to use for textures
*
* @author Shay Leary
* @version 01
* @date March 2005
*
*
* @bug no known bugs, but there may be some out there...
*/

class TexturedPolygons
{
public:

	TexturedPolygons () {}
    virtual ~TexturedPolygons () {Clear();}


            /**
            * @brief Gets the texture at tempIndex
            *
            * @return GLuint m_texture[tempIndex]
            */
	GLuint GetTexture (const int & tempIndex) {return m_texture[tempIndex];}

            /**
            * @brief Loads a raw image into memory
            *
            * @return GLubyte*
            */
	GLubyte* LoadTexture(char *filename, int imgWidth, int imgHeight);
	
            /**
            * @brief Sets the number of textures that will be used
            *
            * @return void
            */
	void SetTextureCount(const int &textureNo);


            /**
            * @brief Creates the texture and sets the values needed for mapping
            *
            * @return void
            */
	void CreateTexture(int textureNo, unsigned char* image, int imgWidth, int imgHeight);

			/**
			* @brief Creates the display list that holds the image/texture
			*
			* @return void
			*/
	void CreateDisplayList(const int &XYZ, const int &listNo, 
		                   const GLdouble &xImgSize, const GLdouble &zImgSize, 
					       const GLdouble &xStart, const GLdouble &yStart, const GLdouble &zStart,
					       const GLdouble &xTimes, const GLdouble &zTimes);

	// used to create display lists where image is larger than world scale on YZ axis

			/**
			* @brief Creates display list for images larger then world scale on yz
			*
			* @return void
			*/
	void CreateYtoZWindowList(const int &listNo, const GLdouble &xStart, 
							  const GLdouble &yStart, const GLdouble &ySize, 
							  const GLdouble &zStart, const GLdouble &zSize,
							  const GLdouble &yImgSize, const GLdouble &zImgSize);

			/**
			* @brief Creates display list for images larger then world scale on XY
			*
			* @return void
			*/
	void CreateXtoYWindowList(const int &listNo, const GLdouble &zStart, 
							  const GLdouble &xStart, const GLdouble &xSize, 
							  const GLdouble &yStart, const GLdouble &ySize,
							  const GLdouble &xImgSize, const GLdouble &yImgSize);
	
			/**
			* @brief Creates display list for images that are on an angle
			*
			* @return void
			*/
	void CreateAngledPolygon(const int &listNo, 
							 const GLdouble &imageWidth, const GLdouble &imageHeight,
							 const GLdouble &x1, const GLdouble &x2, 
							 const GLdouble &x3, const GLdouble &x4,
						     const GLdouble &y1, const GLdouble &y2,
							 const GLdouble &y3, const GLdouble &y4,
							 const GLdouble &z1, const GLdouble &z2,
							 const GLdouble &z3, const GLdouble &z4,
							 const int &smallestX, const int &smallestZ);

private:
	///pointer to display list
	GLuint *m_texture;

			/**
			* @brief Returns the image file
			*
			* @return GLubyte*
			*/
	GLubyte* LoadRawImageFile(char* filename, int width, int height);

			/**
			* @brief Deletes the texture/deletes it
			*
			* @return void
			*/
	void Clear ();


			/**
			* @brief Creates display list for images on the XZ Axis
			*
			* @return void
			*/
	void CreateXtoZTextureList(const GLdouble &xImgSize, const GLdouble &zImgSize, 
					           const GLdouble &xStart, const GLdouble &yStart, const GLdouble &zStart,
					           const GLdouble &xTimes, const GLdouble &zTimes);

			/**
			* @brief Creates display list for images on the XY Axis
			*
			* @return void
			*/
	void CreateXtoYTextureList(const GLdouble &xImgSize, const GLdouble &yImgSize, 
							   const GLdouble &xStart, const GLdouble &yStart, const GLdouble &zStart,
							   const GLdouble &xTimes, const GLdouble &yTimes, const bool &flip);

			/**
			* @brief Creates display list for images on the YZ Axis
			*
			* @return void
			*/
	void CreateYtoZTextureList(const GLdouble &yImgSize, const GLdouble &zImgSize, 
							   const GLdouble &xStart, const GLdouble &yStart, const GLdouble &zStart,
							   const GLdouble &yTimes, const GLdouble &zTimes, const bool &flip);
	
			/**
			* @brief Determines how the angled image will be displayed
			*
			* @return void
			*/
	void CreateTextureScale(GLdouble & xzImage1, GLdouble & xzImage2, 
							GLdouble & xzImage3, GLdouble & xzImage4,
							const GLdouble &imageSize);

    // Privatised copy constructor and assignment operator
    TexturedPolygons (const TexturedPolygons &tp) {};
    TexturedPolygons &operator = (const TexturedPolygons &tp) {};
};

#endif