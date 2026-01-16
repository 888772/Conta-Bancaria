#include "../includes/banco.hpp"
#include <iostream>
#include <string>
#include <cstring>

banco::banco()
    : nome(""),
      cpf(""),
      senha(""),
      saldo(500),
      saldo_poupanca(0),
      corrente(true),
      poupanca(false),
      status(true)
{
}

// ===================== GETTERS ============================

std::string banco::getNome() const{
    return nome;
}
std::string banco::getCpf() const{
    return cpf;
}
std::string banco::getSenha() const{
    return senha;
}

double banco::getSaldo() const {
    return saldo;
}

double banco::getSaldoPoupanca() const {
    return saldo_poupanca;
}

bool banco::getCorrente() const{
    return corrente;
}
bool banco::getPoupanca() const{
    return poupanca;
}

bool banco::getStatus() const{
    return status;
}

// ====================== SETTERS ===========================

void banco::setNome(const std::string& nome) {
    this->nome = nome;
}

void banco::setCpf(const std::string& cpf) {
    this->cpf = cpf;
}

void banco::setSenha(const std::string& senha) {
    this->senha = senha;
}

double banco::setSaldo(const double& saldo) {
    return this->saldo = saldo;
}

double banco::setSaldoPoupanca(const double& saldo_poupanca) {
    return this->saldo_poupanca = saldo_poupanca;
}

bool banco::setCorrente(const bool& corrente){
    return this->corrente = corrente;
}
bool banco::setPoupanca(const bool& poupanca){
    return this->poupanca = poupanca;
}

bool banco::setStatus(const bool& status){
    return this->status = status;
}


// ====================== SISTEMA DO BANCO ==================
bool validar(double valor){
    if (valor < 0)
    {
        std::cout << "ERRO: VALOR NEGATIVO" << std::endl;
        return false;
    }
    else{
        return true;
    }
    
}

bool banco::validar_saldo(double valor) const{
    return saldo >= valor;
}

double banco::depositar(double valor){
    if (!validar(valor))
    {
        return saldo; // não deposita
    }

    saldo += valor;

    return saldo;
}

double banco::depositar_poupanca(double valor){
    if (getPoupanca() == true)
    {
        if (!validar(valor))
        {
            return saldo_poupanca; // não deposita
        }

        saldo_poupanca += valor;

        return saldo_poupanca;
    }
    else
    {
        std::cout << "ERRO: CONTA POUPANÇA NÃO FOI CRIADA" << std::endl;
        return saldo_poupanca;
    }
    
    
}

double banco::sacar(double valor){
    if(!validar(valor)){
        return saldo;
    }
    if(!validar_saldo(valor)){
        std::cout << "ERRO: VALOR INDEFINIDO" << std::endl;
        return saldo;
    }
    saldo -= valor;
    return saldo;
}

double banco::sacar_poupanca(double valor){
    if(!validar(valor)){
        return saldo_poupanca;
    }
    if(!validar_saldo(valor)){
        std::cout << "ERRO: VALOR INDEFINIDO" << std::endl;
        return saldo_poupanca;
    }
    saldo_poupanca -= valor;
    return saldo_poupanca;
}

// VALIDADOR DE CARACTERES DO CHAT GPT
bool validarTamanho(const char* texto, size_t tamanhoExato) {
    return std::strlen(texto) == tamanhoExato;
}

double banco::pix(){
    int opcao;
    char cpf_recebedor[11];
    std::string numero_recebedor;
    std::string email_recebedor;
    double valor;

    std::cout << "===============================================" << std::endl;
    std::cout << "VOCÊ DESEJA FAZER PIX PARA:" << std::endl;
    std::cout << "1.NUMERO" << std::endl;
    std::cout << "2.CPF" << std::endl;
    std::cout << "3.EMAIL" << std::endl;
    std::cin >> opcao;
    std::cout << "===============================================" << std::endl;

    switch(opcao)
    {
    case 1:
        std::cout << "DIGITE O NÚMERO" << std::endl;
        std::cin >> numero_recebedor;
        std::cout << "DIGITE O VALOR" << std::endl;
        std::cin >> valor;
        if(!validar(valor)){
            std::cout << "ERRO NA TRANSAÇÃO" << std::endl;
            return saldo;
        }
        if (!validar_saldo(valor)){
            std::cout << "SALDO INSUFICIENTE" << std::endl;
            return saldo;
        }
        else{
            saldo -= valor;
            std::cout << "TRANSAÇÃO CONCLUIDA" << std::endl;
            valor = 0;
        }
        break;
    case 2:
        std::cout << "DIGITE O CPF" << std::endl;
        std::cin >> cpf_recebedor;
        // VALIDAR CPF
        if (validarTamanho(cpf_recebedor, 11)) {
            std::cout << "CPF valido\n";
            std::cout << "DIGITE O VALOR" << std::endl; // VALIDO, O PROCEDIMENTO É CONTINUADO
            std::cin >> valor;
            if(!validar(valor)){
                std::cout << "ERRO NA TRANSAÇÃO" << std::endl;
                return saldo;
            }
            if (!validar_saldo(valor)){
                std::cout << "SALDO INSUFICIENTE" << std::endl;
                return saldo;
            }
            else{
                saldo -= valor;
                std::cout << "TRANSAÇÃO CONCLUIDA" << std::endl;
                valor = 0;
            }
        } else {
            std::cout << "CPF invalido\n";
        }
        break;
    case 3:
        std::cout << "DIGITE O EMAIL" << std::endl;
        std::cin >> email_recebedor;
        std::cout << "DIGITE O VALOR" << std::endl;
        std::cin >> valor;
        if(!validar(valor)){
            std::cout << "ERRO NA TRANSAÇÃO" << std::endl;
            return saldo;
        }
        if (!validar_saldo(valor)){
            std::cout << "SALDO INSUFICIENTE" << std::endl;
            return saldo;
        }
        else{
            saldo -= valor;
            std::cout << "TRANSAÇÃO CONCLUIDA" << std::endl;
            valor = 0;
        }
        break;
    
    default:
        break;
    }
    return true;
}

bool banco::criar_poupanca(){

    if (poupanca == false)
    {
        std::string opcao;
        std::cout << "===============================================" << std::endl;
        std::cout << "VOCÊ DESEJA CRIAR UMA CONTA POUPANÇA:" << std::endl;
        std::cout << "yes/no?" << std::endl;
        std::cin >> opcao;

        std::string senha_validar;

        if(opcao == "Yes" or opcao == "yes" or opcao == "YES" or opcao == "Y" or opcao == "y"){
            std::cout << "Digite sua senha segura" << std::endl;
            std::cin >> senha_validar;
            if(senha_validar == getSenha()){
                std::cout << "CONTA POUPANÇA CRIADA COM SUCESSO!!!" << std::endl;
                std::cout << "===============================================" << std::endl;
                return poupanca = true;
            }
            else{
                std::cout << "SENHA ERRADA" << std::endl;
                std::cout << "===============================================" << std::endl;
            }
        }
        else if (opcao == "No" or opcao == "no" or opcao == "NO" or opcao == "N" or opcao == "n")
        {
            std::cout << "OPERAÇÃO NEGADA" << std::endl;
            std::cout << "===============================================" << std::endl;
        }
        else{
            std::cout << "OPERAÇÃO NEGADA: RESPOSTA INDEFINIDA" << std::endl;
            std::cout << "===============================================" << std::endl;
        }
    }
    else
    {
        std::cout << "A CONTA JÁ ESTÁ CRIADA" << std::endl;
    }
    
    return true;
}