n_of_stones = int(input())
stones = input()

stones_to_remove = 0
for i in range(n_of_stones - 1):
    if stones[i] == stones[i+1]:
        stones_to_remove += 1

print(stones_to_remove)
