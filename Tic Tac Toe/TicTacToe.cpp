#include <iostream>
#include <cstdlib>
#include <ctime>
//#include <string>


using namespace std;
//using text_t = string;   pengganti typedef
//getline(cin, name)       untuk include spasi
//getline(cin>>ws, name)   ws=widespace/spasi
//#include <cmath>         math function
//array.empty()
//string.append (@gmail.com) 
//const = constant value   (pi=3.14)
//array[] = {x, "xxx", etc};
//sizeof()                  size in bytes
//for(data type : variable_name)  foreach loop array
//& = adress (cth: cout<<&name)

void drawBoard(char *spaces);
void playerMove (char *spaces);
void computerMove (char *spaces);
int checkTie(char *spaces);
int checkResult(char *spaces);
void checkWinner(char *spaces, bool *running);

int main() 
{
   char choices[9]={' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '};
   bool running=true;
   int input=0;

   do{
      drawBoard(choices);
      playerMove(choices);
      if(checkTie(choices)==1)
      {
         checkWinner(choices, &running);
      }
      else
      {
         computerMove(choices);
         checkWinner(choices, &running);
      }
   }while(running==true);

   cout<<'\n';
   system("pause");
   return 0;
}

void drawBoard(char *spaces)
{
   cout<<"___________________\n";
   cout<<"|  "<<spaces[0]<<"  "<<"|  "<<spaces[1]<<"  "<<"|  "<<spaces[2]<<"  |\n";
   cout<<"|-----------------|\n";
   cout<<"|  "<<spaces[3]<<"  "<<"|  "<<spaces[4]<<"  "<<"|  "<<spaces[5]<<"  |\n";
   cout<<"|-----------------|\n";
   cout<<"|  "<<spaces[6]<<"  "<<"|  "<<spaces[7]<<"  "<<"|  "<<spaces[8]<<"  |\n";
   cout<<"-------------------\n";
}

void playerMove (char *spaces)
{
   int player;
   string condition;

   do{
      cout<<"Enter position 1-9: ";
      cin>>player;
      if(player>0 && player<10 && spaces[player-1]==' ')
      {
         spaces[player-1]='X';
         condition="pass";
      }
      else if(player>0 && player<10 && spaces[player-1]!=' ')
      {
         cout<<"Column already filled!\n";
      }
   }while(condition!="pass");
}

void computerMove (char *spaces)
{
   int computer;
   srand(time(0));

   do{
      computer=rand()%9;
   }while(spaces[computer-1]!=' '); 
   spaces[computer-1]='O'; 
}

int checkTie(char *spaces)
{
   int i, cond=0;

   for (i=0; i<9; i++)
   {
      if(spaces[i]!=' ')
      {
         cond++;
      }
   }

   if(cond==9||checkResult(spaces)==0||checkResult(spaces)==1)
   {
      return 1;
   }
   else
   {
      return 0;
   }
}

int checkResult(char *spaces)
{
   if(spaces[0]=='X'&&spaces[1]=='X'&&spaces[2]=='X' ||
      spaces[3]=='X'&&spaces[4]=='X'&&spaces[5]=='X' ||
      spaces[6]=='X'&&spaces[7]=='X'&&spaces[8]=='X' ||
      spaces[0]=='X'&&spaces[3]=='X'&&spaces[6]=='X' ||
      spaces[1]=='X'&&spaces[4]=='X'&&spaces[7]=='X' ||
      spaces[2]=='X'&&spaces[5]=='X'&&spaces[8]=='X' ||
      spaces[0]=='X'&&spaces[4]=='X'&&spaces[8]=='X' ||
      spaces[2]=='X'&&spaces[4]=='X'&&spaces[6]=='X')
   {
      return 0;
   }
   else if(spaces[0]=='O'&&spaces[1]=='O'&&spaces[2]=='O' ||
      spaces[3]=='O'&&spaces[4]=='O'&&spaces[5]=='O' ||
      spaces[6]=='O'&&spaces[7]=='O'&&spaces[8]=='O' ||
      spaces[0]=='O'&&spaces[3]=='O'&&spaces[6]=='O' ||
      spaces[1]=='O'&&spaces[4]=='O'&&spaces[7]=='O' ||
      spaces[2]=='O'&&spaces[5]=='O'&&spaces[8]=='O' ||
      spaces[0]=='O'&&spaces[4]=='O'&&spaces[8]=='O' ||
      spaces[2]=='O'&&spaces[4]=='O'&&spaces[6]=='O')
   {
      return 1;
   }
}

void checkWinner(char *spaces, bool *running)
{
   if(checkTie(spaces)==1)
   {
      drawBoard(spaces);
      cout<<"\nGAME FINISHED!\n";
      if(checkResult(spaces)==0)
      {
         cout<<"Winner: PLAYER\n";
      }
      else if(checkResult(spaces)==1)
      {
         cout<<"Winner: COMPUTER\n";
      }
      else
      {
         cout<<"Winner: TIE\n";
      }
      *running=false;
   }
}