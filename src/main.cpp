#include <SFML/Graphics.hpp>
#include "SFML/Window.hpp"
#include <iostream>
#include <string>
#include "Board.h"

using namespace sf;
using namespace std;




int Play(RenderWindow &window,Board &gameBoard);

bool ClickedOnDebug(int x, int y);
bool ClickedOnTestOne(int x, int y);
bool ClickedOnTestTwo(int x, int y);
bool ClickedOnATile(int x, int y);
bool ClickedOnFace(int x, int y);


int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Minesweeper");
    bool wantsToPlay = true;
    int choice = 0;
    do {
        switch (choice){
            case 0:{
                Board gameBoard(25,16);
                choice  = Play(window,gameBoard);
                break;
            }
            case 1:{
                Board testOne(25,16,"../boards/testboard.brd");
                choice = Play(window,testOne);
                break;
            }
            case 2:{
                Board testOne(25,16,"../boards/testboard2.brd");
                choice = Play(window,testOne);
                break;
            }
            case 3:{
                wantsToPlay = false;
                break;
            }
        }

    } while(wantsToPlay);

    return 0;
}

bool ClickedOnATile(int x, int y) {
    if (x >= 0 && x <= 800) {
        if (y >= 0 && y <= 512) {
            return true;
        }
    }
    return false;
}

bool ClickedOnFace(int x, int y) {
    if (x >= 320 && x <= 384) {
        if (y >= 512 && y <= 576) {
            return true;
        }
    }
    return false;
}

bool ClickedOnDebug(int x, int y) {
    if (x >= 512 && x <= 576) {
        if (y >= 512 && y <= 576) {
            return true;
        }
    }
    return false;
}


