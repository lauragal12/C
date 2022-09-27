#include <stdio.h>
int arre[6];//{2,8,9,10,3};
int cant=6;
int i,x,m,modi,modif,va,op,opc,opci,max;

//-------------------AGREGAR UN ELEMENTO------------------------------
void insertar(const int arre[],va,max){
  if(arre[0]==0){ //si el arreglo esta vacio i=0 agregar elementos i++
    for (i=0; i<6; i++){
      printf("Ingrese el valor entero en %d: ",i);
      scanf("%d",&arre[i]);
    }
  }else if(arre[0]!=0){//si el arreglo tiene elemntos -- verificar si hay espacio--agregar elementos
    for (i=0; i<6; i++){
      if(arre[i]==0){
        va=va+0;
      }else{
        va=va+1;
      }
    }
    printf("\nva %d: ",i);
    if(va==6){
      printf("\n ¡¡Arreglo lleno!! \nNo podemos insertar nuevos elementos.\n"); 
    }else{
      for (i=0; i<6; i++){
        if(arre[i]==0){
          printf("\n Hay espacio en %d ",i);
          printf("\n Ingrese el valor entero en %d: ",i);
          scanf("%d",&arre[i]);
        }
      } 
      printf("\nAhora el arreglo tiene los valores: ");

      for (i=0; i<6; i++){
        printf("\n %d ",arre[i]);
      }
    }
    }
}

//---------------BUSQUEDA DE UN ELEMENTO-------------------------------
int buscarEnArreglo(const int arre[], int busq, int longi) {
    for (int x = 0; x < longi; x++) {
        if (arre[x] == busq) return x;
    }
    return -1;
}
//------------------------------ORDENAR--------------------------------
void ordenar(opc){
  printf("\n1. Ascendente.");
  printf("\n2. Descendente.");
  printf("\n¿De que manera desea ordenar?");scanf("%d",&opc);
  switch(opc){
    case 1:
      for (i=0; i<6-1; i++){
        for (m=0; m<6-1; m++){
          if(arre[m]>arre[m+1]){
            max=arre[m];
            arre[m]=arre[m+1];
            arre[m+1]=max;
          }
        }
      }
      for (i=0; i<6; i++){
        printf("\n %d ",arre[i]);
        }
    break;
    case 2:
      for (i=0; i<6-1; i++){
        for (m=0; m<6-1; m++){
          if(arre[m]<arre[m+1]){
            max=arre[m];
            arre[m]=arre[m+1];
            arre[m+1]=max;
          }
        }
      }
      for (i=0; i<6; i++){
        printf("\n %d ",arre[i]);
        }
    break;
    defalul:
      printf("\n Valor no valido.\n");
    }
}
//--------------------------------------------------------------------
  
int main(void) {
  int busq;int existe;
  int longi= sizeof arre;
  max=0;
  do{
    printf("\n---> • M E N U • <---\n");
  printf("\n1. Agregar un elemento.");
  printf("\n2. Quitar un/todos elemento.");
  printf("\n3. Modificar por elemento nuevo.");
  printf("\n4. Buscar un elemento.");
  printf("\n5. Ordenar de forma ascendente/descendente.");
  printf("\n6. Salir.");
  printf("\n--> ¿Que desea hacer? ");
  scanf("%d",&op);
    switch(op){
      case 1: //AGREGAR ELEMENTO
        insertar(arre,va,max);break;
  
      
      case 2: //QUITAR UNO/TODOS ELEMENTO
        printf("\n 1. Eliminar un elemento.");
        printf("\n 2. Eliminar todos los elementos");
      printf("\n ¿Que desea hacer?");scanf("%d",&opci);
      switch(opci){
        case 1:
          printf(" ¿Cual es la posición del elemento a eliminar?");scanf("%d",&opc);
          for(m=0;m<6;m++){
            if(m==opc){
              while(m<cant-1){
                arre[m]=arre[m+1];
                m++;
              }
              
              break;
            }  
          }
          arre[5]=0;
          printf("\n Los elementos del arreglo son:");
          for (i=0; i<6; i++){
            printf("\n %d ",arre[i]);
          }
          break;
        case 2:
          for (i=0; i<6; i++){
            if(arre[i]!=0){
              arre[i]=0;
            }
          }
          printf("\n Los elementos se eliminaron.\n Arreglo vacio.\n");
          for (i=0; i<6; i++){
            printf("\n %d ",arre[i]);
          }        
          break;       
      }
        break;     
      case 3: //MODIFICAR POR ELEMENTO NUEVO
        if(arre[0]==0){
          printf("\n ¡¡No se puede modificar arreglo porque esta vacio!!\n");
        }else{
          printf("¿Cual es la posición del elemento que desea modificar?");
          scanf("%d",&modi);
          for (i=0; i<6; i++){
            if(i == modi){
              printf("\n ¿Cual es el valor nuevo?");
              scanf("%d",&modif);
              arre[i]=modif;
            }
          } 
          printf("\n Los valores son:");
          for (i=0; i<6; i++){
            printf("\n %d ",arre[i]);
          }
          
        }
        break;
      
      case 4: //BUSCAR VALOR
        if(arre[0]==0){
          printf("\n ¡¡No se puede buscar valor porque esta vacio!!\n");
        }else{     
          printf("\n ¿Cual es el valor que desea buscar?");scanf("%d",&busq);
          existe = buscarEnArreglo(arre, busq, longi);
          if(existe==-1){
            printf("\n El valor no se encuentra en el arreglo.\n");
          }else{
            printf("\n La posición de %d en el arreglo es: %d \n", busq, existe);
            }
        }
          break;
        case 5: //ORDENAR DE FORMA ASCENDENTE/DESCENDENTE

          if(arre[0]==0){
            printf("\n ¡¡No se puede ordenar valores porque esta vacio!!\n");
          }else{  
          ordenar(opc);
          }
          break;
        case 6: 
          break;
        default:
          printf("\n ¡¡Numero no valido!!\n Ingrese el correcto.\n");
        break;
      }

    }while(op!=6);
    
  
}