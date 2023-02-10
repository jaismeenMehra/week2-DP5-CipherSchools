class Node{//doubly circular ll
public:
    int key;
    int val;
    Node *left;
    Node *right;
    Node(int key,int val){
        this->key=key;
        this->val=val;
        left=right=this;
    }
};
class LRUCache {
private:
    unordered_map<int,Node*> mp;
    Node *root{};
    int cap;
    int size{};
public:
    LRUCache(int capacity) {
        this->cap=capacity;
    }
    // void printLru(){
    //     int c=cap;
    //     while(root && c>0){
    //         cout<<root->key<<" "<<root->val<<endl;
    //         root=root->right;
    //         c--;
    //     }
    // }

    /*
    if not present return -1
    else take node-> join chain -> bring node to front
    */
    int get(int key) {
        auto itr=mp.find(key);
        if(itr==mp.end()){
            return -1;
        }
        Node *node=itr->second;
        if(root!=node){
            Node *lft=node->left;
            lft->right=node->right;
            node->right->left=lft;
            addFront(node);
        }
        return root->val;
    }
    
    /*
    if not present add to front -> if size>cap -> delete last
    else take node -> join chain -> bring it to front.
    */
    void put(int key, int value) {
        auto itr=mp.find(key);
        if(itr==mp.end()){
            Node *temp=new Node{key,value};
            mp[key]=temp;
            size++;
            addFront(temp);
        }else{
            Node *node=itr->second;
            node->val=value;
            if(root!=node){
                Node *lft=node->left;
                lft->right=node->right;
                node->right->left=lft;
                addFront(node);
            } 
        }
        if(size>cap){
            deleteLast();
            size--;
        }
    }
    void addFront(Node *node){
            if(!root){
                root=node;
                return;
            }
            Node *lft=root->left;
            lft->right=node;
            node->left=lft;
            node->right=root;
            root->left=node;
            root=node;
    }
    void deleteLast(){
        if(root==root->left){
            mp.erase(root->key);
            root=NULL;
            delete root;
            return;
        }
        Node *del=root->left;
        del->left->right=root;
        root->left=del->left;
        mp.erase(del->key);
        delete del;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */