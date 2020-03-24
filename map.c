#include<stdio.h>
#include<stdlib.h>
const int M=40;

void dijkstra(int G[M][M],int n,int startnode, int endnode);
void printmap(int map[M][M]);
void maxdistance(int G[M][M], int startnode, int endnode);
void takemin(int G[M][M], int startnode, int endnode);
void takemax(int G[M][M], int startnode, int endnode);

int main(){
	
	int map[M][M];
	int i, j;
	int startnode, endnode, select;
	for(i=0;i<M;i++)
	{
		for(j=0;j<M;j++)
		{
			if(i==j) map[i][j]=0;
			else {
				map[i][j]=rand()%100+1;
				map[j][i]=map[i][j];
			}
			
		}
	}
	do
	{
		startnode=0; endnode=0;
		printf("Main Menu:\n1. Print the map\n2. Search the minimum distance between 2 nodes\n3. Search the maximum distance between 2 nodes\n4. Search the distance between 2 nodes while always taking minimum path and visit all node\n5. Search the distance between 2 nodes while always taking maximum path\n6. Exit the program\nSelection: ");
		scanf("%d", &select);
		switch (select)
		{
			case 1: 
				printmap(map);
				break;
			case 2:
				printf("Select the starting node from 0 to %d: ", M-1);
				scanf("%d", &startnode);
				printf("Select the end node from 0 to %d: ", M-1);
				scanf("%d", &endnode);
				dijkstra(map,M,startnode, endnode);
				printf("\n");
				break;
			case 3:
				printf("Select the starting node from 0 to %d: ", M-1);
				scanf("%d", &startnode);
				printf("Select the end node from 0 to %d: ", M-1);
				scanf("%d", &endnode);
				maxdistance(map, startnode, endnode);
				printf("\n");
				break;
			case 4:
				printf("Select the starting node from 0 to %d: ", M-1);
				scanf("%d", &startnode);
				printf("Select the end node from 0 to %d: ", M-1);
				scanf("%d", &endnode);
				takemin(map,startnode, endnode);
				printf("\n");
				break;
			case 5:
				printf("Select the starting node from 0 to %d: ", M-1);
				scanf("%d", &startnode);
				printf("Select the end node from 0 to %d: ", M-1);
				scanf("%d", &endnode);
				takemax(map, startnode, endnode);
				printf("\n");
				break;
			case 6:
				printf("Goodbye\n");
				break;
			default:
				printf("Sorry, your input is invalid. Please try again\n");
				break;
		}
	}while(select!=6);
   


	return 0;
}

void dijkstra(int G[M][M],int n,int startnode, int endnode)
{
 	if(startnode>=M||endnode>=M||startnode<0||endnode<0)
 	{
 		printf("Sorry, your inputs are invalid\n");
 		return;
	}
	int cost[M][M],distance[M],pred[M];
	int visited[M],count,maxdistance,nextnode,i,j;

	for(i=0;i<M;i++)
	{
		for(j=0;j<M;j++)
		{
			if(i==j) cost[i][j]=-99999;
			else cost[i][j]=G[i][j];
		}
	}

	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}

	distance[startnode]=0;
	visited[startnode]=1;
	count=1;

	while(count<M-1)
	{
		maxdistance=9999;
		for(i=0;i<M;i++)
		{
			if(distance[i]<maxdistance&&!visited[i])
			{

				maxdistance=distance[i];
				nextnode=i;
			}
		}
			visited[nextnode]=1;
			for(i=0;i<M;i++)
			{
				if(!visited[i])
				{

					if(maxdistance+cost[nextnode][i]<distance[i])
					{

						distance[i]=maxdistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
				}
			}
		count++;
	}

		if(endnode!=startnode)
		{
			printf("\nMinimum Distance of node %d to node %d is %d",startnode, endnode,distance[endnode]);
			printf("\nPath=%d",endnode);
			
			j=endnode;
			do
			{
				j=pred[j];
				printf("<-%d",j);
			}while(j!=startnode);
	}
}

void printmap(int map[M][M])
{
	int i,j;
	for(i=0;i<M;i++) printf("\t%d", i);
	printf("\n");
	for(i=0;i<M;i++)
	{
		printf("%d\t",i);
		for(j=0;j<M;j++)
		{
			printf("%d\t", map[i][j]);
		}
		printf("\n");
	}
	return;
}

