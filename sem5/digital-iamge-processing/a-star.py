import math
from queue import PriorityQueue

class Cell:
    def __init__(self, i=0, j=0):
        self.i = i
        self.j = j
        self.f = float('inf')
        self.g = float('inf')
        self.h = 0
        self.parent = None

graph = {}
edges = {}

def addedge(u, v, cost):
    if u not in edges:
        edges[u] = []
    if v not in edges:
        edges[v] = []
    edges[u].append((v, cost))
    edges[v].append((u, cost))

def calculate_h_value(n1, n2):
    x1, y1 = graph[n1].i, graph[n1].j
    x2, y2 = graph[n2].i, graph[n2].j
    return math.hypot(x1 - x2, y1 - y2)

def trace_path(dest):
    path = []
    node = dest
    while node is not None:
        path.append(node)
        node = graph[node].parent
    path.reverse()
    print("Path:", " -> ".join(path))

def a_star_search(start, goal):
    pq = PriorityQueue()
    for n in graph:
        graph[n].g = float('inf')
        graph[n].f = float('inf')
        graph[n].h = 0
        graph[n].parent = None

    graph[start].g = 0
    graph[start].h = calculate_h_value(start, goal)
    graph[start].f = graph[start].h
    pq.put((graph[start].f, start))

    closed_set = set()
    expansions = 0

    while not pq.empty():
        f_current, current = pq.get()
        if current in closed_set:
            continue
        expansions += 1

        if current == goal:
            print("Destination found!")
            trace_path(goal)
            print("Total cost:", graph[goal].g)
            print("Nodes expanded:", expansions)
            return

        closed_set.add(current)

        for neighbor, cost in edges.get(current, []):
            if neighbor in closed_set:
                continue
            g_new = graph[current].g + cost
            h_new = calculate_h_value(neighbor, goal)
            f_new = g_new + h_new
            if f_new < graph[neighbor].f:
                graph[neighbor].f = f_new
                graph[neighbor].g = g_new
                graph[neighbor].h = h_new
                graph[neighbor].parent = current
                pq.put((f_new, neighbor))

    print("Failed to find the destination")

for k in [('S',0,0), ('A',6,2),('B',6,0),('C',6,-2),('D',10,9),('E',10,6),('F',10,3),
          ('G',10,-3),('H',10,-6),('I',13,-4),('J',13,-8),('K',15,-3),('L',15,-5),('M',15,-8)]:
    graph[k[0]] = Cell(k[1], k[2])

addedge('S', 'A', 3)
addedge('S', 'B', 6)
addedge('S', 'C', 5)
addedge('A', 'D', 9)
addedge('A', 'E', 8)
addedge('B', 'F', 12)
addedge('B', 'G', 14)
addedge('C', 'H', 7)
addedge('H', 'I', 5)
addedge('H', 'J', 6)
addedge('I', 'K', 1)
addedge('I', 'L', 10)
addedge('I', 'M', 2)

a_star_search('S', 'M')
