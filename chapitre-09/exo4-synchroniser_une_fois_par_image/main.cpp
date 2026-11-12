#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    int current = 0;
    int changed = 0;
    int active = 0;

    int appuisReels = 0;
    int saisies = 0;
    int syncRefusees = 0;

    int boutonPrecedent = 0;

    for (int t = 1; t <= T; t++) {
        int p, s, f;
        cin >> p >> s >> f;

        // Compter les vrais appuis physiques
        if (p == 1 && boutonPrecedent == 0) {
            appuisReels++;
        }

        boutonPrecedent = p;

        // Effectuer les synchronisations demandées
        for (int i = 0; i < s; i++) {

            // Refuser la synchronisation sans le focus
            if (f == 0) {
                syncRefusees++;
                continue;
            }

            // Mettre à jour les états après une synchronisation acceptée
            changed = (p != current) ? 1 : 0;
            current = p;
            active = 1;
        }

        // Vérifier si une saisie doit être déclenchée
        if (current == 1 && changed == 1) {
            cout << t << " "
                 << current << " "
                 << changed << " "
                 << active << " SAISIT\n";

            saisies++;
        } else {
            cout << t << " "
                 << current << " "
                 << changed << " "
                 << active << " -\n";
        }
    }

    // Afficher les statistiques finales
    cout << "APPUIS REELS " << appuisReels << "\n";
    cout << "SAISIES " << saisies << "\n";
    cout << "SYNC REFUSEES " << syncRefusees << "\n";

    return 0;
}
