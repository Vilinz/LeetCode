#include <iostream>
#include "header.h"

class Solution {
public:
/*
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;
        vector<int> res;
        // 存储每个点的入度
        vector<int> indegree(numCourses);
        // 存储当前点指向的下一个节点集
        map<int, vector<int>> m;
        // 计算入度
        for (int i = 0; i < prerequisites.size(); ++i) {
            m[prerequisites[i][1]].push_back(prerequisites[i][0]);
            ++indegree[prerequisites[i][0]];
        }

        // 入度为0的点入队列
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int temp = q.front();
            q.pop();
            res.push_back(temp);
            auto next = m[temp];
            for (auto &i : next) {
                if (--indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        return res.size() == numCourses ? res : vector<int>{};
    }
*/
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> edge(numCourses, vector<int>());
        vector<int> visited(numCourses, 0);
        vector<int> res;
        bool hasRing = false;
        for (int i = 0; i < prerequisites.size(); ++i) {
            edge[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        for (int i = 0; i < numCourses; ++i) {
            if (visited[i] == 0 && !hasRing) {
                dfs(edge, visited, res, hasRing, i);
            }
        }

        return hasRing ? vector<int>{} : res;

    }

    void dfs(vector<vector<int>> &edge, vector<int> &visited, vector<int> &res, bool &hasRing, int &p) {
        visited[p] = 1;
        for (int i = 0; i < edge[p].size(); ++i) {
            if (visited[edge[p][i]] == 0) {
                dfs(edge, visited, res, hasRing, edge[p][i]);
                if (hasRing) {
                    return;
                }
            } else if (visited[edge[p][i]] == 1) {
                hasRing = true;
                return;
            }
        }
        res.push_back(p);
        visited[p] = 2;
    }
};

int main() {
    vector<vector<int>> v = {{1,0}};
    Solution s;
    vector<int> r = s.findOrder(2, v);
    for (auto &i : r) {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}