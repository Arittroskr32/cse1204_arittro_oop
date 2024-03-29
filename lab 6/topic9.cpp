#include <iostream>
#include <deque>
#include <cstdlib>
#include <cstdio>
using namespace std;

class Deque
{
    deque<int> dq;

public:
    void pushFront(int data)
    {
        dq.push_front(data);
        cout << "Pushed " << data << " to the front of the deque." << endl;
    }

    void pushBack(int data)
    {
        dq.push_back(data);
        cout << "Pushed " << data << " to the back of the deque." << endl;
    }

    void popFront()
    {
        if (!dq.empty())
        {
            int front = dq.front();
            dq.pop_front();
            cout << "Popped " << front << " from the front of the deque." << endl;
        }
        else
        {
            cout << "Deque is empty. Cannot pop from the front." << endl;
        }
    }

    void popBack()
    {
        if (!dq.empty())
        {
            int back = dq.back();
            dq.pop_back();
            cout << "Popped " << back << " from the back of the deque." << endl;
        }
        else
        {
            cout << "Deque is empty. Cannot pop from the back." << endl;
        }
    }

    bool empty()
    {
        return dq.empty();
    }

    void displayDeque()
    {
        if (!dq.empty())
        {
            cout << "Deque elements: ";
            for (int element : dq)
            {
                cout << element << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Deque is empty." << endl;
        }
    }
};

void displayMenu()
{
    cout << "**** Deque Menu ****" << endl;
    cout << "1. Push to Front" << endl;
    cout << "2. Push to Back" << endl;
    cout << "3. Pop from Front" << endl;
    cout << "4. Pop from Back" << endl;
    cout << "5. Display Deque" << endl;
    cout << "6. Exit" << endl;
    cout << "Enter your option: ";
}

int main()
{
    Deque dq;
    int choice, data;

    do
    {
        system("cls");

        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter data to push to the front of the deque: ";
            cin >> data;
            dq.pushFront(data);
            break;
        case 2:
            cout << "Enter data to push to the back of the deque: ";
            cin >> data;
            dq.pushBack(data);
            break;
        case 3:
            dq.popFront();
            break;
        case 4:
            dq.popBack();
            break;
        case 5:
            dq.displayDeque();
            break;
        case 6:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }

        cout << "Press enter key to continue...";
        getchar();
        getchar();

    } while (choice != 6);

    return 0;
}