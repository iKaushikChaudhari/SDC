#include<stdio.h>
#include<string.h>

typedef struct staff {
int staffid;
char staffname [30];
char staffusername [30];
char staffpassword [30];
int staffno; 
}staff;

typedef struct courier {
	int cid;
	char sender_name[30];
	char address[100];
	long mobile_no;
	int pincode;
	char reciver_name[30];
	int amount;
	char status[10];
	char exdate[10];
	struct courier*next;
}courier;

courier *head_courier = NULL, *current_courier = NULL;

int autoIncrementcourier() {
	int id=0;
	for (current_courier = head_courier; current; current_courier = current_courier->next)
	id = current_courier->cid;
	return id+1;
}

void addcourier(){
	courier c, *node;
	system("cls");
    printf("\n----------------------------------------------------");
    printf("\n\t\tADD COURIER");
    printf("\n----------------------------------------------------");
	printf ("\nEnter Sender Name : ");
	scanf("%s", &c.sender_name);
	printf("\nEnter Address : ");
	scanf("%s", &c.address);
	printf ("\nEnter Contact Details : ");
	scanf("%s", &c.mobile_no);
	printf ("\nEnter Reciver Name: ");
	scanf("%s", &c.reciver_name);
	printf ("\nEnter Total Amont In INR: ");
	scanf("%s", &c.amount);
	
	node=(courier*)malloc(sizeoff(courier));
	node->cid = autoIncrement courier ();
	strcpy (node->sender_name, c.sender_name);
	strcpy (node->address, c.address);
	strcpy (node->mobile_no, c.mobile_no);
	strcpy (node->reciver_name, c.reciver_name);
	node->amount, c.amount;
	node->next=NULL;
	
	if (head_courier==NULL){
		head_courier=NULL;
	}
	else{
		current_courier=head_courier;
		while(current_courier->next!=NULL)
			current_courier=current_courier -> next;
		current_courier -> next=node;
	}
}



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
        			int matched=0;
        			char suser[30], pwd[30];
					printf("\n----------------------------------------------------");
					printf("\n\t\tLogin Menu");
					printf("\n----------------------------------------------------");	
					printf("\nEnter Username: ");
					scanf("%s",&suser);
					printf("\nEnter Password: ");
					hidepassword(pwd);
					FILE*fp=fopen("staff.csv","r");
					staff s1;
					printf("\n----------------------------------------------------");
					while (fscanf(fp,"%s %s %s %s\n", s1.staffid, s1.staffname, s1.staffusername, s1.staffpassword)!=EOF){
						//decrypt(s1.staffpassword,0xAED);
						if(strcmp(s1.staffusername,suser)==0 && strcmp(s1.staffpassword,pwd)==0){
							matched=1;
							break;
						}
					}
					fclose(fp);
					if(matched==1){
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
								//scanf("%d",&courier.cid);
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
	printf ("\nEnter Staff ID : ");
	scanf("%s", &s.staffid);
	printf ("\nEnter Staff Name : ");
	scanf("%s", &s.staffname);
	printf("\nCreate Username: ");
	scanf("%s", &s.staffusername);
	printf ("\nCreate Password : ");
	hidepassword(s.staffpassword);
	//encrypt (s.staffpassword,0xAED);
	
	//s.staffno=autoIncrementstaffno();
	FILE *fp = fopen ("staff.csv", "a+");
	fprintf(fp,"%s %s %s %s\n", &s.staffid, &s.staffname, &s.staffusername, &s.staffpassword);
	fclose(fp);
	printf("\n----------------------------------------------------");
	printf("\nStaff Added Successfully\n");
}

/*
int autoIncrementstaffno() {
	FILE *fp = fopen ("staff.csv","r");
	int sno= 0;
	staff s;
	while (fprintf(fp,"%s %s %s %s %s\n", &s.staffno, &s.staffid, &s.staffname, &s.staffusername, &s.staffpassword)!=EOF){
	sno= s.staffno;
	}
	fclose(fp);
	return sno+1;
}
*/

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
	
}
/*
void encrypt (char password [], int key) {
	for(int i=0; i<strlen(password); i++) {
		password[i] = password[i] - key;
	}
}

void decrypt (char staffpassword [], int key) {
	for (int i=0; i<strlen (staffpassword); i++) {
		staffpassword[i] = staffpassword [i]+ key;
	}
}
*/

