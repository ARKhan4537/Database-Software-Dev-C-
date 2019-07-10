#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <stdexcept>
#include <string>
#include <windows.h>



using namespace std;



void mainpanel();
void loginpanel();
int main()
{

system("Title Database Software :: Programmer:: ARxshadow");
loginpanel();
return 0;	

}



void loginpanel()
{
	
FILE *loginFile;

struct employ 
    {
	 char Load_Pass[50];
	};

	char login1[50];
	char App_Password[50];
	char CreatePassword[50] ,confirm_Password[50];
	long int recsizelogin;
	struct employ e;
	recsizelogin = sizeof(e);
	
	loginFile=fopen("login","rb+");  //binary read/write files
    system("attrib +h +s login");
    if (loginFile == NULL)
    {
        loginFile = fopen("login","wb+");                 //rule defining for Creating Files 

        if (loginFile==NULL)
        {
        	
        	
            puts("Cannot open file");            //puts dispaly name on screen
            
			      
        }
    }

 fseek(loginFile, 0, SEEK_END);
 if (ftell(loginFile) == 0) 
 {
     // file is empty...
     
     
     cout<<"File is Empty, So Create your Password"<<endl;
     
     cout<<endl;
     
        cout<<"\n\n ===Create Password ===:"<<endl;
        cout<<"\n\n";
        cout<<"Enter New Password:";
        cin>>CreatePassword;
        cout<<"Confirm New Password:";
        cin>>confirm_Password;
        
        if (strcmp(CreatePassword,confirm_Password) == 0)
		{
			for(int i = 0; (i < 100 && CreatePassword[i] != '\0'); i++)
            CreatePassword[i] = CreatePassword[i] + 2;            //the key for encryption is 3 that is added to ASCII value
        
            cout<<CreatePassword<<endl;
			                                            //save new string in file
			fseek(loginFile, - recsizelogin, SEEK_CUR);          //replace text string using seek_cur 
            fwrite(CreatePassword,recsizelogin,1,loginFile);          //save new string in file
		
		}
		else
		{
			cout<<"Password Did Not Match";
		}
         
 } 
 
 else
  {
     	
            cout << "=== Database Login Panel ===";
            cout << "\n";
            rewind(loginFile);
            //cout<<"Enter your login Password:";
            //cin>>login1;
            cout<<"Please Wait...until input Option is dispaly on screen";
            cout<<endl;
            
             system("call starik.bat");
                   
             char pass[50];
             ifstream file("stpassword");
             if(!file)
	         {
     	     cout<<"Error in opening file";
     	     exit(1);
	         }
	         while(!file.eof())
	         {
	 	     file>>pass;
	
        	 }
	         file.close();
            
            
            while (fread(CreatePassword,recsizelogin,1,loginFile) == 1)              //Read string from a file and store into a variable e with loop
            {			                                                             //use as input stream/output streem        
			for(int i = 0; (i < 100 && CreatePassword[i] != '\0'); i++)
            CreatePassword[i] = CreatePassword[i] - 2;                               //the key for encryption is 3 that is subtracted to ASCII value
				        
	  
			if (strcmp(pass , CreatePassword) == 0)        
				{
				  cout<<"correct";
				  mainpanel();	
				}                 
				else
				{
				cout<<endl;
				cout<<endl;
				cout<<"Password not Correct...";
				cout<<endl;
				cout<<endl;
				system("pause");
				system("cls");
				loginpanel();
				}                  
            }
            cout << "\n\n";
 	
 }
}
 void mainpanel()
 {                            //start mainpanel
 	
  	FILE *fp, *ft, *login;              //Creating Communication Between File And Program using pointer
    char another, choice,back;


    struct student
    {
        char Url_Website[50], Email_Address[50], Password[50];   //set 1	
    };

    
    char App_password[50] , Cn_App_password[50];                  //set 2   
	char login1[50];   

    struct student e;         //call stucture from e
    char ARxUrl_Website[50], ARxEmail_Address[50], ARxPassword[50];        //Created Group 
    long int recsize;


    fp=fopen("Database","rb+");  //binary read/write files
    system("attrib +h +s Database");
    if (fp == NULL)
    {
        fp = fopen("Database","wb+");                 //rule defining for Creating Files 

        if (fp==NULL)
        {
            puts("Cannot open file");            //puts dispaly name on screen
            
        }
    }
    
	login=fopen("login","rb+");  //binary read/write files
      
      system("attrib +h +s login");
      
    if(login == NULL)
    {
        login = fopen("login","wb+");                 //rule defining for Creating Files 

        if (login==NULL)
        {
            puts("Cannot open file");               //puts dispaly name on screen        
        }

    }

    recsize = sizeof(e);  //Operator.. Define the size of array
       	while(1)
    {
    	
        system("cls");
        system("color a9");       
        cout << "\t\t========Password Manager System By ARxshadow=========";
        cout << "\n\n";
        cout << "\n\n";
        cout << "\n \t\t Press 1 For  Add       Record";
        cout<<endl;
        cout << "\n \t\t Press 2 For  List      Record";
        cout<<endl;
        cout << "\n \t\t Press 3 For  Modify    Record";
        cout<<endl;
        cout << "\n \t\t Press 4 For  Delete    Record";
        cout<<endl;
        cout << "\n \t\t Press 5 For  Create    New Login Password";
        cout<<endl;
        cout <<"\n  \t\t Press 6 For  Security  Layer";
        cout<<endl;
        cout << "\n \t\t Press 7 For  Exit      Program";
        cout<<endl;
        cout << "\n\n";
        cout << "\t\t Select Your Choice: ";
        fflush(stdin);       //Force Program show msg rather then more output will be generated.
        choice = getche();   //pause the screen For Input
        switch(choice)
        {
        case '1' :
            fseek(fp,0,SEEK_END);  //Set position of pointer to Write strings in output.txt From End of the file.  
            another ='Y';
            char back;
            while(another == 'Y' || another == 'y')
            {
                system("cls");
                cout<< "Enter the Website Name/Url :";
                cin >> e.Url_Website;
                
                
                for(int i = 0; (i < 100 && e.Url_Website[i] != '\0'); i++)
                e.Url_Website[i] = e.Url_Website[i] + 2;
                
                
                cout<<"Enter  the Email Id:";
                cin>>  e.Email_Address;
                
                for(int i = 0; (i < 100 && e.Email_Address[i] != '\0'); i++)
                e.Email_Address[i] = e.Email_Address[i] + 2;
                
                cout<< "Enter the Password:";
                cin >> e.Password;
                
                for(int i = 0; (i < 100 && e.Password[i] != '\0'); i++)
                e.Password[i] = e.Password[i] + 2;
                
                
                fwrite(&e,recsize,1,fp);
                cout << "\n Add Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
        case '2':
            system("cls");
            rewind(fp);                //bring the file pointer at the beginning of file **show on screen**
            cout << "=== View the Records in the Database===";
            cout << "\n";
            while (fread(&e,recsize,1,fp) == 1)  //Read string from a file and store into a variable e with loop
            {
            	
            	 for(int i = 0; (i < 100 && e.Url_Website[i] != '\0'); i++)
                 e.Url_Website[i] = e.Url_Website[i] - 2;
                 cout<<"\n";
                 cout<<"\n" <<"Website Url: "<<e.Url_Website  <<endl;  //setw(10) use for space
                
                 for(int i = 0; (i < 100 && e.Email_Address[i] != '\0'); i++)
                 e.Email_Address[i] = e.Email_Address[i] - 2;
                
                 cout<<"\n" <<"Email   ID : "<<e.Email_Address<<endl;
                
                 for(int i = 0; (i < 100 && e.Password[i] != '\0'); i++)
                 e.Password[i] = e.Password[i] - 2;
                
                 cout<<"\n" <<"Password   : "<<e.Password;        //use as input stream/output streem
				                                                   
            }
            cout << "\n\n";
            system("pause");
            break;

        case '3' :
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout<< "\n Enter the Email ID : ";
                cin>>ARxEmail_Address;
                 
                for(int i = 0; (i < 100 && ARxEmail_Address[i] != '\0'); i++)
                ARxEmail_Address[i] = ARxEmail_Address[i] + 2;
                 
                 
                rewind(fp);
                while (fread(&e,recsize,1,fp) == 1)       //Read string from a file and store into a variable e with loop
                {
                	
                    if (strcmp(e.Email_Address , ARxEmail_Address) == 0)
                    {
                        cout<<"Enter new Website Url   : ";
                        cin >> e.Url_Website;
                        
                        for(int i = 0; (i < 100 && e.Url_Website[i] != '\0'); i++)
                        e.Url_Website[i] = e.Url_Website[i] + 2;
                        
                        cout<<"Enter new Email Address :";
                        cin>>e.Email_Address;
                        
                        for(int i = 0; (i < 100 && e.Email_Address[i] != '\0'); i++)
                        e.Email_Address[i] = e.Email_Address[i] + 2;
                        
                        cout<<"Enter new Password : ";
                        cin>>e.Password;
                        
                        for(int i = 0; (i < 100 && e.Password[i] != '\0'); i++)
                        e.Password[i] = e.Password[i] + 2;
                        
                        fseek(fp, - recsize, SEEK_CUR);   //replace text string using seek_cur 
                        fwrite(&e,recsize,1,fp);          //save new string in file
                        break;
                    }
                    else
                        cout<<"record not found";
                }
                cout << "\n Modify Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;


        case '4':
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout<< "\n Enter Email Address For delete Section : ";
                cin >> ARxEmail_Address;
                
                for(int i = 0; (i < 100 && ARxEmail_Address[i] != '\0'); i++)
                 ARxEmail_Address[i] = ARxEmail_Address[i] + 2;
                
                ft = fopen("temp.dat", "wb");
                rewind(fp);
                while (fread (&e, recsize,1,fp) == 1)
                
				

                    if (strcmp(e.Email_Address,ARxEmail_Address) != 0)    //strcmp Compare two strings .. are equal or mot
                    {
                        fwrite(&e,recsize,1,ft);
                    }
                    
                fclose(fp);
                fclose(ft);
                remove("users.txt");
                rename("temp.dat","users.txt");
                fp=fopen("users.txt","rb+");
                cout << "\n Delete Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
            
        case '5':
        system("cls");
        cout<<"\n\n ===Create New Login Password ===:"<<endl;
        cout<<"\n\n";
        cout<<"Enter New Password:";
        cin>>App_password;
        cout<<"Confirm New Password:";
        cin>>Cn_App_password;
        
        if (strcmp(App_password,Cn_App_password) == 0)
		{
			
			for(int i = 0; (i < 100 && App_password[i] != '\0'); i++)
            App_password[i] = App_password[i] + 2;            //the key for encryption is 3 that is added to ASCII value
     
			fseek(login, - recsize, SEEK_CUR);              //replace text string using seek_cur 
            fwrite(App_password,recsize,1,login);          //save new string in file
            cout<<" "<<endl;
            cout<<" "<<endl;
            cout<<" "<<endl;
            cout<<"Password Changed Successfuly..."<<endl;
            system("pause");
		
		}
		else
		{
			system("cls");
			cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<"Password Did Not Match...Write Again Please...!"<<endl;
			cout<<endl;
			cout<<endl;
			system("pause");
			
			
		}
            break;
        
        case '6':
        cout<<"...Security Layer Must Be Important For Security..."<<endl;
        cout<<" "<<endl;
        cout<<" "<<endl;
        system(" cacls Database /e /p everyone:n");
        system(" cacls login /e /p everyone:n");
        system(" cacls stpassword /e /p everyone:n");
        system("cls");
        cout<<""<<endl;
        cout<<""<<endl;
		cout<<"Security Layer Added Successfully...";
		cout<<""<<endl;
		cout<<""<<endl;
		system("pause");
			
        break;

        case '7':
            fclose(fp);
            cout << "\n\n";
            system("cls");
            cout << "\t\t   Thank You For Using this Software From ARxshadow"<<endl;
			cout<<   "\t\t   I Hope you will Use it Again. . ."<<endl;
            cout << "\n\n";
            exit(0);
        
    
       default:
       	system("color c7");
       	cout<<setw(10)<<"ARxshadow";
       }
   }
    system("pause");
    

 	
 }//end mainpanel
  		

