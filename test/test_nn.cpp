#include <iostream>
#include <sstream>
#include <fstream>
#include <assert.h>

#include "vector.hh"
#include "matrix.hh"
#include "sigmoid.hh"

#include "neural_network.hh"
#include "neural_network_io.hh"




void test_nn ( NNetwork< double > &nn )
{
  std::size_t rows = 16, cols = 5;
    nn.resize(rows,cols);
    NN_Initializor< double > initializor(rows,cols);
    nn.init(initializor);
    Vector< double> arg(cols), dest(rows);
    nn( arg, dest );
    nn.feedForward( arg, dest );

    NN_Random_Init<double> initRand(rows,cols, 42);
    nn.init( initRand );
    std::cout << nn.weights() << std::endl;
    nn.feedBackward(dest, arg );
}



int main ( int argc, char** argv )
{

    NNetwork< double > nn(4,2);
    test_nn(nn);

    return 0;
}
