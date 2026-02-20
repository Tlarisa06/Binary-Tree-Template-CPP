//
// Created by tifle on 13/05/2025.
//
#pragma once

template <class TElem>
AB<TElem>::AB() {
    elems.push_back(TElem());
    valid.push_back(false);
    rad = 1;
}

template <class TElem>
AB<TElem>::AB(const AB& other) {
    elems = other.elems;
    valid = other.valid;
    rad = other.rad;
}

template <class TElem>
void AB<TElem>::creeazaFrunza(TElem elem) {
    elems = std::vector<TElem>(2);
    valid = std::vector<bool>(2, false);
    elems[1] = elem;
    valid[1] = true;
    rad = 1;
}

template <class TElem>
bool AB<TElem>::vid() const {
    return elems.size() <= rad || !valid[rad];
}

template <class TElem>
TElem AB<TElem>::element() const {
    if (vid())
        throw std::runtime_error("Arborele este vid.");
    return elems[rad];
}

template <class TElem>
void AB<TElem>::creeazaAB(const AB& st, TElem elem, const AB& dr) {
    int maxSize = std::max(st.elems.size(), dr.elems.size()) * 2 + 2;
    elems = std::vector<TElem>(maxSize);
    valid = std::vector<bool>(maxSize, false);

    rad = 1;
    elems[1] = elem;
    valid[1] = true;

    for (int i = 1; i < st.elems.size(); ++i) {
        if (st.valid[i]) {
            elems[2 * i] = st.elems[i];
            valid[2 * i] = true;
        }
    }

    for (int i = 1; i < dr.elems.size(); ++i) {
        if (dr.valid[i]) {
            elems[2 * i + 1] = dr.elems[i];
            valid[2 * i + 1] = true;
        }
    }
}

template <class TElem>
void AB<TElem>::adaugaSubSt(const AB& st) {
    for (int i = 1; i < st.elems.size(); ++i) {
        if (st.valid[i]) {
            int pos = 2 * i;
            if (pos >= elems.size()) {
                elems.resize(pos + 1);
                valid.resize(pos + 1, false);
            }
            elems[pos] = st.elems[i];
            valid[pos] = true;
        }
    }
}

template <class TElem>
void AB<TElem>::adaugaSubDr(const AB& dr) {
    for (int i = 1; i < dr.elems.size(); ++i) {
        if (dr.valid[i]) {
            int pos = 2 * i + 1;
            if (pos >= elems.size()) {
                elems.resize(pos + 1);
                valid.resize(pos + 1, false);
            }
            elems[pos] = dr.elems[i];
            valid[pos] = true;
        }
    }
}

template <class TElem>
AB<TElem> AB<TElem>::stang() const {
    AB<TElem> st;
    for (int i = 1; i < elems.size(); ++i) {
        int pos = 2 * i;
        if (pos < elems.size() && valid[pos]) {
            if (st.elems.size() <= i){
                st.elems.resize(i + 1);
                st.valid.resize(i + 1, false);
            }
            st.elems[i] = elems[pos];
            st.valid[i] = true;
        }
    }
    return st;
}

template <class TElem>
AB<TElem> AB<TElem>::drept() const {
    AB<TElem> dr;
    for (int i = 1; i < elems.size(); ++i) {
        int pos = 2 * i + 1;
        if (pos < elems.size() && valid[pos]) {
            if (dr.elems.size() <= i){
                dr.elems.resize(i + 1);
                dr.valid.resize(i + 1, false);
            }
            dr.elems[i] = elems[pos];
            dr.valid[i] = true;
        }
    }
    return dr;
}

template <class TElem>
void AB<TElem>::visitTree(PFunctie<TElem> f) {
    for (int i = 1; i < elems.size(); ++i) {
        if (valid[i]) {
            f(elems[i]);
        }
    }
}
