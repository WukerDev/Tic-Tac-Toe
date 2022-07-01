// game win logic
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
		// add more if statements here for more win conditions
        ) {
        game = 0;
		// game over
    };
};
