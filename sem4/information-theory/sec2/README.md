# MATLAB Section 2 - Task Solutions (Pages 1-12)

## Page 1: Extract from 6th row, 3rd column
```matlab
x = data(6,3);
```

## Page 2: Extract last row, 3rd column
```matlab
y = data(end,3);
```

## Page 3: Extract second-last row, 3rd column
```matlab
z = data(end-1,3);
```

## Page 4: Extract 8th element (single index)
```matlab
% Direct method:
element8 = data(8);

% Using index variable:
idx = 8;
element8 = data(idx);
```

## Page 5: Create column vector from 2nd column
```matlab
density = data(:,2);
```

## Page 6: Extract last two columns
```matlab
volumes = data(:,end-1:end);
```

## Page 7: Get 6th element of density vector
```matlab
p = density(6);
```

## Page 8: Get elements 2-5 of density
```matlab
q = density(2:5);
```

## Page 9: Extract non-consecutive elements (bonus)
```matlab
selected_elements = density([1 3 6]);
```

## Page 10: Extract last column
```matlab
v2 = data(:,end);
```

## Page 11: Modify first element of v2
```matlab
v2(1) = 0.5;
```

## Page 12: Modify first row, last column
```matlab
data(1,end) = 0.5;
```

## Sample Data Matrix (for testing)
```matlab
data = [3.0000  0.5300  4.0753  NaN;
       18.0000 1.7800  6.6678  2.1328;
       19.0000 0.8600  1.5177  3.6852;
       20.0000 1.6000  3.6375  8.5389;
       21.0000 3.0000  4.7243 10.1570;
       23.0000 6.1100  9.0698  2.8739;
       38.0000 2.5400  5.3002  4.4508];
```
