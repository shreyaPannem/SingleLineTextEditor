#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    char data;
    Node *prev;
    Node *next;

    Node(char val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

class SingleLineTextEditor
{
private:
    Node *head;
    Node *cursor;

    void displayText()
    {
        cout << "------------------------ Text Editor Start ------------------------\n";
        Node *current = head;
        while (current != nullptr)
        {
            cout << current->data;
            current = current->next;
        }
        cout << "------------------------ Text Editor End ------------------------\n";
    }

public:
    SingleLineTextEditor()
    {
        head = nullptr;
        cursor = new Node('|');
        head = cursor;
    }

    void insert(const string &text)
    {
        for (char c : text)
        {

            Node *newNode = new Node(c);
            newNode->prev = cursor->prev;
            newNode->next = cursor;

            if (newNode->prev != nullptr)
            {
                newNode->prev->next = newNode;
            }
            else
            {
                head = newNode;
            }
            cursor->prev = newNode;
        }
        displayText();
    }
    void deleteChar()
    {
        if (cursor->prev != nullptr)
        {
            Node *temp = cursor->prev;
            cursor->prev = temp->prev;
            if (cursor->prev != nullptr)
            {
                cursor->prev->next = cursor;
            }
            else
            {
                head = cursor;
            }
            delete temp;
        }
        displayText();
    }

    void moveLeft()
    {
        if (cursor->prev != nullptr)
        {
            swap(cursor->data, cursor->prev->data);
            cursor = cursor->prev;
        }
        displayText();
    }
    void moveRight()
    {
        if (cursor->next != nullptr)
        {
            swap(cursor->data, cursor->next->data);
            cursor = cursor->next;
        }
        displayText();
    }

    void runEditor()
    {
        char command;
        string text;

        while (true)
        {
            cout << "Enter command (I: Insert, D: Delete, L: Left, R: Right, Q: Quit): ";
            cin >> command;
            cin.ignore();
            switch (command)
            {
            case 'I':
                cout << "Enter text to insert: ";
                getline(cin, text);
                insert(text);
                break;
            case 'D':
                deleteChar();
                break;
            case 'L':
                moveLeft();

                break;
            case 'R':
                moveRight();
                break;
            case 'Q':
                return;
            default:
                cout << "Invalid command!" << endl;
            }
        }
    }
};

int main()
{
    SingleLineTextEditor editor;
    editor.runEditor();
    return 0;
}