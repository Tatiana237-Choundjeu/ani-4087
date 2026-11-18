#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {
    int N;
    long long d;

    cin >> N >> d;

    long long sommePosition = 0;
    long long sommeAngle = 0;

    for (int t = 1; t <= N; t++) {
        long long x1, z1, a1;
        long long x2, z2, a2;

        cin >> x1 >> z1 >> a1 >> x2 >> z2 >> a2;

        // Calcul de la différence de position
        long long dx = x2 - x1;
        long long dz = z2 - z1;

        long double distance = sqrt(
            static_cast<long double>(dx) * dx +
            static_cast<long double>(dz) * dz
        );

        long long position = llround(distance);

        // Calcul de l'écart de lacet sans signe
        long long angle = llabs(a2 - a1);

        // Affichage des résultats de l'image
        cout << t << " POSITION " << position
             << " ANGLE " << angle << '\n';

        sommePosition += position;
        sommeAngle += angle;
    }

    // Si N ou d vaut zéro, aucune moyenne n'est calculable
    if (N == 0 || d == 0) {
        cout << "AUCUNE\n";
        return 0;
    }

    // Calcul des moyennes arrondies à l'entier inférieur
    cout << "MOYENNE POSITION "
         << sommePosition / N << '\n';

    cout << "MOYENNE ANGLE "
         << sommeAngle / N << '\n';

    // Calcul de la vitesse moyenne en degrés par seconde
    cout << "VITESSE "
         << sommeAngle / (static_cast<long long>(N) * d)
         << '\n';

    return 0;
}
