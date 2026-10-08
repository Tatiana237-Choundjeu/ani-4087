#include <iostream>
#include <string>

using namespace std;

int main() {
    long long W, H, seuil;
    cin >> W >> H >> seuil;

    int N;
    cin >> N;

    int ok = 0;
    int aReprendre = 0;

    for (int i = 0; i < N; i++) {
        string nom;
        long long u, y, l, h, e, d;

        cin >> nom >> u >> y >> l >> h >> e >> d;

        // Limites du panneau
        long long gauche = u - l / 2;
        long long droite = u + l / 2;
        long long bas = y - h / 2;
        long long haut = y + h / 2;

        // Profondeurs des faces
        long long faceAvant = d + e / 2;
        long long faceArriere = d - e / 2;

        // Saillie
        long long saillie = faceAvant;

        string verdict;

        // 1) Débordement
        if (gauche < -W / 2 ||
            droite > W / 2 ||
            bas < 0 ||
            haut > H) {

            verdict = "DEBORDE";
        }

        // 2) Panneau noyé dans le mur
        else if (saillie <= 0) {
            verdict = "INVISIBLE";
        }

        // 3. Trop proche du mur
        else if (saillie < seuil) {
            verdict = "CLIGNOTE";
        }

        // 4) Panneau trop éloigné
        else if (faceArriere > seuil) {
            verdict = "DECOLLE";
        }

        // 5) Tout est correct
        else {
            verdict = "OK";
        }

        if (verdict == "OK") {
            ok++;
        } else {
            aReprendre++;
        }

        cout << nom << " " << saillie << " " << verdict << '\n';
    }

    cout << "OK " << ok << '\n';
    cout << "A REPRENDRE " << aReprendre << '\n';

    return 0;
}
