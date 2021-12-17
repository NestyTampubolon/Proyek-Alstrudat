#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct penumpang P;

void registrasi();
void login();
void kelolaakunbyadmin();
int kelolarute();
void kelolakota();
	char kar,again = 'y';
struct P{
	char nomorKTP[16];
	char nama[30]; 
	char nomorhandphone[12];
	char username[30]; 
	char password[20]; 
	char re_password[20]; 
	char *next;
}penumpang, cek ;

typedef struct kota {
	char kode[100];
	char namaKota[100];
} kota;

typedef struct rute {
	char keberangkatan[100];
	char tujuan[100];
	char kode[100];
	char kode1[100];
	char kode2[100];
	char kode4[100];
	int bisnis;
	int premium;
}rute;

void registrasi(){
	FILE *ptr,*ptr1;
	int count=0;
	printf("#REGISTER SISTEM#");
	ptr =fopen("penumpang.txt","a");
		system("cls");
		ptr1 =fopen("penumpang.txt","r");
		fclose(ptr1);
		printf ("Nomor KTP : ");
		fflush(stdin);
		scanf ("%s",&penumpang.nomorKTP);
		printf ("Nama Lengkap : ");
		fflush(stdin);
		scanf ("%s",&penumpang.nama);
		printf ("Nomor Handphone : ");
		fflush(stdin);
		scanf ("%s",&penumpang.nomorhandphone); 
		printf("Email : ");
		fflush(stdin);
		scanf("%s",&penumpang.username);
		printf("Password : ");
		fflush(stdin);
		scanf("%s",&penumpang.password);
		printf("Re-Password : ");
		fflush(stdin);
		scanf("%s",&penumpang.re_password);
		
		if(strcmp(penumpang.password, penumpang.re_password) == 0 ){
			fprintf(ptr,"%s|%s|%s|%s|%s\n", penumpang.nomorKTP,penumpang.nama, penumpang.nomorhandphone, penumpang.username, penumpang.password);
			fclose(ptr);
	
			printf("\n\nData Mahasiswa Sudah Disimpan !");
		}else{
			printf("Password tidak SAMA");
		}
}

void loginMahasiswa(){
	char nama[100],input[100],input2[100];
	char noktp[100];
	char nohp[100];
	char email[100];
	char password[100];
	int pilihan;
    FILE *wrote;

  wrote = fopen("penumpang.txt","a+");
  
	printf("#LOGIN SISTEM#\n\n");

   printf("Email : ");
    scanf("%s",&input);
   printf("Password : ");
   scanf("%s",&input2);

    while(!feof(wrote)){
        fscanf(wrote," %[^|]|%[^|]|%[^|]|%[^|]|%[^|]|\n",&noktp,&nama,&nohp,&email,&password);

       if(strcmp(input,noktp)==0){
        	if(strcmp(input2,password)==0){
       		printf("#MENU PENGGUNA#\n\n");
        		printf("Welcome, %s", nama);
       			printf("\n1. Booking Tiket");
       			printf("\n2. Kelola Profile");
       			printf("\n3. History Pembelian");
       			printf("\n0. Logout");
       			printf("\n\n\nPilihan : ");
       			scanf("%d",&pilihan);
       			switch(pilihan){
       				case 1:
       					kelolaakunbyadmin();
       					break;
       				case 2:
       					break;
       				case 3:
       					break;
       				case 4:
       					break;
       				case 5:
       					break;
       				case 0:
       					break;
       				default:
       					printf("Tidak ada dalam pilihan");
       					break;
				   }
        		system("PAUSE");
				break;
			}            
      }
  }
    fclose(wrote);
    
}


