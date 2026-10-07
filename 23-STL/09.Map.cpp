// #include <iostream>
// #include <map>
// using namespace std;

// int main()
// {
//     map<int, string> m;

//     // =========================
//     // 1. insert()
//     // =========================

//     m.insert({1, "Apple"});
//     m.insert({2, "Banana"});
//     m.insert({3, "Mango"});


//     // =========================
//     // 2. emplace()
//     // =========================

//     m.emplace(4, "Orange");


//     // =========================
//     // 3. Display map
//     // =========================

//     cout << "Map elements:" << endl;

//     for (auto it = m.begin(); it != m.end(); it++)
//     {
//         cout << it->first << " -> " << it->second << endl;
//     }


//     // =========================
//     // 4. count()
//     // =========================

//     cout << "\nCount of key 2: " << m.count(2) << endl;


//     // =========================
//     // 5. find()
//     // =========================

//     auto it = m.find(3);

//     if (it != m.end())
//     {
//         cout << "Key found: "
//              << it->first << " -> "
//              << it->second << endl;
//     }
//     else
//     {
//         cout << "Key not found" << endl;
//     }


//     // =========================
//     // 6. erase()
//     // =========================

//     m.erase(2);

//     cout << "\nAfter erasing key 2:" << endl;

//     for (auto it = m.begin(); it != m.end(); it++)
//     {
//         cout << it->first << " -> " << it->second << endl;
//     }


//     // =========================
//     // 7. size()
//     // =========================

//     cout << "\nMap size: " << m.size() << endl;


//     // =========================
//     // 8. empty()
//     // =========================

//     cout << "Is map empty? " << m.empty() << endl;


//     // =========================
//     // 9. Erase all elements
//     // =========================

//     m.erase(m.begin(), m.end());

//     cout << "Map size after erasing all: "
//          << m.size() << endl;

//     cout << "Is map empty now? "
//          << m.empty() << endl;

//     return 0;
// }


// //Multi Map.......................................................................
// #include <iostream>
// #include <map>
// using namespace std;

// int main()
// {
//     multimap<int, string> mm;

//     // insert()
//     mm.insert({1, "Apple"});
//     mm.insert({2, "Banana"});
//     mm.insert({2, "Mango"});
//     mm.insert({3, "Orange"});

//     // emplace()
//     mm.emplace(2, "Grapes");

//     // Display
//     cout << "Multimap:" << endl;

//     for (auto it = mm.begin(); it != mm.end(); it++)
//     {
//         cout << it->first << " -> " << it->second << endl;
//     }

//     // count()
//     cout << "\nCount of key 2: "
//          << mm.count(2) << endl;

//     // find()
//     auto it = mm.find(2);

//     if (it != mm.end())
//     {
//         cout << "Found: "
//              << it->first << " -> "
//              << it->second << endl;
//     }

//     // erase one element using iterator
//     if (it != mm.end())
//         mm.erase(it);

//     // size()
//     cout << "\nSize: " << mm.size() << endl;

//     // empty()
//     cout << "Is empty: " << mm.empty() << endl;

//     return 0;
// }

// //Unordered Map.....................................................................
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<int, string> um;

    // insert()
    um.insert({1, "Apple"});
    um.insert({2, "Banana"});
    um.insert({3, "Mango"});

    // emplace()
    um.emplace(4, "Orange");

    // Display
    cout << "Unordered Map:" << endl;

    for (auto it = um.begin(); it != um.end(); it++)
    {
        cout << it->first << " -> " << it->second << endl;
    }

    // count()
    cout << "\nCount of key 2: "
         << um.count(2) << endl;

    // find()
    auto it = um.find(3);

    if (it != um.end())
    {
        cout << "Found: "
             << it->first << " -> "
             << it->second << endl;
    }

    // erase()
    um.erase(2);

    // size()
    cout << "\nSize: " << um.size() << endl;

    // empty()
    cout << "Is empty: " << um.empty() << endl;

    return 0;
}