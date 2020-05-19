/*
*******************************************************************************
************
 INTRODUCTION
*******************************************************************************
*********** */
//DSA PROJECT

/*
*******************************************************************************
************
 HEADER FILES
*******************************************************************************
*********** */
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
/*
*******************************************************************************
************
 STRUCTURES
*******************************************************************************
*********** */
struct ID //structure to store all the login IDs
{
 char id_1[20];
 char pass[20];
}id1[100],input;
struct products //structure to store all the products
{
 int prodID;
 char name[100];
 float price;
 int discount;
 char desc[600];
 char category[100];
 int available;
}p1[100],inp;
struct kart //structure to store all the items of the cart
{
 char id[20];
 char passwd[20];
 int prodID;
 char name[100];
 float price;
 int discount;
 char desc[600];
 char category[100];
 int quantity;
}k[100],inpu;
int n=0,m=0,p=0,nx=0,my=0,pz=0; //m for items in cart and n for total items
/*
*******************************************************************************
************
 FUNCTIONS
*******************************************************************************
************ */
void login(); //a function to login
void home(); //home page
void category(); //search category-wise
void view(); //view all the products one-by-one
void searchcat(char ch[20]); //search by categories
void kart(); //view the items in the cart
void addkart(int a,int c); //products to be added to the cart
int viewn(int a); //product viewer
void viewdetail(int a); //detailed viewing //delete a product in the cart
void admin();
void user();
void addprod();
void modify();
void dele();
void pay();
void modifykart();
void deletekart();
void newregister();
void cod();
void pu();
void card();
FILE *outfile;
FILE *infile;
FILE *iofile;
char data[200];
/*
*******************************************************************************
************
 MAIN FUNCTION
*******************************************************************************
************ */
void main()
{
 system("cls");
 int i;
  infile=fopen("ID.dat","r");
 if(infile==NULL)
 {
 fprintf(stderr,"\nError opening file\n");
 exit(1);
 }
 while(fread(&input,sizeof(struct ID),1,infile))
 {
 strcpy(id1[p].id_1,input.id_1);
 strcpy(id1[p].pass,input.pass);
 p++;
 }
 fclose(infile);
 infile=fopen("Products.dat","r");
 if(infile==NULL)
 {
 fprintf(stderr,"\nError opening file\n");
 exit(1);
 }
 while(fread(&inp,sizeof(struct products),1,infile))
 {
 p1[n].prodID=inp.prodID;
 strcpy(p1[n].name,inp.name);
 p1[n].price=inp.price;
 p1[n].available=inp.available;
 p1[n].discount=inp.discount;
 strcpy(p1[n].desc,inp.desc);
 strcpy(p1[n++].category,inp.category);
 }
 fclose(infile);
 infile=fopen("kart.dat","r");
 if(infile==NULL)
 {
 fprintf(stderr,"\nError opening file\n");
 exit(1);
 }
 i=0;
 while(fread(&inpu,sizeof(struct kart),1,infile))
 {
 strcpy(k[i].id,inpu.id);
 strcpy(k[i].passwd,inpu.passwd);
 k[i].prodID=inpu.prodID;
 strcpy(k[i].name,inpu.name);
 k[i].price=inpu.price;
 k[i].quantity=inpu.quantity;
 k[i].discount=inpu.discount;
 strcpy(k[i].desc,inpu.desc);
 strcpy(k[i].category,inpu.category);
  i++;
 }
 fclose(infile);
 home();
 do{
 system("cls");
 int choice;
 printf("\t\tMENU:\n\n\t1. View all products\n\n\t2. Categories\n\n\t3. Kart\n\n\t4. Logout\n\n\t5.Logout and exit");
 printf("\n\n\tEnter your choice: ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1: view(n);
 break;
 case 2: category();
 break;
 case 3: kart();
 break;
 case 4: home();
 break;
 case 5: exit(0);
 }
 }while(1);
}
void admin()
{
 system("cls");
 int choice;
 do{
 printf("\t\tMENU:\n\n\t1. Modify products\n\n\t2. Delete Products\n\n\t3. Add products\n\n\t4. Logout and exit");
 printf("\n\n\tEnter your choice: ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1: modify();
 break;
 case 2: dele();
 break;
 case 3: addprod();
 break;
 }
 }while(1);
 return;
}
void modify()
{
 system("cls");
 int proID,disc,availa;
 char ch;
 float pr;
 printf("Enter the product ID to be modified: ");
 scanf("%d",&proID);
 infile=fopen("Products.dat","r");
 outfile=fopen("temp.dat","wb+");
 if(infile==NULL)
 {
 fprintf(stderr,"\nError opening file\n");
 exit(1);
 }
 while(fread(&inp,sizeof(struct products),1,infile))
 {
 if(proID!=inp.prodID)
 {
 fwrite(&inp, sizeof(struct products),1,outfile);
 }
 else
 {
 printf("The product details are: \n");
 printf("Product ID: ");
 printf("%d",inp.prodID);
 printf("\nProduct name: ");
 printf("%s",inp.name);
 printf("\nProduct price: ");
 printf("%f",inp.price);
 printf("\nProduct discount: ");
 printf("%d",inp.discount);
 printf("\nDescription: ");
 printf("%s",inp.desc);
 printf("\nProduct category: ");
 printf("%s",inp.category);
 printf("\nProduct available: ");
 printf("%d",inp.available);
 printf("Do you want to change the price?(y/n)");
 scanf("%c",&ch);
 if(ch=='y'||ch=='Y')
 {
 printf("Enter the new price: ");
 scanf("%f",&pr);
 inp.price=pr;
 }
 printf("Do you want to change the discount?(y/n)");
 scanf("%c",&ch);
 if(ch=='y'||ch=='Y')
 {
 printf("Enter the new discount: ");
 scanf("%d",&disc);
 inp.discount=disc;
 }
 printf("Do you want to change the number of products available?(y/n)");
 scanf("%c",&ch);
 if(ch=='y'||ch=='Y')
 {
 printf("Enter the new amount: ");
 scanf("%d",&availa);
 inp.available=availa;
 }
 fwrite(&inp, sizeof(struct products),1,outfile);
 }
 }
 fclose(infile);
 fclose(outfile);
 remove("Products.dat");
 rename("temp.dat","Products.dat");
}
void dele()
{
 system("cls");
 int s;
 printf("Enter the product ID to be deleted: ");
 scanf("%d",&s);
  infile=fopen("Products.dat","r");
 outfile=fopen("temp.dat","wb+");
 if(infile==NULL)
 {
 fprintf(stderr,"\nError opening file\n");
 exit(1);
 }
 while(fread(&inp,sizeof(struct products),1,infile))
 {
 if(s!=inp.prodID)
 {
 fwrite(&inp, sizeof(struct products),1,outfile);
 }
 else
 {
 continue;
 printf("Product deleted!");
 getch();
 }
 }
 fclose(infile);
 fclose(outfile);
 remove("Products.dat");
 rename("temp.dat","Products.dat");
 }
