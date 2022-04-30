#include <iostream>
using namespace std;


main(int argc, char * argv[])
{
  string helloworld = "hello w3orld";

   cout << helloworld << endl;

   std::cout << "argc =  : " << argc << std::endl; 
    int iter = 0;
    for (iter = 0; iter < argc; iter++) {
        std::cout << "argv[" << iter << "] =" << argv[iter] << std::endl;
    }

}