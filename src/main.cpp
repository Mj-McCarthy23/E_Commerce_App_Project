//
//  main.cpp
//
//  Created by Michael McCarthy and Anton David Guaman Davila
//

#include <iostream>
#include "Item.h"
#include "DLL.h"
#include "AVLT.h"

int main(){
    Item x;
    x.setName("ORANGE");
    cout << x.getName() << endl;
    x.setCategory("Fruits");
    cout << x.getCategory() << endl;
    x.setPrice(5.10);
    cout << x.getPrice() << endl;
    DLL<Item> j;
    j.pushDLL(x);
    return 0;
    
}
