//ADMIN FACILITY
#include<fstream.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<process.h>
#include<dos.h>

void MM();
void Bar(int);
int User_Menu();
int Menu_Options();
int CT();

int tc;

ifstream fi("config.dat",ios::in|ios::binary);

class Admin
{
 int bkcolor,t,ht1,ht2;
     //t=textcolor,ht1=menu name highlight,ht2=items highlight
 protected:
 int Add();
 public:
 char Q1[10][20]; int n;
 Admin();
 void Colors();
 void Menu(char s[10][20],int l);
 int Choice(char string[10][20],int max);
 void Menu_Options();
 void Admin_Menu();
 void BKcolor()
 {
  setfillstyle(SOLID_FILL,bkcolor);
  bar(0,0,640,480);
 }
}A;

Admin::Admin()
{
 t=0;
 n=5;
 ht1=14;
 ht2=15;
 bkcolor=1;
 strcpy(Q1[0],"USER MENU");
 strcpy(Q1[1],"1.");
 strcpy(Q1[2],"2.");
 strcpy(Q1[3],"3.");
 strcpy(Q1[4],"4.");
 strcpy(Q1[5],"5.");
}

int Main_Menu()
{
 A.BKcolor();
 char s[5][20]={"MAIN MENU","ADMINISTRATOR","USER","EXIT"};
 A.Menu(s,4);
 switch(A.Choice(s,3))
 {
  case 1 :A.Admin_Menu();
	  break;
  case 2 :User_Menu();
	  break;
  case 3 :break;
  case 27:break;
 }
 return 1;
}



void MM()   //main
{/*
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"\\tc\\bgi");   */

 //dont touch below
 /*
 setfillstyle(SOLID_FILL,15);
 bar(0,0,640,480);
 setcolor(1);
 int x=5,y=5,z=635,w=475;
 for(int i=0;i<3;i++,x+=5,y+=5,z-=5,w-=5)
 {
  rectangle(x,y,z,w);
  delay(1000);
 }
 settextstyle(1,0,4);
 settextjustify(1,1);
 outtextxy(320,240,"!! WELCOME !!");
 delay(800);

 setfillstyle(SOLID_FILL,1);
 bar(0,0,640,480);
 setcolor(15);
 settextstyle(0,0,0);
 char l[7][2]={"L","O","A","D","I","N","G"};
 x=250;
 for(i=0;i<7;i++,x+=20)
 {
  delay(200);
  outtextxy(x,150,l[i]);
  delay(200);
 }
 */
 //dont touch above

 fi.read((char *)&A,sizeof(A));

 Main_Menu();
 int i;
 do
 {
  i=User_Menu();
 }while(i);
 //getch();
 ofstream f("config.dat",ios::out|ios::binary);
 f.write((char *)&A,sizeof(A));
 closegraph();
}


int Admin::Choice(char string[10][20],int max)
{
 int k=1,up=72,down=80,x=320,y=100;
 char ch;
 do
 {
  ch=getch();
  tc=textwidth(string[k])/2;
  if(ch==up && k>=1)
  {
   setfillstyle(SOLID_FILL,bkcolor);
   Bar(k);
   outtextxy(x,y+=k*20,string[k]);
   if(k>1)
    k--;
   else
   if(k==1)
    k=max;
   y=100;
  }
  else if(ch==down && k<=max)
       {
	setfillstyle(SOLID_FILL,bkcolor);
	Bar(k);
	outtextxy(x,y+=k*20,string[k]);
	if(k<max)
	 k++;
	else
	if(k==max)
	 k=1;
	y=100;
       }
       else if(ch==27)
	     return 27;

 tc=textwidth(string[k])/2;
 setfillstyle(SOLID_FILL,ht2);
 Bar(k);
 outtextxy(x,y+=k*20,string[k]);
 y=100;
 }while(ch!=13);
 return k;
}

void Bar(int k)
{
 int x=320,y=100;
 switch(k)
 {
  case 1 :bar(x-tc-5,y+11,x+tc+5,y+29);
	  break;
  case 2 :bar(x-tc-5,y+31,x+tc+5,y+49);
	  break;
  case 3 :bar(x-tc-5,y+51,x+tc+5,y+69);
	  break;
  case 4 :bar(x-tc-5,y+71,x+tc+5,y+89);
	  break;
  case 5 :bar(x-tc-5,y+91,x+tc+5,y+109);
	  break;
  case 6 :bar(x-tc-5,y+111,x+tc+5,y+129);
	  break;
  case 7 :bar(x-tc-5,y+131,x+tc+5,y+149);
	  break;
  case 8 :bar(x-tc-5,y+151,x+tc+5,y+169);
	  break;
  case 9 :bar(x-tc-5,y+171,x+tc+5,y+189);
	  break;
  case 10:bar(x-tc-5,y+91,x+tc+5,y+209);
	  break;
 }
}

void Admin::Menu(char s[10][20],int l)
{
 int x=320,y=100;
 settextstyle(0,0,2);
 settextjustify(1,1);
 while(fi.read((char *)&A,sizeof(A)));
 tc=textwidth(s[0])/2;
 setfillstyle(SOLID_FILL,ht1);
 bar(x-tc-5,y-10,x+tc+5,y+9);
 tc=textwidth(s[1])/2;
 setfillstyle(SOLID_FILL,ht2);
 bar(x-tc-5,y+11,x+tc+5,y+29);
 setcolor(0);
 for(int i=0;i<l;y+=20,i++)
  outtextxy(x,y,s[i]);
}


int Admin::Add()
{
 BKcolor();
 int x=160,y=240;
 settextstyle(0,0,2);
 char s[20]="ENTER NAME:";
 char ch,aa[20];
 tc=textwidth(s)/2;
 setfillstyle(SOLID_FILL,ht1);
 bar(0,y-10,640,y+9);
 outtextxy(x,y,s);
 x+=tc+16;
 int sf=15;
 for(int ii=0;;ii++,x+=sf)
 {
  char s[2];
  ch=getch();
  s[0]=ch;
  s[1]='\0';
  if(ch==13)
   break;
  else
  if(ch==27)
   return 0;
  else
   if(ch=='\b' && ii>=0)
   {
    setcolor(ht1);
    x-=sf;
    s[0]=aa[ii-1];
    outtextxy(x,y,s);
    ii--;
    aa[ii]='\0';
    ii--;
    setcolor(t);
    x-=sf;
   }
  else
   {
    aa[ii]=ch;
    outtextxy(x,y,s);
   }
 }

 aa[ii]='\0';
 strcpy(Q1[++n],aa);
 ofstream f("config.dat",ios::out|ios::binary);
 f.write((char *)&A,sizeof(A));
 return 1;
}

void Admin::Colors()
{
 BKcolor();
 char s[4][20]={"CHOOSE BKCOLOR","CHOOSE TEXTCOLOR","MENU HILIGHT","OPTIONS HILIGHT"};
 int x=150,y=120;
 int a,b,c,d;
 for(int i=0;i<4;i++)
 {
  BKcolor();
  setcolor(t);
  outtextxy(x,y,s[i]);
  int x=CT();
  if(x==27)
   return;
  switch(i)
  {
   case 0 :a=x;
	   break;
   case 1 :b=x;
	   break;
   case 2 :c=x;
	   break;
   case 3 :d=x;
	   break;
  }
 }
 bkcolor=a,t=b,ht1=c,ht2=d;
}


void Admin::Admin_Menu()
{
 BKcolor();
 char s[5][20]={"ALTER MENU","1.MENU OPTIONS","2.COLORS","3.","4."};
 Menu(s,5);

 switch(Choice(s,4))
 {
  case 1 :Menu_Options();
	  break;
  case 2 :Colors();
	  Admin_Menu();
	  break;
  case 3 :
	  break;
  case 27:Main_Menu();
 }

 //fp.write((char *)&A,sizeof(A));
}

void Admin::Menu_Options()
{
 BKcolor();
 char s[5][20]={"ALTER USER MENU","1.ADD","2.DELETE","3.MOVE"};
 Menu(s,4);
 ofstream f("config.dat",ios::out|ios::binary);
 switch(Choice(s,3))
 {
  case 1 :Add();
	  Menu_Options();
	  break;
  case 2 :BKcolor();
	  Menu(Q1,n+1);
	  int x=Choice(Q1,n);
	  if(x==27)
	   Menu_Options();
	  else
	  {
	   for(int i=x;i<n+1;i++)
	   {
	    strcpy(Q1[i],Q1[i+1]);
	   }
	   n--;
	   f.write((char *)&A,sizeof(A));
	   Menu_Options();
	  }
	  break;
  case 3 :BKcolor();
	  Menu(Q1,n+1);
	  int z=Choice(Q1,n);
	  if(z==27)
	   Menu_Options();
	  else
	  {
	   int k=Choice(Q1,n);
	   if(k==27)
	    Menu_Options();
	   else
	   {
	    char t[20];
	    strcpy(t,Q1[z]);
	    strcpy(Q1[z],Q1[k]);
	    strcpy(Q1[k],t);
	    f.write((char *)&A,sizeof(A));
	    Menu_Options();
	   }
	  }
	  break;
  case 27:Admin_Menu();
 }
}


int User_Menu()
{
 fi.read((char *)&A,sizeof(A));
 A.BKcolor();
 A.Menu(A.Q1,A.n+1);

 switch(A.Choice(A.Q1,A.n))
 {
  case 1 :load();
	  single_player();
	  getch();
	  break;
  case 2 :load();
	  two_player();
	  getch();
	  break;
  case 3 :return 0;;
	  break;
  case 4 :
	  break;
  case 5 :
	  break;
  case 6 :
	  break;
  case 7 :
	  break;
  case 8 :
	  break;
  case 9 :
	  break;
  case 27:Main_Menu();
 }
 return 1;
}

int CT()
{
 setfillstyle(SOLID_FILL,15);
 bar(38,298,602,422);
 setcolor(0);
 rectangle(39,299,601,421);

 int ch=0,l=40,t=300,r=40+70,b=300+60;
 for(int j=0,k=8;j<8;j++,k++,l+=70,r+=70)
 {
  setfillstyle(SOLID_FILL,j);
  bar(l+1,t+1,r-1,b-1);
  setfillstyle(SOLID_FILL,k);
  bar(l+1,t+60+1,r-1,b+60-1);
  setcolor(0);
  if(j!=7)
   line(r,t,r,b+60);
  line(39,360,601,360);
 }

  l=40,t=300,r=40+70,b=300+60;

  int h,o=0;
  do
  {
   h=getch();
   switch(h)
   {
    case 72:if(ch<8)                   //up arrow
	     break;
	    ch-=8;
	    break;
    case 80:if(ch>7)                    //down arrow
	     break;
	    ch+=8;
	    break;
    case 77:if(ch==15)                  //right arrow
	     break;
	    ch++;
	    break;
    case 75:if(ch==0)                 //left arrow
	     break;
	    ch--;
    case 13:break;
    case 27:return 27;
   }
  setcolor(0);
  if(ch<8)
   rectangle(l+2+70*ch,t+2,r-2+70*ch,b-2);
  else
   {
    int m=ch-8;
    rectangle(l+2+70*m,t+60+2,r-2+70*m,b+60-2);
   }
  if(o!=ch)
  {
   setcolor(o);
   if(o<8)
    rectangle(l+2+70*o,t+2,r-2+70*o,b-2);
   else
    {
     int m=o-8;
     rectangle(l+2+70*m,t+60+2,r-2+70*m,b+60-2);
    }
   o=ch;
  }
  }while(h!=13);
 return ch;
}