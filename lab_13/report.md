**Ministry of Education and Science of Ukraine**

**National Technical University "KhPI"**

**Educational and Scientific Institute of Computer Science and Informational Technology**

**_Department of Computer Engineering and Programming_**

**Course:** **_Programming. Part1_**

**REPORT** on the laboratory work #13 & #14

**Topic:** _"Single linked list. Text and binary read and write."_

> **_Prepared by:_**
>
> Student of group KN-924e Nikita Afanasiev.

> **_Checked by:_**
>
> Associate Professor _Volodymyr SAVCHENKO_

# KHARKIV 2024

---

## Task 13

### Explanation

> To create the single linked list, using the structures from the 11th lab.
> To modify the linked list to a double linked list.

### Command performed
```bash
    mkdir lab_13
    cd lab_13
    ...some magic...
    make
    valgrind --leak-check=full -s ./main
    make clean
```

## Task 14

### Explanation
> To create a program that reads the data created in Task 13 and writes it to a file in text and binary format. 

### Command performed
```bash
    cd lab_13
    ...some additional improvements...
    make
    valgrind --leak-check=full -s ./main_io
    make clean
```

### Tools:
- OS: `Ubuntu`
- Editor: `VS Code`