#include "Date.h"

Date::Date(){
	dia = 0;
	mes = 0;
	ano = 0;
}

Date::Date(string date) {
	this->dia = stoi(date.substr(0, 2));
	this->mes = stoi(date.substr(3, 2));
	this->ano = stoi(date.substr(6, 4));
}

Date::Date(unsigned int dia, unsigned int mes, unsigned int ano) {
	this->dia = dia;
	this->mes = mes;
	this->ano = ano;
}

unsigned int Date::getDia() const {
	return dia;
}

unsigned int Date::getMes() const {
	return mes;
}

unsigned int Date::getAno() const {
	return ano;
}

void Date::setDia(unsigned int dia) {
	this->dia = dia;
}

void Date::setMes(unsigned int mes) {
	this->mes = mes;
}

void Date::setAno(unsigned int ano) {
	this->ano = ano;
}

bool Date::operator<(const Date& d) const {
	if ((365 * ano + 31 * mes + dia) < (365 * d.getAno() + 31 * d.getMes() + d.getDia()))
		return true;
	return false;
}


bool Date::operator>(const Date& d) const {
	if ((365 * ano + 31 * mes + dia) > (365 * d.getAno() + 31 * d.getMes() + d.getDia()))
		return true;
	return false;
}

bool Date::operator==(const Date& d) const{
	return (365 * ano + 31 * mes + dia) == (365 * d.getAno() + 31 * d.getMes() + d.getDia());
}

bool Date::operator!=(const Date& d) const {
	return (365 * ano + 31 * mes + dia) != (365 * d.getAno() + 31 * d.getMes() + d.getDia());
}

ostream& operator <<(ostream& out, const Date& date) {
	out << setfill('0') << setw(2) << to_string(date.dia) << "/" << setfill('0') << setw(2) << to_string(date.mes) << "/" << setfill('0') << setw(4) << to_string(date.ano);
	return out;
}