
//link =>https://www.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1
//SHOWING HOW TO APPLY MIN PRIORITY QUEUE(PQ);
//QN=>Given an array, arr[] of rope lengths, connect all ropes into a single rope with the minimum total cost. The cost to connect two ropes is the sum of their lengths. 

//Examples:

//Input: arr[] = [4, 3, 2, 6]
//Output: 29
class Solution {
   using ll = long long;
  public:
    int minCost(vector<int>& arr) {
        // code here
        int n=arr.size();
        priority_queue<ll ,vector<ll>,greater<ll>>p;//DECLARED  PQ
        for(ll i=0;i<n;i++){  //ARRAY JO DIYA THA USKO PQ M DAALA AB VO HEAP BAN GYA 
            p.push(arr[i]);
        }
        
        ll cost =0;
        while(p.size()>1){ //DO DO LEKAR ADD KARKE TOTAL M SUM KAR LE RHE H 
            ll rope=0;
            rope+=p.top();
            p.pop();
            rope+=p.top();
            p.pop();
            cost+=rope;
            p.push(rope);//LAST M JO DO KA SUM AA RHA H USKO VAPAS PQ M PUSH KAR RHE H 
           
        }
        return cost ;
    } 
};


//  Input: arr[] = [4, 3, 2, 6]
//Output: 29
//Explanation: We can connect the ropes in following ways.
//1) First connect ropes of lengths 2 and 3. Which makes the array [4, 5, 6]. Cost of this operation 2 + 3 = 5. 
//2) Now connect ropes of lengths 4 and 5. Which makes the array [9, 6]. Cost of this operation 4 + 5 = 9.
//3) Finally connect the two ropes and all ropes have connected. Cost of this operation 9 + 6 =15. Total cost is 5 + 9 + 15 = 29. This is the optimized cost for connecting ropes. 
//Other ways of connecting ropes would always have same or more cost. For example, if we connect 4 and 6 first (we get three rope of 3, 2 and 10), then connect 10 and 3 (we get two rope of 13 and 2). Finally we connect 13 and 2. Total cost in this way is 10 + 13 + 15 = 38.