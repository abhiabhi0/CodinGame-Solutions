import sys
import math
from collections import deque

# n: the total number of nodes in the level, including the gateways
# l: the number of links
# e: the number of exit gateways
n, l, e = [int(i) for i in input().split()]

nodes = [[] for _ in range(n)] # stores nodes connected to one another
gateway_nodes = []

for i in range(l):
    # n1: N1 and N2 defines a link between these nodes
    n1, n2 = [int(j) for j in input().split()]
    nodes[n1].append(n2)
    nodes[n2].append(n1)

for i in range(e):
    ei = int(input())  # the index of a gateway node
    gateway_nodes.append(ei)

def break_link(si):
    q = deque()
    q.append(si)

    while (q):
        u = q.popleft()
        prev_node = u 
        for n in nodes[u]:
            if n in gateway_nodes:
                return prev_node, n
            q.append(n)

# game loop
while True:
    si = int(input())  # The index of the node on which the Skynet agent is positioned this turn
    n1, n2 = break_link(si)

    nodes[n1].remove(n2)
    nodes[n2].remove(n1)

    # Example: 0 1 are the indices of the nodes you wish to sever the link between
    print(n1, n2)
