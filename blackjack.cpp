#include <iostream>
#include <ctime>

void Shuffle(bool baCardsDealt[]);
void PrintCard (int iCard);
void PrintHand (int iaHand[], const int kiCardCount);
int GetNextCard(bool baCardsDealt[]);
int ScoreHand(int iaHand[], const int kiCardCount);
void PrintScoresAndHands (int iaHouseHand[], const int kiHouseCardCount, int isPlayerHand[], const int kiPlayerCardCount);

using namespace std;

int main(){

    time_t qTime;
    time(&qTime);
    srand(qTime);

    bool baCardsDealt[52];
    int iHouseCardCount = 0;
    int iaHouseHand[12];
    int iPlayerCardCount = 0;
    int iaPlayerHand[12];

    while (true){
        Shuffle(baCardsDealt);
        iaPlayerHand[0] = GetNextCard(baCardsDealt);
        iaHouseHand[0] = GetNextCard(baCardsDealt);
        iaPlayerHand[1] = GetNextCard(baCardsDealt);
        iaHouseHand[1] = GetNextCard(baCardsDealt);
        iHouseCardCount = 2;
        iPlayerCardCount = 2;

        cout << "New Hand " << endl; 
        char cPlayerChoice;
        bool bPlayerHits = true;
        int iPlayerScore = ScoreHand(iaPlayerHand, iPlayerCardCount);
        do {
            cout << "Dealer Hand" << endl;
            cout << "**" << endl;
            PrintCard(iaHouseHand[1]);
            cout << endl;
            cout << "Player Hand: Score = " << ScoreHand(iaPlayerHand, iPlayerCardCount) << endl;
            PrintHand (iaPlayerHand, iPlayerCardCount);

            cout << "hit(h) or stay(s): ";
            cin >> cPlayerChoice;
            if (cPlayerChoice == 'h'){
                iaPlayerHand[iPlayerCardCount] = GetNextCard(baCardsDealt);
                ++iPlayerCardCount;
            }
            else if (cPlayerChoice == 's'){
                bPlayerHits = false;
            }
            else (
                cout << "Error: Try Again" << endl;
            )
            cout << endl;
            iPlayerScore = ScoreHand(iaPlayerHand, iPlayerCardCount);
        }while (bPlayerHits && iPlayerScore < 22);
        
        if (iPlayerScore > 21 ){
            cout << "Dealer Wins" << endl; 
            PrintScoresAndHands(iaHouseHand, iHouseCardCount, iaPlayerHand, iPlayerCardCount);
        }
        else {
            int iHouseScore = ScoreHand(iaHouseHand, iHouseCardCount);
            while (iHouseScore < 17 ){
                iaHouseHand(iHouseCardCount) = GetNextCard(baCardsDealt);
                ++iHouseCardCount;
                iHouseScore = ScoreHand(iaHouseHand,iHouseCardCount);
            }
            bool bHoustBusts = (iHouseScore > 21);
            if (bHoustBusts){
                cout << "You Win " << endl;
                PrintScoresAndHands(iaHouseHand, iHouseCardCount, iaPlayerHand, iPlayerCardCount);
            }
            else {
                if (iPlayerScore == iHouseScore){
                    cout << "Push" << endl;
                    PrintScoresAndHands(iaHouseHand, iHouseCardCount, iaPlayerHand, iPlayerCardCount);
                }
                else (iPlayerScore > iHouseScore){
                    cout << "You Win" << endl;
                    PrintScoresAndHands(iaHouseHand, iHouseCardCount, iaPlayerHand, iPlayerCardCount);
                }
                else {
                    cout << "Dealer Wins" << endl;
                    PrintScoresAndHands(iaHouseHand, iHouseCardCount, iaPlayerHand, iPlayerCardCount);
                }
            }
        }
    }
    return EXIT_SUCCESS;
}
void Shuffle(bool baCardsDealt[]){
    cout << " " << endl;
}
void PrintCard(int iCard){
    cout << " " << endl;
}
void PrintHand (int iaHand[], const int kiCardCount){
    cout << " " << endl;
}
int GetNextCard(bool baCardsDealt[]){
    return 0;
}
int ScoreHand(int iaHand[], const int kiCardCount){
    return 0;
}
