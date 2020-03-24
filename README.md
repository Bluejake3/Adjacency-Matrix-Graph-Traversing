# Graph Traversing with Adjacency Matrix 

Source Code: [map.c](https://github.com/Bluejake3/Adjacency-Matrix-Graph-Traversing/blob/master/map.c)

## table of contents
* [Overview](https://github.com/Bluejake3/Adjacency-Matrix-Graph-Traversing#Overview)
* [Function list](https://github.com/Bluejake3/Adjacency-Matrix-Graph-Traversing#Function-list)

# Overview
This programs generate an adjacency matrix by using the `rand()` function. Users are provided by some menus that operate the randomized adjacency matrix. Some of the operation are printing, searching minimum distance, and searching maximum distance.

# Function List
* `void printmap(int map[M][M]);` for printing the matrix.
* `void dijkstra(int G[M][M],int n,int startnode, int endnode);` for searching the minimum distance of two nodes.
* `void maxdistance(int G[M][M], int startnode, int endnode);` for searching the maximum distance two nodes.
* `void takemin(int G[M][M], int startnode, int endnode);` for searching the distance of two nodes while visiting all nodes and always take the minimum path.
* `void takemax(int G[M][M], int startnode, int endnode);'`for searching the distance of two nodes and always take the maximum path until the end of the path is the destination node.


