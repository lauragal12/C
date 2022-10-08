#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char pila[7];
char elim;
int op,indi=1,i,x=0,min,tope,maxi=7,ele,eleme,to,opci;

int main(void) {
  
  do{
    printf("\n---> • P I L A • <---\n");
    printf("\n1. Agregar un elemento.");
    printf("\n2. Quitar un/todos elemento.");
    printf("\n3. Salir.");
  
    printf("\n--> ¿Que desea hacer? ");
    scanf("%d",&op);
      switch(op){
        case 1:
          if(indi==0){
            printf("\n ¡¡Subdesbordamiento!!\n Pila vacia.");
            indi=1;
          }else if(pila[indi]==0){ 
            printf("Cuantos elementos desea ingresar: ");
            scanf("%d",&ele);
            tope=ele;
            if(ele<=maxi){
              for (i=indi; i<=ele; i++){
                  printf("Ingrese la letra en %d: ",i);
                  scanf("%s",&pila[i]);
                  
                } 
              
            }else{
              printf("\n¡¡A ocurrido un desbordamiento!!\n Valor de arreglo superado. ");
            }
            for (i=maxi; i>=indi; i--){
                printf("\n %c ",pila[i]);
              }
          }else{ 
            printf("Cuantos elementos desea ingresar: ");
            scanf("%d",&eleme); 
            to=eleme+tope;
            //printf("\n El tope es %d ",tope);
            if(to<maxi){
              for (i=tope+1; i<=to; i++){
                printf("Ingrese la letra en %d: ",i);
                scanf("%s",&pila[i]);
                
              }
              tope=to;
            }else{
              printf("\n¡¡A ocurrido un desbordamiento!!\n Valor de arreglo superado. ");
            }
            for (i=maxi; i>=indi; i--){
                printf("\n %c ",pila[i]);
              }
          }
          break;
        case 2:
          printf("\n 1. Eliminar un elemento.");
          printf("\n 2. Eliminar todos los elementos");
          printf("\n 3. Eliminar tope.");
          printf("\n ¿Que desea hacer?");scanf("%d",&opci);
          switch(opci){
            case 1:
              if(pila[indi]==0){
                printf("\n Subdesbordamiento.\n La pila esta vacia ");

              }else{
              printf("Ingrese la letra a eliminar: ");
                scanf("%s",&elim); 
                
                for (i=indi; i<tope; i++){
                  if(pila[i]==elim){
                    for (int y=tope; y>=i; y--){
                      pila[y]='\0';                    
                    }
                    tope=i-1;
                  }
                }
                  
                //printf("\n El tope es %d ",tope);
                for (i=indi; i<=tope; i++){
                  if(pila[i]!=elim){
                    printf("\n Valor no enontrado. ");
                    break;
                  }
                }
                for (i=maxi; i>=indi; i--){
                  printf("\n %c ",pila[i]);
                }
                }
                break;
            case 2:
              if(pila[indi]==0){
                printf("\n Subdesbordamiento.\n La pila esta vacia ");

                }else{
              memset(pila,0,maxi);
              printf("\n Subdesbordamiento.\n La pila se vacio ");
              indi=0;
                }
              break;
            case 3:              
              if(pila[indi]==0){
                printf("\n Subdesbordamiento.\n La pila esta vacia ");

                }else{
              pila[tope]='\0';
              tope=tope-1;
              for (i=maxi; i>=indi; i--){
                printf("\n %c ",pila[i]);
              } 
                }
              break;
            default:
              printf("\n ¡¡Numero no valido!!\n Ingrese el correcto.\n");
            break;
          }
        case 3:         
          break;
        default:
          printf("\n ¡¡Numero no valido!!");
          break;
      }    
  }while(op!=3);

  return 0;
}