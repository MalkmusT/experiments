#ifndef LEXER_HH
#define LEXER_HH


#include <map>
#include <string>
#include <vector>


template< class Alphabet >
struct BasicLexer 
{
  typedef std::string WordType;
  typedef std::vector< std::size_t > IndexType;

  static std::size_t forward ( char i ) { return Alphabet::forward( i ); }
  static char backward ( std::size_t i ) { return Alphabet::backward( i ); }

  static WordType backward ( const IndexType &is )
  {
    WordType ret; ret.resize(is.size());
    for(std::size_t i =0; i< is.size();++i)
      ret[i] = Alphabet::backward( is[i] );
    return ret;
  }

  static IndexType forward ( const WordType &is )
  {
    IndexType ret; ret.resize(is.size());
    for(std::size_t i =0; i< is.size();++i)
      ret[i] = Alphabet::forward( is[i] );
    return ret;
  }

  // thoese two should differ bewtween the implementations
  static std::size_t size() { return Alphabet::size; }
};


// convert [abc..012..9 ] to e in R^37

struct A2zPdAlphabet
{
  static const std::size_t size = 37;
  static const char backward ( std::size_t in ) { return vals_[in]; }
  static const std::size_t forward ( char in ) { 
    for( std::size_t i =0;i< size; ++i) 
      if (vals_[i] == in ) return i;
    return 0;
  }

  static constexpr char* vals_ = "0123456789abcdefghijklmnopqrstuvwxyz ";
};



typedef BasicLexer< A2zPdAlphabet > AlphaLexer;


struct HexAlphabet
{

  static const std::size_t size = 16;
  static const char backward ( std::size_t in ) { return vals_[in]; }
  static const std::size_t forward ( char in ) { 
    for( std::size_t i =0;i< size; ++i) 
      if (vals_[i] == in ) return i;
    return 0;
  }

  static constexpr char* vals_ = "0123456789abcdef";
};

typedef BasicLexer< HexAlphabet > HexLexer;



template< class T >
struct HashLexer
{
  typedef std::vector<T> WordType;
  typedef std::vector< std::size_t > IndexType;

  HashLexer () {}

  std::size_t add ( const T& t )
  {
    std::size_t k = vals_.size();
    vals_.push_back( t );
    valMap_[ t ] = k;
    return k;
  }

  std::size_t forward ( const T& i ) const { return valMap_[i]; }
  T backward ( std::size_t i ) const { return vals_[i]; }

  WordType backward ( const IndexType &is ) const
  {
    WordType ret; ret.resize(is.size());
    for(std::size_t i =0; i< is.size();++i)
      ret[i] = backward( is[i] );
    return ret;
  }

  IndexType forward ( const WordType &is ) const
  {
    IndexType ret; ret.resize(is.size());
    for(std::size_t i =0; i< is.size();++i)
      ret[i] = forward( is[i] );
    return ret;
  }

  // thoese two should differ bewtween the implementations
  std::size_t size() const { return vals_.size(); }
protected:
  std::vector< T > vals_;
  std::map< T, std::size_t > valMap_;
};
#endif // #ifndef LEXER_HH 
