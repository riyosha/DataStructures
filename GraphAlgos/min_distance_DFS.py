#this code finds the minimum distance between a source vertex and all other vertices in a graph using DFS

#sample graph 
G = {'A':['B', 'C'],
     'B':['D', 'E'],
     'C':['D', 'H'],
     'D':['A'],
     'E':['F'],
     'F':[],
     'H':[]}

def DFS_visit(G, u, visited, start_time, final_time, time):

    time = time +1 
    #start time of u = time
    start_time[u] = time
    visited.append(u)
    #for all neighbours of u not in visited, recursively DFS visit
    for v in G[u]:
        if v not in visited:
            DFS_visit(G, v, visited, start_time, final_time, time)
    #final time = time
    final_time[u] = time

def DFS_min_dist(G, s):
    visited = []
    start_time = {}
    final_time = {}

    time = 0
    visited.append(s)
    final_time[s] = time

    for v in G[s]:
        if v not in visited:
            DFS_visit(G,v, visited, start_time, final_time, time)

    return final_time

print(DFS_min_dist(G, 'A'))