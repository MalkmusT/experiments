#ifndef NEURAL_NETWORK_IO_HH
#define NEURAL_NETWORK_IO_HH

#include <cstdlib>
#include <iostream>

#include "vector.hh"
#include "matrix.hh"


template< class T >
class NN_Random_Init
{
  public:
    NN_Random_Init ( std::size_t rows, std::size_t cols, std::size_t seed = 1 ) :
      rows_( rows ),
      cols_( cols )
    {
      std::srand(seed);
    }
    // number of layers
    std::size_t layers () const { return 1;}

    // tuple of dimensions per layer
    std::tuple< std::size_t, std::size_t > size ( std::size_t layer ) const { return std::make_tuple( rows_, cols_ ); }

    // values per layer, biases 
    T operator() ( std::size_t l, std::size_t i ) const { return T( std::rand() ); }
    T operator() ( std::size_t l, std::size_t i, std::size_t j ) const { return T( std::rand() ); }
  private:
    std::size_t rows_, cols_;
};


template< class T >
class NN_InitFromFile
{
  public:
    NN_InitFromFile ( const std::string &wFile, const std::string &bFile )
    {
      std::ifstream file; 
      file.open( wFile );
      file >> weights_ ;
      file.close();
      file.open( bFile );
      file >> bias_;
      file.close();
    }

    std::size_t layers () const { return 1;}


    T operator() ( std::size_t i ) const { return bias_[i]; }
    T operator() ( std::size_t i, std::size_t j ) const { return weights_[i][j]; }

  private:
    Matrix<T> weights_;
    Vector<T> bias_;
};


#endif // #ifndef NEURAL_NETWORK_IO_HH
