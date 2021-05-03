N = int(input())


for i in range(N):
    s = input()
    if 'Simon says' in s:
        action = s.split('Simon says ')[1]
        print(action)