void maxdistance(int map[M][M], int startnode, int endnode)
{
	if(startnode>=M||endnode>=M||startnode<0||endnode<0)
 	{
 		printf("Sorry, your inputs are invalid\n");
 		return;
	}
	int visited[M], nodes[M], cost[M][M];
	int i, j;
	int distance=0, count=1, max, next, current=startnode;
	
	for(i=0;i<M;i++)
	{
		for(j=0;j<M;j++)
		{
			cost[i][j]=map[i][j];
		}
	}
	
	for (i=0;i<M;i++) visited[i]=0;
	visited[startnode]=visited[endnode]=1;
	nodes[0]=startnode;
	nodes[9]=endnode;
	for(i=0;i<M;i++) cost[i][startnode]=0;
	
	while(count<M-1)
	{
		max=-1;
		next=-1;
		for(i=0;i<M;i++)
		{
			if (i==endnode) continue;
			else if (cost[current][i]>max)
			{
				max=cost[current][i];
				next=i;
			}
		}
		distance+=max;
		nodes[count]=next;
		current=next;
		for(i=0;i<M;i++) cost[i][current]=0;
		count++;
	}
	for(i=0;i<M;i++)
	{
		if (cost[current][i]>max)
		{
			max=cost[current][i];
			next=i;
		}
	}
	distance+=max;
	
	printf("Maximum Distance from node %d to %d is %d\n", startnode, endnode, distance);
	printf("Path:");
	for(i=0;i<M-1;i++) printf("%d->", nodes[i]); printf("%d\n", endnode);
}

void takemin(int map[M][M], int startnode, int endnode)
{
	if(startnode>=M||endnode>=M||startnode<0||endnode<0)
 	{
 		printf("Sorry, your inputs are invalid\n");
 		return;
	}
	int visited[M], nodes[M], cost[M][M];
	int i, j;
	int distance=0, count=1, min, next, current=startnode;
	
	for(i=0;i<M;i++)
	{
		for(j=0;j<M;j++)
		{
			cost[i][j]=map[i][j];
		}
	}
	
	for (i=0;i<M;i++) 
	{
		visited[i]=0;
		cost[i][i]=9999;
		cost[i][current]=9999;
	}
	visited[startnode]=visited[endnode]=1;
	nodes[0]=startnode;
	nodes[M-1]=endnode;
	
	
	while(count<M-1)
	{
		min=9999;
		next=9999;
		for(i=0;i<M;i++)
		{
			if (i==endnode) continue;
			else if (cost[current][i]<min)
			{
				min=cost[current][i];
				next=i;
			}
		}
		distance+=min;
		nodes[count]=next;
		current=next;
		for(i=0;i<M;i++) cost[i][current]=9999;
		count++;
	}
	for(i=0;i<M;i++)
	{
		if (cost[current][i]<min)
		{
			min=cost[current][i];
			next=i;
		}
	}
	distance+=min;
	
	printf("Distance from node %d to %d (visit all nodes and take the minimum distance) is %d\n", startnode, endnode, distance);
	printf("Path:");
	for(i=0;i<M-1;i++) printf("%d->", nodes[i]); printf("%d\n", endnode);
}

void takemax(int map[M][M], int startnode, int endnode)
{
	if(startnode>=M||endnode>=M||startnode<0||endnode<0)
 	{
 		printf("Sorry, your inputs are invalid\n");
 		return;
	}
	int visited[M], nodes[M], cost[M][M];
	int i, j;
	int distance=0, count=1, max, next, current=startnode;
	
	for(i=0;i<M;i++)
	{
		for(j=0;j<M;j++)
		{
			cost[i][j]=map[i][j];
		}
	}
	nodes[0]=startnode;
	for (i=0;i<M;i++) 
	{
		visited[i]=0;
		cost[i][i]=-9999;
		cost[i][startnode]=-9999;
	}
	while(current!=endnode)
	{
		max=-9999;
		next=-9999;
		for(i=0;i<M;i++)
		{
			if(cost[current][i]>max)
			{
				max=cost[current][i];
				next=i;
			}
		}
		distance+=max;
		current=next;
		nodes[count]=current;
		current=next;
		for(i=0;i<M;i++)
		{
			cost[i][current]=-9999;
		}
		count++;
	}
	printf("Distance from node %d to %d (visit all nodes and take the maximum distance) is %d\n", startnode, endnode, distance);
	printf("Path:");
	for(i=0;i<count-1;i++) printf("%d->", nodes[i]); printf("%d\n", endnode);
}

