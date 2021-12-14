#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct penumpang P;

void registrasi();
void login();
void kelolaakunbyadmin();
void kelolarute();
void kelolakota();
struct P{
	char nomorKTP[16];
	char nama[30]; 
	char nomorhandphone[12];
	char username[30]; 
	char password[20]; 
	char re_password[20]; 
	char *next;
}penumpang, cek ;

typedef struct kota{
	char kode_kota[10];
	char nama_kota[50];
}kota;


typedef struct SKA KA;

struct SKA {
  int kode_kereta;
  char namaKeretaApi[255];
  char destinasi[255];
  char jam_keberangkatan[50];
  char jenis_kelas[100];
  int daya_tampung;
  int sisa_tiket;
  int kelas_eksekutif;
  int kelas_bisnis;
  int kelas_biasa;
  int harga_eksekutif;
  int harga_bisnis;
  int harga_biasa;
  int id_eksekutif;
  int id_bisnis;
  int id_biasa;
  int keuntungan_kereta;
  char kode_jadwal[200];
  char keberangkatan[50];
  char tujuan[100];
  char tanggal[20];
  char waktu_keberangkatan[20];
  char KAI[20];
  int status;

  KA *nextNode;
};

void daftarKa(KA *data);

void pilihanKa(KA *data, int pilih, int pesan_jumlah);

boolean operasitiket(KA *data, int pilih_kelas, int pesan_jumlah, int pilih_ka);

void hitungKeuntungan(KA *data, int pilih_ka, int pilih_kelas,
                      int pesan_jumlah_tiket);

void cetakKeuntungan(KA *data);

void hargaNaik(KA *data, int sz_eksekutif1, int sz_bisnis1, int sz_biasa1,
               int sz_eksekutif2, int sz_bisnis2, int sz_biasa2,
               int sz_eksekutif3, int sz_bisnis3, int sz_biasa3,
               int harga_eksekutif1, int harga_bisnis1, int harga_biasa1,
               int harga_eksekutif2, int harga_bisnis2, int harga_biasa2,
               int harga_eksekutif3, int harga_bisnis3, int harga_biasa3,
               int pilih_ka);

	KA *kereta_api1 = (KA *)malloc(sizeof(KA) * 1);
  	KA *kereta_api2 = (KA *)malloc(sizeof(KA) * 1);
  	KA *kereta_api3 = (KA *)malloc(sizeof(KA) * 1);

	kereta_api1->kode_kereta = 1;
  strcpy(kereta_api1->kode_jadwal, "JW00001");
  strcpy(kereta_api1->keberangkatan, "Jakarta");
  strcpy(kereta_api1->tujuan, "Bandung");
  strcpy(kereta_api1->tanggal, "tanggal");
	strcpy(kereta_api1->waktu_keberangkatan, "08.00");
	  strcpy(kereta_api1->KAI, "KAI 01");
	kereta_api1->status = 5;	  
//  kereta_api1->daya_tampung = 150;
//  kereta_api1->sisa_tiket = 150;
//  kereta_api1->kelas_eksekutif = 30;
//  kereta_api1->harga_eksekutif = 175000;
//  kereta_api1->kelas_bisnis = 40;
//  kereta_api1->harga_bisnis = 110000;
//  kereta_api1->kelas_biasa = 80;
//  kereta_api1->harga_biasa = 65000;
//  kereta_api1->id_eksekutif = 1;
//  kereta_api1->id_bisnis = 2;
//  kereta_api1->id_biasa = 3;
//  kereta_api1->keuntungan_kereta = 0;
//  kereta_api1->nextNode = kereta_api2;

