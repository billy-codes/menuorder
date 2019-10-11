#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Order {
    string orderNo;
    string itemCode;
    string quantity;
    string rName;           // recipient name
    string rAddress;        // recipient address
    string rTel;            // recipient telephone no.
    string dCharges;        // delivery charges
};
struct Menu {
    string itemCode;
    string itemType;
    string itemCost;
};
struct Menu items[100];
struct Order orders[100];

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
int main(){
    menu_file();
    for(int xx = 0; xx < lines("menu.txt"); xx++){
        cout << items[xx].itemCode << " : " << items[xx].itemType << items[xx].itemCost << endl;
    }



    return 0;
}