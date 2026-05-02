class LFUCache {
    int capacity;
    int minFreq;  // tracks current minimum frequency for O(1) eviction

    unordered_map<int, int> keyToVal;   // key → value
    unordered_map<int, int> keyToFreq;  // key → how many times accessed

    // freq → list of keys at that frequency
    // FRONT = most recently used, BACK = least recently used
    unordered_map<int, list<int>> freqToKeys;

    // key → iterator pointing to its position inside freqToKeys[freq]
    // needed so we can delete from the list in O(1)
    unordered_map<int, list<int>::iterator> keyToIter;

    // called every time a key is accessed (get or put on existing key)
    void updateFreq(int key) {
        int oldFreq = keyToFreq[key];
        int newFreq = oldFreq + 1;

        // step 1: remove key from its current frequency bucket
        freqToKeys[oldFreq].erase(keyToIter[key]);

        // step 2: if that bucket is now empty, clean it up
        // if it was also the minFreq bucket, increment minFreq
        if(freqToKeys[oldFreq].empty()) {
            freqToKeys.erase(oldFreq);
            if(minFreq == oldFreq) minFreq++;
        }

        // step 3: add key to new frequency bucket at FRONT (most recent)
        keyToFreq[key] = newFreq;
        freqToKeys[newFreq].push_front(key);

        // step 4: update iterator so we know where this key sits in the list
        keyToIter[key] = freqToKeys[newFreq].begin();
    }

public:
    LFUCache(int cap) {
        capacity = cap;
        minFreq = 0;
    }

    int get(int key) {
        // key doesn't exist
        if(keyToVal.find(key) == keyToVal.end()) return -1;

        // key exists → increase its frequency, return value
        updateFreq(key);
        return keyToVal[key];
    }

    void put(int key, int value) {
        if(capacity == 0) return;  // edge case

        if(keyToVal.find(key) != keyToVal.end()) {
            // key already exists → just update value and frequency
            keyToVal[key] = value;
            updateFreq(key);
        } else {
            // new key
            if((int)keyToVal.size() == capacity) {
                // cache full → evict LFU key
                // minFreq bucket's BACK = least recently used among least frequent
                int evict = freqToKeys[minFreq].back();
                freqToKeys[minFreq].pop_back();

                // clean up empty bucket
                if(freqToKeys[minFreq].empty()) freqToKeys.erase(minFreq);

                // remove evicted key from all maps
                keyToVal.erase(evict);
                keyToFreq.erase(evict);
                keyToIter.erase(evict);
            }

            // insert new key with frequency 1
            keyToVal[key] = value;
            keyToFreq[key] = 1;
            freqToKeys[1].push_front(key);         // most recent in freq=1 bucket
            keyToIter[key] = freqToKeys[1].begin(); // store iterator
            minFreq = 1;  // new key always has freq=1, so minFreq resets to 1
        }
    }
};