bool ClickedOnTestOne(int x,int y){
    if (x >= (18*32) && x <= (18*32 + 64)) {
        if (y >= 512 && y <= 576) {
            return true;
        }
    }
    return false;
}
bool ClickedOnTestTwo(int x,int y){
    if (x >= (20*32) && x <= (20*32 + 64)) {
        if (y >= 512 && y <= 576) {
            return true;
        }
    }
    return false;
}
int Play(RenderWindow &window,Board &gameBoard) {
    vector<Sprite> spritesOneThroughEight;
    Texture number1T;
    number1T.loadFromFile("../images/number_1.png");
    Sprite number1(number1T);
    Texture number2T;
    number2T.loadFromFile("../images/number_2.png");
    Sprite number2(number2T);
    Texture number3T;
    number3T.loadFromFile("../images/number_3.png");
    Sprite number3(number3T);
    Texture number4T;
    number4T.loadFromFile("../images/number_4.png");
    Sprite number4(number4T);
    Texture number5T;
    number5T.loadFromFile("../images/number_5.png");
    Sprite number5(number5T);
    Texture number6T;
    number6T.loadFromFile("../images/number_6.png");
    Sprite number6(number6T);
    Texture number7T;
    number7T.loadFromFile("../images/number_7.png");
    Sprite number7(number7T);
    Texture number8T;
    number8T.loadFromFile("../images/number_8.png");
    Sprite number8(number8T);
    Texture tile_hidden;
    tile_hidden.loadFromFile("../images/tile_hidden.png");
    Sprite tileHidden(tile_hidden);
    Texture tile_revealed;
    tile_revealed.loadFromFile("../images/tile_revealed.png");
    Sprite tileRevealed(tile_revealed);
    Texture flagS;
    flagS.loadFromFile("../images/flag.png");
    Sprite flag(flagS);
    Texture mineT;
    mineT.loadFromFile("../images/mine.png");    //12 is mine
    Sprite mine(mineT);
    Texture happyText;
    happyText.loadFromFile("../images/face_happy.png");
    Sprite happy(happyText);
    Texture testo;
    testo.loadFromFile("../images/test_1.png");
    Sprite testOne(testo);
    Texture testTwoT;
    testTwoT.loadFromFile("../images/test_2.png");
    Sprite testTwo(testTwoT);
    Texture bug;
    bug.loadFromFile("../images/debug.png");
    Sprite debug(bug);
    Texture dig;
    dig.loadFromFile("../images/digits.png");
    Sprite digits(dig);
    Texture sd;
    sd.loadFromFile("../images/face_lose.png");
    Sprite sad(sd);
    Texture win;
    win.loadFromFile("../images/face_win.png");
    Sprite faceWin(win);

    spritesOneThroughEight.push_back(number1);
    spritesOneThroughEight.push_back(number2);
    spritesOneThroughEight.push_back(number3);
    spritesOneThroughEight.push_back(number4);
    spritesOneThroughEight.push_back(number5);
    spritesOneThroughEight.push_back(number6);
    spritesOneThroughEight.push_back(number7);
    spritesOneThroughEight.push_back(number8);

    int pixWidth = 32;
    bool showMines = false;
    while (window.isOpen()) {
        Vector2i pos = Mouse::getPosition(window);
        int x = pos.x / pixWidth;
        int y = pos.y / pixWidth;

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                return 3;
            }

            if (event.type == Event::MouseButtonPressed)
                if (ClickedOnATile(pos.x, pos.y) && !gameBoard.GetGameOver()) {
                    if (event.key.code == Mouse::Right) {
                        gameBoard.HandleRightClick(x, y);
                    } else if (event.key.code == Mouse::Left) {
                        gameBoard.HandleLeftClick(x, y);
                    }
                } else if (ClickedOnDebug(pos.x, pos.y)) {
                    if (event.key.code == Mouse::Left) {
                    if (!showMines) {
                        showMines = true;
                    } else {
                        showMines = false;
                    }
                    }
                }else if(ClickedOnTestOne(pos.x,pos.y)){
                    if(!gameBoard.GetGameOver()){
                        return 1;
                    }else{
                        break;
                    }
                }else if(ClickedOnTestTwo(pos.x,pos.y)){
                    if(!gameBoard.GetGameOver()){
                        return 2;
                    }else{
                        break;
                    }
                } else if (ClickedOnFace(pos.x, pos.y)) {
                    return 0;
                }
        }
        window.clear(Color::Magenta);
        //
        vector<vector<Tile>> tileVector = gameBoard.GetBoard();
        for (int i = 0; i <= 24; i++)
            for (int j = 0; j <= 15; j++) {

                if (!gameBoard.GetGameOver()) {
                    tileHidden.setPosition(i * pixWidth, j * pixWidth);
                    window.draw(tileHidden);
                    if (tileVector[i][j].GetRevealed()) {
                        tileRevealed.setPosition(i * pixWidth, j * pixWidth);
                        window.draw(tileRevealed);
                        if (tileVector[i][j].GetHasNumber()) {
                            int minesAround = tileVector[i][j].GetNumberOfMinesAround();
                            spritesOneThroughEight[minesAround - 1].setPosition(i * pixWidth, j * pixWidth);
                            window.draw(spritesOneThroughEight[minesAround - 1]);
                        }
                    }
                    if (tileVector[i][j].GetHasFlag()) {
                        flag.setPosition(i * pixWidth, j * pixWidth);
                        window.draw(flag);
                    }
                    if (showMines){
                            if(tileVector[i][j].GetHasMine()){
                                mine.setPosition(i * pixWidth, j * pixWidth);
                                window.draw(mine);
                            }
                        }

                }else if(gameBoard.GetGameWon()){
                    tileHidden.setPosition(i * pixWidth, j * pixWidth);
                    window.draw(tileHidden);
                    if (tileVector[i][j].GetRevealed()) {
                        tileRevealed.setPosition(i * pixWidth, j * pixWidth);
                        window.draw(tileRevealed);
                        if (tileVector[i][j].GetHasNumber()) {
                            int minesAround = tileVector[i][j].GetNumberOfMinesAround();
                            spritesOneThroughEight[minesAround - 1].setPosition(i * pixWidth, j * pixWidth);
                            window.draw(spritesOneThroughEight[minesAround - 1]);
                        }
                    }
                    if (tileVector[i][j].GetHasMine()) {
                        flag.setPosition(i * pixWidth, j * pixWidth);
                        window.draw(flag);
                    }
                }
                else {
                    tileHidden.setPosition(i * pixWidth, j * pixWidth);
                    window.draw(tileHidden);
                    if (tileVector[i][j].GetRevealed()) {
                        tileRevealed.setPosition(i * pixWidth, j * pixWidth);
                        window.draw(tileRevealed);
                        if (tileVector[i][j].GetHasNumber()) {
                            int minesAround = tileVector[i][j].GetNumberOfMinesAround();
                            spritesOneThroughEight[minesAround - 1].setPosition(i * pixWidth, j * pixWidth);
                            window.draw(spritesOneThroughEight[minesAround - 1]);
                        }
                    }
                    if (tileVector[i][j].GetHasFlag() && !tileVector[i][j].GetHasMine()) {
                        flag.setPosition(i * pixWidth, j * pixWidth);
                        window.draw(flag);
                    }
                    if (tileVector[i][j].GetHasMine()) {
                        mine.setPosition(i * pixWidth, j * pixWidth);
                        window.draw(mine);
                    }
                }
            }

        testOne.setPosition(18 * pixWidth, 16 * pixWidth);
        window.draw(testOne);
        testTwo.setPosition(20 * pixWidth, 16 * pixWidth);
        window.draw(testTwo);
        debug.setPosition(16 * pixWidth, 16 * pixWidth);
        window.draw(debug);
        if (!gameBoard.GetGameOver()) {
            happy.setPosition(10 * pixWidth, 16 * pixWidth);
            window.draw(happy);
        } else {
            if(gameBoard.GetGameWon()){
                faceWin.setPosition(10 * pixWidth, 16 * pixWidth);
                window.draw(faceWin);
            }else{
                sad.setPosition(10 * pixWidth, 16 * pixWidth);
                window.draw(sad);
            }
        }
        int flagCount = gameBoard.GetFlagCount();
        Sprite digit2(dig);
        digit2.setPosition(21, 16*pixWidth);
        digit2.setTextureRect(IntRect(21*((flagCount%10)), 0, 21*1, pixWidth));
        digits.setTextureRect(IntRect(21*((flagCount/10)), 0, 21*1, pixWidth));
        digits.setPosition(0, 16 * pixWidth);
        window.draw(digit2);
        window.draw(digits);
        window.display();
    }
}
