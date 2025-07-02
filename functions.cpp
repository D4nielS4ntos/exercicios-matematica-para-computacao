#include <iostream>
using namespace std;


float piso(float num) {
    float numCopy = num;
    if (num >= 1) {
        while(numCopy >= 1) {
            numCopy--;
        }
    } else if (num <= 0) {
        while(numCopy < 0) {
            numCopy++;
        }
    }
    float floorDeNum = num - numCopy;

    return floorDeNum;
}


float teto(float num) {
    float numCopy = num;
    if (num >= 1) {
        while(numCopy >= 1) {
            numCopy--;
        }
    } else if (num <= 0) {
        while(numCopy < 0) {
            numCopy++;
        }
    }
    float floorDeNum = num - numCopy;
    if (numCopy > 0) floorDeNum++;

    return floorDeNum;
}


float divisao(float a, float b) {
    if (b == 0) {
        cout << "Não é possivel dividir por zero" << endl;
        return 0;
    }

    int sinal = 1;
    if (a < 0) {
        sinal *= -1;
        a *= -1;
    }
    if (b < 0) {
        sinal *= -1;
        b *= -1;
    }
    int bCopy = 0;
    int r = a;
    int q = 0;

    while (r >= b) {
        bCopy += b;
        q++;
        r = a - bCopy;
    }
    if (sinal == -1) q *= -1;
    if (sinal == -1) r *= -1;
    
    return q;
}


float resto(float a, float b) {
    int sinal = 1;
    if (a < 0) {
        sinal *= -1;
        a *= -1;
    }
    if (b < 0) {
        sinal *= -1;
        b *= -1;
    }
    int bCopy = 0;
    int r = a;
    int q = 0;

    while (r >= b) {
        bCopy += b;
        q++;
        r = a - bCopy;
    }
    if (sinal == -1) q *= -1;
    if (sinal == -1) r *= -1;
    
    return r;
}


float divisaoEuclidiana(int a, int b) {
    if (b == 0) {
        cout << "Não é possivel dividir por zero" << endl;
        return 0;
    }

    int r = 0;
    int q = 0;

    if (a > 0 && b > 0) {
        while (((q + 1) * b) <= a) {
            q++;
        }
    }
    else if (a < 0 && b < 0) {
        // q = 1;
        while ((a - (q * b)) < 0) {
            q++;
        }
    }
    else if (a > 0 && b < 0) {
        while (((q - 1) * b) <= a) {
            q--;
        }
    }
    else if (a < 0 && b > 0) {
        while (a - (q * b) < 0) {
            q--;
        }
    }
    
    return q;
}


float mod(int a, int b) {
    int q = divisaoEuclidiana(a, b);
    int r = a - q * b;
    return r;
}


bool sePrimo(int N) {
    bool primo = false;

    if (N < 2) {
        primo = false;
    } else {
        int i;
        for (i = 2; i <= abs(N); i++) {
            if (resto(N, i) == 0) {
                break;
            }
        } if (N == i) {
            primo = true;
        }
    }

    return primo;
}


void primosEntreDoisNumeros(int a, int b) {
    for (a; a<b; a++) {
        if (sePrimo(a)) {
            cout << a << " é primo, ";
        } else {
            cout << a << " não é primo, ";
        }
    }
    cout << "\n";
}


string cifraDeCesar(string palavras) {
    string alfabeto = "abcdefghijklmnopqrstuvwxyz";

    for (int lpalavra=0; lpalavra<palavras.size(); lpalavra++) {
        for (int l=0; l<26; l++) {
            if (palavras[lpalavra] == alfabeto[l]) {
                int letraAtual = resto((l + 3), 26);
                palavras[lpalavra] = alfabeto[letraAtual];
                break;
            }
        }
    }

    return palavras;
}


string traduzirCifraDeCesar(string palavras) {
    string alfabeto = "abcdefghijklmnopqrstuvwxyz";
    for (int lpalavra=0; lpalavra<palavras.size(); lpalavra++) {
        for (int l=0; l<26; l++) {
            if (palavras[lpalavra] == alfabeto[l]) {
                int letraAtual = l - 3;
                if (letraAtual < 0) letraAtual += 26;
                palavras[lpalavra] = alfabeto[letraAtual];
                break;
            }
        }
    }

    return palavras;
}


int calcularMDC(int a, int b) {
    int mdc = b;
    int r = resto(a, b);

    cout << "O resto de " << a << " dividido por " << b << " é " << r << "\n";
    if (r == 0) {
        mdc = b;
    } else {
        return calcularMDC(b, r);
    }
    if (mdc < 0) mdc *= -1;

    return mdc;
}


