#ifndef LOOKUPTABLE_H
#define LOOKUPTABLE_H

#include <cassert>
#include <iostream>

// A Pair stores one key and its associated value (datum).
template <class K, class V>
struct Pair {
    Pair(const K& keyA, const V& datumA) : key(keyA), datum(datumA) {}
    K key;
    V datum;
};

template <class K, class V> class LookupTable;

template <class K, class V>
std::ostream& operator<<(std::ostream& os, const LookupTable<K,V>& lt);

template <class K, class V>
class LT_Node {
    friend class LookupTable<K,V>;
private:
    Pair<K,V> pairM;
    LT_Node* nextM;
    LT_Node(const Pair<K,V>& pairA, LT_Node* nextA)
        : pairM(pairA), nextM(nextA) {}
};

template <class K, class V>
class LookupTable {
public:
    class Iterator {
        friend class LookupTable<K,V>;
    private:
        LookupTable<K,V>* tableM;
        explicit Iterator(LookupTable<K,V>* tableA) : tableM(tableA) {}
    public:
        Iterator() : tableM(nullptr) {}
        const V& operator*() const {
            assert(tableM != nullptr && tableM->cursor_ok());
            return tableM->cursor_datum();
        }
        // Return the current datum, then advance.
        const V& operator++() {
            assert(tableM != nullptr && tableM->cursor_ok());
            const V& current = tableM->cursor_datum();
            tableM->step_fwd();
            return current;
        }
        const V& operator++(int) { return ++(*this); }
        // The lab's supplied code uses while (!it) while valid.
        int operator!() const {
            return tableM != nullptr && tableM->cursor_ok();
        }
        void step_fwd() {
            assert(tableM != nullptr && tableM->cursor_ok());
            tableM->step_fwd();
        }
    };

    LookupTable() : sizeM(0), headM(nullptr), cursorM(nullptr) {}

    LookupTable(const LookupTable& source)
        : sizeM(0), headM(nullptr), cursorM(nullptr) {
        copy(source);
    }

    LookupTable& operator=(const LookupTable& rhs) {
        if (this != &rhs) {
            destroy();
            copy(rhs);
        }
        return *this;
    }

    ~LookupTable() { destroy(); }

    Iterator begin() {
        go_to_first();
        return Iterator(this);
    }

    int size() const { return sizeM; }
    int cursor_ok() const { return cursorM != nullptr; }

    const K& cursor_key() const {
        assert(cursor_ok());
        return cursorM->pairM.key;
    }

    const V& cursor_datum() const {
        assert(cursor_ok());
        return cursorM->pairM.datum;
    }

    void insert(const Pair<K,V>& pairA) {
        LT_Node<K,V>* previous = nullptr;
        LT_Node<K,V>* current = headM;

        while (current != nullptr && current->pairM.key < pairA.key) {
            previous = current;
            current = current->nextM;
        }

        if (current != nullptr && !(pairA.key < current->pairM.key)
                                && !(current->pairM.key < pairA.key)) {
            current->pairM.datum = pairA.datum; // Replace existing value.
        } else {
            LT_Node<K,V>* added = new LT_Node<K,V>(pairA, current);
            if (previous == nullptr) headM = added;
            else previous->nextM = added;
            ++sizeM;
        }
        cursorM = nullptr;
    }

    void remove(const K& keyA) {
        LT_Node<K,V>* previous = nullptr;
        LT_Node<K,V>* current = headM;

        while (current != nullptr && current->pairM.key < keyA) {
            previous = current;
            current = current->nextM;
        }

        if (current != nullptr && !(keyA < current->pairM.key)
                                && !(current->pairM.key < keyA)) {
            if (previous == nullptr) headM = current->nextM;
            else previous->nextM = current->nextM;
            if (cursorM == current) cursorM = nullptr;
            delete current;
            --sizeM;
        }
        cursorM = nullptr;
    }

    void find(const K& keyA) {
        LT_Node<K,V>* current = headM;
        while (current != nullptr && current->pairM.key < keyA)
            current = current->nextM;
        if (current != nullptr && !(keyA < current->pairM.key)
                                && !(current->pairM.key < keyA))
            cursorM = current;
        else
            cursorM = nullptr;
    }

    void go_to_first() { cursorM = headM; }

    void step_fwd() {
        assert(cursor_ok());
        cursorM = cursorM->nextM;
    }

    void make_empty() { destroy(); }

    friend std::ostream& operator<< <K,V>(std::ostream& os,
                                           const LookupTable<K,V>& lt);

private:
    int sizeM;
    LT_Node<K,V>* headM;
    LT_Node<K,V>* cursorM;

    void destroy() {
        while (headM != nullptr) {
            LT_Node<K,V>* doomed = headM;
            headM = headM->nextM;
            delete doomed;
        }
        sizeM = 0;
        cursorM = nullptr;
    }

    void copy(const LookupTable& source) {
        for (LT_Node<K,V>* p = source.headM; p != nullptr; p = p->nextM)
            insert(Pair<K,V>(p->pairM.key, p->pairM.datum));

        if (source.cursorM != nullptr)
            find(source.cursorM->pairM.key);
        else
            cursorM = nullptr;
    }
};

template <class K, class V>
std::ostream& operator<<(std::ostream& os, const LookupTable<K,V>& lt) {
    if (lt.cursor_ok())
        os << lt.cursor_key() << "  " << lt.cursor_datum();
    else
        os << "Not Found.";
    return os;
}

#endif
