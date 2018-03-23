// FCI – Programming 1 – 2018 - Assignment 2
// Program Name: Morse code
// Last Modification Date:  2/28/2018
// Author1 and ID and Group: Name:mohamed hamdy mohamed      ID:20170227      Group:G9
// Teaching Assistant:
//Purpose:encrypt or dycrypt a message


#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int  main()
{
while (true)
{
	cout <<endl;
	cout <<"Ahlan ya user ua habibi. \n";
    string choosenumber ;
    cout <<"What do you like to do today? \n";
    cout <<"1- Cipher a message \n";
    cout <<"2- Decipher a message \n";
    cout <<"3- End \n";
    cin >> choosenumber ;
    if (choosenumber == "1" )
    {
        string message ;
        cout <<"Please enter the message to cipher: " ;
        cin.ignore();
        getline(cin, message);
        string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        string Morse[62] = {".- ","-... ","-.-. ","-.. ",". ","..-. ","--. ",".... ",".. ",".--- ","-.- ",".-.. ","-- ","-. ","--- ",".--. ","--.- ",".-. ","... ","- ","..- ","...- ",".-- ","-..- ","-.-- ","--.. ",".- ","-... ","-.-. ","-.. ",". ","..-. ","--. ",".... ",".. ",".--- ","-.- ",".-.. ","-- ","-. ","--- ",".--. ","--.- ",".-. ","... ","- ","..- ","...- ",".-- ","-..- ","-.-- ","--.. ","---- ",".--- ","..--- ","...-- ","....- ","..... ","-.... ","--... ","---.. ","----. "};
        for (int  i = 0 ; i < message.length() ; i++)
        {
            for (int j=0 ; j< 62; j++)
            {
                if (message[i] == alphabet[j])
                {
                    cout << Morse[j];
                }
                if (message[i] == ' ')
                {
                    cout <<"   " ;
                    break;
                }

            }
        }
    }
    else if (choosenumber == "2")
    {
        string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        string Morse[62] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..",".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--..","-----","----.","---..","--...","-....",".....","-....","--...","---..","----."};
        string decryption;
        cin.ignore();
        string message ;
        cout <<"Enter your cipher (for example, ... --- ...  ... --- ...) :  "<<endl;
        getline(cin,message);
        string letter;
        for(int i=0; i< message.length(); i++)
        {
            while (/*(int)*/message[i]!=32)
            {

                letter+=message[i];
                i++;
            }
            for(int j=0 ; j<62; ++j)
            {
                if(letter == Morse[j])
                {
                    decryption += alphabet[j];
                    letter="";
                }
            }
            if (/*(int)*/message[i]==32)
            {
                if (/*(int)*/(message[i+1]==32 && message[i+2] == 32)||(message[i+1]==32))
                {
                    decryption+=" ";
                }
            }


        }
        cout<<decryption;


    }

        else if (choosenumber == "3")
        {
        	break ;
		}
		else
		{
			cout <<"Error \n";
			string choosemunber ;
		 	cout << "Enter any key to repeat the list :";
		 	cin >> choosenumber ;

		}




}






    return 0 ;
}


