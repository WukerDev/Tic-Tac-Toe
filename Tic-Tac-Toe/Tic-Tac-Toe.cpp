#include <iostream>

using namespace std;

bool randomise, game = 1;
int num;
char xo[10] = { '1','2','3','4','5','6','7','8','9' };
// numbers on field

//drawing function
void draw_line() {
    cout << "      -------------------------------------\n";
};

void draw_mid_line() { cout << "\t\t|\t\t|\n"; };

void draw_row(int row) {
    if (row == 1) { cout << "\t" << xo[0] << "\t" << "|" << "\t" << xo[1] << "\t" << "|" << "\t" << xo[2] << endl; };
    if (row == 2) { cout << "\t" << xo[3] << "\t" << "|" << "\t" << xo[4] << "\t" << "|" << "\t" << xo[5] << endl; };
    if (row == 3) { cout << "\t" << xo[6] << "\t" << "|" << "\t" << xo[7] << "\t" << "|" << "\t" << xo[8] << endl; };
};


void change(int number, bool player) {
    if (player == 0) { xo[number - 1] = 'X'; };
    if (player == 1) { xo[number - 1] = 'O'; };
};

bool vertical_win(int num) {
    if (xo[num - 1] == xo[num + 2] && xo[num + 2] == xo[num + 5]) { return true; };
};

bool horizontal_win(int num) {
    if (num == 1) { if (xo[num - 1] == xo[num] && xo[num] == xo[num + 1]) { return true; }; };
    if (num == 2) { if (xo[num + 1] == xo[num + 2] && xo[num + 2] == xo[num + 3]) { return true; }; };
    if (num == 3) { if (xo[num + 3] == xo[num + 4] && xo[num + 4] == xo[num + 5]) { return true; }; };
};

bool cross_win() {
    if (xo[0] == xo[4] && xo[4] == xo[8]) { return true; }
    if (xo[6] == xo[4] && xo[4] == xo[2]) { return true; }
};

void win_checker() {
    if (
        vertical_win(1) == true ||
        vertical_win(2) == true ||
        vertical_win(3) == true ||
        horizontal_win(1) == true ||
        horizontal_win(2) == true ||
        horizontal_win(3) == true ||
        cross_win() == true
        ) {
        game = 0;
    };
};

void draw_board() {
    cout << "\t           Tic Tac Toe\n";
    cout << "\t       Player X VS Player O\n";
    draw_mid_line();
    draw_row(1);
    draw_mid_line();
    draw_line();
    draw_mid_line();
    draw_row(2);
    draw_mid_line();
    draw_line();
    draw_mid_line();
    draw_row(3);
    draw_mid_line();
};

void draw_victory() {
    system("CLS");
    draw_board();
    if (randomise == 0) { cout << "Player X WON THE GAME!"; }
    if (randomise == 1) { cout << "Player O WON THE GAME!"; }
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