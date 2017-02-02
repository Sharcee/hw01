#include <vector>
#include <iostream>
#include <string>

using namespace std;

std::string path_field(std::string& x);
std::vector<int> path_nodes(const string & path);
void print_nodes(const std::vector<int> &v);

int main() {
    std::string str = "";
    std::string path = "";
    std::vector<int> nodes;

    while ( getline(cin, str) ) {
        std::cout << "**** Begin Tests ****" << "\n";
        std::cout << str << "\n";       // Print test
        path = path_field(str);
        std::cout << "PATH_FIELD: " << path << "\n\n";
        nodes = path_nodes(path);
        print_nodes(nodes);
        std::cout << "**** End of Tests ****" << "\n" << endl;
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

std::vector<int> path_nodes(const string & path) {
    std::vector<int> nodes;
    std::string node = "";
    std::string prev = "";

    for (auto& c : path) {
        if( c == ' ') {
            if ( prev == node ) {
                std::cout << "Duplicate Node Detected" << "\n";
                node.clear();
                continue;
            }
            std::cout << "Pushing NODE: " << node << "\n";
            nodes.push_back(atoi(node.c_str()));
            prev = node;
            node.clear();
            continue;
        }
        if ( c == '[') {
            break;
        }
        node += c;
    }

    return nodes;
}

void print_nodes(const std::vector<int> &v) {
    std::cout << "Path: ";
    for (std::vector<int>::const_iterator i = v.begin(); i != v.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << endl;
}
