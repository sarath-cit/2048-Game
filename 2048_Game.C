#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<dos.h>
#include<snap.h>
#include<conio.h>
int checkwin(int *a[]);
int checkout(int *a[]);
void upward(int *a[],int *d[]);
void downward(int *a[],int *d[]);
void rightward(int *a[],int *d[]);
void leftward(int *a[],int *d[]);
void display(int *a[],int score);
void ran(int *a[]);
void save(int *c[],int *a[]);
int getScore(int *c[],int score,int *d[]);
int checkadd(int *a[],int *c[]);
int getRandNum()
{
	int numList[]={2,4};
	return numList[rand()%2];
}
int checkout(int *a[])
{
	int i,j,count=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(a[i][j]>0)
			count=count+1;
		}
	}
	if(count==16)
	{
	if((a[0][0]==a[0][1]) || (a[0][0]==a[1][0]))
	{return 1;}
	if((a[0][3]==a[0][2]) || (a[0][3]==a[1][3]))
	{return 1;}
	if((a[3][0]==a[3][1]) || (a[3][0]==a[2][0]))
	{return 1;}
	if((a[3][3]==a[3][2]) || (a[3][3]==a[2][3]))
	{return 1;}
	if((a[0][1]==a[0][0]) || (a[0][1]==a[0][2]) || (a[0][1]==a[1][1]))
	{return 1;}
	if((a[0][2]==a[0][1]) || (a[0][2]==a[0][3]) || (a[0][2]==a[1][2]))
	{return 1;}
	if((a[1][0]==a[0][0]) || (a[1][0]==a[1][1]) || (a[1][0]==a[2][0]))
	{return 1;}
	if((a[2][0]==a[1][0]) || (a[2][0]==a[2][1]) || (a[2][0]==a[3][0]))
	{return 1;}
	if((a[1][3]==a[0][3]) || (a[1][3]==a[1][2]) || (a[1][3]==a[2][3]))
	{return 1;}
	if((a[2][3]==a[1][3]) || (a[2][3]==a[2][2]) || (a[2][3]==a[3][3]))
	{return 1;}
	if((a[3][1]==a[3][0]) || (a[3][1]==a[2][1]) || (a[3][1]==a[3][2]))
	{return 1;}
	if((a[3][2]==a[3][1]) || (a[3][2]==a[2][2]) || (a[3][2]==a[3][3]))
	{return 1;}
	if((a[1][1]==a[1][0]) || (a[1][1]==a[0][1]) || (a[1][1]==a[1][2]) || (a[1][1]==a[2][1]))
	{return 1;}
	if((a[1][2]==a[1][1]) || (a[1][2]==a[0][2]) || (a[1][2]==a[2][2]) || (a[1][2]==a[1][3]))
	{return 1;}
	if((a[2][1]==a[2][0]) || (a[2][1]==a[3][1]) || (a[2][1]==a[1][1]) || (a[2][1]==a[2][2]))
	{return 1;}
	if((a[2][2]==a[2][1]) || (a[2][2]==a[1][2]) || (a[2][2]==a[2][3]) || (a[2][2]==a[3][2]))
	{return 1;}
	return 0;
    }
    return 1;
}
int checkwin(int *a[])
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(a[i][j]==2048){return 1;}
		}
	}
	return 0;
}
void display(int *a[],int score)
{
	int gdriver=DETECT,gmode;
int i,j,s,high_score=0;
FILE *fp;
initgraph(&gdriver,&gmode,"c:\\tc\\bgi");
printf("\n\n\n\n\n\n\n\n");
printf("\n\n\n\t\t");
setbkcolor(BLUE);
if(a[0][0]>512)
printf("    ");
else
{
if(a[0][0]>64)
printf("     ");
else
{
if(a[0][0]>8)
printf("      ");
else
printf("       ");
}
}
    if(a[0][0]>0)
    printf("%d",a[0][0]);
    else
    printf(" ");
    if(a[0][1]>512)
    printf("      ");
    else
    {
    if(a[0][1]>64)
    printf("       ");
    else
    {
    if(a[0][1]>8)
    printf("        ");
    else
    printf("         ");
    }
    }
    if(a[0][1]>0)
    printf("%d",a[0][1]);
    else
    printf(" ");
    if(a[0][2]>512)
    printf("     ");
    else
    {
    if(a[0][2]>64)
    printf("      ");
    else
    {
    if(a[0][2]>8)
    printf("       ");
    else
    printf("        ");
    }
    }
    if(a[0][2]>0)
    printf("%d",a[0][2]);
    else
    printf(" ");
    if(a[0][3]>512)
    printf("     ");
    else
    {
    if(a[0][3]>64)
    printf("      ");
    else
    {
    if(a[0][3]>8)
    printf("       ");
    else
    printf("        ");
}
}
    if(a[0][3]>0)
    printf("%d",a[0][3]);
    else
    printf(" ");
    printf("\n\n\n\n\n\t\t");
    if(a[1][0]>512)
    printf("    ");
    else
    {
    if(a[1][0]>64)
    printf("     ");
    else
    {
    if(a[1][0]>8)
    printf("      ");
    else
    printf("       ");
}
}
    if(a[1][0]>0)
    printf("%d",a[1][0]);
    else
    printf(" ");
    if(a[1][1]>512)
    printf("      ");
    else
    {
    if(a[1][1]>64)
    printf("       ");
    else
    {
    if(a[1][1]>8)
    printf("        ");
    else
    printf("         ");
}
}
    if(a[1][1]>0)
    printf("%d",a[1][1]);
    else
    printf(" ");
    if(a[1][2]>512)
    printf("     ");
    else
    {
    if(a[1][2]>64)
    printf("      ");
    else
    {
    if(a[1][2]>8)
    printf("       ");
    else
    printf("        ");
}
}
    if(a[1][2]>0)
    printf("%d",a[1][2]);
    else
    printf(" ");
   if(a[1][3]>512)
    printf("     ");
    else
    {
    if(a[1][3]>64)
    printf("      ");
    else
    {
    if(a[1][3]>8)
    printf("       ");
    else
    printf("        ");
}
}
    if(a[1][3]>0)
    printf("%d",a[1][3]);
    else
    printf(" ");
    printf("\n\n\n\n\n\t\t");
    if(a[2][0]>512)
    printf("    ");
    else
    {
    if(a[2][0]>64)
    printf("     ");
    else
    {
    if(a[2][0]>8)
    printf("      ");
    else
    printf("       ");
}
}
    if(a[2][0]>0)
    printf("%d",a[2][0]);
    else
    printf(" ");
    if(a[2][1]>512)
    printf("      ");
    else
    {
    if(a[2][1]>64)
    printf("       ");
    else
    {
    if(a[2][1]>8)
    printf("        ");
    else
    printf("         ");
}
}
    if(a[2][1]>0)
    printf("%d",a[2][1]);
    else
    printf(" ");
   if(a[2][2]>512)
    printf("     ");
    else
    {
    if(a[2][2]>64)
    printf("      ");
    else
    {
    if(a[2][2]>8)
    printf("       ");
    else
    printf("        ");
}
}
    if(a[2][2]>0)
    printf("%d",a[2][2]);
    else
    printf(" ");
    if(a[2][3]>512)
    printf("     ");
    else
    {
    if(a[2][3]>64)
    printf("      ");
    else
    {
    if(a[2][3]>8)
    printf("       ");
    else
    printf("        ");
}
}
    if(a[2][3]>0)
    printf("%d",a[2][3]);
    else
    printf(" ");
    printf("\n\n\n\n\n\t\t");
    if(a[0][1]>512)
    printf("    ");
    else
    {
    if(a[0][1]>64)
    printf("     ");
    else
    {
    if(a[3][0]>8)
    printf("      ");
    else
    printf("       ");
}
}
    if(a[3][0]>0)
    printf("%d",a[3][0]);
    else
    printf(" ");
    if(a[3][1]>512)
    printf("      ");
    else
    {
    if(a[3][1]>64)
    printf("       ");
    else
    {
    if(a[3][1]>8)
    printf("        ");
    else
    printf("         ");
}
}
    if(a[3][1]>0)
    printf("%d",a[3][1]);
    else
    printf(" ");
    if(a[3][2]>512)
    printf("     ");
    else
    {
    if(a[3][2]>64)
    printf("      ");
    else
    {
    if(a[3][2]>8)
    printf("       ");
    else
    printf("        ");
}
}
    if(a[3][2]>0)
    printf("%d",a[3][2]);
    else
    printf(" ");
    if(a[3][3]>512)
    printf("     ");
    else
    {
    if(a[3][3]>64)
    printf("      ");
    else
    {
    if(a[3][3]>8)
    printf("       ");
    else
    printf("        ");
}
}
    if(a[3][3]>0)
    printf("%d",a[3][3]);
    else
    printf(" ");
fp=fopen("high_score.txt","r");
while(fscanf(fp,"%d",&high_score)!=EOF)
if(score>high_score)
{
fclose(fp);
fp=fopen("high_score.txt","w");
high_score = score;
fprintf(fp,"%d",high_score);
fclose(fp);
fp=fopen("high_score.txt","r");
}
if(score<=999)
printf("\n\n\n        Score: %d              PgDn Key => Exit         High Score: %d",score,high_score);
else
{
if(score>999 && score<10000)
printf("\n\n\n      Score: %d              PgDn Key => Exit         High Score: %d",score,high_score);
else
printf("\n\n\n     Score: %d              PgDn Key => Exit         High Score: %d",score,high_score);
}
fclose(fp);
setcolor(YELLOW);
line(150,150,150,445);
line(225,150,225,445);
line(300,150,300,445);
line(375,150,375,445);
line(450,150,450,445);
line(150,150,450,150);
line(150,225,450,225);
line(150,300,450,300);
line(150,375,450,375);
line(150,445,450,445);
for ( s = 200 ; s <= 1000 ; s = s + 20 )
   {
      sound(s);
      delay(3);
   }
   nosound();
}
void upward(int *a[],int *d[])
{
	int i,j,k,*b[4];
	for(i=0;i<4;i++)
	{
	b[i]=(int*)malloc(4*sizeof(int));
    }
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
		b[i][j]=a[i][j];
		}
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(a[j][i]==b[j][i])
			{
				for(k=j+1;k<4;k++)
			{
			if(a[j][i]==a[k][i])
			{
				a[k][i]=a[k][i]+a[j][i];
				a[j][i]=0;
			break;
			}
			if(a[k][i]!=0)
			{
				break;
			}
		    }
		}
	    }
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			d[i][j]=a[i][j];
		}
	}
	for(k=0;k<3;k++)
	{
	for(i=3;i>0;i--)
	{
		for(j=0;j<4;j++)
		{
			if(a[i-1][j]==0)
			{
				a[i-1][j]=a[i][j];
				a[i][j]=0;
			}
		}
	}
    }
}
void downward(int *a[],int *d[])
{
	int i,j,k,*b[4];
	for(i=0;i<4;i++)
	{
	b[i]=(int*)malloc(4*sizeof(int));
    }
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
		b[i][j]=a[i][j];
		}
	}
	for(i=0;i<4;i++)
	{
		for(j=3;j>=0;j--)
		{
			if(a[j][i]==b[j][i])
			{
				for(k=j-1;k>=0;k--)
			{
			if(a[j][i]==a[k][i])
			{
				a[k][i]=a[k][i]+a[j][i];
				a[j][i]=0;
			break;
			}
			if(a[k][i]!=0)
			{
				break;
			}
		    }
		}
	    }
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			d[i][j]=a[i][j];
		}
	}
	for(k=0;k<3;k++)
	{
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			if(a[i+1][j]==0)
			{
				a[i+1][j]=a[i][j];
				a[i][j]=0;
			}
		}
	}
    }
}
void rightward(int *a[],int *d[])
{
    int i,j,k,*b[4];
	for(i=0;i<4;i++)
	{
	b[i]=(int*)malloc(4*sizeof(int));
    }
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
		b[i][j]=a[i][j];
		}
	}
	for(i=3;i>=0;i--)
	{
		for(j=3;j>=0;j--)
		{
			if(a[i][j]==b[i][j])
			{
				for(k=j-1;k>=0;k--)
			{
			if(a[i][j]==a[i][k])
			{
				a[i][k]=a[i][k]+a[i][j];
				a[i][j]=0;
			break;
			}
			if(a[i][k]!=0)
			{
				break;
			}
		    }
		}
	    }
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			d[i][j]=a[i][j];
		}
	}
	for(k=0;k<3;k++)
	{
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			if(a[j][i+1]==0)
			{
				a[j][i+1]=a[j][i];
				a[j][i]=0;
			}
		}
	}
    }
}
void leftward(int *a[],int *d[])
{
	int i,j,k,*b[4];
	for(i=0;i<4;i++)
	{
	b[i]=(int*)malloc(4*sizeof(int));
    }
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
		b[i][j]=a[i][j];
		}
	}
	for(i=3;i>=0;i--)
	{
		for(j=0;j<3;j++)
		{
			if(a[i][j]==b[i][j])
			{
				for(k=j+1;k<4;k++)
			{
			if(a[i][j]==a[i][k])
			{
				a[i][k]=a[i][k]+a[i][j];
				a[i][j]=0;
			break;
			}
			if(a[i][k]!=0)
			{
				break;
			}
		    }
		}
	    }
	}
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			d[i][j]=a[i][j];
		}
	}
	for(k=0;k<3;k++)
	{
	for(i=3;i>0;i--)
	{
		for(j=3;j>=0;j--)
		{
			if(a[j][i-1]==0)
			{
				a[j][i-1]=a[j][i];
				a[j][i]=0;
			}
		}
	}
    }
}
void ran(int *a[])
{
	int i,j;
	i=rand()%4;
	j=rand()%4;
	while(a[i][j]>0)
	{
		i=rand()%4;
		j=rand()%4;
	}
	a[i][j]=getRandNum();
}
void save(int *c[],int *a[])
{
    int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
		c[i][j]=a[i][j];
		}
	}
}
int getScore(int *c[],int score,int *d[])
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
		if(c[i][j]!=d[i][j])
	{
	score+=d[i][j];
	    }
		}
	}
	return score;
}
int checkadd(int *a[],int *c[])
{
    int i,j,count=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
		if(c[i][j]==a[i][j])
	{
	count=count+1;
	    }
		}
	}
	if(count==16)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
	union REGS i, o;

