#!/usr/bin/python3

from typing import List, Tuple


class CustomSet:
    def __init__(self) -> None:
        self.set: List[Tuple[str, str]] = []

    def add(self, item: Tuple[str, str]) -> None:
        if item not in self.set:
            self.set.append(item)

    def count_native(self, item: str) -> int:
        return self.count(item, 1)

    def count_foreign(self, item: str) -> int:
        return self.count(item, 0)

    def count(self, item: str, idx: int) -> int:
        _count = 0
        for pair in self.set:
            if pair[idx] == item:
                _count += 1

        return _count

    def remove(self, item: str):
        set_copy = self.set.copy()

        for tup in set_copy:
            if item in tup:
                self.set.remove(tup)

    def __len__(self):
        return len(self.set)


connections = CustomSet()

tests = int(input())

for i in range(int(input())):
    pizza_name = input()
    ingredients_foreign = input().split(' ')[1:]
    ingredients_native = input().split(' ')[1:]

    for i in ingredients_foreign:
        for j in ingredients_native:
            connections.add((i, j))

matchs: List[Tuple[str, str]] = []

while connections:
    print(len(connections))
    for pair in connections.set:
        if connections.count_foreign(pair[0]) == 1:
            connections.remove(pair[0])
            matchs.append(pair)
        elif connections.count_native(pair[1]) == 1:
            connections.remove(pair[1])
            matchs.append(pair)

print(matchs)
