#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <typeinfo>

using namespace std;
/*
 2. praktiskais darbs "Mantoðana"
 Autors   : Toms Svars
 Grupa    : P2-4
 Variants : 14 "Telpa"
 Uzdevums :
 Izveidot sava individuâlâ varianta bâzes klasi ar trîs atribûtiem: publisko, aizsargâto un privâto.

 Izveidot divus konstruktorus (vienu – bez parametriem), kas inicializç klases atribûtus un destruktoru,
 kas paziòo par objekta iznîcinâðanu.

 Izveidojiet set un get metodes privâtajam un aizsargâtajam atribûtam. Izveidot print metodi
 un kâdu savu metodi, kas veic aprçíinus (ja iespçjams, tad ar klases atribûtiem) un atgrieþ vçrtîbu.

 Izveidot atvasinâto klasi, kura publiski manto bâzes klasei un papildina bâzes klasi
 ar diviem privâtiem atribûtiem. Pievienot atbilstoðâs set un get metodes.

 Izveidot divus konstruktorus, kas inicializç jaunos klases atribûtus un destruktoru. Vienam no tiem
 atklâtâ veidâ jâizsauc bâzes klases konstruktoru, nododot tam parametrus.

 Pârdefinçjiet bâzes klases metodi print, lai tâ izdrukâtu visu atribûtu vçrtîbas.

 Nodemostrçt visu metoþu izsaukumu, izveidojot gan bâzes klases, gan atvasinâtâs klases objektus.
 */

class Room {
    // Bāzes klases definēšana
private:
	/*Bazes klases privatais mainigais ,kurs neattiecas uz atvasinato Hospital
	privato mainigo nevar mainīt arpus bāzes klases
    */
	string room_street;

protected:
	//Mainigie ,kurus var pieskirt tikai Room un Hospital
	float room_price;

public:
	// Mainigie ,kurus var brivi izmantot visâ programmâ
	/*
	[static int] Statiskais mainigais ,kuršs uzskaita visus izveidotos objektus*/
	static int room_count;
	string room_name;

	// Non-Overloaded Constructor
	Room(){
	this->room_count++;
	this->room_name = "Kabinets";
	this->room_street = "Rigas iela 18";
	this->room_price = 780.000;
    }
	// Overloaded constructor
	Room(string name,string street, float price) {
    this->room_count++;
	this->room_name = name;
	this->room_street = street;
	this->room_price = price;
    }
	// Deconstructor
	~Room(){
	cout << endl << " Telpa numurs :  " << room_count <<" "<< room_name<< " "  << "ir pardota."<< endl;
	room_count--;
	getch();
    }
	// RoomName method
	string getRoomName();
	void setRoomName(string);
	// RoomStreet method
	string getRoomStreet();
	void setRoomStreet(string);
	// RoomPrice
	void setRoomPrice(float);
	// printInfo
	void printInfo();
	// paymentMethode
	float payment(float, int);
};
//Static integer
int Room::room_count = 0;

// Metodes RoomName
string Room::getRoomName() {
	return room_name;
}

void Room::setRoomName(string name) {
	this->room_name = name;
}

// Metodes Roomstreet
string Room::getRoomStreet() {
	return room_street;
}

void Room::setRoomStreet(string street) {
	this->room_street = street;
}
// Metodes RoomPrice
void Room::setRoomPrice(float price) {
	this->room_price = price;
}
// Kredita aprekina metode
float Room::payment(float room_price, int month) {
	return this->room_price / month;
}
// printInfo
void Room::printInfo() {
	cout << "Telpas  nr." << room_count << endl <<
		"Telpas nosaukums : " << room_name << endl <<
		"Telpas adrese : " << room_street << endl << "Telpas cena : " <<
		room_price << endl;
}

// Secondary Class Hospital
class Hospital : public Room {
private:
	string hospital_empl;
	string hospital_date;

public:

	// empl
	string getEmpl();
	void setEmpl(string empl);
	// Date
	string getDate();
    void setDate(string date);

    // Atvasinatas klases aprekinu metode
	float payment(float ,int);

	// Print Order
	void printInfo();

	// Atvasinatas Class Constructor
	Hospital(string empl, string date, string name,string street, float price) : Room(name,street, price) {
		this->room_name = name;
		this->room_price = price;
		this->hospital_empl = empl;
		this->hospital_date = date;
	}
	~Hospital(){
        cout << "Telpa nr. " << room_count << " " << room_name << " tika pardota" << endl;
        room_count--;
        getch();
	}

};
// empl metodes
string Hospital::getEmpl() {
	return this->hospital_empl;
}
void Hospital::setEmpl(string empl) {
	this->hospital_empl = empl;
}
// Date metodes
string Hospital::getDate() {
	return this->hospital_date;
}
void Hospital::setDate(string date) {
	this->hospital_date = date;
}
// Atvasina bazes klases metodi payment()
float Hospital::payment(float room_price, int month) {
	return this->room_price * month;
}
// Mikstas mebeles  : Print order
void Hospital::printInfo() {
	cout << "Telpa numur." << this->room_count << endl <<
	 "Telpas nosaukums :" << this->getRoomName() << endl <<
	"Telpas adrese : " << this->getRoomStreet() << endl <<
	 "Telpas cena: " << this->room_price << " EUR" << endl <<
	"Telpas darbinieku skaits:" << this->getEmpl() << endl<<
	 "Datums ,kad telpa tika izireta: " << this->getDate() << endl;
}

	string inputNonEmptyString() {
		string tempString;
		while(1) {
			try	{
				getline(cin, tempString);
				if (tempString != "")
					return tempString;
				cout << "The string must not be empty";
			} catch (...) {
					cout << "Error in input! There is an issue with the string you provided.\n";
			}
		}
	}

int main() {

	int month;
	float price;
	string name, street;
	/*
	 [int] Month - Variable for function payment
	 [float] Price - Variable for room_price
	 [string] Name - Variable for room_name
              Street - Variable for room_street
	 */
	cout << "Ievadiet telpas nosaukumu : ";
	name = inputNonEmptyString();
	cout << "Ievadiet telpas adresi : ";
	 street = inputNonEmptyString();
	cout << "Ievadiet telpas cenu : ";
	cin >> price;
	while (price <= 0){
            if(price<=0){
                cout << "Ievadiet telpas cenu : ";
                    cin >> price;
                }
            }


	cout << "Ievadiet menesu skaitu : ";
	cin >> month;
		while (month <= 0){
            if(month<=0){
                cout << "Ievadiet telpas cenu : ";
                    cin >> month;
                }
            }
    //Statisks objekta ,kurs izmanto Overloaded Constructor
	Room obj1;
	obj1.setRoomName(name);
	obj1.setRoomStreet(street);
	obj1.setRoomPrice(price);
	obj1.printInfo();
	// Bazes metode
	cout << "Telpas ikmenesa iemaksas cena : " <<obj1.payment(price,month) << endl;

	// Dinamisks objeks ,kurs izmanto Non-Overloaded Constructor.
	Room *obj3 = new Room();
	obj3->printInfo();



	// Constructor to give empl and date
	Hospital *obj2 = new Hospital("150", "01.12.2011","Klase","Skolas iela",918.123);

	obj2->printInfo();
	// Atvasinata metode
	cout << "Preces var nopirkte : " << obj2->payment(price,month)<< endl;



	delete obj2,obj3;

	return 0;
}
