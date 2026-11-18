```cpp
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

struct Pose {
    long long x, y, z;
    int k;
};

// Effectuer une rotation de quarts de tour
void tourner(long long &x, long long &z, int k) {
    long long ancienX = x;
    long long ancienZ = z;

    switch (k) {
        case 0:
            break;

        case 1:
            x = ancienZ;
            z = -ancienX;
            break;

        case 2:
            x = -ancienX;
            z = -ancienZ;
            break;

        case 3:
            x = -ancienZ;
            z = ancienX;
            break;
    }
}

// Composer une pose LOCAL avec l'ancre pour obtenir STAGE
Pose composer(Pose ancre, Pose panneau) {
    tourner(panneau.x, panneau.z, ancre.k);

    Pose resultat;

    resultat.x = ancre.x + panneau.x;
    resultat.y = ancre.y + panneau.y;
    resultat.z = ancre.z + panneau.z;
    resultat.k = (ancre.k + panneau.k) % 4;

    return resultat;
}

// Calculer et afficher les quatre coins du panneau
void afficherCoins(Pose centre, long long w, long long h) {
    long long demiW = w / 2;
    long long demiH = h / 2;

    long long coins[4][2] = {
        {-demiW, -demiH},
        {demiW, -demiH},
        {demiW, demiH},
        {-demiW, demiH}
    };

    for (int i = 0; i < 4; i++) {
        long long x = coins[i][0];
        long long y = coins[i][1];
        long long z = 0;

        tourner(x, z, centre.k);

        cout << centre.x + x << " "
             << centre.y + y << " "
             << centre.z + z << '\n';
    }
}

int main() {
    Pose ancre;

    cin >> ancre.x >> ancre.y >> ancre.z >> ancre.k;

    Pose oeil;
    cin >> oeil.x >> oeil.y >> oeil.z;

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        char espace;
        Pose panneau;
        long long w, h;

        cin >> espace
            >> panneau.x >> panneau.y >> panneau.z
            >> panneau.k >> w >> h;

        // Déterminer l'espace du panneau
        bool estLocal = (espace == 'L' || espace == '-');

        Pose centre = panneau;

        // Convertir le centre en STAGE si nécessaire
        if (estLocal) {
            centre = composer(ancre, panneau);
        }

        // Afficher les informations du panneau
        cout << "PANNEAU " << i << " "
             << (estLocal ? "LOCAL" : "STAGE") << '\n';

        // Afficher les quatre coins
        afficherCoins(centre, w, h);

        // Calculer la distance entre le centre et l'œil
        long long dx = centre.x - oeil.x;
        long long dy = centre.y - oeil.y;
        long long dz = centre.z - oeil.z;

        long double distance = sqrt(
            static_cast<long double>(dx) * dx +
            static_cast<long double>(dy) * dy +
            static_cast<long double>(dz) * dz
        );

        cout << "DISTANCE " << llround(distance) << '\n';
    }

    cout << "PANNEAUX " << N << '\n';

    return 0;
}
```
