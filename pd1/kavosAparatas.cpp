#include <iostream>
#include <string>

using namespace std;

// Kavos aparato klase
class KavosAparatas
{
private:
    // Kavos aparato duomenys
    string modelis;
    int vandensKiekis;
    double kavosKiekis;
    bool ijungtas;

public:

    // Paprastas konstruktorius
    KavosAparatas()
    {
        this->modelis = "Nezinomas";
        this->vandensKiekis = 0;
        this->kavosKiekis = 0.0;
        this->ijungtas = false;
    }

    // Konstruktorius su parametrais
    KavosAparatas(string naujasModelis, int vanduo, double kava, bool busena)
    {
        this->modelis = naujasModelis;
        this->vandensKiekis = vanduo;
        this->kavosKiekis = kava;
        this->ijungtas = busena;
    }

    // Keicia vandens kieki
    void keistiVandensKieki(int vanduo)
    {
        this->vandensKiekis = vanduo;
    }

    // Keicia kavos kieki
    void keistiKavosKieki(double kava)
    {
        this->kavosKiekis = kava;
    }

    // Ijungia kavos aparata
    void ijungti()
    {
        this->ijungtas = true;
    }

    // Isjungia kavos aparata
    void isjungti()
    {
        this->ijungtas = false;
    }

    // Parodo kavos aparato duomenis
    void rodytiDuomenis()
    {
        cout << "Modelis: " << this->modelis << endl;
        cout << "Vandens kiekis: " << this->vandensKiekis << " ml" << endl;
        cout << "Kavos kiekis: " << this->kavosKiekis << " g" << endl;
        cout << "Ijungtas: " << this->ijungtas << " (1 - taip, 0 - ne)" << endl;
    }
};

int main()
{
    int vanduo;
    double kava;

    // Sukuriami du kavos aparatai
    KavosAparatas aparatas1;
    KavosAparatas aparatas2("Philips", 1500, 250.5, false);

    cout << "Pirmas kavos aparatas:" << endl << endl;
    aparatas1.rodytiDuomenis();

    cout << endl << "Antras kavos aparatas:" << endl << endl;
    aparatas2.rodytiDuomenis();

    // Ijungiame antra kavos aparata
    aparatas2.ijungti();

    // Keiciame vandens kieki
    cout << endl << "Iveskite vandens kieki (ml): " << endl;
    cin >> vanduo;
    aparatas2.keistiVandensKieki(vanduo);

    // Keiciame kavos kieki
    cout << "Iveskite kavos kieki (g): " << endl;
    cin >> kava;
    aparatas2.keistiKavosKieki(kava);

    cout << endl << "Duomenys po pakeitimo:" << endl << endl;
    aparatas2.rodytiDuomenis();

    return 0;
}