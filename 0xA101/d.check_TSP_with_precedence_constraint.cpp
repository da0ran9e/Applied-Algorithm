#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int N = 1000;

// structure to store the coordinates of a city
struct City
{
int x, y;
};

// function to calculate the distance between two cities
double distance(City a, City b)
{
return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
// array to store the cities
City cities[N];
int n;
cin >> n;
for (int i = 0; i < n; i++)
{
    cin >> cities[i].x >> cities[i].y;
}

// vector to store the sequence of cities
vector<int> seq;
int x;
while (cin >> x)
{
    seq.push_back(x - 1);
}

// check if the sequence is feasible
bool feasible = true;
for (int i = 1; i < seq.size(); i++)
{
    int curr = seq[i];
    int prev = seq[i - 1];
    if (prev >= curr)
    {
        feasible = false;
        break;
    }
}

if (!feasible)
{
    cout << "-1" << endl;
}
else
{
    double total_distance = 0;
    for (int i = 1; i < seq.size(); i++)
    {
        int curr = seq[i];
        int prev = seq[i - 1];
        total_distance += distance(cities[prev], cities[curr]);
    }

    cout << total_distance << endl;
}

return 0;
}