/*
LFU CACHE visual structure:
    keyToNode : {1 -> Node*, 2 -> Node*, 3 -> Node*}
    freqToList: 
        freq = 1 -> HEAD <-> [key3] <-> TAIL
        freq = 2 -> HEAD <-> [key1] <-> [key2] <-> TAIL
                            ^most recent ^least recent(evict this)
    minFreq = 1 -> always know which bucket to evict from

*/

//Node
// one cache entry, lives inside a FreqList

struct Node{
    int key, value, freq;
    Node* next;
    Node* prev;

    Node(int k, int v){
        key = k;
        value = v;
        freq = 1;  //every new node starts at freq 1
        next = prev = nullptr;
    }
};

//FreqList
/*
DLL of nodes that ALL have the same freq
FRONT = most recently used, BACK = LRU(evict from here)
*/

struct FreqList{
    int size;
    Node* head; //dummy
    Node* tail;
    
    FreqList(){
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head -> next = tail;
        tail -> prev = head;
        size = 0;
    }
    //insert node right after HEAD -> marks it as most recently used
    //before: HEAD <-> [A] <-> TAIL
    //after: HEAD <-> [node] <-> TAIL

    void addFront(Node* node){
        Node* firstNode = head -> next; //save current first real node
        node -> next = firstNode;       // node -> old first
        node -> prev = head;            // head <- node
        head -> next = node;            //head -> node
        firstNode -> prev = node;       // node <- old first
        size++;
    }

    //rewire neighbours to skip over this node(doesn't delete from memory)
    //before : [A] <-> [node] <-> [B]
    // after : [A] <-> [B]

    void removeNode(Node* node){
        Node* prevNode = node -> prev;
        Node* nextNode = node -> next;
        prevNode -> next = nextNode; // A skips node, points to B
        nextNode -> prev = prevNode; // B skips node, points back to A
        size--;
    }
};

class LFUCache {
public:
    unordered_map<int, Node*> keyToNode; //key -> node pointer (O(1) lookup)
    unordered_map<int, FreqList*> freqToList; //freq -> list of all nodes at that freq

    int cap;
    int minFreq;
    int curSize;

    //increment freq
    //called on every get/put of an EXISTING key
    //moves node from freqToList[f] to freqToList[f + 1]

    void incrementFreq(Node* node){
        //1. remove node from keyToNode temporarily
        keyToNode.erase(node -> key);

        //2. remove node from its current freq bucket
        freqToList[node -> freq] -> removeNode(node);

        //3. if that bucket is now empty AND it was the minFreq bucket
        //no more nodes at minFreq, so minFreq must go up

        if(node -> freq == minFreq && freqToList[node -> freq] -> size == 0){
            minFreq++;
        }

        //4. get or create the next higher freq bucket
        FreqList* nextFreqList = new FreqList();
        if(freqToList.find(node -> freq + 1) != freqToList.end()){
            nextFreqList = freqToList[node -> freq + 1]; //bucket exists, reuse it 
        }

        //5. bump node's frequency, add to front of new bucket
        node -> freq++;
        nextFreqList -> addFront(node); //front = most recently used
        freqToList[node -> freq] = nextFreqList; //update freq map
        keyToNode[node -> key] = node; //put back in keyToNode
    }

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
        curSize = 0;
    }
    
    int get(int key) {
        if(keyToNode.find(key) == keyToNode.end()) return -1;

        Node* node = keyToNode[key];
        int  val = node -> value;
        incrementFreq(node); //accessing counts as a use -> freq goes up
        return val;
    }
    
    void put(int key, int value) {
        if(cap == 0) return; //edge case : nothing can ever be stored

        if(keyToNode.find(key) != keyToNode.end()){
            //case 1 : key already exists
            //just update value and bump freq
            Node* node = keyToNode[key];
            node -> value = value;
            incrementFreq(node);
        } else{
            //case 2. new key

            if(curSize == cap){
                //cache is full -> must evict before inserting
                // evict from minFreq bucket, take from BACK(LRU)

                FreqList* leastFreqList = freqToList[minFreq];
                Node* lruNode = leastFreqList -> tail -> prev; //LRU node

                keyToNode.erase(lruNode -> key); //remove from key map
                leastFreqList -> removeNode(lruNode); //remove from freq list
                delete lruNode;
                curSize--;
            }

            //create new node (freq = 1 by default inside constructor)
            Node* newNode = new Node(key, value);

            //new node always goes into freq = 1 bucket -> reset minFreq to 1
            minFreq = 1;

            //get or create freq = 1 bucket
            FreqList* freqOneList = new FreqList();
            if(freqToList.find(1) != freqToList.end()){
                freqOneList = freqToList[1]; //freq =1 bucket already exists
            }

            freqOneList -> addFront(newNode); //insert at front
            keyToNode[key] = newNode; //register in key map
            freqToList[1] = freqOneList; // update freq map
            curSize++;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */