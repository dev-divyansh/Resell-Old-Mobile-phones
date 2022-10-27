#include<stdio.h>
#include<conio.h>
#include<unistd.h>
#include<stdlib.h>
// defining our own datatype to store users name and passcode
struct sris{
    char Name[100];
    int passcode;
};

// defining structure  to store products

struct pro{
    char product_name[50];
    char seller_name[50];
    int ram;
    int storage;
    int price;
};

struct pro products[30];

struct sris users[30];
int cursor = 0;
int cursor_product = 0;
int fare;

// function to print welcome message
void welcome(){
    printf("\n\n\n\n\n");
    char mes1[21] = "Welcome to Phone Kart";
  printf("*\
           *********************************************************************\n\
           *                                                                   *\n\
           *                                                                   *\n\
           *              ****    { WELCOME }  < USER/ >  ****                 *\n\
           *                                                                   *\n\
           *                                                                   *\n\
           *             ^^^ TO ^^^   -> (PHONE KART ) => {                    *\n\
           *                                                                   *\n\
           *   Platform to SELL and   BUY  Old refurnished Phones }            *\n\
           *                                                                   *\n\
           *   SOURCECODE  ON  GITHUB  UNDER     Apache-2.0 license            *\n\
           ********************************************************************* ");







    char mes5[85] = " Project developed by Divyansh ";
    printf("\n \n \n \n \n       ");
printf("\n    ");
usleep(3000000);
for(int y = 0 ;y<45;y++){

        printf("%c" , mes5[y]);
    usleep(30000);
}
}

// function for configuring
void config(int seconds){
    printf("\n \n \n       ");
    printf("configuring");

    for(int i= 20 ; i<=40;i++){

            usleep(seconds);
            printf(".");
    }

    }

// function for login

void login(){

    //  login user
 char m[45] = "< Please  LOGIN to proceed /> ";


            for(int i = 0 ;i<45 ;i++){
                printf("%c" , m[i]);
                usleep(10000);}

            printf("\n\n\n Enter YOUR NAME   ");
            scanf("%s" , &users[cursor].Name);
            printf("Enter YOUR MobileNumber   ");
            scanf("%s" , &users[cursor].passcode);

            printf("\n\n\n\n\n   ");

            printf("USER LOGGEED IN SUCCESSFULLY !!");
            char mX[45] = "< redirecting to welcome screen.. !!!/> ";

printf("\n\n\n\n\n   ");
            for(int i = 0 ;i<45 ;i++){
                printf("%c" , mX[i]);
                usleep(10000);}
            for(int n = 0;n<50;n++){
        printf("*");
     }welcome_page();
}

// welcome page after login or registering  successful

void welcome_page(){
    printf("\n\n\n     ");
    printf("\n\n\n     ");
     for(int n = 0;n<50;n++){
        printf("*");
     }
     printf("\n");
    char m[45] = "< Welcome";

            for(int i = 0 ;i<45 ;i++){
                printf("%c" , m[i]);
                usleep(10000);}
                printf("%s />",users[cursor].Name);
         printf("\n\n   ");
            printf("ENTER  1 -> SELLING OLD PHONES \n");
            usleep(50000);
            printf("\n\n   ");
            printf("ENTER  2 -> BUYING REFURNISHED PHONES \n");
            usleep(50000);
            printf("\n\n   ");
            printf("ENTER  3 -> MY LISTED PRODUCTS\n");
            printf("\n\n   ");
            printf("ENTER  4 -> LOG OUT \n");
            printf("\n\n   ");
            int ch;

            scanf("%d" , &ch);

            if(ch==1){
                    for(int n = 0;n<50;n++){
        printf("*");
     }
                selling_page();
            }else  if(ch == 2){
                for(int n = 0;n<50;n++){
        printf("*");
     }
                buying_page();
            }
            else if(ch==3){

               sell_pro();
            }
            else if(ch==4){

                logout();
                printf("\n \n");
            }else{
                printf("invalid input");  welcome_page(); }

     for(int n = 0;n<50;n++){
        printf("*");
     }
}



// logout function to handle  logout  screen

void  logout(){
    ++cursor;
     printf("\n\n\n     ");
     for(int n = 0;n<50;n++){
        printf("*");
     }
     printf("\n\n\n     ");
    char m[45] = "< logged out !!/> ";
    for(int i = 0 ;i<45 ;i++){
                printf("%c" , m[i]);
                usleep(10000);}
    printf("\n\n           SEE YOU soon { %s } ",users[cursor-1].Name);


printf("\n\n\n\n\n  ");
      for(int n = 0;n<50;n++){
        printf("*");
     }

     usleep(10000);
     printf("\n\n\n     ");
     printf("\n\n\n\n LAST logged in  USER --> %s " , users[cursor-1].Name );
     printf("\n\n\n     ");

    login();
}

// function to  display selling products of particular

void sell_pro(){
    int flag = 0;
    for(int i =0 ;i<cursor_product;i++){
        if(strcmp(products[i].seller_name , users[cursor].Name) == 0){
            printf("PRODUCT : %s \t SELLER : %s \t RAM : %d \t STORAGE : %d \t PRICE : %d" , products[i].product_name ,products[i].seller_name,products[i].ram, products[i].storage,products[i].price);
            flag=1;
        }
    }
    if(flag!=1){
        printf("\n\n THERE  ARE  NO PRODUCTS  LISTED BY YOU \n\n");
        usleep(50000);
        welcome_page();
    }
}

// add_item for adding  selling  items

