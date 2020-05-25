#### [LRU缓存机制](https://leetcode-cn.com/problems/lru-cache/)

运用你所掌握的数据结构，设计和实现一个 [LRU (最近最少使用) 缓存机制](https://baike.baidu.com/item/LRU)。它应该支持以下操作： 获取数据 `get` 和 写入数据 `put` 。

获取数据 `get(key)` - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 `put(key, value)` - 如果密钥已经存在，则变更其数据值；如果密钥不存在，则插入该组「密钥/数据值」。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。

 

**进阶:**

你是否可以在 **O(1)** 时间复杂度内完成这两种操作？

 

**示例:**

```
LRUCache cache = new LRUCache( 2 /* 缓存容量 */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4
```

```c++
struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};
class LRUCache {
private:
    int capacity;
    int size;
    DLinkedNode* head;
    DLinkedNode* tail;
    map<int,DLinkedNode*> cache;
public:
    LRUCache(int _capacity) {
        capacity=_capacity;
        size=0;
        head=new DLinkedNode();
        tail=new DLinkedNode();
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(!cache.count(key))
            return -1;
        DLinkedNode* node = cache[key];
        moveNodeToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(!cache.count(key)){
            size++;
            DLinkedNode* node = new DLinkedNode(key,value);
            cache[key]=node;
            addNodeToHead(node);
            if(size>capacity){
                size--;
                DLinkedNode* del = tail->prev;
                removeNode(del);
                cache.erase(del->key);
            }
        }
        else{
            DLinkedNode* node = cache[key];
            node->value=value;
            moveNodeToHead(node);
        }
    }

    void addNodeToHead(DLinkedNode* node){
        node->prev=head;
        node->next=head->next;
        head->next->prev=node;
        head->next=node;
    }

    void removeNode(DLinkedNode* node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
    }

    void moveNodeToHead(DLinkedNode* node){
        removeNode(node);
        addNodeToHead(node);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```

