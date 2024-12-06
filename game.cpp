#include <iostream>
#include <windows.h>
using namespace std;


char getCharAtxy(short int x, short int y);
void gotoxy(int x, int y);
void printEnemy1();
void printEnemy2();
void printEnemy3();
void eraseEnemy1();
void eraseEnemy2();
void eraseEnemy3();
void erasePlayer();
void movePlayerLeft();
void movePlayerRight();
void moveEnemy1();
void moveEnemy2();
void moveEnemy3();
void printMaze();
void printPlayer();
void movePlayer();
void movePlayerUp();
void movePlayerDown();
void score();
void shoot();
void printscore();

void drawbullet();
void erasebullet();
 
void printBullet(int x, int y);
void eraseBullet(int x, int y);
void makeBulletInactive(int index);
void generateBullet();
void playerShooting();
void Health();

int eX1 = 2, eY1 = 2;
int eX2 = 5, eY2 = 31;
int eX3 = 50, eY3 = 10;

int bulletX[100];
int bulletY[100];
bool isBulletActive[100];
int bulletCount=0;
int health=100;
int pX = 4, pY = 13;
int bX=pX+1,bY=pY-1;
int gamescore;


main()
{
	
	system("cls");
	printMaze();
	printEnemy1();
    printEnemy2();
    printEnemy3();
	printPlayer();
	
	while (true)
	{
		moveEnemy1();
        moveEnemy2();
        moveEnemy3();
		movePlayer();
		Health();
		printscore();
		playerShooting();
			
	} 
}

void gotoxy(int x, int y)
{
	COORD coordinates;
	coordinates.X = x;
	coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharAtxy(short int x, short int y)
{
	CHAR_INFO ci;
	COORD xy = {0, 0};
	SMALL_RECT rect = {x, y, x, y};
	COORD coordBufSize;
	coordBufSize.X = 1;
	coordBufSize.Y = 1;
	return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar: ' ';
}

void printMaze()
{
cout <<"######################################################################################################"<<endl;
cout <<"##                                                                                                  ##"<<endl;
cout <<"##                                                                                                  ##"<<endl;
cout <<"##                                                                                                  ##"<<endl;
cout <<"##                                                 $                                                ##"<<endl;
cout <<"##                                                                                                  ##"<<endl;
cout <<"##                                                                                                  ##"<<endl;
cout <<"##########################                                                                          ##"<<endl;
cout <<"##                                                                                                  ##"<<endl;
cout <<"##                                                                                                  ##"<<endl;
cout <<"##         $                                            ########################################### ##"<<endl;
cout <<"##                                                      #                                           ##"<<endl;
cout <<"##                                                      #                                           ##"<<endl;
cout <<"##                                                      #                                           ##"<<endl;
cout <<"##                        ##                            #                                           ##"<<endl;
cout <<"##                        ##                            #                                           ##"<<endl;
cout <<"##                        ##                            #                                           ##"<<endl;
cout <<"#######################################                 #                                           ##"<<endl;
cout <<"##                                                      #                                           ##"<<endl;
cout <<"##                                                      #                                           ##"<<endl;
cout <<"##       $                                                                                          ##"<<endl;
cout <<"##                                                                                                  ##"<<endl;
cout <<"##                                                                                                  ##"<<endl;
cout <<"##                                                                                                  ##"<<endl;
cout <<"## #####                                                                                            ##"<<endl;
cout <<"## #############################                                                                    ##"<<endl;
cout <<"##                                                                                                  ##"<<endl;
cout <<"##                     $                                                                            ##"<<endl;
cout <<"##                                                                           ###################### ##"<<endl;
cout <<"##                                                                           ##                     ##"<<endl;
cout <<"##                                                                                    $             ##"<<endl;
cout <<"##                                                                                                  ##"<<endl;
cout <<"##                                                                                                  ##"<<endl;
cout <<"##                                                                                                  ##"<<endl;
cout <<"##                                                                                                  ##"<<endl;
cout <<"##                                                                                                  ##"<<endl;
cout <<"######################################################################################################"<<endl;
}

void printBullet(int x, int y)
{
    gotoxy(x,y);
    cout<<".";
}
void eraseBullet(int x, int y)
{
    gotoxy(x,y);
    cout<<" ";
}
void makeBulletInactive(int index)
{
    isBulletActive[index]= false;
}
void generateBullet()
{
    bulletX[bulletCount]=pX+4;
    bulletY[bulletCount]=pY;
    isBulletActive[bulletCount]= true;
    gotoxy(pX+4,pY);
    cout<<".";
    bulletCount++;
}
void playerShooting()
{
    for(int x=0;x<bulletCount;x++)
    {
        if(isBulletActive[x] = true)
        {
            char next=getCharAtxy(bulletX[x]+1,bulletY[x]);
            if(next !=' ')
            {
                eraseBullet(bulletX[x],bulletY[x]);
                makeBulletInactive(x);
            }
            else
            {
                eraseBullet(bulletX[x],bulletY[x]);
                bulletX[x]=bulletX[x]+1;
                printBullet(bulletX[x],bulletY[x]);
            }
        }
    }    
}

void printEnemy1()
{
	gotoxy(eX1, eY1);
	cout << "000" << endl;
	gotoxy(eX1, eY1 + 1);
	cout << "(_)" << endl;
}

void Health()
{
    if(((getCharAtxy(pX,pY-1)!=' ') || (getCharAtxy(pX+1,pY-1)!=' ') || (getCharAtxy(pX+2,pY-1)!=' '))
	&&((getCharAtxy(pX,pY-1)!='$') && (getCharAtxy(pX+1,pY-1)!='$') && (getCharAtxy(pX+2,pY-1)!='$')))
    {
        health--;
    }
	if(((getCharAtxy(pX,pY+2)!=' ') || (getCharAtxy(pX+1,pY+2)!=' ') || (getCharAtxy(pX+2,pY+2)!=' '))
	&& ((getCharAtxy(pX,pY+2)!='$') && (getCharAtxy(pX+1,pY+2)!='$') && (getCharAtxy(pX+2,pY+2)!='$')))
    {
        health--;
    }
	if(((getCharAtxy(pX-1,pY)!=' ') || (getCharAtxy(pX-1,pY+1)!=' '))
	&&((getCharAtxy(pX-1,pY)!='$') && (getCharAtxy(pX-1,pY+1)!='$')))
    {
        health--;
    }
	if(((getCharAtxy(pX+3,pY)!=' ') || (getCharAtxy(pX+3,pY+1)!=' '))
	&&((getCharAtxy(pX+3,pY)!='$') && (getCharAtxy(pX+3,pY+1)!='$')))
    {
        health--;
    }
    gotoxy(0, 39);
    cout << "HEALTH:    ";
    gotoxy(0, 39);
    cout << "HEALTH:" << health;
}

void eraseEnemy1()
{
	gotoxy(eX1, eY1);
	cout << "   " << endl;
	gotoxy(eX1, eY1 + 1);
	cout << "   " << endl;
}
void moveEnemy1()
{
	eraseEnemy1();
	eX1 = eX1 + 1;
	if (eX1+4 == 100)
	{
		eX1 = 2;
	}
	printEnemy1();
	Sleep(50);
}
void printEnemy2()
{
	gotoxy(eX2, eY2);
	cout << "000" << endl;
	gotoxy(eX2, eY2 + 1);
	cout << "(_)" << endl;
}
void eraseEnemy2()
{
	gotoxy(eX2, eY2);
	cout << "   " << endl;
	gotoxy(eX2, eY2 + 1);
	cout << "   " << endl;
}
void moveEnemy2()
{
	eraseEnemy2();
	eX2 = eX2 + 1;
	if (eX2+4 == 100)
	{
		eX2 = 5;
	}
	printEnemy2();
	Sleep(50);
}
void printEnemy3()
{
	gotoxy(eX3, eY3);   
	cout << "000" << endl;
	gotoxy(eX3, eY3 + 1);
	cout << "(_)" << endl;
}
void eraseEnemy3()
{
	gotoxy(eX3, eY3);
	cout << "   " << endl;
	gotoxy(eX3, eY3 + 1);
	cout << "   " << endl;
}
void moveEnemy3()
{
	eraseEnemy3();
	eY3 = eY3 + 1;
	if (eY3+1 == 30)
	{
		eY3 = 10;
    }
	printEnemy3();
	Sleep(50);
}

void printPlayer()
{
    gotoxy(pX,pY);
	cout << "(-)" << endl;
    gotoxy(pX,pY+1);
	cout << "000" << endl;

}
void erasePlayer()
{
    gotoxy(pX,pY);
	cout << "   " << endl;
    gotoxy(pX,pY+1);
	cout << "   " << endl;
}
void movePlayer()
{
    if(GetAsyncKeyState(VK_RIGHT))
	{
		movePlayerRight();
	}
	else if(GetAsyncKeyState(VK_LEFT))
	{
		movePlayerLeft();
	}
	else if(GetAsyncKeyState(VK_UP))
	{
		movePlayerUp();
	}
	else if(GetAsyncKeyState(VK_DOWN))
	{
		movePlayerDown();
	}
	else if(GetAsyncKeyState(VK_SPACE))
	{
		generateBullet();
	}
}
void movePlayerRight()
{
	if((getCharAtxy(pX+3,pY)!='#') && getCharAtxy(pX+3,pY+1)!='#') 
	{
		score();
    erasePlayer();
    pX=pX+1;
    printPlayer();
	Sleep(10);
	}
    
}
void movePlayerLeft()
{
	if((getCharAtxy(pX-1,pY)!='#') && getCharAtxy(pX-1,pY+1)!='#') 
	{
		score();
	erasePlayer();
    pX=pX-1;
    printPlayer();
	Sleep(10);
	}

}
void movePlayerUp()
{
	
	if((getCharAtxy(pX,pY-1)!='#') && (getCharAtxy(pX+3,pY-1)!='#')) 
	{
		score();
		erasePlayer();
		pY--;
		printPlayer();
		Sleep(25);
	}
	
}
void movePlayerDown()
{
	if((getCharAtxy(pX,pY+2)!='#') && getCharAtxy(pX+3,pY+2)!='#') 
	{
		score();
		erasePlayer();
		pY++;
		printPlayer();
		Sleep(25);
	}
}


void score()
	{
		bX=pX+1;
		bY=pY-1;
	bool collected = false;

	if (getCharAtxy(pX, pY-1) == '$' || getCharAtxy(pX + 1, pY-1) == '$' || getCharAtxy(pX + 2, pY-1) == '$') 
	{
		collected = true;
	}
	else if ((getCharAtxy(pX, pY+2) == '$' || getCharAtxy(pX + 1, pY + 2) == '$' || getCharAtxy(pX + 2, pY + 2) == '$'))
	{
		collected = true;
	}
	else if (getCharAtxy(pX+3, pY) == '$' || getCharAtxy(pX + 3, pY + 1) == '$')
	 {
		collected = true;
	}
	else if (getCharAtxy(pX-1, pY) == '$' || getCharAtxy(pX - 1, pY +1) == '$')
	{
		collected = true;
	}

	if (collected)
	{
		gamescore += 500;
		collected=false; 
	}
	
}

void printscore()
{
	gotoxy(0, 38);
	cout << "Score:" << gamescore << endl;
}

void shoot()
{
		erasebullet();
		bY--;
		drawbullet();
		Sleep(100);
		erasebullet();
}
void drawbullet()
{
	gotoxy(bX,bY);
	cout<<'0';
}
void erasebullet()
{
	gotoxy(bX,bY);
	cout<<' ';
}
