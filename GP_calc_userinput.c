#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
/* A program to calculate the CGPA of an Electronic Eng student for 1st and 2nd Year */
//prototype declarations
int lettergrade(char*);
int error(int*);
void fnk(char[]);
int main(void) {
    int year,semester,sem=0,nc,gv;
    float values[50];
    char subj[15];
    char g;
    char choice;
    float sum,a=0,j=0;
    float GP,CGPA;
    int UL0,UL;
    printf("\n\nThis is a program to calculate the CGPA of a Nigerian student for up to 25 years of study\n\n*************************** If YoU aRe sTiLL iN sChOOl fOr MoRe tHaN 25 YeArs iDk WhAt yOu'Re DoINg *************************************\n\n");
    do {
        printf("Year of study: ");
        scanf("%d",&year);
        error(&year);
        while(1){
            printf("Semester {Select as [1] or [2]}: ");
            scanf("%d",&semester);
			if(semester== 1 ){
				break;
			} else if(semester== 2){
				break;
			}
			printf("Select a valid semester! [select 1st as '1' and 2nd as '2']\n");
			fflush(stdin);
        }
        printf("No. of courses offered: ");
        scanf(" %d", &nc);
        error(&nc);
        printf("Total unit load: ");
        scanf(" %d",&UL);
        error(&UL);
        printf("Enter the course code, grade and unit load accordingly...\n");
        
        for(int i=sem; i<=sem; i++) {
            sum=0;
            for(int i=1; i<=nc; i++) {
                fflush(stdin);
                printf("Course Code: ");
                fgets(subj,15,stdin);
                fnk(subj);//this is a fxn that gets rid of the newline from fgets -proudly copied from stack-
                printf("Grade: ");
                scanf(" %c",&g);
                gv=lettergrade(&g);
                printf("Unit Load: ");
                scanf(" %d",&UL0);
                error(&UL0);
                sum+=(gv*UL0);
            }
        GP=sum/UL;
        printf("Your GP for semester %d of year %d is %.3f!\n",semester,year,GP);
        values[i]=GP;
        a+=values[i];
        sem++;
        j++;
        CGPA=a/sem;
        printf("Your CGPA after %d semester(s)(%.1f year(s) of study) is %.3f",sem,j/2,CGPA);
        printf("\nDo you want to calculate for another semester?[y/n]: ");
        fflush(stdin);
        scanf(" %c",&choice);
        break;
        /*while(choice!= 'y'||'n') {
            printf("Invalid choice...select either 'y' or 'n'");
            printf("\nDo you want to calculate for another semester?[y/n]: ");
            scanf("%c",&choice);
        }*/
        }
        
    }  while(choice =='y');
    printf("Thank you for using GP calculator!\n");
    printf("press any key to exit...\n");
    getch();
    return 0;
}
int lettergrade (char* x) {
    char retry;
    int gv,k;
redo:
switch(*x) {
    case 'A':
    case 'a':
        gv=5;
        break;
    case 'B':
    case 'b':
        gv=4;
        break;
    case 'C':
    case 'c':
        gv=3;
        break;
    case 'D':
    case 'd':
        gv=2;
        break;
    case 'E':
    case 'e':
        gv=1;
        break;
    case 'F':
    case 'f':
        gv=0;
        break;
    default:
        
        printf("Error! select a valid grade!\n");
        printf("Grade: ");
        fflush(stdin);
        scanf(" %c",&x);
        goto redo;
    }

    return gv;
}
int error(int* a) {
    //fflush(stdin);
    while(*a<1) {
        printf("Enter a valid number!\n: ");
        fflush(stdin);
        scanf(" %d",&a);
       // fflush(stdin);
    }
    return *a;
}
void fnk(char a[]){
    size_t sl = strlen(a);
    if(sl > 0 && a[sl - 1] == '\n'){
       a[sl - 1] = '\0';
    }
}