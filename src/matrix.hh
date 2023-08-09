#ifndef MATRIX_HH
#define MATRIX_HH

#include <ostream>

#include "vector.hh"


// Matrix
// ------

template< class T >
class Matrix
{
  typedef Matrix<T> ThisType;

public:

  typedef Vector<T> VectorType;
  typedef Vector< VectorType > DataType;

  Matrix () {}

  Matrix (std::size_t n, std::size_t m):
      n_(n),
      m_(m),
      rows_( n, VectorType(m, 0) )
  {}

  void resize ( std::size_t n, std::size_t m )
  {
      rows_.resize( n, VectorType(m,0));
      n_ = n;
      m_ = m;
  }

  std::size_t size () const { return n_; }
  std::size_t rows () const { return n_; }
  std::size_t cols () const { return m_; }

  void operator() ( const VectorType &arg, VectorType &dest ) const
  {
    dest.resize(n_);
    for( std::size_t i = 0; i < n_; ++i)
      dest[i] = rows_[i] * arg;
  }

  VectorType operator() ( const VectorType & arg ) const
  {
    VectorType ret(n_, 0);
    for( std::size_t i = 0; i < n_;++i)
      ret[i] = rows_[i] * arg;
    return ret;
  }

  VectorType & operator[] (std::size_t i)  { return rows_[i]; }
  const VectorType& operator[] (std::size_t i) const { return rows_[i]; }

  DataType &data () { return rows_; }
  const DataType &data () const { return rows_; }

  ThisType& operator*= ( T t )
  {
    for( std::size_t i=0; i < n_; ++i )
      rows_[i] *= t;
    return *this;
  }

  ThisType& operator/= ( T t )
  {
    for( std::size_t i=0; i < n_; ++i )
      rows_[i] /= t;
    return *this;
  }

  ThisType& operator-= ( const ThisType &other)
  {
    for( std::size_t i=0; i < n_; ++i )
      rows_[i] -= other[i];
    return *this;
  }

  ThisType& operator+= ( const ThisType &other)
  {
    for( std::size_t i=0; i < n_; ++i )
      rows_[i] += other[i];
    return *this;
  }

private:
  std::size_t n_;
  std::size_t m_;
  DataType rows_;
};


// ostream
// -------

template<class T>
std::ostream &operator<<(std::ostream &os, const Matrix<T> &input)
{
  for (std::size_t i = 0; i < input.size(); ++i) {
    os << input[i] << std::endl;
  }
  return os;
}


// istream
// -------

template< class T>
std::istream &operator>>(std::istream &is, Matrix<T> &out )
{
  out.data().data().clear();
  typename Matrix<T>::VectorType tmp;

  while( is >> tmp ) { 
    std::cout<<tmp <<std::endl;
    out.data().data().push_back(tmp); 
  }
  return is;
}


#endif // #ifndef MATRIX_HH
