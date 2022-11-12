class MedianFinder {
    priority_queue<int> smaller;
    priority_queue<int, vector<int>, greater<int>> larger;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        smaller.push(num);
        larger.push(smaller.top());
        smaller.pop();
        if (smaller.size() < larger.size()){
            smaller.push(larger.top());
            larger.pop();
        }
    }
    
    double findMedian() {
        if (smaller.size() > larger.size()){
            return smaller.top();
        }
        return (smaller.top() + larger.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */