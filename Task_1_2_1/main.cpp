//https://contest.yandex.ru/contest/35212/run-report/66291992/

#include <iostream>
#include <algorithm>
#include <vector>

int MaxHeightOfTower(std::vector<std::pair<int, int>>& athletes)
{
    std::sort(athletes.begin(), athletes.end());
    int height = 0;
    int cumulative_weight = 0;
    for (const auto& athlete : athletes) {
        const int weight = athlete.first;
        const int strength = athlete.second;
        if (strength >= cumulative_weight) {
            height++;
            cumulative_weight += weight;
        }
    }
    return height;
}

int main()
{
    std::vector<std::pair<int, int>> athletes;
    int weight, strenght;
    while (std::cin >> weight >> strenght) {
        athletes.push_back({ weight, strenght });
        if (!std::cin)
            break;
    }

    std::cout << MaxHeightOfTower(athletes);
    return 0;
}