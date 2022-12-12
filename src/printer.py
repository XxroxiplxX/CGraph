import pandas as pd
import matplotlib.pyplot as plt
import networkx as nx
import itertools
data = pd.read_csv('/tmp/graphs/graph_v.csv', delimiter=';')
vertices = data['v']
data2 = pd.read_csv('/tmp/graphs/graph_e.csv', delimiter=';')
edges1 = data2['e1']
edges2 = data2['e2']


G = nx.Graph()
for v in vertices:
    G.add_node(v)
for (e1, e2) in zip(edges1, edges2):
    G.add_edge(e1,e2)

nx.draw(G)
plt.show()
