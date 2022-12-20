#include<stdio.h>
#include<string.h>


typedef struct staff {
int staffid;
char staffname [30];
char staffusername [30];
char staffpassword [30];
int staffno;
} staff;

struct courier{
	int cid;
	char sendname[30];
	char address[100];
	long mobileno;
	char recivername[30];
	int amount;
	char status[10];
	char exdate[10];
	
}Head=NULL;

//Function declearation 
void hidepassword();
int validadmin();
void registerstaff();
int validstaff();
int validadmin();
//main function 
int main()
{
    int ch,ch1,ch2;
    
    do{
        system("cls");
        printf("\n----------------------------------------------------");
        printf("\n\t\tMAIN MENU");
        printf("\n----------------------------------------------------");
        printf("\n1. Admin Login");
        printf("\n2. Staff Login");
        printf("\n3. Customer Login");
        printf("\n0. Exit");
        printf("\n----------------------------------------------------");
        printf("\nEnter Your Choice :");
        scanf("%d",&ch);
        switch(ch){
        	case 1:
				{
					if(validadmin()){
						do {
						system("cls");
						printf("\n----------------------------------------------------");
						printf("\n\t\tAdmin Menu");
						printf("\n----------------------------------------------------");
						printf("\n1.Manage Staff");
						printf("\n3.View Courier");
						printf("\n4.View Complaints");
						printf("\n5.Manage Branches");
						printf("\n6.Manage Pages");
						printf("\n7.View Enquiry");
						printf("\n0.Back");
						printf("\n----------------------------------------------------");
						printf("\nEnter Your Choice: ");
						scanf("%d", &ch1);
						switch(ch1){
							case 1:
							{
								do {
								system("cls");
								printf("\n----------------------------------------------------");
								printf("\n\t\tManage Staff");
								printf("\n----------------------------------------------------");
								printf("\n1.Add Staff");
								printf("\n2.Remove Staff");
								printf("\n3.View");
								printf("\n0.Back");
								printf("\n----------------------------------------------------");
								printf("\nEnter Your Choice: ");
								scanf("%d", &ch2);
								switch(ch2){
									case 1:{
										printf("\n----------------------------------------------------");
										printf("\n\t\tAdd Staff");
										printf("\n----------------------------------------------------");
										registerstaff();
										system("pause");
										break;
									}
											
										
								}
								}while(ch2!=0);
								break;
							}
							
						}
						}while(ch1!=0);
					}
					else
					{
						printf("\n\nWrong Username Or Password\n\nTry Again\n\n");
						system("pause");
					}
					break;
				}
        	case 2:
        		{
					if (validstaff()){
					do {
					system("cls");
					printf("\n----------------------------------------------------");
					printf("\n\t\tStaff Menu");
					printf("\n----------------------------------------------------");
					printf("\n1.Add Courier");
					printf("\n2.Modify Courier");
					printf("\n3.View Courier");
					printf("\n4.Delete Courier");
					printf("\n5.Search Courier");
					printf("\n6.Update Status");
					printf("\n0.Back");
					printf("\n----------------------------------------------------");
					printf("\nEnter Your Choice: ");
					scanf("%d", &ch1);
					switch(ch1)
						{
							case 1:{
								printf("Enter Courier Id");
								scanf("%d",&courier.cid)
								break;
							}
						}
					}while(ch1!=0);
				}
					else
					{
						printf("\n\nWrong Username Or Password\n\nTry Again\n\n");
						system("pause");
					}
					break;
				}
			case 3:
				{
					do {
					system("cls");
					printf("\n----------------------------------------------------");
					printf("\n\t\tCustomer Menu");
					printf("\n----------------------------------------------------");
					printf("\n1.About Us");
					printf("\n2.View Status");
					printf("\n3.");
					printf("\n4.View Courier");
					printf("\n5.Search Courier");
					printf("\n0.Back");
					printf("\n----------------------------------------------------");
					printf("\nEnter Your Choice: ");
					scanf("%d", &ch1);
					}while(ch1!=0);
					break;
				}
			
		}
    }while(ch!=0);

    return 0;

}

//functions 

