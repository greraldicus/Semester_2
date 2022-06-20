#include <iostream>
#include <string>
#include <vector>


class HashTable {
public:
    int size, fill;

    explicit HashTable(int n) : size(n), table(n, "0"), fill(0) {}

    bool Has(const std::string &key) const {
        unsigned long long hash = Hash(key);
        unsigned long long hash2 = Hash2(key);
        unsigned long long new_hash = 0;
        for (int i = 0; i < size; i++) {
            new_hash = DoubleHashing(key, i, hash, hash2);
            if (table[new_hash] == key) return true;
            if (table[new_hash] == "0") return false;
        }
        return false;
    }

    bool Add(const std::string &key) {
        if (size * 3 < fill * 4) {
            ReHash();
        }
        if (Has(key)) return false;
        unsigned long long hash = Hash(key);
        unsigned long long hash2 = Hash2(key);
        unsigned long long new_hash = 0;
        for (int i = 0; i < size; i++) {
            new_hash = DoubleHashing(key, i, hash, hash2);
            if (table[new_hash] == "del" || table[new_hash] == "0") {
                table[new_hash] = key;
                ++fill;
                return true;
            }
        }
    }

    bool Remove(const std::string &key) {
        if (!Has(key)) return false;
        unsigned long long hash = Hash(key);
        unsigned long long hash2 = Hash2(key);
        unsigned long long new_hash = 0;
        for (int i = 0; i < size; i++) {
            new_hash = DoubleHashing(key, i, hash, hash2);
            if (table[new_hash] == key) {
                table[new_hash] = "del";
                return true;
            }
        }
    }

    void ReHash() {
        HashTable new_table(size * 2);
        for (std::string &elem: table) {
            if (elem != "0" && elem != "del") {
                new_table.Add(elem);
            }
        }
        *this = std::move(new_table);
    }
    unsigned long long Hash(const std::string &key) const {
        const int p = 31;
        unsigned long long hash = 0;
        long long p_pow = 1;
        for (char letter: key) {
            hash += (letter - 'a' + 1) * p_pow;
            p_pow *= p;
        }
        return hash;
    }

    unsigned long long Hash2(const std::string &key) const {
        const int p = 37;
        unsigned long long hash2 = 0;
        long long p_pow = 1;
        for (char letter: key) {
            hash2 += (letter - 'a' + 1) * p_pow;
            p_pow *= p;
        }
        return (2*hash2+1) % table.size();
    }

    unsigned int DoubleHashing(const std::string &key, int iteration, unsigned long long hash,unsigned long long hash2) const{
        if (!key.empty()) {
            if (iteration == 0 || iteration == 1) {
                return hash % size;
            } else {
                return (hash + iteration * hash2) % size;
            }
        } else {
            return 0;
        }
    }

private:
    std::vector<std::string> table;
};

int main() {
    HashTable table(8);
    char command;
    std::string value;
    while (std::cin >> command >> value) {
        if (command == '+') {
            std::cout << (table.Add(value) ? "OK" : "FAIL") << std::endl;
        } else if (command == '?') {
            std::cout << (table.Has(value) ? "OK" : "FAIL") << std::endl;
        } else if (command == '-') {
            std::cout << (table.Remove(value) ? "OK" : "FAIL") << std::endl;
        }
    }
    return 0;
}