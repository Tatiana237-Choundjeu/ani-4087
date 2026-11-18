#include <iostream>
#include <string>

using namespace std;

class Session {
private:
    bool ouverte;
    int debuts;
    int fins;
    int refus;

public:
    Session() : ouverte(false), debuts(0), fins(0), refus(0) {}

    bool Wait() {
        if (ouverte) {
            refus++;
            return false;
        }
        return true;
    }

    bool Begin() {
        if (ouverte) {
            refus++;
            return false;
        }

        ouverte = true;
        debuts++;
        return true;
    }

    bool End() {
        if (!ouverte) {
            refus++;
            return false;
        }

        ouverte = false;
        fins++;
        return true;
    }

    void afficher(string nom, int images) const {
        cout << nom
             << " DEBUTS " << debuts
             << " FINS " << fins
             << " REFUS " << refus
             << " IMAGES " << images
             << " OUVERTE " << (ouverte ? "OUI" : "NON")
             << '\n';
    }
};

class GardeTrame {
private:
    Session* session;

public:
    explicit GardeTrame(Session& s) : session(&s) {}

    GardeTrame(const GardeTrame&) = delete;
    GardeTrame& operator=(const GardeTrame&) = delete;

    ~GardeTrame() {
        session->End();
    }
};

// Simulation sans garde
void sansGarde(const string& signes) {
    Session session;
    int images = 0;

    for (char signe : signes) {
        bool attente = session.Wait();
        bool debut = session.Begin();

        if (!attente || !debut) {
            if (signe == 'R') {
                break;
            }
            continue;
        }

        if (signe == 'N') {
            images++;
        }

        if (signe == 'C') {
            continue;
        }

        if (signe == 'R') {
            break;
        }

        session.End();
    }

    session.afficher("SANS", images);
}

// Simulation avec garde
void avecGarde(const string& signes) {
    Session session;
    int images = 0;

    for (char signe : signes) {
        bool attente = session.Wait();
        bool debut = session.Begin();

        if (!attente || !debut) {
            if (signe == 'R') {
                break;
            }
            continue;
        }

        {
            GardeTrame garde(session);

            if (signe == 'N') {
                images++;
            }

            if (signe == 'C') {
                continue;
            }

            if (signe == 'R') {
                break;
            }
        }
    }

    session.afficher("AVEC", images);
}

int main() {
    int T;
    string signes;

    cin >> T >> signes;

    signes = signes.substr(0, static_cast<size_t>(T));

    sansGarde(signes);
    avecGarde(signes);

    return 0;
}
