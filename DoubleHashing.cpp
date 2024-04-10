#include <iostream>
using namespace std;

const int hashTableSize = 10; // Set the hash table size
const int PrimeNumber = 7; // Prime number for better distribution

// First hash function
int firstHash(int key) {
  return key % hashTableSize;
}

// Second hash function (same as before)
int secondHash(int key) {
  return PrimeNumber - (key % PrimeNumber);
}

class HashTable {
private:
  int table[hashTableSize];

public:
  HashTable() {
    // Initialize hash table with 0s
    for (int i = 0; i < hashTableSize; ++i) {
      table[i] = 0;
    }
  }

  // Function to insert a key into the hash table
  void insert(int key) {
    int hash1 = firstHash(key);
    int i = 0;
    int index = (hash1 + i * secondHash(key)) % hashTableSize;

    while (table[index] != 0 && i < hashTableSize) {
      i++;
      index = (hash1 + i * secondHash(key)) % hashTableSize;
    }

    if (i == hashTableSize) {
      cout << "ERROR: TABLE FULL, insertion failed" << endl;
    } else {
      table[index] = key;
      cout << "Key " << key << " inserted successfully." << endl;
    }
  }

  // Function to delete a key from the hash table
  void deleteKey(int key) {
    int hash1 = firstHash(key);
    int i = 0;
    int index = (hash1 + i * secondHash(key)) % hashTableSize;

    while (table[index] != key && i < hashTableSize && table[index] != 0) {
      i++;
      index = (hash1 + i * secondHash(key)) % hashTableSize;
    }

    if (i == hashTableSize || table[index] == 0) {
      cout << "Key " << key << " not found." << endl;
    } else {
      table[index] = 0;
      cout << "Key " << key << " deleted successfully." << endl;
    }
  }

  // Function to display the contents of the hash table
  void display() {
    for (int i = 0; i < hashTableSize; i++) {
      cout <<i<<" "<< table[i] << " ";
    }
    cout << endl;
  }
};

int main() {
    HashTable hashTable;
    int choice, key;

    do {
        cout << "\nMenu:";
        cout << "\n1. Insert a key\n2. Delete a key\n3. Display hash table\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                hashTable.insert(key);
                cout << "Key inserted successfully." << endl;
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                hashTable.deleteKey(key);
                break;
            case 3:
                cout << "Hash table contents: ";
                hashTable.display();
                break;
            case 4:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
