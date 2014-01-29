#include "math3.h"
#include "collidables.h"
namespace irr{
namespace core{
void checkCollision (Sphere sph1, Sphere sph2, float e){
	if (sph1.cm.distance(sph2.cm)<=sph1.R+sph2.R) collisionResponse(sph1,sph2,e);
}
void collisionResponse (Sphere sph1, Sphere sph2, float e){
	vector3df normal=sph2.cm-sph1.cm;
	float dist=sph1.cm.distance(sph2.cm);
	float penetration=sph1.R+sph2.R-dist;
	normal.normalize();
	float distcenter1 = sph1.cm.distance(Point(0,0,0));
	float distcenter2 = sph2.cm.distance(Point(0,0,0));
	if (distcenter2>distcenter1) sph1.cm=sph1.cm+penetration*normal;
	else sph2.cm=sph2.cm+penetration*normal;
	vector3df relative=sph1.speed-sph2.speed;
	float vdotn = normal.dotProduct(relative);
	float j=-((1+e)*vdotn)/2;
	sph1.speed+=j*normal;
	sph2.speed-=j*normal;
}
void UpdatePos(Sphere sph, float dt){
	sph.cm=sph.cm+sph.speed*dt;
}
}
}