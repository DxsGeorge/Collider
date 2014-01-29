#include <stdio.h>     // - Just for some ASCII messages
#include <time.h>
#include <vector>
#include <math.h>
#include "gl/glut.h"   // - An interface and windows 
//   management library
#include "visuals.h"   // Header file for our OpenGL functions
#include "math3.h"
#include "collidables.h"



int count_wall=0,count_sph=0;
float t=0;
std::vector<int> counter_wall;
std::vector<int> counter_sphere;
static float rotx = 0.0;
static float roty = 0.0;
static float rotz = 0.0;
static float tranx = 0.0;
static float trany = 0.0;
static float tranz = 0.0;

void axes()
{
	glColor3f(0.6, 0.6, 0.6);
	glPushMatrix();
	glTranslatef(0, 0, -1.0);
	glBegin(GL_LINES);
	glVertex2f(0.0,0.0);
	glVertex2f(100.0,0.0);
	glVertex2f(0.0,0.0);
	glVertex2f(0.0,100.0);
	glEnd();
	glPopMatrix(); 
}

void Box(int N, float R){
	glColor4f(1,1,1,0.2);
	glBegin(GL_POLYGON);
	glVertex3f(-4*N*R,-4*N*R,4*N*R);
	glVertex3f(4*N*R,-4*N*R,4*N*R);
	glVertex3f(4*N*R,4*N*R,4*N*R);
	glVertex3f(-4*N*R,4*N*R,4*N*R);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-4*N*R,-4*N*R,-4*N*R);
	glVertex3f(-4*N*R,4*N*R,-4*N*R);
	glVertex3f(-4*N*R,4*N*R,4*N*R);
	glVertex3f(-4*N*R,-4*N*R,4*N*R);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(4*N*R,-4*N*R,-4*N*R);
	glVertex3f(4*N*R,4*N*R,-4*N*R);
	glVertex3f(4*N*R,4*N*R,4*N*R);
	glVertex3f(4*N*R,-4*N*R,4*N*R);
	glEnd();
	glBegin(GL_POLYGON);
	glVertex3f(-4*N*R,-4*N*R,-4*N*R);
	glVertex3f(4*N*R,-4*N*R,-4*N*R);
	glVertex3f(4*N*R,4*N*R,-4*N*R);
	glVertex3f(-4*N*R,4*N*R,-4*N*R);
	glEnd();
	/*glBegin(GL_POLYGON);
	glVertex3f(-4*N*R,-4*N*R,4*N*R);
	glVertex3f(4*N*R,-4*N*R,4*N*R);
	glVertex3f(4*N*R,-4*N*R,-4*N*R);
	glVertex3f(-4*N*R,-4*N*R,-4*N*R);
	glEnd();*/
	/*glBegin(GL_POLYGON);
	glVertex3f(-4*N*R,4*N*R,4*N*R);
	glVertex3f(4*N*R,4*N*R,4*N*R);
	glVertex3f(4*N*R,4*N*R,-4*N*R);
	glVertex3f(-4*N*R,4*N*R,-4*N*R);
	glEnd();*/
	glColor4f(0,0,1,1);
	glBegin(GL_LINES);
	glVertex3f(-4*N*R,-4*N*R,4*N*R);
	glVertex3f(4*N*R,-4*N*R,4*N*R);
	glVertex3f(4*N*R,-4*N*R,4*N*R);
	glVertex3f(4*N*R,4*N*R,4*N*R);
	glVertex3f(4*N*R,4*N*R,4*N*R);
	glVertex3f(-4*N*R,4*N*R,4*N*R);
	glVertex3f(-4*N*R,-4*N*R,4*N*R);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(-4*N*R,-4*N*R,-4*N*R);
	glVertex3f(-4*N*R,4*N*R,-4*N*R);
	glVertex3f(-4*N*R,4*N*R,-4*N*R);
	glVertex3f(-4*N*R,4*N*R,4*N*R);
	glVertex3f(-4*N*R,4*N*R,4*N*R);
	glVertex3f(-4*N*R,-4*N*R,4*N*R);
	glVertex3f(-4*N*R,-4*N*R,-4*N*R);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(4*N*R,-4*N*R,-4*N*R);
	glVertex3f(4*N*R,4*N*R,-4*N*R);
	glVertex3f(4*N*R,4*N*R,-4*N*R);
	glVertex3f(4*N*R,4*N*R,4*N*R);
	glVertex3f(4*N*R,4*N*R,4*N*R);
	glVertex3f(4*N*R,-4*N*R,4*N*R);
	glVertex3f(4*N*R,-4*N*R,-4*N*R);
	glEnd();
}