void bezout(int a, int b) {
    int s0 = 1, s1 = 0;
    int t0 = 0, t1 = 1;

    while (b != 0) {
        cout << "-------------------------------------\n";
        int q = piso(divisao(a, b));
        int r = a % b;

        cout << "a: " << a << ", b: " << b << "\n";
        cout << "s0: " << s0 << ", s1: " << s1 << "\n";
        cout << "t0: " << t0 << ", t1: " << t1 << "\n\n";

        cout << "q: " << q << " = " << a << " / " << b << "\n";
        cout << "r: " << r << " = " << a << " % " << b << "\n";
        a = b;
        b = r;
        
        int s = s0 - q * s1;
        cout << "s: " << s << " = " << s0 << " - " << q << " * " << s1 << "\n";
        s0 = s1;
        s1 = s;
        
        int t = t0 - q * t1;
        cout << "t: " << t << " = " << t0 << " - " << q << " * " << t1 << "\n";
        t0 = t1;
        t1 = t;
    }
    cout << "MDC: " << a << " x: " << s0 << " y: " << t0 << "\n";
    cout << "-------------------------------------\n";
}


int bezoutDoRSA(int a, int b) {
    int s0 = 1, s1 = 0;
    int t0 = 0, t1 = 1;

    while (b != 0) {
        cout << "-------------------------------------\n";
        int q = piso(divisao(a, b));
        int r = a % b;

        cout << "a: " << a << ", b: " << b << "\n";
        cout << "s0: " << s0 << ", s1: " << s1 << "\n";
        cout << "t0: " << t0 << ", t1: " << t1 << "\n\n";

        cout << "q: " << q << " = " << a << " / " << b << "\n";
        cout << "r: " << r << " = " << a << " % " << b << "\n";
        a = b;
        b = r;
        
        int s = s0 - q * s1;
        cout << "s: " << s << " = " << s0 << " - " << q << " * " << s1 << "\n";
        s0 = s1;
        s1 = s;
        
        int t = t0 - q * t1;
        cout << "t: " << t << " = " << t0 << " - " << q << " * " << t1 << "\n";
        t0 = t1;
        t1 = t;
    }
    cout << "MDC: " << a << " x: " << s0 << " y: " << t0 << "\n";
    cout << "-------------------------------------\n";
    
    return s0;
}


int exponenciacaoModular(int base, int exp, int mod) {
    int resultado = 1;
    base = base % mod; // Garante que a base esteja dentro do intervalo do módulo

    while (exp > 0) {
        // Se o expoente for ímpar, multiplica o resultado pela base
        if (exp % 2 == 1) {
            resultado = (resultado * base) % mod;
        }
        // Divide o expoente por 2 e eleva a base ao quadrado
        exp = exp / 2;
        base = (base * base) % mod;
    }

    return resultado;
}


string converterASCIIemTexto(int arr[], int tamanho) {
    string textoDeASCIIemTexto = "";
    for (int i=0; i<tamanho; i++) {
        textoDeASCIIemTexto += arr[i];
    }
    return textoDeASCIIemTexto;
}


void criptografarRSA(string texto, int p, int q, int e) {
    if (sePrimo(p) != true || sePrimo(q) != true) {
        cout << "[ERRO]: p, q precisam ser primos\n";
        return;
    }

    cout << "--------------------------------------\n";
    cout << "texto: " << texto << "\n";

    // converter alfabeto para 1-26
    string alfabeto = " abcdefghijklmnopqrstuvwxyz";
    int textoEmNumeros[texto.size()];
    for (int i=0; i<texto.size(); i++) {
        for (int l=0; l<26; l++) {
            if (texto[i] == alfabeto[l]) {
                textoEmNumeros[i] = l;
            }
        }
    }
    cout << "texto em ASCII: ";
    for (auto l: textoEmNumeros) cout << l << ", ";
    cout << "\n";

    // gerar p, q e N
    int N = p * q;
    cout << "p: " << p << " q: " << q << " N: " << N << "\n";
    // Função Totiente de Euler
    int phiDeN = (p-1)*(q-1);
    cout << "phi de N: " << phiDeN << "\n";
    // escolher e = 3 pois é mais fácil
    // int e = 3;
    cout << "e: " << e << "\n";
    if (calcularMDC(phiDeN, e) != 1) {
        cout << "[ERRO]: e não é coprimo de φ(n)\n";
        return;
    }
    // escolher d inverso de e módulo φ(n)
    int d = 0;
    // while (d < phiDeN) {
    //     d++;
    //     if ((d * e) % phiDeN == 1) {
    //         break;
    //     }
    // }
    d = bezoutDoRSA(e, phiDeN);
    if (d == phiDeN) {
        cout << "[ERRO]: não foi possível encontrar o d\n";
        return;
    }
    if (d < 0) {
        while (d < 0) {
            d += phiDeN;
        }
    }
    if (d * e % phiDeN != 1) {
        cout << "[ERRO]: não foi possível encontrar o d\n";
        return;
    }
    cout << "d: " << d << "\n";

    // criptografar texto
    int textoRSA[texto.size()];
    for (int i=0; i<texto.size(); i++) {
        int c = exponenciacaoModular(textoEmNumeros[i], e, N); //int(float(pow(textoEmNumeros[i], e))) % N;
        textoRSA[i] = c;
    }
    cout << "\ntexto criptografado: ";
    for (auto c : textoRSA) cout << c << ", ";
    cout << "\n";
    
    // descriptografar
    int textoDescriptografado[texto.size()];
    for (int i=0; i<texto.size(); i++) {
        int m = exponenciacaoModular(textoRSA[i], d, N);
        textoDescriptografado[i] = m;
    }

    cout << "\ntexto descriptografado: ";
    for (auto m : textoDescriptografado) cout << m << ", ";
    cout << "\n--------------------------------------\n";
}


