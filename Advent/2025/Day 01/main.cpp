#include <fstream>
#include <string>
#include <iostream>

int safeCracker(std::ifstream& inputFile){
    int ans = 0, dialCurrent = 50;
    std::string line;
    while (std::getline(inputFile, line)){
        if (line[0] == 'R'){
            dialCurrent = ((dialCurrent + std::stoi(line.substr(1)) % 100)+100) % 100;
             if (dialCurrent == 0){
                ans++;
             }      
        }
        else if (line[0] == 'L'){
            dialCurrent = ((dialCurrent - std::stoi(line.substr(1)) % 100) + 100) % 100;
            if (dialCurrent == 0){
                ans++;
            }
        }
        std::cout << dialCurrent << std::endl;
    }
    return ans;
}

int main(){
    std::ifstream file("data.txt");
    std::cout << "ANSWER:" << safeCracker(file);
    
    return 0;
}
