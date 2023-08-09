#ifndef NEURAL_NETWORK_IO_HH
#define NEURAL_NETWORK_IO_HH

#include <tuple>
#include <cstdlib>
#include <fstream>
#include <iostream>

#include "vector.hh"
#include "matrix.hh"




// NN_Initializor
// --------------

//
// sets T(i) to bias[i]
// sets T(i+j) to weight[i+j]
//

template< class T >
class NN_Initializor
{
  typedef Matrix<T> WeightsType;
  typedef Vector<T> BiasType;

public:
  NN_Initializor ( std::size_t rows, std::size_t cols ) :
    w_( rows, cols ),
    b_( rows )
  {
    for( std::size_t i = 0; i <rows; ++i )
    {
      b_[i] = T(i);
      for( std::size_t j = 0; j < cols; ++j )
        w_[i][j] = T(i+j);
    }
  }

  // number of layers
  std::size_t layers () const { return 1; }

  // tuple of dimensions per layer
  std::tuple< std::size_t, std::size_t > size ( std::size_t layer ) const { return std::make_tuple( w_.rows(), w_.cols() ); }

  // biases of layer l
  const BiasType &bias ( std::size_t l ) const { return b_; }

  // weights of layer l
  const WeightsType &weights ( std::size_t l ) const { return w_; }

private:
  WeightsType w_;
  BiasType b_;
};


// NN_Random_Init
// ---------------

//
// sets rand() to bias[i]
// sets rand() to weight[i+j]
//

template< class T >
class NN_Random_Init
{
  typedef Matrix<T> WeightsType;
  typedef Vector<T> BiasType;

public:
  NN_Random_Init ( std::size_t rows, std::size_t cols, std::size_t seed = 1 ) :
    w_( rows, cols ),
    b_( rows )
  {
    std::srand(seed);
    for( std::size_t i = 0; i <rows; ++i )
    {
      b_[i] = std::rand();
      for( std::size_t j = 0; j < cols; ++j )
        w_[i][j] = std::rand();
    }
  }

  // number of layers
  std::size_t layers () const { return 1; }

  // tuple of dimensions per layer
  std::tuple< std::size_t, std::size_t > size ( std::size_t layer ) const { return std::make_tuple( w_.rows(), w_.cols() ); }

  // biases of layer l
  const BiasType &bias ( std::size_t l ) const { return b_; }

  // weights of layer l
  const WeightsType &weights ( std::size_t l ) const { return w_; }

private:
  WeightsType w_;
  BiasType b_;
};


template< class T >
class NN_InitFromFile
{
  typedef Matrix<T> WeightsType;
  typedef Vector<T> BiasType;

public:
  NN_InitFromFile ( const std::string &wFile, const std::string &bFile )
  {
    std::ifstream file;
    file.open( wFile );
    file >> w_ ;
    file.close();
    file.open( bFile );
    file >> b_;
    file.close();
  }

  // number of layers
  std::size_t layers () const { return 1; }

  // tuple of dimensions per layer
  std::tuple< std::size_t, std::size_t > size ( std::size_t layer ) const { return std::make_tuple( w_.rows(), w_.cols() ); }

  // biases of layer l
  const BiasType &bias ( std::size_t l ) const { return b_; }

  // weights of layer l
  const WeightsType &weights ( std::size_t l ) const { return w_; }

private:
  WeightsType w_;
  BiasType b_;
};


#endif // #ifndef NEURAL_NETWORK_IO_HH
