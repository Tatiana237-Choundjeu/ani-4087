#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Mur {
    string nom;
    long long xmin;
    long long xmax;
    long long zmin;
    long long zmax;
};

bool contientCoin(const Mur& mur,
                  long long xmin,
                  long long xmax,
                  long long zmin,
                  long long zmax) {
    return mur.xmin <= xmin &&
           mur.xmax >= xmax &&
           mur.zmin <= zmin &&
           mur.zmax >= zmax;
}

bool angleBouceParUnSeulMur(const vector<Mur>& murs,
                             long long xmin,
                             long long xmax,
                             long long zmin,
                             long long zmax) {
    int nombre = 0;

    for (const Mur& mur : murs) {
        if (contientCoin(mur, xmin, xmax, zmin, zmax)) {
            nombre++;
        }
    }

    return nombre == 1;
}

int main() {
    long long L, e;
    cin >> L >> e;

    int N;
    cin >> N;

    vector<Mur> murs;

    for (int i = 0; i < N; i++) {
        string nom;
        long long cx, cz, sx, sz;

        cin >> nom >> cx >> cz >> sx >> sz;

        Mur mur;

        mur.nom = nom;
        mur.xmin = cx - sx / 2;
        mur.xmax = cx + sx / 2;
        mur.zmin = cz - sz / 2;
        mur.zmax = cz + sz / 2;

        murs.push_back(mur);
    }

    // Affichons l'emprise de chaque mur
    for (const Mur& mur : murs) {
        cout << mur.nom << " "
             << mur.xmin << " "
             << mur.xmax << " "
             << mur.zmin << " "
             << mur.zmax << '\n';
    }

    long long h = L / 2;

    int trous = 0;

    // FOND_GAUCHE
    if (angleBouceParUnSeulMur(
            murs,
            -h - e, -h,
            -h - e, -h)) {
        cout << "FOND_GAUCHE BOUCHE\n";
    } else {
        cout << "FOND_GAUCHE TROU\n";
        trous++;
    }

    // FOND_DROIT
    if (angleBouceParUnSeulMur(
            murs,
            h, h + e,
            -h - e, -h)) {
        cout << "FOND_DROIT BOUCHE\n";
    } else {
        cout << "FOND_DROIT TROU\n";
        trous++;
    }

    // ENTREE_GAUCHE
    if (angleBouceParUnSeulMur(
            murs,
            -h - e, -h,
            h, h + e)) {
        cout << "ENTREE_GAUCHE BOUCHE\n";
    } else {
        cout << "ENTREE_GAUCHE TROU\n";
        trous++;
    }

    // ENTREE_DROIT
    if (angleBouceParUnSeulMur(
            murs,
            h, h + e,
            h, h + e)) {
        cout << "ENTREE_DROIT BOUCHE\n";
    } else {
        cout << "ENTREE_DROIT TROU\n";
        trous++;
    }

    cout << "TROUS " << trous << '\n';

    return 0;
}
