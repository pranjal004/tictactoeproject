#include<iostream>
#include<conio.h>
#include<stdlib.h>

using namespace std;
char a[3][3]= {{'1','2','3'},{'4','5','6'}, {'7','8','9'}};
bool draw= false;
char turn= 'X';
int row, column;




void display()
{   system("cls");
    cout<<"TIC TAC TOE GAME"<<endl;
    cout<<"PLAYER[X]\nPLAYER[O]"<<endl;
    cout<<"________________________________________________________"<<endl;
    cout<<"                                                        "<<endl;
    cout<<"\t\t     |     |      "<<endl;
    cout<<"\t\t "<<a[0][0]<<"   | "<<a[0][1]<<"   | "<<a[0][2]<<endl;
    cout<<"\t\t_____|_____|_____ "<<endl;
    cout<<"\t\t     |     |      "<<endl;
    cout<<"\t\t "<<a[1][0]<<"   | "<<a[1][1]<<"   | "<<a[1][2]<<endl;
    cout<<"\t\t_____|_____|_____ "<<endl;
    cout<<"\t\t     |     |      "<<endl;
    cout<<"\t\t "<<a[2][0]<<"   | "<<a[2][1]<<"   | "<<a[2][2]<<endl;
    cout<<"\t\t_____|_____|_____ "<<endl;
    cout<<"\t\t     |     |      "<<endl;


}

void player_turn()
{      int choice;
        if(turn== 'X')
        {
            cout<<"PLAYER[X] turn"<<endl;

        }
        else if(turn== 'O')
        {
            cout<<"PLAYER[O] turn"<<endl;

        }
        cin>>choice;
        switch(choice)
        {

            case 1: row=0 , column=0;
                    break;
            case 2: row=0 , column=1;
                    break;
            case 3: row=0 , column=2;
                    break;
            case 4: row=1 , column=0;
                    break;
            case 5: row=1 , column=1;
                    break;
            case 6: row=1 , column=2;
                    break;
            case 7: row=2 , column=0;
                    break;
            case 8: row=2 , column=1;
                    break;
            case 9: row=2 , column=2;
                    break;
            default: cout<<"Invalid choice";
                    break;
        }

        if(turn== 'X'&& a[row][column]!= 'X' && a[row][column]!= 'O')
        {
            a[row][column]= 'X';
            turn= 'O';

        }
        else if(turn== 'O'&& a[row][column]!= 'X' && a[row][column]!= 'O')
        {
            a[row][column]= 'O';
            turn= 'X';

        }
        else
        {cout<< "Box already filled\n Please try again\n";
        player_turn();
        }


}

bool gameover(){
int i, j;
for(i=0; i<3; i++)
{
    if(a[i][0]== a[i][1] && a[i][0]== a[i][2]|| a[0][i]==a[1][i] && a[0][i]== a[2][i])
        return false;

        if( a[0][0]==a[1][1] && a[0][0]== a[2][2]|| a[0][2]==a[1][1] && a[0][2]==a[2][0])
            return false;
}
for(i=0; i<3; i++)
{
    for(j=0; j<3; j++)
    {
        if(a[i][j]!= 'X' && a[i][j]!= 'O')
            return true;
    }

}

draw= true;
return false;


}
int main()
{



while(gameover())
    {
      display();
      player_turn();
      gameover();

}
if(turn== 'X' && draw== false)
{
    cout<<"PLAYER[O] won! Congratulation!!"<<endl;
}
else if(turn== 'O' && draw== false)
{
    cout<<"PLAYER[X] won! Congratulation!!"<<endl;
}
else
    cout<<"GAME DRAW!!"<<endl;


    return 0;
}
