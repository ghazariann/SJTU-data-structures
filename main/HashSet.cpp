#include <list>
#include <vector>

class HashSet {
    int bucketCount;
    std::vector<std::list<int>> buckets;

    int hash(int key) {
        return key % bucketCount;
    }

public:
    HashSet(int size) : bucketCount(size), buckets(size) {}

    void add(int key) {
        int index = hash(key);
        for (auto it = buckets[index].begin(); it != buckets[index].end(); ++it) {
            if (*it == key) {
                return; // Key already exists, no action needed
            }
        }
        buckets[index].push_back(key);
    }

    bool contains(int key) {
        int index = hash(key);
        for (auto it = buckets[index].begin(); it != buckets[index].end(); ++it) {
            if (*it == key) {
                return true;
            }
        }
        return false;
    }

    void remove(int key) {
        int index = hash(key);
        for (auto it = buckets[index].begin(); it != buckets[index].end(); ++it) {
            if (*it == key) {
                buckets[index].erase(it);
                return;
            }
        }
    }
};
