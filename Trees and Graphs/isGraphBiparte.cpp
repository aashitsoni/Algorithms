/*
Is Graph Bipartite?

Solution
There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:

There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.

Return true if and only if it is bipartite.

 

Example 1:

    0 -------  1
    | \        |
    |  \       |
    |   \      |
    |    \     |
    |     \    |
    |      \   |
    |       \  |
    3 ------- 2

Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.
Example 2:

    0 ------- 1
    |         |
    |         |
    |         |
    3 ------- 2

Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.
 

Constraints:

graph.length == n
1 <= n <= 100
0 <= graph[u].length < n
0 <= graph[u][i] <= n - 1
graph[u] does not contain u.
All the values of graph[u] are unique.
If graph[u] contains v, then graph[v] contains u.

*/


bool isBipartite(int** graph, int graphSize, int* graphColSize)
{
    int* color = malloc(graphSize*sizeof(int));
    int* list = malloc(graphSize*sizeof(int));
    
    int start;
    
    memset(color,-1,sizeof(int)*graphSize);
    
    
    for(start = 0; start < graphSize;start++)
    {
        if(color[start] == -1)
        {
            int n=0;
            int count=0;
  
            color[start] = 0;

            list[count++] =start;


            while(n < count)
            {

                int nei;
                int node = list[n++];
           
                for(int j = 0; j< graphColSize[node];j++)
                {
                    nei = graph[node][j];

                    if(color[nei] == -1)
                    {
                        list[count++] = nei;
                        color[nei] = color[node]^1; // xor to switch from 0 to 1

                    }
                    else if(color[nei] == color[node])
                    {
                        free(list);
                        free(color);
                        return false;
                    }
                }
       
            }
        }
    }
    free(list);
    free(color);
return true;
}