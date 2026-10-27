// ENSF 614 - Lab 3, Exercise C
#include <cassert>
#include <cstring>
#include <iostream>
#include "lookupTable.h"
#include "customer.h"
#include "mystring2.h"

using namespace std;

template <class K, class V>
void print(LookupTable<K,V>& lt) {
    if (lt.size() == 0) {
        cout << "  Table is EMPTY.\n";
        return;
    }
    for (lt.go_to_first(); lt.cursor_ok(); lt.step_fwd())
        cout << lt << endl;
}

template <class K, class V>
void try_to_find(LookupTable<K,V>& lt, const K& key) {
    lt.find(key);
    if (lt.cursor_ok())
        cout << "\nFound key: " << lt << endl;
    else
        cout << "\nCouldn't find key: " << key << " in the table.\n";
}

void test_Customer() {
    cout << "\nCreating and testing LookupTable<int, Customer>...\n";
    LookupTable<int, Customer> lt;

    Customer a("John", "Michael", "11 St. Calgary.", "(587)-1111-123456");
    Customer b("Maya", "Thomas", "12 St. Calgary.", "(587)-1111-123567");
    Customer c("Jerry", "Tom", "13 St. Calgary.", "(587)-1111-123789");

    lt.insert(Pair<int, Customer>(8002, a));
    lt.insert(Pair<int, Customer>(8004, c));
    lt.insert(Pair<int, Customer>(8001, b));
    assert(lt.size() == 3);
    lt.remove(8004);
    assert(lt.size() == 2);

    cout << "\nPrinting table after inserting 3 keys and removing 1...\n";
    print(lt);
    cout << "\nLooking up keys...\n";
    try_to_find(lt, 8001);
    try_to_find(lt, 8000);

    cout << "\nTesting iterator...\n";
    LookupTable<int, Customer>::Iterator it = lt.begin();
    if (!it) cout << "First datum: " << *it << endl;
    while (!it) cout << ++it << endl;

    lt.go_to_first();
    lt.step_fwd();
    LookupTable<int, Customer> clt(lt);
    assert(strcmp(clt.cursor_datum().getFname(), "John") == 0);
    cout << "\nTesting copy constructor (keys should be 8001 and 8002)...\n";
    print(clt);

    lt.remove(8002);
    clt = lt;
    cout << "\nTesting assignment operator (key should be 8001)...\n";
    print(clt);

    lt.make_empty();
    cout << "\nPrinting empty table...\n";
    print(lt);
}

void test_String() {
    cout << "\nCreating and testing LookupTable<int, Mystring>...\n";
    LookupTable<int, Mystring> lt;

    Mystring a("We are ENSF-614 students.");
    Mystring b("C++ is a powerful language for engineers but it's not easy.");
    Mystring c("Fall 2026");

    lt.insert(Pair<int, Mystring>(8002, a));
    lt.insert(Pair<int, Mystring>(8001, b));
    lt.insert(Pair<int, Mystring>(8004, c));
    assert(lt.size() == 3);
    lt.remove(8004);
    assert(lt.size() == 2);

    cout << "\nPrinting table...\n";
    print(lt);
    try_to_find(lt, 8001);
    try_to_find(lt, 8000);

    LookupTable<int, Mystring>::Iterator it = lt.begin();
    if (!it) cout << "\nFirst datum: " << *it << endl;
    while (!it) cout << ++it << endl;

    lt.go_to_first();
    lt.step_fwd();
    LookupTable<int, Mystring> clt(lt);
    assert(strcmp(clt.cursor_datum().c_str(), "We are ENSF-614 students.") == 0);
    cout << "\nTesting copy constructor...\n";
    print(clt);

    lt.remove(8002);
    clt = lt;
    cout << "\nTesting assignment operator...\n";
    print(clt);
    lt.make_empty();
    cout << "\nPrinting empty table...\n";
    print(lt);
}

void test_integer() {
    cout << "\nCreating and testing LookupTable<int, int>...\n";
    LookupTable<int, int> lt;

    lt.insert(Pair<int, int>(8002, 9999));
    lt.insert(Pair<int, int>(8001, 8888));
    lt.insert(Pair<int, int>(8004, 7777));
    assert(lt.size() == 3);
    lt.remove(8004);
    assert(lt.size() == 2);

    cout << "\nPrinting table...\n";
    print(lt);
    try_to_find(lt, 8001);
    try_to_find(lt, 8000);

    LookupTable<int, int>::Iterator it = lt.begin();
    while (!it) cout << ++it << endl;

    lt.go_to_first();
    lt.step_fwd();
    LookupTable<int, int> clt(lt);
    assert(clt.cursor_datum() == 9999);
    cout << "\nTesting copy constructor...\n";
    print(clt);

    lt.remove(8002);
    clt = lt;
    cout << "\nTesting assignment operator...\n";
    print(clt);
    lt.make_empty();
    cout << "\nPrinting empty table...\n";
    print(lt);
}

int main() {
    test_Customer();
    test_String();
    test_integer();
    cout << "\n\nProgram terminated successfully.\n";
    return 0;
}
