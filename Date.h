#pragma once

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
/**
 * @brief classe relativa a data
 */
class Date {
	unsigned int dia, mes, ano;
public:
    /**
     * @brief construtor vazio da classe Date
     */
	Date();
	/**
	 * @brief separa a string com a data e armazena o dia, mes e ano
	 * @param date string com uma data
	 */
	Date(string date);
	/**
	 *
	 * @param dia unsigned int com dia
	 * @param mes unsigned int com mes
	 * @param ano unsigned int com ano
	 */
	Date(unsigned int dia, unsigned int mes, unsigned int ano);
    /**
     * @brief retorna um unsigned int com o dia da data
     * @return unsigned int com o dia da data
     */
	unsigned int getDia() const;
	/**
	 * @brief retorna um unsigned int com o mes da data
	 * @return unsigned int com o mes da data
	 */
	unsigned int getMes() const;
	/**
	 * @brief retorna um unsigned int com o ano da data
	 * @return unsigned int com o ano da data
	 */
	unsigned int getAno() const;

	/**
	 * @brief altera o dia de uma data
	 * @param dia unsigned int com  dia da data
	 */
	void setDia(unsigned int dia);
	/**
	 * @brief altera o mes de uma data
	 * @param mes unsigned int com o mes de uma data
	 */
	void setMes(unsigned int mes);
	/**
	 * @brief altera o ano de uma data
	 * @param ano unsigned int com o ano de uma data
	 */
	void setAno(unsigned int ano);

	/**
	 * @brief mostra uma data no formata DD/MM/AAAA
	 * @param out ostream vazia
	 * @param date objeto da classe Date com a data
	 * @return ostream com a data no formato DD/MM/AAAA
	 */
	friend ostream& operator <<(ostream& out, const Date& date);
	/**
	 * @brief operador que compara se uma data é inferior a outra
	 * @param d objeto da classe Date com a data
	 * @return bool resultante da comparacao entre duas datas
	 */
	bool operator < (const Date& d) const;
	/**
	 * @brief operador que compara se uma data é superior a outra
	 * @param d objeto da classe Date com a data
	 * @return bool resultante da comparacao entre duas datas
	 */
	bool operator > (const Date& d) const;
	/**
	 * @brief operador que compara se uma data é igual a outra
	 * @param d objeto da classe Date com a data
	 * @return bool resultante da comparacao entre duas datas
	 */
	bool operator == (const Date& d) const;
	/**
	 * @brief operador que compara se uma data é diferente de outra
	 * @param d objeto da classe Date com a data
	 * @return bool resultante da comparacao entre duas datas
	 */
	bool operator!=(const Date& d) const;
};