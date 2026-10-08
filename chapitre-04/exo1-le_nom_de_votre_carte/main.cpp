#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

string nomLisible(const string& api) {
    if (api == "VULKAN") return "Vulkan";
    if (api == "DX12") return "DirectX 12";
    if (api == "DX11") return "DirectX 11";
    if (api == "OPENGL") return "OpenGL";
    if (api == "METAL") return "Metal";
    return "Software";
}

vector<string> ordrePlateforme(const string& plateforme) {
    if (plateforme == "WINDOWS") {
        return {"VULKAN", "DX12", "DX11", "OPENGL"};
    }

    if (plateforme == "MACOS") {
        return {"METAL", "OPENGL"};
    }

    if (plateforme == "IOS") {
        return {"METAL"};
    }

    return {"VULKAN", "OPENGL"};
}

bool contient(const vector<string>& interfaces, const string& api) {
    for (const string& element : interfaces) {
        if (element == api) {
            return true;
        }
    }
    return false;
}

int main() {
    int N;
    cin >> N;

    int ignorees = 0;
    int logiciel = 0;

    set<string> differentes;

    for (int i = 0; i < N; i++) {
        string nom;
        string plateforme;
        int k;

        cin >> nom >> plateforme >> k;

        vector<string> interfaces(k);

        for (int j = 0; j < k; j++) {
            cin >> interfaces[j];
        }

        vector<string> ordre = ordrePlateforme(plateforme);

        // Comptons les interfaces ignorées
        for (const string& api : interfaces) {
            if (!contient(ordre, api) && api != "SOFTWARE") {
                ignorees++;
            }
        }

        // Cherchons l'interface choisie
        string choisie = "SOFTWARE";

        for (const string& api : ordre) {
            if (contient(interfaces, api)) {
                choisie = api;
                break;
            }
        }

        string resultat = nomLisible(choisie);

        if (resultat == "Software") {
            logiciel++;
        }

        differentes.insert(resultat);

        cout << nom << " " << resultat << '\n';
    }

    cout << "IGNOREES " << ignorees << '\n';
    cout << "LOGICIEL " << logiciel << '\n';
    cout << "DIFFERENTES " << differentes.size() << '\n';

    return 0;
}
