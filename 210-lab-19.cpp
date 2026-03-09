#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <ctime>
using namespace std;

const int NUM_COMMENTS = 12;
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
    void addRev(double, string);
    void outputRevs();
};

double randrating();
void finComments(array<string, NUM_COMMENTS>&);
int main()
{
    std::cout << "Hello World!\n";
}
