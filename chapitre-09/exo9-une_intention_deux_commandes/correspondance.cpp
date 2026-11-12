#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Action {
    string nom;
    string usage;
};

vector<string> traiterTable(
    int numero,
    const vector<Action>& actions
) {
    int U;
    cin >> U;

    vector<string> commandes(actions.size(), "");

    // Lire la table de correspondance
    for (int i = 0; i < U; i++) {
        string usage, commande;
        cin >> usage >> commande;

        for (int j = 0; j < (int)actions.size(); j++) {
            if (actions[j].usage == usage) {
                commandes[j] = commande;
            }
        }
    }

    cout << "TABLE " << numero << "\n";

    // Signaler les actions inactives
    for (int i = 0; i < (int)actions.size(); i++) {
        if (commandes[i].empty()) {
            cout << "INACTIVE " << actions[i].nom << "\n";
        }
    }

    int T;
    cin >> T;

    vector<bool> precedent(actions.size(), false);
    vector<string> lignes;

    // Traiter chaque image
    for (int t = 1; t <= T; t++) {
        int k;
        cin >> k;

        vector<string> tenues(k);

        for (int i = 0; i < k; i++) {
            cin >> tenues[i];
        }

        vector<bool> actuel(actions.size(), false);
        string ligne = to_string(t);
        bool nouvelAppui = false;

        for (int i = 0; i < (int)actions.size(); i++) {
            if (!commandes[i].empty()) {
                actuel[i] = find(
                    tenues.begin(),
                    tenues.end(),
                    commandes[i]
                ) != tenues.end();
            }

            if (actuel[i] && !precedent[i]) {
                ligne += " " + actions[i].nom;
                nouvelAppui = true;
            }
        }

        if (!nouvelAppui) {
            ligne += " -";
        }

        cout << ligne << "\n";
        lignes.push_back(ligne);

        precedent = actuel;
    }

    return lignes;
}

int main() {
    int A;
    cin >> A;

    vector<Action> actions(A);

    // Déclarer les actions une seule fois
    for (int i = 0; i < A; i++) {
        cin >> actions[i].nom >> actions[i].usage;
    }

    // Traiter les deux tables séparément
    vector<string> premiere =
        traiterTable(1, actions);

    vector<string> seconde =
        traiterTable(2, actions);

    // Comparer les résultats des deux tables
    if (premiere == seconde) {
        cout << "IDENTIQUES OUI\n";
    } else {
        cout << "IDENTIQUES NON\n";
    }

    return 0;
}
