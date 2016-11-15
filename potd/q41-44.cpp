#include <iostream>
using namespace std;


void getInput(int playerid, int *arr, int SIZE){
    // get user choice
    char token = (playerid == 1) ? 'X' : 'O';
    int row, col;
    cout << "Player " << playerid << ", it's your turn." << endl;
    do{
        cout << "Where would you like to place an " << token << "? Row (1, 2...): ";
        cin >> row;
        cout << "Col (1, 2...): ";
        cin >> col;
        if(col < 1 || col > SIZE)
            cout << "Column must be between 1 and " << SIZE << endl;
        if(row < 1 || row > SIZE)
            cout << "Row must be between 1 and " << SIZE << endl;
        if(arr[(row - 1) * SIZE + (col - 1)] != 0)
            cout << "That square is already occupied" << endl;
    } while( row < 1 || row > SIZE || col < 1 || col > SIZE || arr[(row - 1) * SIZE + (col - 1)] != 0);
    
    // store in data structure
    arr[(row - 1) * SIZE + (col - 1)] = playerid;
}

void printBoard(int *arr, int SIZE){
    for(int i = 0; i < SIZE; i++){
        // print first row of grid square
        for(int j = 0; j < SIZE; j++){
            int index = i * SIZE + j;
            if(arr[index] == 0)
                cout << " ";
            else if (arr[index] == 1)
                cout << "X";
            else
                cout << "O";
            cout << "  ";
            if(j != SIZE - 1)
                cout << "|";
        }
        cout << endl;
        // print second row of grid square
        if(i != SIZE - 1){
            for(int j = 0; j < SIZE; j++){
                cout << "___";
                if(j != SIZE - 1)
                    cout << "|";
            }
        }
        else{
            for(int j = 0; j < SIZE; j++){
                cout << "   ";
                if(j != SIZE -1)
                    cout << "|";
            }
        }
        cout << endl;
    }
}

int check(int *arr, int SIZE){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(arr[i * SIZE + j] == 0)
                continue;
            
            //check to the right
            if(j + 2 < SIZE){
                if(arr[i * SIZE + j] == arr[i * SIZE + j + 1] && arr[i * SIZE + j] == arr[i * SIZE + j + 2])
                    return arr[i * SIZE + j];
            }
            //check down
            if(i + 2 < SIZE){
                if(arr[i * SIZE + j] == arr[(i + 1) * SIZE + j] && arr[i * SIZE + j] == arr[(i + 2) * SIZE + j])
                    return arr[i * SIZE + j];
            }
            //check down/right diagonal
            if(i + 2 < SIZE && j + 2 < SIZE){
                if(arr[i * SIZE + j] == arr[(i + 1) * SIZE + j + 1] && arr[i * SIZE + j] == arr[(i + 2) * SIZE + j + 2])
                    return arr[i * SIZE + j];
            }
            //check down/left diagonal
            if(i + 2 < SIZE && j - 2 >= 0){
                if(arr[i * SIZE + j] == arr[(i + 1) * SIZE + j - 1] && arr[i * SIZE + j] == arr[(i + 2) * SIZE + j - 2])
                    return arr[i * SIZE + j];
            }
        }
    }
    return 0;
}

int main(){
    int size;
    int *arr;
    cout << "WElCOME TO TIC-TAC-TOE 5000\nHow large would you like the nxn board to be? n=";
    cin >> size;
    arr = new int[size*size];
    // initialize board
    for(int i = 0; i < size*size; i++){
        arr[i] = 0;
    }
    cout << "LET'S BEGIN!" << endl;
    int turn = 0;
    int player = 1;
    int winner;
    while(turn < size*size){
        printBoard(arr, size);
        cout << "PLAYER " << player << " it's your move.";
        getInput(player, arr, size);
        if(winner = check(arr, size)){
            printBoard(arr, size);
            cout << "PLAYER " << winner << " WINS!" << endl;
            delete [] arr;
            return 0;
        }
        player = (player == 1) ? 2 : 1;
        turn++;
    }
    printBoard(arr, size);
    cout << "Cat's game." << endl;
    delete [] arr;
    return 0;
}
