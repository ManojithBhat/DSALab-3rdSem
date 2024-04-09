#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 5

class Queue {
private:
    int front, rear;
    char data[SIZE][20];

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void send(char item[20]) {
        if ((front == (rear + 1) % SIZE))
            cout << "\nQueue full";
        else {
            rear = (rear + 1) % SIZE;
            strcpy(data[rear], item);
            if (front == -1)
                front = 0;
        }
    }

    char* receive() {
        char* del;
        if (front == -1) {
            cout << "\nQueue empty";
            return nullptr;
        } else {
            del = data[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            } else
                front = (front + 1) % SIZE;
            return del;
        }
    }

    void display(){
        int i;
        if (front == -1)
            cout << "\nQueue Empty";
        else {
            cout << "\nQueue content are\n";
            for (i = front; i != rear; i = (i + 1) % SIZE)
                cout << data[i] << endl;
            cout << data[i] << endl;
        }
    }
};

int main() {
    int ch;
    char item[20];
    Queue q;
    for (;;) {
        cout << "\n1. Send\n2. Receive\n3. Display\n4. Exit";
        cout << "\nRead Choice :";
        cin >> ch;
        cin.ignore();
        switch (ch) {
            case 1:
                cout << "\nRead msg to be send :";
                cin.getline(item, 20);
                q.send(item);
                break;
            case 2: {
                char* del = q.receive();
                if (del != nullptr)
                    cout << "\nElement deleted is " << del << endl;
                break;
            }
            case 3:
                q.display();
                break;
            default:
                exit(0);
        }
    }
    return 0;
}
