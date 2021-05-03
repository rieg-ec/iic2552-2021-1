from collections import defaultdict

graph = defaultdict(set)

for i in range(int(input())):
    node = input().strip('\n').split(' ')
    graph[node[0]].update(node[1:])
    for n in node[1:]:
        graph[n].add(node[0])


def search(node, target, path=[]):
    if path.count(node) > 1:
        return None
    if target in path:
        return path

    for i in graph[node]:
        p = search(i, target, [*path, i])
        if p is not None:
            return p

    return None


s, e = input().strip('\n').split(' ')

result = search(s, e, [s])
if not result:
    print('no route found')
else:
    print(' '.join(i for i in result))
