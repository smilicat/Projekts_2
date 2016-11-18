#include <iostream>
#include <string>
#include <conio.h>
#include <typeinfo>

using namespace std;
/*
 2. praktiskais darbs "Mantoðana"
 Autors   : Kirils Volobujevs
 Grupa    : P2-4
 Variants : 8 "Mebeles"
 Uzdevums :
Izmainît otro praktisko darbu:
 1. Bâzes klases rçíinoðo metodi pârveidot par tîri virtuâlo.
 2. Papildinât programmu ar vçl vienu atvasinâto klasi atbilstoði
  individuâlajam uzdevumam. Pievienot tai savu atribûtu un savas metodes.
 3. Realizçt bâzes klases rçíinoðo metodi atvasinâtajâs klasçs
   (vçlams - ar atðíirîgu realizâciju).
	3.1. Pievienot katrâ atvasinâtajâ klasç tai unikâlo metodi.
 4. Main funkcijâ izveidot masîvu no norâdçm uz bâzes klases elementiem,
  ar to palîdzîbu izveidot atvasinâto klaðu objektus pçc lietotâja izvçles
  (lietotâjs izvçlâs gan objekta tipu, gan konstruktora variantu).
 5. Izmantojot dinamisko tipu pârveidoðanu un bâzes klases norâdi izsaukt visas programmas metodes
 (ar dynamic cast palîdzîbu izsaukt arî unikâlâs atvasinâto klaðu metodes).
*/

class Furniture {
private:
	// Bazes klases privatais mainigais ,kurs neattiecas uz SoftFur
	string furniture_color;

protected:
	// Mainigie ,kurus var pieskirt tikai Furniture un SoftFur
	static int furniture_count;
	float furniture_price;

public:
	// Mainigie ,kurus var brivi izmantot visâ programmâ
	string furniture_name;
	string order_date;

	// Constructor
	Furniture();
	// Overloaded constructor
	Furniture(string, string, float);
	Furniture(string, float);
	// Deconstructor
	~Furniture();
	// FurnitureName
	string getFurnitureName();
	void setFurnitureName(string);
	// FurnitureColor
	string getFurnitureColor();
	void setFurnitureColor(string);
	// FurniturePrice
	void setFurniturePrice(float);
	// PrintOrder
	void printOrder();
	// CreditMethode
	virtual float credit(float, int) = 0;
};

// Static integer
int Furniture::furniture_count = 0;

// Constructor
Furniture::Furniture() {
	this->furniture_count++;
	this->furniture_name = "Galds";
	this->furniture_color = "Yellow";
	this->furniture_price = 780.1;
}

// Overloaded constructor
Furniture::Furniture(string name, string color, float price) {
	this->furniture_name = name;
	this->furniture_color = color;
	this->furniture_price = price;
}

Furniture::Furniture(string name, float price) {
	this->furniture_name = name;
	this->furniture_price = price;
}

// Deconstructor
Furniture::~Furniture() {
	cout << endl << " Dzestas preces  numurs : " << furniture_count << endl <<
		"Preces nosaukums : " << furniture_name;
	furniture_count--;
	getch();

}

// Metodes FurnitureName
string Furniture::getFurnitureName() {
	return furniture_name;
}

void Furniture::setFurnitureName(string name) {
	this->furniture_name = name;
}

// Metodes FurnitureColor
string Furniture::getFurnitureColor() {
	return furniture_color;
}

void Furniture::setFurnitureColor(string color) {
	this->furniture_color = color;
}

// Metodes furniturePrice
void Furniture::setFurniturePrice(float price) {
	this->furniture_price = price;
}

// Kredita aprekina metode
float Furniture::credit(float furniture_price, int month) {
	return this->furniture_price / month;
}

// printOrder
void Furniture::printOrder() {
	cout << "Main Preces Mebele nr." << furniture_count << endl <<
		"Mebeles nosaukums : " << furniture_name << endl <<
		"Mebeles Krasas : " << furniture_color << endl << "Mebeles cena : " <<
		furniture_price << endl;
}

// Secondary Class SoftFur
class SoftFur : public Furniture {
private:
	string softFur_serial;
	string softFur_date;

public:

	// Serial
	string getSerial();
	void setSerial(string serial);
	// Date
	string getDate();
	float credit(float, int);
	void setDate(string date);
	// Print Order
	void printOrder();


