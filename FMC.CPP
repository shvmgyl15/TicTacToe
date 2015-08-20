#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
union REGS i,o;
int mousecall();
int hidemouse();
void mousepos(int &cl,int &x,int &y);
void setmouse(int &,int &);
void restrict(int x1,int x2,int y1,int y2);

int mousecall()
{
i.x.ax=1;
int86(51,&i,&o);
return 1;
}


int hidemouse()
{
i.x.ax=2;
int86(51,&i,&o);
return 1;
}


void mousepos( int &button, int &x, int &y)
{
i.x.ax=3;
int86(51,&i,&o);
button=o.x.bx;
x=o.x.cx;
y=o.x.dx;
}


void setmouse(int &x, int &y)
{
i.x.ax=4;
i.x.cx=x;
i.x.dx=y;
int86(51,&i,&o);
}



void restrict(int x1,int x2,int y1, int y2)
{
i.x.ax=7;
i.x.cx=x1;
i.x.dx=x2;
int86(51,&i,&o);
i.x.ax=8;
i.x.cx=y1;
i.x.dx=y2;
int86(51,&i,&o);
}

