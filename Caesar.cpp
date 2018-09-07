/*
	Name Program : Caesar Encrypt.cpp
	Date : 17 April 2017
*/
#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;
char caesarEncrypt(char c, int k)
{
	if(isalpha(c) && c != toupper(c))
	{
		c = toupper(c);
		c = (((c-65)+k)%26);
	}
	else
	{
		c = (((c-65)+26)%26)+65;
		c = tolower(c);
	}
return c;
}

int main()
{
	string input,output;
	int choice=0;
	
	while(choice !=2)
	{
		cout<<endl<<"Press 1: Encryption/Decryption;"<<endl;
		cout<<"Press 2: quit"<<endl;
		try
		{
			cin>>choice;
			if(choice != 1 && choice !=2) throw "Incorrect Choice";
		}
		catch(const char* chc)
		{
			cerr<<"Incorrect Choice!!"<<endl;
			return 1;
		}
		if(choice == 1)
		{
			int key;
			try
			{
				cout<<endl<<"Choose key value (Choose a number between 1 to 26): ";
				cin>>key;
				cin.ignore();
				if(key <1 || key >26) throw "Incorrect Key";
			}
			catch(const char* k)
			{
				cerr<<"Incorrect key Value Choosen!!!"<<endl;
				return 1;
			}
			
			try
			{
				cout<<endl<<"Note: put lower case letters for encryption and "<<endl;
				cout<<"Upper Case letters for decryption"<<endl;
				cout<<endl<<"Enter cipertext(only alphabets) and press enter to continue: ";
				getline(cin,input);
				
				for(int i=0;i<input.size();i++)
				{
					if((!(input[i]>='a' && input[i] <='z')) &&(!(input[i]>='A' && input[i] <='Z'))) throw "Incorrect String";
				}
			}
			catch(const char* str)
			{
				cerr<<"Your string may have digits or special symbols!!!"<<endl;
				cerr<<"Please put only alphabets!!!"<<endl;
				return 1;
			}
			
			for(unsigned int x=0;x<input.length();x++)
			{
				output += caesarEncrypt(input[x],key);
			}
			
			cout<<output<<endl;
			output.clear();
		}
	}
	
return 0;	
}
