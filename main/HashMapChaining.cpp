#include <list>
#include <vector>

class HashMapChaining {
    int bucketCount;
    std::vector<std::list<std::pair<int, int>>> buckets;

    int hash(int key) {
        return key % bucketCount;
    }

public:
    HashMapChaining(int size) : bucketCount(size), buckets(size) {}
    
    void put(int key, int value) {
        int index = hash(key);
        for (auto it = buckets[index].begin(); it != buckets[index].end(); ++it) {
            if (it->first == key) {
                it->second = value;
                return;
            }
        }
        buckets[index].push_back({key, value});
    }
    
    int get(int key) {
        int index = hash(key);
        for (auto it = buckets[index].begin(); it != buckets[index].end(); ++it) {
            if (it->first == key) {
                return it->second;
            }
        }
        return -1;
    }

    void remove(int key) {
        int index = hash(key);
        for (auto it = buckets[index].begin(); it != buckets[index].end(); ++it) {
            if (it->first == key) {
                buckets[index].erase(it);
                return;
            }
        }
    }
};
