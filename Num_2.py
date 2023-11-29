from some_func import *


def valid_int_checker(n: str) -> int:
    if type(n) is not str:
        raise TypeError('Функция valid_int_checker принимает только аргументы типа str.')

    if n.isdigit():
        return int(n)
    if ('.' or ',') in n:
        n = n.replace(',', '.').split('.', 1)
        if n[0].isdigit() and int(n[0]) > 1 and n[-1].isdigit() and int(n[-1]) == 0:
            n = int(n[0])
            return n
        else:
            # raise ValueError(f'"{".".join(n)}" не является натуральным числом.')
            return -1
    else:
        # raise ValueError(f'{n} не является натуральным числом')
        return -1


N, M = valid_int_checker(input('Введите количество строк матрицы: ')), \
       valid_int_checker(input('Введите количество столбцов матрицы: '))


if N == -1 or M == -1:
    print(f'Не удалось создать матрицу {N} на {M}')

else:
    A = matrix_creator(N, M)
    positive_nums_X = []
    negative_nums_Y = []
    print(f"Матрица {N} на {M}")
    print(matrix_formatter(A))
    for i in range(N):
        for j in range(M):
            if A[i][j] >= 0:
                positive_nums_X.append(A[i][j])
            else:
                negative_nums_Y.append(A[i][j])

    print(f"Положительные элементы матрицы: {positive_nums_X}")
    print(f"Отрицательные элементы матрицы: {negative_nums_Y}")
