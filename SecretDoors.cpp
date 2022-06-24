#include<iostream>
#include<ctime>
using namespace std;

void PrintIntroduction(int LevelDifficulty) {
    cout<<"\n\nYou are a secret agent breaking  into a level "<<LevelDifficulty;
    cout<<" secure server room . . .\nEnter the correct code to continue . . ."<<'\n';
}

bool PlayGame(int LevelDifficulty) {
    PrintIntroduction(LevelDifficulty);
    const int CodeA=rand() % LevelDifficulty + LevelDifficulty + LevelDifficulty;
    const int CodeB=rand() % LevelDifficulty + LevelDifficulty + LevelDifficulty;
    const int CodeC=rand() % LevelDifficulty + LevelDifficulty + LevelDifficulty;

    const int CodeSum=CodeA+CodeB+CodeC;
    const int CodeProduct = CodeA*CodeB*CodeC;

    cout<<"+ There are 3 numbers in the code"<<'\n';
    cout<<"+ The code add-up to: "<<CodeSum<<'\n';
    cout<<"+ The codes multiply to give: "<<CodeProduct<<'\n';

    int GuessA, GuessB, GuessC;
    cin>>GuessA>>GuessB>>GuessC;

    int GuessSum=GuessA+GuessB+GuessC;
    int GuessProduct=GuessA*GuessB*GuessC;

    if(CodeSum==GuessSum && CodeProduct==GuessProduct){
        cout<<"\n*** Well done agent! You have extracted a file! Keep going! ***"<<'\n';
        return true;
    } else {
        cout<<"\n*** You have entered the wrong code! Careful agent! Try again! ***"<<'\n';
        return false;
    }
}

int main() {
    srand(time(NULL));
    int LevelDifficulty=1;
    int MaxDifficulty=10;
    while(LevelDifficulty<=MaxDifficulty){
        bool LevelComplete=PlayGame(LevelDifficulty);
        cin.clear();
        cin.ignore();
        if(LevelComplete) ++LevelDifficulty; 
    }
    cout<<"\n*** Great work Agent! You got all the files! Now get out of there! ***\n";
}