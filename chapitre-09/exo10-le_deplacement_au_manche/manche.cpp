#include <iostream>
#include <string>

using namespace std;

int main() {
    int v, T;
    cin >> v >> T;

    int X = 0;
    int Z = 0;
    int diagonales = 0;

    for (int t = 1; t <= T; t++) {
        int k, n;
        cin >> k >> n;

        int x = 0;
        int y = 0;

        // Lire les boutons tenus
        for (int i = 0; i < n; i++) {
            string bouton;
            cin >> bouton;

            if (bouton == "F_DROITE") {
                x++;
            }
            else if (bouton == "F_GAUCHE") {
                x--;
            }
            else if (bouton == "F_HAUT") {
                y++;
            }
            else if (bouton == "F_BAS") {
                y--;
            }
        }

        // Définir les directions selon le lacet de la tête
        int ax = 0, az = 0;
        int dx = 0, dz = 0;

        switch (k) {
            case 0:
                ax = 0;
                az = -1;
                dx = 1;
                dz = 0;
                break;

            case 1:
                ax = -1;
                az = 0;
                dx = 0;
                dz = -1;
                break;

            case 2:
                ax = 0;
                az = 1;
                dx = -1;
                dz = 0;
                break;

            case 3:
                ax = 1;
                az = 0;
                dx = 0;
                dz = 1;
                break;
        }

        // Calculer le déplacement
        X += v * (y * ax + x * dx);
        Z += v * (y * az + x * dz);

        // Compter les déplacements diagonaux
        if (x != 0 && y != 0) {
            diagonales++;
        }

        cout << t << " "
             << x << "," << y << " "
             << X << " " << Z << "\n";
    }

    // Afficher le décalage final
    cout << "DECALAGE " << X << " " << Z << "\n";

    // Afficher le nombre de diagonales
    cout << "DIAGONALES " << diagonales << "\n";

    return 0;
}
