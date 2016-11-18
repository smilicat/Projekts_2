#include <iostream>
#include <string>
#include <conio.h>



using namespace std;
/*
2. Darbs
Autors   : Jānis Mangulis
Grupa    : P2-4
Variants : 17 "Prece"
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

class Item {
    // Bāzes klases definēšana
private:
                /*Bazes klases privatais mainigais ,kurs neattiecas uz atvasinato Food
                privato mainigo nevar mainīt arpus bāzes klases
    */
                string item_manuf;

protected:
                //Mainigie ,kurus var pieskirt tikai Item un Food
                float item_price;

public:
                // Mainigie ,kurus var brivi izmantot visâ programmâ
                /*
                [static int] Statiskais mainigais ,kuršs uzskaita visus izveidotos objektus*/
                static int item_count;
                string item_name;

                // Non-Overloaded Constructor
                Item(){
                this->item_count++;
                this->item_name = "Pildspalva";
                this->item_manuf = "China";
                this->item_price = 1.7;
    }
                // Overloaded constructor
                Item(string name,string manuf, float price) {
    this->item_count++;
                this->item_name = name;
                this->item_manuf = manuf;
                this->item_price = price;
    }
                // Deconstructor
                ~Item(){

                cout << endl << "Prece numurs :  " << item_count <<" "<< this->item_name<< " "  << " tika pardota"<< endl;
item_count--;
                getch();
    }
                // ItemName method
                string getItemName();
                void setItemName(string);
                // ItemManuf method
                string getItemManuf();
                void setItemManuf(string);
                // ItemPrice
                void setItemPrice(float);
                // printData
                void printData();
                // paymentMethode
                float payment(float, int);
};
//Static integer
int Item::item_count = 0;

// Metodes ItemName
string Item::getItemName() {
                return item_name;
}

void Item::setItemName(string name) {
                this->item_name = name;
}

// Metodes ItemManuf
string Item::getItemManuf() {
                return item_manuf;
}

void Item::setItemManuf(string manuf) {
                this->item_manuf = manuf;
}
// Metodes ItemPrice
void Item::setItemPrice(float price) {
                this->item_price = price;
}
// Kredita aprekina metode
float Item::payment(float item_price, int items) {
                return this->item_price * items;
}
// printData
void Item::printData() {
                cout << "Prece  nr." << item_count << endl <<
                                "Preces nosaukums : " << item_name << endl <<
                                "Prece izstradataj valsts : : " << item_manuf << endl <<
                                "Preces cena : " << item_price << " Euro"<<endl;
}

// Secondary Class Food
class Food : public Item {
private:
                int food_weight;
                string food_date;

public:

                // weight
                int getWeight();
                void setWeight(int weight);
                // Date
                string getDate();
    void setDate(string date);

    // Atvasinatas klases aprekinu metode
                float payment(float ,int);

                // Print Order
                void printData();

                // Atvasinatas Class Constructor
                Food(int weight, string date, string name,string manuf, float price) : Item(name,manuf, price) {

                                this->item_name = name;
                                this->item_price = price;
                                this->food_weight = weight;
                                this->food_date = date;
                }

};
// weight metodes
int Food::getWeight() {
                return this->food_weight;
}
void Food::setWeight(int weight) {
                this->food_weight = weight;
}
// Date metodes
string Food::getDate() {
                return this->food_date;
}
void Food::setDate(string date) {
                this->food_date = date;
}
// Atvasina bazes klases metodi payment()
float Food::payment(float item_price, int items) {
                return 0,21*item_price*items;
}
// Mikstas mebeles  : Print order
void Food::printData() {
cout <<"Partikas prece Nr. " << this->item_count << endl <<
                "Partikas preces nosaukums :" << this->getItemName() << endl <<
                "Partikas preces razotajvalsts : " << this->getItemManuf() << endl <<
                "Partikas preces cena : " << this->item_price << " EUR" << endl <<
                "Partikas preces svars : " << this->getWeight()<<" KG " << endl<<
                "Partikas preces razosanas datums : " << this->getDate() << endl;
}

int main() {

                int items;
                float price;
                string name,manuf;
                /*
                [int] items - Variable for function payment
                [float] Price - Variable for item_price
                [string] Name - Variable for item_name
                        manuf - Variable for item_manuf
                */
                cout << "Ievadiet preces nosaukumu: ";
                cin >> name;
                cout << "Ievadiet preces razotajvalsti : ";
                cin >> manuf;
                cout << "Ievadiet preces cenu : ";
                        cin >> price;
                while (price <= 0){
            if(price<=0){
                cout << "Kluda ievade! Ludzu atkartojiet preces cenas ievadi : ";
                    cin >> price;
                }
            }


                cout << "Ievadiet perkamo precu skaitu : ";
                cin >> items;
                    while (items <= 0){
            if(items <= 0){
                cout << "Kluda ievade! Ievadiet perkamo precu skaitu : ";
                    cin >> items;
                }
            }
    //Statisks objekta ,kurs izmanto Overloaded Constructor
                Item objekts1;
                objekts1.setItemName(name);
                objekts1.setItemManuf(manuf);
                objekts1.setItemPrice(price);
                objekts1.printData();
                // Bazes metode
                cout << "Visu precu summa bez PVN : " <<objekts1.payment(price,items) << endl;
                // Constructor to give weight and date

                Food *objekts2 = new Food(3/*weight*/, "01.12.2011" /* date*/
    ,"Krievija"/*prece nosaukum*/,
    "China"/*razotajvalsts */,918.123/* cena*/);
                objekts2->printData();
                // Atvasinata metode
                cout << "Preces cena ar PVN : " << objekts2->payment(price,items)<< endl;
                // Dinamisks objeks ,kurs izmanto Non-Overloaded Constructor.
                Item objekts3;
                objekts3.printData();
                                cout << "Ediena izmaksas : " << objekts3.payment(price,items)<< endl;
                delete objekts2;
    return 0;
}
