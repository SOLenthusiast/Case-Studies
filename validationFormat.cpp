//
//  main.cpp
//

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
#include "validationFormat.h"
#include <stdio.h>
#include <string.h>

bool validerNas(const string& unNAS);
bool validerFormatFichier(std::istream& p_is);

int main() {
    
/* Prog test pour "validerNas"
    char buffer[256];
    string unNAS;
    bool reponse;
    bool vide = true;
    

    cout<<"Entrez votre NAS"<<endl;
    
    //cin.ignore(100,'\n');
    cin.getline(buffer, 255);
    unNAS = buffer;
    
    vide = !unNAS.empty();
    if (!vide){
        cout << endl << "! Le NAS est vide." << endl;
        return 2;
    }
    
    reponse=validerNas(unNAS);
    cout<<"Réponse : "<<reponse<<endl;
    cout<<"Si rep=0 alors le NAS est faux sinon il est bon"<<endl;
    return reponse;
*/
    
    
// Prog test pour "validerFormatFichier"
    bool repons=false;
    ifstream file("/Users/boubacmo/Documents/C++/tp1/tp1/donneesValides_linux.txt");
    
    if (file) {
        cout<<"Ouverture du fichier"<<endl;
        repons=validerFormatFichier(file);
        return repons;
    }
    file.close();
}


bool validerFormatFichier(istream& p_is)
{
    string contenu_ligne;
    string ligne1="Circonscription";
    string parti[6]={"BLOC_QUEBECOIS","CONSERVATEUR","INDEPENDANT","LIBERAL","NOUVEAU_PARTI_DEMOCRATIQUE"};
    int i=0;
    int nb_ligne = 0;
    bool valid=false;
    string str_jour; string str_mois; string str_annee;
    int entier;

    
    while(getline(p_is, contenu_ligne)){
        //cout<<contenu_ligne<<endl;
        //cout<<contenu_ligne.substr(0,15)<<endl;
        i++;
        
        if ((i==1) && strcmp(ligne1.c_str(), contenu_ligne.substr(0,15).c_str())!=0)
        {
            cout<<"Format incorrecte à la ligne "<<i<<endl;
            exit(ERREUR);
            //return valid;
        }

        else if (i>1)
        {
            int type_data=validerNas(contenu_ligne); cout << type_data << endl;
            
            if ((i==2) && (type_data==0) && parti[1]!=contenu_ligne)
            {
                cout<<"Format incorrecte à la ligne "<<i<<endl;
                exit(ERREUR);
            }
            
            if ((type_data==0) && (parti[1]==contenu_ligne || parti[2]==contenu_ligne ||
                                   parti[3]==contenu_ligne || parti[4]==contenu_ligne ||
                                   parti[3]==contenu_ligne))
            {nb_ligne=i+5;}
            
            else if ( (type_data==1) && (i>nb_ligne) ) {nb_ligne=i+4;}
            
            
            if (i==nb_ligne-1) {
                
                istringstream iss;
                string str_date=contenu_ligne;
                
                iss.str(str_date);
                
                for (int j=0; j<3; j++) {
                    
                    if ( (iss >> entier) && (((j==0) && (entier <= 31))
                                              || ((j==1) && (entier <= 12))
                                              || (j==2))) {
                        cout << entier << " ";
                    }
                    else {cout<<"Format incorrecte à la ligne "<<i<<endl; exit(ERREUR);}
                }
                cout<<endl;
             }
        }
    }
    cout<<"Format correct"<<endl;
    valid=true;
    return valid;
}



bool validerNas(const string& unNAS)
{
    int var=0;
    int res;
    bool valide=true;
    string unNASnew=unNAS;
    
    string s;
    istringstream str(unNASnew);
    int qc;

    if (str >> qc) {unNASnew.erase(std::remove(unNASnew.begin(), unNASnew.end(), ' '), unNASnew.end());}
    else {valide=false; return valide;}
    
    for (int i=0; i<unNASnew.length(); i++)
    {
        if ((i+unNASnew.length())%2 != 0){res=(int)unNASnew[i]-(int)48;}
        else
        {
            res=(int)unNASnew[i]-(int)48; res*=2;
            if (res>=10) {res=(res%10)+1;}
        }
        var+=res;
    }
    if (var%10==0) {return valide;}
    else {valide=false;return valide;}
}
