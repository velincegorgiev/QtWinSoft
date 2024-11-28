// 2.Напиши програма за играње на едноставна игра со карти која ги има следните правила: шпилот од 52 карти се меша и 
// се делат картите на сите играчи подеднакво. Добива оној играч што има најголем збир. 
// а) Вредностите на картите се од 1 до 14 соодветно, без разлика на бојата, А има вредност 1.
// б) Вредностите на картите се од 1 до 14 соодветно, А има вредност 1. Картите срце се бројат двојно.
// На почетокот на играта да се внесе бројот на играчи. Во излезот да се прикажат картите и збирот што ги добил секој играч.

#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;
struct Card {
    int value;
    string suit;
};
Card createCard(int value, string suit) {
    Card card;
    card.value = value;
    card.suit = suit;
    return card;
}

int getCardValue(const Card& card) {
    if (card.suit == "srce") {
        return card.value * 2;
    }
    return card.value;
}

int main() {
    srand(time(0));
    int numPlayers;
    cout << "vnesi broj na igraci: ";
    cin >> numPlayers;
    vector<Card> deck;
    vector<string> suits = {"detelina", "baklava", "srce", "list"};
    for (int i = 1; i <= 14; i++) {
        for (const string& suit : suits) {
            deck.push_back(createCard(i, suit));
        }
    }
    random_shuffle(deck.begin(), deck.end());
    vector<vector<Card>> players(numPlayers); 
    int i = 0;
    while (!deck.empty()) {
        players[i % numPlayers].push_back(deck.back());
        deck.pop_back();
        i++;
    }
    vector<int> scores(numPlayers, 0);
    for (int j = 0; j < numPlayers; j++) {
        cout << "\nigrac " << j + 1 << " karti: ";
        for (const Card& card : players[j]) {
            cout << card.value << " " << card.suit << " | ";
            scores[j] += getCardValue(card);
        }
        cout << "\nzbir: " << scores[j] << endl;
    }
    int maxScore = *max_element(scores.begin(), scores.end());
    int winner = -1;
    for (int j = 0; j < numPlayers; j++) {
        if (scores[j] == maxScore) {
            winner = j;
            break;
        }
    }
    cout << "\npobednik: igrac " << winner + 1 << " so zbir: " << maxScore << endl;
    
    return 0;
}
