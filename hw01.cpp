// Simon Aizpurua
// Assignment 01

#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>

using namespace std;

// Typedefs
typedef std::map<int, std::vector<int>> Map;

// Functions Declarations
std::string path_field(std::string& x);
std::vector<int> path_nodes(const string & path);
void print_nodes(const std::vector<int> &v, const char& c = ' ');
void insert_node(Map& m, const int & k, const int & v);
void printMap( const Map& m );

struct vec_sizecmp {
    bool operator()(const pair<int, std::vector<int>> &lhs, const pair<int, std::vector<int>> &rhs) {
        if ( lhs.second.size() == rhs.second.size() )
            return lhs.first < rhs.first;
        else
            return lhs.second.size() > rhs.second.size();
    }
};


int main() {
    std::string str = "";
    std::string path = "";

    std::vector<int> nodes;
    Map m;

    while ( getline(cin, str) ) {
        // std::cout << "********* Begin Tests *********" << "\n";
        // std::cout << str << "\n";       // Print test

        path = path_field(str);
        // std::cout << "PATH_FIELD: " << path << "\n\n";

        nodes = path_nodes(path);
        // print_nodes(nodes);

        for (auto iter = nodes.begin(); iter != nodes.end(); ++iter) {
            auto next = std::next(iter);
            if ( next == nodes.end() ) {
                continue;
            } else {
                insert_node(m, *iter, *next);
                insert_node(m, *next, *iter);
            }
        }

        // std::cout << "********* End of Tests *********" << "\n" << endl;
    }

    // std::cout << "\n********* Printing Map *********" << "\n" << endl;
    printMap(m);

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
    std::stringstream stream(path);

    int n;
    while ( stream >> n ) {
        // std::cout << "Found node:" << n << "\n"; //Parsing through node
        nodes.push_back(n);
    }
    return nodes;
}

void print_nodes(const std::vector<int> &v, const char& c) {
    // std::cout << "Path: ";
    std::vector<int> temp = v;
    sort(temp.begin(), temp.end());

    for (std::vector<int>::const_iterator i = temp.begin(); i != temp.end(); ++i) {
        if(std::next(i) == temp.end())
            std::cout << *i;
        else
            std::cout << *i << c;
    }
    std::cout << endl;
}

void insert_node(Map& m, const int & k, const int & v) {
    std::vector<int> temp;
    // If node K is not in map, add it and add K+1 as a neighbor
    if ( m.find(k) == m.end() ) {
        temp.push_back(v);
        m.emplace(make_pair(k, temp));
        temp.clear();
    }

    // Add node V as a neighbor to node K if NOT already listed
    if ( std::find(m[k].begin(), m[k].end(), v) == m[k].end() ) {
        m[k].push_back(v);
    }
}

void printMap( const Map& m ) {
    std::vector<std::pair<int, std::vector<int>>> v;
    for (auto& it : m) {
        v.push_back(pair<int, std::vector<int>> ( it.first, it.second ));
    }
    sort(v.begin(), v.end(), vec_sizecmp());

    for (uint i = 0; i < v.size(); ++i) {
        std::cout << v[i].first << " " << v[i].second.size() << " ";
        print_nodes( v[i].second, '|' );
        // std::cout << std::endl;
    }
}
