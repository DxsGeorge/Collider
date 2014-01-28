#ifndef VISUALS_H
#define VISUALS_H
#include "math3.h"

extern int N,choice;
extern float R;
extern std::vector<Point> vertices;
extern std::vector<Vector3> speeds;
extern std::vector<Molecule3> mols;
extern std::vector<Vector3> vels;
//extern std::vector<Molecule3> mols;



//-------- Functions --------------------------------

void Render();
// The function responsible for drawing everything in the 
// OpenGL context associated to a window. 
void Render2();
void Resize(int w, int h);
// Handle the window size changes and define the world coordinate 
// system and projection type

void Setup();
// Set up the OpenGL state machine and create a light source

void Idle();

void Keyboard(unsigned char key,int x,int y);


#endif