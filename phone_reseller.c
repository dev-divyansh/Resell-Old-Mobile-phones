#include<stdio.h>
#include<conio.h>
#include<unistd.h>
#include<stdlib.h>
// defining our own datatype to store users name and passcode

struct dls {
    int mobilenumber;
    int passcode;
};

struct dls users[30];
int cursor = 0;

// these for  storing users credentials
int Number;
int password;
// function to handle registration of new user


void register_user(int number , int Passcode){

        users[cursor].mobilenumber = number;
    users[cursor].passcode = Passcode;
    ++cursor;

    printf("User registered  successful..");

    printf("\n \n \n       ");
    printf("redirecting to welcome page...");

    for(int i= 20 ; i<=40;i++){

            usleep(3000);
            printf(".");
    }

}

// function to print welcome message
void welcome(){
    char mes1[21] = "Welcome to Phone Kart";
    char mes2[45] = "Platform to 'BUY' & 'SELL' --> OLD  PHONES ";
    char c[30] = "Glad to see You ! back !!!";
    char mes5[85] = "Project by Divyansh , Liza , Sargam";
    printf("\n \n \n \n \n       ");
    for(int x = 0; x<22;x++){

    printf("%c" , mes1[x] );
    usleep(30000);
}
       printf("\n \n           ");
usleep(500000);
for(int y = 0 ;y<45;y++){

        printf("%c" , mes2[y]);
    usleep(30000);
}printf("\n \n \n \n            ");
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
    char m[45] = "< Please  LOGIN to proceed /> ";

            for(int i = 0 ;i<45 ;i++){
                printf("%c" , m[i]);
                usleep(10000);}

            printf("Enter  Phone Number");
            scanf("%d" , &Number);
            printf("\n\n YOUR  PASSWORD");
            scanf("%d" , &password);

            // checking if password is correct or not

            for(int j = 0 ; j<30 ;j++){
                if(users[j].mobilenumber == Number){
                    if(users[j].passcode == password){
                        printf("\n\n LOGIN SUCCESSFUl");
                         printf("redirecting to welcome page...");

                        for(int i= 20 ; i<=40;i++){

                                usleep(3000);
                                    printf(".");
                            }
                        welcome_page(); // redirecting to welcome page  after successful login
                    }
                    else{
                        printf("INCORRECT PASSWORD \n");
                        login();
                    }
                }
            }
}

// welcome page after login or registering  successful

void welcome_page(){
    printf("\n\n\n     ");
    char m[45] = "< Welcome USER /> ";

            for(int i = 0 ;i<45 ;i++){
                printf("%c" , m[i]);
                usleep(10000);}
         printf("\n\n   ");
            printf("ENTER  1 -> SELLING OLD PHONES \n");
            usleep(50000);
            printf("ENTER  2 -> BUYING REFURNISHED PHONES \n");
            usleep(50000);
            printf("ENTER  3 -> LOG OUT \n");
            int ch;
            scanf("%d" , &ch);

            if(ch==1){
                printf("Sell old phones");
            }else  if(ch == 2){
                printf("Buy old phones");
            }else{
                printf("BYE  !!!  you are  logged out");
            }
}



// drivers  code
int main(){

  usleep(700000);
 welcome();
   usleep(800000);
 config(300000);
    usleep(7000000);

    printf("\n \n \n       ");
    char m[45] = "< Please  REGISTER to proceed /> ";

    for(int i = 0 ;i<45 ;i++){
        printf("%c" , m[i]);
        usleep(10000);}

    printf("\n\n\n  ");

    printf("Enter  Phone Number");
    scanf("%d" , &Number);
    printf("\n\nSET YOUR  PASSWORD");
    scanf("%d" , &password);

    // checking  if  user  is registered
    for(int i = 0 ;i<30;i++){
        if(users[i].mobilenumber == Number){
            printf("Number is already registered !!! - please login");
            printf("\n \n   ");
            printf("loading login page.....");

            for(int i= 20 ; i<=40;i++){

                usleep(3000);
                printf(".");
            }
           login();
        }
        else{

            printf("YOU ARE  SUCCESSFULLY REGISTERED ");
            register_user(Number , password);
            welcome_page();
            break;
        }
    }



}
