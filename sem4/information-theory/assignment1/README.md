
# Assignment 1 MATLAB Solutions

This repository contains the solutions to the MATLAB questions in Assignment 1. Below are the solutions for each question:

---

## Q1: Matrix Operations

```matlab
M = [12 -4 5; 23 0 -100; 2 45 6];

second_row = M(2,:);

M(3,1) = 78;

M(:,2) = M(:,3);
```

---

## Q2: Replace Negative Values with Zero

```matlab
V = [1 -5 8 -9 -2];
for i = 1:length(V)
    if V(i) < 0
        V(i) = 0;
    end
end
```

---

## Q3: Loop to Display Numbers

```matlab
N = input('Enter a number: ');
for i = 1:N
    disp(i)
end
```

---

## Q4: Extract Even Numbers from a Vector

```matlab
V = [3 6 9 12 15 18 21];
even_numbers = [];
for i = 1:length(V)
    if mod(V(i), 2) == 0
        even_numbers = [even_numbers, V(i)];
    end
end
```

---

## Q5: Remove the Second Row from Matrix `A`

```matlab
A(2,:) = [];
```

