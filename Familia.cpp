#include "Familia.hpp"

Familia::Familia():nume(NULL),prenume(NULL)
{
	for(int i=0;i<3;i++)
		varsta[i]=0;
}

Familia::Familia(const char* nume, const char* prenume, int varsta[])
{
	this->nume = new char[strlen(nume) + 1];
	strcpy(this->nume, nume);
    this->prenume = new char[strlen(prenume) + 1];
	strcpy(this->prenume, prenume);
	for(int i=0; i < 3; i++)
		this->varsta[i] = varsta[i];
}

Familia::Familia(const Familia& obj)
{
	nume = NULL;
	prenume = NULL;
	*this = obj;
}

Familia& Familia::operator=(const Familia& obj)
{
	if(nume!=NULL)
		delete []nume;
	this->nume=new char[strlen(obj.nume)+1];
	strcpy(this->nume,obj.nume);
    if(prenume!=NULL)
		delete []prenume;
	this->prenume=new char[strlen(obj.prenume)+1];
	strcpy(this->prenume,obj.prenume);

	for(int i=0; i<3; i++)
	{
		this->varsta[i]=obj.varsta[i];
	}

	return *this;
}

istream& operator>>(istream& in, Familia& obj)
{
	char buffer[100];
    cout << "Prenume :";
	in >> buffer;
	if (obj.prenume != NULL)
		delete []obj.prenume;
	obj.prenume = new char[strlen(buffer) + 1];
	strcpy(obj.prenume,buffer);

    buffer==NULL;
	cout << "Nume :";
	in >> buffer;
	if (obj.nume != NULL)
		delete []obj.nume;
	obj.nume = new char[strlen(buffer) + 1];
	strcpy(obj.nume,buffer);

	cout << "Varsta :";
	for(int i=0; i < 3; i++)
    in >> obj.varsta[i];
	return in;
}
char* Familia::getNume()
{
	return nume;
}
char* Familia::getPrenume()
{
	return prenume;
}
int Familia::getAn()
{
   int aux;
   aux=varsta[0];
   return aux;
}

int Familia::getLuna()
{
   int aux;
   aux=varsta[1];
   return aux;
}

int Familia::getZi()
{
   int aux;
   aux=varsta[2];
   return aux;
}

bool Familia:: operator <( Familia& F){
	if((*this).getAn() < F.getAn())
	 return true;
	else
	 return false;
}

Familia::~Familia()
{
	delete []nume;
	delete []prenume;
}

