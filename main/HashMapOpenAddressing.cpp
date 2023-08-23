#include <vector>

class HashMapOpenAddressing
{
    int bucketCount;
    std::vector<std::pair<int, int>> buckets;
    std::vector<bool> occupied;

    int hash(int key)
    {
        return key % bucketCount;
    }

public:
    HashMapOpenAddressing(int size) : bucketCount(size),
                                      buckets(size, {0, 0}),
                                      occupied(size, false) {}

    void put(int key, int value)
    {
        int index = hash(key);
        while (occupied[index] && buckets[index].first != key)
        {
            //                       even if occupied but same key => overwrite
            index = (index + 1) % bucketCount; // Linear probing
        }
        buckets[index] = {key, value};
        occupied[index] = true;
    }

    int get(int key)
    {
        int index = hash(key);
        while (occupied[index])
        {
            if (buckets[index].first == key)
            {
                return buckets[index].second;
            }
            index = (index + 1) % bucketCount; // Linear probing
        }
        return -1;
    }

    void remove(int key)
    {
        int index = hash(key);
        while (occupied[index])
        {
            if (buckets[index].first == key)
            {
                occupied[index] = false;
                return;
            }
            index = (index + 1) % bucketCount; // Linear probing
        }
    }
};
