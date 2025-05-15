class Solution {
  public:
    int heapHeight(int N, int arr[]) {
        if (N == 1) return 1;

        int level = 0;
        int nodesUsed = 0;
        int nodesInCurrentLevel = 1;

        while (nodesUsed + nodesInCurrentLevel <= N) {
            nodesUsed += nodesInCurrentLevel;
            nodesInCurrentLevel *= 2;
            level++;
        }

        return level;
    }
};
