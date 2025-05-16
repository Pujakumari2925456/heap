// Profit Maximisation
// Programming
// Heaps And Maps

// Problem Description
 
 

//  Given an array A , representing seats in each row of a stadium. You need to sell tickets to B people.

// Each seat costs equal to the number of vacant seats in the row it belongs to. The task is to maximize the profit by selling the tickets to B people.



// Problem Constraints
// 1 <= |A| <= 100000

// 1 <= B <= 1000000



// Input Format
// First argument is the array A.

// Second argument is integer B.



// Output Format
// Return one integer, the answer to the problem.



int Solution::solve(vector<int> &A, int B) {
    priority_queue<long long>p;
    int n=A.size();
    for(long long i=0;i<n;i++)p.push(A[i]);
    long long sums=0;
    //remember har baar jitne bache ab unmes dekhna h pehle hi input se one go m nahi hoga
    while(B-- && !p.empty()){
        int largest=p.top();
        p.pop();
        sums+=largest;
        p.push(largest-1);
    }
    return int(sums);
}
