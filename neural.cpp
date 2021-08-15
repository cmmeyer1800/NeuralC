#include <iostream>
#include <string>
#include "neural.hpp"
#include "matrices.hpp"

Dense_Layer::Dense_Layer(int n_inputs){
    weights = rand_mat(n_inputs, 1);
    biases = set_mat(new_matrix(n_inputs, 1), 0.0);
}

Dense_Layer::Dense_Layer(Matrix *weights, Matrix *biases){
    weights = weights;
    biases = biases;
}

void Dense_Layer::forward(Matrix * inputs){
    Matrix *bef_bias = dot(inputs, weights);
    node_values = add_mats(bef_bias, transpose(biases));
}

Matrix * Dense_Layer::get_output(){
    return node_values;
}

int main(){
    init_mat_gen();
    Matrix *inputs = set_mat(new_matrix(1, 2), 5.0);
    Dense_Layer lay(2);
    lay.forward(inputs);
    prnt_mat(lay.get_output());
}