//=============================
//Roosevelt Bannerman
//Inventory Program With Linked List
//No Error Checking
//=============================
#include <iostream>

using namespace std;

struct Item{

    string name;
    string key;
    int quantity;
    Item* next;

    Item(){
        name = "\0";
        key = "\0";
        quantity = 0;
        next = NULL;
    }
    Item(string arg1,string arg2, int arg3){
        name = arg1;
        key = arg2;
        quantity = arg3;
        next = NULL;
    }

};

struct List{

    int currentSize;
    Item* head;

    List(){
        currentSize = 0;
        head = NULL;
    }

};

int displayMenu();
void addNewItem(List*);
void deleteItem(List*);
void updateQuantity(List*);
void getQuantity(List*);
void printInventory(List*);
void printDescending(Item*);


int main(){

    List Inventory;
    List* inventoryPtr = &Inventory;
    int selection;

    do{
        selection = displayMenu();
        switch(selection){
            case 1:
                addNewItem(inventoryPtr);
                break;
            case 2:
                deleteItem(inventoryPtr);
                break;
            case 3:
                updateQuantity(inventoryPtr);
                break;
            case 4:
                getQuantity(inventoryPtr);
                break;
            case 5:
                printInventory(inventoryPtr);
                break;
        }
    }while(selection!=6);

    cout << "\n\tGoodbye. Have a nice day!" << endl;
}

//========================
//Displays menu to the user
//Obtains their menu selection
//Returns the selection
//========================
int displayMenu(){

    cout << "\n\n\t1 - Add New Item";
    cout << "\n\t2 - Delete Item";
    cout << "\n\t3 - Update Quantity";
    cout << "\n\t4 - Get Quantity";
    cout << "\n\t5 - Print Inventory";
    cout << "\n\t6 - Quit";
    cout << "\n\n\tWhat would you like to do: ";

    int selection;
    cin >> selection;


    return selection;
}

//===============================
//Recieves the current Inventory
//Creates a new Item
//Adds the item the head of the Inventory
//===============================
void addNewItem(List* inventoryPtr){

    cin.ignore();

    cout << "\n\tPlease enter the item's name: ";
    string name;
    getline(cin,name);

    cout << "\tPlease enter the item's key: ";
    string key;
    getline(cin,key);

    cout << "\tPlease enter the item's quantity: ";
    int quantity;
    cin >> quantity;

    Item* newItem = new Item(name,key,quantity);

    Item* current = inventoryPtr->head;

    while(current!=NULL){
        if(current->key == key){
            cout << "\n\tThis item's key already exists.";
            return;
        }
        current = current->next;
    }

    if(inventoryPtr->head == NULL){
        inventoryPtr->head = newItem;
        inventoryPtr->currentSize++;
    }
    else{
        newItem->next = inventoryPtr->head;
        inventoryPtr->head = newItem;
        inventoryPtr->currentSize++;
    }
}

//===============================
//Recieves the current Inventory
//Obtains an item's key
//Deletes the item
//===============================
void deleteItem(List* inventoryPtr){

    cin.ignore();

    cout << "\n\tPlease enter the item's key: ";
    string key;
    getline(cin,key);

    if(inventoryPtr->head == NULL){
        cout << "\n\tThe list is empty.";
        return;
    }
    else{
        Item* current = inventoryPtr->head;
        Item* trail = NULL;

        while(current != NULL){
            if(current->key == key){
                break;
            }
            else{
                trail = current;
                current = current->next;
            }
        }

        if(current == NULL){
            cout << "\n\tThis key does not exist.";
            return;
        }
        else if(inventoryPtr->head == current){
            inventoryPtr->head = current->next;
            delete current;
            inventoryPtr->currentSize--;
        }
        else{
            trail->next = current->next;
            delete current;
            inventoryPtr->currentSize--;
        }
    }
}

