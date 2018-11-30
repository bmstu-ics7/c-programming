import matplotlib
matplotlib.use("TkAgg")
from matplotlib import pyplot as plt

f = open('graph.txt', 'r')

x = []
y1 = []
y2 = []

for line in f:
    xk, y1k, y2k = line.split()
    x.append(int(xk))
    y1.append(int(y1k))
    y2.append(int(y2k))

plt.title("strpbrk")
plt.xlabel('Размер строк (синяя - my_strpbrk, красная - strpbrk)')
plt.ylabel('Скорость работы')
plt.plot(x, y1, 'b')
plt.plot(x, y2, 'r')
plt.grid(True, linestyle='-', color='0.75')
plt.show()

f.close()

