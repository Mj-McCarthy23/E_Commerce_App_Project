//
//  Item.h
//
//  Created by Michael McCarthy and Anton David Guaman Davila
//

#pragma once
#include <string>

using namespace std;

class Item{
private:
    string name;    //item name
    string cat;     // category
    string exp;     // expirey date
    float price;    // price of item
    
public:
    //Methods to write to private variables
    void setName(string name){
        this -> name = name;
    }
    void setCategory(string category){
        this -> cat = category;
    }
    void setExpiryDate(string expiry){
        this -> exp = expiry;
    }
    void setPrice(float price){
        this -> price = price;
    }
    //Methods to get private variables
    string getName(){
        return name;
    }
    string getCategory(){
        return cat;
    }
    string getExpiryDate(){
        return exp;
    }
    float getPrice(){
        return price;
    }
    //Method to print all the information
    
    void displayInfo(){
        cout << "The item name is:" << name <<endl;
        cout << "The category of the item is:"<< cat << endl;
        
        cout << "The expiry date of the item is:" << exp << endl;
        cout << "The price of the item is:"<< price << endl;
        cout << "-------------------------------------" << endl;
        
    }
    
    //friend class DLL;
};

