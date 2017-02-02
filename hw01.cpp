#include <vector>
#include <iostream>
#include <string>

using namespace std;
std::string path_field(std::string& x);

int main() {
    std::string str = "";
    std::string path = "";

    while ( getline(cin, str) ) {
        std::cout << str << "\n";       // Print test
        path = path_field(str);
        std::cout << "PATH_FIELD: " << path << "\n\n";
    }

    return 0;
}

std::string path_field(std::string& x) {
    auto count = 0;
    std::string path = "";

    for (char& c : x) {
        if ( c == '|' ) {
            count++;
            continue;
        }
        if ( count == 6 ) {
            // std::cout << c;  // print aspath field
            path += c;
        }
        if ( count == 7 ) {
            break;
        }
    }
    return path;
}

// std::vector<int> name(/* arguments */) {
//     /* code */
//     return 0;
// }
