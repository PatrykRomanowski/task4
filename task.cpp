#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <vector>
#include <chrono>

using namespace std;

std::fstream logFile; //handler for log file
long long counterBits = 0;



void saveLog(std::string msg)           // zapisanie logów
{
    std::string ss;
    time_t currentTime = time(NULL);
    std::string txttime = (std::string)asctime(localtime(&currentTime));
    txttime = txttime.substr(0, txttime.length() - 1);
    ss = (std::string)"T: " + txttime + " M: " + msg + "\n";
    logFile << ss.c_str();
    logFile.flush();
    std::cout << ss.c_str();
    std::cout.flush();
}


void createFile1(const std::string name, const int count, const char value)   // funkcja tworząca plik binarny
{
    std::fstream f;
    f.open(name.c_str(), std::ios::binary | std::ios::out);
    for (int i = 0; i < count; i++)
    {
        f.write((char*)&value,1);
    }
    f.close();
}

void openLog(std::string fileName)
{
    logFile.open(fileName.c_str(), std::ios_base::app);
    if (!logFile.good() == true)
    {
        std::cout << "Cannot open log file " << "log.txt" << std::endl;
    }
    saveLog("Log file opened");
}

void closeLog(void)
{
    saveLog("Log file closed");
    logFile.close();
}


uint8_t hammingDistance(uint8_t n1, uint8_t n2)    // funkcja porównująca zgodność bitów
{
    uint8_t x = n1 ^ n2; // XOR
    uint8_t setBits = 0;
    while (x > 0)
    {
        setBits += x & 1;
        x >>= 1;
    }
    counterBits += 8;
    return setBits;
}


main(int argc, char * argv[])                            // funkcja główna
{
    std::cout << "BER Calc v1.0" << std::endl;
    openLog("log.log");
    saveLog("Program uruchomiono poprawnie");

   // createFile1("file2.bin", 100, 0x55);

   string helloworld = "hello w3orld";
   long long BER = 0;
    
   ifstream plik1(argv[1], ios::binary);   // wczytywanie plików binarnych
   ifstream plik2(argv[2], ios::binary);
   std::vector<unsigned char> buffer(std::istreambuf_iterator<char>(plik1), {});
   std::vector<unsigned char> buffer2(std::istreambuf_iterator<char>(plik2), {});

if(sizeof(buffer) == sizeof(buffer2))
{
    auto begin = std::chrono::high_resolution_clock::now();    // włączenie timera

   for (int i=0; i<(sizeof(buffer)+1)*4; i++) 
   {
       BER += (int)hammingDistance(buffer[i], buffer2[i]);
   }

    auto end = std::chrono::high_resolution_clock::now(); // wyłączenie timera
    auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(end - begin); //porównanie czasów

    cout << "czas obliczeń: " << elapsed.count() << endl;

    cout <<"BER = " << BER << endl;
    cout <<"Sprawdzonych bitów = " << counterBits << endl;

    saveLog("Porównano plik: " +  static_cast<string>(argv[1]) + " z plikiem: " + static_cast<string>(argv[2]));
    saveLog("Sprawdzono bitów: " + to_string(counterBits));
    saveLog( "BER = " + to_string(BER));
    saveLog("Czas obliczeń wynosił: " + to_string(elapsed.count()) + " mili Sekund");

   // cout << "Program porównał plik: \"" + argv[2] + " z plikiem: " + argv[2] << endl;
   

   std::cout << "argc =  : " << argc - 1 << std::endl; 
    int iter = 0;
    for (iter = 1; iter < argc; iter++) {
        std::cout << "argv[" << iter << "] =" << argv[iter] << std::endl;
    }
    closeLog();
    
}
else
{
    cout << "pliki nie są tej samej wielkości" << endl;   //  sprawdzanie czy porównywane pliki są tej samej wielkości
}
    // std::cout << (int)hammingDistance(0xFF, 0x01) << std::endl; // wywołanie funkcji porównywającej zgodność bitow

}
