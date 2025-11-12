
#include <iostream>
#include <ctime>    // mesure de temps
#include <cstdlib>  // gen nbre aleatoires
#include <cctype>   // analyse des lettres
#include <string>
#include <vector>
#include <list>
#include<stack> // LIFO
#include<queue>  //FIFO
#include<thread>
#include<mutex>
#include <type_traits>  // check type


using namespace std;

void SL_heritageDuC(void);
void lambdafunctions(void);
void vectors(void);
void lists(void);
void stacks_LIFO(void); // pile
void queue_FIFO(void) ; // file

// threads -------------
mutex carMutex;
void driveCar(string driverName);
void threads_();
//-----------------------------

// check type --------------
void Check_Type_Example();
template <typename T>
void Ckeck_type_function(T);
//---------------------------

int main()
{
    //SL_heritageDuC(); // ctime, cstdlib, cctype
    //lambdafunctions();
    //vectors();
    //lists();
    //stacks_LIFO();
    //queue_FIFO();
    //threads_();
    Check_Type_Example();
    return 0;
}

void SL_heritageDuC(void)
{
    //-1) cctype : operations sur les lettres.
    
    std::string str = "raouf54";
    
    for(auto &elt : str )
    {
        if(isalpha(elt))
            std::cout << "alpha : " << elt << std::endl;
        if(isdigit(elt))
            std::cout << "digit : " << elt << std::endl;
        if(islower(elt))
            elt = toupper(elt);  // il faut une reference 
    }
    
    std::cout << str << std::endl; // affichage après modif (&)
    
    // -2) ctime 
    
    int t0 = time(0);     // ou bien std::time_t now = std::time(0);
    std::cout << "il s'est ecoulé " << t0 << "s. depuis 1970"<<std::endl;
    
    // retarder le progamme un peu
    char c = getchar(); // attendre un charactere a l'entrée
    int t1 = time(0); 
    
    std::cout <<"Temps d'attente : "<< t1-t0 <<"s."<<std::endl;
    
    // -3) cstdlib (nbre aleatoire)
    
    srand(time(0));  // initialiser la suite des nbre aleatoires
    int aleatoire =  rand() % 10;
    std::cout << "aleatroire = " << aleatoire << std::endl;
        
}


void lambdafunctions(void)

{
    int a = 5 , b = 8;

    auto myLambdaFct = [=](int  x, int &y) -> int {
        y = 5;
        return x + y;
    };
    int s = myLambdaFct(a, b);
    std::cout << "s = " << s << std::endl;
    std::cout << b ; // passage par reference
    /*
    [=] or [&] : captuer tout par val(copie) ou par ref ou les 2 [a, &b]
    ->         : return_type
    auto nomLambdafct : nom de la fonction
    */
}

void vectors(void)
{

    vector<int> tab;
    tab.push_back(0);
    
    //remplissage du vecteur 
    for(int i = 1; i<=5 ; i++)
        tab.push_back(i);

    
    //print vector elements methode1)
    cout << "print usign simple for loop : " << endl;
    for(auto elt : tab)
        cout << elt <<endl; 
        
    
    //print vector elements methode 2) itterators
    cout << "print usign iterators : " << endl;
    for(auto it = tab.begin() ; it != tab.end() ; it++)
        cout << *it << endl;
    
    //access elts using iterators
    auto it = tab.begin();
    cout << "Element de l'index 5 = " << *(it+5) <<endl;
    
    
    //operations sur les vecteurs
    cout << "Size: " << tab.size() << endl;
	cout << "Max size: " << tab.max_size() << endl;
	cout << "Capacity: " << tab.capacity() << endl;
	tab.resize(5);
	cout << "Size after resizing: " << tab.size() << endl;
	if (tab.empty())
		cout << "Vector is empty" << endl;
	else
		cout << "Vector is not empty" << endl;
	cout << "Element[0] is: " << tab[0] << endl;
	cout << "Element at(3) is: " << tab.at(3) << endl;
	tab.erase(tab.begin());
	cout << "Front: " << tab.front() << endl;
	cout << "Back: " << tab.back() << endl;

	//insert element at specific position in vector
	tab.insert(tab.begin() + 2, 88);
	//erase element from a specific position
	tab.erase(tab.begin() + 2);
	//remove last element of vector
	tab.pop_back();

	//clear all the elements of vector
	tab.clear();
	cout << "Size after clear: " << tab.size() << endl;
}

