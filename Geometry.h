#ifndef GEOMETRY_H
#define MY_HEADER_FILE_H
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include "ppm.h"
#include "Graph.h"
#define f(i,a,b) for(int i=a;i<b;i++)
#define new(t,n) (t*)malloc(sizeof(t)*n)
#define ld long double
typedef struct shape{
    Pixel bdr,fill;
    ld thick;
    Image*canvas;
}Shape; 

ld dist(ld x1,ld y1,ld x2,ld y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int check(Shape sp,int i,int j){
    int w=sp.canvas->width,h=sp.canvas->height;
    if(i>=0&&j>=0&&j<w&&i<h)return 1;
    return 0;

}
void circle(Shape*sp,int x,int y,int r){
    int w=sp->thick;
    f(i,y-r,y+r)
        f(j,x-r,x+r)
            if(check(*sp,i,j)){
                ld d=dist(i,j,y,x);
                if(d<=r&&d>r-w)sp->canvas->map[i][j]=sp->bdr;
                else sp->canvas->map[i][j]=sp->fill;
            }
    
}
void rect(Shape*sp,int x,int y,int l,int b){
    int w=sp->thick;
    f(i,0,b)
        f(j,0,l)
            if(check(*sp,i,j)){
                if(j<w||j>=l-w||i<w||i>=b-w)sp->canvas->map[y+i][x+j]=sp->bdr;
                else sp->canvas->map[i][j]=sp->fill;
            }
}
void line(Shape *sp,int x1,int y1,int x2,int y2){
    int w=sp->thick;
    
    f(i,y1,y2)
        f(j,x1,x2)
        circle(sp,i,j,w);
}
void poly(Shape*sp,int*xi,int*yi,int xn,int yn){
    // int w=sp->thick;
    // f(i,0,b)
    //     f(j,0,l)
    //         if(check(sp,i,j)){
    //             if(j<w||j>=l-w||i<w||i>=b-w)sp->canvas->map[y+i][x+j]=sp->bdr;
    //             else sp->canvas->map[i][j]=sp->fill;
    //         }
}
#endif