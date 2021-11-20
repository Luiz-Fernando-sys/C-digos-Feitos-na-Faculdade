#include <iostream>
#include <cstdlib>

using namespace std;

int PIN(int numero_limite){
	int n;
	n = 1;
		while(n<=numero_limite){
			if(n < 4){
				cout << n;
				cout << "\n";
				n = n++;	
			}
			if(n==4){
				cout << "\nPIN\n";
				n = n++;
			}
			if(n>4){
				int conta1, conta2;
				conta1 = n % 4;
//				conta2 = conta1 % 2;
				
				if(conta1 == 0){
					cout << "\nPIN\n";
					n = n++;
				} else{
					if(conta1 != 0){
						cout << n;
						cout << "\n";
						n = n++;
					}
				}
			}
		}
}

int main()
{
	setlocale(LC_ALL, "Portuguese");
	int num_limite;
	
	cout << "Informe um número limite para contagem de PINS \n";
	cin >> num_limite;
	system("cls");
	PIN(num_limite);
	system("PAUSE");
	 
	return 0;
}