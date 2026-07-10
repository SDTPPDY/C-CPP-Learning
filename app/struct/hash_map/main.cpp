#include <iostream>
using namespace std;

template <typename KeyType, typename ValueType>
class HashNode {
  public:
    KeyType key;
    ValueType value;
    HashNode* next;

    HashNode(const KeyType& key, const ValueType& value) {
        this->key = key;
        this->value = value;
        this->next = NULL;
    }
};

template <typename KeyType, typename ValueType>
class HashMap {
  private:
    int size;
    HashNode<KeyType, ValueType>** table;

    int hash(const KeyType& key) const {
        int hash_key = key % size;
        if (hash_key < 0) {
            hash_key += size;
        }

        return hash_key;
    }

  public:
    HashMap(int size = 256) {
        this->size = size;
        this->table = new HashNode<KeyType, ValueType>*[size];

        for (int i = 0; i < size; ++i) {
            this->table[i] = NULL;
        }
    }

    ~HashMap() {
        for (int i = 0; i < size; ++i) {
            if (table[i]) {
                HashNode<KeyType, ValueType>* current = table[i];
                while (current) {
                    HashNode<KeyType, ValueType>* next = current->next;
                    delete current;
                    current = next;
                }

                table[i] = NULL;
            }
        }

        delete[] table;
        table = NULL;
    }

    void insert(const KeyType& key, const ValueType& value) {
        int index = hash(key);
        HashNode<KeyType, ValueType>* now = new HashNode<KeyType, ValueType>(key, value);

        if (!table[index]) {
            table[index] = now;
        }
        else {
            now->next = table[index]->next;
            table[index]->next = now;
        }
    }

    void remove(const KeyType& key) {
        int index = hash(key);
        if (table[index]) {
            if (table[index]->key == key) {
                HashNode<KeyType, ValueType>* next = table[index]->next;
                delete table[index];
                table[index] = next;
            }
            else {
                HashNode<KeyType, ValueType>* current = table[index];
                while (current->next && current->next->key != key) {
                    current = current->next;
                }

                if (current->next) {
                    HashNode<KeyType, ValueType>* temp = current->next;
                    current->next = current->next->next;
                    delete temp;
                }
            }
        }
    }

    pair<ValueType, bool> find(const KeyType& key) const {
        int index = hash(key);
        ValueType value = ValueType();
        if (table[index]) {
            if (table[index]->key == key) {
                value = table[index]->value;
                return {value, true};
            }
            else {
                HashNode<KeyType, ValueType>* current = table[index];

                while (current->next && current->next->key != key) {
                    current = current->next;
                }

                if (current->next) {
                    value = current->next->value;
                    return {value, true};
                }
                else {
                    return {value, true};
                }
            }
        }

        return {value, false};
    }
};

template <typename KeyType>
class HashCounter {
    int* counter;
    int counter_index;
    int counter_size;
    HashMap<keyType, int>* hash;

  public:
    HashCouter(int size = 256) {
        counter_size = size;
        counter_index = 0;
        couunter = new int[counter_size];
    }

    ~HashCounter() {
    }

    void reset() {
    }

    int add(const KeyType& key) {
    }

    int sub(const KeyType& key) {
    }

    int get(const KeyType& key) {
    }
};

int main() {
    HashMap<int, char> h(1000);

    h.insert(1, 's');
    h.insert(2, 'b');
    h.insert(234, 'd');
    h.insert(114514, 'n');

    auto it = h.find(114514);
    if (it.second) {
        cout << it.first << endl;
    }

    it = h.find(3);
    if (!it.second) {
        cout << it.second << endl;
    }
}