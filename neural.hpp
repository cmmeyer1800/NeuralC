#ifndef NEURAL_HPP_
#define NEURAL_HPP_

#include "matrices.hpp"

int main();

class Dense_Layer{
    private:
        Matrix *weights;
        Matrix *biases;
        Matrix *node_values;
    public:
        Dense_Layer(Matrix *weights, Matrix *biases);
        Dense_Layer(int n_inputs);
        void forward(Matrix * inputs);
        Matrix * get_output();
};

#endif