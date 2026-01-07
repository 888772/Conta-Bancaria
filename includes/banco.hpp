#ifndef BANCO_HPP
#define BANCO_HPP

#include <string>

class banco
{
private:
    std::string nome;
    std::string cpf;
    std::string senha;
    double saldo;
    bool corrente;
    bool poupanca;
    bool status;
public:
    banco();
    std::string getNome() const;
    std::string getCpf() const;
    std::string getSenha() const;
    bool getStatus() const;
    bool getCorrente() const;
    bool getPoupanca() const;
    double getSaldo() const;

    void setNome(const std::string& nome);
    void setCpf(const std::string& cpf);
    void setSenha(const std::string& senha);
    bool setStatus(const bool& status);
    bool setCorrente(const bool& corrente);
    bool setPoupanca(const bool& poupanca);
    double setSaldo(const double& saldo);
    

    bool validar_saldo(double valor) const;
    double depositar(double valor);
    double sacar(double valor);
    double pix();
    bool criar_poupanca();

};



#endif