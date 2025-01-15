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
        void set_titular(string t){
            Nome_titular = t;
        }
        string get_titular(){
            return Nome_titular;
        }

        void Sacar(float saque){
            if(saque > Saldo){
                std :: cout << "Erro: Saque de R$" << saque << " excede o saldo disponível.\n";
            }else{
                Saldo -= saque;
                std :: cout << "Saque de R$" << saque << " realizado com sucesso.\n";
            }
        }

        void Depositar(float dep){
            if(dep > 0){
                Saldo += dep;
                std :: cout << "Depósito de R$" << dep << " realizado com sucesso.\n";
            }else{
                std :: cout << "Valor para deposito Invalido" << '\n';
            }
        }

        void Exibir_saldo(){
            std :: cout << "\nTitular: " << get_titular() << '\n';
            std :: cout << "Saldo atual: R$" << Saldo << "\n";
        }
};

int main(){

    string titular = "Guto";
    float quant_inicial = 1000;

    Conta_Bancaria conta = Conta_Bancaria(titular, quant_inicial);

    conta.Depositar(1000);
    conta.Sacar(500);
    conta.Exibir_saldo();
    return 0;
}