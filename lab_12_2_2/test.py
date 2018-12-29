from ctypes import *
from random import randint

def fibb_arr_test1():
    a = [0] * 12
    a = (c_int * len(a))(*a)
    size = 12

    libc.fibb_arr(a, size)

    print("fibb_arr_test1: ")
    libc.print_array(a, size)
    print()

def fibb_arr_test2():
    a = [0] * 20
    a = (c_int * len(a))(*a)
    size = 20

    libc.fibb_arr(a, size)

    print("fibb_arr_test1: ")
    libc.print_array(a, size)
    print()

def fibb_arr_test3():
    a = [0]
    a = (c_int * len(a))(*a)
    size = 1

    libc.fibb_arr(a, size)

    print("fibb_arr_test3: ")
    libc.print_array(a, size)
    print()

def cp_test1():
    a = [randint(1, 10) for i in range(80)]
    a = (c_int * len(a))(*a)
    size = 80

    new_a = [0] * 80
    new_a = (c_int * len(new_a))(*new_a)
    new_size = [0]
    new_size = (c_int * len(new_size))(*new_size)

    libc.cp_no_dublicates(new_a, a, new_size, size)

    print("cp_test1:")
    libc.print_array(new_a, new_size[0])
    print()

def cp_test2():
    a = [randint(10, 15) for i in range(30)]
    a = (c_int * len(a))(*a)
    size = 30

    new_a = [0] * 30
    new_a = (c_int * len(new_a))(*new_a)
    new_size = [0]
    new_size = (c_int * len(new_size))(*new_size)

    libc.cp_no_dublicates(new_a, a, new_size, size)

    print("cp_test2:")
    libc.print_array(new_a, new_size[0])
    print()

def cp_test3():
    a = [3] * 10
    a = (c_int * len(a))(*a)
    size = 10

    new_a = [0] * 10
    new_a = (c_int * len(new_a))(*new_a)
    new_size = [0]
    new_size = (c_int * len(new_size))(*new_size)

    libc.cp_no_dublicates(new_a, a, new_size, size)

    print("cp_test3:")
    libc.print_array(new_a, new_size[0])
    print()

def cp_test4():
    a = [i for i in range(30)]
    a = (c_int * len(a))(*a)
    size = 30

    new_a = [0] * 30
    new_a = (c_int * len(new_a))(*new_a)
    new_size = [0]
    new_size = (c_int * len(new_size))(*new_size)

    libc.cp_no_dublicates(new_a, a, new_size, size)

    print("cp_test4:")
    libc.print_array(new_a, new_size[0])
    print()

def main():
    global libc
    libc = CDLL("array.dll")

    fibb_arr_test1()
    fibb_arr_test2()

    cp_test1()
    cp_test2()
    cp_test3()
    cp_test4()

if __name__ == "__main__":
    main()

