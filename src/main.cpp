//
//  main.cpp
//
//  Created by Michael McCarthy and Anton David Guaman Davila
//

#include <iostream>
#include "Item.h"
#include "DLL.h"

int main(){
    Item x;
    x.setName("ORANGE");
    cout << x.getName() << endl;
    x.setCategory("Fruits");
    cout << x.getCategory() << endl;
    x.setPrice(5.10);
    cout << x.getPrice() << endl;
    x.displayInfo();
    Item y;
    y.setName("Apple");
    cout << y.getName() << endl;
    y.setCategory("Fruits");
    cout << y.getCategory() << endl;
    y.setPrice(2.19);
    cout << y.getPrice() << endl;
    y.displayInfo();
    Item z;
    z.setName("Milk");
    cout << z.getName() << endl;
    z.setCategory("Dairy");
    cout << z.getCategory() << endl;
    z.setPrice(13.14);
    cout << z.getPrice() << endl;
    z.displayInfo();
    DLL<Item> j;
    j.pushDLL(x);
    j.pushDLL(y);
    j.pushDLL(z);
    j.printDLL();
    j.deletevalueDLL(<#Item key#>)
    return 0;
    

    
    
    
}
