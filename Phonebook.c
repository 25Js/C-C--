#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
//struct initialization
struct Phonebook {
    char f_name[20];
    char l_name[20];
    unsigned long long int number[100];
};
struct Phonebook contact[1000];
int a,c=0,sn;
char choice,owner[50];
//prototype declearations
char error(char*);
void save(void);
void display(void);
void update(struct Phonebook*);
void delete(int*);
void fnk(char[]);

int main(void) {
    int x,k=0;
    printf("How would you like to be addressed?\n");
    fgets(owner,50,stdin);
    fnk(owner);//this is a fxn that gets rid of the newline from fgets -proudly copied from stack-
    printf("Welcome %s! to your phonebook ✧◝(⁰▿⁰)◜✧\n",owner);
    printf("You have no contacts in your phonebook...would you like to save a contact?[y/n]: ");
    scanf("%[^\n]%*c",&choice);
    //error(&choice);//a fxn that prevents abuse of the normal running of code...but it is with errors -delete the forward slashes to make it executable-
    if(choice=='y') {
        save();
    }
while(k==0){
    printf("What would you like to do?\n\t1. Save a contact\n\t2. Update existing contact\n\t3. View Contacts\n\t4. Delete contact\n\t5. Exit\n\t:");
    scanf(" %d",&x);
    switch(x) {
        case 1:
            save();
            break;
        case 2:
            if(c==0) {
                printf("You have no contacts in your phonebook, Save some first...\n");
                continue;
            }
            printf("Select the contact to update\n");
            display();//prints the contacts in an ordered line by line format
            printf("Contact serial number: ");
            scanf(" %d",&sn);
            //saves the serial number and passes it to the fxn
            update(&contact[sn]);
            break;
        case 3:
            if(c==0) {
                printf("You have no contacts in your phonebook, Save some first...\n");
                continue;
            }
            display();
            continue;
        case 4:
            if(c==0) {
                printf("You have no contacts in your phonebook, Save some first...\n");
                continue;
            }
            printf("Select a contact to delete\n");
            display();
            printf("Contact serial number: ");
            scanf(" %d",&sn);
            delete(&sn);
            break;
        case 5:
            k=1;
            break;
        default:
                printf("Error! select a valid option\n");
                fflush(stdin);
        }
}
printf("Thank you for using %s's phonebook! Make sure to check back next time!!\n", owner);
printf("press any key to exit...\n");
getch();
return 0;
}
void save(void) {
    c++;
    for(int i=c; i<=1000; i++) {
        fflush(stdin);
        printf("First name: ");
        fgets(contact[i].f_name,20,stdin);
        fnk(contact[i].f_name);
        printf("Last name: ");
        fgets(contact[i].l_name,20,stdin);
        fnk(contact[i].l_name);
        printf("Phone number: ");
        scanf(" %llu",&contact[i].number[i]);
        printf("You have saved a contact!\n");
        display();
        printf("Would you like to save a contact?[y/n]: ");
        scanf(" %c",&choice);
        //error(&choice);
        if(choice=='y') {
            c++;
            continue;
        } else {
            break;
        }
    }
}
void update(struct Phonebook* cptr) {
    int x,k=0;
        while(k==0){
            printf("What would you like to update?\n1. First name\n2. Last name\n3. Phone number\n4. Exit\n: ");
            scanf(" %d",&x);
            switch(x){
            case 1:
                fflush(stdin);
                printf("Enter new First name: ");
                fgets(cptr->f_name,20,stdin);
                fnk(cptr->f_name);
                printf("Successfully updated!\n");
                printf("Would you like to update anything else?[y/n]: ");
                scanf(" %c",&choice);
                //error(&choice);
                if(choice=='y') {
                    continue;
                } else {
                    k=1;
                }
                break;
            case 2:
                fflush(stdin);
                printf("Enter new Last name: ");
                fgets(cptr->l_name,20,stdin);
                fnk(cptr->l_name);
                printf("Successfully updated!\n");
                printf("Would you like to update anything else?[y/n]: ");
                scanf(" %c",&choice);
                //error(&choice);
                if(choice=='y') {
                    continue;
                } else {
                    k=1;
                }
                break;
            case 3:
                printf("Enter new Phone number: ");
                scanf(" %llu",&cptr->number[sn]);
                printf("Successfully updated!\n");
                printf("Would you like to update anything else?[y/n]: ");
                scanf(" %c",&choice);
                //error(&choice);
                if(choice=='y') {
                    continue;
                } else {
                    k=1;
                }           
                break;
            case 4:
                k=1;
                break;
            default:
                    printf("Error! select a valid option\n");
                    fflush(stdin);
                }
            }
        }
void display(void) {
    printf("\t\t%s's phonebook\nContacts:\n",owner);
    for(int i=1; i<=c; i++) {
            printf("%d. %s %s\n   %llu\n",i, contact[i].f_name, contact[i].l_name, contact[i].number[i]);
        }
}
void delete(int* sn) {
    while(*sn>c || *sn<1){
        printf("Select a valid serial number!\n");
         printf("Contact serial number: ");
        scanf(" %d",&sn);
        fflush(stdin);
    }
    for(int i=*sn;i<=c-1;i++) {
        contact[i]=contact[i+1];
    }
    c--;
    printf("You have deleted a contact!\n");
}
char error(char* ce) {
    int k;
    while(1){
		if(*ce == 'y' ){
			break;
		} else if(*ce == 'n'){
				break;
        } else{
            printf("Error! select either 'y' or 'n'");
            fflush(stdin);
            printf("\n: ");
            scanf("%c",&ce);
        }
    }
    return *ce;
}
void fnk(char a[]){
    size_t sl = strlen(a);
    if(sl > 0 && a[sl - 1] == '\n'){
       a[sl - 1] = '\0';
    }
}