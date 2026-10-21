
#include <iostream>
#include <string>

using namespace std;

/** @brief Kavos aparato klase. */
class KavosAparatas {
private:
    string modelis;
    int vandensKiekis;
    double kavosKiekis;
    bool ijungtas;

public:
    /** @brief Konstruktorius be parametru. */
    KavosAparatas()
        : modelis("Nezinomas"), vandensKiekis(0),
        kavosKiekis(0), ijungtas(false) {
    }

    /** @brief Konstruktorius su parametrais. */
    KavosAparatas(string m, int v, double k, bool i)
        : modelis(m), vandensKiekis(v),
        kavosKiekis(k), ijungtas(i) {
    }

    /** @brief Kopijavimo konstruktorius. */
    KavosAparatas(const KavosAparatas& kitas)
        : modelis(kitas.modelis),
        vandensKiekis(kitas.vandensKiekis),
        kavosKiekis(kitas.kavosKiekis),
        ijungtas(kitas.ijungtas) {
    }

    /** @brief Keicia kavos kieki. */
    void keistiKavosKieki(double kiekis) {
        kavosKiekis = kiekis;
    }

    /** @brief Rodo aparato duomenis. */
    void rodytiDuomenis() {
        cout << "Modelis: " << modelis << endl;
        cout << "Vandens kiekis: " << vandensKiekis << " ml" << endl;
        cout << "Kavos kiekis: " << kavosKiekis << " g" << endl;
        cout << "Ijungtas: " << ijungtas << endl;
    }

    /** @brief Papildo kavos kieki. */
    void operator+=(double kiekis) {
        kavosKiekis += kiekis;
    }
};

/** @brief WiFi irenginio klase. */
class WifiIrenginys {
public:
    /** @brief Rodo WiFi funkcija. */
    void rodytiWifi() {
        cout << "Wifi funkcija yra" << endl;
    }
};

/** @brief Kavos pupeliu klase. */
class KavosPupeles {
public:
    string rusis;

    KavosPupeles() : rusis("Arabica") {
    }
};

/** @brief Automatinio kavos aparato klase. */
class AutomatinisKavosAparatas : public KavosAparatas, public WifiIrenginys {
private:
    int puodeliuSkaicius;
    KavosPupeles pupeles;

public:
    AutomatinisKavosAparatas()
        : KavosAparatas("DeLonghi", 1000, 100, true),
        puodeliuSkaicius(0) {
    }

    /** @brief Keicia puodeliu skaiciu. */
    void keistiPuodeliuSkaiciu(int skaicius) {
        puodeliuSkaicius = skaicius;
    }

    /** @brief Paslepia bazines klases metoda. */
    void rodytiDuomenis() {
        KavosAparatas::rodytiDuomenis();
        cout << "Puodeliu skaicius: " << puodeliuSkaicius << endl;
        cout << "Kavos pupeles: " << pupeles.rusis << endl;
    }
};

/** @brief Protected paveldėjimo pavyzdys. */
class ProtectedKavosAparatas : protected KavosAparatas {
public:
    void testas() {
        cout << "Protected klase:" << endl;
        rodytiDuomenis();
    }
};

/** @brief Private paveldėjimo pavyzdys. */
class PrivateKavosAparatas : private KavosAparatas {
public:
    void testas() {
        cout << "Private klase:" << endl;
        rodytiDuomenis();
    }
};

/** @brief Protected paveldėjimo tikrinimas. */
class ProtectedVaikas : public ProtectedKavosAparatas {
public:
    void patikrinti() {
        cout << "Protected vaikas:" << endl;
        rodytiDuomenis();
    }
};

/** @brief Private paveldėjimo tikrinimas. */
class PrivateVaikas : public PrivateKavosAparatas {
public:
    void patikrinti() {
        cout << "Private vaikas:" << endl;

        // rodytiDuomenis(); // Negalima, nes private paveldėjimas
        testas();
    }
};

int main() {
    AutomatinisKavosAparatas aparatas;
    ProtectedKavosAparatas aparatas2;
    PrivateKavosAparatas aparatas3;
    ProtectedVaikas aparatas4;
    PrivateVaikas aparatas5;

    aparatas.keistiPuodeliuSkaiciu(5);
    aparatas.rodytiDuomenis();
    aparatas.rodytiWifi();

    cout << endl;

    // Operatoriaus perkrovimas
    aparatas += 50;
    aparatas.rodytiDuomenis();

    cout << endl;

    // Bazines klases metodo iskvietimas
    aparatas.KavosAparatas::rodytiDuomenis();

    cout << endl;

    // Protected ir private paveldėjimas
    aparatas2.testas();
    cout << endl;

    aparatas3.testas();
    cout << endl;

    aparatas4.patikrinti();
    cout << endl;

    aparatas5.patikrinti();

    // aparatas2.rodytiDuomenis(); // Negalima - protected
    // aparatas3.rodytiDuomenis(); // Negalima - private

    return 0;
}
