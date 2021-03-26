import sys

# test = input()
# numbers = list(map(lambda x: int(x), test.strip().split(' ')))
# total_sum = sum(numbers)

# for number in numbers:
#     if total_sum - number == number:
#         print(number)
#         break

for line in sys.stdin:
    numbers = list(map(lambda x: int(x), line.strip().split(' ')))
    total_sum = sum(numbers)

    for number in numbers:
        if total_sum - number == number:
            print(number)
            break
