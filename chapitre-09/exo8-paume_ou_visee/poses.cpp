#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    long long x, y, z;
};

// Rotation de x et z selon le lacet de la tête
Point tourner(Point p, int k) {
    switch (k % 4) {
        case 0:
            return {p.x, p.y, p.z};

        case 1:
            return {p.z, p.y, -p.x};

        case 2:
            return {-p.x, p.y, -p.z};

        case 3:
            return {-p.z, p.y, p.x};
    }

    return p;
}

// Transformer une pose locale en position dans la salle
Point transformer(Point local, Point tete, int k) {
    Point resultat = tourner(local, k);

    resultat.x += tete.x;
    resultat.y += tete.y;
    resultat.z += tete.z;

    return resultat;
}

// Calculer la distance au carré entre deux points
long long distanceCarree(Point a, Point b) {
    long long dx = a.x - b.x;
    long long dy = a.y - b.y;
    long long dz = a.z - b.z;

    return dx * dx + dy * dy + dz * dz;
}

// Chercher l'objet le plus proche à 150 mm au maximum
int chercherObjet(Point main, const vector<Point>& objets) {
    int meilleur = -1;
    long long meilleureDistance = 22501;

    for (int i = 0; i < (int)objets.size(); i++) {
        long long distance = distanceCarree(main, objets[i]);

        if (distance <= 22500 && distance < meilleureDistance) {
            meilleureDistance = distance;
            meilleur = i + 1;
        }
    }

    return meilleur;
}

int main() {
    int H, M;
    cin >> H >> M;

    vector<Point> tetes(H);
    vector<int> lacets(H);

    vector<Point> objets(M);

    // Lecture des poses de tête
    for (int i = 0; i < H; i++) {
        cin >> tetes[i].x
            >> tetes[i].y
            >> tetes[i].z
            >> lacets[i];
    }

    // Lecture des positions des objets
    for (int i = 0; i < M; i++) {
        cin >> objets[i].x
            >> objets[i].y
            >> objets[i].z;
    }

    long long ecart = 0;

    // Traitement de chaque pose de tête
    for (int h = 0; h < H; h++) {
        Point tete = tetes[h];
        int k = lacets[h];

        // Poses locales de la main droite
        Point paumeDroite = {180, -300, -250};
        Point viseeDroite = {180, -250, -400};

        // Poses locales de la main gauche
        Point paumeGauche = {-180, -300, -250};
        Point viseeGauche = {-180, -250, -400};

        // Transformer les quatre poses dans la salle
        paumeDroite = transformer(paumeDroite, tete, k);
        viseeDroite = transformer(viseeDroite, tete, k);

        paumeGauche = transformer(paumeGauche, tete, k);
        viseeGauche = transformer(viseeGauche, tete, k);

        // Affichage des positions
        cout << "TETE " << h + 1 << "\n";

        cout << "PAUME D "
             << paumeDroite.x << " "
             << paumeDroite.y << " "
             << paumeDroite.z << "\n";

        cout << "VISEE D "
             << viseeDroite.x << " "
             << viseeDroite.y << " "
             << viseeDroite.z << "\n";

        cout << "PAUME G "
             << paumeGauche.x << " "
             << paumeGauche.y << " "
             << paumeGauche.z << "\n";

        cout << "VISEE G "
             << viseeGauche.x << " "
             << viseeGauche.y << " "
             << viseeGauche.z << "\n";

        // Recherche de l'objet le plus proche
        int objetPaume = chercherObjet(paumeDroite, objets);
        int objetVisee = chercherObjet(viseeDroite, objets);

        if (objetPaume == -1) {
            cout << "SAISIE PAUME AUCUNE\n";
        } else {
            cout << "SAISIE PAUME " << objetPaume << "\n";
        }

        if (objetVisee == -1) {
            cout << "SAISIE VISEE AUCUNE\n";
        } else {
            cout << "SAISIE VISEE " << objetVisee << "\n";
        }

        // Calcul de la distance entre la paume et la visée
        if (h == 0) {
            long long d2 = distanceCarree(paumeDroite, viseeDroite);
            ecart = static_cast<long long>(round(sqrt(d2)));
        }
    }

    cout << "ECART " << ecart << "\n";

    return 0;
}
