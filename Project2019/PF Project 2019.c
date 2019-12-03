#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
void fordelay(int x);           // Function Prototypes for the functions used in the Project 
void menu();                    // Main Menu
void bookm();                   // Book Menu
void add_books();                
void view_book();
void studentm();                // Student Menu
void add_student();
void view_student();
void update_status();
void issue_book();              // Issue Books
void return_book();             // Return Books
void searchm();                 // Search Menu
void searchbook();         
void searchstudent();
void inventory();               // Inventory
void notification();            // Notification
void back();
void back2();
void back3();
void back4();  
void close();                   // Endgame

struct book                     // Structure Definition
{
	char name[45];
	char aname[45];
	char cat[45];
	int code;
	int year;
}add,isu,ret,sea,check,*Ibad;
struct student
{
	char name[45];
	char roll[45];
	char status [45];
	int days;
}ad,is,up,se,chec,*Bruce;
int main()                       //Main Function
{
	system("color 0B");
	int main_exit;
    char pass[10],password[10]="Ibad";
    int i=0;
    printf("\n\n\t\tEnter the password to login:");
    scanf("%s",pass);
    if (strcmp(pass,password)==0)
        {printf("\n\nPassword Match!\nLOADING");
        for(i=0;i<=6;i++)
        {
            fordelay(100000000);
            printf(".");
        }
                system("cls");
            menu();
        }
    else
        {   printf("\n\nWrong password!!\a\a\a");
            login_try:
            printf("\nEnter 1 to try again and 0 to exit:");
            scanf("%d",&main_exit);
            if (main_exit==1)
                    {

                        system("cls");
                        main();
                    }

            else if (main_exit==0)
                    {
                    system("cls");
                    close();}
            else
                    {printf("\nInvalid!");
                    fordelay(1000000000);
                    system("cls");
                    goto login_try;}

        }
        return 0;
}
void fordelay(int j)       //Fordelay Function Definition
{   int i,k;
    for(i=0;i<j;i++)
         k=i;
}




void menu(void)              //Main Menu of Library Function
{   int choice;
    system("cls");
    system("color 0B");
    printf("\n\n\t\t\t            LIBRARY MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU OF THE LIBRARY \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.BOOK DATABASE MANAGEMENT\n\t\t2.STUDENT DATABASE MANAGEMENT\n\t\t3.ISSUE A BOOK\n\t\t4.RETURN A BOOK\n\t\t5.SEARCH FOR A BOOK OR STUDENT\n\t\t6.INVENTORY MENU\n\t\t7.NOTIFICATION MENU\n\t\t8.EXIT\n\n\n\n\n\t\tEnter your choice:");
    scanf("%d",&choice);
      if(choice<1 || choice>8)
	  {
        printf("ERROR: The choice isn't allowed\n");
        back3();
      }
    system("cls");
    switch(choice)
    {
        case 1:bookm();
        break;
        case 2:studentm();
        break;
        case 3:issue_book();
        back3();
        break;
        case 4:return_book();
        back3();
        break;
        case 5:searchm();
        break;
        case 6:inventory();
        back3();
        break;
        case 7:notification();
        back3();
        break;
        case 8:close();
        break;
	}
}
  
  
//BOOK DATABASE MENU NUMBER 1 FEATURE 
    
void bookm(void)                     //Book Database Menu
{   int choice;
    system("cls");
    system("color 0B");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE BOOK DATABASE  \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.ADD NEW BOOK IN THE DATABASE\n\t\t2.VIEW THE BOOKS IN THE DATABASE\n\t\t3.BACK TO MAIN MENU\n\n\n\n\n\t\tEnter your choice:");
    scanf("%d",&choice);
    if(choice<1 || choice>3)
	  {
        printf("ERROR: The choice isn't allowed\n");
        back();
       }
    system("cls");
    switch(choice)
    {
        case 1:add_books();
        back();
        break;
        case 2:view_book();
        back();
        break;
        case 3:menu();
        break;
    
    }
}

