#this code finds the minimum distance between a source vertex and all other vertices in a graph using BFS
from queue import Queue

#sample graph 
G = {'A':['B', 'C'],
     'B':['D', 'E'],
     'C':['D', 'H'],
     'D':['A'],
     'E':['F'],
     'F':[],
     'H':[]}

def BFS(G, s):
    visited = []
    distance = {}
    #set color of all vertices to white
    #initialize queue Q with s as source  vertex, mark s visited 
    Q = Queue(maxsize=50)
    Q.put(s)
    visited.append(s)
    #set distance of s from s as 0
    distance[s] = 0
    #till Q is not empty -
    while Q.empty() is False:
        #dequeue Q, let element = u
        u = Q.get() 
        #mark u as visited
        visited.append(u)

        #enqueue all v in G.Adj(u) (if they are white), make them grey
        for v in G[u]:
            if v not in visited:
                Q.put(v) 
                #distance of neighbours = distance of u from s + 1
                distance[v] = distance[u]+1

    return distance


print(BFS(G, 'A'))



    
