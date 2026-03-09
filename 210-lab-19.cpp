#include <iostream>
#include <fstream>
#include <string>
#include <array>
#include <ctime>
using namespace std;

const int NUM_COMMENTS = 12;
const int NUM_MOVIES = 4;

struct Node {
    double rating;
    string comment;
    Node* next;
};

class Movie {
    string title;
    Node* head;

public: 
    Movie() { //default constructor
        title = "";
        head = nullptr;
    }
    Movie(string t) { //partial constructor
        title = t;
        head = nullptr;
    }

    string getTitle(); //return title
    void addRev(double, string); //adds review to linked list
    void outputRevs(); //outputs reviews 

};

double randRating();
void finComments(array<string, NUM_COMMENTS>&); //reads comments from file and populates array

int main()
{
    srand(time(0)); //seeds random number generator
    array<string, NUM_COMMENTS> comments; //declare array and populate
    finComments(comments);

    array<Movie, NUM_MOVIES> movies; //array of 4 movie objects
    movies[0] = Movie("Nemo");
    movies[1] = Movie("Star Wars");
    movies[2] = Movie("Bullet Train");
    movies[3] = Movie("Mission Impossible");

    int commentIndex = 0; //assigns 3 reviews per movie, ranodm ratings, comments from file
    for (int i = 0; i < NUM_MOVIES; i++) {
        for (int j = 0; j < 3; j++) {
            movies[i].addRev(randRating(), comments[commentIndex++]);
        }
    }

    for (int i = 0; i < NUM_MOVIES; i++) {
        cout << "Title: " << movies[i].getTitle() << endl;
        movies[i].outputRevs();
        cout << endl;
    }


}

string Movie::getTitle(){
    return title;
}

void Movie::addRev(double rating, string comment) {
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
void Movie::outputRevs() {
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

double randRating() {
    return(rand() % 41 + 10) / 10.0; // rand()%(max-min+1) + min
}

void finComments(array<string, NUM_COMMENTS>& comments) {
    ifstream fin;
    fin.open("comments.txt");
    string buf;
    if (fin.good()) {
        for (int i = 0; i < NUM_COMMENTS; i++) {
            getline(fin, comments[i]);
        }
        fin.close();
    }
    else {
        cout << "File not found" << endl;
    }
}
