# NeuralC
Neural network library in c++

This is a small scale c++ library in order to build and run neural networks.
While it will certainly not be as fast as mainstream libraries, this point is to learn the exact
math and concepts or neural networks.

In order to move data around to create the network we use many matrices. For this, a structure and functions to create matrices and manipulate
them is in matrices.cpp. This was originally written in c and moved to cpp for modernizing.

All Matrices are manipulated through pointers to these structs created in these ways:
```
Matrix * mat; for uninitiated
Matrix * mat = new_mat(dim0, dim1); for initiated with given size
Matrix * mat = rand_mat(dim0, dim1); for initiated to value [0,1] with given size
```
