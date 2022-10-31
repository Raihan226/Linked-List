#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

node *head, *tail, *n;

void init()
{
    head, tail = NULL;
}

int isEmpty()
{
    if ( tail == NULL ) return true;
    else return false;
}

void inserthead( int newdata )
{
    n = new node();
    n -> data = newdata;

    if ( isEmpty() )
    {
        head = tail = n;
        tail -> next = NULL;
    }
    else
    {
        n -> next = head;
        head = n;
    }

    cout << "Data telah masuk.\n\n";
}

void inserttail( int newdata )
{
    node *beg;
    n = new node();
    n -> data = newdata;
    n -> next = NULL;

    if ( head == NULL )
    {
        head = n;
        head -> next = NULL;
        inserthead( newdata );
    }
    else
    {
        beg = head;
        while ( beg -> next != NULL )
        {
            beg = beg -> next;
        }
        beg -> next = n;
        cout << "Data telah masuk.\n\n";
    }
}

void print()
{
    node *help;
    help = head;
    if ( !isEmpty() )
    {
        while ( help != NULL )
        {
            cout << help -> data << "\t";
            help = help -> next;
        }
        cout << "\n\n";
    }
    else cout << "Data kosong\n\n";
}

void delhead()
{
    node *del;
    int d;

    if ( !isEmpty() )
    {
        if ( head != tail )
        {
            del = head;
            d = del -> data;
            head = head -> next;
            delete del;
        }
        else 
        {
            d = tail -> data;
            head = tail = NULL;
        }

        cout << "Data telah terhapus.\n\n";
    }
    else cout << "Data kosong.\n\n";
}

void deltail()
{

    if ( head != NULL )
    {
        if ( head -> next == NULL )
        {
            head = NULL;
        }
        else
        {
            node *del = head;
            while(del->next->next != NULL) del = del->next;
            node *tail = del -> next;
            del -> next = NULL;
            free(tail);
        }
    }
    else cout << "Data kosong.\n\n";
}

void deln( int n )
{
    node *temp1 = head;
    int i;

    if ( n == 1 )
    {
        head = temp1 -> next;
        free(temp1);
    }
    else
    {
        for ( i = 0; i < n-2; i++ )
        {
            temp1 = temp1 -> next;
        }
        node *temp2 = temp1 -> next;
        temp1 -> next = temp2 -> next;
        free(temp2);
    }
}

int main()
{
    int plh, newdata, n;

    cout    << "===== Linked List =====\n"
            << "1. Input data depan\n"
            << "2. Input data belakang\n"
            << "3. Delete data depan\n";
    cout    << "4. Delete data belakang\n"
            << "5. Delete data ke-n\n"
            << "6. Tampilkan data\n";
    cout    << "7. Exit\n"
            << "========================\n"
            << "Masukkan pilihan : "; cin >> plh;

    switch (plh)
    {
        case 1 :
            cout << "Masukkan data : "; cin >> newdata;
            inserthead( newdata );
            main();
            break;
        case 2 :
            cout << "Masukkan data : "; cin >> newdata;
            inserttail( newdata );
            main();
            break;
        case 3 :
            delhead();
            main();
            break;
        case 4 :
            deltail();
            main();
            break;
        case 5 :
            print();
            cout << "Masukkan data ke-n yang ingin dihapus : "; cin >> n;
            deln( n );
            main();
            break;
        case 6 :
            print();
            main();
            break;
        case 7 :
            break;
        default :
            main();
            break;
    }

    return 0;
}