void loginAdmin(){
	char nama[100],input[100],input2[100];
	char noktp[100];
	char nohp[100];
	char email[100];
	char password[100];
	int pilihan;
    FILE *wrote;

  wrote = fopen("admin.txt","a+");
  
	printf("#LOGIN SISTEM#\n\n");

   printf("Email : ");
    scanf("%s",&input);
   printf("Password : ");
   scanf("%s",&input2);

    while(!feof(wrote)){
        fscanf(wrote," %[^|]|%[^|]|%[^|]|%[^|]|%[^|]|\n",&noktp,&nama,&nohp,&email,&password);

       if(strcmp(input,noktp)==0){
        	if(strcmp(input2,password)==0){
       		printf("#MENU ADMIN#\n");
        		printf("Welcome, %s", nama);
       			printf("\n1. Kelola Akun");
       			printf("\n2. Kelola Kota");
       			printf("\n3. Kelola Rute");
       			printf("\n4. Lihat Pemasukan");
       			printf("\n5. Lihat Jadwal Kereta Api");
       			printf("\n0. Logout");
       			printf("\n\n\nPilihan : ");
       			scanf("%d",&pilihan);
       			switch(pilihan){
       				case 1:
       					kelolaakunbyadmin();
       					break;
       				case 2:
       					kelolakota();
       					break;
       				case 3:
       					kelolarute();
       					break;
       				case 4:
       					break;
       				case 5:
       			
       					break;
       				case 0:
       					break;
       				default:
       					printf("Tidak ada dalam pilihan");
       					break;
				   }
       	
        		system("PAUSE");
				break;
			}
                
      }
  }
    fclose(wrote);
    
}

void kelolaakunbyadmin()
{
	
	char cekktp[100];
	int pilih,test=0;
	FILE *lama,*baru;
	lama = fopen("penumpang.txt","r");
	baru = fopen ("baru.txt","w");
	system("cls");
	
	
	printf ("Masukan No KTP : ");
	scanf ("%s",&cekktp);
	while(!feof(lama))
	{
		fscanf(lama," %[^|]|%[^|]|%[^|]|%[^|]|%[^|]\n",&cek.nomorKTP,&cek.nama,&cek.nomorhandphone,&cek.username,&cek.password);

		if(strcmp(cekktp,cek.nomorKTP)==0)
		{
			test=1;
			printf("-- Data Pengguna --\n");
			printf("Nama Lengkap : %s\n", cek.nama);
        	printf("Nomor Handphone : %s\n",cek.nomorhandphone);
        	printf("Email : %s\n",cek.username);
       		printf("Password : %s\n",cek.password);     		

			printf("\n");
			printf("-- Ubah Data Pengguna --");
			printf ("\nNama Lengkap : ");
			fflush(stdin);
			scanf ("%[^\n]",&penumpang.nama);
			strcpy(cek.nama,penumpang.nama);
			printf ("Nomor Handphone : ");
			fflush(stdin);
			scanf ("%[^\n]",&penumpang.nomorhandphone); 
			strcpy(cek.nomorhandphone,penumpang.nomorhandphone);
			printf("Email : ");
			fflush(stdin);
			scanf("%[^\n]",&penumpang.username);
			strcpy(cek.username,penumpang.username);
			printf("Password : ");
			fflush(stdin);
			scanf("%[^\n]",&penumpang.password);
			strcpy(cek.password,penumpang.password);
			fprintf(baru,"%s|%s|%s|%s|%s|\n", cek.nomorKTP,cek.nama,cek.nomorhandphone,cek.username,cek.password);
			
			system("PAUSE");
		break;
		}else if (strcmp(cekktp,cek.nomorKTP)== 1){
		
		fprintf(baru,"%s|%s|%s|%s|%s|\n", cek.nomorKTP,cek.nama,cek.nomorhandphone,cek.username,cek.password);
	
		}
		fprintf(baru,"%s|%s|%s|%s|%s|\n", cek.nomorKTP,cek.nama,cek.nomorhandphone,cek.username,cek.password);

	}

	fclose(lama);
	fclose(baru);
	remove("penumpang.txt");
	rename("baru.txt","penumpang.txt");
	if(test!=1){   
		system("cls");
        printf("\nData tidak ditemukan !\a\a\a");
        }
        
        
    	while(!feof(baru)){
    		fscanf(baru," %[^|]|%[^|]|%[^|]|%[^|]|%[^|]\n",&cek.nomorKTP,&cek.nama,&cek.nomorhandphone,&cek.username,&cek.password);
    		printf("Data Berhasil Diupdate, Berikut Data Terbaru : \n");
    		printf("Nomor KTP : %s\n", cek.nomorKTP);
    		printf("Nama Lengkap : %s\n", cek.nama);
    		printf("Nomor Handphone : %s\n", cek.nomorhandphone);
    		printf("Email : %s",cek.username);
    		printf("Password :  %s", cek.password);
    			
        		system("PAUSE");
				break;
		}
	    
    }
    

