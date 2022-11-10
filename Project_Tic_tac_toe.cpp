#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

void homeMenu();

void StartBoard (char board [3][3]){
    int line, colunm;

    for (line = 0 ; line < 3 ; line++){
        for(colunm = 0;colunm < 3; colunm++){
            board[line][colunm] = '-';
        }
    }
    
}

void DisplayBoard (char board [3][3]){
    int line, colunm;

    for (line = 0 ; line < 3 ; line++){
        
        for(colunm = 0;colunm < 3; colunm++){
            cout << "|" << board[line][colunm] << "|";
        }
        cout << "\n";
    
    }
}

int checks (char board [3][3]){

    int line, colunm;

    // Analysis of rows, columns and diagonals

    for(line=0;line<3;line++){
        

            if(board [line][0] == 'x' && board [line][0] == board [line][1] && board [line][1] == board [line][2]){
                
                return 1;

            }else if(board [line][0] == 'o' && board [line][0] == board [line][1] && board [line][1] == board [line][2]){

                return 2;
                
            }
    } 


    for(colunm=0;colunm<3;colunm++){
        

            if(board [0][colunm] == 'x' && board [0][colunm] == board [1][colunm] && board [1][colunm] == board [2][colunm]){
                
                return 1;

            }else if(board [0][colunm] == 'o' && board [0][colunm] == board [1][colunm] && board [1][colunm] == board [2][colunm]){

                return 2;
                 
            }
    }  

    if(board [0][0] != '-' && board [0][0] == board [1][1] && board [1][1] == board [2][2]){
                
        if(board [0][0] == 'x') {
            return 1;
        }else {
            return 2;
        } 
    }

    if (board [2][0] != '-' && board [2][0] == board [1][1] && board [1][1] == board [0][2]){

        if(board [0][0] == 'x') {
            return 1;
        }else {
            return 2;
        } 

    }

    return 0;
}

int Position (char board [3][3],int ChosenLine,int ChosenColunm,int game,int round){


    if(board[ChosenLine][ChosenColunm] != '-'){

        system("read -p '\nRepeated position or invalid position, continues...' var");
        
    }else{

        if(round == 1){

            board [ChosenLine][ChosenColunm] = 'x'; 
            round = 2;
            
        }else{

            board [ChosenLine][ChosenColunm] = 'o';
            round = 1;
    
        }

        game++;
    }
    
    return game;
}


void play(string PlayerName1,string PlayerName2, int Player1score, int Player2score){

    char board [3][3];
    string PlayerNameRound; 
    int ChosenLine, ChosenColunm, positiongame;
    int StatusTheGame = 1,game = 0,status,option, round;
    int positions [9][2] ={{2,0},{2,1},{2,2},{1,0},{1,1},{1,2},{0,0},{0,1},{0,2}};

    system("clear");
    StartBoard(board);

    while (StatusTheGame == 1 && game < 9){

        
        system("clear");
        DisplayBoard(board);

        if(game%2 == 0){
            PlayerNameRound = PlayerName1;
            round = 1;
        }else{
            PlayerNameRound = PlayerName2;
            round = 2;
        }
        
        cout << "\nInstruction map" << "\t\t\tScore:\n" << endl
            << "| 7 | 8 | 9 |" << "\t\t\t" << PlayerName1 << ": " << Player1score << endl
            << "| 4 | 5 | 6 |" << "\t\t\t" << PlayerName2 << ": " << Player2score << endl
            << "| 1 | 2 | 3 |\n" << endl;


        cout << "\nPlayer " << PlayerNameRound << ", it's your turn!!\n";
        cout << "\nEnter a position, according to the map above:\n";
        cin >> positiongame;

        ChosenLine = positions[positiongame-1][0];
        ChosenColunm = positions[positiongame-1][1];

        game = Position(board, ChosenLine, ChosenColunm,game,round);
        status = checks(board);
        
        if (status == 1){

            StatusTheGame = 2;
            system ("clear");
            DisplayBoard (board);
            cout << "\nCongratulations " << PlayerNameRound << ", you win (^-^)\n\n";
            Player1score++;
            
        }else if(status == 2){
        
            StatusTheGame = 2;
            system ("clear");
            DisplayBoard (board);
            cout << "\nCongratulations " << PlayerNameRound << ", you win (^-^)\n\n"; 
            Player2score++;
        }
    }

    cout << "\nWhat do you want to do?\n"; 
    cout << "\n1- Next round"; 
    cout << "\n2- Return Home menu"; 
    cout << "\n3- Exit\n";
    cin >> option;

    if(option == 1){

        play(PlayerName1,PlayerName2,Player1score,Player2score);

    }else if(option == 2){

        homeMenu();

    }
    
}

void About(){

    system ("clear");
    cout <<            "Game Information\n\n";
    cout << "---------------------------------------" << endl
         << "|                                     |" << endl
         << "|               ABOUT                 |" << endl
         << "|                                     |" << endl
         << "|          Game produced by:          |" << endl
         << "|                                     |" << endl
         << "|   Tiago Gimenes Scarpelin           |" << endl
         << "|                                     |" << endl
         << "|       Produced on the date of:      |" << endl
         << "|                                     |" << endl
         << "|   09/11/2022                        |" << endl
         << "|                                     |" << endl
         << "|         With the help of:           |" << endl
         << "|                                     |" << endl
         << "|    Teacher John's Course at Udemy:  |" << endl
         << "|                                     |" << endl
         << "|  Link:https://www.udemy.com/course/ |" << endl
         << "|  curso-completo-de-linguagem-c-     |" << endl
         << "|  iniciante-ao-avancado/             |" << endl
         << "|                                     |" << endl
         << "---------------------------------------" << endl;


    system("read -p 'Press enter to return to home menu...' var");
    homeMenu();
}


void homeMenu(){

    int option = 0;
    string PlayerName1,PlayerName2;

    while (option < 1 || option > 3){

        system ("clear");
        cout << "1-Play\n";
        cout << "2-About\n";
        cout << "3-Exit\n";
        cout << "Choose a option and press enter\n";
        cin >> option;

        switch (option){
            case 1:
                cout << "\nPlayer name 1:\n";
                cin >> PlayerName1;
                cout << "Player name 2:\n";
                cin >> PlayerName2;
                play(PlayerName1,PlayerName2,0,0);
                break;
            case 2: 
                About();
                break;
            case 3:
                cout << "\nThank you! See you!\n\n";
                break;
        }
    }

}

int main (){

    homeMenu();

    return 0;
}