//===============================
//Recieves the current Inventory
//Obtains an item's key and quantity change
//Updates the item's quantity
//===============================
void updateQuantity(List* inventoryPtr){

    cin.ignore();

    cout << "\n\tPlease enter the item's key: ";
    string key;
    getline(cin,key);

    cout << "\tPlease enter the item's quantity change: ";
    int quantity;
    cin >> quantity;

    if(inventoryPtr->head == NULL){
        cout << "\n\tThe list is empty.";
        return;
    }
    else{
        Item* current = inventoryPtr->head;

        while(current!=NULL){
            if(current->key == key){
                break;
            }
            else{
                current = current->next;
            }
        }

        if(current == NULL){
            cout << "\n\tThis key does not exist.";
            return;
        }
        else{
            current->quantity = current->quantity + quantity;
            if(current->quantity < 0){
                current->quantity = 0;
            }
        }
    }
}

//===============================
//Recieves the current Inventory
//Obtains an item's key
//Displays the item's quantity
//===============================
void getQuantity(List* inventoryPtr){

    cin.ignore();

    cout << "\n\tPlease enter the item's key: ";
    string key;
    getline(cin,key);

    if(inventoryPtr->head == NULL){
        cout << "\n\tThe list is empty.";
        return;
    }
    else{
        Item* current = inventoryPtr->head;

        while(current!=NULL){
            if(current->key == key){
                break;
            }
            else{
                current = current->next;
            }
        }

        if(current == NULL){
            cout << "\n\tThis key does not exist.";
            return;
        }
        else{
            cout << "\n\tThere are " << current->quantity << " " << current->name << " in the inventory.";
        }
    }
}

//===============================
//Recieves the current Inventory
//Obtains the order code and order
//Displays the current inventory
//===============================
void printInventory(List* inventoryPtr){

    cout << "\n\t1 - By Name";
    cout << "\n\t2 - By Key";

    cout << "\n\n\tHow would you like the list printed: ";
    int orderCode;
    cin >> orderCode;

    cout << "\n\tWould you like the list to be in ascending order(y,n): ";
    char order;
    cin >> order;

    if(inventoryPtr->head == NULL){
        cout << "\n\tThe list is empty.";
        return;
    }

    switch(orderCode){
        case 1:{
            Item *left = inventoryPtr->head;
            Item *right = left->next;
            int swapped = 1;
            while(swapped !=0){
                swapped = 0;
                while(right!=NULL){
                    if(right->name < left->name){
                        string temp = right->name;
                        right->name = left->name;
                        left->name = temp;

                        temp = right->key;
                        right->key = left->key;
                        left->key = temp;

                        int temp2 = right->quantity;
                        right->quantity = left->quantity;
                        left->quantity = temp2;
                        swapped++;
                    }
                    else{
                        left = right;
                        right = right->next;
                    }
                }
                left = inventoryPtr->head;
                right = left->next;
            }
            break;
        }
        case 2:{
            Item *left = inventoryPtr->head;
            Item *right = left->next;
            int swapped = 1;
            while(swapped !=0){
                swapped = 0;
                while(right!=NULL){
                    if(right->key < left->key){
                        string temp = right->name;
                        right->name = left->name;
                        left->name = temp;

                        temp = right->key;
                        right->key = left->key;
                        left->key = temp;

                        int temp2 = right->quantity;
                        right->quantity = left->quantity;
                        left->quantity = temp2;
                        swapped++;
                    }
                    else{
                        left = right;
                        right = right->next;
                    }
                }
                left = inventoryPtr->head;
                right = left->next;
            }
        }
    }


    if(order == 'y'){
        cout << "\n\n\t---Current Inventory---";
        Item* current = inventoryPtr->head;
        while(current!=NULL){
            cout << "\n\t" << current->name << " - " << current->key << " - " << current->quantity;
            current = current->next;
        }
    }
    else{
        cout << "\n\n\t---Current Inventory---";
        printDescending(inventoryPtr->head);
    }

}


void printDescending(Item* node){
    if(node == NULL){
        return;
    }
    printDescending(node->next);
    cout << "\n\t" << node->name << " - " << node->key << " - " << node->quantity;
}
