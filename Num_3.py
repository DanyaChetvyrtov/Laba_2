from string import ascii_uppercase as eng_letters


rus_letters = ''.join(sorted('ЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬБЮ'))

rus_dictionary = {letter: 0 for letter in rus_letters}
eng_dictionary = {letter: 0 for letter in eng_letters}


user_string = input('Введите строку: ')


for letter in user_string.upper():
    if letter in rus_dictionary:
        rus_dictionary[letter] += 1
    elif letter in eng_dictionary:
        eng_dictionary[letter] += 1

all_dictionary = eng_dictionary | rus_dictionary

user_letter = input('Введите символ, количество которой нужно посчитать в строке: ').upper()

print()
for key, val in all_dictionary.items():
    print(key, val)
print(f'Символ {user_letter} встречался в строке: {all_dictionary[user_letter]} раз')
