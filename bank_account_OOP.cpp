#include <iostream>
#include <string>
#include <ctime>

using std :: string;

class Conta_Bancaria{
    private:
        string Nome_titular;
        float Saldo;

    public:
        //Construtor
        Conta_Bancaria(string t, float s){
            Nome_titular = t;

            if(s > 0){
                Saldo = s;
            }else{
                std :: cout << "Saldo inicial inválido. Configurando para 0.\n";
                Saldo = 0;
            }
            
        }

        //Metodos

        //getter
        string get_titular(){
            return Nome_titular;
        }

        bool Sacar(float saque){
            if(saque > Saldo){
                std :: cout << "Erro: Saque de R$" << saque << " excede o saldo disponível.\n";
            }else{
                Saldo -= saque;
                std :: cout << "Saque de R$" << saque << " realizado com sucesso.\n";
            }
        }

        bool Depositar(float dep){
            if(dep > 0){
                Saldo += dep;
                std :: cout << "Depósito de R$" << dep << " realizado com sucesso.\n";
            }else{
                std :: cout << "Valor para deposito Invalido" << '\n';
            }
        }

        void Exibir_saldo(){
            std :: cout << "Saldo atual: R$" << Saldo << "\n";
        }
};

class Transacao: public Conta_Bancaria{
    private:
        string tipo;
        float valor;
        int data;

    public:
        
};

int main(){
    Conta_Bancaria conta1 = Conta_Bancaria("Gustavo", 1000);

    conta1.Sacar(500);
    conta1.Depositar(250);
    conta1.Exibir_saldo();
    return 0;
}