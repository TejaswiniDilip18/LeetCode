class MyCircularQueue {
private: 
    std::vector<int> buffer;
    int start;
    int end;
    int capacity;
    int size;

public:
    MyCircularQueue(int k) {
        this->start = 0;
        this->end = -1;
        this->capacity = k;
        buffer.resize(capacity);
        this->size = 0;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;

        end = (end+1) % capacity;
        buffer[end] = value;
        size++;
       
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;

        start = (start+1) % capacity;
        size--;
        
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return buffer[start];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return buffer[end];
    }
    
    bool isEmpty() {
        return size==0;
    }
    
    bool isFull() {
        // if(end+1 % capacity == start) return true
        return size==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */