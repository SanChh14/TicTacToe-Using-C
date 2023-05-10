#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include <windows.h>
#include <direct.h>
#include <io.h>

void space()
{
    printf("\t\t\t\t\t\t");
}

void color(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}

void Setcolor(int ForgC, int BackC)
{
 WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
               //Get the handle to the current output buffer...
 HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
                     //This is used to reset the carat/cursor to the top left.
 COORD coord = {0, 0};
                  //A return value... indicating how many chars were written
                    //   not used but we need to capture this since it will be
                      //   written anyway (passing NULL causes an access violation).
 DWORD count;

                               //This is a structure containing all of the console info
                      // it is used here to find the size of the console.
 CONSOLE_SCREEN_BUFFER_INFO csbi;
                 //Here we will set the current color
 SetConsoleTextAttribute(hStdOut, wColor);
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                          //This fills the buffer with a given character (in this case 32=space).
      FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

      FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
                          //This will set our cursor position for the next print statement.
      SetConsoleCursorPosition(hStdOut, coord);
 }
 return;
}


int main()
{
    int i,j,k=0,l=0,m=0,d,p=0,q=0,turn=1,r,t,check=0,circler[3]={0,0,0},circlec[3]={0,0,0},crossr[3]={0,0,0},crossc[3]={0,0,0},crossd[2]={0,0},circled[2]={0,0},winner=0;
    char a[3][3],c,w[]="GAME By SanChh";
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            a[i][j]=' ';
        }
    }
    a[0][0]='O';
    Setcolor(6,9);
    space();
    for(j=0;j<14;j++)
    {
        printf("%c",w[j]);
        for(i=0;i<59999999;i++);
    }
        for(i=0;i<599999999;i++);


    do{
    player1:
    system ("CLS");
    Setcolor(5,8);
    space();
    color(6);
    for(j=0;j<14;j++)
    {
        printf("%c",w[j]);
    }
    printf("\n");
    space();
    printf("Use WASD to move the marker and Enter to select the box.\n");
//FRAMEWORK OF BOX
    printf("\n");
    space();
    color(5);
    printf(" --- --- ---\n");
    for(i=0;i<3;i++)
    {
        space();
        printf("|");
        for(j=0;j<3;j++)
        {
            if(a[i][j]=='O'){
            color(4);}
            if(a[i][j]=='X'){
            color(4);}
            if(a[i][j]=='o'){
            color(2);}
            if(a[i][j]=='x'){
            color(1);}
            printf(" %c ",a[i][j]);
            color(5);
            printf("|");
        }
        printf("\n");
        space();
        printf(" --- --- ---\n");

    }
    if(winner!=0)
    {
        printf("\n");
        space();
        color(0);
        printf("Winner is Player %d",winner);
        color(5);
        break;
    }
    if(k==9 && winner==0)
    {
        printf("\n");
    space();
    color(0);
    printf("     Draw");
    color(5);
    break;
    }
    color(0);
    printf("\n");
    space();
    printf("Player %d's turn",turn);
    color(5);
    printf("\n\n");
    space();
    color(4);
    c=getch();
    d=c;

//FOR OUT OF BORDER ERROR
    if(l==0 && d==119)
    {
        printf("OUT OF BORDER");
        for(i=0;i<99999999;i++);
        goto player1;
    }
    if(l==0 && m==0)
    {
        if(d==97){
        printf("OUT OF BORDER");
        for(i=0;i<99999999;i++);
        goto player1;}
    }
    if(l==2 && d==115)
    {
        printf("OUT OF BORDER");
        for(i=0;i<99999999;i++);
        goto player1;
    }
    if(l==2 && m==2)
    {
        if(d==100){
        printf("OUT OF BORDER");
        for(i=0;i<99999999;i++);
        goto player1;}
    }
    if(l==0 && m==2)
    {
        if(d==100){
        printf("OUT OF BORDER");
        for(i=0;i<99999999;i++);
        goto player1;}
    }
    if(l==1 && m==0)
    {
        if(d==97){
        printf("OUT OF BORDER");
        for(i=0;i<99999999;i++);
        goto player1;}
    }
    if(l==1 && m==2)
    {
        if(d==100){
        printf("OUT OF BORDER");
        for(i=0;i<99999999;i++);
        goto player1;}
    }
    if(l==2 && m==0)
    {
        if(d==97){
        printf("OUT OF BORDER");
        for(i=0;i<99999999;i++);
        goto player1;}
    }

//FOR POSTION OF O
    switch(d)
    {
    case 119:
        l--;
        if(a[l][m]!=' ')
        {
            r=l+1;
            t=m;
            if(l==1)
            {
                m=0;
                if(a[l][m]!=' ')
                {
                    m=1;
                }
                if(a[l][m]!=' ')
                {
                    m=2;
                }
                if(a[l][m]!=' ')
                {
                    l=0;
                    m=0;
                }
                if(a[l][m]!=' ')
                {
                    m=1;
                }
                if(a[l][m]!=' ')
                {
                    m=2;
                }
            }
            if(l==0)
            {
                    l=0;
                    m=0;
                if(a[l][m]!=' ')
                {
                    m=1;
                }
                if(a[l][m]!=' ')
                {
                    m=2;
                }
                if(a[l][m]!=' ')
                {
                    l=r;
                    m=t;
                    check=1;
                }
            }
    }
        break;

    case 97:
        m--;
        if(a[l][m]!=' ')
        {
            r=l;
            t=m+1;
            if(m==1)
            {
                if(l==0 || l==1)
                {
                    l=0;
                    if(a[l][m]!=' ')
                    {
                        l=1;
                    }
                    if(a[l][m]!=' ')
                    {
                        l=2;
                    }
                    m=0;
                    l=0;
                    if(a[l][m]!=' ')
                    {
                        l=1;
                    }
                    if(a[l][m]!=' ')
                    {
                        l=2;
                    }
                }
                else
                {
                    m=0;
                    l=2;
                    if(a[l][m]!=' ')
                    {
                        l=1;
                        m=1;
                    }
                    if(a[l][m]!=' ')
                    {
                        l=0;
                    }
                    if(a[l][m]!=' ')
                    {
                        l=1;
                        m=0;
                    }
                    if(a[l][m]!=' ')
                    {
                        l=0;
                    }
                }
            }
            else
            {
                    if(l==0)
                    {
                        if(a[l][m]!=' ')
                        {
                            l=1;
                        }
                        if(a[l][m]!=' ')
                        {
                            l=2;
                        }
                    }
                    else
                    {
                        l=2;
                        if(a[l][m]!=' ')
                        {
                            l=1;
                        }
                        if(a[l][m]!=' ')
                        {
                            l=0;
                        }
                    }
            }
            if(a[l][m]!=' ')
            {
                l=r;
                m=t;
                check=1;
            }
        }
        break;


    case 115:
        l++;
        if(a[l][m]!=' ')
        {
            r=l-1;
            t=m;
            if(l==1)
            {
                m=0;
                if(a[l][m]!=' ')
                {
                    m=1;
                }
                if(a[l][m]!=' ')
                {
                    m=2;
                }
                if(a[l][m]!=' ')
                {
                    l=2;
                    m=0;
                }
                if(a[l][m]!=' ')
                {
                    m=1;
                }
                if(a[l][m]!=' ')
                {
                    m=2;
                }
            }
            if(l==2)
            {
                    l=2;
                    m=0;
                if(a[l][m]!=' ')
                {
                    m=1;
                }
                if(a[l][m]!=' ')
                {
                    m=2;
                }
                if(a[l][m]!=' ')
                {
                    l=r;
                    m=t;
                    check=1;
                }
            }
    }
        break;


    case 100:
        m++;
        if(a[l][m]!=' ')
        {
            r=l;
            t=m-1;
            if(m==1)
            {
                if(l==0 || l==1)
                {
                    l=0;
                    if(a[l][m]!=' ')
                    {
                        l=1;
                    }
                    if(a[l][m]!=' ')
                    {
                        l=2;
                    }
                    if(a[l][m]!=' ')
                    {
                        m=2;
                        l=0;
                    }
                    if(a[l][m]!=' ')
                    {
                        l=1;
                    }
                    if(a[l][m]!=' ')
                    {
                        l=2;
                    }
                }
                else
                {
                    m=2;
                    if(a[l][m]!=' ')
                    {
                        m=1;
                        l=1;
                    }
                    if(a[l][m]!=' ')
                    {
                        l=0;
                    }
                    if(a[l][m]!=' ')
                    {
                        m=2;
                        l=1;
                    }
                    if(a[l][m]!=' ')
                    {
                        m=2;
                        l=0;
                    }
                }
            }
            else
            {
                if(l==0 || l==1)
                {
                    l=0;
                    if(a[l][m]!=' ')
                    {
                        l=1;
                    }
                    if(a[l][m]!=' ')
                    {
                        l=2;
                    }
                }
                else
                {
                    if(a[l][m]!=' ')
                    {
                        l=1;
                    }
                    if(a[l][m]!=' ')
                    {
                        l=0;
                    }
                }

            }
            if(a[l][m]!=' ')
                {
                    l=r;
                    m=t;
                    check=1;
                }
        }
        break;


    case 13:
        k++;
        break;


    default:
        printf("Invalid input");
        for(i=0;i<99999999;i++);
        goto player1;
    }

    if(d==13)
    {
        if(turn==1)
        {
            circler[l]++;
            circlec[m]++;
            if(l==m)
            {
                circled[0]++;
            }
            if(l+m==2)
            {
                circled[1]++;
            }
            a[l][m]='o';
            for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
                {
                    if(a[i][j]==' ')
                    {
                        a[i][j]='X';
                        turn=2;
                        l=i;
                        m=j;
                        p=i;
                        q=j;
                    }
                    if(turn==2)
                        break;
                }
                if(turn==2)
                    break;
            }
        }
        else
        {
            crossr[l]++;
            crossc[m]++;
            if(l==m)
            {
                crossd[0]++;
            }
            if(l+m==2)
            {
                crossd[1]++;
            }
            a[l][m]='x';
            for(i=0;i<3;i++)
            {
                for(j=0;j<3;j++)
                {
                    if(a[i][j]==' ')
                    {
                        a[i][j]='O';
                        turn=1;
                        l=i;
                        m=j;
                        p=i;
                        q=j;
                    }
                    if(turn==1)
                        break;
                }
                if(turn==1)
                    break;
            }
        }
    }
    else{
    if(turn==1)
    a[l][m]='O';
    if(turn==2)
    a[l][m]='X';
    if(check!=1){
    a[p][q]=' ';}
    check=0;
    p=l;
    q=m;}
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(circler[i]==3)
            {
                a[i][j]='O';
                if(k<9){
                a[l][m]=' ';}
                winner=1;
            }
            if(crossr[i]==3)
            {
                a[i][j]='X';
                if(k<9){
                a[l][m]=' ';}
                winner=2;
            }
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            if(circlec[i]==3)
            {
                a[j][i]='O';
                if(k<9){
                a[l][m]=' ';}
                winner=1;
            }
            if(crossc[i]==3)
            {
                a[j][i]='X';
                if(k<9){
                a[l][m]=' ';}
                winner=2;
            }
        }
    }
    if(circled[0]==3)
    {
        for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            {
                a[j][j]='O';
                if(k<9){
                a[l][m]=' ';}
                winner=1;
            }}
    }
    if(crossd[0]==3)
    {
        for(i=0;i<3;i++){
        for(j=0;j<3;j++)
            {
                a[j][j]='X';
                if(k<9){
                a[l][m]=' ';}
                winner=2;
            }}
    }
    if(circled[1]==3)
    {
        a[0][2]='O';
        a[1][1]='O';
        a[2][0]='O';
        if(k<9){
                a[l][m]=' ';}
        winner=1;
    }
    if(crossd[1]==3)
    {
        a[0][2]='X';
        a[1][1]='X';
        a[2][0]='X';
        if(k<9){
                a[l][m]=' ';}
        winner=2;
    }
    }while(k<=10);
}
