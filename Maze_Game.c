#include <stdio.h>
int main()
{

// max board size 50x50 /   first number -----   second one  ||||



int x,y; //maze size
int i,j; //counters
int a,b; //scanf
char d,e; //start position
char f,p; //finish position
char c,t,r;
int bonus=0;
d=1;
e=1;
f=2;
p=2;
scanf("%d %d",&x,&y);

char wall[50] [50];

for(i=0;i<x;i++)
{
for(j=0;j<y;j++)   	//tüm arrayi boşluk yapma
wall[i] [j]=' ';
}

for(i=0;i<y;i++)
{
wall[0] [i]='*';		//alt üst duvar
wall[x-1] [i]='*';
}

for(i=0;i<x;i++)
{
wall[i] [0]='*';		//sağ sol duvar
wall[i] [y-1]='*';
}



//---------------------------------------------------------------------------------------------------------------------------



while((scanf("%c",&c)) != EOF)
{


switch(c)
{
case 'e':

scanf("%c %c",&t,&r);

for(i=0;i<x;i++)
{
for(j=0;j<y;j++)
printf("%c",wall[i] [j]);
printf("\n");
}
printf("\n");

break;

case 's':
scanf("%d %d",&a,&b);
wall[a] [b]='O';      //start position
d=a;
e=b;
break;

case 'f':
scanf("%d %d",&a,&b);
f=a;
p=b;
wall [a] [b]=' ';      //finish position
break;

case '$':
scanf("%d %d",&a,&b);
wall [a] [b]='$';
break;

case 'b':
scanf("%d %d",&a,&b);
wall  [a] [b]='*';
break;

case 'X':
scanf("%d %d",&a,&b);
wall  [a] [b]='X';
break;

case 'd':
if(wall [d+1] [e] == '*')
{
printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
		for(i=0;i<x;i++)
		{
		for(j=0;j<y;j++)
		printf("%c",wall[i] [j]);
		printf("\n");
		}
		printf("\n");
}
	else if(wall [d+1] [e] == '$')
	{
	printf("YOU GOT 1 $.\n");
	bonus++;
	wall [d] [e]=' ';              //down
	wall [d+1] [e]='O';
	d++;
	

		for(i=0;i<x;i++)
		{
		for(j=0;j<y;j++)
		printf("%c",wall[i] [j]);
		printf("\n");
		}
		printf("\n");
	}

			else if(wall [d+1] [e] == 'X')
			{
			printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
			
				for(i=0;i<x;i++)
				{
				for(j=0;j<y;j++)
				printf("%c",wall[i] [j]);
				printf("\n");
				}
				printf("\n");
			
			return 0;
			}

else
{
wall [d] [e]=' ';              //down
wall [d+1] [e]='O';
d++;

	if(!(d==f && e==p))
	{
		for(i=0;i<x;i++)
		{
		for(j=0;j<y;j++)
		printf("%c",wall[i] [j]);
		printf("\n");
		}
		printf("\n");
	}
}
break;

case 'r':
if(wall [d] [e+1] == '*')
{
printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
		for(i=0;i<x;i++)
		{
		for(j=0;j<y;j++)
		printf("%c",wall[i] [j]);
		printf("\n");
		}
		printf("\n");
}
	else if(wall [d] [e+1] == '$')
	{
	printf("YOU GOT 1 $.\n");
	bonus++;
	wall [d] [e]=' ';
	wall [d] [e+1]='O';             //right
	e++;
	

		for(i=0;i<x;i++)
		{
		for(j=0;j<y;j++)
		printf("%c",wall[i] [j]);
		printf("\n");
		}
		printf("\n");

	}

			else if(wall [d] [e+1] == 'X')
			{
			printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
			
				for(i=0;i<x;i++)
				{
				for(j=0;j<y;j++)
				printf("%c",wall[i] [j]);
				printf("\n");
				}
				printf("\n");
			return 0;
			}

else
{
wall [d] [e]=' ';
wall [d] [e+1]='O';             //right
e++;

	if(!(d==f && e==p))
	{
		for(i=0;i<x;i++)
		{
		for(j=0;j<y;j++)
		printf("%c",wall[i] [j]);
		printf("\n");
		}
		printf("\n");
	}
}
break;

case 'l':
if(wall [d] [e-1] == '*')
{
printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
		for(i=0;i<x;i++)
		{
		for(j=0;j<y;j++)
		printf("%c",wall[i] [j]);
		printf("\n");
		}
		printf("\n");
}
	else if(wall [d] [e-1] == '$')
	{
	printf("YOU GOT 1 $.\n");
	bonus++;
	wall [d] [e]=' ';
	wall [d] [e-1]='O';		//left
	e--;
	

		for(i=0;i<x;i++)
		{
		for(j=0;j<y;j++)
		printf("%c",wall[i] [j]);
		printf("\n");
		}
		printf("\n");
	}

			else if(wall [d] [e-1] == 'X')
			{
			printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
			
				for(i=0;i<x;i++)
				{
				for(j=0;j<y;j++)
				printf("%c",wall[i] [j]);
				printf("\n");
				}
				printf("\n");
			return 0;
			}
		
else
{
wall [d] [e]=' ';
wall [d] [e-1]='O';		//left
e--;

	if(!(d==f && e==p))
	{
		for(i=0;i<x;i++)
		{
		for(j=0;j<y;j++)
		printf("%c",wall[i] [j]);
		printf("\n");
		}
		printf("\n");
	}
}
break;

case 'u':
if(wall [d-1] [e] == '*')
{
printf("INVALID MOVE. TRY ANOTHER DIRECTION!\n");
		for(i=0;i<x;i++)
		{
		for(j=0;j<y;j++)
		printf("%c",wall[i] [j]);
		printf("\n");
		}
		printf("\n");
}
	else if(wall [d-1] [e] == '$')
	{
	printf("YOU GOT 1 $.\n");
	bonus++;
	wall [d] [e]=' ';
	wall [d-1] [e]='O';		//up
	d--;
	

		for(i=0;i<x;i++)
		{
		for(j=0;j<y;j++)
		printf("%c",wall[i] [j]);
		printf("\n");
		}
		printf("\n");
	}

			else if(wall [d-1] [e] == 'X')
			{
			printf("YOU MET WITH THE ENEMY AND LOST THE GAME :(\nGAME IS OVER!\n");
			
				for(i=0;i<x;i++)
				{
				for(j=0;j<y;j++)
				printf("%c",wall[i] [j]);
				printf("\n");
				}
				printf("\n");
			return 0;
			}
else
{
wall [d] [e]=' ';
wall [d-1] [e]='O';		//up
d--;

	if(!(d==f && e==p))
	{
		for(i=0;i<x;i++)
		{
		for(j=0;j<y;j++)
		printf("%c",wall[i] [j]);
		printf("\n");
		}
		printf("\n");
	}
}
break;

case 'q':
printf("YOU COULD NOT REACH THE FINAL POSITION :(\nGAME IS OVER!\n");
	for(i=0;i<x;i++)
	{
	for(j=0;j<y;j++)
	printf("%c",wall[i] [j]);
	printf("\n");
	}
	printf("\n");
return 0;
break;

}//switch

	if(d==f && e==p)
	{
		printf("CONGRATS! YOU GOT %d BONUS:)\n",bonus);
			for(i=0;i<x;i++)
			{
			for(j=0;j<y;j++)
			printf("%c",wall[i] [j]);
			printf("\n");
			}
			printf("\n");
	return 0;
	}
}//while


if(!(d==f && e==p))
{
printf("YOU COULD NOT REACH THE FINAL POSITION :(\nGAME IS OVER!\n");
	for(i=0;i<x;i++)
	{
	for(j=0;j<y;j++)
	printf("%c",wall[i] [j]);
	printf("\n");
	}
	
}



return 0;



}
