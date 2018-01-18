/*This source code copyrighted by Lazy Foo' Productions (2004-2013)
and may not be redistributed without written permission.*/
//Version: 001

#include "LUtil.h"
#include "constant.h"
//void runMainLoop( int val );
/*
Pre Condition:
 -Initialized freeGLUT
Post Condition:
 -Calls the main loop functions and sets itself to be called back in 1000 / SCREEN_FPS milliseconds
Side Effects:
 -Sets glutTimerFunc
*/

int main( int argc, char* args[] )
{
	//Initialize FreeGLUT
	glutInit( &argc, args );

	//Create OpenGL 2.1 context
	glutInitContextVersion( 2, 1 );

	//Create Double Buffered Window
    //Option: GLUT_RGBA, GLUT_DEPTH, GLUT_DOUBLE
    //GLUT_DOUBLE use 2 buffer, one is saved for new drawing, and it replace the former one when change is done.
	glutInitDisplayMode( GLUT_DOUBLE );
    
	glutInitWindowSize( SCREEN_WIDTH, SCREEN_HEIGHT );
	glutCreateWindow( "OpenGL" );

	//Do post window/context creation initialization
	if( !initGL() )
	{
		printf( "Unable to initialize graphics library!\n" );
		return 1;
	}

	//Set rendering function
	glutDisplayFunc( GLrender ); //put rendering func
    glutKeyboardFunc(GLkeyboardInput);
    
    glutIdleFunc(GLidle);

	//Set main loop
	//glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, 0 );

	//Start GLUT main loop
    //This runs freeGLUT's internal main loop not our main loop.
	glutMainLoop();

	return 0;
}

/*
void runMainLoop( int val )
{
    //Frame logic
    //GLupdate();
    //GLrender();

    //Run frame one more time
    glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, val );
}
 */
