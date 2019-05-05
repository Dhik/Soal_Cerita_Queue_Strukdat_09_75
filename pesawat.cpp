#include <iostream>
using namespace std;
struct ElmtList{
	string nPes;
	string destinasi;
	string asal;
	string cat;
	ElmtList* next;
};
typedef ElmtList* pointer;
typedef pointer List;
struct Queue{
	List Head;
	List Tail;
};
Queue q;
void createQueue(Queue& q){
	q.Head=NULL;
	q.Tail=NULL;
}
void createElmt(pointer& pBaru){
	pBaru=new ElmtList;
	cout<<"Nama Pesawat : "; cin>>pBaru->nPes;
	cout<<"Destinasi : "; cin>>pBaru->destinasi;
	cout<<" Asal Keberangkatan : "; cin>>pBaru->asal;
	pBaru->cat="NULL";
	pBaru->next=NULL;
}
void insertQueue(Queue& q, pointer pBaru){
	if(q.Head==NULL && q.Tail==NULL){
		q.Head=pBaru;
		q.Tail=pBaru;
	}
	else{
		q.Tail->next=pBaru;
		q.Tail=pBaru;
	}
}
void linearSearch(Queue& q, int& found, string& key, pointer pCari){
	found=0;
	pCari=q.Head;
	while(pCari != NULL && found==0){
		if(pCari->nPes==key){
			found=1;
		}
		else{
			pCari=pCari->next;
		}
	}
}
void deleteQueue(Queue& q, pointer pHapus){
	if(q.Head==NULL && q.Tail==NULL){
		cout<<"Queue was Empty"<<endl;
	}
	else if(q.Head->next==NULL){
		pHapus=q.Head;
		pHapus=NULL;
	}
	else{
		pHapus=q.Head;
		q.Head=q.Head->next;
		pHapus=NULL;
	}
}
void traversal(Queue q){
	pointer pBantu;
	if(q.Head==NULL && q.Tail==NULL){
		cout<<"Queue is Empty"<<endl;
	}
	else{
		pBantu=q.Head;
		do{
			cout<<"\t"<<pBantu->nPes<<"\t\t"<<pBantu->destinasi<<"\t\t"<<pBantu->asal<<"\t\t"<<pBantu->cat<<endl;
			pBantu=pBantu->next;
		}
		while(pBantu != NULL);	
	}
}
typedef pointer poin[100];
main(){
	pointer h, cari;
	poin p;
	int n;
	string key;
	int found;
	char choose;
	
	createQueue(q);
	cout<<"Masukan banyak daftar pesawat : "; cin>>n;
	for(int i=0; i<n; i++){
		createElmt(p[i]);
		insertQueue(q, p[i]);
		cout<<endl;
	}
	cout<<"\tDaftar Pesawat"<<endl;
	cout<<"===================================================================================="<<endl;
	cout<<"\tNama Pesawat\tDestinasi\tAsal Keberangkatan\tCatatan"<<endl;
	cout<<"===================================================================================="<<endl;
	traversal(q);
	cout<<endl;
	cout<<"\t Apakah anda ingin Memasukan Catatan mengenai Penerbangan ? "; cin>>choose;
	if(choose=='Y'||choose=='y'){
		cout<<"Masukan Nama Pesawat : "; cin>> key;
		linearSearch(q, found, key, cari);
		if(found){
			for(int i=0; i<n; i++){
				if(key==p[i]->nPes){
					cout<<"Masukan Catatan : "; cin>>p[i]->cat;
				}
			}
		}
		else{
			cout<<"Unfounded "<<endl;
		}
	}
	else{
		return 0;
	}
	cout<<"\tDaftar Pesawat"<<endl;
	cout<<"===================================================================================="<<endl;
	cout<<"\tNama Pesawat\tDestinasi\tAsal Keberangkatan\tCatatan"<<endl;
	cout<<"===================================================================================="<<endl;
	traversal(q);
}
