#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;

    string images;
    if (T > 0) {
        cin >> images;
    }

    // État de la gâchette
    int current = 0;
    int precedent = 0;
    int changed = 0;

    // État de l'objet dans les deux versions
    bool tenuAvec = false;
    bool tenuSans = false;
    bool tombeSans = false;

    // Compteurs
    int prisesAvec = 0;
    int prisesSans = 0;
    int chutesSans = 0;
    int coincesAvec = 0;
    int differences = 0;

    for (int i = 0; i < T; i++) {
        char signe = images[i];

        // Déterminer si la manette est active
        int active = (signe == 'x') ? 0 : 1;

        // Déterminer l'état de la gâchette
        current = (signe == '1') ? 1 : 0;

        // Détecter un changement, même pendant une coupure
        changed = (current != precedent) ? 1 : 0;

        // VERSION AVEC : on vérifie active
        if (active == 1) {
            if (current == 1 && changed == 1) {
                tenuAvec = true;
                prisesAvec++;
            }

            if (current == 0 && changed == 1) {
                tenuAvec = false;
            }
        }

        // VERSION SANS : on ne vérifie pas active
        if (current == 1 && changed == 1) {
            if (!tombeSans) {
                tenuSans = true;
                prisesSans++;
            }
        }

        if (current == 0 && changed == 1 && tenuSans) {
            if (active == 0) {
                tenuSans = false;
                tombeSans = true;
                chutesSans++;
            } else {
                tenuSans = false;
            }
        }

        // Compter les images où l'objet reste coincé
        if (signe == '0' && tenuAvec) {
            coincesAvec++;
        }

        // Comparer les deux versions
        if (tenuAvec != tenuSans) {
            differences++;
        }

        // Afficher les états des deux versions
        cout << i + 1 << " "
             << (tenuAvec ? "TENU" : "LIBRE") << " "
             << (tenuSans ? "TENU" : "LIBRE") << "\n";

        // Mémoriser l'état courant pour l'image suivante
        precedent = current;
    }

    // Bilan final
    cout << "PRISES AVEC " << prisesAvec << "\n";
    cout << "PRISES SANS " << prisesSans << "\n";
    cout << "CHUTES SANS " << chutesSans << "\n";
    cout << "COINCES AVEC " << coincesAvec << "\n";
    cout << "DIFFERENCES " << differences << "\n";

    return 0;
}
