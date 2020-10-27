#include "functions.h"

//--------------------------------------------------------------------------------------
//  Main function 
//--------------------------------------------------------------------------------------
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 200);
	glutInitWindowSize(1280, 720);
	glutCreateWindow("Murdoch University Campus Tour");

	myinit();

	glutIgnoreKeyRepeat(1);
	glutSpecialFunc(movementKeys);
	glutSpecialUpFunc(releaseKey);
	glutKeyboardUpFunc(releaseKeys);
	glutKeyboardFunc(keys);

	glutDisplayFunc(Display);
	glutIdleFunc(Display);
	glutMouseFunc(Mouse);

	// ONLY USE IF REQUIRE MOUSE MOVEMENT
	glutPassiveMotionFunc(mouseMove);
	ShowCursor(FALSE);

	glutReshapeFunc(reshape);
	glutMainLoop();
	return(0);
}