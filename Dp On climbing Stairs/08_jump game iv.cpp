class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> indicesOfValue;
        for (int i = 0; i < n; i++)
            indicesOfValue[arr[i]].push_back(i);  // creating a map from where we can go
        // for tracing the nodes ;
        vector<bool> visited(n); 
        visited[0] = true; // start from 0 so mark as true;
        queue<int> q; 
        q.push(0); // we pushed 0 in queue
        int step = 0;
        while (!q.empty()) {
            for (int size = q.size(); size > 0; --size) 
            {
                int front = q.front(); 
                q.pop();
                if (front == n - 1) return step; // Reached to last index
                vector<int>& next = indicesOfValue[arr[front]];
                next.push_back(front - 1);
                next.push_back(front + 1);
                for (int j : next) 
                {
                    if (j >= 0 && j < n && !visited[j])  // we have to add back on queue
                    {
                        visited[j] = true; // marks as true;
                        q.push(j); // and push in queue
                    }
                }
                indicesOfValue[arr[front]].clear(); // avoid later lookup indicesOfValue arr[i]
            }
            step++;
        }
        return step;
    }
};