void kelolakota(){
	int pilihan;
	do{
	system("cls");
	printf("#KELOLA KOTA#\n");
	printf("1. Tambah Data Kota\n");
	printf("2. Lihat Data Kota\n");
	printf("3. Edit Data Kota\n");
	printf("4. Delete Data Kota\n");
	printf("5. Menu Utama\n");
	printf("\nPilihan : ");
	scanf("%d",&pilihan);
	if(pilihan>5){
		system("cls");
            printf("INPUT SALAH, COBA LAGI!!\n");
	}switch(pilihan){
		case 1:
			
			system("cls");
			printf("#TAMBAH DATA KOTA#\n");
			kota *k;
			FILE *city, *city1;
			int n,i,j;
			
			k = (kota*)malloc(100*sizeof(kota));
			city = fopen("kota.txt","a+");
			
			printf("#TAMBAH DATA KOTA#\n\n");
			for(i=0;i<1;i++){
				printf("Tambah Kota : ");
				fflush(stdin);
			    scanf("%s %s",k[i].kode,k[i].namaKota);
			    fwrite(k+i,sizeof(kota),1,city);
			}
	    
	    fclose(city);	
		printf("Menu Utama [y/t] ? ");
        again=getch();		
			break;
			
		case 2:
			system("cls");
			kota k1;
			int counter = 1;
		    city = fopen("kota.txt","r");
			printf("#LIHAT DATA KOTA#");
			printf("\nData Lengkap Kota");
			printf("\n-------------------------------------------------------------------\n");
			printf("No\t\tKode Kota\t\tNama Kota\n");
			while(fread(&k1,sizeof(kota),1,city)) { 
				printf("%d\t\t%s\t\t\t%s\n",counter,k1.kode,k1.namaKota);
				counter++;
		    }
			printf("\n\n-------------------------------------------------------------------");
    		fclose(city);
            printf("\nMenu Utama [y/t] ? ");
			again=getch();
			break;
			
		case 3:
			system("cls");
			char id_kota[5];
			int found = 0;
			int counter2 = 1;
			city = fopen("kota.txt","r");
			printf("#LIHAT DATA KOTA#");
			printf("\nData Lengkap Kota");
			printf("\n-------------------------------------------------------------------\n");
			printf("No\t\tKode Kota\t\tNama Kota\n");
			while(fread(&k1,sizeof(kota),1,city)) { 
				printf("%d\t\t%s\t\t\t%s\n",counter2,k1.kode,k1.namaKota);
				counter2++;
		    }
			printf("\n\n-------------------------------------------------------------------");
    		fclose(city);
    		
		    char kodeKota[10];
		    fflush(stdin);
		    printf("\nEdit Kota : EDIT_");
		    scanf("%[^\n]s",kodeKota);
		    
		    city = fopen("kota.txt","r");
		    city1= fopen("temp2.txt","w");
		    while(fread(&k1,sizeof(kota),1,city)){
		        if(strcmp(k1.kode,kodeKota)==0){
		        	found ==1;
		        	fflush(stdin);
		            printf("\nKode Kota : ");
		            fflush(stdin);
				    scanf("%[^\n]s",k1.kode);
				    fflush(stdin);
				    printf("Nama Kota : ");
				    scanf("%[^\n]s",k1.namaKota); 	
		        } 
		        fwrite(&k1,sizeof(kota),1,city1);
		    }
		    fclose(city);
		    fclose(city1);
		    
			if(found==0){
            	city = fopen("kota.txt","w");
	            city1 = fopen("temp2.txt","r");
	
	        while(fread(&k1,sizeof(kota),1,city1)){
	           fwrite(&k1,sizeof(kota),1,city);	
            }
            fclose(city);
            fclose(city1);
    }

			break;
		
		case 4:	
			system("cls");
			int counter3 = 1;
		    city = fopen("kota.txt","r");
			printf("#LIHAT DATA KOTA#");
			printf("\nData Lengkap Kota");
			printf("\n-------------------------------------------------------------------\n");
			printf("No\t\tKode Kota\t\tNama Kota\n");
			while(fread(&k1,sizeof(kota),1,city)) { 
				printf("%d\t\t%s\t\t\t%s\n",counter3,k1.kode,k1.namaKota);
				counter3++;
		    }
			printf("\n\n-------------------------------------------------------------------");
    		fclose(city);

    		char kode[10];
		    printf("\nDelete Kota : DELETE_");
		    fflush(stdin);
		    scanf("%[^\n]s",kode);
			
			city = fopen("kota.txt","r");
		    city1 = fopen("temp2.txt","w");
		    
		    while(fread(&k1,sizeof(kota),1,city)){
		        if(strcmp(k1.kode,kode)==0){
		        	found = 1;			
		        }
		        else
		        
		        fwrite(&k1,sizeof(kota),1,city1);   
		    }
		    fclose(city);
		    fclose(city1);
		     if(found){
		        city = fopen("kota.txt","w");
		        city1 = fopen("temp2.txt","r");
		
		        while(fread(&k1,sizeof(kota),1,city1)){
		            fwrite(&k1,sizeof(kota),1,city);
		        }
		        fclose(city);
		        fclose(city1);
		        printf("\nData telah berhasil dihapus\n");
    		}
    		
            printf("Menu Utama [y/t] ? ");
			again=getch();
			break;
		
		case 5:
			system("cls");
		
			system("cls");
			break;
	}
	}while(again == 'y');	
}

