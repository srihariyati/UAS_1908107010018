//bismillahirahmanirrahim

//Sri Hariyati - 1908107010018
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100


int login();
int showdata();
int finddata();
int adddata();
int deldata();
int changedata();
int awal();
void table();


typedef struct penonton{
	char kd_tiket[MAX];
	char nama[MAX];
	int umur;
	char seats[MAX];
} input;

int main(){
	system("cls");
	printf("\t==================================\n");
	printf("\t==========SELAMAT DATANG==========\n");
	printf("\t==================================\n");
	printf("\t   +-------------------------+\n");
	printf("\t   | DI PORTAL DATA PENONTON |\n");
	printf("\t   |   BIOSKOP APAADANYA     |\n");
	printf("\t   +-------------------------+\n");
	login();
	awal();
}

int awal(){
	int status=2,menu;
	char ask;

	menu:
	printf("\n\n\t\tMenu\n");
	printf("-------------------------------\n");
	printf("1. Tampilkan Data Penonton\n");
	printf("2. Cari Data Penonton\n");
	printf("3. Tambah Data Penonton\n");
	printf("4. Hapus Data Penonton\n");
	printf("5. Ubah Data Penonton\n");
	printf("6. Selesai\n");
	printf("-------------------------------\n");
	printf("Pilihan Anda :");scanf ("%d",&menu);
	printf("\n-------------------------------\n");
	

	while(menu!=6){ 
			
			switch(menu){
				case 1:showdata();
				break;

				case 2:finddata();
				break;

				case 3:adddata();
				break;

				case 4:deldata();
				break;

				case 5:changedata();
				break;

				default:
				goto menu;
			}
			
		}	
			lanjut:
				printf("\n");
				printf("y = untuk lanjut\n");
				printf("n = untuk keluar\n");
				printf("Apakah anda ingin melanjutkan? (y/n) :");
				getchar();scanf("%c",&ask);
				if ((ask =='y')|| (ask == 'Y')){
					goto menu;	
				} else if ((ask =='n')|| (ask == 'N')){
					exit(1);
				}else {
					goto lanjut;
				}
	
	return 0;
}

//prototype login
int login(){
	char password[100];
	char username[100];
	int status=1;

	printf("----------\n");
	printf("  Login\n");
	printf("----------\n");


	while (status==1){
	printf("\nMasukkan Username:");
	scanf(" %[^\n]",username);
	fflush(stdin);
	
	printf("Masukkan password:");
	scanf(" %[^\n]",password);

	if((strcmp(username,"admin")==0) && (strcmp(password,"root")==0)){
		printf("\nStatus :Login Berhasil!");
		break;
	}else{
		printf("\nStatus :Username atau Password salah\n");
		status=1;
		}
	}

}

int showdata(){//prototype menampilkan data
	char a;
	int c;
 
	printf("menampilkan data\n");
	printf("----------------\n");
	
	//openfile
	FILE *fp1;
	fp1 = fopen("data/data.txt","r");//buka file dalam mode r

	while((c=fgetc(fp1)) != EOF){//seelama belum nerjumpa akhir text
		putchar(c);
	}

		awal();//kembali ke prototype awal
	
	fclose(fp1);//menutup file
	
	//meminta kepastian kepada user
	printf("Apakah Anda ingin melanjutkan?(y/n) :");
	getchar();scanf("%c",&a);
	if((a=='y')||(a=='Y')){
		awal();
	}if((a=='n')||(a=='N')){
		exit(1);
	}
}


int adddata(){//prototype menambahkan data
	input input;
	char a;
	int nilai=1;
	add:
	printf("\nmenambah data\n");
	printf("=============\n");
	FILE *fp1;
	if((fp1=fopen("data/data.txt", "a"))==NULL){//cekfile ada atau tidak
		printf("data tidak ada\n");
	}
	printf("Kode Tiket:");
	while ((getchar()) != '\n');
	gets(input.kd_tiket);
	fputs(input.kd_tiket,fp1);//memasukkan data kedalam kode tiket
	fputs(",",fp1);
	 
	printf("Nama:");gets(input.nama); 
	fputs(input.nama,fp1);//memasukkan nama
	fputs(",",fp1);
	
	printf("Umur :");fscanf(stdin," %d",&input.umur);
	fprintf(fp1,"%d",input.umur);
	fputs(",",fp1);
	 
	printf("Seats:");
	while ((getchar()) != '\n');
	gets(input.seats);
	fputs(input.seats,fp1);
	fputs(".",fp1);

	char enter = '\n';
	fprintf(fp1,"%c",enter);//agar ter enter
	
	fclose(fp1);
	printf("\n");

	//meminta kepastian
	pasti:
	printf("Apakah Anda ingin melanjutkan mengisi data?(y/n) :");
	scanf("%c",&a);
	if((a=='y')||(a=='Y')){
		nilai++;
		printf("nilai = %d \n",nilai);

		goto add;
	}
		else if((a =='n')||(a =='N')){
		awal();

		}else goto pasti;
}
//seharusnya ini berjalan, ya tapi karena gabisa dibuat , yaudahla :(
int finddata(){
	printf("cari data\n");
}
int deldata(){
	printf("hapus data\n");
}
int changedata(){
	printf("mengubah data\n");
}
