#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h> 
#include<stdlib.h>
#include <math.h>
#include "ppm.h"
#define f(i,a,b) for(int i=a;i<b;i++)
#define new(t,n) (t*)malloc(sizeof(t)*n)
#define ld long double
#define pi 3.141592653589793
typedef struct pair{
	ld x,y;
}Pair;
typedef ld (*func)(ld);
typedef struct fmt{
	byte thick:4,grd:1,mkd:1,grid:1,fine:1,scale:8;
	Pixel acolor,gcolor;
}Fmt;
typedef struct graph{
    func y;
	Image*paper;
    ld orgx,orgy,thick,scale,prec;
    Pixel color;
}Graph;

ld x_sqr(ld x){
	return x*x;
}
ld Sin(ld x){
	return 4*sin(x);
}
ld Sin_i(ld x){
	return 10*sin(10/x);
}
ld Exp(ld x){
	return exp(x);
}
ld Floor(ld x){
	return floorl(x);
}
ld Log_Sin(ld x){
	return log(sin(x))/log(pi);
}
ld gama(ld x){
	return tgamma(x/5); 
}

void axis(Image*img,Fmt attr){
	int orgx=img->width/2,orgy=img->height/2,s=img->width/attr.scale,b=(img->width/60+attr.thick)/2;

	f(i,3,img->width-3){
		
		f(j,0,attr.thick)
		img->map[orgy+j][i]=attr.acolor;
	}
	f(i,3,img->height-3){
		f(j,0,attr.thick)
		img->map[i][orgx+j]=attr.acolor;
	}

	for(int j=orgx+s;j<img->width-attr.thick;j+=s){
		f(u,0,attr.thick)f(k,0,b)img->map[orgy-k+attr.thick][j+u-attr.thick/4]=img->map[orgy+k][j+u-attr.thick/4]=attr.acolor;
		f(i,0,img->height)f(k,0,attr.thick/3)img->map[i][j+k]=attr.gcolor;
	}
	for(int i=orgy+s;i<img->height-attr.thick;i+=s){
		f(u,0,attr.thick)f(k,0,b)img->map[i+u-attr.thick/4][orgx-k+attr.thick]=img->map[i+u-attr.thick/4][orgx+k]=attr.acolor;
		f(j,0,img->width)f(k,0,attr.thick/3)img->map[i+k][j]=attr.gcolor;
	}
	for(int j=orgx-s;j>attr.thick;j-=s){
		f(u,0,attr.thick)f(k,0,b)img->map[orgy-k+attr.thick][j-u+attr.thick/4]=img->map[orgy+k][j-u+attr.thick/4]=attr.acolor;
		f(i,0,img->height)f(k,0,attr.thick/3)img->map[i][j-k]=attr.gcolor;
	}
	for(int i=orgy-s;i>attr.thick;i-=s){
		f(u,0,attr.thick)f(k,0,b)img->map[i-u+attr.thick/4][orgx-k+attr.thick]=img->map[i-u+attr.thick/4][orgx+k]=attr.acolor;
		f(j,0,img->width)f(k,0,attr.thick/3)img->map[i-k][j]=attr.gcolor;
	}
}

void point(Graph*g,ld x,ld y){
    int x1=x+g->orgx,y1=g->orgy-y,r=g->thick;
	if(x1-r<0||y1-r<0||x1>=g->paper->width||y1>=g->paper->height)return;
	f(i,y1-r,y1+r)f(j,x1-r,x1+r){
		int tmp=(j-x1)*(j-x1)+(i-y1)*(i-y1)-r*r;
		if(tmp<0)g->paper->map[i][j]=g->color;
	}
}
void plot(Graph*g,func foo){
	int mx=-g->orgx,Mx=g->paper->width-g->orgx,my=-g->orgy,My=g->paper->height-g->orgy;
	for(ld x=mx;x<Mx;x+=g->prec){
		ld y=foo(x);
		point(g,x*g->scale,y*g->scale);
	}
}

#endif