void add_books(void)
{
	system("cls");
	printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE ADD BOOK MENU  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
	printf("*************************************************************************");
	printf("\n[NOTE;- IF YOU WISH TO USE SPACE THEN INSTEAD USE _ TO PREVENT ERRORS!]");
	printf("\n*************************************************************************");
	FILE *fp;
	char another= 'Y';
	fp=fopen("BOOKS.TXT","a+");
	account_no:
	if(fp == NULL)
	{
		puts ("File Cannot be Opened due to Some Error!");
		exit (1);
	}
	while (another=='Y')
	{
	fflush(stdin);
	printf("\n----------------------------------------------\nEnter the Book Code:-[4 digit Preferred]\n");
	scanf("%d",&check.code);
	while(fscanf(fp,"%s%s%s%d%d",add.name,add.aname, add.cat,&add.code,&add.year)!=EOF)
    {
        if (check.code==add.code)
            { 
			printf("A book of this code already exists in the Database, You have to Start Over!");
            fordelay(1000000000);
            back();
            }
    }
    add.code=check.code;	
    fflush(stdin);
	printf("\n-----------------------------------------------------\nEnter the Name of the Book:-[15 characters Preferred]\n");
	scanf("%s",add.name);
	fflush(stdin);
	printf("\n-----------------------------------------------------\nEnter the Name of the Author:-[15 characters Preferred]\n");
	scanf("%s",add.aname);
	fflush(stdin);
	printf("\n-----------------------------------------------------\nEnter the Category of the Book:-\n");
	scanf("%s",add.cat);
	printf("\n-----------------------------------------------------\nEnter the Year the Book was Published:-\n");
	scanf("%d",&add.year);
	if(add.year<1985 || add.year>2019)
	  {
        printf("ERROR: The choice isn't allowed, Sorry You have to Start Over\n");
        back();
       }
	fprintf(fp,"%s %s %s %d %d\n",add.name,add.aname,add.cat,add.code,add.year);
	printf("\n\n\n************************************************************");
	printf("\n[THE BOOK HAS BEEN ADDED IN THE DATABASE SUCCESSFULY!]");
	printf("\n************************************************************");
	printf("\n\n\nDo you want to add another record (Y/N):-");
	fflush (stdin);
	another= getche();
	}
	fclose(fp);
}

void view_book(void)
{
	system("cls");
	printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE BOOK LIST MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
 	int test=0;
	system("cls");
	FILE *fpr;
	fpr=fopen("BOOKS.txt","r");
	if(fpr==NULL)
	{
	printf("\nFile Cannot be Opened due to Some Error!!");
	}
	printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE BOOK INVENTORY  \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n----------------------------------------------------------------------------------------------------------------");
	printf("\nBook Code \t Book Name \t\t\t Author Name \t\t Catogory \t\t Year Published");
	printf("\n----------------------------------------------------------------------------------------------------------------");
	while(fscanf(fpr,"%s%s%s%d%d",add.name,add.aname, add.cat,&add.code,&add.year)!=EOF)
	{
		printf("\n%d \t\t %s \t\t %s \t\t %s \t\t %d\n",add.code,add.name,add.aname,add.cat,add.year);
		test++;
	}
	if (test==0)
	{
		printf("\n NO RECORD FOUND!");
	}
	else
	{
		printf("\n----------------------------------------------------------------------------------------------------------------");
		printf("\n\t\t\t\t%d BOOKS ARE PRESENT IN THE DATABASE", test);
		printf("\n----------------------------------------------------------------------------------------------------------------");
	}
	fclose(fpr);
}
 		



