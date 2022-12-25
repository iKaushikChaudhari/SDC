#include<stdio.h>
#include<string.h>

struct Courier{
	char name[15];
	char address[15];
	long mobno;
	int price;
}p[15];

struct staff{
	char names[15];
	int id;
	int prices;
}t[15];



int main(){
	printf("\t*******Welcome*******\n");
	int ch;
	void user();
	void admin();
	//void hidepassoword();

	printf("\n----------------------------------------------------");
    printf("\n\t\tMAIN MENU");
    printf("\n----------------------------------------------------");
    printf("\n1. Admin Login");
    printf("\n2. Customer Login");
    printf("\n----------------------------------------------------");
    printf("\nEnter Your Choice :");
	scanf("%d",&ch);
	
	switch(ch)
	{
		
		case 1:
			admin();
			break;
			
//		case 2:
//			user();
//			break;
	}
	
	
	return 0;
}



int admin(){
	char username[30], password[30];
	void dilveryagent();
	void displayout();
	//void hidepassword();
	printf("\n----------------------------------------------------");
	printf("\n\t\tLogin Menu");
	printf("\n----------------------------------------------------");
	printf("\nEnter Username: ");
	scanf("%s",&username);
	printf("\nEnter Password: ");
	scanf("%s",&password);
	//hidepassword(password);
	printf("\n----------------------------------------------------");
	if (strcmp(username, "kaushik") == 0 && strcmp (password, "kaushik")==0) {
	printf("\nlogin Successfull");
	dilveryagent();
		}
	else
		printf("\nEnter Correct Password Or Username");
		printf("\nTry Again");
}



void dilveryagent(){
	int i,j,n,a,ch;
	void delete_cou();
	void displayout();
	printf("\nEnter Number Of Courier : ");
	
	scanf("%d",&j);
	
	for(i=0;i<j;i++){
		printf("\n----------------------------------------------------");
		printf("\nEnter Customer Name:- ");
		scanf("%s",p[i].name);
		printf("\nEnter The Address:- ");
		scanf("%s",&p[i].address);
		printf("\nEnter Mobile No.:- ");
		scanf("%ld",&p[i].mobno);
		printf("\nEnter Total Cost:- ");
		scanf("%d",&p[i].price);
		printf("\n----------------------------------------------------");
	}
printf("\n-----Checkout-----\n");

for(i=0;i<j;i++){
	printf("\n%s\t",p[i].name);
	printf("\n%s",p[i].address);
	printf("\n%ld",p[i].mobno);
	printf("\n%d\n\n",p[i].price);
}

	displayout();
}
void displayout(){
	int i,j,n,a,ch;
	void delete_cou();
	printf("\n----------------------------------------------------");
	printf("\n\t\tCourier Selection Menu");
	printf("\n----------------------------------------------------");
	printf("\nWhich courer is Your\n");
	printf("\n1.%s\t%s\n2.%s\t%s\n3.%s\t%s",p[0].name,p[0].address,p[1].name,p[1].address,p[2].name,p[3].address);
	scanf("%d",&ch);

switch(ch){
	case 1:
		strcpy(t[0].names,p[0].name);
		t[0].prices=p[0].price;
		printf("\nSuccefullay Added to verifyed your products");
		break;
		
	case 2:
		strcpy(t[1].names,p[1].name);
		t[1].prices=p[1].price;
	    break;
	    
	case 3:
		strcpy(t[2].names,p[2].name);
		t[2].prices=p[2].price;


}

printf("\nPress 1 to Add more Courier.");
printf("\nPress 2 To Go To Main Menu. ");
printf("\nPress 3 To Delete Courier");
printf("\nPress 0 for Slip:- ");
scanf("%d",&a);

if(a==0){
	for(i=0;i<3;i++){
		if(t[i].prices!=0)
		
		{
		printf("\n%s\t",t[i].names);
		printf("\n%d\n",t[i].prices);
		}
	}
	
	int total=0;
	printf("/nThe total bill is:- ");
	
	for(i=0;i<3;i++){
		total=total+t[i].prices;
		
	}
	printf("%d",total);
}

else if(a==1){
	dilveryagent();
	
}
else if(a==2){
	admin();
	
}
else if(a==3){
	delete_cou();
}

}
void delete_cou(){
	int x = 0;
	void displayout();
	int counter = 0;
    char deleteName[20];  // Temp string to compare to existing phonebook
    char deleteaddress[20];  
	char deletemo;//temp string
    char nullStr[20] = {"\0"};  // empty string to remove phonenumber
	int nullno=0;
	
    printf("\nEnter Name: ");
    scanf("%s", deleteName); //place into temp string
    printf("Enter Address.: ");
    scanf("%s", deleteaddress); //place into temp string

    for (x = 0; x < 4; x++)
    {
        if (strcmp(deleteName, p[x].name) == 0) 
        {
            for (x = 0; x < 4; x++)
            {
                if (strcmp(deleteaddress, p[x].address) == 0) 
                {
                    strcpy(p[x].name, nullStr); 
                    p[x].mobno=nullno; 
                    strcpy(p[x].address, nullStr);
                    printf("Courier removed from Record.\n");
                    counter--;
                    break;
                }
            }

        }
        else {
        	printf("Invalid entry--try again.\n");
		}
    }
    displayout();
}
