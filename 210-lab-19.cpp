#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <ctime>
using namespace std;

struct Node {
    double rating;
    string comment;
    Node* next;
};

class Movie {
    string title;
    Node* head;

public: 
    Movie(string t) {
        title = t;
    }

    string getTitle(); 

};
int main()
{
    std::cout << "Hello World!\n";
}