int initmouse()
{
   i.x.ax = 0;
   int86(0X33,&i,&o);
   return ( o.x.ax );
}

void showmouseptr()
{
   i.x.ax = 1;
   int86(0X33,&i,&o);
}

void restrictmouseptr(int x1, int y1, int x2, int y2)
{
   i.x.ax = 7;
   i.x.cx = x1;
   i.x.dx = x2;
   int86(0X33,&i,&o);

   i.x.ax = 8;
   i.x.cx = y1;
   i.x.dx = y2;
   int86(0X33,&i,&o);
}
void getmousepos(int *button, int *x, int *y)
{
   i.x.ax = 3;
   int86(0X33,&i,&o);

   *button = o.x.bx;
   *x = o.x.cx;
   *y = o.x.dx;

}
void main()
{
int *a[4],*c[4],*d[4],i,j,k,l,ch2,score=0,loop=1,win,out,check=0;
int status, gd = DETECT, gm,button,x,y,z,high_score;
    char e,m[50],array[50];
    int gdriver1 = DETECT,gmode1;
int x1,y1,i1;
FILE *fp;
w:	initgraph(&gdriver1,&gmode1,"C:\\TC\\BGI");

	for(i1=30;i1<100;i1++)
	{
		delay(50);
		setcolor(i1/10);
		sound(i1+170);
		arc(310,375,0,180,i1-10);
		arc(200,375,0,180,i1-10);
		arc(420,375,0,180,i1-10);
		arc(90,375,0,180,i1-10);
		arc(530,375,0,180,i1-10);
	}
	capture("C:\\TC\\Capture\\Capture1.jpg");
    nosound();
    settextstyle(DEFAULT_FONT,HORIZ_DIR,7);
   setcolor(GREEN);
   outtextxy(200,50,"2048");
   delay(100);
   settextstyle(DEFAULT_FONT,0,2);

   status = initmouse();

   if ( status == 0 )
      outtext("Mouse support not available.\n");
   else
   {
      showmouseptr();
     circle(310,200,65);
     line(300,180,300,220);
     line(300,180,330,200);
     line(300,220,330,200);
     floodfill(310,200,GREEN);
     settextstyle(DEFAULT_FONT,0,1);
     outtextxy(20,200,"LEFT CLICK => PLAY");
     outtextxy(450,200,"RIGHT CLICK => HELP");
     restrictmouseptr(245,135,375,265);
	  getmousepos(&button,&x,&y);

      while(!kbhit())
      {
	 getmousepos(&button,&x,&y);

	 if( button == 1 )
	 {
	 button=-1;
       cleardevice();
       initgraph( &gd, &gm, "C:\\TC\\BGI");
       settextjustify( CENTER_TEXT, CENTER_TEXT );
	settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
       setcolor(RED);

   for (z=5;z >=0;z--)
   {
      settextstyle(GOTHIC_FONT,HORIZ_DIR,30);
      sprintf(m,"%d",z);
      outtextxy(getmaxx()/2, getmaxy()/2,m);
      delay(1000);
      cleardevice();
      if ( z == 0 )
      {
for(i=0;i<4;i++)
	a[i]=(int*)malloc(4*sizeof(int));
for(i=0;i<4;i++)
	c[i]=(int*)malloc(4*sizeof(int));
	for(i=0;i<4;i++)
	d[i]=(int*)malloc(4*sizeof(int));
srand(time(NULL));
for(i=0;i<4;i++)
{
	for(j=0;j<4;j++)
	{
		a[i][j]=0;
	}
}
for(i=0;i<4;i++)
{
	for(j=0;j<4;j++)
	{
		c[i][j]=0;
	}
}
for(i=0;i<4;i++)
{
	for(j=0;j<4;j++)
	{
		d[i][j]=0;
	}
}
i=rand()%4;
j=rand()%4;
k=rand()%4;
l=rand()%4;
while((i==k) && (j==l))
{
	k=rand()%4;
	l=rand()%4;
}
a[i][j]=getRandNum();
a[k][l]=getRandNum();
display(a,score);
while(loop)
{
getch();
ch2=0;
ch2=getch();
switch(ch2)
{
case 72:closegraph();//up was pressed
    save(c,a);
	upward(a,d);
	score=getScore(c,score,d);
	win=checkwin(a);
	if(win==1)
	{
		printf("\n-----------------------GAME WIN-------------------------");
		loop=0;break;
	}
	else
	{
	check=checkadd(a,c);
	if(check==0)
	{
	ran(a);
    }
	out=checkout(a);
	if(out==0)
	{
	     display(a,score);
		 printf("\n----------------------GAME OVER-------------------------");
	 printf("\n Your Score: %d",score);
	    break;
    }
	display(a,score);
    }
break;
case 80:closegraph();//down was pressed
    save(c,a);
	downward(a,d);
	score=getScore(c,score,d);
	win=checkwin(a);
	if(win==1)
	{
		printf("\n-----------------------GAME WIN-------------------------");
		loop=0;break;
	}
	else
	{
	check=checkadd(a,c);
	if(check==0)
	{
	ran(a);
    }
	out=checkout(a);
	if(out==0)
	{
		 display(a,score);
		 printf("\n----------------------GAME OVER-------------------------");
	printf("\n Your Score: %d",score);
		break;
	}
	closegraph();
	display(a,score);
    }
break;
case 77:closegraph();//Right was pressed
    save(c,a);
	rightward(a,d);
	score=getScore(c,score,d);
	win=checkwin(a);
	if(win==1)
	{
		printf("\n-----------------------GAME WIN-------------------------");
		loop=0;break;
	}
	else
	{
		check=checkadd(a,c);
	if(check==0)
	{
	ran(a);
    }
	out=checkout(a);
	if(out==0)
	{
		 display(a,score);
		 printf("\n----------------------GAME OVER-------------------------");
	     printf("\n Your Score: %d",score);
	     break;
	}
	closegraph();
	display(a,score);
    }
break;
case 75:closegraph();//Left was pressed
    save(c,a);
	leftward(a,d);
	score=getScore(c,score,d);
	win=checkwin(a);
	if(win==1)
	{
	    printf("\n-----------------------GAME WIN-------------------------");
		loop=0;break;
	}
	else
	{
		check=checkadd(a,c);
	if(check==0)
	{
	ran(a);
    }
	out=checkout(a);
	if(out==0)
	{
		 display(a,score);
		 printf("\n----------------------GAME OVER-------------------------");
	     printf("\n Your Score: %d",score);
		 break;
	}
	closegraph();
	display(a,score);
    }
break;
default:
closegraph();
initgraph(&gdriver1,&gmode1,"c:\\TC\\BGI");
fp=fopen("high_score.txt","r");
while(fscanf(fp,"%d",&high_score)!=EOF)
printf("\n\n\n\t\t  %d\t\t\t\t\t%d",score,high_score);
fclose(fp);
setcolor(RED);
settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
outtextxy(50,50,"SCORE:");
outtextxy(300,50,"HIGH SCORE:");
setcolor(BLUE);
settextstyle(GOTHIC_FONT,HORIZ_DIR,10);
outtextxy(50,100,"T");
delay(1000);
outtextxy(135,100,"H");
delay(1000);
outtextxy(220,100,"A");
delay(1000);
outtextxy(305,100,"N");
delay(1000);
outtextxy(390,100,"K");
delay(1000);
outtextxy(300,250,"Y");
delay(1000);
outtextxy(385,250,"O");
delay(1000);
outtextxy(470,250,"U");
delay(2000);
loop=0;break;
	 }
}
	 break;
   }
    }
}
	 else if( button == 2 )
	 {

		 button=-1;
		 cleardevice();
		 printf(" \n\n\n\n2048 - How to play?\nThe objective of the game is to get the number 2048 using additions of the number two and its multiples.\nYou will have a grid of 16 tiles. Two numbers will be given: usually two number twos, maybe number four.\nMove up or down, left or right trying to join two equal numbers.\nWhen two equal numbers are in touch, they will add up.\nIf we are run out of equal numbers on our grid, or we can not put them in touch, the game will provide us another two, a four or even an eight so we can keep on playing. If there are no free tiles on our grid, the game ends.By adding numbers, we get higher numbers and we can approach to 2048, which is the goal of the game.\n\n\n\n");
		printf("\n\n\n\n\n\nEnter 'e' key to exit ");
		scanf("%c",&e);
if(e=='e')
 {
	 cleardevice();
	 goto w;
 }
 cleardevice();
 }
 }
 }
getch();
closegraph();
}

