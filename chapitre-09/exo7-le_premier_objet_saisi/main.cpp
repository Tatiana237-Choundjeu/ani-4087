#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Pose {
    long long x;
    long long y;
    int k;
};

// Tourner un vecteur de k quarts de tour
Pose tourner(Pose p, int k) {
    switch (k % 4) {
        case 0:
            return {p.x, p.y, 0};
        case 1:
            return {-p.y, p.x, 0};
        case 2:
            return {-p.x, -p.y, 0};
        case 3:
            return {p.y, -p.x, 0};
    }

    return {p.x, p.y, 0};
}

// Composer deux poses : A * B
Pose composer(Pose A, Pose B) {
    Pose position = tourner(B, A.k);

    return {
        A.x + position.x,
        A.y + position.y,
        (A.k + B.k) % 4
    };
}

// Calculer l'inverse d'une pose
Pose inverse(Pose A) {
    int angle = (4 - A.k) % 4;

    Pose position = tourner(
        {-A.x, -A.y, 0},
        angle
    );

    return {
        position.x,
        position.y,
        angle
    };
}

int main() {
    int M, T;
    cin >> M >> T;

    vector<Pose> objets(M);

    // Lecture des poses initiales des objets
    for (int i = 0; i < M; i++) {
        cin >> objets[i].x
            >> objets[i].y
            >> objets[i].k;
    }

    int tenu = -1;
    int saisies = 0;
    int ratees = 0;
    int boutonPrecedent = 0;

    Pose attache = {0, 0, 0};

    // Traitement de chaque image
    for (int t = 1; t <= T; t++) {
        Pose paume;
        int bouton;

        cin >> paume.x
            >> paume.y
            >> paume.k
            >> bouton;

        bool appui = (bouton == 1 && boutonPrecedent == 0);
        bool relachement = (bouton == 0 && boutonPrecedent == 1);

        // En cas de relâchement, libérer l'objet
        if (relachement) {
            tenu = -1;
        }

        // En cas de nouvel appui, chercher l'objet le plus proche
        if (appui) {
            int meilleur = -1;
            long long meilleureDistance = LLONG_MAX;

            for (int i = 0; i < M; i++) {
                long long dx = objets[i].x - paume.x;
                long long dy = objets[i].y - paume.y;

                long long distance = dx * dx + dy * dy;

                if (distance <= 22500 &&
                    distance < meilleureDistance) {
                    meilleureDistance = distance;
                    meilleur = i;
                }
            }

            if (meilleur != -1) {
                tenu = meilleur;

                // Calculer l'attache une seule fois à la saisie
                attache = composer(
                    inverse(paume),
                    objets[tenu]
                );

                saisies++;
            } else {
                tenu = -1;
                ratees++;
            }
        }

        // Si un objet est tenu, il suit la paume
        if (tenu != -1) {
            objets[tenu] = composer(paume, attache);

            cout << t << " TIENT "
                 << tenu + 1 << " "
                 << objets[tenu].x << " "
                 << objets[tenu].y << " "
                 << objets[tenu].k << "\n";
        } else if (appui) {
            cout << t << " RATE\n";
        } else {
            cout << t << " LIBRE\n";
        }

        boutonPrecedent = bouton;
    }

    // Afficher le bilan
    cout << "SAISIES " << saisies << "\n";
    cout << "RATEES " << ratees << "\n";

    // Afficher les poses finales des objets
    for (int i = 0; i < M; i++) {
        cout << "OBJET " << i + 1 << " "
             << objets[i].x << " "
             << objets[i].y << " "
             << objets[i].k << "\n";
    }

    return 0;
}
