#include <iostream>
#include <string>
#include<cmath>
#include <algorithm>
using namespace std;
//  This function belongs to cipher number zero
int FindA(int a)
{
    for(int i=0; i<26; ++i)
    {
        if((i*a)%26==1) return i;
    }
}
//End of This function
int main()
{
	while (true)
	{	

	cout << endl<<endl;
	string cipher_number;
    cout <<"Ahlan ya user ya habibi. \n"<<"if you want Affine Cipher press 0 . \n"<<"if you want Caesar Cipher press 1 . \n";
    cout <<"if you want Atbash Cipher press 2 . \n"<<"if you want ROT13 Cipher press 3 . \n"<<"if you want Baconian Cipher  press 4 . \n";
    cout <<"if you want Simple Substitution Cipher press 5 . \n"<<"if you want Polybius Square Cipher press 6 . \n"<<"if you want Morse Cipher press 7 . \n";
    cout <<"if you want XOR Cipher  press 8 . \n"<<"if you want Rail-fence Cipher press 9 . \n"<<"To End press 10 . \n";
    cout << "\n\nEnter your cipher number please :";
    cin >> cipher_number ;
    if (cipher_number == "0" )
    {
        while(true)
        {
            string input, encryption, decryption;
            int x,y,a,b;
            cout<<"Ahlan ya user ya habibi. \n What do you like to do today? \n1- Cipher a message \n2- Decipher a message \n3- End \n";
            cin>>x;

            switch(x)
            {
            case 1:
                cout<< "please enter the decipher keys a and b for the letter to be deciphered in (ax+b)%26"<<'\n';
                cin>>a>>b;
                while (a<0 && b<0)
                {
                    cout<<"a & b must be > 0 please re-enter them : ";
                    cin>> a>>b;
                }
                cout<<"Please enter the message : \n";
                cin.ignore();
                getline(cin,input);
                for (int i=0; i<(int)input.length(); ++i)
                {
                    if((int)input[i]==32)
                    {
                        encryption += " ";
                        continue;
                    }
                    else if((int)input[i]<=90 && (int)input[i]>=65)
                    {
                        y = input[i]-'A';
                        encryption +=(char)((a*y+b)%26 +'A');
                    }
                    else if ((int)input[i]<=122 && (int)input[i]>=97)
                    {
                        y = input[i]-'a';
                        encryption +=(char)((a*y+b)%26 +'a');
                    }
                    else
                    {
                        encryption += input[i];
                    }
                }
                cout<<"Your encrypted message is "<<'"'<<encryption<<'"'<<'\n';
                break;

            case 2:
                cout<< "please enter the cipher keys a,b and c for the letter to be ciphered in a(x-b)%c"<<'\n';
                cin>>a>>b;
                while (a<0 && b<0)
                {
                    cout<<"a & b must be > 0 please re-enter them : ";
                    cin>> a>>b;
                }
                a = FindA(a);
                cout << a<<'\n';
                cout<<"Please enter the message : \n";
                cin.ignore();
                getline(cin,input);
                for (int i=0; i<(int)input.length(); ++i)
                {
                    if((int)input[i]==32)
                    {
                        decryption += " ";
                        continue;
                    }
                    else if((int)input[i]<=90 && (int)input[i]>=65)
                    {
                        y = input[i]-'A';
                        y = (a*(y-b))%26;
                        (y<0)? y+=26:y;
                        decryption += (char)( y + 65);
                    }
                    else if ((int)input[i]<=122 && (int)input[i]>=97)
                    {
                        y = input[i]-'a';
                        y = (a*(y-b))%26; //insxchmrwbglqvafkpuzejotyd
                        (y<0)? y+=26:y;
                        decryption += (char)( y + 97);
                    }
                    else
                    {
                        decryption += input[i];
                    }
                }
                cout<<"Your decrypted message is "<<'"'<<decryption<<'"'<<'\n';
                break;
            case 3:
                return 0;
            default :
                cout<<"Invalid Input"<<endl;
                main();
            }
        }

    }
    
    else if (cipher_number == "1")
    {
        while (true)
        {
            string array = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

            cout << "hello my dear user ! \n"<<"what do you like to do today ? \n";
            cout <<"1-cipher text \n"<<"2-decipher text \n"<<"3-End "<<endl;

            int q = 0;
            cin >> q ;
            if (q == 1)
            {
                cout << "what is the number of shifts you want ? (maximum 25 shifts)  "<<endl;
                int x ;
                cin >> x ;
                while (x>25 || x<0)
                {

                    cout<<"error ! "<<endl;
                    cout << "what is the number of shifts you want ? (maximum 25 shifts)  "<<endl;
                    int x ;
                    cin >> x ;

                }
                cin.ignore();
                string message ;
                cout <<"enter the text you wanna cipher "<<endl;
                getline(cin,message);
                int (y) = 0 ;
                int i = 0 ;
                int c ;
                while (i<53 )
                {
                    c=(int)message[y];
                    if (int(message[y])==32)
                    {
                        y++;
                        i=0;
                    }
                    else if (c <65 || (c <96 && c >90) ||c >122)
                    {
                        y++;
                        i=0;
                    }
                    else if (message[y]== array[i] )
                    {

                        if (((i+x)>25)&& i<26)
                        {
                            message[y]=array[(i+x)-26];
                            i=0;
                            y+=1;
                        }
                        else if (((i+x)<=25)&& i<26)
                        {
                            message[y]=array[i+x];
                            y+=1;
                            i=0;
                        }
                        else if(((i+x)>52)&& i>=26)
                        {
                            message[y]=array[(i+x)-26];
                            i=0;
                            y+=1;
                        }
                        else if (((i+x)<=52)&& i>=26)
                        {
                            message[y]=array[i+x];
                            y+=1;
                            i=0;

                        }
                    }
                    else

                    {
                        i++;
                    }

                }
                cout << message <<endl<<endl;

            }
            else if (q==2)
            {
                cout << "what is the number of shifts you did ? (maximum 25 shifts) "<<endl;
                int x ;
                cin >> x ;
                while (x>25 || x<0)
                {

                    cout<<"error ! "<<endl;
                    cout << "what is the number of shifts you did ? (maximum 25 shifts)  "<<endl;
                    int x ;
                    cin >> x ;
                }
                cin.ignore();
                string message ;
                cout <<"enter the text you wanna decipher "<<endl;
                getline(cin,message);
                int (y) = 0 ;
                int i = 0 ;
                int c ;
                while (i<53)
                {
                    c= (int)message[y];
                    if (c <65 || (c <96 && c >90) ||c >122)
                    {
                        y++;
                        i=0;

                    }
                    else if (int(message[y])==32)
                    {
                        y++;
                        i=0;

                    }
                    else if (message[y]== array[i])
                    {
                        if ((i-x)>=0 && i < 26)
                        {
                            message[y]=array[(i-x)];
                            i=0;
                            y+=1;
                        }
                        else if ((i-x)<0 && i < 26)
                        {
                            message[y]=array[26+(i-x)];
                            y+=1;
                            i=0;
                        }
                        else if ((i-x)<26 && i >= 26)
                        {
                            message[y]=array[26+(i-x)];
                            y+=1;
                            i=0;
                        }
                        else if ((i-x)>=26 && i >= 26)
                        {
                            message[y]=array[(i-x)];
                            i=0;
                            y+=1;

                        }
                    }
                    else
                    {
                        i++;
                    }

                }

                cout << message <<endl<<endl;
            }
            else if (q==3)
            {
                break;
            }
            else
            {
                cout<<"ERROR"<<endl;

            }

        }

    }
    else if (cipher_number == "2")
    {

        while (true)
        {
            string array = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
            cout << "hello my dear user ! \n"<<"what do you like to do today ? \n";
            cout <<"1-cipher text \n"<<"2-decipher text \n"<<"3-End "<<endl;

            int q = 0;
            cin >> q ;
            if (q == 1)
            {

                cin.ignore();
                string message ;
                cout <<"enter the text you wanna cipher "<<endl;
                getline(cin,message);
                int (y) = 0 ;
                int i = 0 ;
                int c ;
                while (i<53 )
                {
                    if (message[y]== array[i] )
                    {
                        if (i<26)
                        {
                            message[y]=array[25-i];
                            i=0;
                            y++;
                        }
                        else
                        {
                            message[y]=array[25+(52-i)];
                            i=0;
                            y++;
                        }
                    }
                    else if ((int)message[y] ==32)
                    {
                        y++;
                        i=0;
                    }
                    else

                    {
                        i++;
                    }

                }
                cout << message <<endl<<endl;

            }
            else if (q==2)
            {

                cin.ignore();
                string message ;
                cout <<"enter the text you wanna decipher "<<endl;
                getline(cin,message);
                int (y) = 0 ;
                int i = 0 ;
                int c ;
                while (i<53)
                {
                    if (message[y]== array[i])
                    {
                        if (i<26)
                        {
                            message[y]=array[25-i];
                            i=0;
                            y++;
                        }
                        else
                        {
                            message[y]=array[25+(52-i)];
                            i=0;
                            y++;
                        }
                    }
                    else if (int(message[y])==32)
                    {
                        y++;
                        i=0;

                    }
                    else
                    {
                        i++;
                    }

                }

                cout << message <<endl<<endl;
            }
            else if (q==3)
            {
                break;
            }
            else
            {
                cout<<"ERROR"<<endl;

            }

        }
    }
        else if (cipher_number == "3")
        {
            while (true)
    {
        string array = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
        cout << "hello my dear user ! \n"<<"what do you like to do today ? \n";
        cout <<"1-cipher text \n"<<"2-decipher text \n"<<"3-End "<<endl;

        int q = 0;
        cin >> q ;
        if (q == 1)
        {

            cin.ignore();
            string message ;
            cout <<"enter the text you wanna cipher "<<endl;
            getline(cin,message);
            int (y) = 0 ;
            int i = 0 ;
            int c ;
            while (i<53 )
            {
            if ((int)message[y] ==32)
                {
                    y++;
                    i=0;
                }
                else if (message[y]== array[i] )
                {
                    if (i<13 || (i>=26 && i<39)){
                        message[y]=array[13+i];
                        i=0;
                        y++;
                    }else if (i>=13 && i<26) {
                        message[y]=array[13-(26-i)];
                        i=0;
                        y++;
                    }else if (i>=39){
                        message[y]=array[39-(52-i)];
                        i=0;
                        y++;
                    }
                }
                else

                {
                    i++;
                }

            }cout << message <<endl<<endl;

        }
        else if (q==2)
        {

            cin.ignore();
            string message ;
            cout <<"enter the text you wanna decipher "<<endl;
            getline(cin,message);
            int (y) = 0 ;
            int i = 0 ;
            int c ;
            while (i<53)
            {
            if (int(message[y])==32)
                {
                    y++;
                    i=0;

                } else if (message[y]== array[i] )
                {
                    if (i<13 || (i>=26 && i<39)){
                        message[y]=array[13+i];
                        i=0;
                        y++;
                    }else if (i>=13 && i<26) {
                        message[y]=array[13-(26-i)];
                        i=0;
                        y++;
                    }else if (i>=39){
                        message[y]=array[39-(52-i)];
                        i=0;
                        y++;
                    }
                }
                else
                {
                    i++;
                }

            }

            cout << message <<endl<<endl;
        }
        else if (q==3)
        {
            break;
        }
        else
        {
            cout<<"ERROR"<<endl;

        }

}



        }
        else if (cipher_number == "4")
        {
            cout <<"Ahlan ya user ua habibi. \n";
            int choosenumber ;
            cout <<"What do you like to do today? \n";
            cout <<"1- Cipher a message \n";
            cout <<"2- Decipher a message \n";
            cout <<"3- End \n";
            cin >> choosenumber ;
            if (choosenumber == 1 )
            {
                string message ;
                cout <<"Please enter the message to cipher: " ;
                cin.ignore();
                getline(cin, message);
                string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
                string cipher[54] = {"aaaaa","aaaab","aaaba","aaabb","aabaa","aabab","aabba","aabbb","abaaa","abaab","ababa","ababb","abbaa","abbab","abbba","abbbb","baaaa","","baaab","baaba","baabb","babaa","babab","babba","babbb","bbaaa","bbaab","aaaaa","aaaab","aaaba","aaabb","aabaa","aabab","aabba","aabbb","abaaa","abaab","ababa","ababb","abbaa","abbab","abbba","abbbb","baaaa","","baaab","baaba","baabb","babaa","babab","babba","babbb","bbaaa","bbaab"};
                for (int  i = 0 ; i < message.length() ; i++)
                {
                    for (int j=0 ; j< 54; j++)
                    {
                        if (message[i] == alphabet[j])
                        {
                            cout << cipher[j];
                        }
                        if (message[i] == ' ')
                        {
                            cout <<" ";
                            break;
                        }

                    }
                }
            }
            else if (choosenumber == 2 )
            {
                string cipher [800];
                cout << "before you enter your code follow this example \n(input :aaaaa aaaaa aaaaa , aaaaa aaaaa aaaaa ) \n\t(output :AAA AAA) \n";
                cout<<"Please enter the message to decipher : ";
                for (int i = 0 ; i < 1000 ;  i++)
                {
                    cin>>cipher[i];
                    if (cipher[i] == "aaaaa")
                        cout << "A";
                    else if (cipher[i] == "," )
                        cout << "  ";             // 2 _space if the user Enter the ,
                    else if (cipher[i] == "aaaab" )
                        cout << "B";
                    else if (cipher[i] == "aaaba")
                        cout <<"C";
                    else if (cipher[i] == "aaabb" )
                        cout << "D";
                    else if (cipher[i] == "aabaa" )
                        cout << "E";
                    else if (cipher[i] == "aabab")
                        cout <<"F";
                    else if (cipher[i] == "aabba")
                        cout <<"G";
                    else if (cipher[i] == "aabbb" )
                        cout << "H";
                    else if (cipher[i] == "abaaa")
                        cout <<"I";
                    else if (cipher[i] == "abaab" )
                        cout << "J";
                    else if (cipher[i] == "ababa" )
                        cout << "K";
                    else if (cipher[i] == "ababb")
                        cout <<"L";
                    else if (cipher[i] == "abbaa")
                        cout <<"M";
                    else if (cipher[i] == "abbab" )
                        cout << "N";
                    else if (cipher[i] == "abbba")
                        cout <<"O";
                    else if (cipher[i] == "abbbb" )
                        cout << "P";
                    else if (cipher[i] == "baaaa" )
                        cout << "Q";
                    else if (cipher[i] == "baaab")
                        cout <<"R";
                    else if (cipher[i] == "baaba")
                        cout <<"S";
                    else if (cipher[i] == "baabb" )
                        cout << "T";
                    else if (cipher[i] == "babaa")
                        cout <<"U";
                    else if (cipher[i] == "babab" )
                        cout << "V";
                    else if (cipher[i] == "babba" )
                        cout << "W";
                    else if (cipher[i] == "babbb")
                        cout <<"X";
                    else if (cipher[i] == "bbaaa")
                        cout <<"Y";
                    else if (cipher[i] == "bbaab")
                        cout << "Z";

                }

            }


        }
        else if (cipher_number == "5")
        {
           
    cout <<"Ahlan ya user ua habibi. \n";
    string choosenumber ;
    cout <<"What do you like to do today? \n";
    cout <<"1- Cipher a message \n";
    cout <<"2- Decipher a message \n";
    cout <<"3- End \n";
    cin >> choosenumber ;
        if (choosenumber == "1")
		{

        string name;
        string arrayofchar_1="abcdefghijklmnopqrstuvwxyz";
        char arrayOfletters[]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        string key, arr[26];
        cout<<"Enter Your Key : ";
        cin>>key;
        cout<<"Please Enter The Message To Cipher : ";
        cin.ignore();
        getline(cin,name);
        int number=0;
        for(int i=0; i<5 ; i++)   // loop for key char in empty array (arr)
        {
            arr[i]=key[i];
        }
        for(int s=0 ; s<5 ; s++)   // loop for key
        {
            for(int j=0; j<26 ; j++)   // loop for array
            {
                if(key[s]==arrayOfletters[j])
                {
                    arrayOfletters[j]='#';
                }
            }
        }
        for(int i=5; i<26 ; i++)  // loop to compare the key char with arrayofletter char
        {
            if(arrayOfletters[number]!='#')
                arr[i]=arrayOfletters[number];
            else
                i--;
            number++;
        }
        for(int i=0 ; i<name.size() ; i++)  // loop on the input
        {
            for(int j=0 ; j<26 ; j++)  // loop in arrayofletter
            {
                if(name[i]==arrayofchar_1[j])
                {
                    cout<<arr[j]; // print the cipher chars this's found in empty array
                }
            }
            if (name[i]==' ')
            {
                cout<<" ";
            }
        }



	}
if (choosenumber == "2")
		{
        string name;
        string arrayofchar_1="abcdefghijklmnopqrstuvwxyz";
        char arrayOfletters[]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        string key;
        char arr[26];
        cout<<"Enter Your key : ";
        cin>>key;
        cout<<"please enter the cipher to decipher : ";
        cin.ignore();
        getline(cin,name);
        int number=0;
        for(int i=0; i<5 ; i++)     // loop for key char in empty array (arr)
        {
            arr[i]=key[i];
        }
        for(int s=0 ; s<5 ; s++)    // loop for key
        {
            for(int j=0; j<26 ; j++)     // loop for array
            {
                if(key[s]==arrayOfletters[j])
                {
                    arrayOfletters[j]='#';
                }
            }
        }
        for(int i=5; i<26 ; i++)
        {
            if(arrayOfletters[number]!='#')
                arr[i]=arrayOfletters[number];
            else
                i--;
            number++;
        }
        for(int i=0 ; i<name.size() ; i++)  // loop on the input
        {
            for(int j=0; j<26 ; j++)    // loop in arrayofletter
            {
                if (arr[j]==name[i])
                {
                    cout<<arrayofchar_1[j];     // print the cipher chars this's found in array of letter
                }
            }
            if(name[i]==' ')
            {
                cout<<" ";
            }
        }


	}

    }
        else if (cipher_number == "6")
        {

            cout <<"Ahlan ya user ua habibi. \n";
            int choosenumber ;
            cout <<"What do you like to do today? \n";
            cout <<"1- Cipher a message  \n "<<"2- Decipher a message \n"<<"3- End \n";
            cin >> choosenumber ;
            if (choosenumber == 1 )
            {
                int choise;
                cout << "if you want the 1 2 3 4 5 cipher press 1 \n ";
                cout << "if you want 5 4 3 2 1 cipher press 2  \n";
                cout <<"Enter your choise here : ";
                cin >> choise ;
                if (choise == 1)
                {
                    cout <<"you in 1 2 3 4 5  cipher ";
                    string massage ;
                    cout <<"Please enter your message : " ;
                    cin.ignore();
                    getline(cin, massage);
                    string  arrayofchar = "abcdefghijklmnopqrstuvxyz";
                    string  arrayofcipher[26] = {"11","12","13","14","15","21","22","23","24","25","31","32","33","34","35","41","42","43","44","45","51","52","53","54","55"};
                    for (int  i = 0 ; i < massage.length() ; i++)
                    {
                        for (int j=0 ; j < 27; j++)
                        {
                            if (massage[i] == arrayofchar[j])
                            {
                                cout << arrayofcipher[j];
                            }
                            if (massage[i] == ' ')
                            {
                                cout <<"      ";
                                break;
                            }

                        }
                    }
                }
                else if (choise == 2 )
                {
                    cout <<"you in 5 4 3 2 1 cipher ";
                    string massage ;
                    cout <<"Please enter your message : " ;
                    cin.ignore();
                    getline(cin, massage);
                    string  arrayofchar = "abcdefghijklmnopqrstuvxyz";
                    string  arrayofcipher[26] = {"55","51","54","52","53","15","11","14","12","13","45","41","44","42","43","25","21","24","22","23","35","31","34","32","33"};
                    for (int  i = 0 ; i < massage.size() ; i++)
                    {
                        for (int j=0 ; j < 27; j++)
                        {
                            if (massage[i] == arrayofchar[j])
                            {
                                cout << arrayofcipher[j];
                            }
                            if (massage[i] == ' ')
                            {
                                cout <<"      ";
                                break;
                            }

                        }
                    }
                }
            }




            else if (choosenumber == 2)
            {

                int choise;
                cout << "if you want the 1 2 3 4 5 Decipher press 1 \n ";
                cout << "if you want 5 4 3 2 1 Decipher press 2  \n";
                cout <<"Enter your choise here : ";
                cin >> choise ;
                if (choise == 1)
                {

                    string cipher[800] ;
                    cout << "before you enter your code follow this exzmple \n(input :11 11 11 , 11 11 11 ) \n\t(output :aaa aaa) \n";

                    cout <<"Enter your cipher : ";
                    for ( int i = 0 ; i < 1000 ; i++)
                    {
                        cin>>cipher[i];
                        if (cipher[i] == "11")
                            cout << "a";
                        else if (cipher[i] =="12" )
                            cout << "b";
                        else if (cipher[i] == "13")
                            cout <<"c";
                        else if (cipher[i] == "14" )
                            cout << "d";
                        else if (cipher[i] == "15" )
                            cout << "e";
                        else if (cipher[i] == "21")
                            cout <<"f";
                        else if (cipher[i] == "22")
                            cout <<"g";
                        else if (cipher[i] == "23" )
                            cout << "h";
                        else if (cipher[i] == "24")
                            cout <<"i";
                        else if (cipher[i] == "25" )
                            cout << "j";
                        else if (cipher[i] == "31" )
                            cout << "k";
                        else if (cipher[i] == "32")
                            cout <<"l";
                        else if (cipher[i] == "33")
                            cout <<"m";
                        else if (cipher[i] == "34" )
                            cout << "n";
                        else if (cipher[i] == "35")
                            cout <<"o";
                        else if (cipher[i] == "41" )
                            cout << "p";
                        else if (cipher[i] == "42" )
                            cout << "q";
                        else if (cipher[i] == "43")
                            cout <<"r";
                        else if (cipher[i] == "44")
                            cout <<"s";
                        else if (cipher[i] == "45" )
                            cout << "t";
                        else if (cipher[i] == "51")
                            cout <<"u";
                        else if (cipher[i] == "52" )
                            cout << "v";
                        else if (cipher[i] == "53")
                            cout <<"x";
                        else if (cipher[i] == "54")
                            cout <<"y";
                        else if (cipher[i] == "55")
                            cout << "z";
                        else if (cipher[i]== ",")
                            cout <<"   ";
                    }
                }
                else if (choise == 2 )
                {

                    cout <<"you in 5 4 3 2 1 cipher ";
                    string massage ;
                    cout <<"Please enter your message : " ;
                    string cipher[800] ;
                    cout << "before you enter your code follow this exzmple \n(input :55 55 55 , 55 55 55 ) \n\t(output :aaa aaa) \n";

                    cout <<"Enter your cipher : ";
                    for ( int i = 0 ; i < 1000 ; i++)
                    {

                        cin>>cipher[i];
                        if (cipher[i] == "55")
                            cout << "a";
                        else if (cipher[i] =="51" )
                            cout << "b";
                        else if (cipher[i] == "54")
                            cout <<"c";
                        else if (cipher[i] == "52" )
                            cout << "d";
                        else if (cipher[i] == "53" )
                            cout << "e";
                        else if (cipher[i] == "15")
                            cout <<"f";
                        else if (cipher[i] == "11")
                            cout <<"g";
                        else if (cipher[i] == "14" )
                            cout << "h";
                        else if (cipher[i] == "12")
                            cout <<"i";
                        else if (cipher[i] == "13" )
                            cout << "j";
                        else if (cipher[i] == "45" )
                            cout << "k";
                        else if (cipher[i] == "41")
                            cout <<"l";
                        else if (cipher[i] == "44")
                            cout <<"m";
                        else if (cipher[i] == "42" )
                            cout << "n";
                        else if (cipher[i] == "43")
                            cout <<"o";
                        else if (cipher[i] == "25" )
                            cout << "p";
                        else if (cipher[i] == "21" )
                            cout << "q";
                        else if (cipher[i] == "24")
                            cout <<"r";
                        else if (cipher[i] == "22")
                            cout <<"s";
                        else if (cipher[i] == "23" )
                            cout << "t";
                        else if (cipher[i] == "35")
                            cout <<"u";
                        else if (cipher[i] == "31" )
                            cout << "v";
                        else if (cipher[i] == "34")

                            cout <<"x";
                        else if (cipher[i] == "32")
                            cout <<"y";
                        else if (cipher[i] == "33")
                            cout << "z";
                        else if (cipher[i]== ",")
                            cout <<"   ";
                    }
                }
            }

        }
        else if (cipher_number == "7")
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
		 	cout << "Enter any key to repeat the choise :";
		 	cin >> choosenumber ; 
		 		
		}
		



}

        }
        else if (cipher_number == "8")
        {
             while (true)
    	{
        cout << "hello my dear user ! \n"<<"what do you like to do today ? \n";
        cout <<"1-cipher text \n"<<"2-decipher text \n"<<"3-End "<<endl;

        int q = 0;
        cin >> q ;
        if (q==1 || q==2)
        {
            cin.ignore();
            string encryption;
            string text;
            char input;
            cout <<"enter the text "<<endl;
            cin.ignore();
            getline(cin,text);
            cout<<"enter the secret letter ! "<<endl;
            cin>>input;
            for (int i=0; i<text.length(); i++)
            {
                    encryption+=(char)((int)text[i]^(int)input);
               }
        cout <<encryption<<endl;


        }
		else if (q==3)
		{
        break;
        }else {
        cout<<"error! "<<endl;
        break; 
        }
    	}


        }
        else if (cipher_number == "9")
        {
            cout <<"Ahlan ya user ua habibi. \n";
    string x;
    cout <<"What do you like to do today? \n";
    cout <<"1- Cipher a message \n";
    cout <<"2- Decipher a message \n";
    cout <<"3- End \n";
    cin>>x;
    if(x=="1")
    {
        string msg;
        int key;
        cout<<"enter your message\n";
        cin.ignore();
        getline(cin,msg);
        cout<<"enter key\n";
        cin>>key;
        int i,j,k=-1,row=0,col=0;
        int len=msg.size();
        char mat[key][len];
        for(i=0; i<key; i++)
            for(j=0; j<len; j++)
                mat[i][j]='\n';
        for(i=0; i<len; i++)
        {
            mat[row][col++]=msg[i];
            if(row==0||row==key-1)
                k=k*(-1);
            row=row+k;
        }
        cout<<"\n encrypted message : ";
        for(i=0; i<key; i++)
            for(j=0; j<len; j++)
                if(mat[i][j] != '\n')
                    cout<<mat[i][j];
    }
    else if(x=="2")
    {
        string enmsg;
        int key;
        int i,j,k=-1,row=0,col=0,s=0;
        cout<<"enter your encrypted message\n";
        cin.ignore();
        getline(cin,enmsg);
        cout<<"enter key\n";
        cin>>key;
        int len=enmsg.size();
        char mat[key][len];
        for(i=0; i<key; i++)
            for(j=0; j<len; j++)
                mat[i][j]='\n';
        for(i=0; i<len; i++)
        {
            mat[row][col++]='#';
            if(row==0||row==key-1)
                k=k*(-1);
            row=row+k;

        }
        for(i=0; i<key; i++)
            for(j=0; j<len; j++)
                if(mat[i][j]=='#')
                    mat[i][j]=enmsg[s++];
        row = col = 0;
        k = -1;

        cout<<"\n decrypted message is : ";
        for(i=0; i<len; i++)
        {
            cout<<mat[row][col++];
            if(row==0||row==key-1)
                k=k*(-1);
            row=row+k;
        }
    }
    

	}
	else if (cipher_number=="10") 
    {
		cout << "Bye Bye User \n\n\n";
    	break;
	}


}
		

        return 0;
    }
