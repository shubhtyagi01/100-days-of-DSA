class Solution {
public:
    string findOrder(vector<string>& words) {
        const int N = 26;
        vector<int> indegree(N, 0);
        vector<vector<int>> adj(N);
        vector<bool> present(N, false);

        
        for (auto &word : words)
            for (char c : word)
                present[c - 'a'] = true;

        
        for (int i = 0; i < words.size() - 1; i++) {
            string w1 = words[i], w2 = words[i+1];
            int len = min(w1.size(), w2.size());
            bool found = false;
            for (int j = 0; j < len; j++) {
                if (w1[j] != w2[j]) {
                    int u = w1[j] - 'a', v = w2[j] - 'a';
                    adj[u].push_back(v);
                    indegree[v]++;
                    found = true;
                    break;
                }
            }
            
            if (!found && w1.size() > w2.size()) return "";
        }

        
        queue<int> q;
        for (int i = 0; i < N; i++)
            if (present[i] && indegree[i] == 0)
                q.push(i);

        string result;
        int count = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            result += (char)(u + 'a');
            count++;
            for (int v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) q.push(v);
            }
        }

        
        int total = 0;
        for (int i = 0; i < N; i++) if (present[i]) total++;
        if (count != total) return "";

        return result;
    }
};