int lihat_rute(){
	rute *r;
	rute r1;
	kota k1;
    FILE *prute,*prute1;
    int n,i,j, found =0;
	int counter4=1;
    prute = fopen("rute.txt","r");
	system("cls");
	printf("\n\n#LIHAT DATA RUTE#");
	printf("\nData Lengkap Rute Kereta Api");
	printf("\n-------------------------------------------------------------------\n");
	printf("No\t\tKeberangkatan\t\tTujuan\t\tKode_Rute\t\tBisnis\t\tPremium\n");
	while(fread(&r1,sizeof(rute),1,prute)) {
		printf("%d\t\t%s\t\t%s\t\t%s - %s\t\t%d\t\t\%d\n",counter4,r1.keberangkatan,r1.tujuan,r1.kode1,r1.kode2,r1.bisnis,r1.premium);
		counter4++;
    }
	printf("\n\n-------------------------------------------------------------------");
    fclose(prute);
}

int kelolarute(){
	int pilihan;
	do{
	system("cls");
	printf("#KELOLA DATA RUTE#\n");
	printf("1. Tambah Data Rute\n");
	printf("2. Lihat Data Rute\n");
	printf("3. Edit Data Kota\n");
	printf("4. Delete Data Rute\n");
	printf("5. Menu Utama\n");
	printf("\nPilihan : ");
	scanf("%d",&pilihan);
	switch(pilihan){
		case 1:
		system("cls");
		rute *r;
		rute r1;
		kota k1;
	    FILE *prute,*prute1,*pf;
	    int n,i,j, found =0;
	
	    r = (rute*)malloc(100*sizeof(rute));
	    prute = fopen("rute.txt","a+");
	    prute1 = fopen("kota.txt","r");
	    
		printf("#TAMBAH DATA RUTE#\n\n");
		char kode1[100], kode2[100], kode3[100],kode4[2];
		
	    	printf("Tambah Data Rute : ");
	    	fflush(stdin);
	        scanf("%s %s %d %d",r1.keberangkatan,r1.tujuan,&r1.bisnis,&r1.premium);
	        while(fread(&k1,sizeof(kota),1,prute1)) {
	            if(strcmp(r1.keberangkatan,k1.namaKota)==0) {
	            	strcpy(r1.kode1,k1.kode);
				} 
				if (strcmp(r1.tujuan,k1.namaKota)==0) {
					strcpy(r1.kode2,k1.kode);
				}
				strcpy(kode3,strcat(r1.kode1,""));
				strcpy(r1.kode,(strcat(kode3,r1.kode2)));
	        }
	        fwrite(&r1,sizeof(rute),1,prute);
	    
	    
	    printf("\n-----------------------------------------");
	    printf("\nData Berhasil Ditambahkan\n");
	    printf("------------------------------------------");
	    
	    fclose(prute);
	    fclose(prute1);
	    printf("\nMenu Utama [y/t] ? ");
		again=getch();
		break;
		
		case 2:
			system("cls");
		    lihat_rute();
		    printf("\nMenu Utama [y/t] ? ");
			again=getch();
		break;
		
		case 3:
		system("cls");
		int counter5 =1;
			prute = fopen("rute.txt","r");
			system("cls");
			lihat_rute();
			char kodeKota[100];
			printf("\n\n#EDIT DATA RUTE#");
			fflush(stdin);
		    printf("\n\nEdit Rute : EDIT_");
		    scanf("%[^\n]s",kodeKota);
		    
		    pf= fopen("kota.txt","r");
		    prute = fopen("rute.txt","r");
		    prute1 = fopen("temp3.txt","w");
		    	while(fread(&r1,sizeof(rute),1,prute)){
		        	if(strcmp(r1.kode,kodeKota)==0){
		       			found = 1;
				    	fflush(stdin);
			            printf("\nKeberangkatan : ");
					    scanf("%[^\n]s",r1.keberangkatan);
					    fflush(stdin);
					    printf("Tujuan : ");
					    scanf("%[^\n]s",r1.tujuan);
					    fflush(stdin);
					    printf("Bisnis : ");
					    scanf("%d",&r1.bisnis);
					    fflush(stdin);
					    printf("Premium : ");
					    scanf("%d",&r1.premium);
						    
						while(fread(&k1,sizeof(kota),1,pf)) {
						if(strcmp(r1.keberangkatan,k1.namaKota)==0) {
	            			strcpy(r1.kode1,k1.kode);
						} 
						if (strcmp(r1.tujuan,k1.namaKota)==0) {
							strcpy(r1.kode2,k1.kode);
						}
				        }
					}
					fwrite(&r1,sizeof(rute),1,prute1); 
		    }
		    fclose(pf);
		    fclose(prute);
		    fclose(prute1);
		    
		    if (found==1) {
		    	prute = fopen("rute.txt","w");
		    	prute1 = fopen("temp3.txt","r");
		    	
				while(fread(&r1,sizeof(rute),1,prute1)) {
		            fwrite(&r1,sizeof(rute),1,prute);
		            
		        }
		        fclose(prute);
			    fclose(prute1);
				printf("Data berhasil diubah");
			}	
			printf("\nMenu Utama [y/t] ? ");
			again=getch();
		break;
		
		case 4:
			system("cls");
			FILE *drute,*drute1;
			prute = fopen("rute.txt","r");
			system("cls");
			lihat_rute();
			printf("\n\n#EDIT DATA RUTE#");
			fflush(stdin);
		    printf("\n\nDelete Rute : DELETE_");
		    scanf("%[^\n]s",kodeKota);
		    
		    drute = fopen("rute.txt","r");
		    drute1 = fopen("temp3.txt","w");
		    	while(fread(&r1,sizeof(rute),1,drute)){
		    		if(strcmp(r1.kode,kodeKota)){
		        		found = 1;
		        	}
				}
					fwrite(&r1,sizeof(rute),1,drute1); 
		    
			fclose(drute);
			fclose(drute1);
		    
		     if(found){
		        drute = fopen("rute.txt","w");
		        drute1 = fopen("temp3.txt","r");
		
		        while(fread(&r1,sizeof(rute),1,drute1)){
		            fwrite(&r1,sizeof(rute),1,drute);
		        }
		        fclose(drute);
		        fclose(drute1);
		        printf("\nData telah berhasil dihapus\n");
    		}
			
			printf("\nMenu Utama [y/t] ? ");
			again=getch();
		break;
		
		case 5:
		system("cls");		
		default:
			printf("Tidak ada dalam pilihan\n");
	}
}while(again == 'y');
}

