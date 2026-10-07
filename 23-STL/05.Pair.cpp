#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // =========================
    // 1. Normal initialization of pair
    // =========================

    pair<int, int> p = {10, 20};

    cout << "First element: " << p.first << endl;
    cout << "Second element: " << p.second << endl;


    // =========================
    // 2. Pair containing a pair
    // =========================

    pair<int, pair<int, int>> p2 = {1, {2, 3}};

    cout << "\nPair of pair:" << endl;

    cout << "First element: " << p2.first << endl;

    cout << "Second pair first element: " << p2.second.first << endl;

    cout << "Second pair second element: " << p2.second.second << endl;


    // =========================
    // 3. Vector of pairs
    // =========================

    vector<pair<int, int>> v;

    // Using push_back()
    v.push_back({10, 20});
    v.push_back({30, 40});

    // Using emplace_back()
    v.emplace_back(50, 60);
    v.emplace_back(70, 80);


    // =========================
    // 4. Access vector of pairs
    // =========================

    cout << "\nVector of pairs:" << endl;

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }


    // Access using index
    cout << "\nUsing index:" << endl;

    cout << v[0].first << " " << v[0].second << endl;
    cout << v[1].first << " " << v[1].second << endl;


    return 0;
}