#include <iostream>
#include <utility>
#include <limits>
#include <vector>
using namespace std;

int shortestPath(const double* const * graph, int numV, int src, double* dist, int* prev)
{
   vector< pair<int,int> > edges; 
   int numEdges = 0;
   for (int i = 0;i<numV;i++)
   {
      
      for (int j = 0;j<numV;j++)
      {
	 if (graph[i][j]!=numeric_limits<double>::infinity())
	 {
	    edges.push_back(pair<int,int>(i,j));
	    numEdges++;
	 }
      }
   }
   dist[src] = 0;
   for (int i= 1;i<numV;i++)
   {
      for (int j = 0; j<numEdges;j++)
      {
	 if (dist[edges[j].second] > dist[edges[j].first] + graph[edges[j].first][edges[j].second])
	 {
	    dist[edges[j].second] = dist[edges[j].first]+graph[edges[j].first][edges[j].second];
	    prev[edges[j].second] = edges[j].first;
	 }
      }
   }
   for(int j=0;j<numEdges;j++)
   {
      if (dist[edges[j].second] > dist[edges[j].first] + graph[edges[j].first][edges[j].second])
      {
	 dist[edges[j].second] = dist[edges[j].first]+graph[edges[j].first][edges[j].second];
	 prev[edges[j].second] = edges[j].first;
	 return edges[j].second+1;
      }
   }	 
   return 0;
}



