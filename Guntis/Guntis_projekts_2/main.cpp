#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <typeinfo>

using namespace std;
/*
2. praktiskais darbs "Mantosana"
Autors   : Guntis Bertins
Grupa    : P2-4
Variants : 16 "Celosana"
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

class Travel {
    // Bāzes klases definēšana
private:
                /*Bazes klases privatais mainigais ,kurs neattiecas uz atvasinato BussTravel
                privato mainigo nevar mainīt arpus bāzes klases
    */
                int travel_dur;

protected:
                //Mainigie ,kurus var pieskirt tikai Travel un BussTravel
                float travel_price;

public:
                // Mainigie ,kurus var brivi izmantot visâ programmâ
                /*
                [static int] Statiskais mainigais ,kuršs uzskaita visus izveidotos objektus*/
                static int travel_count;
                string travel_name;

                // Non-Overloaded Constructor
                Travel(){
                this->travel_count++;
                this->travel_name = "Tenerife";
                this->travel_dur = 24;
                this->travel_price = 1780.000;
    }
                // Overloaded constructor
                Travel(string name,int dur, float price) {
    this->travel_count++;
                this->travel_name = name;
                this->travel_dur = dur;
                this->travel_price = price;
    }
                // Deconstructor
                ~Travel(){

                cout << endl << "Celojums numurs :  " << travel_count <<" "<< this->travel_name<< " "  << " tika izpardots"<< endl;
travel_count--;
                getch();
    }
                // TravelName method
                string getTravelName();
                void setTravelName(string);
                // Traveldur method
                int getTravelDur();
                void setTravelDur(int);
                // TravelPrice
                void setTravelPrice(float);
                // printData
                void printData();
                // paymentMethode
                float payment(float, int);
};
//Static integer
int Travel::travel_count = 0;

// Metodes TravelName
string Travel::getTravelName() {
                return travel_name;
}

void Travel::setTravelName(string name) {
                this->travel_name = name;
}

// Metodes Traveldur
int Travel::getTravelDur() {
                return travel_dur;
}

void Travel::setTravelDur(int dur) {
                this->travel_dur = dur;
}
// Metodes TravelPrice
void Travel::setTravelPrice(float price) {
                this->travel_price = price;
}
// Kredita aprekina metode
float Travel::payment(float travel_price, int first_payment) {
                return this->travel_price - first_payment;
}
// printData
void Travel::printData() {
                cout << "Celojums  nr." << travel_count << endl <<
                                "Celojuma nosaukums : " << travel_name << endl <<
                                "Celojuma ilgums : " << travel_dur << endl <<
                                "Celojuma izmaksas : " << travel_price << endl;
}

// Secondary Class BussTravel
class BussTravel : public Travel {
private:
                int bussTravel_person;
                string BussTravel_date;

public:

                // person
                int getPerson();
                void setPerson(int person);
                // Date
                string getDate();
    void setDate(string date);

    // Atvasinatas klases aprekinu metode
                float payment(float ,int);

                // Print Order
                void printData();

                // Atvasinatas Class Constructor
                BussTravel(int person, string date, string name,int dur, float price) : Travel(name,dur, price) {

                                this->travel_name = name;
                                this->travel_price = price;
                                this->bussTravel_person = person;
                                this->BussTravel_date = date;
                }

};
// person metodes
int BussTravel::getPerson() {
                return this->bussTravel_person;
}
void BussTravel::setPerson(int person) {
                this->bussTravel_person = person;
}
// Date metodes
string BussTravel::getDate() {
                return this->BussTravel_date;
}
void BussTravel::setDate(string date) {
                this->BussTravel_date = date;
}
// Atvasina bazes klases metodi payment()
float BussTravel::payment(float travel_price, int first_payment) {
                return this->travel_price * bussTravel_person - bussTravel_person*first_payment;
}
// Mikstas mebeles  : Print order
void BussTravel::printData() {
cout <<"Celojums Nr. " << this->travel_count << endl <<
                "Celojuna nosaukums :" << this->getTravelName() << endl <<
                "Celojuma ilgums : " << this->getTravelDur() << endl <<
                "Celojuma izmaksas : " << this->travel_price << " EUR" << endl <<
                "Celojuma personu skaits : " << this->getPerson() << endl<<
                "Datums ,kad izlido : " << this->getDate() << endl;
}

int main() {

                int first_payment;
                float price,dur;
                string name;
                /*
                [int] first_payment - Variable for function payment
                [float] Price - Variable for travel_price
                [string] Name - Variable for travel_name
              dur - Variable for travel_dur
                */
                cout << "Ievadiet celojuma nosaukumu : ";
                cin >> name;
                cout << "Ievadiet celojuma ilgumu : ";
                cin >> dur;
                while (dur <= 0){
            if(dur<=0){
                cout << "Ievadiet celojuma ilgumu : ";
                    cin >> dur;
                }
            }

                cout << "Ievadiet celojuma cenu : ";
                cin >> price;
                while (price <= 0){
            if(price<=0){
                cout << "Ievadiet celojuma cenu : ";
                    cin >> price;
                }
            }


                cout << "Ievadiet primo maksajumu summu (vismaz 100 eiro) : ";
                cin >> first_payment;
                                while (first_payment < 100){
            if(first_payment < 100){
                cout << "Ievadiet pirmas iekasas summu (vismaz 100 eiro) : ";
                    cin >> first_payment;
                }
            }
    //Statisks objekta ,kurs izmanto Overloaded Constructor
                Travel travelObjekts;
                travelObjekts.setTravelName(name);
                travelObjekts.setTravelDur(dur);
                travelObjekts.setTravelPrice(price);
                travelObjekts.printData();
                // Bazes metode
                cout << "Atlikusi summa ,ko jamaksa par celojumu : " <<travelObjekts.payment(price,first_payment) << endl;
                // Constructor to give person and date

                BussTravel *bussObjekts = new BussTravel(3/*dienu skaits*/, "01.12.2011" /*Izlidosanas datums*/
    ,"Krievija"/*Celojuma nosaukum*/,
    5/*Personu skaits*/,918.123/*Celojuma izmaksas*/);
                bussObjekts->printData();
                // Atvasinata metode
                cout << "Celojums izmaksas : " << bussObjekts->payment(price,first_payment)<< endl;
                // Dinamisks objeks ,kurs izmanto Non-Overloaded Constructor.
                Travel staicObjekts;
                staicObjekts.printData();
                                cout << "Celojums izmaksas : " << staicObjekts.payment(price,first_payment)<< endl;
                delete bussObjekts;
    return 0;
}
