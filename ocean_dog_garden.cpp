#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Breakthrough {

private:

    // Create a map for tracking ideas
    map<string, int> ideas;
    // Create a vector for tracking the ideas
    vector<string> innovation;

public:

    Breakthrough() {
        cout << "Welcome to the Breakthrough Innovation system!" << endl;
    }

    // Add an idea
    void insert(string concept) {
        // Check if the idea exists in ideas map first
        if (ideas.find(concept) == ideas.end()) {
            // Add the idea to the ideas map
            ideas.insert({concept, 1});
            // Add the idea to the innovation vector
            innovation.push_back(concept);
        } else {
            // Increment the count of that idea in the ideas map
            ideas[concept]++;
        }
    }

    // Remove an idea
    void remove(string concept) {
        // Check if the idea exists in ideas map
        if (ideas.find(concept) != ideas.end()) {
            // Decrement the count of the idea in ideas map
            ideas[concept]--;
            // Check if the count of that idea is 0
            if (ideas[concept] == 0) {
                // Remove the idea from ideas map
                ideas.erase(concept);
                // Remove the idea from the innovation vector
                innovation.erase(std::remove(innovation.begin(), innovation.end(), concept), innovation.end());
            }
        }
    }

    // List the ideas
    void list_ideas() {
        cout << "Ideas currently in the Breakthrough Idea System:" << endl;
        for (auto idea : innovation) {
            cout << idea << " - Count: " << ideas[idea] << endl;
        }
    }

    // Check if an element exists in the idea system
    bool exists_in_system(string concept) {
        return ideas.find(concept) != ideas.end();
    }

};

int main() {
    // Create Breakthrough instance
    Breakthrough breakthrough;
    // Insert some ideas
    breakthrough.insert("AI-based driverless cars");
    breakthrough.insert("Smart homes");
    breakthrough.insert("Virtual reality gaming");
    // List the ideas
    breakthrough.list_ideas();
    // Remove an idea
    breakthrough.remove("AI-based driverless cars");
    // List the ideas
    breakthrough.list_ideas();
    // Check if an element exists in the idea system
    if (breakthrough.exists_in_system("AI-based driverless cars")) {
        cout << "AI-based driverless cars exists in the system." << endl;
    } else {
        cout << "AI-based driverless cars does not exist in the system." << endl;
    }
    return 0;
}