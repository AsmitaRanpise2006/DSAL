#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

class flight {
    int m[20][20], n, i, j; 
    char ch;  
    string v[20];

public:
    flight() { 
        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 20; j++)
                m[i][j] = 0;
    }

    void getgraph();
    void displaym();
};

void flight::getgraph() {
    cout << "\nEnter the number of cities (max. 20): ";
    cin >> n;

    if (n > 20) {
        cout << "\nError: Maximum limit of cities is 20.";
        return;
    }

    cout << "\nEnter the names of the cities: ";
    for (i = 0; i < n; i++)
        cin >> v[i];

        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) { 
                do {
                    cout << "\nIs there a path between " << v[i] << " and " << v[j] << "? (y/n): ";
                    cin >> ch;
                    if (ch == 'y') {
                        cout << "\nEnter time required to reach " << v[j] << " from " << v[i] << " (in minutes): ";
                        cin >> m[i][j];
                        m[j][i] = m[i][j]; 
                        break;
                    } 
                    else if (ch == 'n') {
                        m[i][j] = m[j][i] = 0;  // No path in both directions
                        break;
                    } 
                    else {
                        cout << "\nInvalid entry! Please enter 'y' or 'n'.";
                    }
                } while (true);
            }
        }
}

void flight::displaym() {
    cout << "\nAdjacency Matrix (Travel Time in Minutes):\n\n";

    // Print column headers
    cout << "        ";  // Extra space for row labels
    for (j = 0; j < n; j++)
        cout << v[j] << "\t";
    cout << "\n";

   

    // Print matrix with row labels
    for (i = 0; i < n; i++) {
        cout << v[i] << "\t| ";  // Row label
        for (j = 0; j < n; j++) {
            cout << m[i][j] << "\t";
        }
        cout << "\n";
    }
}

int main() {  
    int choice;   
    flight a;
    
    while (true) {
        cout << "\n\nEnter your choice:";
        cout << "\n1. Enter graph";
        cout << "\n2. Display adjacency matrix for cities";
        cout << "\n3. Exit";
        cout << "\n Enter your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
				    a.getgraph();
                    break;
            case 2: 
					a.displaym();
                    break;
            case 3: 
					exit(0);
					
            default: 
					cout << "\n Unknown choice, please try again.";
        }
    }
    return 0;
}
