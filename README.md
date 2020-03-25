# Graph Traversing with Adjacency Matrix 

Source Code: [map.c](https://github.com/Bluejake3/Adjacency-Matrix-Graph-Traversing/blob/master/map.c)

## Table of Contents
* [Overview](https://github.com/Bluejake3/Adjacency-Matrix-Graph-Traversing#Overview)
* [Function list](https://github.com/Bluejake3/Adjacency-Matrix-Graph-Traversing#Function-list)
* [How it Works](https://github.com/Bluejake3/Adjacency-Matrix-Graph-Traversing#How-it-Works)

# Overview
This programs generate an adjacency matrix by using the `rand()` function. Users are provided by some menus that operate the randomized adjacency matrix. Some of the operation are printing, searching minimum distance, and searching maximum distance.

# Function List
* `void printmap(int map[M][M]);` for printing the matrix.
* `void dijkstra(int G[M][M],int n,int startnode, int endnode);` for searching the minimum distance of two nodes.
* `void maxdistance(int G[M][M], int startnode, int endnode);` for searching the maximum distance two nodes.
* `void takemin(int G[M][M], int startnode, int endnode);` for searching the distance of two nodes while visiting all nodes and always take the minimum path.
* `void takemax(int G[M][M], int startnode, int endnode);'`for searching the distance of two nodes and always take the maximum path until the end of the path is the destination node.

# How it Works
Before the program prints the menu, an adjacency matrix is generated by using the `rand()` function. To maintain the distance on the list always on 1-100 range, we operate the result of `rand()` function by 100 and add it by 1. This program also mirrors the result so the distance between a to b and b to a is always the same and mark the a to a node by 0. Then, the program print the main menu and wait for user to input the command.

We use `switch` branching for choosing the menu. The program will do the command inside the selected menu, then back to main menu after the program finish the operation. This cycle continues until user enter the exit menu command.

* `void printmap(int map[M][M]);`

This program is made for printing the adjacency matrix. this program will print every single node in the matrix.

* `void dijkstra(int G[M][M],int n,int startnode, int endnode);`



