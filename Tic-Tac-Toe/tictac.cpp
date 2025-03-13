#include <bits/stdc++.h>
using namespace std;

int currentplayer;
char currentmarker;
char board[3][3];

void resetBoard() {
    char ch = '1';
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ch++;
        }
    }
}

void drawboard() {
    cout << "     |       |       \n";
    cout << "  " << board[0][0] << "  |   " << board[0][1] << "   |   " << board[0][2] << "\n";
    cout << "_____|_______|_______\n";
    cout << "     |       |       \n";
    cout << "  " << board[1][0] << "  |   " << board[1][1] << "   |   " << board[1][2] << "\n";
    cout << "_____|_______|_______\n";
    cout << "     |       |       \n";
    cout << "  " << board[2][0] << "  |   " << board[2][1] << "   |   " << board[2][2] << "\n";
    cout << "     |       |       \n";
}

bool placemarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = currentmarker;
        return true;
    }
    return false;
}

int winner() {
    // Rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return currentplayer;
        }
    }
    // Columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return currentplayer;
        }
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return currentplayer;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return currentplayer;
    }
    return 0;
}

void swapplayer() {
    currentmarker = (currentmarker == 'X') ? 'O' : 'X';
    currentplayer = (currentplayer == 1) ? 2 : 1;
}

void game() {
    resetBoard();
    
    string n1, n2;
    cout << "Enter the First player name: ";
    cin >> n1;
    cout << "Enter the Second Player name: ";
    cin >> n2;
    
    cout << n1 << " is Player 1, so they will play first.\n";
    cout << n2 << " is Player 2, so they will play second.\n";
    cout <<"Player 1, choose your marker (X or O): ";
    
    char markerP1;
    cin >> markerP1;
    
    while (markerP1 != 'X' && markerP1 != 'O') {
        cout << "Invalid marker! Please choose either X or O: ";
        cin >> markerP1;
    }

    currentplayer = 1;
    currentmarker = markerP1;

    drawboard();
    int playerwon = 0;
    
    for (int i = 0; i < 9; i++) {
        cout << "It's Player " << currentplayer << "'s turn. Enter your slot: ";
        int slot;
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Try again.\n";
            i--;
            continue;
        }
        if (!placemarker(slot)) {
            cout << "Slot occupied! Try again.\n";
            i--;
            continue;
        }

        drawboard();
        playerwon = winner();

        if (playerwon == 1) {
            cout << n1 << " wins!\n";
            return;
        }
        if (playerwon == 2) {
            cout << n2 << " wins!\n";
            return;
        }
        swapplayer();
    }

    cout << "It's a tie!\n";
}

int main() {
    game();
    return 0;
}
