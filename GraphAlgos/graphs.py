from collections import defaultdict

class Graph:

    def __init__(self, vertex):
        self.v = vertex
        self.adj_list = defaultdict(dict) #adjacency list 

    def add_edge(self, u, v):
        self.adj_list[u][v] = 1
    
    def add_ud_edge(self, u, v):
        self.adj_list[u][v] = 1
        self.adj_list[v][u] = 1
    
    def add_vertex(self, u):
        self.adj_list[u]={}
    
    def vertices(self):
        return list(self.adj_list.keys())
    
    def edges(self, u):
        return dict(self.adj_list[u])
    
    def add_weighted_edge(self, u, v, weight):
        self.adj_list[u][v] = weight
    
    def add_ud_weighted_edge(self, u, v, weight):
        self.adj_list[u][v] = weight
        self.adj_list[v][u] = weight

    def transpose(self):
        G_transpose = Graph(self.v)
        for u in list(self.adj_list.keys()):
            for v in list(self.adj_list[u].keys()):
                G_transpose.add_edge(v,u)
        return G_transpose
    
    def dfs(self, source, visited):
        
        visited.append(source)
        
        for v in list(self.adj_list[source].keys()):
            if v not in visited:
                self.dfs(v, visited)
        print(source, end = "")
    
    def print(self):
        print(self.adj_list)