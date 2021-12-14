#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "boockingticket.c"


int main(){
  int login;
  printf("TRAIN SCHEDULING & TICKET BOOOKING\n\n");
  printf("#LOGIN#\n");
  printf("1. Penumpang\n");
  printf("2. Admin\n");
  printf("3. Registrasi\n\n");
  printf("Pilihan Anda = ");
  scanf("%d", &login);
   switch(login){
   	 case 1 : 
   	 	loginMahasiswa();
   	 	break;
   	case 2 :
   		loginAdmin();
   		break;
   	case 3 :
   		registrasi();
   		break;
   	default : 
   		printf("Tidak ada dalam pilihan");
   		break;
   }	
	
}
