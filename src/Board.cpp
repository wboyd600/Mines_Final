//
// Created by wesley on 12/1/18.
//
#include "Board.h"
#include <iostream>


void Board::CheckIfGameWon(){
    bool allNonMinesRevealed = true;
    for (int i = 0; i < boardWidth; ++i) {
        for (int j = 0; j < boardHeight; ++j) {
            if(tileVector[i][j].GetHasMine()){

            }else{
                if(!tileVector[i][j].GetRevealed()){
                    allNonMinesRevealed = false;
                }
            }
        }
    }
    if(allNonMinesRevealed){
        gameOver = true;
        gameWon = true;
    }
}
void Board::HandleRightClick(int x, int y) {
    if (!gameOver) {
        if(!tileVector[x][y].GetRevealed()){
            if (!tileVector[x][y].GetHasFlag()) {
                tileVector[x][y].SetFlag(true);
                flagCount--;
            } else {
                tileVector[x][y].SetFlag(false);
                flagCount++;
            }
            CheckIfGameWon();
        }
    }
}

void Board::HandleLeftClick(int x, int y) {
    if (!tileVector[x][y].GetHasFlag()) {
        if (tileVector[x][y].GetHasMine()) {
            tileVector[x][y].SetRevealed(true);
            gameOver = true;
        } else if(!tileVector[x][y].GetRevealed()){
            tileVector[x][y].SetBeenClicked(true);
            tileVector[x][y].SetRevealed(true);
            RevealAfterClick(tileVector[x][y]);
        }
    } else {

    }
    CheckIfGameWon();
}

void Board::PopulateWithMines(vector<vector<Tile>> &miMines) {
    int minesAdded = 0;
    srand((int) time(0));
    while (minesAdded < 50) {
        int x = (rand() % boardWidth);
        int y = (rand() % boardHeight);
        if (!miMines[x][y].GetHasMine()) {
            miMines[x][y].SetHasMine(true);
            minesAdded++;
        } else {
            continue;
        }
    }
}

bool Board::InBounds(int x, int y) {
    if (x >= 0 && x <= 24) {
        if (y >= 0 && y <= 15)
            return true;
    }
    return false;
}

void Board::SetTilesAround(vector<vector<Tile>> &miTiles) {
    vector<Tile *> tempVector;
    for (int i = 0; i <= 24; i++)
        for (int j = 0; j <= 15; j++) {
            if (InBounds(i - 1, j)) {
                tempVector.push_back(&miTiles[i - 1][j]);
            }
            if (InBounds(i - 1, j + 1)) {
                tempVector.push_back(&miTiles[i - 1][j + 1]);
            }
            if (InBounds(i, j + 1)) {
                tempVector.push_back(&miTiles[i][j + 1]);
            }
            if (InBounds(i + 1, j + 1)) {
                tempVector.push_back(&miTiles[i + 1][j + 1]);
            }
            if (InBounds(i + 1, j)) {
                tempVector.push_back(&miTiles[i + 1][j]);
            }
            if (InBounds(i + 1, j - 1)) {
                tempVector.push_back(&miTiles[i + 1][j - 1]);
            }
            if (InBounds(i, j - 1)) {
                tempVector.push_back(&miTiles[i][j - 1]);
            }
            if (InBounds(i - 1, j - 1)) {
                tempVector.push_back(&miTiles[i - 1][j - 1]);
            }
            miTiles[i][j].SetTilesAround(tempVector);
            tempVector.clear();
        }
}

void Board::SetHasNumber(vector<vector<Tile>> &miTiles) {
    vector<Tile *> tempVector;
    for (int i = 0; i < boardWidth; i++)
        for (int j = 0; j < boardHeight; j++) {
            if ((miTiles[i][j].GetNumberOfMinesAround() > 0) && !(miTiles[i][j].GetHasMine())) {
                miTiles[i][j].SetHasNumber(true);
            }
        }
}

void Board::RevealAfterClick(Tile &clicked) {
    vector<Tile *> tilesRound = clicked.GetTilesAround();
    int i = 0;
    if(clicked.GetNumberOfMinesAround() == 0){
        do {
            if (!tilesRound[i]->GetRevealed()) {
                if (!tilesRound[i]->GetHasMine()) {
                    if (!tilesRound[i]->GetHasNumber()) {
                        tilesRound[i]->SetRevealed(true);
                        RevealAfterClick(*tilesRound[i]);
                    } else
                        tilesRound[i]->SetRevealed(true);
                }
            }
            i++;
        } while (i < tilesRound.size());
    }

}