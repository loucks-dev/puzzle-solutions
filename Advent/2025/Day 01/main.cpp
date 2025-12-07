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

            // passes over zero can be determined by taking our start number and...?
                  // its a comparison of the start number and the substring on each line, so...
                  // lets say we have line L1000 and dialCurrent is 50.
                    // this passes over 0 10 times and ends at 50.
                  // say dialCurrent is 98 and we have line R4. This passes over 0 once and ends at 102.
                  // we can tell it passed over in the second case by comparing the start to the end, but...
                    // how do we know when its looped many times?
                        // can we take the initial dialCurrent - line and, 
                            // if its gone under 0 or above 100, divide by 100. result should be how many times it passed