void criptografarComplicadoRSA(string texto, int p, int q, int e) {
    if (sePrimo(p) != true || sePrimo(q) != true) {
        cout << "[ERRO]: p, q precisam ser primos\n";
        return;
    }

    cout << "--------------------------------------\n";
    cout << "texto: " << texto << "\n";

    // converter para ASCII
    // int textoAS[texto.size()];
    int textoASCII[texto.size()][2];
    for (int i=0; i<texto.size(); i++) {
        // textoAS[i] = texto[i];
        textoASCII[i][0] = texto[i] / 10;
        textoASCII[i][1] = texto[i] % 10;
    }
    // for (auto l: textoAS) cout << l << ", ";
    cout << "texto em ASCII: \n";
    for (int x=0; x<texto.size(); x++) {
        for (int y=0; y<2; y++) {
            cout << textoASCII[x][y] << ", ";
        }
        cout << "\n";
    }
    cout << "\n";

    // gerar p, q e N
    int N = p * q;
    cout << "p: " << p << " q: " << q << " N: " << N << "\n";
    // Função Totiente de Euler
    int phiDeN = (p-1)*(q-1);
    cout << "phi de N: " << phiDeN << "\n";
    // escolher e = 3 pois é mais fácil
    // int e = 3;
    cout << "e: " << e << "\n";
    // escolher d
    int d = 0;
    // while (d < phiDeN) {
    //     d++;
    //     if ((d * e) % phiDeN == 1) {
    //         break;
    //     }
    // }
    d = bezoutDoRSA(e, phiDeN);
    if (d == phiDeN) {
        cout << "[ERRO]: não foi possível encontrar o d\n";
        return;
    }
    if (d < 0) {
        while (d < 0) {
            d += phiDeN;
        }
    }
    if (d * e % phiDeN != 1) {
        cout << "[ERRO]: não foi possível encontrar o d\n";
        return;
    }
    cout << "d: " << d << "\n";

    // criptografar texto
    int textoRSA[texto.size()][2];
    for (int x=0; x<texto.size(); x++) {
        for (int y=0; y<2; y++) {
            int c = exponenciacaoModular(textoASCII[x][y], e, N);//int(float(pow(textoASCII[x][y], e))) % N;
            textoRSA[x][y] = c;
        }
    }
    cout << "\ntexto criptografado: \n";
    for (int x=0; x<texto.size(); x++) {
        for (int y=0; y<2; y++) {
            cout << textoRSA[x][y] << ", ";
        }
        cout << "\n";
    }

    // descriptografar
    int textoDescriptografado[texto.size()][2];
    for (int x=0; x<texto.size(); x++) {
        for (int y=0; y<2; y++) {
            int m = exponenciacaoModular(textoRSA[x][y], d, N);
            textoDescriptografado[x][y] = m;
        }
    }

    cout << "\ntexto descriptografado: \n";
    int textoDescriptografadoASCII[texto.size()];
    for (int x=0; x<texto.size(); x++) {
        for (int y=0; y<2; y++) {
            cout << textoDescriptografado[x][y] << ", ";
        }
        // converte a matriz para um array
        textoDescriptografadoASCII[x] = textoDescriptografado[x][0] * 10 + textoDescriptografado[x][1];
        cout << "\n";
    }
    cout << "\n";
    for (int i : textoDescriptografadoASCII) cout << i << ", ";
    cout << "\n";
    cout << converterASCIIemTexto(textoDescriptografadoASCII, texto.size());
    cout << "\n--------------------------------------\n";
}
