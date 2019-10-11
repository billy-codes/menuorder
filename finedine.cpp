#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// DECLARATIONS and DEFINTION START //
string orderFile = "orders.txt";
string menuFile = "menu.txt";
string deliveryFile = "delivery.txt";
struct Order {
    string orderNo;
    string itemCode;
    string quantity;
    string rName;           // recipient name
    string rAddress;        // recipient address
    string rTel;            // recipient telephone no.
    string dCharges;        // delivery charges
    string status;          // order status 
    string tCost;           // total cost
};
struct Menu {
    string itemCode;
    string itemType;
    string itemCost;
};
struct Menu items[100];
struct Order orders[100];
// DECLARATIONS and DEFINTION END //

int lines(string txtFile){  // number of text-file lines
    ifstream textFile;
    string line;
    int count = 0;
    textFile.open(txtFile);
    if(textFile.is_open()){
        while(getline(textFile, line)){
            count++;
        }
        return count;
    }
}
int search_order(string searchTerm){
    // return the element position of the order number
    for(int x = 0; x < lines(orderFile); x++){
        if(searchTerm == orders[x].orderNo || searchTerm == orders[x].rName){
            return x;
        }
    }
}
void menu_file(){
    ifstream readFile;
    readFile.open("menu.txt", ios::in);
    if(readFile.is_open()){
        int i = 0;
        while(readFile){
            getline(readFile, items[i].itemCode, ':');
            getline(readFile, items[i].itemType, ';');
            getline(readFile, items[i].itemCost);
            i++;
        }
    }
    readFile.close();    
}
void view_orders(){
    ifstream readFile;
    readFile.open("orders.txt", ios::in);
    if(readFile.is_open()){
        int i = 0;
        while(readFile){
            getline(readFile, orders[i].orderNo, ':');
            getline(readFile, orders[i].itemCode, ';');
            getline(readFile, orders[i].quantity, '[');
            getline(readFile, orders[i].rName, '+');
            getline(readFile, orders[i].rAddress, '=');
            getline(readFile, orders[i].rTel, ']');
            getline(readFile, orders[i].dCharges, '(');
            getline(readFile, orders[i].status, ')');
            getline(readFile, orders[i].tCost);
            i++;
        }
    }
    readFile.close();
}
void modify_order(string orderNo, string rName, string rAddress, string rTel){
    // using nested functions
    int x = search_order(orderNo);
    orders[x].rName = rName;
    orders[x].rAddress = rAddress;
    orders[x].rAddress = rTel;
    ofstream writeFile("orders.txt");
    if(writeFile.is_open()){
        for(int y = 0; y < lines("orders.txt"); y++){
            writeFile << orders[y].orderNo << ":" << orders[y].itemCode 
                        << ";" << orders[y].quantity << "[" << orders[y].rName
                        << "+" << orders[y].rAddress << "=" << orders[y].rTel 
                        << "]" << orders[y].dCharges << "(" << orders[y].status 
                        << ")" << orders[y].tCost << "\n";
        }
        writeFile.close();
    }
}
void delete_order(string orderNo){
    int x = search_order(orderNo);
    orders[x].orderNo = ""; // nullify struct element
    orders[x].itemCode = "";
    orders[x].quantity = "";
    orders[x].rName = "";
    orders[x].rAddress = "";
    orders[x].rTel = "";
    orders[x].dCharges = "";
    orders[x].status = "";
    orders[x].tCost = "";
    ofstream writeFile("orders.txt");
    if(writeFile.is_open()){
        for(int y = 0; y < lines("orders.txt"); y++){
            if(y == x){
                continue;
            }else{
                writeFile << orders[y].orderNo << ":" << orders[y].itemCode 
                        << ";" << orders[y].quantity << "[" << orders[y].rName
                        << "+" << orders[y].rAddress << "=" << orders[y].rTel 
                        << "]" << orders[y].dCharges << "(" << orders[y].status 
                        << ")" << orders[y].tCost << "\n";
            }
        }
        writeFile.close();
    }
}
int main(){
    menu_file();
    view_orders();
    for(int xx = 0; xx < lines("menu.txt"); xx++){
        cout << items[xx].itemCode << " : " << items[xx].itemType << items[xx].itemCost << endl;
    }

    for(int yy = 0; yy < lines("orders.txt"); yy++){
        cout << "Order Number: " << orders[yy].orderNo << endl;
        cout << "Item Code: " << orders[yy].itemCode << endl;
        cout << "Recipient Name: " << orders[yy].rName << endl;
        cout << "Address: " << orders[yy].rAddress << endl;
        cout << "Telephone Number: " << orders[yy].rTel << endl;
        cout << "Delivery Charges: " << orders[yy].dCharges << endl;
        cout << "Status: " << orders[yy].status << endl;
        cout << "Total Cost: " << orders[yy].tCost << endl;
    }

    // search order
    cout << orders[search_order("Andrew")].rAddress << endl;



    return 0;
}