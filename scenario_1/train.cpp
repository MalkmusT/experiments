#include <iostream>

#include "neural_network.hh"
#include "neural_network_io.hh"
#include "vector.hh"
#include "lexer.hh"



// 4 chars of 
const std::size_t word_count = AlphaLexer::size() * 4; 
const std::size_t sum_length = HexLexer::size() * 8;


void train ( const std::string &filename, NNetwork< double >&nn )
{
  NNetwork< double >::ArgumentType arg(word_count);
  NNetwork< double >::ObjectType dest(sum_length);

  std::ifstream file;
  file.open(filename);
  std::string val1, val2;
  while( file >> val1 >> val2 )
  {
    arg.clear(); 
    dest.clear();
    for(auto e : AlphaLexer::forward(val1)) 
      arg[e] = 1.0;
    for(auto e : HexLexer::forward(val2))
      dest[e] = 1.0;
    nn.feedBackward( arg, dest );
  }
}


int main ( int argc, char** argv )
{
    NNetwork< double > nn(word_count,sum_length);

    NN_Random_Init<double> initRand(word_count,sum_length, 42);
    nn.init( initRand );

    std::string filename = "train_data";
    train( filename, nn ); 

    std::cout << nn.weights() <<std::endl;
    std::cout << nn.bias() << std::endl;
    return 0;
}
