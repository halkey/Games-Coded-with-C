#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main ()
{
int a,b,i=0,j=0;
char **map;
char x,y,z;
int c,d,mapx,mapy,counter=0;;
double dx,dy,k,l;
int point,score=0;

scanf("%d %d",&a,&b);

map=(char **) malloc(sizeof(char *)*b);  //yyy

for(i=0;i<b;i++)
map[i]=(char *) malloc(sizeof(char)*a);  //xxx

for(i=0;i<b;i++)
{
for(j=0;j<a;j++)
map[i][j]=' ' ;                          //space

}


for(i=0;i<b;i++)
{
map[i][0]='|';

	if(i==0)
	for(j=1;j<a-1;j++)                 //map
	{
	map[i][j]='~';
	}

map[i][a-1]='|';
}


i=1;
j=1;
while(scanf("%c",&x) != 'e')
{

	while(i<b)
	{
	j=1;
		while(j<a-1)
		{
		if(x != '\n')
		map[i][j]=x;
		else
		j--;
		scanf("%c",&x);
		if(x=='e')
		break;
		j++;
		}
	if(x=='e')
	break;
	i++;
	}
if(x=='e')
break;
}
scanf("%c %c",&y,&z);

scanf("%lf %lf",&k,&l);       //shooter location
map[(int)l][(int)k]='_';
mapx=k;
mapy=l;

for(i=0;i<b;i++)
{
for(j=0;j<a;j++)
printf("%c",map[i][j]);                    //printf
printf("\n");
}
printf("\n");

while(scanf(" %c",&y) != EOF)
{
if(y=='q')
{
printf("Game is over. Your score is %d!",score);
return 0;
}
scanf("%lf %lf",&dx,&dy);
dx=dx/10000;
dy=dy/10000;
k=mapx;
l=mapy; 
counter=0;

		while(map[(int)l/1][(int)k/1] == ' ' || map[(int)l/1][(int)k/1] == '_' || map[(int)l/1][(int)k/1] == '|')
		{	
		
			if((map[(int)l/1][(int)k/1] == '|')){
			l-=dy;
			
			dx=-dx;
			}
		k+=dx;
		l+=dy;
		
		}

k-=dx;
l-=dy;

map[(int)l/1][(int)k/1]=y;




if(map[(int)l+1][(int)k]==y)
counter++;


if(map[(int)l][(int)k+1]==y)
counter++;


if(map[(int)l-1][(int)k]==y)
counter++;


if(map[(int)l][(int)k-1]==y)
counter++;


if(map[(int)l-1][(int)k-1]==y)
counter++;


if(map[(int)l+1][(int)k+1]==y)
counter++;


if(map[(int)l+1][(int)k-1]==y)
counter++;


if(map[(int)l-1][(int)k+1]==y)
counter++;


if(map[(int)l][(int)k]==y)
counter++;
			
if(counter>=3)
{
if(map[(int)l+1][(int)k]==y)
map[(int)l+1][(int)k]=' ';

if(map[(int)l][(int)k+1]==y)
map[(int)l][(int)k+1]=' ';

if(map[(int)l-1][(int)k]==y)
map[(int)l-1][(int)k]=' ';

if(map[(int)l][(int)k-1]==y)
map[(int)l][(int)k-1]=' ';

if(map[(int)l-1][(int)k-1]==y)
map[(int)l-1][(int)k-1]=' ';

if(map[(int)l+1][(int)k+1]==y)
map[(int)l+1][(int)k+1]=' ';

if(map[(int)l+1][(int)k-1]==y)
map[(int)l+1][(int)k-1]=' ';

if(map[(int)l-1][(int)k+1]==y)
map[(int)l-1][(int)k+1]=' ';

if(map[(int)l][(int)k]==y)
map[(int)l][(int)k]=' ';

}

if(counter==3)
{
point=30;
score+=point;
printf("You got %d points. Score: %d\n",point,score);
}

if(counter==4)
{
point=40;
score+=point;
printf("You got %d points. Score: %d\n",point,score);
}

if(counter > 4)
{
point=100;
score+=point;
printf("You got %d points. Score: %d\n",point,score);
}


for(i=0;i<b;i++)
{
for(j=0;j<a;j++)
printf("%c",map[i][j]);                    //printf
printf("\n");
}
printf("\n");






}//while
printf("Game is over. Your score is %d!",score);


}//int main

