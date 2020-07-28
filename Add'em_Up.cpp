#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int N;
    std::cin >> N; std::cin.ignore();
    std::vector<int> cards(N);

    int cost = 0;

    for (int i = 0; i < N; i++) 
    {
        int x;
        std::cin >> x; std::cin.ignore();
        cards[i] = x;
    }
    std::sort(cards.begin(), cards.end());

    while (cards.size() > 1)
    {
        int new_card = cards[0] + cards[1];
        cost += new_card;
        cards[1] = new_card;
        cards.erase(cards.begin());
        std::sort(cards.begin(), cards.end());
    }

    std::cout << cost << std::endl;
}
