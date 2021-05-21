board = [["5", "3", ".", ".", "7", ".", ".", ".", "."],
         ["6", ".", ".", "1", "9", "5", ".", ".", "."],
         [".", "9", "8", ".", ".", ".", ".", "6", "."],
         ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
         ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
         ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
         [".", "6", ".", ".", ".", ".", "2", "8", "."],
         [".", ".", ".", "4", "1", "9", ".", ".", "5"],
         ["3", ".", ".", ".", "8", ".", ".", "7", "9"]]


def check_vertically(col: int):
    used = []
    for row in board:
        if row[col] in used and row[col] != '.':
            return False
        used.append(row[col])

    return True


def check_sub_box(sub_box: int):
    used = []
    start_row = (sub_box // 3) * 3
    start_col = (sub_box % 3) * 3
    for row in board[start_row:start_row+3]:
        for box in row[start_col:start_col+3]:
            if box in used and box != '.':
                return False
            used.append(box)
    return True


def check_row(row: int):
    used = []
    for box in board[row]:
        if box in used and box != '.':
            return False
        used.append(box)
    return True


def get_row_col_from_pos(pos: int):
    row = pos // 9
    col = pos % 9
    return (row, col)


empty = []
for i in range(80):
    r, c = get_row_col_from_pos(i)
    if board[r][c] == '.':
        empty.append(i)


def get_sub_box_from_pos(pos: int):
    row, col = get_row_col_from_pos(pos)
    y = row // 3
    x = col // 3
    return y*3 + x


def solve(pos: int):

    if (not check_vertically(get_row_col_from_pos(pos)[1])
            or not check_sub_box(get_sub_box_from_pos(pos))
            or not check_row(get_row_col_from_pos(pos)[0])
            ):
        return False

    if not empty:
        return True

    p = empty.pop(-1)
    r, c = get_row_col_from_pos(p)
    for i in range(1, 10):
        board[r][c] = str(i)
        if solve(p):
            return True
        board[r][c] = '.'
    empty.append(p)

    return False


solve(0)

for row in board:
    print(row)
