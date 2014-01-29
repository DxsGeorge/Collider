#ifndef COLLIDABLES_H
#define COLLIDABLES_H
#include "math3.h"

class Sphere{
public:
	Point cm;
	float R;
	Vector3 speed;
};

class Molecule3{
public:
	Point cm;
	Sphere sph1;
	Sphere sph2;
	Sphere sph3;
	Matrix33 orientation;
	AxisAngle w;
	Matrix33 inertiaTensor;

};
#endif