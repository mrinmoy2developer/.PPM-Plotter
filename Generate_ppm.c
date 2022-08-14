#include <stdio.h> 
#include<stdlib.h>
#include <math.h>
#include "ppm.h"
#include "Graph.h"
#include "Geometry.h"
#define f(i,a,b) for(int i=a;i<b;i++)
#define new(t,n) (t*)malloc(sizeof(t)*n)
#define ld long double

int main() 
{ 
	int i, j, temp = 0; 
	int width = 4000, height = 4000; 
    Image img=create(width,height);
	Pixel white={255,255,255};
	background(&img,white);
	Fmt attr;
	attr.acolor=ink(255,0,0);
	attr.gcolor=ink(200,0,0);
	attr.thick=6;
	Graph gf;
	attr.scale=gf.scale=100;
	gf.orgx=width/2;
	gf.orgy=height/2;
	gf.color=ink(0,255,0);
	gf.paper=&img;
	gf.prec=0.01;
    gf.thick=9;
	axis(&img,attr);
	//point(&gf,100,100);
    // plot(&gf,x_sqr);
	gf.color=ink(0,0,255);
    plot(&gf,Sin);
    gf.color=ink(102,0,102);
	plot(&gf,gama);
	//show(img);
	save_as("graph.ppm",img); 
	
	//plot(&img,&x_sqr); 
	return 0;
} 
