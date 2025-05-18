//1354. Construct Target Array With Multiple Sums
//link=>https://leetcode.com/problems/construct-target-array-with-multiple-sums/description/
//please see 2 egde case 
//1)Tle 
//2)prev=0 ka case ///abhi mujhe bhi ye dono case nhi samjh aaya 

class Solution {
public:
    bool isPossible(vector<int>& target) {
        int n=target.size();
        priority_queue<int>p;
        long long sum=0;
        for(int i=0;i<n;i++){
            p.push(target[i]);
            sum+=target[i];
        }
        long long remSum,prev,max;
        while(p.top()!=1){
            max=p.top();
            p.pop();
            remSum=sum-max;
            if(remSum<=0 || remSum>=max)return 0;
            // prev=max-remSum;
            prev=max%remSum;
            if(prev==0){
                if(remSum!=1)return 0;
                else return 1;
            }
            p.push(prev);
            sum=remSum+prev;

        }
        return 1;
    }
};