	// Atvasinatas Class Constructor
	SoftFur(string serial, string date, string name, string color, float price)
		: Furniture(name, color, price) {
		this->furniture_name = name;
		this->furniture_price = price;
		this->softFur_serial = serial;
		this->softFur_date = date;
		this->furniture_count++;
		cout << endl;
	}

};

// Serial metodes
string SoftFur::getSerial() {
	return this->softFur_serial;
}

void SoftFur::setSerial(string serial) {
	this->softFur_serial = serial;
}

// Date metodes
string SoftFur::getDate() {
	return this->softFur_date;
}

void SoftFur::setDate(string date) {
	this->softFur_date = date;
}

// Atvasina bazes klases metodi Credit()
float SoftFur::credit(float furniture_price, int month) {
	return this->furniture_price * month;
}

// Mikstas mebeles  : Print order
void SoftFur::printOrder() {
	cout << "Mebele numur." << this->furniture_count << endl;
	cout << "Mebeles nosaukums :" << this->getFurnitureName() << endl;
	cout << "Mebeles Krasa : " << this->getFurnitureColor() << endl;
	cout << "Summa: " << this->furniture_price << " EUR" << endl;
	cout << "Pasutijums Nr. " << this->getSerial() << endl;
	cout << "Datums: " << this->getDate() << endl;
}

class Other : public Furniture {
protected:
	int other_weight;
	float other_size;

public:
	// Non-Overloaded Constructor
	Other() {
		other_weight = 5;
		other_size = 12.1;

	}

	Other(float weight, float size, string name, float price)
		: Furniture(name, price) {
		this->furniture_name = name;
		this->furniture_price = price;
		this->other_weight = weight;
		this->other_size = size;
		this->furniture_count++;

}

	// Other Weight
	float getOtherWeight() {
		return this->other_weight;
	}

	void setOtherName(float weight) {
		this->other_weight = weight;
	}

	// Other Size
	float getOtherSize() {
		return this->other_size;
	}

	void setOtherSize(float size) {
		this->other_size = size;
	}

	// Credit
	float credit(float size, int weight) {
		return size*weight;
	}
	// PrintOrder
	void printOrder();
};

void Other::printOrder() {
	cout << "Mebele numur." << this->furniture_count << endl;
	cout << "Mebeles nosaukums :" << this->getFurnitureName() << endl;
	cout << "Summa: " << this->furniture_price << " EUR" << endl;
	cout << "Mebeles izmers " << this->getOtherSize() << " CM^2 " << endl;
	cout << "Mebeles svars: " << this->getOtherWeight() << " KG " << endl;
}

/*
 Autors : Mikus Leduskrasts
 String pârbaude no viòa private library
 */
string inputNonEmptyString() {
	string tempString;
	while (1) {
		try {
			getline(cin, tempString);
			if (tempString != "")
				return tempString;
			cout << "The string must not be empty";
		}
		catch (...) {
			cout << "Error in input! There is an issue with the string you provided.\n";
		}
	}
}

int main() {
	clrscr();
	int month;
	float price;
	string name, color;
	/*
	 [int] Month - Variable for funtion Credit
	 [float] Price - Variable for furniture_price
	 [string] Name - Variable for furniture_name
	 Color - Variable for furniture_color
	 */


	cout << "Ievadiet preces nosaukumu : ";
	name = inputNonEmptyString();
	cout << "Ievadiet preces krasu : ";
	color = inputNonEmptyString();
	cout << "Ievadiet preces cenu : ";

	cin >> price;
	while (price <= 0) {

		if (price <= 0) {
			cout << "Cena nevar but 0 vai mazaka" << endl;
			cout << "Ievadiet jauno preces cenu : ";
			cin >> price;
		}
	}
	cout << "Ievadiet menesu skaitu : ";
	cin >> month;
	while (month <= 0) {

		if (month <= 0) {
			cout << "month nevar but 0 vai mazaka" << endl;
			cout << "Ievadiet menesu skaits : ";

			cin >> month;
		}
	}
	clrscr();
	// Bazes metode

	// Constructor to give serial and date
	SoftFur *t2 = new SoftFur("123987", "31.12.2013", "Stool", "Yellow", 512);
	t2->printOrder();
	// Atvasinata metode
	cout << "Preces var nopirkte : " << t2->credit(price, month) << endl;

	Other *t4 = new Other(123.1, 125421.123, "StavGalds", 983);
	t4->printOrder();

	delete t2, t4;

	return 0;
}
