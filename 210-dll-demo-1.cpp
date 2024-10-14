#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Goat {
private:
    int age;
    string name;
    string color;
    string names[15] = {"Senior", "Godlike", "Old", "Mature", "Teen", "Kid", "Ancient", "Elder", "Youth", "Youngster", "Adult", "Veteran", "Master", "Grandmaster", "Legend"};
    string colors[15] = {"White", "Black", "Brown", "Grey", "Spotted", "Gold", "Red", "Blue", "Green", "Yellow", "Pink", "Purple", "Orange", "Silver", "Mauve"};

public:
    // Default constructor
    Goat() {
        age = rand() % 20 + 1; // Random age between 1 and 20
        name = names[rand() % 15];
        color = colors[rand() % 15];
    }
    // Parameterized constructor
    Goat(int a, string n, string c) : age(a), name(n), color(c) {}

    int getAge() const { return age; }
    string getName() const { return name; }
    string getColor() const { return color; }

    void setAge(int a) { age = a; }
    void setName(string n) { name = n; }
    void setColor(string c) { color = c; }

    friend ostream& operator<<(ostream& os, const Goat& goat) {
        os << goat.name << " (" << goat.color << ", " << goat.age << ")";
        return os;
    }
};


class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;
        Node(Goat val, Node* p = nullptr, Node* n = nullptr) : data(val), prev(p), next(n) {}
    };

    Node* head;
    Node* tail;

public:
    // constructor
    DoublyLinkedList() { head = nullptr; tail = nullptr; }

    void push_back(Goat value) {
        Node* newNode = new Node(value);
        if (!tail) { // Empty list
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(Goat value) {
        Node* newNode = new Node(value);
        if (!head) { // Empty list
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void print() {
        Node* current = head;
        if (!current) {
            cout << "List is empty" << endl;
            return;
        }
        while (current) {
            cout << current->data << endl;
            current = current->next;
        }
        cout << endl;
    }

    // Print reverse method
    void print_reverse() {
        Node* current = tail;
        if (!current) {
            cout << "List is empty" << endl;
            return;
        }
        while (current) {
            cout << current->data << endl;
            current = current->prev;
        }
        cout << endl;
    }

    // Destructor
    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = nullptr;
    }
};

// Driver program
int main() {
    srand(time(0)); 

    DoublyLinkedList list;
    int size = rand() % (20 - 5 + 1) + 5; // Random between 5 and 20

    for (int i = 0; i < size; ++i) {
        Goat goat; 
        list.push_back(goat);
    }

    cout << "Forward: " << endl;
    list.print();

    cout << "Backward: " << endl;
    list.print_reverse();

    cout << "Deleting list, then trying to print." << endl;
    list.~DoublyLinkedList();

    cout << "List forward: ";
    list.print();


    return 0;
}
