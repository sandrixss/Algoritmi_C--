
#include<iostream>
#include<cstdlib>
using namespace std;

struct Node
{
    int data;
    Node *link; // Raditajs uz nakamo mezglu
    Node *prev; // Raditajs uz ieprieksejo mezglu
};

Node *CreateNode()
{
    Node *newNode;
    newNode=new Node;
    cout<<"Ievadiet skaitli";
    cin>>newNode->data;
    newNode->link=NULL;
    newNode->prev=NULL;
    return newNode;
}
//==========================================
Node *findNode(Node *head, int x)
{
    Node *cur = head;
    while (cur != NULL && cur->data != x)
    {
        cur = cur->link;
    }
    return cur;
}
//============================================
Node *findNode2(Node *head, int x)
{
    Node *cur = findNode(head, x);
    if (cur == NULL)
        return NULL;
    return cur->prev;
}
//===============================piev saraksta sakuma
Node *Addfirst(Node *head)
{
    Node *newNode = CreateNode();
    newNode->link = head;
    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
    return head;
}
//============================piev saraksta beigas
Node *AddLast(Node *head)
{
    Node *newNode, *cur;
    if (head == NULL)
    {
        head = CreateNode();
        return head;
    }

    newNode = CreateNode();
    cur = head;
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->link = newNode;
    newNode->prev = cur;
    return head;
}
//=============================piev pec
Node *Addafter(Node *head)
{
    int x;
    cout << "\nPec kura mezgla pievienot? ";
    cin >> x;

    Node *find = findNode(head, x);
    if (find == NULL)
    {
        cout << "\nTada skaitla saraksta nav";
    }
    else
    {
        Node *newNode = CreateNode();
        newNode->link = find->link;
        newNode->prev = find;

        if (find->link != NULL)
        {
            find->link->prev = newNode;
        }
        find->link = newNode;
    }
    return head;
}
//====================Pirms noradita mezgla
Node *Addbefore(Node *head)
{
    int x;
    cout << "\nPirms kura mezgla pievienot? ";
    cin >> x;

    if (head->data == x)
    {
        head = Addfirst(head);
    }
    else
    {
        Node *prev = findNode2(head, x);
        if (prev != NULL)
        {
            Node *newNode = CreateNode();
            newNode->link = prev->link;
            newNode->prev = prev;
            prev->link->prev = newNode;
            prev->link = newNode;
        }
        else
        {
            cout << "\nMeklejama mezgla nav!";
        }
    }
    return head;
}
//=================dzest saraksta sakuma
Node *deleteFirst(Node *head)
{
    if (head != NULL)
    {
        Node *prev = head;
        head = head->link;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        delete prev;
        cout << "\nMezgls tika nodzests!";
    }
    else
    {
        cout << "\nSaraksts ir tukss!";
    }
    return head;
}
//=======================dzest saraksta beigas
Node *deleteLast(Node *head)
{
    if (head == NULL)
    {
        cout << "\nSaraksts ir tukss!";
        return head;
    }

    if (head->link == NULL)
    {
        delete head;
        cout << "\nHead tika nodzests!";
        return NULL;
    }

    Node *cur = head;
    while (cur->link != NULL)
    {
        cur = cur->link;
    }
    cur->prev->link = NULL;
    delete cur;

    cout << "\nMezgls tika nodzests!";
    return head;
}
//===========dzest pec noradita mezgla
Node *deleteAfter(Node *head)
{
    int x;
    cout << "\nPec kura mezgla dzest? ";
    cin >> x;

    Node *cur = findNode(head, x);
    if (cur == NULL)
    {
        cout << "\nTada mezgla nav!";
    }
    else if (cur->link == NULL)
    {
        cout << "\nMezgls ir pedejais!";
    }
    else
    {
        Node *delNode = cur->link;
        cur->link = delNode->link;
        if (delNode->link != NULL)
        {
            delNode->link->prev = cur;
        }
        delete delNode;
        cout << "\nMezgls tika nodzests!";
    }
    return head;
}
//===================dzest pirms noradita mezgla
Node *deleteBefore(Node *head)
{
    if (head == NULL || head->link == NULL)
    {
        cout << "\nNav ko dzest!";
        return head;
    }

    int x;
    cout << "\nPirms kura mezgla dzest? ";
    cin >> x;

    Node *cur = findNode(head, x);

    if (cur == NULL)
    {
        cout << "\nTada mezgla nav!";
    }
    else if (cur->prev == NULL)
    {
        cout << "\nPirms pirma mezgla nav ko dzest!";
    }
    else if (cur->prev == head)
    {
        head = deleteFirst(head);
    }
    else
    {
        Node *prev = cur->prev;
        prev->prev->link = cur;
        cur->prev = prev->prev;
        delete prev;
        cout << "\nMezgls tika nodzests!";
    }
    return head;
}
//=============saraksta izvads
void PrintList(Node *head)
{
    cout << "\nSaraksta elementi:\n";
    Node *cur = head;
    while (cur != NULL)
    {
        cout << cur->data << " ";
        cur = cur->link;
    }
    cout << endl;
}
//=================mezglu sk noteiksana
int CountElements(Node *head)
{
    int count = 0;
    Node *cur = head;
    while (cur != NULL)
    {
        count++;
        cur = cur->link;
    }
    return count;
}
//=================saraksta dzesana
Node *ClearList(Node *head)
{
    Node *cur;
    while (head != NULL)
    {
        cur = head;
        head = head->link;
        delete cur;
    }
    cout << "\nViss saraksts tika izdzests!";
    return NULL;
}

int main()
{
    Node *head = NULL;
    int izvele;
    do
    {
        cout << "\n1. Pievienot sakuma";
        cout << "\n2. Pievienot beigas";
        cout << "\n3. Pievienot pec noradita mezgla";
        cout << "\n4. Pievienot pirms noradita mezgla";
        cout << "\n5. Dzest sakuma";
        cout << "\n6. Dzest beigas";
        cout << "\n7. Dzest pec noradita mezgla";
        cout << "\n8. Dzest pirms noradita mezgla";
        cout << "\n9. Saraksta izvadisana";
        cout << "\n10. Elementu skaita noteiksana";
        cout << "\n11. Visa saraksta dzesana";
        cout << "\n0. Programmas beigas";
        cout << "\nIzveleties darbibu: ";
        cin >> izvele;

        switch (izvele)
        {
        case 1:
            head = Addfirst(head);
            break;
        case 2:
            head = AddLast(head);
            break;
        case 3:
            if (head) head = Addafter(head);
            else cout << "\nSaraksts ir tukss!";
            break;
        case 4:
            if (head) head = Addbefore(head);
            else cout << "\nSaraksts ir tukss!";
            break;
        case 5:
            head = deleteFirst(head);
            break;
        case 6:
            head = deleteLast(head);
            break;
        case 7:
            if (head) head = deleteAfter(head);
            else cout << "\nSaraksts ir tukss!";
            break;
        case 8:
            if (head) head = deleteBefore(head);
            else cout << "\nSaraksts ir tukss!";
            break;
        case 9:
            PrintList(head);
            break;
        case 10:
            cout << "\nElementu skaits saraksta: " << CountElements(head) << endl;
            break;
        case 11:
            head = ClearList(head);
            break;
        case 0:
            cout << "\nProgrammas beigas!";
            break;
        default:
            cout << "\nNepareiza izvele!";
        }
    } while (izvele != 0);

    head = ClearList(head);

    system("pause>nul");
    return 0;
}
