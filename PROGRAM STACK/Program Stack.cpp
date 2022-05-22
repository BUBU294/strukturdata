#include <iostream>
using namespace std;

//deklarasi variable
int maksimal = 5;
string arrayData[5];
int top = 0;

bool isFull()
{
	if (top == maksimal)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isEmpty()
{
	if (top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void pushArray(string data)
{
	if (isFull())
	{
		cout << "Data penuh" << endl;
	}
	else
	{
		arrayData[top] = data;
		top++;
	}
}

void popArray()
{
	if (isEmpty())
	{
		cout << "Data kosong!!" << endl;
	}
	else
	{
		arrayData[top - 1] = "";
		top--;
	}
}

void peekArray(int posisi)
{
	if (isEmpty())
	{
		cout << "Data kosong!!" << endl;
	}
	else
	{
		int index = top;
		for (int i = 0; i < posisi; i++)
		{
			index--;
		}
		cout << "Data posisi ke-" << posisi << " : " << arrayData[index] << endl;
	}
}

int countArray()
{
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		return top;
	}
}

void destroyArray()
{
	for (int i = 0; i < top; i++)
	{
		arrayData[i] = "";
	}
	top = 0;
}

void displayArray()
{
	if (isEmpty())
	{
		cout << "Data kosong!!" << endl;
	}
	else
	{
		cout << "Data stack array : " << endl;
		for (int i = maksimal - 1; i >= 0; i--)
		{
			if ( arrayData[i] != "")
			{
				cout << "Data : " << arrayData[i] << endl;
			}
		}
		cout << "\n"
			 << endl;
	}
}

int main()
{
	pushArray("Muhammad");								  // pertama masuk stack (paling bawah) urutan = 0
	pushArray("Abu Bakar Ash-shiddiq");					  // masuk stack ke-2 urutan = 1
	pushArray("Umar bin Khattab");						  // masuk stack ke-3 urutan = 2
	pushArray("Utsman bin Affan");						  // masuk stack ke-4 urutan = 3
	pushArray("Ali bin Abi Thalib");					  // masuk stack ke-5 urutan = 4
	displayArray();										  // menampilkan stack
	
	peekArray(3);										  // menampilkan data pada index tertentu
	cout << "Banyak Data : " << countArray() << endl;     // menghitung banyak data pada stack
	cout << "\n"
		 << endl;
		 
	cout << "Apakah data full? " << isFull() << endl;		// cek apakah stack penuh? ya= 1, tidak = 0
	pushArray("Abdurrahman bin Auf");						// masuk stack ke-6, padahal masimal stack hanya 5, program menunjukkan pesan = Data 
	popArray();												// mengurangi data stack paling atas / TOP
	displayArray();											// menampilkan stack
	
	peekArray(3);											// menampilkan data pada index tertentu
	cout << "Banyak Data : " << countArray() << endl;		// menghitung banyak data pada stack 
	cout << "/n"
		 << endl;
	
	cout << "Apakah data full? " << isFull() << endl;		// cek apakah stack penuh? ya= 1, tidak = 0
	cout << "Apakah data kosong? " << isEmpty() << endl;	// cek apakah stack kosong? ya= 1, tidak = 0
	
	destroyArray();											// menghapus stack
	// cek lagi setelah destroy berapa jumlah data ? ataukah full / kosong
	cout << "Banyak Data : " << countArray() << endl;		// menghitung banyak data pada stack
	cout << "Apakah data full? " << isFull() << endl;		// cek apakah stack penuh? ya= 1, tidak = 0
	cout << "Apakah data kosong? " << isEmpty() << endl;	// cek apakah stack kosong? ya= 1, tidak = 0
}
