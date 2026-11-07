#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() {
    int n, T;
    long long x0, v;

    std::cin >> n >> T >> x0 >> v;

    std::string modes;
    std::cin >> modes;

    // Dernière trame peinte dans chaque emplacement.
    std::vector<int> dernieresTrames(n, 0);

    // Indice de la prochaine image à emprunter.
    int prochaine = 0;

    long long positionPrecedente = 0;
    bool precedenteMontree = false;

    bool premierSaut = true;
    long long sautMin = 0;
    long long sautMax = 0;

    for (int t = 1; t <= T; ++t) {
        // 1. Emprunter la prochaine image.
        int empruntee = prochaine;

        // 2. Peindre la trame actuelle.
        dernieresTrames[empruntee] = t;

        char mode = modes[t - 1];
        int soumise = 0;

        // 3. Lecture avant ou après la libération.
        if (mode == 'P') {
            soumise = (prochaine + n - 1) % n;
        }

        // 4. Libérer l'image et avancer.
        prochaine = (prochaine + 1) % n;

        if (mode == 'D') {
            soumise = (prochaine + n - 1) % n;
        }
        else if (mode == 'A') {
            soumise = empruntee;
        }

        // 5. Déterminer la trame affichée.
        int f = dernieresTrames[soumise];

        if (f == 0) {
            std::cout << t << " NOIR -\n";
            precedenteMontree = false;
        }
        else {
            long long position = x0 + v * f;

            std::cout << t << " " << position << " ";

            if (t == 1 || !precedenteMontree) {
                std::cout << "-\n";
            }
            else {
                long long saut = position - positionPrecedente;

                std::cout << saut << "\n";

                if (premierSaut) {
                    sautMin = saut;
                    sautMax = saut;
                    premierSaut = false;
                }
                else {
                    sautMin = std::min(sautMin, saut);
                    sautMax = std::max(sautMax, saut);
                }
            }

            positionPrecedente = position;
            precedenteMontree = true;
        }
    }

    // 6. Bilan des sauts.
    if (premierSaut) {
        std::cout << "SAUTS AUCUN\n";
    }
    else {
        std::cout << "SAUT MIN " << sautMin << "\n";
        std::cout << "SAUT MAX " << sautMax << "\n";

        if (sautMin != sautMax) {
            std::cout << "TREMBLE OUI\n";
        }
        else {
            std::cout << "TREMBLE NON\n";
        }
    }

    return 0;
}

