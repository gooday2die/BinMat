# BinMat
A binary matrix for C++ and C

## Motivation
### Traditional Way of Binary Matrices
```
bool matrix[10][10];
```
`bool` data type takes up `1 byte`. The Expression above will use `100 bytes`. It is well known fact that a single `byte` contains `8 bits`. However, in order to represent just `1 bit` using `bool` data type, the remaining `7 bits` are being wasted. 

### BinMat
```
BinMat* binMat = new BinMat(10, 10);
```
**BinMat** does a simple calculation for using as little data as possible. The expression above will give us access to a `10 * 10` matrix, however will cost us just `16 bytes`. 

## Usage
Using **BinMat** is easy. Download `BinMat.cpp` and `BinMat.h`. Then include those two files into the code that you would like to use **BinMat**. 

### Constructing a BinMat Object
```
BinMat::BinMat(uint32_t width, uint32_t height);
```
The constructor member function will automatically generate a matrix that satisfies the dimension that was requested.

### Retrieving a Value
```
uint8_t BinMat::get(uint32_t x, uint32_t y);
```
The `get` member function will return `uint8_t` type that represents the value from specific point of matrix that was requested. 

### Setting a Value
```
void BinMat::set(uint32_t x, uint32_t y, uint8_t value);
```
The `set` member function will set a point from matrix with the given value as argument. 

### Exceptions
```
BinMat::OutOfRangeException()
```
The `OutOfRangeException` will be raised when member function `get` or `set` is trying to retrieve or set a value to a position that is invalid and is out of boundary.
