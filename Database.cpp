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
void LastPassword();
void History();
void FireWall(); 
int  main()
{


system("Title Database Software :: Programmer:: ARxshadow");
loginpanel();

return 0;	


}


void FireWall()
{ 
ifstream sourcefileAvr("Avr.bat");
   if (sourcefileAvr)   //File is Exist Or Not Starik.bat
	{
	
       system("start Avr.bat");	
	
    }
    else
	{
     
	 cout<<"Error..! System Cannot Found Avr.bat File...";
     system("pause");
     mainpanel();
	     	
	}

}



void LastPassword()
{
	
	ifstream sourcefileHistory("LastPassword.bat");
    if (sourcefileHistory)   //File is Exist Or Not Starik.bat
	{
	
	system("call LastPassword.bat");
	mainpanel();
    }
    
else
{
	
	 cout<<"Error...! System Cannot Found LastPassword.bat File...";
     system("pause");
     mainpanel();
	
}
}



void History()
{
	ifstream sourcefileHistory("History.bat");
    if (sourcefileHistory)   //File is Exist Or Not Starik.bat
	{
	
	system("call History.bat");	
	mainpanel();
	
    }

else
{
	
cout<<"Error...! System Cannot Found History.bat File...";
system("pause");
mainpanel();
	
}
}






void loginpanel()
{
	
FILE *loginFile, *WrongPassword;

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
            puts("Cannot be open file>> login");            //puts dispaly name on screen
     	      
        }
        
    }

    WrongPassword=fopen("WrongPassword","r");  //binary read/write files
    system("attrib +h +s WrongPassword");
    if (WrongPassword == NULL)
    {
    
	    WrongPassword = fopen("WrongPassword","w");                 //rule defining for Creating Files 
        if (WrongPassword==NULL)
        {   	
            puts("Cannot be open file>> WrongPassword");            //puts dispaly name on screen 	      
        }
	
	}


 fseek(loginFile, 0, SEEK_END);
 if (ftell(loginFile) == 0)      
 {
     // file is empty...
     system("cacls login /e /p everyone:f");
     system("cls");
     
     //cout<<"Password is Not Created , So Create your Database Password First"<<endl;
         cout<<endl;
         cout<<endl;
         cout<<endl;
         cout<<"\n\n === Create Password ===: "<<endl;
         cout<<"\n\n";
         system("break >login");
         system("cls");
		 //cout<<"Enter New Password:";
         //cin>>CreatePassword;
         //cout<<"Please Wait...until input Option is dispaly on screen";
         //cout<<endl;           
            ifstream sourcefile("CreatePasswordStarik.bat");
            if (sourcefile)   //File is Exist Or Not Starik.bat
			{
             system("call CreatePasswordStarik.bat");      
            // char CreatePassword[50];
             ifstream file("crpassword");
             if(!file)
	        {
     	     cout<<"Error in opening file";
     	     exit(1);
	        }
	         while(!file.eof())
	        {
	 	     file>>CreatePassword;
        	}
	         file.close();
    
    
    
            cout<<endl;
            cout<<endl;
            cout<<endl;
		    
			
			for(int i = 0; (i < 100 && CreatePassword[i] != '\0'); i++)
            CreatePassword[i] = CreatePassword[i] + 400;                      //the key for encryption is 3 that is added to ASCII value            			                                                                //save new string in file
			
			
			fseek(loginFile, - recsizelogin, SEEK_CUR);                     //replace text string using seek_cur 
            fwrite(CreatePassword,recsizelogin,1,loginFile);                //save new string in file
            cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<endl;
			cout<<"Password is Created Successfully..."<<endl;
			cout<<endl;
			cout<<endl;
			system("pause");
			system("cacls login /e /p everyone:n");
			system("cls");
			goto DatabaseLogin;        
}
else
{
	
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"System Cannot Found CreatePasswordStarik.bat...! Please Consult with Programmer...!";
	cout<<endl;
	cout<<endl;
	system("pause");
	exit(0);
}

        //cout<<"Confirm New Password:";
        //cin>>confirm_Password;
        //if (strcmp(CreatePassword,confirm_Password) == 0)
		//{
            
				 		
		
			
			
			//createPassword was not declear
					
		//}
		//else
		//{	
		//  cout<<endl;
		//	cout<<endl;
		//	cout<<endl;
		//	cout<<endl;
		//	cout<<endl;
		//	cout<<endl;
		//	cout<<"Password Did Not Match ...Write Again..."<<endl;
		//	cout<<endl;
		//	cout<<endl;
		//	system("pause");
		//}
         
 } 
 
 else
  {
  	
  	DatabaseLogin:
  	rewind(loginFile);
  	system("taskkill /f /t /im cmd.exe");
  	system(" cacls login /e /p everyone:f");
  	//system("taskkill /f /t /im Avr.bat");
    //system("taskkill /f /t /im Avr.vbs");
    
    system("cls");
            cout << "=== Database Login Panel ===";
            cout << "\n";
            //cout<<"Enter your login Password:";
            //cin>>login1;
            cout<<"Please Wait...until input Option is display on screen";
            cout<<endl;
            
            ifstream sourcefile("starik.bat");
            if (sourcefile)   //File is Exist Or Not Starik.bat
			{
             system("call starik.bat");      
             char pass[50];
             ifstream file("stpassword");
             if(!file)
	        {
	        	
     	     cout<<"Error in opening file";
     	     //exit(1);
	        
			}
	        
	         while(!file.eof())
	        {
	 	     file>>pass;
        	}
	         file.close();

            
            
            while (fread(CreatePassword,recsizelogin,1,loginFile) == 1)              //Read string from a file and store into a variable e with loop
            {			                                                             //use as input stream/output streem        
			for(int i = 0; (i < 100 && CreatePassword[i] != '\0'); i++)
            CreatePassword[i] = CreatePassword[i] - 400;                               //the key for encryption is 3 that is subtracted to ASCII value
				        
	  
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
			  //system("cacls login /e /p everyone:n");
			     
	        ifstream fileWrongPassword("WrongPassword.bat");
            if (fileWrongPassword)   //File is Exist Or Not Starik.bat
			{		     
			     system("call WrongPassword.bat");
		    }
		    else
			{
		    
			cout<<"Error..! System Cannot be found WrongPassword.bat ";
			exit(0);
			
			}
			     
			     
			//char wrongPassword1[50]; 
			//ifstream fileWrongPassword("stpassword");
            //if(!fileWrongPassword)
	        //{                                               
	        	                                                   
     	     //cout<<"Error in opening file";
     	     //exit(1);
	        
		//}
	        
	        
	      //   while(!fileWrongPassword.eof())
	        //{
	 	     //fileWrongPassword>>wrongPassword1;
        	//}
        	
        	
	        //fileWrongPassword.close();
			
			//fseek(WrongPassword, - recsizelogin, SEEK_CUR);          //replace text string using seek_cur 
            //fwrite(wrongPassword1,recsizelogin,1,WrongPassword);
				 
	        
			 	
				goto DatabaseLogin;
			
				
				}                  
            }
            cout << "\n\n";
}
else
{
	cout<<endl;
	cout<<endl;
	cout<<"Error...! File Starik.bat is not Found in the System "<<endl;
	cout<<"Please Contact to Programmer:>> ARxShadow"<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;
	system("pause");
}
}
}

 void mainpanel()
 {                            //start mainpanel

 	
  	FILE *fp, *ft, *login , *mailfile;              //Creating Communication Between File And Program using pointer
    char another, choice,back;


    struct student
    {
 
    	
        char  Url_Website[50], Email_Address[50], Password[50];   //set 1
		char  ID[50], RecoveryMail[50];

		
    };

    
    char        App_password[50] ,  Cn_App_password[50];                  //set 2   
	char        login1[50];         int Traceoption; 
    struct      student e;           //call stucture from e
    char        ARxUrl_Website[50], ARxEmail_Address[50], ARxPassword[50];
	char        ARxID[50];               //Created Group
	int         Backup;
	char        SetBackupEmail[50];
    long int    recsize;
    char        ARxRecoveryMail[50];
  //char        CreatePassword1[50];
    



    mailfile=fopen("mail","rb+");  //binary read/write files
    system("attrib +h +s mail");
    if (mailfile == NULL)
    {
        mailfile = fopen("mail","wb+");                 //rule defining for Creating Files 


        if (mailfile==NULL)
        {
            puts("Cannot be open file >> mail");            //puts dispaly name on screen
            
        }
        
                
    }

    
	
	
	
	fp=fopen("Database","rb+");  //binary read/write files
    system("attrib +h +s Database");
    if (fp == NULL)
    {
        fp = fopen("Database","wb+");                 //rule defining for Creating Files 
        if (fp==NULL)
        {
			puts("Cannot be open file >> Database");            //puts dispaly name on screen   
        }
    }
    
    
	login=fopen("login","rb+");  //binary read/write files
      
      system("attrib +h +s login");
      
    if(login == NULL)
    {
        login = fopen("login","wb+");                 //rule defining for Creating Files 

        if (login==NULL)
        {
            puts("Cannot be open file >> login");               //puts dispaly name on screen        
        }

    }

    recsize = sizeof(e);  //Operator.. Define the size of array
       	while(1)
    {
    	system("Title Database Software :: Programmer:: ARxshadow  Authorized PC:: %username%");
        system("cls");
        system("color a9");       
        cout <<"\t\t========Password Manager System By ARxshadow=========";
        cout <<"\n\n";
        cout <<"\n\n";
        cout <<"\n  \t\t Press 1 For  Add        Record";
        cout<<endl;
        cout <<"\n  \t\t Press 2 For  List       Record";
        cout<<endl;
        cout <<"\n  \t\t Press 3 For  Modify*    Record";
        cout<<endl;
        cout <<"\n  \t\t Press 4 For  Delete     Record";
        cout<<endl;
        cout<<"\n   \t\t Press 5 For  Search     Record";
        cout<<endl;
        cout <<"\n  \t\t Press 6 For  Create     New Login Password";
        cout<<endl;
        cout <<"\n  \t\t Press 7 For  Security   Layer";
        cout<<endl;
        cout <<"\n  \t\t Press 8 For  Backup     Mail Data";
        cout<<endl;
        cout <<"\n  \t\t Press 9 For  Exit";
        cout<<endl;
        cout <<"\n\n";
        cout <<"\t\t Select Your Choice: ";
        fflush(stdin);       //Force Program show msg rather then more output will be generated.
        choice = getche();   //pause the screen For Input
        switch(choice)
        {
        case '1' :
        	system("cacls Database /e /p everyone:f");
        	system("cls");
        	cout<<"===Add Records==="<<endl;
            fseek(fp,0,SEEK_END);  //Set position of pointer to Write strings in output.txt From End of the file.  
            another ='Y';
            
            while(another == 'Y' || another == 'y')
            {
             
			system("cls");
			
			ifstream SourceCount("starik.bat");
            if (SourceCount)   //File is Exist Or Not Starik.bat
			{    
			
			 system("if not exist count.bat echo Error...! System Cannot found count.bat");
			 system("attrib +h +s count.bat");
             system("call count.bat");
              
             ifstream file("CounterID");
             if(!file)
	         {
     	     cout<<"Error in opening file";
     	     exit(1);
	         }
	         while(!file.eof())
	         {
	 	     file>>e.ID;
        	 } 
        	 
	         file.close();
	         
             
			 cout<<"Your Record ID :"<<e.ID<<endl;
             cout<<endl;
             for(int i = 0; (i < 100 && e.ID[i] != '\0'); i++)
             e.ID[i] = e.ID[i] + 400;
             cout<<"\n";
			 cout<<endl;
             
                cout<<"Enter the Website Name/Url :";
                cin >>e.Url_Website;
                if (strcmp(e.Url_Website , "back") == 0)
                    
				{	
					system("cls");
			        mainpanel();	     
				}
				
			
                
                for(int i = 0; (i < 100 && e.Url_Website[i] != '\0'); i++)
                e.Url_Website[i] = e.Url_Website[i] + 400;
                
                
                cout<<"Enter  the Email Id:";
                cin>>  e.Email_Address;
                
                if(strcmp(e.Email_Address,"back")==0)
                {
                	system("cls");
                	mainpanel();
			    }
			    
                
				for(int i = 0; (i < 100 && e.Email_Address[i] != '\0'); i++)
                e.Email_Address[i] = e.Email_Address[i] + 400;
                
                
                
                cout<<"Enter the Password:";
                cin >> e.Password;
                 if(strcmp(e.Password,"back")==0)
				 {
                 	system("cls");
                 	mainpanel();
				 }
                 
                for(int i = 0; (i < 100 && e.Password[i] != '\0'); i++)
                e.Password[i] = e.Password[i] + 400;
                
                
                cout<<"Enter the Recovery Mail:";
                cin >>e.RecoveryMail;
                if (strcmp(e.RecoveryMail , "back") == 0)
                    
				{	
					system("cls");
			        mainpanel();	     
				}
				
				
                
                for(int i = 0; (i < 100 && e.RecoveryMail[i] != '\0'); i++)
                e.RecoveryMail[i] = e.RecoveryMail[i] + 400;
                
                fwrite(&e,recsize,1,fp);
                cout << "\n Add Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
                system(" cacls Database /e /p everyone:n");
                system("cls");
            
        }
        else
		{
			system("cls");
        	cout<<endl;
        	cout<<endl;
        	cout<<"Error..! System cannot be found file count.bat ... Please Contact Programmer :ARxshadow"<<endl;
        	cout<<endl;
        	cout<<endl;
        	system("pause");
        	
		}
            
            
        }
            
            break;
            
        case '2':
            system("cacls Database /e /p everyone:f");
            system("cls");
            rewind(fp);                           //bring the file pointer at the beginning of file **show on screen**
            cout << "=== View the Records===";
            cout << "\n";
            while (fread(&e,recsize,1,fp) == 1)  //Read string from a file and store into a variable e with loop
            {
            	cout<<endl;
            	
            	for(int i = 0; (i < 100 && e.ID[i] != '\0'); i++)
                 e.ID[i] = e.ID[i] - 400;
                 cout<<"\n";
            	
                 cout<<"Your Record Id Number:"<<e.ID<<endl;
				 	
                 cout<<"=========================================="<<endl;
            	 for(int i = 0; (i < 100 && e.Url_Website[i] != '\0'); i++)
                 e.Url_Website[i] = e.Url_Website[i] - 400;
                 cout<<"\n";
                 
				 cout<<"\n" <<"Website Url: "<<e.Url_Website  <<endl;  //setw(10) use for space
                
                 for(int i = 0; (i < 100 && e.Email_Address[i] != '\0'); i++)
                 e.Email_Address[i] = e.Email_Address[i] - 400;
                
                 cout<<"\n" <<"Email   ID : "<<e.Email_Address<<endl;
                
                 for(int i = 0; (i < 100 && e.Password[i] != '\0'); i++)
                 e.Password[i] = e.Password[i] - 400;
                 cout<<"\n" <<"Password   : "<<e.Password<<endl;        //use as input stream/output streem
                 cout<<endl;
                 
                 for(int i = 0; (i < 100 && e.RecoveryMail[i] != '\0'); i++)
                 e.RecoveryMail[i] = e.RecoveryMail[i] - 400;
                 cout<<"\n" <<"Recovery Mail   : "<<e.RecoveryMail<<endl;
                 cout<<endl;
                 cout<<"=========================================="<<endl;
                 cout<<endl;
				                                                   
            }
            cout << "\n\n";
            system("pause");
            system(" cacls Database /e /p everyone:n");
            system("cls");
            break;
            

        case '3' :
        	system(" cacls Database /e /p everyone:f");
            system("cls");
            cout<<"===Modify Record==="<<endl;
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout<< "\n Enter Record ID No# : ";
                cin>>ARxID;
             if (strcmp(ARxID , "back") == 0)
                    
				{
					
					system("cls");
                    mainpanel();	
                    
				}
				
					if (strcmp(ARxID , "History") == 0)
                    
				{	
					system("cls");
			        History();	     
				}
				
				if (strcmp(ARxID , "LastPassword") == 0)
                    
				{	
					system("cls");
			        LastPassword();	     
				}
				
				
                for(int i = 0; (i < 100 && ARxID[i] != '\0'); i++)
                ARxID[i] = ARxID[i] + 400;
                 
                 
                rewind(fp);
                while (fread(&e,recsize,1,fp) == 1)       //Read string from a file and store into a variable e with loop
                {
                	
                    if (strcmp(e.ID , ARxID) == 0)
                    {
                        cout<<"Enter new Website Url   : ";
                        cin >>e.Url_Website;
                       
                       if (strcmp(e.Url_Website , "back") == 0)
                    
				{
					
					system("cls");
                    mainpanel();	
                    
				}
					    
                        for(int i = 0; (i < 100 && e.Url_Website[i] != '\0'); i++)
                        e.Url_Website[i] = e.Url_Website[i] + 400;
                        
                        cout<<"Enter new Email Address :";
                        cin>>e.Email_Address;
                        if (strcmp(e.Email_Address , "back") == 0)
                    
				{
					
					system("cls");
                    mainpanel();	
                    
				}
                        
                        for(int i = 0; (i < 100 && e.Email_Address[i] != '\0'); i++)
                        e.Email_Address[i] = e.Email_Address[i] + 400;
                        
                        cout<<"Enter new Password : ";
                        cin>>e.Password;
                        if (strcmp(e.Password , "back") == 0)
                    
				{
					
					system("cls");
                    mainpanel();	
                    
				}
                        for(int i = 0; (i < 100 && e.Password[i] != '\0'); i++)
                        e.Password[i] = e.Password[i] + 400;
                        
                        
                        
                        
                        
                        cout<<"Enter New Recovery Mail : ";
                        cin>>e.RecoveryMail;
                        if (strcmp(e.RecoveryMail , "back") == 0)
                    
				{
					
					system("cls");
                    mainpanel();	
                    
				}
                        for(int i = 0; (i < 100 && e.RecoveryMail[i] != '\0'); i++)
                        e.RecoveryMail[i] = e.RecoveryMail[i] + 400;
                        
                        
                        
                        
                        
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
                system("cacls Database /e /p everyone:n");
                system("cls");
            }
            break;


        case '4':
        	system("cacls Database /e /p everyone:f");
            system("cls");
            cout<<"===Delete Record==="<<endl;
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout<< "\n Enter ID For delete Section : ";
                cin >> ARxID;
               
                if (strcmp(ARxID , "back") == 0)
                    
				{
					
					system("cls");
                    mainpanel();	
                    
				}
                
                
                 for(int i = 0; (i < 100 && ARxID[i] != '\0'); i++)
                 ARxID[i] = ARxID[i] + 400;
                
                 
                ft = fopen("temp.dat", "wb");
                rewind(fp);  
                while (fread (&e, recsize,1,fp) == 1)
                
				

                    if (strcmp(ARxID,e.ID) != 0)    //strcmp Compare two strings .. are equal or mot
                    {
                        fwrite(&e,recsize,1,ft);    
                    }
                    
                    cout<<endl;
                    cout<<endl;
                    cout<<endl;
                    for(int i = 0; (i < 100 && ARxID[i] != '\0'); i++)
                    ARxID[i] = ARxID[i] - 400;
                    cout<<endl;
                    cout<<endl;
                    cout<<endl;
                    cout<<endl;
                    cout<<"=================================================================================="<<endl;
                    cout<<endl;
                    cout<<"Record Deleted by ID:"<<setw(4)<<ARxID<<setw(4)<<"Successfully From Database";
                    cout<<endl;
                    cout<<"=================================================================================="<<endl;
                    cout<<endl;
                    cout<<endl;
                    
                fclose(fp);
                fclose(ft);
                remove("Database");
                rename("temp.dat","Database");
                fp=fopen("Database","rb+");
                cout << "\n Delete Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
                system("cacls Database /e /p everyone:n");
                system("cls");
            }
            
            
            break;
            
            
        case '5':
        system("cacls Database /e /p everyone:f");
        rewind(fp);
		system("cls");
		cout<<"\n\n ===Searching For specific Record View===:"<<endl;
		cout<<"\n\n";
		another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
            	
            	cout<<"Press 1 For Trace With ID: "<<endl;
            	cout<<endl;
            	cout<<"Press 2 For Trace With Email:"<<endl;
            	cout<<endl;
            	cout<<endl;
            	cout<<"select Option:";
            	cin>>Traceoption;
            	if(Traceoption==1)
				{
					
            	system("cls");
            	cout<<""<<endl;
            	cout<<""<<endl;
				cout<<"\n Enter the ID N0# For Trace :";
                cin>>ARxID;
                
                
                
                if (strcmp(ARxID , "back") == 0)
				{
					
					system("cls");
                    mainpanel();	
                    
				}
				
             
            while (fread(&e,recsize,1,fp) == 1)       //Read string from a file and store into a variable e with loop
            {
                	for(int i = 0; (i < 100 && ARxID[i] != '\0'); i++)
                         ARxID[i] = ARxID[i] + 400;
                    //if (e.ID == ARxID)
                    if (strcmp(e.ID , ARxID) == 0)
                    {
                    	
                    	 cout<<"============================================"<<endl;
                    	 for(int i = 0; (i < 100 && e.Url_Website[i] != '\0'); i++)
                         e.Url_Website[i] = e.Url_Website[i] - 400;
                    	
                         cout<<"Website Url    :"<<e.Url_Website<<endl;
                
					    
                         for(int i = 0; (i < 100 && e.Email_Address[i] != '\0'); i++)
                         e.Email_Address[i] = e.Email_Address[i] - 400;
                        
                         cout<<"Email Address  :"<<e.Email_Address<<endl;;
        
                        
                         for(int i = 0; (i < 100 && e.Password[i] != '\0'); i++)
                         e.Password[i] = e.Password[i] - 400;
                        
                         cout<<"Your Password  :"<<e.Password<<endl;
                         
                         for(int i = 0; (i < 100 && e.RecoveryMail[i] != '\0'); i++)
                         e.RecoveryMail[i] = e.RecoveryMail[i] - 400;
                        
                         cout<<"Your Recovery Mail  :"<<e.RecoveryMail<<endl;
                         
                         cout<<"============================================="<<endl;
                    
                         break;
                       }
                    }
                      cout<<"\n if you See Blank Screen while searching Record , Means Record Did Not Found"<<endl; 
				      cout<<"Search For Another Record (Y/N) ";
                      fflush(stdin);
                      another = getchar();
                      system("cls");
                      
                    
            	
			
				}
				
				else if(Traceoption==2)
				{
				system("cls");
				cout<<"\n Enter the Email ID For Trace :";
                cin>>ARxEmail_Address;
                 if(strcmp(ARxEmail_Address , "back") == 0)
                    
				{
					
					system("cls");
                    mainpanel();	
                    
				}
				
                for(int i = 0; (i < 100 && ARxEmail_Address[i] != '\0'); i++)
                ARxEmail_Address[i] = ARxEmail_Address[i] + 400;
                 
                 
                
                while (fread(&e,recsize,1,fp) == 1)       //Read string from a file and store into a variable e with loop
                {
                	
                    if (strcmp(e.Email_Address , ARxEmail_Address) == 0)
                    {
                    	
                    	cout<<"================================================="<<endl;
                    	 for(int i = 0; (i < 100 && e.Url_Website[i] != '\0'); i++)
                         e.Url_Website[i] = e.Url_Website[i] - 400;
                    	
                         cout<<"Website Url    :"<<e.Url_Website<<endl;
                
					    
                         for(int i = 0; (i < 100 && e.Email_Address[i] != '\0'); i++)
                         e.Email_Address[i] = e.Email_Address[i] - 400;
                        
                         cout<<"Email Address  :"<<e.Email_Address<<endl;;
        
                        
                         for(int i = 0; (i < 100 && e.Password[i] != '\0'); i++)
                         e.Password[i] = e.Password[i] - 400;
                        
                         cout<<"Your Password  :"<<e.Password<<endl;
                         
                         
                         for(int i = 0; (i < 100 && e.RecoveryMail[i] != '\0'); i++)
                         e.RecoveryMail[i] = e.RecoveryMail[i] - 400;
                        
                         cout<<"Your Recovery Mail  :"<<e.RecoveryMail<<endl;
                         
                         cout<<"==================================================="<<endl;
                         break;
                       }
                    }
                    
                      cout<<"\n if you See Blank Screen while searching Record ,Means Record Did Not Found"<<endl; 
				      cout<<"Search For Another Record (Y/N) ";
                      fflush(stdin);
                      another = getchar();
                      system("cls");
                      system(" cacls Database /e /p everyone:n");
                      
				}
				else
				{
					
					cout<<"You Choose illegal option Run Program Again.. "<<endl;
					cout<<endl;
					system("pause");
					system(" cacls Database /e /p everyone:n");
					system("cls");
					exit(0);
					
				}
                    }
                         
        break;
         	
         case '6':
        system("cacls Database /e /p everyone:f");
        system("cls");
        cout<<"\n\n ===Create New Login Password ===:"<<endl;
        cout<<"\n\n";
        
        cout<<"Enter New Password:";
        cin>>App_password;
        if (strcmp(App_password , "back") == 0)
                    
				{
					
					system("cls");
                    mainpanel();	
                    
				}
				
        cout<<"Confirm New Password:";
        cin>>Cn_App_password;
        if (strcmp(Cn_App_password , "back") == 0)
                    
				{
					
					system("cls");
                    mainpanel();	
                    
				}
				
        if (strcmp(App_password,Cn_App_password) == 0)
		{
			system("break >login");
			for(int i = 0; (i < 100 && App_password[i] != '\0'); i++)
            App_password[i] = App_password[i] + 400;            //the key for encryption is 3 that is added to ASCII value     
			fseek(login, - recsize, SEEK_CUR);                //replace text string using seek_cur 
            fwrite(App_password,recsize,1,login);             //save new string in file
            cout<<" "<<endl;
            cout<<" "<<endl;
            cout<<" "<<endl;
            cout<<"Password Changed Successfuly..."<<endl;
            cout<<endl;
            cout<<endl;
            system("pause");
            system("cacls Database /e /p everyone:n");
            system("cls");
            mainpanel();
		
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
        
        
        case '7':
        cout<<"...Security Layer Must Be Important For Securing Files..."<<endl;
        cout<<" "<<endl;
        cout<<" "<<endl;
        system("cacls Database /e /p everyone:n");
        system("cacls login /e /p everyone:n");
        system("cacls stpassword /e /p everyone:n");
        FireWall();
        system("cls");
        cout<<""<<endl;
        cout<<""<<endl;
		cout<<"...Security Layer Added Successfully...";
		cout<<""<<endl;
		cout<<""<<endl;
		system("pause");
		exit(0);
			
        break;

        case '8':
        system(" cacls Database /e /p everyone:f");
        system("cls");
        cout<<"==========Backup on Mail=============";
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"Please Wait...!"<<endl;
        system("if not exist mail.exe echo Error...! System Cannot be found mail.exe");
        system("attrib +h +s mail.exe");
        system("mail.exe -t  Email -f Email -ssl -port 465 -auth -smtp smtp.gmail.com -sub Database  -M BackupData -attach Database  -user hereemail -pass herePassword ");
        
		//fwrite(SetBackupEmail,recsize,1,mailfile);
        system("pause");
        	
        	break;


        case '9':
        	
        	
            fclose(fp);
            cout << "\n\n";
            system("cls");
            cout << "\t\t   Thank You For Using this Software From ARxshadow"<<endl;
			cout<<   "\t\t  I Hope you will Use it Again. . ."<<endl;
            cout << "\n\n";
            cout<<endl;
            cout<<endl;
            system("pause");
            system(" cacls Database /e /p everyone:n");
            system("cls");
            exit(0);
        
    
        default:
       	system("color c7");
       	cout<<setw(10)<<"ARxshadow";
   
       }
   
   }
   
    system("pause");

 }//end mainpanel //End Sub Class Of Software /// This is a Prototype of a software by Arxshadow 
