#include <iostream>
using namespace std;

struct Nodo{
  int dato;
  Nodo *sig; 
  
};

//******Cola******

class Cola{
  
  private:
  Nodo *inicio;
  Nodo *fin;

  public:

  Nodo* crearNodo(int valor){
    Nodo *n = new Nodo;
    n->dato =valor;
    n->sig = nullptr;
    return n;
  }

  void push(int valor){
    Nodo *n = crearNodo(valor);
    if(!inicio){
      inicio=n;
      fin=n;
    }else{
      fin->sig=n;
      fin=n;
    }

  }

  void pop(){
    Nodo *temp= inicio;
    inicio = inicio->sig;
    free(temp);
  }

  int cantCola(){    
    int  cant;    
    Nodo *temp = inicio;
    if(!inicio)
    cout<<"Cola Vacia"<<endl;
 
    else 
    while (temp){
      cant+=1;         
      temp= temp->sig;
      
    }   
    
    return cant;
  }


  int PromedioCola(){
    
    int acum, cant,prom;
    acum=0;
    Nodo *temp = inicio;
    if(!inicio)
    cout<<"Cola Vacia"<<endl;
 
    else 
    while (temp){
      
      acum +=temp->dato;
      cant+=1;         
      temp= temp->sig;
      
    }    
    prom= acum/cant;
    
    cout <<"El promedio es: "<<prom<<endl;
    return prom;
  }

  

   int dato(int value){
      Nodo *temp= inicio;
      int aux=0;
      while(temp){
        if(aux ==value){
          return temp->dato;
        }
        temp = temp->sig;
        aux++;
      }
      return 0;
    }

 

  void mostrarCola(){
    Nodo *temp = inicio;
    if(!inicio)
    cout<<"Cola Vacia"<<endl;

    else
    while (temp){
      cout<<temp->dato<<", ";
      temp= temp->sig;
    }
    cout<<endl;
  }

   Cola(){
    inicio=nullptr;
  } 

};

 Cola pushColaPromedio(Cola cola1, int prom,int cant){    
  Cola ColaMultiplo;  
  int valor;
  
  for(int i=0; i<cant; i++){
      valor= cola1.dato(i);
      if(valor % prom == 0){
          ColaMultiplo.push(valor);
      }
      
  }
  cout<<"Cola con los multiplos del promedio: ";
  ColaMultiplo.mostrarCola();
  return ColaMultiplo; 


};

//*********Pila*********
class Pila{
  private:
  Nodo *inicio;
  Nodo *fin;  

  public:
  Nodo* crearNodo(int valor){
    Nodo *n = new Nodo;
    n->dato = valor;
    n->sig = nullptr;
    return n;
  }

  void push(int valor){
    Nodo *n = crearNodo(valor);
    n->sig = inicio;
    inicio=n;
  }
  void pop(){
    Nodo *temp = inicio;
    inicio = inicio->sig;
    free(temp);
  }

  int dato(int value){
      Nodo *temp= inicio;
      int aux=0;
      while(temp){
        if(aux ==value){
          return temp->dato;
        }
        temp = temp->sig;
        aux++;
      }
      return 0;
    }
  
  void mostrarPila(){
    Nodo *temp = inicio;
    if (!inicio)
      cout<<"Pila vacia"<<endl;
    else
      while(temp){
        cout<<temp->dato<<", ";
        temp = temp ->sig;
      }
      cout<<endl;
  }
  Pila(){
    inicio=nullptr;
  }
};
////****Borrar Cola****

Cola DeleteCola(Cola cola1, int cant){
  for(int i=0; i<cant; i++){         
      cola1.pop();   
                        
  }
  return cola1;

};


////*****LLenar Pila*********

 Pila LLenarPila(Cola cola1,int cant){    
  Pila pila; 
  int valor;
  
  for(int i=0; i<cant; i++){
    
      valor= cola1.dato(i);
      
      pila.push(valor);       
            
  }  
  
  return pila;
};

///***Invertir Cola****
void invertirCola(Cola cola1,int cant){  
   
  Cola cola;
  cola=cola1;
  Pila pila;
  pila=LLenarPila(cola1,  cant) ;  
  int valor;
  cola1=DeleteCola( cola1,  cant)  ; 
  
  for(int i=0; i<cant; i++){    
      valor= pila.dato(i);      
      cola1.push(valor);   
  }  
  cout<<"Cola Invertida: ";
  cola1.mostrarCola();
};




 

int main() {
  Cola cola1;
  Cola cola2;
  Cola colaProm;
  cola1.push(1); 
  cola1.push(2); 
  cola1.push(3); 
  cola1.push(4); 
  cola1.push(5);
  cola1.push(6); 
  cola1.push(7); 
  cola1.push(8); 
   
  
  cout<<"Cola: ";
  cola1.mostrarCola();
  int cant=cola1.cantCola();
  int prome=cola1.PromedioCola();
  colaProm=pushColaPromedio(cola1,prome,cant);
  invertirCola(cola1, cant);
  

  
  
  
}