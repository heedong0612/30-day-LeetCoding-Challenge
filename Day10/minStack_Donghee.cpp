// 4/11/2020
// Donghee Lee

// runtime: (constant time to retrieve the min value)
class MinStack {
private:
    stack<int> stk;
    stack<int> minStk;
    
public:
    /** initialize your data structure here. */
    
    MinStack() {
        
    }
    
    void push(int x) {
        stk.push(x);
        
        if (minStk.empty()) {
            minStk.push(x);
        } else if (minStk.top() >= x) {
            minStk.push(x);
        }
    }
    
    void pop() {
        if (stk.top() == minStk.top()) {
            stk.pop();
            minStk.pop();
        } else {
            stk.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};


// // runtime: 40ms (constant time to retrieve the minimum value, but uses 2 stacks)
// class MinStack2 {
// private:
//     stack<int> stk;
//     stack<int> minStk;
    
// public:
//     /** initialize your data structure here. */
    
//     MinStack() {
        
//     }
    
//     void push(int x) {
//         stk.push(x);
        
//         if (minStk.empty()) {
//             minStk.push(x);
//         } else if (minStk.top() >= x) {
//             minStk.push(x);
//         }
//     }
    
//     void pop() {
//         if (stk.top() == minStk.top()) {
//             stk.pop();
//             minStk.pop();
//         } else {
//             stk.pop();
//         }
//     }
    
//     int top() {
//         return stk.top();
//     }
    
//     int getMin() {
//         return minStk.top();
//     }
// };


// runtime: 40ms (linear time to find the min)
// class MinStack3 {
// private:
//     stack<int> stk;
//     int currMin;
    
// public:
//     /** initialize your data structure here. */
    
//     MinStack() {
//         currMin = INT_MAX;
//     }
    
//     void push(int x) {
//         if (currMin == INT_MAX)
//             currMin = x;
        
//         if (currMin > x)
//             currMin = x;
        
//         stk.push(x);
//     }
    
//     void pop() {
//         int pk = stk.top();
//         stk.pop();
        
//         if (pk == currMin) {
//             stack<int> stk2 = stk;
//             currMin = INT_MAX;
//             while (!stk2.empty()) {
//                 if (stk2.top() < currMin)
//                     currMin = stk2.top();
                
//                 stk2.pop();
//             }
//         } 
//     }
    
//     int top() {
//         return stk.top();
//     }
    
//     int getMin() {
//         return currMin;
//     }
// };
