//Tic Tac Toe
#include<fstream.h>          d
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>
#include<dos.h>
#include"fmc.cpp"
void load();
void single_player();
void two_player();
#include"mmt.h"

void Dx(int x=0,int y=0);
void Do(int x=0,int y=0);
void Er(int x=0,int y=0);
void Draw();
void init();
int W();
int Think(int mark);

int box=0,player=1,a[10],ch[3][3],h[10],turn=0;

/*void c1(int z,int x,int y,int w,int a=1)       //  rltb
{
 setcolor(a);
 rectangle(x,y,z,w);
}*/
/*
void corner_button(int x,int y)
{
 setcolor(WHITE);
 setfillstyle(SOLID_FILL,7);
 settextstyle(SMALL_FONT,0,6);
 rectangle(x-5,y-3,x+8,y+8);
 setcolor(8);
 rectangle(x-4,y-2,x+9,y+9);
 bar(x-4,y-2,x+8,y+8);
}
*/

void init()
{
 int k=20,i=0;
 for(i=0;i<10;i++)
  a[i]=0,h[i]=0;
 for(i=0;i<3;i++,k++)
  for(int j=0;j<3;j++,k++)
   ch[i][j]=k;
 box=0;
 turn=0;
 setcolor(15);
 setfillstyle(SOLID_FILL,15);
 bar(90,90,180,110);
}

void main()
{
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"\\tc\\bgi");

 //OPTIONS MENU
 //MAIN CODE
 MM();
 getch();
 closegraph();
}
 //coords of square :   320,200    440,200     440,280     320,280
void Dx(int x,int y)
{
 int xl=330,yl=200;
 setcolor(MAGENTA);
 //cross at centre
 hidemouse();
 line(xl+x,yl+y,xl+100+x,yl+80+y);
 line(xl+x,yl+80+y,xl+100+x,yl+y);
 mousecall();
}

void Do(int x,int y)
{
 int xl=260+120,yl=240;
 setcolor(9);
 hidemouse();
 circle(xl+x,yl+y,40);
 mousecall();
}

void Er(int x,int y)
{
 setfillstyle(SOLID_FILL,15);
 bar(329+x,193+y,431+x,287+y);
}

void Draw()
{
 int x=0,y=0,i,j;
 switch(box)
 {
  case 1 :x=-140,y=-110;
	  i=0,j=0;
	  break;
  case 2 :x=0,y=-110;
	  i=0,j=1;
	  break;
  case 3 :x=140,y=-110;
	  i=0,j=2;
	  break;
  case 4 :x=-140,y=0;
	  i=1,j=0;
	  break;
  case 5 :x=0,y=0;
	  i=1,j=1;
	  break;
  case 6 :x=140,y=0;
	  i=1,j=2;
	  break;
  case 7 :x=-140,y=110;
	  i=2,j=0;
	  break;
  case 8 :x=0,y=110;
	  i=2,j=1;
	  break;
  case 9 :x=140,y=110;
	  i=2,j=2;
	  break;
 }
 switch(player)
 {
  case 1:Do(x,y);
	 ch[i][j]=9;
	 break;
  case 2:Dx(x,y);
	 ch[i][j]=5;
	 break;
 }
}

int W()
{
 if(a[1])
 {
  if((ch[0][0]==ch[0][1] && ch[0][1]==ch[0][2]) || (ch[0][0]==ch[1][0] && ch[1][0]==ch[2][0]))
   return ch[0][0];
 }
 if(a[5])
 {
  if((ch[1][1]==ch[0][1] && ch[0][1]==ch[2][1]) || (ch[1][1]==ch[1][0] && ch[1][0]==ch[1][2]))
   return ch[1][1];
  if((ch[1][1]==ch[0][0] && ch[0][0]==ch[2][2]) || (ch[1][1]==ch[2][0] && ch[2][0]==ch[0][2]))
   return ch[1][1];
 }
 if(a[9])
 {
  if((ch[2][2]==ch[2][1] && ch[2][1]==ch[2][0]) || (ch[2][2]==ch[1][2] && ch[1][2]==ch[0][2]))
   return ch[2][2];
 }
 return 0;
}

void load()
{

 setfillstyle(SOLID_FILL,9);
 bar(0,0,640,480);

 setcolor(1);
 rectangle(0,640,0,480);
 rectangle(1,1,639,479);
 rectangle(2,2,638,478);

 setcolor(9);
 settextstyle(0,0,5);
 settextjustify(1,1);
 char s[20]="TIC TAC TOE";
 int x=320,y=240;
 int tc=textwidth(s)/2;
 setfillstyle(2,1);
 bar(x-tc-5,y-20,x+tc+5,y+14);
 outtextxy(x,y,s);
 setcolor(1);
 settextstyle(2,0,4);
 outtextxy(x,y-80,"presenting...");
 delay(100);
 outtextxy(x,y-60,"THE MOST AWAITED");
 delay(100);
 while(!kbhit())
 {
  setcolor(9);
  outtextxy(x,y+80,"Press any key to continue...");
  delay(300);
  setcolor(1);
  outtextxy(x,y+80,"Press any key to continue...");
  delay(300);
 }
 rectangle(x-tc-5-5,y-20-5,x+tc+5+5,y+14+5);

 getch();

 setfillstyle(SOLID_FILL,15);
 bar(2,2,638,478);
 setcolor(BROWN);
 setlinestyle(SOLID_LINE,1,3);
 int r=120;        //to move right-left  main area::canvas
 line(180+r,80,180+r,400);
 line(340+r,80,340+r,400);
 line(60+r,180,460+r,180);
 line(60+r,300,460+r,300);
		  //Imp shifts ::>>  Dx(-140,-110);
 //corner_button(636,1);
}

int Think(int mark)
{
 int i=0,j=0,k=0,x=0,y=0;
 for(k=1;k<10;k++)
 {
   if(a[k]==0)
   {
    switch(k)
    {
     case 1 :x=-140,y=-110;
	   i=0,j=0;
	   break;
     case 2 :x=0,y=-110;
	   i=0,j=1;
	   break;
     case 3 :x=140,y=-110;
	   i=0,j=2;
	   break;
     case 4 :x=-140,y=0;
	   i=1,j=0;
	   break;
     case 5 :x=0,y=0;
	   i=1,j=1;
	   break;
     case 6 :x=140,y=0;
	   i=1,j=2;
	   break;
     case 7 :x=-140,y=110;
	   i=2,j=0;
	   break;
     case 8 :x=0,y=110;
	   i=2,j=1;
	   break;
     case 9 :x=140,y=110;
	   i=2,j=2;
	   break;
    }
    int temp=ch[i][j];
    a[k]=1;
    ch[i][j]=mark;
    if(W())
     {
      delay(250);
      box=k;
      a[box]=1;
      h[turn]=box;
      ch[i][j]=5;
      turn++;
      Dx(x,y);
      return 1;
     }
    else
    {
     ch[i][j]=temp;
     a[k]=0;
    }
   }

 }
 return 0;
}

void two_player()
{
 init();
 int cl=0,x=0,y=0,check=2,j=0,k=0;
 restrict(0,640,0,480);
 mousecall();
 do
 {
  int m=431-140,n=193,o=287,p=640-70;
  cl=0;
  mousepos(cl,x,y);      //329+x,193+y,431+x,287+y
  if(x>180 && x<580 && y>80 && y<400 && cl==1)
  {
    if(x<m && x>n && y<n-16 && y>n-110)
     box=1;  //,type=1;
    if(x<m+140 && x>n+140 && y<n-16 && y>n-110)
     box=2; //,type=1;
    if(x<p && x>n+280 && y<n-16 && y>n-110)
     box=3;  //,type=1;
    if(x<m && x>n && y<o && y>n)
     box=4;  //,type=2;
    if(x<m+140 && x>n+140 && y<o && y>n)
     box=5; //,type=3;
    if(x<p && x>n+280 && y<o && y>n)
     box=6;  //,type=2;
    if(x<m && x>n && y>o+16 && y<o+110)
     box=7;  //,type=1;
    if(x<m+140 && x>n+140 && y>o+16 && y<o+110)
     box=8;  //,type=1;
    if(x<p && x>n+280 && y>o+16 && y<o+110)
     box=9;  //,type=1;
    cl=0;
    k=0;
    for(j=0;j<turn;j++)
    {
     if(box==h[j])
      {
       k=1;
       break;
      }
    }
    if(k==0)
    {
     a[box]=1;
     h[turn]=box;
     turn++;
      if(turn%2==0)               //player 2
      {
       player=2;
       Draw();
      }
      else
      {
       player=1;
       Draw();
      }
     if(turn>=5)
     {
      check=W();
      if(check)
       break;
     }
    }
  }
 }while(turn<9);

 switch(check)
 {
  case 9 :outtextxy(100,100,"Player 1 won");
	  break;
  case 5 :outtextxy(100,100,"Player 2 won");
	  break;
  default:outtextxy(100,100,"Its a draw !");
 }
}

void single_player()
{
 init();
 int cl=0,x=0,y=0,check=2,j=0,k=0;
 restrict(0,640,0,480);
 mousecall();
 do
 {
  int m=431-140,n=193,o=287,p=640-70;
  cl=0;
  mousepos(cl,x,y);      //329+x,193+y,431+x,287+y
  if(x>180 && x<580 && y>80 && y<400 && cl==1)
  {
    if(x<m && x>n && y<n-16 && y>n-110)
     box=1;  //,type=1;
    if(x<m+140 && x>n+140 && y<n-16 && y>n-110)
     box=2; //,type=1;
    if(x<p && x>n+280 && y<n-16 && y>n-110)
     box=3;  //,type=1;
    if(x<m && x>n && y<o && y>n)
     box=4;  //,type=2;
    if(x<m+140 && x>n+140 && y<o && y>n)
     box=5; //,type=3;
    if(x<p && x>n+280 && y<o && y>n)
     box=6;  //,type=2;
    if(x<m && x>n && y>o+16 && y<o+110)
     box=7;  //,type=1;
    if(x<m+140 && x>n+140 && y>o+16 && y<o+110)
     box=8;  //,type=1;
    if(x<p && x>n+280 && y>o+16 && y<o+110)
     box=9;  //,type=1;
    cl=0;
    k=0;
    for(j=0;j<turn;j++)
    {
     if(box==h[j])
      {
       k=1;
       break;
      }
    }
    if(k==0)
    {
     a[box]=1;
     h[turn]=box;
     turn++;
     player=1;
     Draw();
     //player 2
     delay(100);
     if(turn>=5)
     {
      check=W();
      if(check)
       break;
     }
     player=2;
     if(turn<9)
     {
      if(!Think(5))
       if(!Think(9) )
       {
	int b;
	do
	{
	  randomize();
	  b=1+random(9);
	  if(a[b]==0)
	  {
	   box=b;
	   a[box]=1;
	   h[turn]=box;
	   turn++;
	   Draw();
	   break;
	  }

	}while(1);
       }
     }
     if(turn>=5)
     {
      check=W();
      if(check)
       break;
     }
    }
  }
 }while(turn<9);

 switch(check)
 {
  case 9 :outtextxy(100,100,"Player 1 won");
	  break;
  case 5 :outtextxy(100,100,"Player 2 won");
	  break;
  default:outtextxy(100,100,"Its a draw !");
 }
}
