#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> s;

    // =========================
    // 1. insert()
    // =========================

    s.insert(10);
    s.insert(20);
    s.insert(30);
    s.insert(40);

    // Duplicate element
    s.insert(20);


    // =========================
    // 2. emplace()
    // =========================

    s.emplace(50);


    // =========================
    // 3. Display set
    // =========================

    cout << "Set elements: ";

    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;


    // =========================
    // 4. count()
    // =========================

    cout << "Count of 20: "
         << s.count(20) << endl;


    // =========================
    // 5. find()
    // =========================

    auto it = s.find(30);

    if (it != s.end())
    {
        cout << "Element found: " << *it << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }


    // =========================
    // 6. lower_bound()
    // =========================

    auto lb = s.lower_bound(25);

    if (lb != s.end())
    {
        cout << "Lower bound of 25: " << *lb << endl;
    }
    else
    {
        cout << "Lower bound does not exist" << endl;
    }


    // =========================
    // 7. upper_bound()
    // =========================

    auto ub = s.upper_bound(30);

    if (ub != s.end())
    {
        cout << "Upper bound of 30: " << *ub << endl;
    }
    else
    {
        cout << "Upper bound does not exist" << endl;
    }


    // =========================
    // 8. erase()
    // =========================

    s.erase(20);

    cout << "After erasing 20: ";

    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    cout << endl;


    // =========================
    // 9. size()
    // =========================

    cout << "Set size: "
         << s.size() << endl;


    // =========================
    // 10. empty()
    // =========================

    cout << "Is set empty? "
         << s.empty() << endl;


    // =========================
    // 11. Erase all elements
    // =========================

    s.erase(s.begin(), s.end());

    cout << "Set size after erasing all: "
         << s.size() << endl;

    cout << "Is set empty now? "
         << s.empty() << endl;


    return 0;
}