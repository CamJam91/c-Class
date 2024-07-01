#include <fstream>
#include <iostream>
#include<filesystem>
using namespace std;

int main() {
    // Change the path to the desired location
    filesystem::path testPath {"\\example.txt"};
    
    std::ofstream outfile(testPath);
    if (outfile.is_open()) {
        outfile << "Hello, World!" << std::endl;
        outfile.close();
        std::cout << "File created successfully at " << filesystem::current_path() << std::endl;
    } else {
        std::cerr << "Error: Could not create file." << std::endl;
    }

    return 0;
}
