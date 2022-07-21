#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

COORD coord ={0,0};
void gotoxy (int p, int o)
    {
    coord.X=p;
    coord.Y=o;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
    }
int menu;
int a=0 , b, c, d,e=0,kode['0'],harga['0'], jumlah['0'], tunai['0'], jumharga['0'], totharga['0'], pemasukan;
char nama['0'][32],baris[64];
FILE *penjualan ;
void penyimpanan()
{
     rewind(penjualan);
      if(fgets(baris,64,penjualan)==NULL){
            a=0;
            fprintf(penjualan,"Data Penjualan");
      }
      else{
            while(!feof(penjualan)){
                  a++;
                  fscanf(penjualan,"\nKode Barang : %d\nNama Barang : %s\nHarga Barang : %d\nJumlah Barang : %d\nJumlah harga : %d\nTotal Harga : %d",&kode[a],nama[a],&harga[a],&jumlah[a],&jumharga[a],&totharga[a]);
            }e=kode[a];
      }
}
void input_penjualan ()
{
     b=1;
     d=0;
      while(b==1)
      {
            a++;
            e++;
            kode[a]=e;
            printf("\n Kode Jual              : %d\n",kode[a]);
            printf("Nama Barang   : ");
            scanf(" %s",nama[a]);
            printf("Harga Barang  : Rp.");
            scanf(" %d",&harga[a]);
            printf("Jumlah Barang : ");
            scanf(" %d",&jumlah[a]);
            jumharga[a]=harga[a]*jumlah[a];
            printf(" Jumlah harga           : Rp.%d\n",jumharga[a]);
            totharga[a]=jumharga[a];
            printf(" Total Harga            : Rp.%d\n",totharga[a]);
            fprintf(penjualan,"\nKode Barang : %d\nNama Barang : %s\nHarga Barang : %d\nJumlah Barang : %d\nJumlah harga : %d\nTotal Harga : %d",kode[a],nama[a],harga[a],jumlah[a],jumharga[a],totharga[a]);
            d=d+totharga[a];
            printf("\n Harga Yang Harus Dibayar : Rp.%d",d);
            printf("\n\n ketik 1 untuk input lagi dan ketik 2 untuk kembali ke menu : ");
            scanf("%d",&b);
      }
}
void viewjual(){
      pemasukan=0;

      if(a<1){
            printf(" Data Masih Kosong");
      }else{
            b=1;
            while(b<=a){
                  printf("%d.Kode Jual     : %d\n",b,kode[b]);
                  printf("  Nama Barang   : %s\n",nama[b]);
                  printf("  Harga Barang  : Rp.%d\n",harga[b]);
                  printf("  Jumlah Barang : %d\n",jumlah[b]);
                  printf("  Jumlah harga  : Rp.%d\n",jumharga[b]);
                  printf("  Total Harga   : Rp.%d\n",totharga[b]);
                  printf("==================\n");
                  pemasukan=pemasukan+totharga[b];
                  b++;
            }
            printf("\n Total Pemasukan : Rp.%d",pemasukan);
      }
}
void penutup(){
      fclose(penjualan);
      penjualan=fopen("penjualan.txt","w+");
      fclose(penjualan);
      penjualan=fopen("penjualan.txt","a+");
      b=1;
      while(b<=a){
            fprintf(penjualan,"\nKode Barang : %d\nNama Barang : %s\nHarga Barang : %d\nJumlah Barang : %d\nJumlah harga : %d\nTotal Harga : %d",kode[b],nama[b],harga[b],jumlah[b],jumharga[b],totharga[b]);
            b++;
      }
}
int main()
{
    while(menu != 6)
    {
        system("pause");
        system("cls");
    penjualan=fopen("penjualan.txt","a+");
    penyimpanan();
    gotoxy(1,1); printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
    gotoxy(1,2); printf("\xba                        \xba\n");
    gotoxy(1,3); printf("\xba                        \xba\n");
    gotoxy(1,4); printf("\xba                        \xba\n");
    gotoxy(1,5); printf("\xba                        \xba\n");
    gotoxy(1,6); printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
    gotoxy(2,2); printf("nama : Teguh Riyadi \n");
    gotoxy(2,3); printf("nim  : 672019154 \n\n\n\n\n\n");

    gotoxy(1,7); printf("\xc9\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbb\n");
    gotoxy(1,9); printf("\xc8\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xcd\xbc\n");
    gotoxy(1,8);printf("  ============= DATA PENJUALAN ============\n");
    gotoxy(1,11);printf("1. Input Penjualan\n");
                printf(" 2. lihat data Penjualan\n");
                printf(" 3. cari data Penjualan\n");
                printf(" 4. Update Penjualan\n");
                printf(" 5. hapus data Penjualan\n");
                printf(" 6. Exit dan simpan\n");
                printf("===========================\n ");
                printf("masukkan pilihan    : ");
                scanf("%d",&menu);
    switch(menu)
    {
    case 1 :
        input_penjualan();
        getch();
        break;
    case 2 :
        viewjual();
        getch();
        puts("");
        break;

    }
    penutup();
    };
    fclose(penjualan);

}
