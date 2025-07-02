#include <iostream>
#include "functions.cpp"
using namespace std;


void showOptions() {
    cout << "======================================================================\n";
    cout << "1 - piso, teto, divisao, resto, divisaoEuclidiana, mod, sePrimo, primosEntreDoisNumeros \n";
    cout << "2 - cifraDeCesar ou traduzirCifraDeCesar \n";
    cout << "3 - calcularMDC \n";
    cout << "4 - bezout \n";
    cout << "5 - criptografarRSA \n";
    cout << "6 - criptografarComplicadoRSA \n";
    cout << "======================================================================\n";
}


int main()
{
    int option = 0;
    while (true) {
        showOptions();
        cout << "Digite uma das opções: \n";
        cin >> option;

        if (option == 1) {
            while (true) {
                string continuar;
                string op;
                float n1 = -999999, n2 = -999999;
    
                cout << "Pressione \"p\" para piso, \"t\" para teto, \"d\" para divisao, \"r\" para resto, \"de\" para divisaoEuclidiana, \"m\" para mod, \"sp\" para sePrimo, \"pe\" para primosEntreDoisNumeros: \n";
                cin >> op;
                if (op == "p") {
                    cout << "digite número: \n";
                    cin >> n1;
                    cout << "resultado: " << piso(n1) << "\n";
                } else if (op == "t") {
                    cout << "digite número: \n";
                    cin >> n1;
                    cout << "resultado: " << teto(n1) << "\n";
                } else if (op == "d") {
                    cout << "digite o numerador: \n";
                    cin >> n1;
                    cout << "digite o denominador: \n";
                    cin >> n2;
                    cout << "resultado: " << divisao(n1, n2) << "\n";
                } else if (op == "r") {
                    cout << "digite o numerador: \n";
                    cin >> n1;
                    cout << "digite o denominador: \n";
                    cin >> n2;
                    cout << "resultado: " << resto(n1, n2) << "\n";
                } else if (op == "de") {
                    cout << "digite o numerador: \n";
                    cin >> n1;
                    cout << "digite o denominador: \n";
                    cin >> n2;
                    cout << "resultado: " << divisaoEuclidiana(n1, n2) << "\n";
                } else if (op == "m") {
                    cout << "digite o numerador: \n";
                    cin >> n1;
                    cout << "digite o denominador: \n";
                    cin >> n2;
                    cout << "resultado: " << mod(n1, n2) << "\n";
                } else if (op == "sp") {
                    int nP = 0;
                    cout << "digite número: \n";
                    cin >> nP;
                    cout << "resultado: " << sePrimo(nP) << "\n";
                } else if (op == "pe") {
                    cout << "digite número: \n";
                    cin >> n1;
                    cout << "digite número: \n";
                    cin >> n2;
                    primosEntreDoisNumeros(n1, n2);
                }
                cout << "\nPressione Q para fechar, ou qualquer outro para continuar.\n\n";
                cin >> continuar;
                if (continuar == "Q" || continuar == "q") break;
            }
        } else if (option == 2) {
            while (true) {
                string continuar;
                string cOuT;
                string texto = "";
    
                cout << "deseja usar cifraDeCesar ou traduzirCifraDeCesar (c/t)?: \n";
                cin >> cOuT;
                if (cOuT == "c") {
                    cout << "digite texto: \n";
                    cin.ignore();
                    getline(cin, texto);
                    cout << cifraDeCesar(texto) << "\n";
                } else if (cOuT == "t") {
                    cout << "digite texto: \n";
                    cin.ignore();
                    getline(cin, texto);
                    cout << traduzirCifraDeCesar(texto) << "\n";
                }
                cout << "\nPressione Q para fechar, ou qualquer outro para continuar.\n";
                cin >> continuar;
                if (continuar == "Q" || continuar == "q") break;
            }
        } else if (option == 3) {
            while (true) {
                string continuar;
                int n1 = -999999, n2 = -999999;
    
                cout << "digite n1: \n";
                cin >> n1;
                cout << "digite n2: \n";
                cin >> n2;
                if (n1 != -999999 && n2 != -999999) {
                    cout << (calcularMDC(n1, n2)) << "\n";
                }
                cout << "Pressione Q para fechar, ou qualquer outro para continuar.\n";
                cin >> continuar;
                if (continuar == "Q" || continuar == "q") break;
            }
        } else if (option == 4) {
            while (true) {
                string continuar;
                int n1 = -999999, n2 = -999999;
    
                cout << "digite n1: \n";
                cin >> n1;
                cout << "digite n2: \n";
                cin >> n2;
                if (n1 != -999999 && n2 != -999999) {
                    bezout(n1, n2);
                }
                cout << "Pressione Q para fechar, ou qualquer outro para continuar.\n";
                cin >> continuar;
                if (continuar == "Q" || continuar == "q") break;
            }
        } else if (option == 5) {
            while (true) {
                string continuar;
                string texto = "";
                int n1 = 0, n2 = 0, e = 0;
    
                cout << "digite o texto: \n";
                cin.ignore();
                getline(cin, texto);
                cout << "digite n1: \n";
                cin >> n1;
                cout << "digite n2: \n";
                cin >> n2;
                cout << "digite e: \n";
                cin >> e;
                criptografarRSA(texto, n1, n2, e);
                cout << "Pressione Q para fechar, ou qualquer outro para continuar.\n";
                cin >> continuar;
                if (continuar == "Q" || continuar == "q") break;
            }
        } else if (option == 6) {
            while (true) {
                string continuar;
                string texto = "";
                int n1 = 0, n2 = 0, e = 0;
    
                cout << "digite o texto: \n";
                cin.ignore();
                getline(cin, texto);
                cout << "digite n1: \n";
                cin >> n1;
                cout << "digite n2: \n";
                cin >> n2;
                cout << "digite e: \n";
                cin >> e;
                criptografarComplicadoRSA(texto, n1, n2, e);
                cout << "Pressione Q para fechar, ou qualquer outro para continuar.\n";
                cin >> continuar;
                if (continuar == "Q" || continuar == "q") break;
            }
        }
    }
}
