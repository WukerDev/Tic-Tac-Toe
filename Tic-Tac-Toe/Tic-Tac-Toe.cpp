#include <iostream>



bool randomise, game = 1;
int num; 
char xo[10] = { '1','2','3','4','5','6','7','8','9' }; // numbers on field

#include "Winning_Logic.hpp" 
#include "Drawing.hpp" 
// including the header files

void change(int number, bool player) {
    if (player == 0) { xo[number - 1] = 'X'; };
    if (player == 1) { xo[number - 1] = 'O'; };
};
// changing the player from X to O and vice versa

void main_game() {
    srand(time(NULL));    // randomising the seed
    randomise = rand() % 2;    // randomising the current player
    while (game) {   // while the game is running
        randomise = !randomise; // changing the player
        system("CLS");    // clearing the screen
        draw_board();   // drawing the board
        if (randomise == 0) { std::cout << "Player X turn:"; }    // printing the current player
		else { std::cout << "Player O turn:"; };
        std::cin >> num;   // taking the field from the user
        while (xo[num - 1] == 'O' || xo[num - 1] == 'X') { std::cout << "Invalid number! Try again:"; std::cin.ignore(); std::cin >> num; };
		// checking if the field is already taken
        change(num, randomise);  // changing field to X or O
        win_checker();   // checking if the player won
    };
};

int main()
{
    system("COLOR F4");
	// changing the background colour to white and font to red
    draw_board();
    main_game();
    draw_victory();
	// calling the main game functions
	return 0;
}