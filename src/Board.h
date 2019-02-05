#include "Tile.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include <string>
#include <fstream>
#include <cstring>
using namespace std;
using namespace sf;
class Board{
public:

    Board(int width, int height){       //default constructor 50 random mines
        this->boardWidth = width;
        this->boardHeight = height;
        for (int i = 0; i < width; ++i) {
            vector<Tile> tempVector;
            for (int j = 0; j < height; ++j) {
                Tile finnaAdd;
                tempVector.push_back(finnaAdd);
            }
            tileVector.push_back(tempVector);
            tempVector.clear();
        }
        PopulateWithMines(tileVector);
        SetTilesAround(tileVector);
        SetHasNumber(tileVector);
        gameOver = false;
        gameWon = false;
        flagCount = 50;
    }
    Board(int width,int height,const char * filename){  //loads board from files
        this->boardWidth = width;
        this->boardHeight = height;
        for (int i = 0; i < width; ++i) {
            vector<Tile> tempVector;
            for (int j = 0; j < height; ++j) {
                Tile finnaAdd;
                tempVector.push_back(finnaAdd);
            }
            tileVector.push_back(tempVector);
            tempVector.clear();
        }
        flagCount = 0;
        ifstream inFile;
        inFile.open(filename,ios::in);
        string line;
        int numberOfLines = GetNumberOfLines(filename);
        if(inFile.is_open()){
            for (int i = 0; i <= numberOfLines; ++i) {
                getline(inFile, line);
                char * tab2 = new char [line.length()+1];
                strcpy (tab2, line.c_str());
                for (int j = 0; j < 25; ++j) {
                    if(tab2[j] == '1'){
                        tileVector[j][i].SetHasMine(true);
                        flagCount++;
                    }else{
                        tileVector[j][i].SetHasMine(false);
                    }
                }
            }
        }
        SetTilesAround(tileVector);
        SetHasNumber(tileVector);
        gameOver = false;
        gameWon = false;

    }
    void HandleRightClick(int x, int y);
    void HandleLeftClick(int x, int y);
    vector<vector<Tile>> GetBoard(){
        return this->tileVector;
    }
    void PopulateWithMines(vector<vector<Tile>> &miMines);
    void SetTilesAround(vector<vector<Tile>> &miTiles);
    void SetHasNumber(vector<vector<Tile>> &miTiles);
    void RevealAfterClick(Tile &clicked);
    bool InBounds(int x, int y);
    bool GetGameOver(){
        return gameOver;
    }
    bool GetGameWon(){
        return gameWon;
    }
    void CheckIfGameWon();
    int GetFlagCount(){
        return flagCount;
    }
    int GetNumberOfLines(string fileName){
        ifstream inFile;
        inFile.open(fileName,ios::in);
        string line;
        int count = 0;
        if(inFile.is_open()){
            getline (inFile,line);
            while ( getline (inFile,line) )
            {
                count++;
            }
            inFile.close();
        }
        return count;
    }
private:
    vector<vector<Tile>> tileVector;
    int boardWidth;
    int boardHeight;
    bool gameWon;
    bool gameOver;
    int flagCount;
};