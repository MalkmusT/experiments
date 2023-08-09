#include <iostream>

#include "neural_network.hh"
#include "neural_network_io.hh"
#include "vector.hh"
#include "lexer.hh"



// 4 chars of 
const std::size_t word_count = AlphaLexer::size() * 4; 
const std::size_t sum_length = HexLexer::size() * 8;


template<class ArgPars, class DestPars> 
void project( const std::vector<std::pair<std::string, std::string>> &vals, 
ArgPars argPars,
DestPars destPars,
std::vector< std::size_t > &argsIndex, 
std::vector< std::size_t > &destIndex )
{
    std::size_t size = vals.size();
    argsIndex.resize(size);
    destIndex.resize(size);
    for( std::size_t i =0 ; i<size; ++i)
    {
        auto e = vals[i];
        argsIndex[i] = argPars.forward(std::get<0>(e));
        destIndex[i] = destPars.forward(std::get<1>(e));
    }
}

void read_data ( std::string filename, std::vector<std::pair<std::string, std::string>> &vals )
{
    std::cout<<"opening file:"<<filename<<std::endl;
    std::ifstream file;
    file.open(filename);
    std::string val1, val2;
    while( file >> val1 >> val2 )
    {
        vals.push_back( std::make_pair( val1, val2 ));
    }
    std::cout<<"added "<< vals.size() << " lines" << std::endl;
}


int main ( int argc, char** argv )
{
    NNetwork< double > nn(word_count,sum_length);
    NN_Random_Init<double> initRand(word_count,sum_length, 42);
    nn.init( initRand );

    std::string filename = "train_data";
    std::vector<std::pair<std::string, std::string>> vals;
    read_data( filename, vals );

    std::vector<std::size_t> argIdx, destIdx;
    project( vals, AlphaLexer(), HexLexer(), argIdx, destIdx);
    
    return 0;
}