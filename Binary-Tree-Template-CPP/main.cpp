#include <iostream>
#include "AB.h"

struct masina {
    int id, an, pret;
};
void printMasina(masina m) {
    std::cout << "ID: " << m.id << " An: " << m.an << " Pret: " << m.pret<<" EUR"<<std::endl;
}

void ABMasini() {
    masina m1={101,2020,15000};
    AB<masina>st1;
    st1.creeazaFrunza(m1);

    masina m2={102,2021,18000};
    AB<masina>st2;
    st2.creeazaFrunza(m2);

    masina m3={109,2019, 12000};
    AB<masina>dr1;
    dr1.creeazaFrunza(m3);

    masina m4={104,2022,25000};
    AB<masina>n1;
    n1.creeazaAB(st2,m4,dr1);

    masina m5={100,2018,20000};
    AB<masina>n2;
    n2.creeazaAB(st1,m5,n1);

    n2.visitTree(printMasina);

}

void printString(std::string s) {
    std::cout << s << std::endl;
}

void ABString() {
    AB<std::string>l;
    l.creeazaFrunza("Laptopuri");
    AB<std::string>a;
    a.creeazaFrunza("Android");
    AB<std::string>i;
    i.creeazaFrunza("IPhone");
    AB<std::string>t;
    t.creeazaAB(a,"Telefoane",i);
    AB<std::string>e;
    e.creeazaAB(l,"Electronice",t);

    e.visitTree(printString);
}

int main() {
    ABString();
    std::cout << std::endl;
    ABMasini();

    return 0;
}