void cari(){
	char masukankeberangkatan[200];
	char masukantujuan[200];
	char masukantanggal[200];
	printf("Cari Jadwal Kereta Api : \n");
	printf("Keberangkatan : ");
	scanf("%[^\t\n]s",&masukankeberangkatan);
	printf("Tujuan : ");
	scanf("%[^\t\n]s",&masukantujuan);
	printf("Tanggal : ");
	scanf("%[^\t\n]s",&masukantanggal);
	
	while (KA!=NULL)
    {
        if (strcmp(masukankeberangkatan,KA->keberangkatan)==0)
        {
        	if(strcmp(masukantujuan,KA->tujuan)==0){
        		if(strcmp(masukantanggal,KA->tanggal)==0){
        			printf("%s",KA->tanggal);
        		}
			}
        }
        KA = KA->NextAntrian;
    }
}










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
       					cari();
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
    
    
void kelolakota()
{
	int pilihan;
	printf("#KELOLA KOTA#\n");

	printf("1. Tambah Data Kota\n");
	printf("2. Lihat Data Kota\n");
	printf("3. Edit Data Kota\n");
	printf("4. Delete Data Kota\n");
	printf("99. Menu Utama\n\n");
	
	printf("Pilihan : ");
	scanf("%d",pilihan);
	switch(pilihan){
		case 1 :
			break;
		case 2 : 
		printf("aaa");
			lihatkota();
			break;
		case 3 : 
			break;
		case 4 : 
			break;
		case 99 : 
			break;
		default :
			printf("Tidak ada pilihan");
			kelolakota();
	}
}

void tambahkota(){
	int pilihan;
	
	printf("#TAMBAH DATA KOTA#\n");
	printf("Tambah Kota");
	printf("----------------------------------------------------------------------\n");
	printf("Kota Berhasil Ditambahkan / Kota Gagal Ditambahkan\n");
	printf("1. Tambah Data Kota\n");
	printf("2. Lihat Data Kota\n");
	printf("3. Edit Data Kota\n");
	printf("99. Menu Utama\n\n");
	printf("Pilihan : ");
	scanf("%d",pilihan);
	switch(pilihan){
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 99 :
			break;
	}
	
}

//void lihatKota() {
//	kota *k;
//	kota k1;
//    FILE *fp;
//    int n,i,j, counter=1;
//    
//    fp = fopen("kota.txt","r");
//	
//	printf("#LIHAT DATA KOTA#");
//	printf("\nData Lengkap Kota");
//	printf("\n-------------------------------------------------------------------\n");
//	printf("No\t\tKode Kota\t\tNama Kota\n");
//	while(fread(&k1,sizeof(kota),1,fp)) { 
////		fscanf(fp," %d|%[^|]|%[^|]|\n",&kota.nomor, &kota.kode_kota, &kota.nama_kota);
//		printf("%d\t\t%s\t\t\t%s\n",k1.nomor,k1.kode_kota,k1.nama_kota);
//		counter++;
//    }
//	
//	printf("\n\n-------------------------------------------------------------------");
//    fclose(fp);
//}

//
//
void lihatkota(){
	char nomor[5];
	char nama[100], kode[100];
    FILE *fp;
	fp = fopen("kota.txt","r");
  
	printf("#LIHAT DATA KOTA#\n\n");
	printf("Data Lengkap Kota\n");
	printf("------------------------------------------------------------------------------------------------------------\n");
	printf("No\t\tKode Kota\t\tNama Kota\n");
	

	while((fscanf(fp,"%[^|]|%[^|]|\n",&kode,&nama)) != EOF) { 
		fscanf(fp,"%[^|]|%[^|]|\n",&kode,&nama);
		//fscanf(fp,"%d;%[^|];%[^|];\n",&kota.nomor,&kota.kode_kota,&kota.nama_kota);
		printf("%s\t\t%s\t\t%s\n",nomor,kode,nama);
	}
	  fclose(fp);
}

void kelolarute(){
	int pilihan;
	printf("#KELOLA DATA RUTE#\n");
	printf("-----------------------------------------------------------------------------------------------------\n");
	printf("1. Tambah Data Rute\n");
	printf("2. Lihat Data Rute\n");
	printf("3. Edit Data Rute\n");
	printf("4. Delete Data Rute\n");
	printf("99. Menu Utama\n\n");
	printf("Pilihan : ");
	scanf("%d",&pilihan);
	switch(pilihan){
		case 1 :
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 99:
			break;	
	}
	
}


