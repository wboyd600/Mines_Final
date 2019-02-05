#include <vector>
class Tile{
public:
    Tile(){
        this->beenClicked= false;
        this->hasMine = false;
        this->flag = false;
        this->revealed = false;
        this->hasNumber = false;
    }
    bool GetHasMine(){
        return hasMine;
    }
    bool GetHasFlag(){
        return flag;
    }
    bool GetBeenClicked(){
        return beenClicked;
    }
    void SetHasMine(bool mine){
        this->hasMine = mine;
    }
    void SetFlag(bool flag){
        this->flag= flag;
    }
    void SetBeenClicked(bool clicked){
        this->beenClicked= clicked;
    }
    void SetTilesAround(std::vector<Tile *> tilesRound){
        this->tilesAround = tilesRound;
    }
    std::vector<Tile *> GetTilesAround(){
        return tilesAround;
    }
    int GetNumberOfMinesAround(){
        int number = 0;
        for (int i = 0; i < tilesAround.size(); ++i) {
            if(tilesAround[i]->GetHasMine()){
                ++number;
            }
        }
        return number;
    }
    void SetHasNumber(bool number){
        this->hasNumber = number;
    }
    bool GetHasNumber(){
        return hasNumber;
    }

    bool SetRevealed(bool rev){
        this->revealed = rev;
    }
    bool GetRevealed(){
        return revealed;
    }
private:
    bool hasNumber;
    bool hasMine;
    bool beenClicked;
    bool flag;
    bool revealed;
    std::vector<Tile *> tilesAround;
};