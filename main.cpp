//--------------------------------------------------//
//													//	
//    Learning OpenGL: Εισαγωγικά Μαθήματα OpenGL   //
//													//
//    Πλατφόρμα ανάπτυξης παραδειγμάτων				//
//													//
//													//
//		Μάθημα 4ο									//
//--------------------------------------------------//


#include <stdio.h>     // - Just for some ASCII messages

#include <time.h>
#include <vector>
#include "gl/glut.h"   // - An interface and windows 
                       //   management library
#include "visuals.h"   // Header file for our OpenGL functions

////////////////// State Variables ////////////////////////
 ///Time
int N;
float R;
std::vector<Point> vertices;
std::vector<Vector3> speeds;


/////////////// Main Program ///////////////////////////

int main(int argc, char* argv[])
{ 
  
  printf("How many? \n");
  scanf("%d",&N);
  printf("radius? \n");
  scanf("%f",&R);
  vertices.reserve(N);
  speeds.reserve(N);
  if (vertices.size()!=speeds.size()) printf("error different sizes");
  srand(time(NULL));
  Point p;
  Vector3 sp;
  for (int i=0;i<N;i++){
	  
	  p.x=fmod(rand(),2*N*R);
	  
	  p.y=fmod(rand(),2*N*R);
	  
	  p.z=fmod(rand(),2*N*R);
	  //printf("%f %f %f \n",p.x,p.y,p.z);
	  vertices.push_back(p);
	  
	  sp.x=fmod(rand(),10.0);
	  
	  sp.y=fmod(rand(),10.0);
	  sp.z=fmod(rand(),10.0);
	  //printf("%f %f %f \n",sp.vx,sp.vy,sp.vz);
	  speeds.push_back(sp);
  }
  int mainwin;
  // initialize GLUT library state
  glutInit(&argc, argv);
	
  // Set up the display using the GLUT functions to 
  // get rid of the window setup details:
  // - Use true RGB colour mode ( and transparency )
  // - Enable double buffering for faster window update
  // - Allocate a Depth-Buffer in the system memory or 
  //   in the video memory if 3D acceleration available	
  glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE);
 
  
  // Define the main window size and initial position 
  // ( upper left corner, boundaries included )
  glutInitWindowSize(960,480);
  glutInitWindowPosition(50,50);
  
  // Create and label the main window
  mainwin=glutCreateWindow("Spheres!");

  
  
  // Configure various properties of the OpenGL rendering context
  Setup();
  
  // Callbacks for the GL and GLUT events:

  // The rendering function 
  glutDisplayFunc(Render);
  glutReshapeFunc(Resize);
  glutIdleFunc(Idle);

  //glutCreateSubWindow(mainwin,550,50,480,480);
  //glutPositionWindow(550,50);
  //Setup();
  //glutDisplayFunc(Render2);
  //glutReshapeFunc(Resize);
  //glutIdleFunc(Idle);
 
  //Enter main event handling loop
  glutMainLoop();
  return 0;


}  

