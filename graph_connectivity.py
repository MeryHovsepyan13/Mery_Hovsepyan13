def dfs(v, visited, adj, component):
    visited[v] = True
    component.append(v)
    for u in adj[v]:
        if not visited[u]:
            dfs(u, visited, adj, component)

with open("input.txt", "r") as input_file, open("output.txt", "w") as output_file:
    n, m = map(int, input_file.readline().split())
    adj = [[] for _ in range(n+1)]
    visited = [False] * (n+1)

    for i in range(m):
        u, v = map(int, input_file.readline().split())
        adj[u].append(v)
        adj[v].append(u)

    components = []
    for i in range(1, n+1):
        if not visited[i]:
            component = []
            dfs(i, visited, adj, component)
            components.append(component)

    if len(components) == 1:
        output_file.write("The graph is connected\n")
    else:
        output_file.write("The graph is not connected\n")
        output_file.write("The connected components are:\n")
        for component in components:
            output_file.write(str(component) + "\n")