int validadmin(){
	char username[30], password[30];
	printf("\n----------------------------------------------------");
	printf("\n\t\tLogin Menu");
	printf("\n----------------------------------------------------");
	printf("\nEnter Username: ");
	scanf("%s",&username);
	printf("\nEnter Password: ");
	hidepassword(password);
	printf("\n----------------------------------------------------");
	if (strcmp(username, "kaushik") == 0 && strcmp (password, "kaushik")==0) {
	return 1;
		}
	else
		return 0;
}

void hidepassword(char password[])
{
	char ch; int i=0;
	while((ch=_getch())!=13){
		password[i]=ch;
		printf("*");
		i++;
	}
	password[i]='\0';	
}

void registerstaff() {
	staff s;
	fflush(stdin);
	printf ("\nEnter Staff ID : ");
	scanf("%[^\n]s", s.staffid);
	fflush(stdin);
	printf ("\nEnter Staff Name : ");
	scanf("%[^\n]s", s.staffname);
	printf("\nEnter Username: ");
	scanf("%s", s.staffusername);
	printf ("\nEnter Password : ");
	hidepassword(s.staffpassword);
	FILE *fp = fopen ("staff.csv", "a+");
	fprintf(fp,"%d, s, %s, %s, %ld, s, %s\n", s.staffno, s.staffid, s.staffname, s.staffusername, s.staffpassword);
	fclose(fp);
	printf("\n----------------------------------------------------");
	printf("\nStaff Added Successfully\n");
}

int autoIncrement staffno () {
	FILE *fp = fopen ("staff.csv","r");
	int id= 0;
	staff s;
	while (fprintf(fp,"%d, s, %s, %s, %ld, s, %s\n", s.staffno, s.staffid, s.staffname, s.staffusername, s.staffpassword);
	id= c.cid;
}
fclose(fp);
return id+1;
-}

int validstaff(){
	staff s;
	char suser[30], pwd[30];
	printf("\n----------------------------------------------------");
	printf("\n\t\tLogin Menu");
	printf("\n----------------------------------------------------");	
	printf("\nEnter Username: ");
	scanf("%s",&suser);
	printf("\nEnter Password: ");
	hidepassword(pwd);
	printf("\n----------------------------------------------------");
	if (strcmp(suser,s.username) == 0 && strcmp (pwd,s.password)==0){
		return 1;
		}
	else
		return 0;
}

void addcourier(){
	struct courier *last, *ptr;
    int choice_add;
    do
    {
        ptr = (struct courier *)malloc(sizeof(struct courier));
        struct courier *last, *ptr;
    int choice_add;
    do
    {
//    	int cid;
//	char sendname[30];
//	char address[100];
//	long mobileno;
//	char recivername[30];
//	int amount;
//	char status[10];
//	char exdate[10];
        ptr = (struct courier *)malloc(sizeof(struct courier));
        printf("Courier ID :");
        scanf("%d", &ptr->cid);
        printf("Customer Name :");
        scanf("%s", &ptr->sendname);
        printf("Address :");
        scanf("%s", &ptr->address);
        printf("mobileno :");
        scanf("%ld", &ptr->mobileno);
        printf("Reciver Name :");
        scanf("%s", &ptr->recivername);
        printf("Amount :");
        scanf("%d", &ptr->amount);
        printf("status :");
        scanf("%s", &ptr->status);
        printf("exdate :");
        scanf("%s", &ptr->exdate);

        ptr->next = NULL;
        if (Head_Item == NULL)
        {
            Head_Item = ptr;
        }
        else
        {
            last = Head_Item;
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = ptr;
        }
        printf("\nIf you add one more Item (Press 0):");
        scanf("%d", &choice_add);
    } while (choice_add == 0);

        ptr->next = NULL;
        if (Head_Item == NULL)
        {
            Head_Item = ptr;
        }
        else
        {
            last = Head_Item;
            while (last->next != NULL)
            {
                last = last->next;
            }
            last->next = ptr;
        }
        printf("\nIf you add one more Item (Press 0):");
        scanf("%d", &choice_add);
    } while (choice_add == 0);
}
