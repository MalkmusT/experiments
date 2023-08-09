#include <iostream>
#include <sstream>
#include <fstream>
#include <assert.h>

#include "vector.hh"
#include "matrix.hh"
#include "sigmoid.hh"


void sigmoid_test ( const double &a, const Vector< double> &va, const Matrix< double> &ma)
{
  Sigmoid sigmoid;
  
  double a_copy(a);
  Vector< double > v_copy(va);
  Matrix< double > m_copy(ma);

  sigmoid( a_copy );
  double t = sigmoid(a);
  sigmoid( v_copy );
  Vector< double > tv = sigmoid(va);
  sigmoid( m_copy );
  Matrix< double > tm = sigmoid(ma);

  Sigmoid::Derivativ sig_prime;
  sig_prime( a_copy );
  double tp = sig_prime(a);
  sig_prime( v_copy );
  Vector< double > tpv = sig_prime(va);
  sig_prime( m_copy );
  Matrix< double > tpm = sig_prime(ma);
}



int main ( int argc, char** argv )
{
    Matrix<double> m(2,4);
    for(std::size_t i=0;i<2;++i)
        for(std::size_t j=0;j<4;++j)
            m[i][j] = i+j;

    Vector<double> v(15);
    for(std::size_t i=0;i<15;++i)
      v[i] = i;

    double a =123;
    sigmoid_test( a, v, m );

    return 0;
}
