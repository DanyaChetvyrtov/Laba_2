from random import randint, uniform


def matrix_creator(n: int, m: int) -> list[list]:
    matrix = []
    for i in range(n):
        sub_arr = []
        for j in range(m):
            sub_arr.append(round(randint(-100, 100), 1))
        matrix.append(sub_arr)
    return matrix


def matrix_formatter(matrix: list[list]) -> str:
    formatted_matrix = ''
    len_of_one_string = 0
    for string in matrix:
        formatted_matrix += '|'
        for char in string:
            formatted_matrix += str(char) + ' '*(6 - len(str(char))) if char != string[-1] \
                else str(char) + ' '*(4-len(str(char)))
        formatted_matrix += '|\n'
        if formatted_matrix.count('|') == 2:
            len_of_one_string = len(formatted_matrix)
    formatted_matrix = ((len_of_one_string-1) * '-') + '\n' + formatted_matrix + ((len_of_one_string-1) * '-')

    return formatted_matrix
