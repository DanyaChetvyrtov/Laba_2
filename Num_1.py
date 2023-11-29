from some_func import *


while True:
    try:
        n = input('Укажите размер квадратной матрицы (введите натуральное N число > 1): ')
        if n.isdigit() and int(n) > 1:
            n = int(n)
            break

        if ('.' or ',') in n:
            n = n.replace(',', '.').split('.', 1)
            if n[0].isdigit() and int(n[0]) > 1 and n[-1].isdigit() and int(n[-1]) == 0:
                n = int(n[0])
                break
            else:
                raise ValueError

    except ValueError:
        print('Необходимо ввести натуральное число N > 1.')


rand_matrix = matrix_creator(n, n)

print(f'\nВаша матрица из случайных чисел, размером {n} на {n}\n', matrix_formatter(rand_matrix), '\n')

j = len(rand_matrix[0]) - 1
elements_for_summ = []
for string in rand_matrix:
    elements_for_summ += string[:j]
    j -= 1

summ_of_elements = 0
for el in elements_for_summ:
    summ_of_elements += el

print(f'Сумма элементов,расположенных выше побочной диагонали: {summ_of_elements}')
