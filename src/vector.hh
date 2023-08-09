#ifndef VECTOR_HH
#define VECTOR_HH

#include <istream>
#include <ostream>
#include <vector>


template<class T>
class Vector
{
  typedef Vector< T > ThisType;
public:
  typedef T FieldType;
  typedef std::vector< FieldType > DataType;

  Vector () {}

  Vector ( std::size_t n ) :
    data_( n )
  {}

  Vector ( std::size_t n, const T &t ) :
    data_(n, t)
  {}


  Vector ( const ThisType &other ) :
    data_( other.data_ )
  {}


  void resize (std::size_t n, const T &t = T(0) )
  {
      data_.clear();
      data_.resize(n, t);
  }

  void clear ()
  {
    for( auto & e : data_)
      e = T(0);
  }

  std::size_t size() const { return data_.size(); }

  FieldType& operator[] (std::size_t i) { return data_[i]; }
  const FieldType& operator[] (std::size_t i) const { return data_[i]; }

  DataType &data () { return data_; }
  const DataType &data () const { return data_; }

  FieldType operator* ( const ThisType & o) const
  {
    FieldType ret(0);
    for( std::size_t i=0; i < data_.size(); ++i )
      ret += data_[i] * o[i];
    return ret;
  }

  void operator* ( const FieldType &t )
  {
    for( std::size_t i=0; i < data_.size(); ++i )
      data_[i] *= t;
  }

  void operator/ ( const FieldType &t )
  {
    for( std::size_t i=0; i < data_.size(); ++i )
      data_[i] /= t;
  }

  ThisType operator+ ( const ThisType &other) const
  {
      ThisType ret( data_.size(), FieldType(0) );
      for( std::size_t i=0; i < data_.size(); ++i )
          ret[i] = data_[i] + other[i];
      return ret;
  }

  ThisType operator- ( const ThisType &other) const
  {
      ThisType ret( data_.size(), FieldType(0) );
      for( std::size_t i=0; i < data_.size(); ++i )
          ret[i] = data_[i] - other[i];
      return ret;
  }

  ThisType& operator-= ( const ThisType &other)
  {
      for( std::size_t i=0; i < data_.size(); ++i )
          data_[i] -= other[i];
      return *this;
  }

  ThisType& operator+= ( const ThisType &other)
  {
      for( std::size_t i=0; i < data_.size(); ++i )
          data_[i] += other[i];
      return *this;
  }

private:
  DataType data_;
};



// ostream
// -------

template<class T>
std::ostream &operator<<(std::ostream &os, const Vector<T> &in)
{
  for (std::size_t i = 0; i < in.size(); ++i) {
    os << in[i] << " ";
  }
  return os;
}


// istream
// -------

template<class T>
std::istream &operator>>(std::istream &is, Vector<T> &out)
{
  out.data().clear();

  T tmp;
  while( is >> tmp ) { out.data().push_back(tmp); }
  return is;
}

#endif // VECTOR_HH
