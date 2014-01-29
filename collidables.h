#ifndef COLLIDABLES_H
#define COLLIDABLES_H
#include "math3.h"
#include "vector3d.h"
#include "quaternion.h"

class Sphere{
public:
	Point cm;
	float R;
	irr::core::vector3df speed;
};

class Molecule3{
public:
	Point cm;
	float R;
	irr::core::vector3df sph1;
	irr::core::vector3df sph2;
	irr::core::vector3df sph3;
	irr::core::quaternion orientation;
	AxisAngle w;
	Matrix33 inertiaTensor;

};
#endif