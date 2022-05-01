#include <iostream>
#include <fstream>
#include <ctime>


using namespace std;

std::fstream logFile; //handler for log file


void saveLog(std::string msg)
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



main(int argc, char * argv[])
{
    std::cout << "BER Calc v1.0" << std::endl;
    openLog("log.log");
    saveLog("Program uruchomiono poprawnie");
    closeLog();


  string helloworld = "hello w3orld";

   cout << helloworld << endl;

   std::cout << "argc =  : " << argc << std::endl; 
    int iter = 0;
    for (iter = 0; iter < argc; iter++) {
        std::cout << "argv[" << iter << "] =" << argv[iter] << std::endl;
    }

}