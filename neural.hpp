#ifndef NEURAL_HPP_
#define NEURAL_HPP_

#include "matrices.hpp"

class Dense_Layer{
    Matrix *weights;
    Matrix *biases;
    Matrix *output;
    public:
        Dense_Layer(Matrix *weights, Matrix *biases);
        Dense_Layer(int n_inputs, int n_neurons);
        void forward(Matrix * inputs);
        Matrix * get_output();
};

class ReLU{
    Matrix * output;
    public:
        void forward(Matrix * input);
        Matrix * get_output();
};

#endif