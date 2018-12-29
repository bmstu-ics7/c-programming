import matplotlib
matplotlib.use("TkAgg")
from matplotlib import pyplot as plt

def graph(name):
    f = open(name, 'r')

    temp = []
    year = []

    for line in f:
        y, t = line.split()
        temp.append(float(t))
        year.append(int(y))

    plt.title(name[:3])
    plt.xlabel("Год")
    plt.ylabel("Средняя темпераура за лето")
    plt.plot(year, temp, 'y')
    plt.grid(True, linestyle='-', color='0.75')
    plt.show()

    f.close()

def main():
    graph("EKB.out")
    graph("SPB.out")
    graph("STC.out")

if __name__ == "__main__":
    main()

