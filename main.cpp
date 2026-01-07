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
        std::cout << "BEM VINDO AO MONTAINBANK" << std::endl;
        std::cout << "VOCÊ DESEJA:" << std::endl;
        std::cout << "1. DEPOSITAR" << std::endl;
        std::cout << "2. SACAR" << std::endl;
        std::cout << "3. PIX" << std::endl;
        if (cliente1.getPoupanca() == false)
        {
            std::cout << "4. CRIAR CONTA POUPANÇA" << std::endl;
        }
        std::cout << "5. SALDO" << std::endl;
        std::cout << "6. SAIR" << std::endl;
        std::cout << "DIGITE A OPÇÃO QUE DESEJA:" << std::endl;
        std::cin >> opcao;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "================================================================" << std::endl;

        // condição para encerramento
        if(opcao == 6)
        {
            std::cout << "O sistema foi encerrado." << std::endl;
            break;
        }
        // SWITCH
        switch (opcao)
        {
            case 1:
                std::cout << "Digite o valor a ser Depositado" << std::endl;
                std::cin >> valor;
                cliente1.depositar(valor);
                valor = 0;
                break;
            case 2:
                std::cout << "Digite o valor a ser sacado" << std::endl;
                std::cin >> valor;
                cliente1.sacar(valor);
                valor = 0;
                break;
            case 3:
                std::cout << "Digite sua senha segura" << std::endl;
                std::cin >> senha_validar;
                if(senha_validar == cliente1.getSenha()){
                    cliente1.pix();
                    valor = 0;
                }
                else{
                    std::cout << "SENHA ERRADA" << std::endl;
                }
                break;
            case 4:
                cliente1.criar_poupanca();
                break;
            case 5:
                std::cout << "SALDO: " << cliente1.getSaldo() << std::endl;
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
