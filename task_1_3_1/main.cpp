#include <iostream>
#include <vector>

int MinDaysCounter(int n,std::vector<int>& incubation_days)
{
    for (int i = 2; i < n+1; i++)
    {
        incubation_days[i] = incubation_days[i-1] + 1;
        if (i % 5 == 0)
        {
            incubation_days[i] = std::min(incubation_days[i],incubation_days[i / 5]+1);
        }
        if (i % 4 == 0)
        {
            incubation_days[i] = std::min(incubation_days[i],incubation_days[i / 4]+1);
        }
    }
    return incubation_days[n];
}


int main() {
    int n;
    std::cin >> n;
    std::vector<int> incubation_days(n+1);
    std::cout << MinDaysCounter(n,incubation_days) << std::endl;
    return 0;
}