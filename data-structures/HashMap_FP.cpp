#include <iostream>
#include <stdexcept>
#include <string>

static const int TABLE_SIZE = 1000;
using namespace std;

template <typename K, typename V>
class HashNode {
   public:
    HashNode(const K& key, const V& value) : key(key), value(value), next(nullptr) {}

    K key;
    V value;
    HashNode* next;
};

template <typename K, typename V>
class HashMap {
   public:
    HashMap(unsigned long (*hashFunc)(const K& k)) : hashFunc(hashFunc) {}
    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            for (HashNode<K, V>* cur = table[0]; cur != nullptr;) {
                auto prev = cur;
                cur = cur->next;
                delete prev;
            }
        }
    }
    void put(const K& key, const V& value) {
        auto idx = hashFunc(key) % TABLE_SIZE;
        if (table[idx] == nullptr) {
            HashNode<K, V>* newNode = new HashNode<K, V>(key, value);
            table[idx] = newNode;
            return;
        }
        HashNode<K, V>* cur;
        for (cur = table[idx]; cur->next != nullptr && cur->value != value; cur = cur->next) {
        }
        if (cur != nullptr && cur->value == value) {
            cur->value = value;
            return;
        }
        cur->next = new HashNode<K, V>(key, value);
    }

    V get(const K& key) {
        auto idx = hashFunc(key) % TABLE_SIZE;
        for (HashNode<K, V>* cur = table[idx]; cur != nullptr; cur = cur->next) {
            if (cur->key == key) {
                return cur->value;
            }
        }
        throw std::invalid_argument("key does not exist");
    }

    // void remove(const K& key) {
    // }

   private:
    HashNode<K, V>* table[TABLE_SIZE] = {};
    unsigned long (*hashFunc)(const K& k);
};

struct MyKeyHash {
    unsigned long operator()(const int& k) const {
        return k % 10;
    }
};

unsigned long fun1(int key) {
    return key % 10;
}

int main(void) {
    auto fun = [](const int& key) -> unsigned long { return key % 10; };
    HashMap<int, std::string> hmap(fun);
    hmap.put(1, "val1");
    cout << hmap.get(1) << "\n";
    hmap.put(2, "val2");
    cout << hmap.get(2) << "\n";
    return 0;
}