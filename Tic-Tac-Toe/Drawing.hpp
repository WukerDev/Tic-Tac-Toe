
void draw_line() {
    std::cout << "      -------------------------------------\n";
};
// draws a line

void draw_score() {
    if (stats[0] > 0 || stats[1] > 0) {
        std::cout << " \t\t      " << stats[0] << " To " << stats[1] << std::endl;
    }
}


void draw_mid_line() { std::cout << "\t\t|\t\t|\n"; };
// draws a line in the middle of the board

void draw_row(int row) {
    if (row == 1) { std::cout << "\t" << xo[0] << "\t" << "|" << "\t" << xo[1] << "\t" << "|" << "\t" << xo[2] << std::endl; };
    if (row == 2) { std::cout << "\t" << xo[3] << "\t" << "|" << "\t" << xo[4] << "\t" << "|" << "\t" << xo[5] << std::endl; };
    if (row == 3) { std::cout << "\t" << xo[6] << "\t" << "|" << "\t" << xo[7] << "\t" << "|" << "\t" << xo[8] << std::endl; };
};
// draws a row of the board

void draw_board() {
    std::cout << "\t           Tic Tac Toe\n";
    std::cout << "\t       Player X VS Player O\n";
    draw_score();
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
// draws the board

void draw_victory() {
    system("CLS");
    draw_board();
    if (randomise == 0) { std::cout << "Player X WON THE GAME!"; stats[0]++; }
    if (randomise == 1) { std::cout << "Player O WON THE GAME!"; stats[1]++;  }
};
// draws the victory screen