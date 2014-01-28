#ifndef MATH_H
#define MATH_H


class Point{
public:
	float x;
	float y;
	float z;
	Point (float _x, float _y, float _z){
		x=_x;
		y=_y;
		z=_z;
	}
	Point(){
		x=0;
		y=0;
		z=0;
	}
};

class Vector3 {
	
public:
	float x;
	float y;
	float z;
	Vector3 (float _x,float _y,float _z){
		x=_x;
		y=_y;
		z=_z;
	}
	Vector3 (){
		x=0;
		y=0;
		z=0;
	}
	float magnitude(){
		float magn=sqrt(this->x*this->x+this->y*this->y+this->z*this->z);
		return magn;
	}
	void normalize(){
		float magn=this->magnitude();
		this->x=this->x/magn;
		this->y=this->y/magn;
		this->z=this->z/magn;
	}
	Vector3 operator+(Vector3 v){
		return Vector3(v.x+x,v.y+y,v.z+z);
	}
	float operator*(Vector3 v){
		return (v.x*x+v.y*y+v.z*z);
	}
	Vector3 operator*(float f){
		return Vector3(f*x,y*f,z*f);
	}
	Vector3 operator/(float f){
		return Vector3 (x/f,y/f,z/f);
	}
	Vector3 operator=(Vector3 v){
		return Vector3 (x=v.x,y=v.y,z=v.z);
	}
	Vector3 operator-(Vector3 v) {
		return Vector3(x-v.x,y-v.y,z+v.z);
	}
	Vector3 cross(Vector3 v) {
		return Vector3(x*v.z-z*v.y,z*v.x-x*v.z,x*v.y-y*v.x);
	}
};

class Matrix33{
	Vector3 v1; //row1
	Vector3 v2; //row2
	Vector3 v3; //row3
	Matrix33 (Vector3 _v1, Vector3 _v2, Vector3 _v3){
		v1=_v1;
		v2=_v2;
		v3=_v3;
	}
	Matrix33 (){
		Vector3 v1,v2,v3;
	}
	float Det(){
		return v1.z*v2.x*v3.y+v1.x*v2.y*v3.z+v1.y*v2.z*v3.x-v1.x*v2.x*v3.z-v1.z*v2.y*v3.x-v1.x*v2.z*v3.y;
	}
	Matrix33 Inverse(){
		float det=this->Det();
		Vector3 row1 ((v2.y*v3.z-v2.z*v3.y)/det,(v1.z*v3.y-v1.y*v3.z)/det,(v1.y*v2.z-v1.z*v2.y)/det);
		Vector3 row2 ((v2.z*v3.x-v2.x*v3.z)/det,(v1.x*v3.z-v1.z*v3.x)/det,(v1.z*v2.x-v1.x*v2.z)/det);
		Vector3 row3 ((v2.x*v3.y-v2.y*v3.x)/det,(v1.y*v3.x-v1.x*v3.y)/det,(v1.x*v2.y-v1.y*v2.x)/det);
		return Matrix33 (row1,row2,row3);
	}
	Matrix33 fromAxisAngle(Vector3 v, float angle){
		angle*=3.14/180;
		Vector3 row1 (cos(angle)+v.x*v.x*(1-cos(angle)), 
			          v.x*v.y*(1-cos(angle))-v.z*sin(angle),
					  v.x*v.z*(1-cos(angle))+v.y*sin(angle));
		Vector3 row2 (v.y*v.x*(1-cos(angle))+v.z*sin(angle),
					  cos(angle)+v.z*v.z*(1-cos(angle)),
					  v.y*v.z*(1-cos(angle))-v.x*sin(angle));
		Vector3 row3 (v.z*v.x*(1-cos(angle))-v.y*sin(angle),
					  v.z*v.y*(1-cos(angle))+v.x*sin(angle),
					  cos(angle)+v.z*v.z*(1-cos(angle)));
		return Matrix33 (row1,row2, row3);
	}
	Vector3 operator*(Vector3 v){
		float a=v1.x*v.x+v1.y*v.y+v1.z*v.z;
		float b=v2.x*v.x+v2.y*v.y+v2.z*v.z;
		float c=v3.x*v.x+v3.y*v.y+v3.z*v.z;
		return Vector3 (a,b,c);
	}
};

class AxisAngle{
public:
	Vector3 v;
	float angle;
};

class Molecule3{
public:
	Point cm;
	Vector3 v1;
	Vector3 v2;
	Vector3 v3;
	Matrix33 orientation;
	AxisAngle w;
	Matrix33 inertiaTensor;

};

#endif