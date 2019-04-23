/*
nama program  : singel linked list
nama : delvian ikhsan maulana
npm : 140810180065
tanggal buat : 23 april 2019
deskripsi : nomor 1
*/

#include <iostream>
using namespace std;


struct ElemtList{
 int nodaftar;
 char tim[20];
 char daerah[20];
 int gol;
 ElemtList* next;
};
typedef ElemtList* pointer;
typedef pointer List;

void createList(List& First){
    First = NULL;
}

void createElemt(pointer& pBaru){
    pBaru=new ElemtList;
    cout << "No. Daftar :";cin >>pBaru->nodaftar;
    cout << "Nama Tim   :";cin >>pBaru->tim;
    cout << "daerah asal:";cin >>pBaru->daerah;
 pBaru->next=NULL;
}

void insertFirst(List& First, pointer pBaru){
    if(First==NULL)
  First=pBaru;
  else{
   pBaru->next=First;
   First=pBaru;
  }
}

void traversal(List First){
    pointer pBantu;
 pBantu=First;
 cout << "No. Daftar\t"<< "Nama Tim\t"<< "daerah asal\t"<<"Gol\t"<<endl;
 while(pBantu != NULL){
        cout <<pBantu->nodaftar<<"\t"<<pBantu->tim<<"\t"<<pBantu->daerah<<"\t"<<endl;
  pBantu=pBantu->next;
 }
}

void deleteFirst(List& First, pointer& pHapus){
    if (First==NULL){
        pHapus=NULL;
        cout << "List kosong, tidak ada yang dihapus"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else{
        pHapus=First;
        First=First->next;
        pHapus->next=NULL;
    }
}

void insertLast(List& First, pointer pBaru){

    pointer last;
    if(First==NULL){
        First=pBaru;
    }
    else{
        last=First;
        while(last->next!=NULL){
            last=last->next;
    }
    last->next=pBaru;
    }
}

void deleteLast(List& First, pointer& pHapus){
    pointer last,precLast;
    cout << "Delete last"<<endl;
    if (First==NULL){
        pHapus=NULL;
        cout << "List Kosong, tidak ada yang dihapus"<<endl;
    }
    else if(First->next==NULL){
        pHapus=First;
        First=NULL;
    }
    else{
        last=First;
        precLast=NULL;
        while(last->next !=NULL){
            precLast=last;
            last=last->next;
        }
        pHapus=last;
        precLast->next=NULL;
    }
}


void insertAfter(List& First,pointer pCari,pointer pBaru){
    if (pCari->next==NULL)
        pCari->next=pBaru;
    else {
        pBaru->next=pCari->next;
        pCari->next=pBaru;
    }
}


void linearSearch(List First,int key, int& found, pointer& pCari){
    found=0;
    pCari=First;
    while (found==0 && pCari!=NULL) {
        if (pCari->nodaftar==key)
            found=1;
        else
        pCari=pCari->next;
        }

}

void update(List& First, int key) {
  pointer pToUpdate = NULL;
  cout << "nama: "; cin >> pToUpdate->gol;
  cout << endl;
}

void sortin(List& First){
  int count = 0, i;
  pointer start,curr,trail,temp;
  start=First;
  curr=NULL;
  trail=NULL;
  temp=NULL;

  while(start != NULL) {
    count++;
    start = start->next;
  }

  for(i = 0; i<count; ++i) {

    curr = trail = First;

    while (curr->next != NULL) {
      if (curr->nodaftar > curr->next->nodaftar) {

        temp = curr->next;
        curr->next = curr->next->next;
        temp->next = curr;


        if(curr == First)
          First = trail = temp;
        else
          trail->next = temp;
        curr = temp;
      }

      trail = curr;
      curr = curr->next;
    }
  }
}

int main()
{
    pointer p,pCari;
    List m;
    int ketemu;
    int kunci;
    int pilih;

    createList(m);
    while(1){
        system("cls");
        cout<<"Menu"<<endl;
        cout<<"1. Insert "<<endl;
        cout<<"2. Update Jumlah Gol"<<endl;
        cout<<"3. Tampilkan"<<endl;
        cout<<"4. Exit"<<endl;
        cout << "Masukan Pilihan : "; cin >> pilih;
        switch(pilih){
        case 1:
            createElemt(p);
            insertFirst(m, p);
            sortin(m);
        break;

        case 2:
            cout<<"\nMasukkan no daftar : "; cin>>kunci;
            linearSearch(m,kunci,ketemu,pCari);
            if (ketemu){
                cout<<"Ditemukan yang dicari "<<endl;
                update(m,kunci);
            }
            else {
                cout<<" Tidak Ditemukan yang dicari "<<endl;
            }
        break;

        case 3:
            traversal(m);
        break;

        case 4:
            return 0;
            break;
        }
        system("pause");
    }

    return 0;
}

