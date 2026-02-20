#pragma once
#include <vector>

template <typename TElem>
using PFunctie = void(*)(TElem);

template <class TElem>
class AB {
private:
    std::vector<TElem> elems;
    std::vector<bool> valid;
    int rad;

public:
    AB();
    AB(const AB& other);
    ~AB() = default;

    void creeazaFrunza(TElem elem);
    void creeazaAB(const AB& st, TElem elem, const AB& dr);
    void adaugaSubSt(const AB& st);
    void adaugaSubDr(const AB& dr);
    bool vid() const;
    TElem element() const;
    AB stang() const;
    AB drept() const;
    void visitTree(PFunctie<TElem> f);
};

#include "AB.tpp"
