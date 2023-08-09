#include <iostream>
#include <sstream>
#include <fstream>
#include <assert.h>

#include "vector.hh"
#include "matrix.hh"
#include "sigmoid.hh"

#include "neural_network.hh"
#include "neural_network_io.hh"

#include "lexer.hh"



void matrix_test ( Matrix<double> &m )
{
  Matrix<double> mcopy(m);

  assert( ( m.size() == mcopy.size() ) );
  assert( m.rows() == mcopy.rows() );
  assert( m.cols() == mcopy.cols() );
  mcopy.resize(2,1);

  assert( m.rows() != mcopy.rows() );
  assert( m.cols() != mcopy.cols() );

  Vector<double> v1, v2;
  v1.resize( m.cols() );
  m(v1, v2);

  std::cout<<m <<std::endl;
  std::stringstream file;
  file << m ;
  file >> mcopy;

  std::cout<<mcopy <<std::endl;
}

void vector_test ( Vector<double> &v )
{
  Vector<double> v_copy(v);
  assert( v_copy.size() == v.size() );
  double d = v * v_copy;

  v_copy.resize( 1 );
  assert( v_copy.size() != v.size() );

  std::stringstream file;
  file << v;
  file >> v_copy;
}

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
}



int main ( int argc, char** argv )
{

    NNetwork< double > nn(4,2);
    test_nn(nn);

    return 0;
}
