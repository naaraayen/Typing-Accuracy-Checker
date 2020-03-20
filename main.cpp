#include <iostream>
#include<stdio.h>
#include<conio.h>
#include<ctime> //To get and manipulate date and time information.

#include<graphics.h>
#include<windows.h>

using namespace std;

//GLOBAL VARIABLES ::
    int arr[12];
    int incr2=0;
    int x2=90,y2=325;
    int checkresult;



//USED TO CREATE HOME PAGE
void start_screen(int win1,int win2)
{
      int decree=0;
      int decree2=0;
      //ANIMATTION
   while(decree<=15)
   {
    setcolor(2);
    rectangle(15-decree,15-decree,getmaxx()-15+decree,getmaxy()-40+decree);
    decree++;
    delay(100);
    }
    while(decree2<=15)
    {
        setcolor(2);
	rectangle((getmaxx()/2)-300+decree2,(getmaxy()/2)-150-100+decree2,(getmaxx()/2)+300-decree2,(getmaxy()/2)-150+80+150-decree2);
	decree2++;
	delay(100);
    }

	setcolor(2);
	settextstyle(10,0,3);
    outtextxy((getmaxx()/2)-240,(getmaxy()/2)-150,"   START           [PRESS 1]");
	outtextxy((getmaxx()/2)-240,(getmaxy()/2)-150+20,"   -------------------------");
	outtextxy((getmaxx()/2)-240,(getmaxy()/2)-150+40,"   RULES           [PRESS 2]");
	outtextxy((getmaxx()/2)-240,(getmaxy()/2)-150+60,"   -------------------------");
	outtextxy((getmaxx()/2)-240,(getmaxy()/2)-150+80,"   ABOUT US        [PRESS 3]");
	while(1)
	{
    if(GetKeyState(49))//GetKeyState is used to know the state of key
	{
	    getch();
	    break;

	}

	if(GetKeyState(50))
	{
        win1=initwindow(getmaxx(),getmaxy(),"Rules");
		setcurrentwindow(win1);//Windows Shift

		settextstyle(0,0,15);
		setcolor(14);
		outtextxy(600,10,"RULES :");

		setcolor(3);
		outtextxy(200,100,"*Try to type the keywords displayed in circle");
		outtextxy(200,160,"*Indication of color in the circle :");
		outtextxy(200,330,"*Result will be shown after you filled all the circles");

        setcolor(8);
		outtextxy(550,700,"Press any key to play");

        setcolor(2);
		outtextxy(200,220,"   ->Green (You pressed the right key)");
        setcolor(4);
		outtextxy(200,280,"   ->Red (You pressed the wrong key)");

		if(getch())
        {

		break;

        }
	}
	else if(GetKeyState(51))

	{
        win2=initwindow(getmaxx(),getmaxy(),"About us");
		setcurrentwindow(win2);//windows shift
		settextstyle(0,0,15);
		setcolor(14);
		outtextxy(600,10,"ABOUT US :");
		setcolor(15);
		outtextxy(200,100,"A noob Programmer");
		outtextxy(200,160,"Email : naaraayen@gmail.com");
		outtextxy(200,220,"Helping Hands :");
		outtextxy(230,280,"~NABIN ~BIBHU ~RAM");
		for(int i=0;i<10;i++)
        {
        setcolor(8);
		outtextxy(550,700,"Press any key to play");
        }
		if(getch())
		break;


	}

	else
		{
			outtextxy(200,200,"");

		}
		jmp:
		    cout<<"";
	delay(100);
	}
}



//USED TO CREATE MULTIPLE CIRCLES IN A ROW
void row_circles()
{
	cleardevice();

    settextstyle(8,0,5);
    outtextxy(300,100,"Type without looking at keyboard :)");

    settextstyle(2,0,5);
    int incr=0;
    for(int i=0;i<12;i++)
    {
    int x=90,y=325;
    circle(x+incr,y,60);
    incr=incr+125;//Shifts circle
    }
}




//USED TO GENERATE RANDOM ALPABETS INSIDE CIRCLES
void random_alphabet(int max,int min)
{
	char p[0];
	int shift=0,a=74,b=300;
	//int shift=0,a=74,b=175;
	int difference=max-min;

	srand(time(0));//Predefined function to give time in seconds

	for(int j=0;j<12;j++)
	{
	Pick:
	int picker=rand()%difference+min;//Generates number from 65-122
	if(picker>90 && picker<97)//Skips 90-97
	goto Pick;


	p[0]=char(picker);//Explicitly converted to Char
	arr[j]=p[0];
	settextstyle(6,0,5);
	outtextxy(a+shift,b,p);

	shift=shift+125;//Shifts Alphabet
	}
}





//USED TO FILL IN THOSE CIRCLES
void fillcolor(int ckcolor)
{

	setfillstyle(1,ckcolor);
	for(int t=0;t<15;t++)
	floodfill(x2+incr2+t , y2+t, 15);
	incr2=incr2+125;

}





//USED TO GET INPUTS FROM THE KEYBOARD
int check()
{
	char chk;
	int i=0;
	while(1)
	{
	chk = getch();
	if(arr[i]==chk)
	{
	fillcolor(2);//Calling fillcolor function
	checkresult++;
	}
	else
	{
	fillcolor(4);//Calling fillcolor function
	}
	i++;

	//HOLD THE SCREEN BEFORE SHOWING RESULT
	if(i==12)
{
	cleardevice();
	while(1)
    {
    //BLINKING OF TEXT
	for(int blink=0;blink<=26;blink++)
    {

       while(blink<26)
       {
        if(blink%2==0)
        {
	settextstyle(0,0,5);
    setcolor(0);
   outtextxy(90,300,"Press any key to see your result :)");
        }

   else
   {
       settextstyle(0,0,5);
    setcolor(14);
   outtextxy(90,300,"Press any key to see your result :)");

    }
    blink++;
    delay(100);
       }
         if(blink==26)
           goto jump;
    }
    }
    jump:
    getch();


   return 0;
    }
}
}





//USED TO DISPLAY FINAL SCORE
//POPPING OF HAPPY & SAD EMOJI
void result()
{
	cleardevice();
	char acc[50];
	int percent;
	percent=((checkresult*100)/12);
	sprintf(acc,"%d",percent);
	setcolor(15);
	outtextxy(350,315,"Your accuracy is ");
	outtextxy(1130,315,"%");
	setbkcolor(15);
	setcolor(0);
	outtextxy(1000,315,acc);
	//HAPPY EMOJI :)
	if(percent>=50)
	{
	for(int z=0;z<10;z++)
	{
	setcolor(2);
	circle((getmaxx()/2)-50,(getmaxy()/2),1+z);
	circle((getmaxx()/2)+50,(getmaxy()/2),1+z);
	arc((getmaxx()/2),(getmaxy()/2),210,340,100+z);
	delay(95);

	}
	}
	else
    //SAD EMOJI :(
	{
		for(int z=0;z<10;z++)
	{
	setcolor(4);
	circle(getmaxx()/2-50,(getmaxy()/2),1+z);
	circle((getmaxx()/2)+50,(getmaxy()/2),1+z);
	arc((getmaxx()/2),(getmaxy()/2)+170,30,150,100-z);
	delay(95);

	}
}
}



//MAIN FUNCTION
main()
{

    int win,win1,win2;

    //Gets Screen Height and Width
	win=initwindow(GetSystemMetrics(SM_CXSCREEN),GetSystemMetrics(SM_CYSCREEN));

	//FUNCTIONS CALL
	setcurrentwindow(win);

    start_screen(win1,win2);

    setcolor(15);
    row_circles();

    random_alphabet(122,65);

    check();

    result();

    getch();
    return 0;
}