void studentm(void)                   //Student Database Menu
{   int choice;
    system("cls");
    system("color 2");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE STUDENT DATABASE   \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.ADD STUDENTS IN THE DATABASE\n\t\t2.VIEW STUDENTS IN THE DATABASE\n\t\t3.UPDATE THE STATUS OF THE STUDENTS\n\t\t4.BACK TO THE MAIN MENU\n\n\n\n\n\t\tEnter your choice:");
    scanf("%d",&choice);
    if(choice<1 || choice>4)
	  {
        printf("ERROR Detected: The choice isn't allowed\n");
        back2();
       }
    system("cls");
    switch(choice)
    {
        case 1:add_student();
        back2();
        break;
        case 2:view_student();
        back2();
        break;
        case 3:update_status();
        back2();
        break;
        case 4:menu ();
        break;
    
    }

}
void add_student(void)
{
	system("cls");
	system("color 2");
	printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE ADD STUDENT MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");
	printf("*************************************************************************");
	printf("\n[NOTE;- IF YOU WISH TO USE SPACE THEN INSTEAD USE _ TO PREVENT ERRORS!]");
	printf("\n*************************************************************************");
 	FILE *fp;
	char another= 'Y';
	fp=fopen("STUDENT.TXT","a+");
	if(fp == NULL)
	{
		puts ("File Cannot be Opened due to Some Error!");
		exit (1);
	}
	while (another=='Y')
	{
	fflush(stdin);
	printf("\n-----------------------------------------------------\nEnter the Roll Number of the Student:-\n");
	scanf("%s",chec.roll);
	while(fscanf(fp,"%s%s%s",ad.name,ad.roll,ad.status)!=EOF)
    {
        	if(strcmp(ad.roll,chec.roll)==0)
            { 
			printf("A Student of the same Roll Number already exists in the Database, You have to Start Over!");
            fordelay(1000000000);
            back2();
            }
    }
    strcpy (ad.roll,chec.roll);
	printf("\n-----------------------------------------------------\nEnter the Name of the Student:-\n");
	scanf("%s",ad.name);
	fflush(stdin);
	printf("\n-----------------------------------------------------\nEnter the Status of the Student in the Current Year [Freshman/Sophomore/Junior/Senior]:-\n");
	scanf("%s",ad.status);
	fprintf(fp,"%s %s %s\n",ad.name,ad.roll,ad.status);
	printf("\n\n\n************************************************************");
	printf("\n[THE STUDNET HAS BEEN ADDED IN THE DATABASE SUCCESSFULY!]");
	printf("\n************************************************************");
	printf("\n\nDo you want to add another record (Y/N):-");
	fflush (stdin);
	another= getche();
	}
	fclose(fp);	
}
void view_student(void)
{
	int test=0;
	system("cls");
	system("color 2");
	FILE *fpr;
	fpr=fopen("STUDENT.TXT","r");
	if(fpr==NULL)
	{
	printf("\nFile Cannot be Opened due to Some Error!!");
	}
	printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE STUDENT INVENTORY  \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n----------------------------------------------------------------|");
	printf("\nRoll Number \t\tStudent Name \t\tCurrent Status");
	printf("\n----------------------------------------------------------------|");
	while(fscanf(fpr,"%s%s%s",ad.name,ad.roll,ad.status)!=EOF)
	{
		printf("\n%s\t\t\t%s\t\t%s\n",ad.roll,ad.name,ad.status);
		test++;
	}
	if (test==0)
	{
		printf("\n NO RECORD FOUND!");
	}
	else
	{
		printf("\n----------------------------------------------------------------|");
		printf("\n\t%d STUDENTS ARE PRESENT IN THE DATABASE", test);
		printf("\n----------------------------------------------------------------|");
	}
	fclose(fpr);	
}
void update_status (void)
{
 	int k=0;
	system("cls");
	system("color 2");
	printf("\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE UPDATE  STATUS MENU  \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	FILE *fa,*fb;
	fa=fopen("STUDENT.TXT","r");
	fb=fopen("NEWSTUDENT.TXT","w");
	if(fa==NULL||fb==NULL)
	{
	printf("\nCannot open file");
	}
	printf("\n\nEnter the Roll Number of the Student whose Status you wish to update\n");
	scanf("%s",up.roll);
	fflush(stdin);
	while(fscanf(fa,"%s%s%s",ad.name,ad.roll,ad.status)!=EOF)
	{
		if(strcmp(ad.roll,up.roll)==0)
		{
			printf("\n\t\t Record Found!");
			printf("\n Enter the Updated Status[Freshman/Sophomore/Junior/Senior] \t\n");
			gets(ad.status); 
			fflush(stdin);
		    fprintf(fb,"%s %s %s\n",ad.name,ad.roll,ad.status);
			k++;
		}
		else
		{
		 fprintf(fb,"%s %s %s\n",ad.name,ad.roll,ad.status);
		}
	}
	if (k==0)
	{
		system("cls");
		printf("\n Record was not found on the PC");
	}
	fclose(fa);
	fclose(fb);
	remove("STUDENT.TXT");
	rename("NEWSTUDENT.TXT","STUDENT.TXT");
}

void issue_book(void)              //Issue Book Function
{
	system("cls");
	system ("color 0E");
	printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE ISSUE BOOK MENU  \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n*************************************************************************");
	printf("\n[NOTE;- IF YOU WISH TO USE SPACE THEN INSTEAD USE _ TO PREVENT ERRORS!]");
	printf("\n*************************************************************************");
	printf("\n-----------------------------------------------------------------------------------------------------------");
	FILE *fp;
	char another= 'Y';
	fp=fopen("ISSUEBOOKS.TXT","a+");
	if(fp == NULL)
	{
		puts ("File Cannot be Opened due to Some Error!");
		exit (1);
	}
	while (another=='Y')
	{
	fflush(stdin);
	printf("\n-----------------------------------------------------\nEnter the Book Code [XXXX]:-\n");
	scanf("%d",&check.code);
	if(check.code<1000 || check.code>9999)
	  {
        printf("ERROR Detected: The choice isn't allowed\n");
        back3();
       }
	while(fscanf(fp,"%s%d%s%s%d\n",isu.name,&isu.code,is.name,is.roll,&is.days)!=EOF)
    {
        if (check.code==isu.code)
            { 
			printf("A book of this code already been Issued by Someone, You have to Start Over!");
            fordelay(1000000000);
            back3();
            }
    }
    isu.code=check.code;	
	fflush(stdin);
	printf("\n-----------------------------------------------------\nEnter the Name of the Book:-\n");
	scanf("%s",isu.name);
	fflush(stdin);	
	printf("\n-----------------------------------------------------\nEnter the Name of the Student:-\n");
	scanf("%s",is.name);
	fflush(stdin);
	printf("\n-----------------------------------------------------\nEnter the Roll Number of the Student:-[XXKXXXX]\n");
	scanf("%s",is.roll);
	fflush(stdin);
	printf("\n-----------------------------------------------------\nEnter For How many days you want the Book for:-\n");
	scanf("%d",&is.days);
	if(is.days<1 || is.days>15)
	  {
        printf("YOU ARE NOT ALLOWED TO ISSUE A BOOK MORE THAN 15 DAYS , YOU HAVE TO START OVER\n");
        back3();
       }
	fprintf(fp,"%s %d %s %s %d\n",isu.name,isu.code,is.name,is.roll,is.days);
	printf("\n\n\n************************************************************");
	printf("\n[THE STUDNET HAS BEEN ISSUED THE BOOK SUCCESSFULLY!]");
	printf("\n************************************************************");
	printf("\n\n\nDo you want to add another record (Y/N):-");
	another= getche();
	}
	fclose(fp);	
}            
void return_book(void)             //Return Book Function
{
	int test=0;
	system("cls");
	system ("color 7D");
	printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE RETURN MENU  \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n-----------------------------------------------------------------------------------------------------------");
	FILE *old,*update;
	old=fopen("ISSUEBOOKS.TXT","r");
	update=fopen("NEWISSUEBOOKS.TXT","w");
	printf("\nEnter the Name of the Book which you want to Return in the Library!\n");
	scanf("%s", ret.name);
	while(fscanf(old,"%s%d%s%s%d\n",isu.name,&isu.code,is.name,is.roll,&is.days)!=EOF)
	{
	if(strcmp(isu.name,ret.name)==0)
	{
		printf("----------------------------------------------------------------");
		printf("\nThe Book Has Been Returned Successfully In the Library!\n");
		printf("\n----------------------------------------------------------------");
		test++;
	}
	else
	{
	fprintf(update,"%s %d %s %s %d\n",isu.name,isu.code,is.name,is.roll,is.days);
	}
	}
	if (test==0)
	{
		system("cls");
		printf("Record Not Found in the Database , Try Again Later!");
	}
	fclose(old);
	fclose(update);
	remove("ISSUEBOOKS.TXT");
	rename("NEWISSUEBOOKS.TXT","ISSUEBOOKS.TXT");
}
	    
void searchm(void)             //Search Menu 
{   int choice;
    system("cls");
    system("color 6");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE SEARCH MENU  \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n\n\t\t1.SEARCH FOR A BOOK\n\t\t2.SEARCH FOR A STUDENT\n\t\t3.BACK TO MAIN MENU\n\n\n\n\n\t\tEnter your choice:");
    scanf("%d",&choice);
    if(choice<1 || choice>3)
	  {
        printf("ERROR: The choice isn't allowed\n");
        back4();
       }
    system("cls");
    switch(choice)
    {
        case 1: searchbook();
        back4();
        break;
        case 2:searchstudent();
        back4();
        break;
        case 3: menu();
        break;
    }
}  

void searchbook(void)
{
	system("cls");
	system("color 6");
 	int test=0;
	FILE *fpr;
	fpr=fopen("BOOKS.txt","r");
	if(fpr==NULL)
	{
	printf("\nFile Cannot be Opened due to Some Error!");
	}
	printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE SEARCH BOOK MENU  \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n----------------------------------------------------------------------------------------------------------------");
	printf("\nBook Code \t Book Name \t\t\t Author Name \t\t Catogory \t\t Year Published");
	printf("\n----------------------------------------------------------------------------------------------------------------");
	printf("\nEnter the Name of the Book which you are Searching for in the Database!\n");
	scanf("%s", sea.name);
	while(fscanf(fpr,"%s%s%s%d%d",add.name,add.aname, add.cat,&add.code,&add.year)!=EOF)
	{
		if(strcmp(add.name,sea.name)==0)
		printf("\nThe Record you are looking for does exist in the Database which is as follows:-\n--------------------------------------------------------------------------------------------------------\n%d \t\t %s \t\t %s \t\t %s \t\t %d\n--------------------------------------------------------------------------------------------------------",add.code,add.name,add.aname,add.cat,add.year);
		test++;
	}
	if (test==0)
	{
		printf("\n SORRY NO RECORD FOUND!");
	}
	fclose(fpr);
}
 
void searchstudent(void)
{
	system("cls");
	system("color 6");
 	int test=0;
	FILE *fpr;
	fpr=fopen("STUDENT.txt","r");
	if(fpr==NULL)
	{
	printf("\nFile Cannot be Opened due to Some Error!!");
	}
	printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE SEARCH STUDENT MENU  \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n----------------------------------------------------------------------------------------------------------------");
	printf("\nRoll Number \t\tStudent Name \t\tCurrent Status");
	printf("\n----------------------------------------------------------------------------------------------------------------");
	printf("\nEnter the Roll Number of the STUDENT which you want to SEARCH in the Database!\n");
	scanf("%s", se.roll);
	while(fscanf(fpr,"%s%s%s",ad.name,ad.roll,ad.status)!=EOF)
	{
		if(strcmp(ad.roll,se.roll)==0)
	    printf("\n------------------------------------------------------------------------\n%s\t\t\t%s\t\t%s\n------------------------------------------------------------------------\n",ad.roll,ad.name,ad.status);
		test++;
	}
	if (test==0)
	{
		printf("\n SORRY NO RECORD FOUND!");
	}
	fclose(fpr);
}
void inventory(void)           //Inventory Menu
{
	int test=0;
	system("cls");
	FILE *fpr;
	fpr=fopen("ISSUEBOOKS.TXT","r");
	if(fpr==NULL)
	{
	printf("\nFile Cannot be Opened due to Some Error!!");
	}
	printf("\n\t\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE INVENTORY MENU  \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n-----------------------------------------------------------------------------------------------------------");
	printf("\nBooK Code\tBook Name\t\t\tStudent Name\t\tRollNumber\t\tDays Taken");
	printf("\n-----------------------------------------------------------------------------------------------------------");
	system("color 09");
	while(fscanf(fpr,"%s%d%s%s%d",isu.name,&isu.code,is.name,is.roll,&is.days)!=EOF)
	{
		printf("\n%d\t\t%s\t\t%s\t\t%s\t\t\t%d\n",isu.code,isu.name,is.name,is.roll,is.days);
		test++;
	}
	if (test==0)
	{
		printf("\n NO RECORD FOUND!");
	}
	else
	{
		printf("\n-----------------------------------------------------------------------------------------------------------");
		printf("\n\t\t\t\t%d BOOKS ARE ISSUED AT THE MOMENT", test);
		printf("\n-----------------------------------------------------------------------------------------------------------");
	}
	fclose(fpr);
}              
void notification(void)        // Notification Menu
{
	int test=0;
	int i=1;
	system("cls");
	system("color 0F");
	FILE *fpr;
	fpr=fopen("ISSUEBOOKS.TXT","r");
	if(fpr==NULL)
	{
	printf("\nFile Cannot be Opened due to Some Error!!");
	}
	printf("\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE NOTIFICATION MENU  \xB2\xB2\xB2\xB2\xB2\xB2\xB2");
	printf("\n\n-----------------------------------------------------------------------------------------------------------");
	printf("\n[A room without books is like a body without a soul.]-Ibad Ahmed Shaikh 2019");
	printf("\n-----------------------------------------------------------------------------------------------------------");
	while(fscanf(fpr,"%s%d%s%s%d\n",isu.name,&isu.code,is.name,is.roll,&is.days)!=EOF)
	{
		Ibad=&isu;
		Bruce=&is;
		printf("\n[%d] The Book Named [%s] was issued by Student [%s] with Roll Number [%s] \n Which is Expected to Return in [%d] days.\n\n",i++,Ibad->name,Bruce->name,Bruce->roll,is.days);
		test++;
	}
	if (test==0)
	{
		printf("\n NO RECORD FOUND!");
	}
	else
	{
		printf("\n-----------------------------------------------------------------------------------------------------------");
		printf("\n\t\t\t\t%d BOOKS ARE EXPECTED TO RETURN BACK", test);
		printf("\n-----------------------------------------------------------------------------------------------------------\n\n\n");
	}
	fclose(fpr);
}  

void back(void)                //BACK FUNCTION 1
{
	int choice;
    printf("\n\n******************************************");
	printf("\nPress [1] to go back to the Main Menu or REFRESH\n");
	scanf("%d", &choice);
	if(choice != 1)
	{
		printf("INVALID ENTRY , KINDLY TRY AGAIN!");
		back();
	}
	switch (choice)
		{
			case 1:
			system("cls");
			bookm();
			break;		
		
		}
}
void back2(void)                //BACK FUNCTION 2
{
	int choice;
	printf("\n\n******************************************");
	printf("\nPress [1] to go back to the Main Menu or REFRESH\n");
	scanf("%d", &choice);
	if(choice != 1)
	{
		printf("INVALID ENTRY , KINDLY TRY AGAIN!");
		back2();
	}
	switch (choice)
		{
			case 1:
			system("cls");
			studentm();
			break;		
		
		}
}
void back3(void)               //BACK FUNCTION 3
{
	int choice;
	printf("\nPress [1] to go back to the Main Menu Or REFRESH\n");
	scanf("%d", &choice);
	if(choice != 1)
	{
		printf("INVALID ENTRY , KINDLY TRY AGAIN!");
		back3();
	}
	switch (choice)
		{
			case 1:
			system("cls");
			menu();
			break;		
		}	
}
void back4(void)               //BACK FUNCTION 4
{
	int choice;
	printf("\nPress [1] to go back to the Main Menu Or REFRESH\n");
	scanf("%d", &choice);
	if(choice != 1)
	{
		printf("INVALID ENTRY , KINDLY TRY AGAIN!");
		back4();
	}
	switch (choice)
		{
			case 1:
			system("cls");
			searchm();
			break;		
		}	
}
void close(void)           //End of Program 
{
	int dead;
    printf("This Project was developed By \n 1- Ibad-Ur-Rehman Ahmed Shaikh \n 2- Saman Khan \n 3- Haider Ali Baig \nAll rights reserved by 19k0246 ,19k0354 and 19k0132!\n\nThank You!");
}
