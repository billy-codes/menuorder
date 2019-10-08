#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

struct Order {
    int orderNo;
    int itemCode;
    int quantity;
    string rName;           // recipient name
    string rAddress;        // recipient address
    string rTel;            // recipient telephone no.
    double dCharges;        // delivery charges
};

struct Menu {
    int itemCode;
    string itemType;
    int itemCost;
};
struct Menu itemss[100];

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

// void read_file(){ // read user.txt file
//     string iType;
//     int iCode, iCost;
//     FILE *fp;
//     fp = fopen("menu.txt","r");

//     int j = 0;
//     rewind(fp);
//     while(fscanf(fp, "%d %s %d", &iCode, iType, &iCost) != EOF){
//         // fscanf(fp, "%d %s %d", &iCode, iType, &iCost);
//         itemss[j].itemCode = iCode;
//         itemss[j].itemType = iType;
//         itemss[j].itemCost = iCost;
//         cout << itemss[j].itemCode << itemss[j].itemType << itemss[j].itemCost << endl;
//         j++;
//     }
//     fclose(fp);
// }
string arr[100];
void menu_file(){
    ifstream readFile;
    string line;
    readFile.open("menu.txt", ios::in);
    int j = 0;
    int i = 0;
    if(readFile.is_open()){
        while(getline(readFile, line, ' ')){
            arr[i] = line;
            i++;
        }
        j++; 
    }
    readFile.close();
    
}
int main(){
    // cout << lines("menu.txt");
    menu_file();
    cout << arr[1];
    // cout << itemss[0].itemCode << " : " << itemss[0].itemType;
    // cout << "Trest";


    return 0;
}