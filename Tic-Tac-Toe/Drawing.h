
void draw_line() {
    cout << "      -------------------------------------\n";
};

void draw_mid_line() { cout << "\t\t|\t\t|\n"; };

void draw_row(int row) {
    if (row == 1) { cout << "\t" << xo[0] << "\t" << "|" << "\t" << xo[1] << "\t" << "|" << "\t" << xo[2] << endl; };
    if (row == 2) { cout << "\t" << xo[3] << "\t" << "|" << "\t" << xo[4] << "\t" << "|" << "\t" << xo[5] << endl; };
    if (row == 3) { cout << "\t" << xo[6] << "\t" << "|" << "\t" << xo[7] << "\t" << "|" << "\t" << xo[8] << endl; };
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