void addprod()
{
 system("cls");
 infile=fopen("Products.dat","a+");
 printf("Enter the details: \n");
 printf("prodID: ");
 scanf("%d",&inp.prodID);
 printf("prodID: ");
 scanf("%s",inp.name);
 printf("prodID: ");
 scanf("%f",&inp.price);
 printf("prodID: ");
 scanf("%d",&inp.discount);
 printf("prodID: ");
 scanf("%s",&inp.desc);
 printf("prodID: ");
 scanf("%s",&inp.category);
 printf("prodID: ");
 scanf("%d",&inp.available);
 fwrite(&inp, sizeof(struct products),1,infile);
 fclose(infile);
 printf("\n\n\n\tProduct added!");
 getch();
 }
void newregister()
{
 char newid[20],newpass[20],newpass1[20];
 infile=fopen("ID.dat","a+");
 printf("Enter the credentials: \nID: ");
 scanf("%s",newid);
 printf("\nPassword: ");
 scanf("%s",newpass);
 printf("\nPassword: ");
 scanf("%s",newpass1);
 while(strcmp(newpass,newpass1)!=0)
 {
 printf("\n\n Both the passwords do not match!!");
 printf("Enter the credentials: \nID: ");
 scanf("%s",newid);
 printf("\nPassword: ");
 scanf("%s",newpass);
 printf("\nPassword: ");
 scanf("%s",newpass1);
 }
 strcpy(id1[p].id_1,newid);
 strcpy(id1[p].pass,newpass);
 p++;
  fwrite(&id1[p], sizeof(struct ID),1,infile);
 fclose(infile);
 return;
}
void login() //a function to login
{
 system("cls");
 char studentID[20],password[20],ch;
 int temp=1,x,y,a=0,i;
 do{
 system("cls");
 i=0;
 printf("\nStudent_ID:");
 scanf("%s",studentID);
 printf("\nPassword:");
 while((ch=getch())!=13)
 {
 password[i++]=ch;
 printf("*");
 }
 password[i]='\0';
 while(pz!=p)
 {
 x=strcmp(id1[pz].id_1,studentID);
 y=strcmp(id1[pz].pass,password);
 if(x==0&&y==0)
 {
 printf("\n\n\n\t\t\tWelcome %s",studentID);
 getch();
 if(strcmp("admin",studentID)==0)
 {
 admin();
 printf("Successfully logged out!");
 }
 else
 {
 a=1;
 return;
 }
 }
 pz++;
 }
 printf("\nWrong Password, try again", 3-n);
 getch();
 temp++;
 if(temp>3)
 {
 printf("\nAccess Denied");
 getch();
 exit(0);
 }
 }while (temp<=3&&a==0);
}
void home() //home page
{
 system("cls");
 int a;
 printf("\n\n\n\n\t\t\t\t WELCOME TO\n\n\t\t\t\t\tVIT\n\n\t\t\t\t CART!!!\n\n\n\n\n\n\t\tA website to help VITians save time.");
 printf("\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tPRESS ANY KEY TO CONTINUE");
 getch();
 system("cls");
 printf("First time user then press 1");
 scanf("%d",&a);
 switch(a)
 {
 case 1: newregister();
 break;
 }
 login();
}
int viewn(int a) //view products one-by-one
{
     system("cls");
 char ch;
 int b;
 printf("\n\n%d\t%s\n\n\tPrice:%.0f",p1[a].prodID,p1[a].name,p1[a].price);
 printf("\n\n\n\nPress \'tab\' to go to next product");
 printf("\nPress \'backspace\' to go to previous product");
 printf("\nPress \'enter\' to go to get detailed description of the product");
 ch=getch();
 b=ch;
 switch(b)
 {
 case 8: return -1; //if the user presses backspace
 case 9: return 0; //if the user presses tab
 case 13:viewdetail(a); //if the user preses enter
 return 1;
 }
}
void viewdetail(int a) //to view the detailed information about a item
{
 system("cls");
 char b,ch;
 int c;
 printf("\n\n\t%d\t%s\n\n\tPrice: %.2f\n\n\tDiscount: %d\n\n\tDescription:\n\t\t%s\n\tCategory: %s\n\n\t\t\t\tAvailable: %d",p1[a].prodID,p1[a].name,p1[a].price,p1[a].discount,p1[a].desc,p1[a].category,p1[a].available)
;
 printf("\n\n\n\nEnter 1 to add to cart...");
 printf("\n\n\n\nEnter 2 to go back...");
 b=getch();
 if(b=='1') //to add to cart
 {
 printf("\nHow many do you want to add? ");
 scanf("%d",&c);
 p1[a].available-=c;
 if(p1[a].available<0)
 {
 p1[a].available+=c;
 printf("\nOnly %d items available, so adding %d items!",c,c);
 c=p1[a].available;
 p1[a].available=0;
 }
 addkart(a,c);
 }
 else
 return;
 getch();
 return;
}
void view() //view all the products
{
 int b;
 for(nx=0;nx<n;)
 {
 b=viewn(nx);
 if(b==-1)
 {
 nx--;
 if(nx<0)
 {
 printf("\nThis is the first product... Cannot go back");
 nx+=2;
 }
 }
 else
 nx++;
 }
}
void category() //view products category-wise
{
 system("cls");
 int choice;
 char ch[20];
 printf("\tSelect any one category: ");
  printf("\n\t\t1. Eatables\n\t\t2. Toileteries\n\t\t3. Household\n\t\t ");
 printf("Enter your choice: ");
 scanf("%d",&choice);
 switch(choice)
 {
 case 1: strcpy(ch,"Eatables");
 searchcat(ch);
 break;
 case 2: strcpy(ch,"Toiletries");
 searchcat(ch);
 break;
 case 3: strcpy(ch,"Household");
 searchcat(ch);
 break;
 }
 getch();
}
void searchcat(char ch[20]) //search for the products of a particular category
{
 int b;
 for(nx=0;nx<n;)
 {
 if(strcmp(p1[nx].category,ch)==0)
 {
     b=viewn(nx);
 if(b==-1)
 {
 nx--;
 if(nx<0)
 {
 printf("\nThis is the first product... Cannot go back");
 nx+=2;
 }
 }
 else
 nx++;
 }
 }
 getch();
}
void delekart()
{
 int s;
 printf("Enter the product ID to be deleted: ");
 scanf("%d",&s);
 infile=fopen("kart.dat","r");
 outfile=fopen("temp.dat","wb+");
 if(infile==NULL)
    {
 fprintf(stderr,"\nError opening file\n");
 exit(1);
 }
 while(fread(&inpu,sizeof(struct kart),1,infile))
 {
 if(s!=inpu.prodID)
 {
 fwrite(&inpu, sizeof(struct kart),1,outfile);
 }
 else
 {
 continue;
 printf("Product deleted from kart!");
 getch();
 }
 }
 fclose(infile);
 fclose(outfile);
 remove("kart.dat");
 rename("temp.dat","kart.dat");
}
void modifykart()
{
     int proID,quanti;
 char ch;
 n=0;
 printf("Enter the product ID to be modified: ");
 scanf("%d",&proID);
 infile=fopen("kart.dat","r");
 outfile=fopen("temp.dat","wb+");
 iofile=fopen("Products.dat","r");
 while(fread(&inp,sizeof(struct products),1,iofile))
 {
 if(inp.prodID==proID)
 break;
 n++;
 }
 if(infile==NULL)
 {
 fprintf(stderr,"\nError opening file\n");
 exit(1);
 }
 while(fread(&inpu,sizeof(struct kart),1,infile))
 {
 if(proID!=inpu.prodID)
 {
 fwrite(&inpu, sizeof(struct kart),1,outfile);
 }
 else
 {
 printf("The product details are: \n");
 printf("Product ID: ");
 printf("%d",inpu.prodID);
 printf("\nProduct name: ");
 printf("%s",inpu.name);
 printf("\nProduct price: ");
 printf("%f",inpu.price);
 printf("\nProduct discount: ");
 printf("%d",inpu.discount);
 printf("\nProduct quantity: ");
 printf("%d",inpu.quantity);
 printf("Do you want to change the quantity?(y/n)");
 scanf("%c",&ch);
 if(ch=='y'||ch=='Y')
 {
 printf("Enter the new quantity: ");
 scanf("%d",&quanti);
 p1[n].available+=inpu.quantity;
 if(p1[n].available<quanti)
 {
 printf("Adding %d items as %d are only available",p1[n].available,p1[n].available);

} else
 inpu.quantity=quanti;
 }
 fwrite(&inpu, sizeof(struct kart),1,outfile);
 }
 }
 fclose(infile);
 fclose(outfile);
 remove("kart.dat");
 rename("temp.dat","kart.dat");
}
void kart() //view all the items in the cart
{
 float total=0,sum,sumad;
 do{
 system("cls");
 int i,b,a=0;
 infile=fopen("kart.dat","r");
 if(infile==NULL)
 {
 fprintf(stderr,"\nYour kart is empty!\n");
 }
 while(fread(&inpu,sizeof(struct kart),1,infile))
     {
 if(strcmp(inpu.id,id1[pz].id_1)==0)
 {
 a=1;
 printf("\n\n%d\t%s\nPrice: %.2f\nQuantity: %d",inpu.prodID,inpu.name,
((inpu.price)*(inpu.quantity)),inpu.quantity);
 sum=(inpu.price)*(inpu.quantity);
 sumad=sum-((inpu.price)*(inpu.discount)/100);
 total+=sumad;
 }
 }
 fclose(infile);
 if(a==0)
 {
 printf("Your kart is empty!");
 getch();
 return;
 }
 else
 {
 printf("\n\t\t\t\tTotal amount: Rs.%.2f",total);
 printf("\npress '0' to go to payment options");
 printf("\npress '-1' to return back");
 printf("\nInput 1 to delete an item ");
 printf("\nInput 2 to modify an item\n ");
 scanf("%d",&b);
 if(b==-1) //to return back to the main menu
 return;
 else if(b==0) //to payment window
 pay();
 else if(b==1)
 delekart(); //to search for the prodID of the product to be removed from the cart
 else
 modifykart();
 }
 }while(1); //the loop runs forever till we are
 getch();
}
void addkart(int a,int c) //add to cart
{
 infile=fopen("kart.dat","a+");
 strcpy(inpu.id,id1[pz].id_1);
 strcpy(inpu.passwd,id1[pz].pass);
 inpu.prodID=p1[a].prodID;
 strcpy(inpu.name,p1[a].name);
 inpu.price=p1[a].price;
 inpu.discount=p1[a].discount;
 strcpy(inpu.desc,p1[a].desc);
 strcpy(inpu.category,p1[a].category);
  inpu.quantity=c;
 fwrite(&inpu, sizeof(struct ID),1,infile);
 printf("Item added!!");
 fclose(infile);
 getch();
}
void pay()
{
 system("cls");
 int a;
 char address[200];
 printf("\t\t\t\tWELCOME TO THE PAYMENT GATEWAY! WE ENSURE A SAFE PAYMENT PROCESS");
 printf("\n\nEnter your full address: ");
 fgets(address,200,stdin);
 printf("\n\n\t1. Pay using card(only VISA-debit and Mastercards)\n\n\t2. Cash on delivery\n\n\t3. Pick-Up");
 printf("\n\nEnter your choice: ");
 scanf("%d",&a);
 switch(a)
 {
 case 1: card();
 break;
 case 2: cod();
 break;
 case 3: pu();
 break;
 }
 return;
}
void cod()
{
 system("cls");
 printf("\n\t\t\t\tOrder successful!");
 printf("\n\n\n\n\t\t\tYour order will arrive in 20 minutes...");
 getch();
 return;
}
void pu()
{
 system("cls");
 printf("\n\t\t\t\tOrder successful!");
 printf("\n\n\n\n\t\t\tYou can come and pick-up your order in 10 minutes...");
 getch();
 return;
}
void card()
{
 system("cls");
  char no[17],dat[5],name[40],cvv[4];
 int a=0;
 printf("Enter the card number: ");
 scanf("%s",no);
 if(no[0]=='4')
 {
 printf("Expiry date(mmyy): ");
 scanf("%s",dat);
 printf("Holder's name: ");
 scanf("%s",name);
 printf("CVV: ");
 while(a!=3)
 {
 cvv[a]=getch();
 printf("*");
 }
 getch();
 system("cls");
 printf("\n\n\n\n\t\t\t\tProcessing....");
 getch();
 printf("\n\n\n\nPayment successful!");
 return;
 }
 else if(no[0]=='5')
     {
 printf("Expiry date(mmyy): ");
 scanf("%s",dat);
 printf("Holder's name: ");
 scanf("%s",name);
 printf("CVV: ");
 while(a!=3)
 {
 cvv[a]=getch();
 printf("*");
 }
 getch();
 system("cls");
 printf("\n\n\n\n\t\t\t\tProcessing....");
 getch();
 printf("\n\n\n\nPayment successful!");
 getch();
 return;
 }
 else
 {
 printf("\n\nCard not supported!");
 getch();
 return;
  }
}

