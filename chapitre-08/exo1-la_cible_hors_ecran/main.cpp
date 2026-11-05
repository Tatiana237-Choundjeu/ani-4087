#include <iostream>
#include <vector>
#include <string>
#include <sstream>

struct Cible {
    int largeur;
    int hauteur;
};

int main() {
    int L, H, F, N;
    std::cin >> L >> H >> F >> N;

    bool offscreenAllume = false;
    bool bloque = false;

    int largeurRendu = L;
    int hauteurRendu = H;

    int cibleActuelle = 0;
    int nombreImages = 0;

    std::vector<Cible> cibles;
    std::vector<bool> tamponsOccupes(F, false);

    std::string ligne;
    std::getline(std::cin, ligne);

    for (int i = 0; i < N; ++i) {
        std::getline(std::cin, ligne);

        if (bloque) {
            continue;
        }

        std::istringstream commande(ligne);
        std::string operation;

        commande >> operation;

        if (operation == "allume") {
            std::string nom;
            commande >> nom;

            if (nom == "OFFSCREEN") {
                offscreenAllume = true;
            }
        }
        else if (operation == "cible") {
            int w, h;
            commande >> w >> h;

            if (!offscreenAllume) {
                std::cout << "CIBLE NULLE\n";
            } else {
                cibles.push_back({w, h});

                std::cout << "CIBLE "
                          << cibles.size() << " "
                          << w << " "
                          << h << "\n";
            }
        }
        else if (operation == "vers") {
            int k;
            commande >> k;

            if (k == 0) {
                cibleActuelle = 0;
            }
            else if (k > 0 &&
                     k <= static_cast<int>(cibles.size())) {
                cibleActuelle = k;
            }
            else {
                std::cout << "VERS REFUSE\n";
            }
        }
        else if (operation == "taille") {
            commande >> largeurRendu >> hauteurRendu;
        }
        else if (operation == "image") {
            int n = nombreImages + 1;
            int tampon = (n - 1) % F;

            if (tamponsOccupes[tampon]) {
                std::cout << "BLOQUE " << n << "\n";
                bloque = true;
                continue;
            }

            nombreImages++;

            if (cibleActuelle == 0) {
                std::cout << "IMAGE "
                          << n << " FENETRE\n";
            }
            else {
                std::cout << "IMAGE "
                          << n << " CIBLE "
                          << cibleActuelle << "\n";

                const Cible& cible = cibles[cibleActuelle - 1];

                if (largeurRendu > cible.largeur ||
                    hauteurRendu > cible.hauteur) {
                    tamponsOccupes[tampon] = true;
                }
            }
        }
    }

    std::cout << "IMAGES " << nombreImages << "\n";

    std::cout << "ETAT "
              << (bloque ? "BLOQUE" : "LIBRE")
              << "\n";

    return 0;
}