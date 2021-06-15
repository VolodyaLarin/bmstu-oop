"""
Ларин Владимир

Конвертирует из obj wareframe (можно просматривать, например в blender 3d) 
в более удобный для парсинга формат

Описание формата:
<Кол-во точек>
<Центр в формате X Y Z, разделитель пробел>
<Точки в формате X Y Z, разделитель пробел>
<Кол-во связей>
<Связь в формате ОТ КУДА, разделитель пробел>
"""

file = open(input("Введите имя входного файла: "), "rt")
cords = [[0,0,0]]
lines = [] 
for line in file.readlines():
    try:
        x = line.replace("/n", "").split()
        if x[0] == "v":
            cords.append(list(map(float, x[1:])))
        if x[0] == "f":
            c = list(map(lambda y: int(y.split('/')[0]), x[1:]))
        
            for i in range(len(c) - 1):
                line = [c[i], c[i+1]]
                lines.append(line)
            lines.append([c[0], c[-1]])
    except:
        pass

center = [
    (min(map(lambda x: x[0], cords[1:])) + max(map(lambda x: x[0], cords[1:]))) / 2,
    (min(map(lambda x: x[1], cords[1:])) + max(map(lambda x: x[1], cords[1:]))) / 2,
    (min(map(lambda x: x[2], cords[1:])) + max(map(lambda x: x[2], cords[1:]))) / 2,
]

file.close()
file = open(input("Введите имя выходного файла: "), "w")

# запись в файл
print(len(cords),file=file)
print(*center, file=file)

for cord in cords:
    print(*cord, file=file)

print(len(lines),file=file)

for line in lines:
    print(*line, file=file)

file.close() 