void  add_item(){
    printf("\n\n\n\n");
         for(int n = 0;n<50;n++){
        printf("*");
     }
     printf("\n\n\n\n");
    printf("Enter Product name   ");
    scanf("%s" , &products[cursor_product].product_name);
    printf("Enter RAM  ");
    scanf("%d" , &products[cursor_product].ram);
    printf("Enter STORAGE   ");
    scanf("%d" , &products[cursor_product].storage);
    printf("Enter Seller's name  ");
    scanf("%s" , &products[cursor_product].seller_name);
    products[cursor_product].price = fare;

    printf("\n\n\n");
    for(int i=0;i<40;i++){
        printf("*");
    }
    printf("\n\n\n  Following Item's  Were  Added\n\n\n");

    printf("PRODUCT : %s \t SELLER : %s \t RAM : %d \t STORAGE : %d \t PRICE : %d" , products[cursor_product].product_name ,products[cursor_product].seller_name,products[cursor_product].ram, products[cursor_product].storage,products[cursor_product].price);
    ++cursor_product;
    logout();

}

// selling function

void selling_page(){

printf("\n\n\n\n");
 printf("Welcome to the seller's  hub \n\n  Start Selling From Today -->  Reach the Global Audience!!");
 printf("\n\n\n ENTER  1 to start  QUALITY CHECK   ");
 int ch ;
 scanf("%d" , & ch);

 if(ch==1){
        printf("\n\n\n");
 for(int p =0;p<=40;p++){ printf("*"); }
    printf("\n\n\n WELCOME !!  to Quality Check -  GET the  best Price for your Product");

    // returning  the fare  of  the  product
    fare = Quality_check();
    printf("\n\n FARE : %d RS/- \n\n" , fare);
         for(int n = 0;n<50;n++){
        printf("*");
     }
     printf("\n\n\n");
    printf("\n\n Do you want  to Sell this Product \n\n-> ENTER 1 to sell \n\n -> ENTER 2 for MAIN MENU\n\n -> ENTER 3 to LOGOUT ");
    int c ;
    scanf("%d" , &c);
    if(c == 1){
        // coding for  adding item to structure
        add_item();
               }

    else if(c==2){
       welcome_page();
    }
    else{
        logout();
    }
    printf("\n\n\n\n LAST logged in  USER --> %s " , users[cursor].Name );

 }
 else{
    printf("invalid input !!!");
    selling_page();
    printf("\n\n\n");
 }



printf("\n\n\n\n\n");
}

// buying page  to show  products available to buy
void  buying_page(){
    printf("\n\n\n\n      ");
 printf("Welcome to the BUYER's  hub \n\n  GET MOBILE PHONES  AT  CHEAPEST RATES !!");
    printf("\n\n\n\n    ");
    if(cursor_product==0){
        printf("\n\n NO ITEM AVAILABLE \n\n ");
        welcome_page();
    }
    for(int i=0;i<cursor_product;i++){
        printf("\n\n");
         printf("PRODUCT : %s \t SELLER : %s \t RAM : %d \t STORAGE : %d \t PRICE : %d" , products[i].product_name ,products[i].seller_name,products[i].ram, products[i].storage,products[i].price);

    }
    printf("\n\n\n\n      ");
     for(int n = 0;n<50;n++){
        printf("*");
     }
     welcome_page();
    }



// Quality check  function

int Quality_check(){
    printf("\n\nenter  1 -> Iphones \n 2 -> Smartphones \n 3 -> Keypad Phones\n\n");
    int  brand ;
    int ram;
    int storage;
    int usage_days;
    scanf("%d" , &brand);

    if(brand==1){
        // iphone section
        printf("\n\nPROVIDE US  DETAILS FOR IPHONE RESOURCES\n\n");
        printf("\n\nenter RAM  ");
        scanf("%d" , &ram);
         printf("\n\nenter STORAGE in GB  ");
        scanf("%d" , &storage);
         printf("\n\nenter YEARS useage  ");
        scanf("%d" , &usage_days);

        if(ram < 4 && storage < 40 && usage_days > 3){
            return 15000;
        }
        else if(ram > 4 && ram < 50 && storage > 10 && storage< 40 && usage_days > 3){
            return 20000;
        }
        else if(ram > 10 && storage > 60 && usage_days < 3){
            return 30000;
        }
        else{return 10000;}
    }
    else  if(brand == 2){
        //  smartphone  section
        // iphone section
        printf("\n\nPROVIDE US  DETAILS FOR SMARTPHONE RESOURCES\n\n");
        printf("\nenter RAM  ");
        scanf("%d" , &ram);
         printf("\n\nenter STORAGE in GB ");
        scanf("%d" , &storage);
         printf("\n\nenter YEARS useage  ");
        scanf("%d" , &usage_days);

        if(ram < 4 && storage < 40 && usage_days > 3){
            return 8000;
        }
        else if(ram > 4 && ram < 10 && storage > 10 && storage< 40 && usage_days > 3){
            return 9000;
        }
        else if(ram > 10 && storage > 40 && usage_days < 3){
            return 10000;
        }
        else{
            return 5000;
        }
    }
    else  if(brand ==3){
        // keypad  section
        // iphone section
        printf("\n\nPROVIDE US  DETAILS FOR keypad RESOURCES\n\n");

         printf("\n\nEnter YEARS Useage  ");
        scanf("%d" , &usage_days);

        if(usage_days > 3){
            return 150;
        }
        else if(usage_days < 3){
            return 200;
        }
        else {
            return 100;
        }
}
else{
    printf("Invalid choice !!!  ---> Program not directed from here");
    return 0;
}

}
// drivers  code


int main(){

  usleep(700000);
 welcome();
   usleep(800000);
 config(300000);
    usleep(7000000);


  login();

}
