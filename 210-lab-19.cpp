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

string getTitle(){
    return title;
}

void addRev(double rating, string comment) {
    Node* newReview = new Node;
    newReview->rating = rating;
    newReview->comment = comment;
    newReview->next = nullptr;

    if (!head) { //if list empty, make new review head
        head = newReview;
    }
    else { //otherwise, set new review to be before head, make it new head
        newReview->next = head;
        head = newReview;
    }
}
void outputRevs() {
    if (!head) { //check for empty list
        cout << "No reviews" << endl;
        return;
    }
    Node* traverse = head; //node for traversing list
    int count = 0;
    double total = 0;

    cout << "Outputting all reviews: " << endl;
    while (traverse) { //while traverse isn't beyond tail
        cout << "\t> Review #" << ++count << ": " << traverse->rating
            << ": " << traverse->comment << endl;
        total += traverse->rating;
        traverse = traverse->next;
    }

    cout << "\t> Average: " << (total / count) << endl;
}

double randrating() {
    return(rand() % 41 + 10) / 10.0; // rand()%(max-min+1) + min
}
