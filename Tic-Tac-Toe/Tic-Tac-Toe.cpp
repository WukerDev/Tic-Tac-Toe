#include <iostream>

using namespace std;

bool randomise, game = 1;
int num;
char xo[10] = { '1','2','3','4','5','6','7','8','9' }; // numbers on field

#include "Winning_Logic.hpp" //winning
#include "Drawing.hpp" //drawing functions

void change(int number, bool player) {
    if (player == 0) { xo[number - 1] = 'X'; };
    if (player == 1) { xo[number - 1] = 'O'; };
};

void main_game() {
    srand(time(NULL));
    randomise = rand() % 2;
    while (game) {
        randomise = !randomise;
        system("CLS");
        draw_board();
        if (randomise == 0) { cout << "Player X turn:"; }
        if (randomise == 1) { cout << "Player O turn:"; }
        cin >> num;
        while (xo[num - 1] == 'O' || xo[num - 1] == 'X') { cout << "Invalid number! Try again:"; cin.ignore(); cin >> num; };
        change(num, randomise);
        win_checker();
    };
};

int main()
{
    system("COLOR F4");
    draw_board();
    main_game();
    draw_victory();
}