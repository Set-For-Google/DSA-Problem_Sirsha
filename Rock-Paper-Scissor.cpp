// created a Rock-paper-Scissor game with computer and user
#include <iostream>
#include <cstdlib>
#include <time.h>

// Constant variables
const char ROCK = 'r';
const char PAPER = 'p';
const char SCISSORS = 's';

using namespace std;

char getComputerOption()
{
    // Use current time as seed for random generator
    srand(time(0));
    // Random number
    int num = rand() % 3 + 1;

    if (num == 1)
        return 'r';
    if (num == 2)
        return 'p';
    if (num == 3)
        return 's';
}

char getUserOption()
{
    int n;
    char c;
    cout << "Rock, Paper and Scissors Game!" << endl;
    cout << "Choose one of the following options" << endl;
    cout << "-----------------------------------" << endl;
    cout << "(r) for rock " << endl
         << "(p) for paper" << endl
         << "(s) for scissors " << endl;
    cin >> c;

    while (c != 'r' && c != 'p' && c != 's')
    {
        cout << "Please enter one of the following options only. " << endl;
        cout << "(r) for rock " << endl
             << "(p) for paper" << endl
             << "(s) for scissors " << endl;
        cin >> c;
    }

    return c;
}

void showSelectedOption(char option)
{
    if (option == 'r')
        cout << "Rock" << endl;
    if (option == 'p')
        cout << "Paper" << endl;
    if (option == 's')
        cout << "Scissors" << endl;
}

int chooseWinner(char uChoice, char cChoice)
{
    int win = 0;

    if (uChoice == ROCK && cChoice == PAPER)
    {
        cout << "Computer Wins! Paper wraps Rock." << endl;
        win= 0;
    }
    else if (uChoice == PAPER && cChoice == SCISSORS)
    {
        cout << "Computer Wins! Scissors cut Paper." << endl;
        win= 0;
    }
    else if (uChoice == SCISSORS && cChoice == ROCK)
    {
        cout << "Computer Wins! Rock smashes Scissors." << endl;
        win= 0;
    }
    else if (uChoice == ROCK && cChoice == SCISSORS)
    {
        cout << "You Win! Paper wraps Rock." << endl;
        win= 1;
    }
    else if (uChoice == PAPER && cChoice == ROCK)
    {
        cout << "You Win! Paper wraps Rock." << endl;
        win= 1;
    }
    else if (uChoice == SCISSORS && cChoice == PAPER)
    {
        cout << "You Win! Scissors cut Paper." << endl;
        win= 1;
    }
    else
    {
        cout << "Tie. Play again win the Game." << endl;
        win= 0;
    }

    return win;
}

int main()
{
    int n,result,score=0;
    string name;
    // User's choice
    char uChoice;
    // Compter's choice
    char cChoice;
    cout << "What's your name?" << endl;
    cin >> name;
    cout << "Enter How many times you want to play with computer" << endl;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        uChoice = getUserOption(); // for user choice
        cout << "Your choice is: " << endl;
        showSelectedOption(uChoice);

        cout << "Computer's choice is: " << endl;
        cChoice = getComputerOption(); // for computer choice
        showSelectedOption(cChoice);
        result= chooseWinner(uChoice, cChoice);
        if(result==0){
            score+=0;
        }
        else if(result==1){
            score+=1;
        } 
    }
    cout<<name <<"  Has a final Score of "<<score<<endl;
    return 0;
}