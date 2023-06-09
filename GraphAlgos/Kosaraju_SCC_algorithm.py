from collections import defaultdict
from graphs import Graph


#sample graph 
L = {'A':['B', 'C'],
     'B':['D', 'E'],
     'C':['D', 'H'],
     'D':['A'],
     'E':['F'],
     'F':[],
     'H':[],
     'I':[]}

class Graph_SCC_fns(Graph):

    def filling_order(self, source, visited, stack):
        visited.append(source)
        
        for v in list(self.adj_list[source].keys()):
            if v not in visited:
                self.filling_order(v, visited, stack)
        
        stack.append(source)

    def print_SCC(self):
        visited = []
        stack = []

        for u in list(self.adj_list.keys()):
            if u not in visited:
                self.filling_order(u, visited, stack)
        
        trans = self.transpose()
        visited_=[]

        while stack:
            u = stack.pop()
            if u not in visited_:
                trans.dfs( u, visited_)
                print("")


G = Graph_SCC_fns("A")
G.add_edge("A", "B")
G.add_edge("B", "D")
G.add_edge("A", "C")
G.add_edge("B", "E")
G.add_edge("C", "H")
G.add_edge("C", "D")
G.add_edge("D", "A")
G.add_edge("E", "F")
G.add_vertex("F")
G.add_vertex("H")
G.add_vertex("I")

G.print()

G.print_SCC()
















