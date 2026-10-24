class Node{
    public:

    int freq;
    unordered_set<string> keyStore;

    Node* prev;
    Node* next;

    Node(int freq){
        this -> freq = freq;
        prev = nullptr;
        next = nullptr;
    }

};

class DoublyLinkedList{
    public:

    Node* head;
    Node* tail;
    int size;

    DoublyLinkedList(){
        head = new Node(INT_MIN);
        tail = new Node(INT_MAX);
        
        head -> next = tail;
        tail -> prev = head;
        size = 0;
    }

    bool isEmpty(){
        return (size == 0);
    }

    void addNode(Node* prev,Node* node){
        node -> next = prev -> next;
        prev -> next -> prev = node;
        
        node -> prev = prev;
        prev -> next = node;

        size++;
    }

    void removeNode(Node* node){

        node -> prev -> next = node -> next;
        node -> next -> prev = node -> prev;
        
        node -> prev = nullptr;
        node -> next = nullptr;
        size--;
    }

};

class AllOne {

    DoublyLinkedList* ds;
    unordered_map<string,Node*> stringNode;
    unordered_map<string,int> stringCount;
public:
    AllOne() {
        ds = new DoublyLinkedList();
    }
    
    void inc(string key) {
        
        if (stringNode.find(key) == stringNode.end()){

            //find if the node contains keys with frequency 1 exists or not
            Node* head = ds -> head;
            if (head -> next -> freq != 1){
                Node* newNode = new Node(1);
                ds -> addNode(head,newNode);
            }

            head -> next -> keyStore.insert(key);
            stringNode[key] = head -> next;
            stringCount[key] = 1;

            return;
        }

        Node* node = stringNode[key];
        int freq = node -> freq;

        //remove the key from the node
        node -> keyStore.erase(key);

        //as the key as erase now it should be transfered to the next freq
        int new_freq = freq + 1;
        if (node -> next -> freq != new_freq){
            Node* newNode = new Node(new_freq);
            ds -> addNode(node,newNode);
        }

        stringCount[key] = new_freq;
        stringNode[key] = node -> next;
        node -> next -> keyStore.insert(key);

        if (node -> keyStore.empty()){
            ds -> removeNode(node);
        }
    }
    
    void dec(string key) {
        
        if (stringNode.find(key) == stringNode.end()) return;

        Node* node = stringNode[key];
        
        if (node -> freq == 1){
            node -> keyStore.erase(key);
            if (node -> keyStore.empty()){
                ds -> removeNode(node);
            }

            stringCount.erase(key);
            stringNode.erase(key);

            return;
        }

        int freq = node -> freq;
        node -> keyStore.erase(key);

        int new_freq = freq - 1;
        if (node -> prev -> freq != (freq - 1)){
            Node* newNode = new Node(new_freq);
            ds -> addNode(node -> prev,newNode);
        }

        node -> prev -> keyStore.insert(key);
        stringCount[key] = new_freq;
        stringNode[key] = node -> prev;

        if (node -> keyStore.empty()){
            ds -> removeNode(node);
        }
    }
    
    string getMaxKey() {
        if (ds -> isEmpty()) return "";
        auto it = ds -> tail -> prev -> keyStore.begin();
        return (*it);
    }
    
    string getMinKey() {
        if (ds -> isEmpty()) return "";
        auto it = ds -> head -> next -> keyStore.begin();
        return (*it);
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */