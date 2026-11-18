#include <iostream>
using namespace std;

struct Pose {
    long long x, y, z;
    int k;
};

// Tourner une position selon le nombre de quarts de tour
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

// Transformer une pose LOCAL en pose STAGE
Pose composer(Pose ancre, Pose p) {
    tourner(p.x, p.z, ancre.k);

    Pose resultat;

    resultat.x = ancre.x + p.x;
    resultat.y = ancre.y + p.y;
    resultat.z = ancre.z + p.z;
    resultat.k = (ancre.k + p.k) % 4;

    return resultat;
}

int main() {
    Pose ancre;

    cin >> ancre.x >> ancre.y >> ancre.z >> ancre.k;

    int N;
    cin >> N;

    int justes = 0;
    int fausses = 0;

    for (int i = 1; i <= N; i++) {
        char D, C;
        Pose p;

        cin >> D >> C >> p.x >> p.y >> p.z >> p.k;

        // Calcul de la vraie pose dans STAGE
        Pose vraie = p;

        if (D == 'L') {
            vraie = composer(ancre, p);
        }

        // Calcul de la pose interprétée par le compositeur
        Pose crue = p;

        if (C == 'L') {
            crue = composer(ancre, p);
        }

        // Calcul des écarts
        long long dx = crue.x - vraie.x;
        long long dy = crue.y - vraie.y;
        long long dz = crue.z - vraie.z;

        int dk = (crue.k - vraie.k + 4) % 4;

        // Affichage de la pose crue
        cout << i << " CRU "
             << crue.x << " "
             << crue.y << " "
             << crue.z << " "
             << crue.k << '\n';

        // Affichage des écarts
        cout << i << " ECART "
             << dx << " "
             << dy << " "
             << dz << " "
             << dk << '\n';

        // Vérification de la pose
        if (dx == 0 && dy == 0 && dz == 0 && dk == 0) {
            justes++;
        } else {
            fausses++;
        }
    }

    cout << "JUSTES " << justes << '\n';
    cout << "FAUSSES " << fausses << '\n';

    return 0;
}