void lists()
{
    //declaratation + initialisation
    list<int> lst = { 2 , 3};
    
    //iterator for test
    list<int>::iterator it=lst.begin();  // or auto it
    
    // insert elemeents
    lst.push_back(4);
    lst.push_front(1);
    lst.push_front(0);
    lst.insert(++it , 99);
    
    advance(it, 2); // avancer de deux cases
    lst.insert(it , 2 , 88); // 2 fois 88 

    
    //remove elements
    lst.pop_back();
    lst.pop_front();
    
    // erase elts
    lst.erase(--it);
    
    //print list elements (for each)
    cout << "avec for each : " << endl;
    
    for(auto elt : lst)
        cout << elt << endl;
        
    
    //print list elements (itterator, for)
    cout << "avec itteraors : " << endl;
    
    for(list<int>::iterator it = lst.begin() ; it!=lst.end() ; it++)
        cout << *it << endl;
        
    // merge lists
    cout << "merge lists : " <<endl;
    list<int> lst2 = {9 , 9};
    lst.merge(lst2);
    
    
    // sort lists 
    lst.sort();   //par def : petit vers grand, lst.reverse()
    
    for(auto elt: lst)
        cout << elt << endl;
    
    cout << "front : " <<lst.front() << endl;
    cout << "back : " << lst.back() << endl;
    cout << "size : " << lst.size() << endl;
    
    // clear all
    lst.clear();
    
    // check if empty
    if (lst.empty())
        cout << "lst is empty." <<endl;
    
}

void stacks_LIFO(void){

    std::stack<int> maPile;

    // Ajouter des éléments à la pile
    maPile.push(10);
    maPile.push(20);
    maPile.push(30);

    // Vérifier la taille de la pile
    std::cout << "La pile contient " << maPile.size() << " éléments." << std::endl;

    // Accéder au sommet de la pile
    std::cout << "Sommet de la pile : " << maPile.top() << std::endl;

    // Retirer un élément du sommet
    maPile.pop();

    // Vérifier la taille après retrait
    std::cout << "La pile contient maintenant " << maPile.size() << " éléments." << std::endl;

    // Vérifier si la pile est vide
    if (maPile.empty()) {
        std::cout << "La pile est vide." << std::endl;
    } else {
        std::cout << "La pile n'est pas vide." << std::endl;
    }
}

void queue_FIFO(void)
{
    std::queue<int> maFile;

    // Ajouter des éléments à la file
    maFile.push(10);
    maFile.push(20);
    maFile.push(30);

    // Vérifier la taille de la file
    std::cout << "La file contient " << maFile.size() << " éléments." << std::endl;

    // Accéder à l'élément du front de la file
    std::cout << "Élément au front de la file : " << maFile.front() << std::endl;

    // Accéder à l'élément à l'arrière de la file
    std::cout << "Élément à l'arrière de la file : " << maFile.back() << std::endl;

    // Retirer un élément du front
    maFile.pop();

    // Vérifier la taille après retrait
    std::cout << "La file contient maintenant " << maFile.size() << " éléments." << std::endl;

    // Vérifier si la file est vide
    if (maFile.empty()) {
        std::cout << "La file est vide." << std::endl;
    } else {
        std::cout << "La file n'est pas vide." << std::endl;
    }

}



void driveCar(string driverName){
    
    // lock here for mutex
    unique_lock<mutex> carlock(carMutex);
    // or lock_guard<mutex> carlock(carMutex); 
    // automatique lock and unlock (when is out of scope)
    
    cout << driverName << " is driving" <<endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << driverName << " is done driving" <<endl;
    
    // unlock here
    carlock.unlock();
}

void threads_(){
        
    thread t1(driveCar, "raouf");
    thread t2(driveCar, "Abdou");
    
    // attendre que t1 soit finit
    t1.join(); 
    t2.join();
    
    // si jamais on est pas sure
    if(t1.joinable())
        t1.join();
        
    // ne pas attendre (run in the background)
    if(t1.joinable())
        t2.detach(); 
}


// check type
void Check_Type_Example()
{
    int a = 4, b = 3;
    std::string str = "raouf";

    Ckeck_type_function(str);
    Ckeck_type_function(a);
}

template <typename T>
void Ckeck_type_function(T a)
{

    if constexpr (std::is_same_v<T, std::string>)
    {
        std::cout << "c'est un string (" << a << ")" << std::endl;
    }
    else if constexpr (std::is_same_v<T, int>)
    {
        std::cout << "c'est un entier (" << a << ")" << std::endl;
    }
    else
        std::cout << "autre type" << std::endl;


}