#include <iostream>
#include <math.h>

using namespace std;

double Module(double r, double i);
double Arg(double r,double i);

void Frequence(double *f, int *n);
void SaisirValeur(double *valeur);
void Affichage(double x);

void RCserie();

int main() {
    cout << "Choisir le circuit que vous voulez travailler" << endl;
    cout << "1. RL serie" << endl;
    cout << "2. RL parallele" << endl;
    cout << "3. RC serie" << endl;
    cout << "4. RL parallele" << endl;
    cout << "5. LC serie" << endl;
    cout << "6. LC parallele" << endl;
    cout << "Saisir ici: " << endl;
    int circuit;
    cin >> circuit;
    if (circuit == 3) RCserie();

}

double Module(double r, double i)
{
    double module=sqrt(r*r+i*i);
    return module;
}

double Arg(double r, double i)
{
    double arg;
    if (r==0) arg = 90;
    else arg= atan(i/r)*180/M_PI;
    return arg;
}
   
void Frequence(double *f, int *n)
{
    cout << "Saisir la frequence max: " ;
    cin >> *f;
    cout << endl;
    cout << "Saisir le nombre de frequence: ";
    cin >> *n;
    cout << endl;
    
        
}

void SaisirValeur(double *valeur)
{
    cin >> *valeur;
    cout << endl;
}
void Affichage (double x)
{
    cout << x << endl;
}
void RCserie()
{
    cout << "RC en serie" << endl;
    // Initialisation de R et C
    double R;
    double C;
    double f;
    double fmin=1;
    int n;
    cout << "Saisir valeur de R: ";
    SaisirValeur(&R);
    cout << endl;
    cout << "Saisir valeur de C: ";
    SaisirValeur(&C);
    cout << endl;
    //Frequence
    double a[100];
    double module[100];
    double arg[100];
    Frequence(&f,&n);
    if (n==1)
        a[0]=f;
    else
    {
        for (int i=0; i<n;i++){
            a[i]=(int)(fmin+i*(f-fmin)/n);
            cout << "Frequence " << i+1 << " : " << a[i] <<endl ;
            // Calcul du module et d'arg
            module[i]=Module(R,1/(2*M_PI*a[i]*C));
            arg[i]=Arg(R,1/(2*M_PI*a[i]*C));
            cout << "Module ";
            Affichage(module[i]);
            cout << "Argument ";
            Affichage(arg[i]);
        }
    }
    
    
}
