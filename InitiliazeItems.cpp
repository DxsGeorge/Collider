#include <stdio.h>
#include <vector>
#include <time.h>
#include "math3.h"

void Initialize(float choice, int N, float R)
{
	std::vector<Point> vertices;
	vertices.reserve(N);
	std::vector<Vector3> speeds;
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
}