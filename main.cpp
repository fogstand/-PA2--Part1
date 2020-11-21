#include <iostream>
#include <fstream>
#include<string.h>
 using namespace std;
#define MAXLENGTH 12
#define MINLENGTH 8
int main() {

    ifstream openFile;
    int minLength=8;
    char pwd[MAXLENGTH];
    const int SIZE = 50;
    char password[SIZE];
    int length;

	int lowercase = 0, uppercase=0, specialcase = 0, numeric = 0,letter=1;
    int retryPassword = 0;
    int limitPassword = 5;
    int invalid = 0;

    while (retryPassword < limitPassword) {
    	invalid=0;
    	int lowercase = 0, uppercase=0, specialcase = 0, numeric = 0,letter=1;
        if (retryPassword > 0) {
        	
            cout << "You have" << limitPassword - retryPassword << " attempts left.\n";
        } 
    

    openFile.open("prevPswds.data");
    if (!openFile) {
        cout << "cannot open the file\n";
        return 1;
    }

    cout << "Please enter the password" << endl;
    cin.getline(password, SIZE);
    length = strlen(password);
    if (length > MAXLENGTH || length < MINLENGTH) {
        cout << "Please enter a password between 8 and 12 characters.\n";
        openFile.close();
        //retryPassword++;
        //continue;
        invalid=1;
    }
    
    while (openFile >> pwd) {
        if (!strcmp(pwd, password)) {
            cout << "This password already exists plase try a differernt pattern of password.\n";
            invalid = 1;
            break;
        }
    }
    openFile.close();
    /*if (invalid) {
        retryPassword++;
        continue;
    }*/
    char *substringCheck = strstr(password, "UCD");
    if (!substringCheck) {
        cout << "Your password must contain UCD in it.Please try again.\n";
       // retryPassword++;
        //continue;
        invalid=1;
    }
    
    for (int i = 0; i < length; i++)
    {
        if (password[i] == '0' || password[i] == '1' || password[i] == '5') {
            invalid = 1;
            cout << "Invalid password should not contain integers 0,1,5\n";
            break;
        }
    for (int i = 0; i < length; i++){
	
        if (password[i] == '2' || password[i] == '3' || password[i] == '4' ||
            password[i] == '6' || password[i] == '7' || password[i] == '8' ||
            password[i] == '9') {
       //     minLength++;
            numeric = 1;
            //continue;
        }
    }
    for (int i = 0; i < length; i++)
    {
	
        if (password[i] == 'l' || password[i] == 'i' || password[i] == 'o' || password[i] == 'z'
            || password[i] == 'I' || password[i] == 'O' || password[i] == 'S') {
     //       minLength++;
     		letter=0;
        }
    }
    for (int i = 0; i < length; i++){
	
        /*if ((password[i]!='U' && password[i]!='C' && password[i]!='D') && (password[i] >= 65 && password[i] <= 90))  {
        	
            uppercase = 1;
        }*/
        if(password[i]=='U')
        {
        	i=i+3;
		}
	
		if(password[i] >= 65 && password[i] <= 90)
		{
			uppercase=1;
		}
    }
     for (int i = 0; i < length; i++){
	
        if (password[i] >= 97 && password[i] <= 122) {
            lowercase = 1;
        }
    }
    for (int i = 0; i < length; i++){
	//considered all possible symols  ~ ! @ # $ % ^ & * ( ) - _ + = | < > ? , . / ; ' : " { }[ ] . ` \ 
        if ((password[i] >= 33 && password[i] <= 47) || (password[i] >= 58 && password[i] <= 64) || (password[i] >= 91 && password[i] <= 96)|| (password[i] >= 123 && password[i] <= 126)  ) {
        	//cout<<"in special case";
			specialcase=1;
        } 
	}

/*
if( strlen(password)<minLength)
{
cout <<"Password length should be 8 characters atleast.\n"<<strlen(password);
retryPassword++;
continue;
}
*/
if (uppercase==0)
{
cout <<"Password must have uppercase character.\n";
//retryPassword++;
invalid=1;
//continue;
}
if (letter==0)
{
cout <<"U can not have letters l o i z or I O S\n";
//retryPassword++;
invalid=1;
//continue;
}

if (lowercase==0)
{
cout << "Password must have lowercase character.\n";
//retryPassword++;
invalid=1;
//continue;
}

if (specialcase==0)
{
cout <<"Password must have one special character.\n";
//retryPassword++;
invalid=1;
//continue;
}

if(numeric == 0)
{
//retryPassword++;
cout <<"Password must have an integer\n";
invalid=1;
//continue;
}
if(invalid)
{
retryPassword++;
//continue;
}

if (retryPassword >=5)
{
cout <<"Password tries exceeds  limit of 5.\n";

}

if(invalid==0)
{

cout <<"Its a valid Password.\n";
break;
}
}
return 0;
}
