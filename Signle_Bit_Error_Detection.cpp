/*Hamming code - Error Detection
  Given by R W Hamming 
  7 bit Hamming code is used commonly
  Data bit = 4
  Parity bit = 3
  [D7] [D6] [D5] [P4] [D3] [P2] [P1]                
  7     6   5     4    3    2    1
  P1 = D3^D5^D7
  P2 = D3^D6^D7
  P4 = D5^D6^D7
  
Example: 
  1 0 1 1 = DATA bits 
  1  0  1  0  1  0  1
        |     |     |
	    P3    P2   P1 
 */

#include<iostream>
using namespace std;

int main()
{
	int a[4], b[4], p1, p2, p4, d[8], A, B, C, i;
	cout<<"\nEnter 4 bit data word:"<<endl;
	cin>>a[7]; 
	cin>>a[6]; 
	cin>>a[5]; 
	cin>>a[3];
	a[4]=a[7]^a[6]^a[5]; 
	a[2]=a[7]^a[6]^a[3];
	a[1]=a[7]^a[5]^a[3];  
	cout<<"\n7 bit Hamming code word:"<<endl; // 7 Bit of Hamming code generation.(4 are Data bit & 3 are Parity bit) 
	// A7, A6, A5, A3 = Data bit
	// A4, A2, A1 = Parity bit
	for(i = 7; i > 0; i--)
	{
		cout<<a[i]<< " "; // Prints 7 Parity bits 
	}
	cout<<"\nEnter the received Hamming code word:"<<endl;

	for(i = 7; i > 0; i--)
	{
		cin>>d[i]; // Read the received Hamming code with or without change the bits.
	}
	p4=d[7]^d[6]^d[5]; // Parity 4 bit is Depends on D5 D6 D7 = It will give odd no of 1s. 
	p2=d[7]^d[6]^d[3]; // Parity 2 bit is Depends on D3 D6 D& it will give odd no of 1s.
	p1=d[7]^d[5]^d[3]; // Parity 1 bit is Depends on D3 D5 D7 & it will give odd of 1s.
	cout<<"Our parity bit of received code word:"<<endl;
	cout<<" d4: "<<d[4]<<" d2: "<<d[2]<<" d1: "<<d[1]<<endl;

	A=d[4]^p4;
	B=d[2]^p2;
	C=d[1]^p1;

	cout<<"POSITION OF ERROR:"<<endl;
	cout<<" A:"<<A<<" B:"<<B<<" C:"<<C<<endl;
	if(A==0 && B==0 && C==0)
	{
		cout<<"RECEIVED CODE IS ERROR FREE:"<<endl;
	}
	if(A==0 && B==0 && C==1)
	{
		cout<<"RECEIVED CODE HAS ERROR AT FIRST BIT FROM THE RIGHT(D[1]):"<<endl;
	}
	if(A==0 && B==1 && C==0)
	{
		cout<<"RECEIVED CODE HAS ERROR AT SECOND BIT FROM THE RIGHT(D[2]):"<<endl;
	}
	if(A==0 && B==1 && C==1)
	{
		cout<<"RECEIVED CODE HAS ERROR AT THIRD BIT FROM THE RIGHT(D[3]):"<<endl;
	}
	if(A==1 && B==0 && C==0)
	{
		cout<<"RECEIVED CODE HAS ERROR AT FOURTH BIT FROM THE RIGHT(D[4]):"<<endl;
	}
	if(A==1 && B==0 && C==1)
	{
		cout<<"RECEIVED CODE HAS ERROR AT FIFTH BIT FROM THE RIGHT(D[5]):"<<endl;
	}
	if(A==1 && B==1 && C==0)
	{
		cout<<"RECEIVED CODE HAS ERROR AT SIXTH BIT FROM THE RIGHT(D[6]):"<<endl;
	}
	if(A==1 && B==1 && C==1)
	{
		cout<<"RECEIVED CODE HAS ERROR AT SEVENTH BIT FROM THE RIGHT(D[7]):"<<endl;
	}
	return 0;

}