void WallGraph(std::vector<int> count) {
	glBegin(GL_LINES);
	if (count.size()>0) {
		for (int i=0;i<count.size() && i<350;i++){
			glVertex3f(i*0.1,counter_wall.at(i)*0.1,0);
		}
	}
	glEnd();
}

void Render()
{    
	glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0,0,-8*N*R);
	//glRotatef(45,0,1,0);
	glTranslatef(tranx,trany,tranz);
	glRotatef(rotx,1,0,0);
	glRotatef(roty,0,1,0);
	glRotatef(rotz,0,0,1);
	//Box(N,R);
	glColor4f(1,0,0,1.0);
	if (choice==1){
		for (int i=0;i<int(vertices.size());i++){
			glPushMatrix();
			glTranslatef(vertices.at(i).x,vertices.at(i).y,vertices.at(i).z);
			//glRotatef(f,1,0,0);
			glutSolidSphere(R,30,30);
			glPopMatrix();
		}
	}
	else {
		for (int i=0;i<mols.size();i++){
			glPushMatrix();
			glTranslatef(mols.at(i).cm.x,mols.at(i).cm.y,mols.at(i).cm.z);
			glPushMatrix();
			glTranslatef(mols.at(i).v1.x,mols.at(i).v1.y,mols.at(i).v1.z);
			glutSolidSphere(R,20,20);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(mols.at(i).v2.x,mols.at(i).v2.y,mols.at(i).v2.z);
			glutSolidSphere(R,20,20);
			glPopMatrix();
			glPushMatrix();
			glTranslatef(mols.at(i).v3.x,mols.at(i).v3.y,mols.at(i).v3.z);
			glutSolidSphere(R,20,20);
			glPopMatrix();
			//glRotatef(mols.at(i).orientation.W,mols.at(i).orientation.X,mols.at(i).orientation.Y,mols.at(i).orientation.Z);
			glPopMatrix();
		}
	}
	/*glColor3f(1,1,1);
	glPushMatrix();
	glTranslatef(2*N*R+10,-2*N*R,0);
	WallGraph(counter_wall);
	glColor3f(0,1,0);
	glTranslatef(2,0,0);
	WallGraph(counter_sphere);
	glPopMatrix();*/


	glutSwapBuffers();
}

//-----------------------------------------------------------


void Idle()
{
	t+=0.01;
	float dt=0.01;
	if (choice==1){
		for (int i=0;i<vertices.size();i++){
			for (int j=i+1;j<vertices.size();j++){
				float x12=vertices.at(i).x-vertices.at(j).x;
				float y12=vertices.at(i).y-vertices.at(j).y;
				float z12=vertices.at(i).z-vertices.at(j).z;
				float d=sqrt(pow(x12,2)+pow(y12,2)+pow(z12,2));
				if (d<=2*R) {
					count_sph++;
					counter_sphere.push_back(count_sph);
					float d1=pow(vertices.at(i).x,2)+pow(vertices.at(i).y,2)+pow(vertices.at(i).z,2);
					float d2=pow(vertices.at(j).x,2)+pow(vertices.at(j).y,2)+pow(vertices.at(j).z,2);
					if (d2>d1) {
						float p12x=vertices.at(i).x-vertices.at(j).x;
						float p12y=vertices.at(i).y-vertices.at(j).y;
						float p12z=vertices.at(i).z-vertices.at(j).z;
						float p=sqrt(pow(p12x,2)+pow(p12y,2)+pow(p12z,2));
						float var=2*R/p;
						vertices.at(i).x=vertices.at(j).x+p12x*var;
						vertices.at(i).y=vertices.at(j).y+p12y*var;
						vertices.at(i).z=vertices.at(j).z+p12z*var;
					}
					else {
						float p12x=vertices.at(j).x-vertices.at(i).x;
						float p12y=vertices.at(j).y-vertices.at(i).y;
						float p12z=vertices.at(j).z-vertices.at(i).z;
						float p=sqrt(pow(p12x,2)+pow(p12y,2)+pow(p12z,2));
						float var=2*R/p;
						vertices.at(j).x=vertices.at(i).x+p12x*var;
						vertices.at(j).y=vertices.at(i).y+p12y*var;
						vertices.at(j).z=vertices.at(i).z+p12z*var;
					}
					float v1=sqrt(pow(speeds.at(i).x,2)+pow(speeds.at(i).y,2)+pow(speeds.at(i).z,2));
					float v2=sqrt(pow(speeds.at(j).x,2)+pow(speeds.at(j).y,2)+pow(speeds.at(j).z,2));
					float en1=pow(v1,2)+pow(v2,2);
					Vector3 n;
					n.x=vertices.at(i).x-vertices.at(j).x;
					n.y=vertices.at(i).y-vertices.at(j).y;
					n.z=vertices.at(i).z-vertices.at(j).z;
					float magn=magn3(n);
					n=Normalize3(n);
					float e=1;
					Vector3 v12;
					v12.x=speeds.at(i).x-speeds.at(j).x;
					v12.y=speeds.at(i).y-speeds.at(j).y;
					v12.z=speeds.at(i).z-speeds.at(j).z;
					float nv12=Dot3(n,v12);
					float jn=(-(1+e)*nv12)/2;
					speeds.at(i).x=speeds.at(i).x+jn*n.x;
					speeds.at(i).y=speeds.at(i).y+jn*n.y;
					speeds.at(i).z=speeds.at(i).z+jn*n.z;
					speeds.at(j).x=speeds.at(j).x-jn*n.x;
					speeds.at(j).y=speeds.at(j).y-jn*n.y;
					speeds.at(j).z=speeds.at(j).z-jn*n.z;
					v1=sqrt(pow(speeds.at(i).x,2)+pow(speeds.at(i).y,2)+pow(speeds.at(i).z,2));
					v2=sqrt(pow(speeds.at(j).x,2)+pow(speeds.at(j).y,2)+pow(speeds.at(j).z,2));
					float en2=pow(v1,2)+pow(v2,2);
					if (en1!=en2) printf("%f \n",en1-en2);
				}
			}
			if (!(vertices.at(i).x+R<N*R/2 && vertices.at(i).x-R>-N*R/2)) {
				count_wall++;
				counter_wall.push_back(count_wall);
				speeds.at(i).x=-speeds.at(i).x;
			}
			if (!(vertices.at(i).y+R<N*R/2 && vertices.at(i).y-R>-N*R/2)) {
				count_wall++;
				counter_wall.push_back(count_wall);
				speeds.at(i).y=-speeds.at(i).y;
			}
			if (!(vertices.at(i).z+R<N*R/2 && vertices.at(i).z-R>-N*R/2)) {
				count_wall++;
				counter_wall.push_back(count_wall);
				speeds.at(i).z=-speeds.at(i).z;
			}
			vertices.at(i).x=vertices.at(i).x+speeds.at(i).x*dt;
			vertices.at(i).y=vertices.at(i).y+speeds.at(i).y*dt;
			vertices.at(i).z=vertices.at(i).z+speeds.at(i).z*dt;
		}
	}
	
	glutPostRedisplay(); 
}


