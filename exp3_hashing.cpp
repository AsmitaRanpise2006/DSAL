//Linear probing with number of comparisions
#include <iostream>
#define MAX 10
using namespace std;

class Hash {
    long int arr[MAX];
    int comparisons[MAX]; // To store the number of comparisons for each key

public:
    Hash() {
        for (int i = 0; i < MAX; i++) {
            arr[i] = 0;
            comparisons[i] = 0;
        }
    }

    int hashFun(long int num) {
        return num % MAX; // Simple hash function
    }

    void insert() {
        long int num;
        cout << "Enter the number: ";
        cin >> num;

        int index = hashFun(num);
        int start = index;
        int comp = 1; // Initial comparison to check the first slot

        if (arr[index] == 0) {
            // If bucket is empty, insert directly
            arr[index] = num;
            comparisons[index] = comp;
            cout << "Number " << num << " inserted with " << comp << " comparisons." << endl;
            return;
        }

        // Collision handling using linear probing
        while (arr[index] != 0) {
            index = (index + 1) % MAX;
            comp++;
            if (index == start) {
                cout << "Hash table is full. Unable to insert " << num << endl;
                return;
            }
        }

        arr[index] = num;
        comparisons[index] = comp; // Store comparisons for this key
        cout << "Number " << num << " inserted with " << comp << " comparisons." << endl;
    }

    void displayTable() {
        for (int i = 0; i < MAX; i++) {
            if (arr[i] == 0)
                cout << i << " ------> NULL" << endl;
            else
                cout << i << " ------> " << arr[i] << endl;
        }
    }

    void displayComparisons() {
        int totalComparisons = 0;

        cout << "\nComparisons for each key:" << endl;
        for (int i = 0; i < MAX; i++) {
            if (arr[i] != 0) {
                cout << "Key " << arr[i] << " required " << comparisons[i] << " comparisons." << endl;
                totalComparisons += comparisons[i];
            }
        }
        cout << "Total comparisons: " << totalComparisons << endl;
    }
};

int main() {
    int choice;
    Hash h;

    do {
        cout << "\nMenu:\n1. Insert\n2. Display Table\n3. Display Comparisons\n0. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                h.insert();
                break;
            case 2:
                h.displayTable();
                break;
            case 3:
                h.displayComparisons();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}








//Quadratic probing with number of comparisions.

#include<iostream>
#define MAX 10
using namespace std;

class Hash {
    long int arr[MAX];
    int comparisons[MAX]; // To store comparisons for each key

public:
    Hash() {
        for (int i = 0; i < MAX; i++) {
            arr[i] = 0;
            comparisons[i] = 0;
        }
    }

    int hashFun(long int num) {
        return num % MAX; // Simple hash function
    }

    void insert() {
        long int num;
        cout << "Enter the number: ";
        cin >> num;

        int index = hashFun(num);
        int i = 0, comp = 1;

        // Check if the initial bucket is empty
        if (arr[index] == 0) {
            arr[index] = num;
            comparisons[index] = comp;
            return;
        }

        // If not, use quadratic probing to find the next empty slot
        while (arr[(index + i * i) % MAX] != 0) {
            comp++;
            i++;
            if (i == MAX) {
                cout << "Hash table is full" << endl;
                return;
            }
        }

        arr[(index + i * i) % MAX] = num;
        comparisons[(index + i * i) % MAX] = comp; // Store total comparisons for this key
    }

    void displayComparisons() {
        int totalComparisons = 0;
        for (int i = 0; i < MAX; i++) {
            if (arr[i] != 0) {
                cout << "Key " << arr[i] << " required " << comparisons[i] << " comparisons." << endl;
                totalComparisons += comparisons[i];
            }
        }
        cout << "Total comparisons for all keys: " << totalComparisons << endl;
    }

    void display() {
        for (int i = 0; i < MAX; i++) {
            if (arr[i] == 0)
                cout << i << " ------> NULL" << endl;
            else
                cout << i << " ------> " << arr[i] << endl;
        }
    }
};

int main() {
    int choice;
    Hash h;

    do {
        cout << "\nMenu:\n1. Insert\n2. Display\n3. Display Comparisons\n0. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                h.insert();
                break;
            case 2:
                h.display();
                break;
            case 3:
                h.displayComparisons();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
