#include "includes/banco.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <limits>

std::string novo_nome;
std::string novo_cpf;
std::string nova_senha;

void criar_conta();
float digitar_valor(valor);

int main()
{

    SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

    banco cliente1;

    criar_conta();
    cliente1.setNome(novo_nome);
    cliente1.setCpf(novo_cpf);
    cliente1.setSenha(nova_senha);
    cliente1.setStatus(true);

    std::string senha_validar;

    //REPETICAO
    while (true)
    {
        int opcao;
        double valor;
        std::cout << "================================================================" << std::endl;
        std::cout << "BEM VINDO AO MOUNTAINBANK" << std::endl;
        std::cout << "VOCÊ DESEJA:" << std::endl;
        std::cout << "1. DEPOSITAR" << std::endl;
        std::cout << "2. DEPOSITAR POUPANÇA" << std::endl;
        std::cout << "3. SACAR" << std::endl;
        std::cout << "4. PIX" << std::endl;
        if (cliente1.getPoupanca() == false)
        {
            std::cout << "5. CRIAR CONTA POUPANÇA" << std::endl;
        }
        std::cout << "6. SALDO" << std::endl;
        std::cout << "7. SAIR" << std::endl;
        std::cout << "DIGITE A OPÇÃO QUE DESEJA:" << std::endl;
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "================================================================" << std::endl;

        // condição para encerramento
        if(opcao == 7)
        {
            std::cout << "O sistema foi encerrado." << std::endl;
            break;
        }
        // SWITCH
        switch (opcao)
        {
            case 1:
                cliente1.depositar(digitar_valor(valor));
                valor = 0;
                break;
            case 2:
                cliente1.depositar_poupanca(digitar_valor(valor));
                valor = 0;
                break;
            case 3:
                cliente1.sacar(digitar_valor(valor));
                valor = 0;
                break;
            case 4:
                if(senha_validar == cliente1.getSenha()){
                    cliente1.pix();
                }
                else{
                    std::cout << "SENHA ERRADA" << std::endl;
                }
                break;
            case 5:
                cliente1.criar_poupanca();
                break;
            case 6:
                std::cout << "SALDO CORRENTE: " << cliente1.getSaldo() << std::endl;
                if(cliente1.getPoupanca() == true){
                    std::cout << "SALDO POUPANCA: " << cliente1.getSaldoPoupanca() << std::endl;
                }
                // else{
                //     std::cout << "Voce ainda não tem conta poupança" << std::endl;
                // }
                break;
            default:
                break;
        }

    }
        
    
    

    system("Pause");
    return 0;
}


void criar_conta(){
    std::cout << "Digite seu nome completo" << std::endl;
    std::getline(std::cin, novo_nome);
    std::cout << "Digite seu cpf" << std::endl;
    std::getline(std::cin, novo_cpf);
    std::cout << "Digite uma senha segura" << std::endl;
    std::getline(std::cin, nova_senha);
}

float digitar_valor(int valor){
	std::cout << "Digite o valor" << std::endl;
    std::cin >> valor;
    return valor;
}
