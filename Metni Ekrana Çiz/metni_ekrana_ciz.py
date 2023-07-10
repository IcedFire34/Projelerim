def draw_text(text):
    character_map = {
        'A': ['  A  ', ' A A ', 'AAAAA', 'A   A', 'A   A'],
        'B': ['BBBB ', 'B   B', 'BBBB ', 'B   B', 'BBBB '],
        'C': [' CCCC', 'C    ', 'C    ', 'C    ', ' CCCC'],
        'D': ['DDD  ', 'D  D ', 'D   D', 'D  D ', 'DDD  '],
        'E': ['EEEEE', 'E    ', 'EEEEE', 'E    ', 'EEEEE'],
        'F': ['FFFFF', 'F    ', 'FFFFF', 'F    ', 'F    '],
        'G': [' GGG ', 'G    ', 'G  GG', 'G   G', ' GGGG'],
        'H': ['H   H', 'H   H', 'HHHHH', 'H   H', 'H   H'],
        'I': ['IIIII', '  I  ', '  I  ', '  I  ', 'IIIII'],
        'J': ['JJJJJ', '   J ', '   J ', 'J  J ', ' JJ  '],
        'K': ['K   K', 'K  K ', 'KK   ', 'K  K ', 'K   K'],
        'L': ['L    ', 'L    ', 'L    ', 'L    ', 'LLLLL'],
        'M': ['M   M', 'MM MM', 'M M M', 'M   M', 'M   M'],
        'N': ['N   N', 'NN  N', 'N N N', 'N  NN', 'N   N'],
        'O': [' OOO ', 'O   O', 'O   O', 'O   O', ' OOO '],
        'P': ['PPPP ', 'P   P', 'PPPP ', 'P    ', 'P    '],
        'Q': [' QQQ ', 'Q   Q', 'Q Q Q', 'QQQQQ', '   Q '],
        'R': ['RRRR ', 'R   R', 'RRRR ', 'R  R ', 'R   R'],
        'S': [' SSSS', 'S    ', ' SSS ', '    S', 'SSSS '],
        'T': ['TTTTT', '  T  ', '  T  ', '  T  ', '  T  '],
        'U': ['U   U', 'U   U', 'U   U', 'U   U', ' UUU '],
        'V': ['V   V', 'V   V', 'V   V', ' V V ', '  V  '],
        'W': ['W   W', 'W   W', 'W W W', 'WW WW', 'W   W'],
        'X': ['X   X', ' X X ', '  X  ', ' X X ', 'X   X'],
        'Y': ['Y   Y', ' Y Y ', '  Y  ', '  Y  ', '  Y  '],
        'Z': ['ZZZZZ', '   Z ', '  Z  ', ' Z   ', 'ZZZZZ'],
        ' ': ['      ', '      ', '      ', '      ', '      '],
        '.': ['      ', '      ', '      ', '      ', '   .  '],
        ',': ['      ', '      ', '      ', '   ,  ', '  .   '],
        '!': ['  !   ', '  !   ', '  !   ', '      ', '  !   '],
        '?': ['?????', '     ?', '    ? ', '      ', '   ?  '],
        ':': ['      ', '  :   ', '      ', '  :   ', '      '],
        ';': ['      ', '  ;   ', '      ', '  ;   ', '   .  '],
        '-': ['      ', '      ', ' ---- ', '      ', '      '],
        '_': ['      ', '      ', '      ', '      ', '_____ '],
        '#': ['  # # ', ' #####', '  # # ', ' #####', '  # # '],
        '@': [' @@@@ ', '@@  @@', '@@ @ @', '@@    ', ' @@@@ '],
        '1': ['  1   ', ' 11   ', '  1   ', '  1   ', ' 1111 '],
        '2': [' 2222 ', '     2', ' 2222 ', '2     ', ' 2222 '],
        '3': [' 3333 ', '     3', ' 3333 ', '     3', ' 3333 '],
        '4': ['4   4 ', '4   4 ', '44444 ', '    4 ', '    4 '],
        '5': ['55555 ', '5     ', '5555  ', '    5 ', '5555  '],
        '6': [' 6666 ', '6     ', '6666  ', '6   6 ', ' 666  '],
        '7': ['77777 ', '    7 ', '   7  ', '  7   ', ' 7    '],
        '8': [' 888  ', '8   8 ', ' 888  ', '8   8 ', ' 888  '],
        '9': [' 9999 ', '9   9 ', ' 9999 ', '    9 ', ' 999  '],
        '0': [' 000  ', '0   0 ', '0   0 ', '0   0 ', ' 000  '],
    }

    rows = len(character_map['A'])
    cols = sum(len(character_map[char][0]) for char in text)

    shape = [[' ' for _ in range(cols)] for _ in range(rows)]

    col_index = 0
    for char in text:
        char_shape = character_map.get(char, character_map[' '])
        for row in range(rows):
            shape[row][col_index:col_index + len(char_shape[row])] = char_shape[row]
        col_index += len(char_shape[0])

    for row in shape:
        print(''.join(row))


# Kullanıcıdan metin girişi
metin = input("Bir metin girin: ")

# Metin farklı karakterler kullanılarak ekrana çizilir
draw_text(metin)