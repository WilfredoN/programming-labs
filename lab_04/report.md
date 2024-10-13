**National Technical University "KhPI"**

**Educational and Scientific Instutute of Computer Science and Informational Technology**

**_Department of Computer Engineering and Programming_**

**Course:** **_Programming. Part1_**

**REPORT** on the laboratory work #4

**Topic:** _"Expressions"_

> **_Prepared by:_**
>
> Student of group KN-924e Nikita Afanasiev.
>
> **_Checked by:_**
>
> Associate Professor _Volodymyr SAVCHENKO_

# KHARKIV 2024

---

## Task 4

> Objective: Understand how to create a data set for testing and practice running code in a debugger.

### Command performed

```bash
git checkout main
git checkout -b lab_04
mkdir lab_04
cd lab_04
nvim main.cpp
...
g++ -g main.cpp -o main
gdb ./main
(gdb) break calculate_integer
(gdb) break calculate_float
run
./main > output.txt
git add .
git commit -m "feat: lab_04"
git push lab_04
```

### Algorithm
1. Created main.cpp.
2. Realized expression for float and int data types.
3. Use gdb debugger to see how code is working.
4. Write output into output.txt.
5. Generate a pdf version of the report.



### Debugger output
```zsh
Breakpoint 1, calculate_integer (a=2, b=3, c=4, d=1, e=6, f=2)
at main.cpp:10
10 return (int)(std::pow(a, 2) + b _ c - d) _ (e - (b / c) + a \* f)
- (gdb) step
  std::pow<int, int> (**x=2, **y=2) at /usr/include/c++/14.2.1/cmath:1077
  1077 return pow(**type(**x), **type(**y));
  (gdb) step
  Downloading source file /usr/src/debug/glibc/glibc/math/./w_pow_template.c
  0x00007ffff7eeadd2 in **pow (x=2, y=2) at ./w_pow_template.c:32  
  32 FLOAT z = M_SUF (**ieee754_pow) (x, y);
  (gdb) next
  33 if (**glibc_unlikely (!isfinite (z)))
  (gdb) next
  45 else if (**glibc_unlikely (z == 0) && isfinite (x) && x != 0 && isfinite (y))
  (gdb) next
  std::pow<int, int> (**x=2, **y=2) at /usr/include/c++/14.2.1/cmath:1078
  1078 }
  (gdb) next
  calculate_integer (a=2, b=3, c=4, d=1, e=6, f=2) at main.cpp:11
  11 (c + a _ d) + ((b _ e) / (c - d _ f));
  (gdb) next
  10 return (int)(std::pow(a, 2) + b _ c - d) _ (e - (b / c) + a _ f) -
  (gdb) next
  11 (c + a _ d) + ((b _ e) / (c - d \* f));
  (gdb) next
  12 }
  (gdb) next
  main () at main.cpp:20
  20 << std::endl;
  (gdb) next
  Integer Calculation 1: 153
  21 std::cout << "Integer Calculation 2: "
  (gdb) next
  22 << calculate_integer(int_a2, int_b2, int_c2, int_d2, int_e2, int_f2)
  (gdb) next
Breakpoint 1, calculate_integer (a=5, b=7, c=8, d=3, e=4, f=1) at main.cpp:10
10 return (int)(std::pow(a, 2) + b _ c - d) _ (e - (b / c) + a _ f) -
(gdb) next
11 (c + a _ d) + ((b _ e) / (c - d _ f));
(gdb) next
10 return (int)(std::pow(a, 2) + b _ c - d) _ (e - (b / c) + a _ f) -
(gdb) next
11 (c + a _ d) + ((b _ e) / (c - d _ f));
(gdb) next
12 }
(gdb) next
main () at main.cpp:23
23 << std::endl;
(gdb) step
Downloading source file /usr/src/debug/gcc/gcc-build/x86_64-pc-linux-gnu/libstdc++-v3/include/ostream
std::basic_ostream<char, std::char_traits<char> >::operator<< (this=0x555555558040 <std::cout@GLIBCXX_3.4>,  
 **pf=0x7ffff7d4fb90 <std::endl<char, std::char_traits<char> >(std::basic_ostream<char, std::char_traits<char> >&)>)
at /usr/src/debug/gcc/gcc-build/x86_64-pc-linux-gnu/libstdc++-v3/include/ostream:116
warning: 116 /usr/src/debug/gcc/gcc-build/x86_64-pc-linux-gnu/libstdc++-v3/include/ostream: No such file or directory
(gdb) next
std::endl<char, std::char_traits<char> > (**os=...) at /usr/src/debug/gcc/gcc-build/x86_64-pc-linux-gnu/libstdc++-v3/include/ostream:741
741 in /usr/src/debug/gcc/gcc-build/x86_64-pc-linux-gnu/libstdc++-v3/include/ostream
(gdb) next
742 in /usr/src/debug/gcc/gcc-build/x86_64-pc-linux-gnu/libstdc++-v3/include/ostream
(gdb) step
Downloading source file /usr/src/debug/gcc/gcc-build/x86_64-pc-linux-gnu/libstdc++-v3/include/bits/basic_ios.h
std::basic_ios<char, std::char_traits<char> >::widen (this=<optimized out>, **c=10 '\n')  
 at /usr/src/debug/gcc/gcc-build/x86_64-pc-linux-gnu/libstdc++-v3/include/bits/basic_ios.h:454
(gdb) step
std::**check_facet<std::ctype<char> > (**f=0x7ffff7e83920 <(anonymous namespace)::ctype_c>)
at /usr/src/debug/gcc/gcc-build/x86_64-pc-linux-gnu/libstdc++-v3/include/bits/basic_ios.h:47
47 in /usr/src/debug/gcc/gcc-build/x86_64-pc-linux-gnu/libstdc++-v3/include/bits/basic_ios.h
(gdb) next
Downloading source file /usr/src/debug/gcc/gcc-build/x86_64-pc-linux-gnu/libstdc++-v3/include/bits/locale_facets.h
(gdb) next
Integer Calculation 2: 684
warning: 763 /usr/src/debug/gcc/gcc-build/x86_64-pc-linux-gnu/libstdc++-v3/include/ostream: No such file or directory
(gdb) next
742 in /usr/src/debug/gcc/gcc-build/x86_64-pc-linux-gnu/libstdc++-v3/include/ostream  
(gdb) step
main () at main.cpp:25
25 float float_a1 = 1.0f, float_b1 = 2.0f, float_c1 = 3.0f, float_d1 = 4.0f,
(gdb) next
26 float_e1 = 5.0f, float_f1 = 6.0f;
(gdb) next
27 float float_a2 = 3.1f, float_b2 = 2.4f, float_c2 = 5.3f, float_d2 = 8.6f,
(gdb) next
28 float_e2 = 4.2f, float_f2 = 2.5f;
(gdb) next
30 std::cout << "Float Calculation 1: "
(gdb) next
32 float_f1)
(gdb) next

Breakpoint 2, calculate_float (a=1, b=2, c=3, d=4, e=5, f=6) at main.cpp:5
5 return (float)(std::powf(a, 2.0) + b _ c - d) _ (e - (b / c) + a _ f) -
(gdb) next
6 (c + a _ d) + ((b _ e) / (c - d _ f));
(gdb) next
5 return (float)(std::powf(a, 2.0) + b _ c - d) _ (e - (b / c) + a _ f) -
(gdb)
6 (c + a _ d) + ((b _ e) / (c - d _ f));
(gdb)
7 }
(gdb)
main () at main.cpp:33
33 << std::endl;
(gdb) next
Float Calculation 1: 23.5238
34 std::cout << "Float Calculation 2: "
(gdb) next
36 float_f2)
(gdb) next
Breakpoint 2, calculate_float (a=3.0999999, b=2.4000001, c=5.30000019, d=8.60000038, e=4.19999981, f=2.5) at main.cpp:5
5 return (float)(std::powf(a, 2.0) + b _ c - d) _ (e - (b / c) + a _ f) -
(gdb)
6 (c + a _ d) + ((b _ e) / (c - d _ f));
(gdb)
5 return (float)(std::powf(a, 2.0) + b _ c - d) _ (e - (b / c) + a _ f) -
(gdb)
6 (c + a _ d) + ((b _ e) / (c - d _ f));
(gdb)
7 }
(gdb)
main () at main.cpp:37
37 << std::endl;
(gdb)
Float Calculation 2: 125.274
38 return 0;
(gdb)
39 }
(gdb)
Downloading source file /usr/src/debug/glibc/glibc/csu/../sysdeps/nptl/libc_start_call_main.h
\_\_libc_start_call_main (main=main@entry=0x5555555552dd <main()>, argc=argc@entry=1, argv=argv@entry=0x7fffffffe388) at ../sysdeps/nptl/libc_start_call_main.h:74  
74 exit (result);
(gdb)
[Inferior 1 (process 24807) exited normally]
(gdb)
```