//-----------------------------------------------------------

void Resize(int w, int h)
{ 
	// define the visible area of the window ( in pixels )
	if (h==0) h=1;
	glViewport(0,0,w,h); 

	// Setup viewing volume

	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();

	//glOrtho(-4*N*R,4*N*R,-4*N*R,4*N*R,4*N*R,-4*N*R);


	float aspect = (float)w/(float)h;             /// aspect ratio
	gluPerspective(60.0, aspect, 1.0, 500.0+N*R);
}


//-----------------------------------------------------------

void Setup()  
{ 

	//glEnable( GL_CULL_FACE );
	glEnable( GL_BLEND );
	glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glShadeModel( GL_SMOOTH );

	glEnable(GL_DEPTH_TEST);
	glDepthFunc( GL_LEQUAL );      
	glClearDepth(1.0); 		      


	//Set up light source
	GLfloat ambientLight[] = { 0.2, 0.2, 0.2, 1.0 };
	GLfloat diffuseLight[] = { 0.8, 0.8, 0.8, 1.0 };
	GLfloat lightPos[] = { -20.0, 20.0, 150.0, 1.0 };

	glLightfv( GL_LIGHT0, GL_AMBIENT, ambientLight );
	glLightfv( GL_LIGHT0, GL_DIFFUSE, diffuseLight );
	glLightfv( GL_LIGHT0, GL_POSITION,lightPos );


	// polygon rendering mode and material properties
	glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);

	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE );

	glEnable( GL_LIGHTING );
	glEnable( GL_LIGHT0);



	// Black background
	glClearColor(0.0f,0.0f,0.0f,1.0f);
}

void Keyboard(unsigned char key,int x,int y)
{

	switch(key)
	{
	case 'o' : rotx-=2.0f;
		break;
	case 'p' : rotx+=2.0f;
		break;
	case 'k' : roty-=2.0f;
		break;
	case 'l' : roty+=2.0f;
		break;
	case 'n' : rotz-=2.0f;
		break;
	case 'm' : rotz+=2.0f;
		break;
	case 'q' : tranx-=2.0f;
		break;
	case 'w' : tranx+=2.0f;
		break;
	case 'a' : trany-=2.0f;
		break;
	case 's' : trany+=2.0f;
		break;
	case 'z' : tranz-=2.0f;
		break;
	case 'x' : tranz+=2.0f;
		break;
	default : 
		break;

	}

	glutPostRedisplay();
	//
}



