#include <iostream>
#include <stdio.h>
#include <iomanip>
#include <stdlib.h>

using namespace std;

struct Node
{
	long data;
	Node *next;
	Node *prev;
};

Node *head; //variable awal untuk kepala linked list
Node *tail; //variable awal untuk ekor linked list
Node *print; //variable awal untuk menampilkan
Node *del; //variable awal untuk menghapus
Node *entry; //variable awal untuk input awal

void inisialisasi()
{
	head = NULL;
	tail = NULL;
}

int isEmpty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

void input(int *data)
{
	entry = new Node;
	entry-> data = *data;
	entry->next = NULL;
	entry->prev = NULL;
	
	if(isEmpty())
	{
		head = entry;
		head->next = NULL;
		head->prev = NULL;
		tail = head;
	}
	else
	{
		tail->next = entry;
		entry->prev = tail;
		tail = entry;
	}
}

void hapus()
{
	int simpan;
	if (head != NULL)
	{
		if (head->next != NULL)
		{
			del = head;
			simpan = head->data;
			cout << "\n" << simpan << " telah di hapus " << endl;
			head = head->next;
			head->prev = NULL;
			delete del; 
		}
		else
		{
			simpan = head->data;
			cout << "\n" << simpan << " telah di hapus " << endl;
			head = NULL;
		}
	}
	else
	cout << "\nLinked List masih kosong" << endl;
}

void cetak()
{
	print = head;
	if (head != NULL)
	{
		while (print != NULL)
		{
			cout << "\n\t" << print->data;
			print = print->next;
		}
	}
	else
	cout << "\nTidak ada data yang di tampilkan" << endl;
}

void menu()
{
	char pilih, ulang;
	int data;
	do
	{
		system("cls");
		menu:
			cout << "============================" << endl;
			cout << " PROGRAM DOUBLE LINKED LIST " << endl;
			cout << "============================" << endl;
			cout << " Pilih Menu: " << endl;
			cout << " 1. Entri Data" << endl;
			cout << " 2. Hapus Data" << endl;
			cout << " 3. Tampilkan Semua Data" << endl;
			cout << " 4. Keluar " << endl;
			cout << "============================" << endl;
			cout << " \n Masukkan Pilihan Anda: " << endl;
			cin >> pilih;
			
			switch (pilih)
			{
			case '1':
				cout << "\nMasukkan data : ";
				cin >> data;
				input(&data);
				cout << "\n" << data << "telah di masukkan" << endl;
				break;
			case '2':
				hapus();
				break;
			case '3':
				cetak();
				break;
			case '4':
				cout << "\nTerimakasih telah menggunakan program ini" << endl;
			exit(EXIT_SUCCESS);
				break;
			default:
				cout << "\nPilih ulang" << endl;
				goto menu;
			}
			cout<< "\nKembali ke menu? (Y/n)";
			cin >> ulang;
	} while (ulang == 'y' || ulang == 'Y');
}

int main()
{
	inisialisasi();
	menu();
	return EXIT_SUCCESS; 
}
