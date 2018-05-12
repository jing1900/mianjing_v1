/*

问题：无向图的复制，leetcode 133
https://leetcode.com/problems/clone-graph/description/

*/
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        /*
        //BFS解法
        if(!node) return NULL;
        //unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> mp;
        queue<UndirectedGraphNode*> toVisit;//待访问队列
        UndirectedGraphNode * copy = new UndirectedGraphNode(node->label);
        mp[node] = copy;
        toVisit.push(node);//记住，这里放入的是原node，因为copy现在还是个空壳子，需要跟着node，继续填充其邻居
        while(!toVisit.empty())
        {
            UndirectedGraphNode* cur = toVisit.front();
            toVisit.pop();
            for(auto neigh: cur->neighbors)//访问原节点的邻居节点
            {
                if(mp.find(neigh) == mp.end())//表示该节点并未被拷贝过，则拷贝并存入mp表示已被拷贝过，并将邻居节点本身加入toVisit，然后将邻居拷贝添加至拷贝的邻居
                {
                    UndirectedGraphNode* neigh_copy = new UndirectedGraphNode(neigh->label);
                    mp[neigh] = neigh_copy;//同样放入邻居节点和它的拷贝
                    toVisit.push(neigh);//并将邻居节点本身加入待访问队列

                }

                mp[cur]->neighbors.push_back(mp[neigh]);//注意，这里开始将原节点的邻居节点的拷贝, 赋值给原节点拷贝的邻居节点

            }
        }
        return copy;*/
        //DFS解法
        if(!node) return NULL;
        if(mp.find(node) == mp.end())
        {
            mp[node] = new UndirectedGraphNode(node->label);
            for(auto neigh: node->neighbors)
                mp[node]->neighbors.push_back(cloneGraph(neigh));
        }
        return mp[node];
    }

private:
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> mp;//标记是否被访问过,存放原节点及其拷贝,DFS解法mp必须放这里
};