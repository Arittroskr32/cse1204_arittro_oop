#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

void Display(const list<int> lst)
{
    for (auto it = lst.begin(); it != lst.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
}
bool isBig(int x)
{
    return x > 40;
}
int main()
{
    list<int> li;
    for (int i = 1; i <= 8; ++i)
    {
        li.push_back(i * 10);
    }
    cout << "Inserted 8 integers: ";
    Display(li);
    li.push_front(30);
    li.push_front(50);
    cout << "Pushed 30 & 50 at front: ";
    Display(li);
    cout << "List: ";
    Display(li);
    cout << "Reversed list: ";
    for (auto it = li.rbegin(); it != li.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    cout << "Front element: " << li.front() << endl;
    cout << "Back element: " << li.back() << endl;
    li.pop_front();
    cout << "After poping front: ";
    Display(li);
    li.pop_back();
    cout << "After poping back: ";
    Display(li);
    int found = 0;
    for (auto it = li.begin(); it != li.end(); ++it)
    {
        if (*it == 40)
        {
            found = 1;
        }
    }
    if (found)
    {
        cout << "Element 40 found in the list." << endl;
    }
    else
    {
        cout << "Element 40 not found in the list." << endl;
    }
    auto insertBeforePos = li.end();
    for (auto it = li.begin(); it != li.end(); ++it)
    {
        if (*it == 60)
        {
            insertBeforePos = it;
        }
    }
    if (insertBeforePos != li.end())
    {
        li.insert(insertBeforePos, 50);
    }
    cout << "Inserted 50 before 60: ";
    Display(li);
    auto insertAfterPos = li.end();
    for (auto it = li.begin(); it != li.end(); ++it)
    {
        if (*it == 30)
        {
            insertAfterPos = it;
        }
    }
    if (insertAfterPos != li.end())
    {
        li.insert(++insertAfterPos, 85);
    }
    cout << "Inserted 85 after 30: ";
    Display(li);
    int countX = 0;
    for (auto it = li.begin(); it != li.end(); ++it)
    {
        if (*it == 50)
        {
            countX++;
        }
    }
    cout << "Count of element 50: " << countX << endl;
    int countCondition = count_if(li.begin(), li.end(), isBig);
    cout << "Count of elements greater than 40: " << countCondition << endl;
    for (auto it = li.begin(); it != li.end(); ++it)
    {
        if (*it == 30)
        {
            li.erase(it);
            break;
        }
    }
    cout << "Erased 30: ";
    Display(li);
    auto eraseEnd = li.begin();
    for (int i = 0; i < 4; i++)
    {
        eraseEnd++;
    }
    li.erase(li.begin(), eraseEnd);
    cout << "Erased 1st 4 elements: ";
    Display(li);
    li.remove(60);
    cout << "removed 60: ";
    Display(li);
    li.remove_if(isBig);
    cout << "Removed elements greater than 40: ";
    Display(li);
    list<int> anotherList = {100, 200, 300};
    li.assign(anotherList.begin(), anotherList.end());
    cout << "Assigned another list: ";
    Display(li);
    int arr[] = {5, 10, 15, 10, 5};
    li.assign(arr, arr + 5);
    cout << "Assigned an array: ";
    Display(li);
    li.sort();
    cout << "Sorted list: ";
    Display(li);
    li.unique();
    cout << "Unique list elements: ";
    Display(li);

    return 0;
}