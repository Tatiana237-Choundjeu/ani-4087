#include <iostream>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    int muettes = 0;

    for (int i = 1; i <= N; i++) {
        string fin;
        int g, d;
        char instant, pose, espace;

        cin >> fin >> g >> d >> instant >> pose >> espace;

        string symptomes = "";

        // Symptômes liés à la fin de trame
        if (fin == "JAMAIS") {
            symptomes += "FIGE";
        } else if (fin == "SI_RENDU") {
            symptomes += "NE_REPART_PAS";
        }

        // Symptômes liés aux chaînes des yeux
        if (g == 0) {
            if (!symptomes.empty()) symptomes += " ";
            symptomes += "OEIL_NOIR_G";
        }

        if (d == 0) {
            if (!symptomes.empty()) symptomes += " ";
            symptomes += "OEIL_NOIR_D";
        }

        // Symptômes liés à l'instant, à la pose et à l'espace
        if (instant == 'N') {
            if (!symptomes.empty()) symptomes += " ";
            symptomes += "TREMBLE";
        }

        if (pose == 'F') {
            if (!symptomes.empty()) symptomes += " ";
            symptomes += "DE_TRAVERS";
        }

        if (espace == 'L') {
            if (!symptomes.empty()) symptomes += " ";
            symptomes += "DECALE";
        }

        // Affichage des symptômes sur le casque
        cout << i << " CASQUE ";

        if (symptomes.empty()) {
            cout << "AUCUN";
        } else {
            cout << symptomes;
        }

        cout << '\n';

        // Vérification de ce que signale le simulateur
        bool simulateurDit =
            (fin != "TOUJOURS" || g == 0 || d == 0);

        if (simulateurDit) {
            cout << i << " SIMULATEUR DIT\n";
        } else {
            cout << i << " SIMULATEUR MUET\n";

            if (!symptomes.empty()) {
                muettes++;
            }
        }
    }

    cout << "MUETTES " << muettes << '\n';

    return 0;
}
