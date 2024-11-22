**National Technical University "KhPI"**

**Educational and Scientific Instutute of Computer Science and Informational Technology**

**_Department of Computer Engineering and Programming_**

**Course:** **_Programming. Part1_**

**REPORT** on the laboratory work #5

**Topic:** _"Expressions (II)"_

> **_Prepared by:_**
>
> Student of group KN-924e Nikita Afanasiev.
>
> **_Checked by:_**
>
> Associate Professor _Volodymyr SAVCHENKO_

# KHARKIV 2024

---

## Task 5

> Objective: To calculate complex expressions using standard C mathematical functions.
> Option: 4.

### Command performed

```bash
git checkout -b lab_05
mkdir lab_05
cd lab_05
nvim main.cpp
...
g++ -g main.cpp -o main
./main
git add .
git commit -m "feat: lab_05"
git push lab_05
```

### Algorithm

1. Created lab 5 branch with main.cpp inside of its directory
2. Realized expression execution for several sets
3. Wrote input/output into output.txt
4. Provide analysis of the expression and possible invalid values
5. Generated a pdf report

---

### Analysis

The expression being evaluated is:
`y = (atan(a) / exp(b * cos(c))) + (log2(d + 1))^(1/3)`

#### Possible Invalid Values:
1. **Division by Zero**: The denominator exp(b * cos(c)) should never be zero. Since the exponential function is always positive, this scenario is avoided.
2. **Logarithm Domain Error**: The term log2(d + 1) requires d + 1 > 0. Thus, d must be greater than -1.
3. **Complex Numbers**: The cube root of a negative number will result in a complex number. Therefore, log2(d + 1) should be non-negative to avoid complex results.

#### Example Sets:
- **Set 1**: a = 2.0, b = 3.0, c = 4.0, d = 5.0
- **Set 2**: a = 3.0, b = 2.0, c = 1.0, d = 4.0
- **Set 3**: a = 5.0, b = 15.0, c = 2.0, d = 1.0

All these sets are valid as they do not violate the conditions mentioned above.

