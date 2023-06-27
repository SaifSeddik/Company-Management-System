
//Author : Saif mohamed , Rana zayed , Omar essam
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int day,mon,year;
}date;
typedef struct{
    int id;
    float salary;
    char first_name[20],last_name[20],address[50],phone[16],email[25];
    date dob;

}employee;
employee e[100]; // global array of employees
int count;
int evalid(char *n){ //  validation for email
    int v=0,y=0;
    int ca=0,cb=0;    while(n[y]!= '\0'){
        if((n[y]>='a' && n[y]<='z')||(n[y]>='A' && n[y]<='Z')||(n[y]>='0' && n[y]<='9')){
                    v=1;
                    y++;
                    continue;
                }
        else if(n[y]== '@'){
                    if(!((n[y+1]>='a' && n[y+1]<='z')||(n[y+1]>='A' && n[y+1]<='Z'))||(n[y]==' ')){
                        v=0;
                        break;
                    }
                    else{
                        v=1;
                        ca++;
                        y++;}

                }
                else if(n[y]=='.'){
                    if(!((n[y+1]>='a' && n[y+1]<='z')||(n[y+1]>='A' && n[y+1]<='Z'))){
                        v=0;
                        break;
                    }
                    else if(ca != 1){
                        v=0;
                        break;
                    }
                    else{
                        v=1;
                        cb++;
                        y++;}
                }
                else{
                    v=0;
                    break;
                }

               }

    if(ca!=1 && v !=0 ){
             v=0;
         }
    if(cb!=1 && v!=0){
             v=0;

        }
    return v;
}
int nvalid(char *s){
    int y=0,v=1;
    while(s[y]!= '\0'){
        if(!((s[y]>='a' && s[y]<='z')||(s[y]>='A' && s[y]<='Z'))){
            v=0;
            break;
        }
        y++;
    }
    return v;
}
void idvalidate(char *s,int i){ //  validation for id to check if there is a letere
    int y=0;
    while(s[y]!= '\0'){
        if(!((s[y]>='0')&&(s[y]<='9'))){ // id are consist only from numbers
            printf("employee %d has an invalid ID: %s\n",i+1,s);
            printf("please enter another valid ID :");
            scanf("%s",s);
            y=-1;
        }
        y++;
    }
    int id=atoi(s);
    for(int j=0;j<=count;j++){
        if(e[j].id==id){
            printf("employee %d has the same id as employee %d %s\n",i+1,j+1,s);
            printf("please enter another valid ID :");
            scanf("%s",s);
            idvalidate(s, i);
        }

    }
}
void salvalidate(char *salary,int i){ //validation for salary to check if its a number
    int cdot=0;
    int y=0;
    while(salary[y]!='\0'){
        if((!((salary[y]>='0' && salary[y]<='9') || (salary[y]=='.')))){ // to make sure that the salary consist from numbers and dot point
            printf("employee %d has an invalid salary: %s\n",i+1,salary);
            printf("please enter a valid salary:");
            scanf("%s",salary);
            y=-1;
        }
        else if(salary[y]=='.'){
            cdot++;
        }

        y++;
    }
    if(cdot>1){
        printf("employee %d has an invalid salary: %s\n",i+1,salary);
        printf("please enter a valid salary:");
        scanf("%s",salary);
        salvalidate(salary, i);
    }
}
void pvalidate(char *phone,int i){ //validation for phone number
    int y=0;



    while(phone[y]!= '\0'){ // to make sure that the phone number has only digits
        if(!(phone[y]>='0' && phone[y]<='9'))
        {
            if((phone[y]=='+')&&(y==0)){
                y++;
                continue;
            }
            else{
            printf("employee %d has an invalid phone number: %s\n",i+1,phone);
            printf("please enter a valid phone number:");
            scanf("%s",phone);
                y=0;}
        }
        else{
            y++;
        }}
        if(phone [0]!= '+' && phone[0]!= '0'){ // to check if the phone number start by 0 or +
            printf("employee %d has an invalid phone number: %s\n",i+1,phone);
            printf("please enter a valid phone number:");
            scanf("%s",phone);
            pvalidate(phone, i);
        }




}

void LOAD2(FILE *f,int *ecount){

    f=fopen("company.txt","r+");
    if(f == NULL){
        printf("error !!");}
    int i=0,j=0;
    char c[100];
    char *id,*last={'o','\0'},*first={'o','\0'},*salary={'o','\0'},*day={'o','\0'},*mon={'o','\0'},*year={'o','\0'},*address={'o','\0'},*email={'o','\0'},*phone={'o','\0'},temp[50]={'o','\0'};
    char d[3]=",-\n";
    char d2[4]=",-\n ";

    int z=1;
    rewind(f);
    fgets(c,99,f);
    id= strtok(c, d2);
    while((!feof(f))&& (id != NULL)&&(first!=NULL)&&(last!=NULL)&&(phone!= NULL)&&(email != NULL)&&(address != NULL)&&(salary != NULL)&&(day != NULL)&&(mon != NULL)&&(year != NULL)){

        switch (z) {
            case 1:

                strcpy(temp,id);
                idvalidate(temp ,i);
                j=strlen(id);
                e[i].id = atoi(temp);
                z=(z+1)%10;
                    last = strtok(NULL, d2);
                break;
            case 2:

                j = j+strlen(last);
                strcpy(e[i].last_name , last);
                int n = nvalid(e[i].last_name);
                while(!(n)){

                    printf("employee %d has an invalid last name: %s\n",i+1,e[i].last_name);
                    printf("please enter a valid name:");
                    scanf("%s",e[i].last_name);
                    n= nvalid(e[i].last_name);
                    }


                z=(z+1)%10;
                first = strtok(NULL,d2);
                break;
            case 3:

                j = j+strlen(first);
                strcpy(e[i].first_name,first);
                n= nvalid(e[i].first_name);
                while(!(n)){

                    printf("employee %d has an invalid last name: %s\n",i+1,e[i].first_name);
                    printf("please enter a valid name:");
                    scanf("%s",e[i].first_name);
                    n= nvalid(e[i].first_name);
                    }
                z=(z+1)%10;
                salary = strtok(c+j+3,d2);

                break;
            case 4:

                j = j+strlen(salary);
                strcpy(temp,salary);
                salvalidate(temp,i);
                e[i].salary = atof(temp);

                z=(z+1)%10;
                day = strtok(c+j+4,d2);

                break;
            case 5:
                strcpy(temp, day);
                j = j+strlen(day);
                int y=0;
                while(temp[y]!='\0'){
                    if(!(temp[y]>='0' && temp[y]<='9')){
                        printf("employee %d has an invalid date(day): %s\n",i+1,temp);
                        printf("please enter a valid date(day):");
                        scanf("%s",temp);
                        y=-1;
                    }
                    y++;
                }

                e[i].dob.day =atoi(temp);
                z=(z+1)%10;
                mon = strtok(c+j+5,d2);

                break;
            case 6:
                strcpy(temp, mon);
                j = j+strlen(mon);

                y=0;
                while(temp[y]!='\0'){
                    if(!(temp[y]>='0' && temp[y]<='9')){
                        printf("employee %d has an invalid date(months): %s\n",i+1,temp);
                        printf("please enter a valid date(months):");
                        scanf("%s",temp);
                        y=-1;
                    }
                    y++;
                }

                e[i].dob.mon =atoi(temp);
                z=(z+1)%10;
                year = strtok(c+j+6,d2);

                break;
            case 7:
                strcpy(temp, year);
                j = j+strlen(year);

                y=0;
                while(temp[y]!='\0'){
                    if(!(temp[y]>='0' && temp[y]<='9')){
                        printf("employee %d has an invalid date(year): %s\n",i+1,temp);
                        printf("please enter a valid date(year):");
                        scanf("%s",temp);
                        y=-1;
                    }
                    y++;
                }

                e[i].dob.year =atoi(year);
                z=(z+1)%10;
                address = strtok(c+j+7, d);

                break;
            case 8:
                strcpy(e[i].address,address);
                j = j+strlen(address);

                z=(z+1)%10;
                phone = strtok(c+j+8, d2);
                break;
            case 9 :

                j = j+strlen(phone);
                strcpy(e[i].phone , phone);
                pvalidate(e[i].phone , i);

                z=(z+1)%10;
                email = strtok(c+j+9, d2);

                break;
            case 0 :


                j = j+strlen(email);
                strcpy(e[i].email , email);
                while(!(evalid(e[i].email))){
                    printf("employee %d has an invalid email : %s \n",i,e[i].email);
                    printf("please enter another email:");
                    scanf("%s",e[i].email);}



                z=(z+1)%10;
                i++;

                    fgets(c,99,f);
                    id=strtok(c, d2);


                break;

            default:
                break;
        }
    }
    *ecount=i-1;
}

void LOAD(FILE *f,int *ecount){
    f=fopen("company.txt","r");
    if(f == NULL){
        printf("error !!");}
    int i=0,j=0;
    char c[100][100];

    rewind(f);
    char id[10],salary[10],day[3],mon[3],year[3];
    for(i=0;!(feof(f));i++){

        id[j]= getc(f);
        while(id[j] != ','){
            j++;
            id[j] = getc(f);
        }
        id[j]='\0';
        e[i].id= atoi(id);
        j=0;
        e[i].last_name[j]= getc(f);
        while(e[i].last_name[j] != ','){
            j++;
            e[i].last_name[j] = getc(f);
        }
        e[i].last_name[j]= '\0';
        j=0;
        e[i].first_name[j]= getc(f);
        while(e[i].first_name[j] != ','){
            j++;
            e[i].first_name[j] = getc(f);
        }
        e[i].first_name[j]= '\0';
        j=0;
        salary[j]= getc(f);
        while(salary[j] != ','){
            j++;
            salary[j] = getc(f);
        }
        salary[j]= '\0';
        e[i].salary= atof(salary);
        j=0;
        day[j]= getc(f);
        while(day[j] != '-'){
            j++;
            day[j] = getc(f);
        }
        day[j]= '\0';
        e[i].dob.day= atoi(day);
        j=0;
        mon[j]= getc(f);
        while(mon[j] != '-'){
            j++;
            mon[j] = getc(f);
        }
        mon[j]= '\0';
        e[i].dob.mon= atoi(mon);
        j=0;
        year[j]= getc(f);
        while(year[j] != ','){
            j++;
            year[j] = getc(f);
        }
        year[j]= '\0';
        e[i].dob.year= atoi(year);
        j=0;
        e[i].address[j] = fgetc(f);
        while(e[i].address[j] != ','){
            j++;
            e[i].address[j] = fgetc(f);
        }
        e[i].address[j]= '\0';
        j=0;
        e[i].phone[j] = fgetc(f);
        while(e[i].phone[j] != ','){
            j++;
            e[i].phone[j] =fgetc(f);
        }
        e[i].phone[j]= '\0';
        j=0;
        e[i].email[j] = fgetc(f);
        while(e[i].email[j] != '\n' &&  !(feof(f))){
            j++;
            e[i].email[j] =fgetc(f);
        }
        e[i].email[j]= '\0';
        j=0;

              }
    *ecount= i-1;
}



void add(int *count) // function to add new employee to the list
{
    (*count)++;
    int y=0;
    char id[10],salary[10],date[10];
    printf("Enter the information of employee %d:\n",(*count)+1);
    printf("employee ID:");
    scanf("%s",id);
    idvalidate(id, *count);
    e[*count].id= atoi(id);
    printf("employee last name:");

    scanf("%s",e[*count].last_name);
    while(!(nvalid(e[*count].last_name))){
        printf("employee %d has an invalid name : %s \n",(*count)+1,e[*count].last_name);
        printf("please enter another name:");
        scanf("%s",e[*count].last_name);
    };
    printf("employee first name:");
    scanf("%s",e[*count].first_name);
    while(!(nvalid(e[*count].first_name))){
        printf("employee %d has an invalid name : %s \n",(*count)+1,e[*count].first_name);
        printf("please enter another name:");
        scanf("%s",e[*count].first_name);
    };
    printf("employee salary:");
    scanf("%s",salary);
    salvalidate(salary, *count);

    e[*count].salary = atof(salary);
    printf("employee address:");
    getchar();
    gets(e[*count].address);

    printf("employee phone number:");
    scanf("%s",e[*count].phone);
    pvalidate(e[*count].phone, *count);


    printf("employee E-mail:\n");
    scanf("%s",e[*count].email);
    while(!(evalid(e[*count].email))){
        printf("employee %d has an invalid email : %s \n",(*count)+1,e[*count].email);
        printf("please enter another email:");
        scanf("%s",e[*count].email);
    }

    printf(" Enter employee date of birth:\n");
    printf("Day:");
    scanf("%s",date);
    e[*count].dob.day = atoi(date);
    y=0;
    while(date[y]!= '\0'){
        if(!((date[y]>='0' && date[y]<='9'))||((e[(*count)].dob.day<=0)||(e[(*count)].dob.day>31))){
            printf("employee %d has an invalid date (day): %s\n",(*count)+1,date);
            printf("please enter a valid date (date):");
            scanf("%s",date);
            e[*count].dob.day = atoi(date);
            y=0;
        }
        else{
            y++;
        }

    }

    y=0;
    printf("Month:");
    scanf("%s",date);
    e[*count].dob.mon= atoi(date);
    while(date[y]!= '\0'){
        if(!((date[y]>='0' && date[y]<='9'))||((e[(*count)].dob.mon<=0)||(e[(*count)].dob.mon>12))){
            printf("employee %d has an invalid date (month): %s\n",(*count)+1,date);
            printf("please enter a valid date (month):");
            scanf("%s",date);
            e[*count].dob.mon= atoi(date);
            y=0;
        }
        else{
            y++;
        }

    }
    y=0;
    printf("Year:");
    scanf("%s",date);
    e[*count].dob.year= atoi(date);
    while(date[y]!= '\0'){
        if(!((date[y]>='0' && date[y]<='9'))||((e[(*count)].dob.year<=1900)||(e[(*count)].dob.year>2010))){
            printf("employee %d has an invalid date (year): %s\n",(*count)+1,date);
            printf("please enter a valid date (year):");
            scanf("%s",date);
            e[*count].dob.year= atoi(date);
            y=0;
        }
        else{
            y++;
        }

    }



}
void SORT_BY_DOB(int count) //function to sort the employees by date of birth
{
    int i,j ;
    employee temp ;

    for (i = 0; i <= count ; i++)
    {
        for (j = i+1; j <= (count); j++)
        {


            if (e[i].dob.year > e[j].dob.year )
            {
                temp = e[i];
                e[i] = e[j];
                e[j] = temp;

            }
            else  if (e[i].dob.year == e[j].dob.year )
            {
                if (e[i].dob.mon >e[j].dob.mon)
                {
                    temp = e[i];
                    e[i] = e[j];
                    e[j] = temp;

                }
                else  if (e[i].dob.mon  == e[j].dob.mon)
                {
                    if (e[i].dob.day >e[j].dob.day)
                    {
                        temp = e[i];
                        e[i] = e[j];
                        e[j] = temp;
                    }

                }
            }



        }

    }
}
void SORT_BY_LAST_NAME( int count)  //function to sort the employees by last namee
{
    int i,j ;
    employee temp ;

    for (i = 0; i <= count ; i++)
    {
        for (j = i+1; j <= (count); j++)
        {


        if (strcasecmp(e[i].last_name,e[j].last_name) > 0)
        {

            temp = e[j];
            e[j] = e[i];
            e[i] = temp;

        }
        }
    }


}

void SORT_BY_SALARY(int count) // function to sort the employees by salary
{
    int i  , j;
    employee temp ;


for (i = 0; i <= count ; i++)
    {
        for (j = i+1; j <= (count); j++)
        {
            if (e[i].salary< e[j].salary)
            {
                temp = e[j];
                e[j] = e[i];
                e[i] = temp;
            }
        }
    }
}


void PRINT (int count ) // function to print the list by 4 ways : last name, date of birth , salary , unsorted
{
    int algorithm ;
    printf("please enter the number of sorting algorithm\n(1) : sort by last name \n(2) : sort by DOB \n(3) : sort by salary \n(4) : unsorted \n");
    scanf("%d", &algorithm);


    while(1){
    if (algorithm == 1)
    {
        SORT_BY_LAST_NAME(count);
        break;
    }
    else if (algorithm == 2)
    {
        SORT_BY_DOB(count);
        break;
    }
    else if  (algorithm == 3)
    {
        SORT_BY_SALARY(count);
        break;
    }
    else if( algorithm == 4){
        break;
    }
    else
    {
        printf("please enter a vailid algorithm ") ;
        scanf("%d",&algorithm);
    }}
    for (int i=0; i<=count; i++)
{
    printf("Employee no %d:\n",i+1);
    printf("id:%d\nlast name:%s\nfirst name:%s\nsalary:%f\ndate of birth:%d-%d-%d\naddress:%s\nphone number:%s\nemail:%s\n",e[i].id,e[i].last_name,e[i].first_name,e[i].salary,e[i].dob.day,e[i].dob.mon,e[i].dob.year,e[i].address,e[i].phone,e[i].email);
    printf("           * * *\n");

}
}
void Delete (int *count) // function for deleting an employee by his first and last name
{int i,j,flag=0;
    char first[20],last [20];
    printf("enter the last name of the employee you desire to delete:");
    scanf("%s",last);
    printf("enter the first name of the employee you desire to delete:");
    scanf("%s",first);
    for(i=0;i<=(*count);i++)
    {
        if((strcasecmp(e[i].first_name,first)==0)&&(strcasecmp(e[i].last_name,last)==0))
        {
            flag=1;

            for(j=i;j<=(*count)-1;j++)
            {

             e[j] = e[j+1];

            }
            i--;
            (*count)--;
        }

    }
    if(flag==0){
        printf("no one with first name:%s and last name:%s\n",first,last);
    }

}
void modify(int count) // function to modify any information for the employee
{ int i,c=0,searchint;
    char id[10],date[10],salary[10],searchID[10];

    printf("Enter ID of employee to be modified:\n");
    scanf("%s",searchID);
    int y=0;
    while(id[y]!='\0'){
        if(!((id[y]>='0')&&(id[y]<='9'))){
            printf("please enter a valid id:\n");
            scanf("%s",id);
            y=-1;
        }
        y++;
    }
    for(i=0;i<=(count);i++){
        searchint = atoi(searchID);
     if(e[i].id == searchint) {
         c=1;
         break;
}

}
    if(c){

        printf("Employee no %d:\n",i+1);
        printf("id:%d\nlast name:%s\nfirst name:%s\nsalary:%f\ndate of birth:%d-%d-%d\naddress:%s\nphone number:%s\nemail:%s\n",e[i].id,e[i].last_name,e[i].first_name,e[i].salary,e[i].dob.day,e[i].dob.mon,e[i].dob.year,e[i].address,e[i].phone,e[i].email);
        printf("           * * *\n");

        printf(" \n");
        printf("enter new ID:");


        scanf("%s",id);
        idvalidate(id, i);
        e[i].id = atoi(id);
        printf("new employee last name:");
        scanf("%s",e[i].last_name);
        while(!(nvalid(e[i].last_name))){
            printf("employee %d has an invalid last name: %s\n",i+1 , e[i].last_name);
            printf("please enter a valid name:");
            scanf("%s",e[i].last_name);
        }

        printf("new employee first name:");
        scanf("%s",e[i].first_name);
        while(!(nvalid(e[i].first_name))){
            printf("employee %d has an invalid first name: %s\n",i+1 , e[i].first_name);
            printf("please enter a valid name:");
            scanf("%s",e[i].first_name);
        }



        printf("employee salary:");
        scanf("%s",salary);
        salvalidate(salary, i);
        e[i].salary = atof(salary);
        printf("Enter new employee date of birth:\n");
        printf("Day:");
            scanf("%s",date);
        e[i].dob.day= atoi(date);
            y=0;
            while(date[y]!='\0'){
                if(!(date[y]>='0' && date[y]<='9')||((e[i].dob.day<=0)||(e[i].dob.day>31))){
                    printf("employee %d has an invalid date(day): %s\n",i+1,date);
                    printf("please enter a valid date(day):");
                    scanf("%s",date);
                    e[i].dob.day= atoi(date);
                    y=-1;
                }
                y++;
            }

        printf("Month:");
        scanf("%s",date);
        e[i].dob.mon= atoi(date);
            y=0;
            while(date[y]!='\0'){
                if(!(date[y]>='0' && date[y]<='9')||((e[i].dob.mon<=0)||(e[i].dob.mon>12))){
                    printf("employee %d has an invalid date(month): %s\n",i+1,date);
                    printf("please enter a valid date(month):");
                    scanf("%s",date);
                    e[i].dob.mon= atoi(date);
                    y=-1;
                }
                y++;
            }

        printf("Year:");

            scanf("%s",date);
        e[i].dob.year = atoi(date);
            y=0;
            while(date[y]!='\0'){
                if(!(date[y]>='0' && date[y]<='9')||(e[i].dob.year<1900||e[i].dob.year>=2010)){
                    printf("employee %d has an invalid date(year): %s\n",i+1,date);
                    printf("please enter a valid date(year):");
                    scanf("%s",date);
                    e[i].dob.year = atoi(date);
                    y=-1;
                }
                y++;
            }


        printf("employee address:");
        getchar();
        gets(e[i].address);


        printf("employee phone number:");
        scanf("%s",e[i].phone);
        pvalidate(e[i].phone, i);


        printf("employee E-mail:\n");
        scanf("%s",e[i].email);
        while(!(evalid(e[i].email))){
            printf("employee %d has an invalid email : %s \n",i+1,e[i].email);
            printf("please enter another email:");
            scanf("%s",e[i].email);
        }


    }
    else{
        printf("no employee found with this id");
    }
}
void Query (int *ecount)
{ char search[20];
int counter=0;
    printf("\nTo look up information about a specific Employee\n");
    printf("Supply the employees last name : \n");
    scanf("%s",search);
    for (int i=0;i<=(*ecount);i++)
   { if (strcasecmp(e[i].last_name,search)==0)
   {

       printf("Employee no %d:\n",i+1);
       printf("id:%d\nlast name:%s\nfirst name:%s\nsalary:%f\ndate of birth:%d-%d-%d\naddress:%s\nphone number:%s\nemail:%s\n",e[i].id,e[i].last_name,e[i].first_name,e[i].salary,e[i].dob.day,e[i].dob.mon,e[i].dob.year,e[i].address,e[i].phone,e[i].email);
       printf("           * * *\n");


        counter++;
   }
}
if(counter==0)
    printf("No records match your need ");
}
int save(FILE *f,int count){
    fclose(f);
    f=fopen("company.txt", "w+");
    int i=0;
    for(i=0;i<=count;i++){
        fprintf(f,"%d,%s,%s,%.3f,%d-%d-%d,%s,%s,%s",e[i].id,e[i].last_name,e[i].first_name,e[i].salary,e[i].dob.day,e[i].dob.mon,e[i].dob.year,e[i].address,e[i].phone,e[i].email);
            fprintf(f,"\n");
    }


    return 1;
}
void quit(FILE *fp){
    fclose(fp);
    exit(0);

}

int main() {

    FILE* fp;
    printf("                    *COMPANY MANAGEMENT SYSTEM*\n\n");
    printf("Employees personal informations:\n");
    count=0;
    LOAD(fp,&count); //TRY LOAD2 IF YOU HAD AN ERROR
    for (int i=0; i<=count; i++)
{

    printf("%d,%s,%s,%f,%d-%d-%d,%s,%s,%s",e[i].id,e[i].last_name,e[i].first_name,e[i].salary,e[i].dob.day,e[i].dob.mon,e[i].dob.year,e[i].address,e[i].phone,e[i].email);
    printf(" \n");


}
    printf("\nOPERATIONS MENU:\nTo SEARCH  for an employee *press 1*\nTo ADD an employee *press 2*\nTo DELETE an employee *press 3*\nTo MODIFY the data of an existing employee *press 4*\nTo PRINT(sorted or unsorted) *press 5*\nTo SAVE *press 6*\nTo EXIT *press 7*\nPRESS ENTER TO START\n");
    char c;
    int s=0;
    do{
        c=getchar();
        printf("\nChoose an option\nSEARCH:1\nADD:2\nDELETE:3\nMODIFY:4\nPRINT:5\nSAVE:6\nEXIT:7\n");
        scanf("%c",&c);
        switch (c) {
            case '1':
                Query(&count);
                break;
            case '2':
                add(&count);
                s=0;
                break;
            case '3':
                Delete(&count);
                s=0;
                break;
            case '4':
                modify( count);
                s=0;
                break;
            case '5':
                PRINT(count);
                s=0;
                break;
            case '6':
                s = save(fp,count);
                break;
            case '7':
                if(!(s)){
                    printf("\n\nyour modifications won't be saved if you exit right now,");
                    printf("press 1 if you're sure you want to exit before you save, if you want to save press 2\n\n");
                    char cs;
                    while(1){
                    getchar();
                    scanf("%c", &cs);
                    if(cs=='1'){
                        quit(fp);
                    }
                    else if(cs=='2'){
                        save(fp,count);
                        quit(fp);
                    }
                    else{
                        printf("please enter a valid input:");
                    }

                    }}
                else{
                    quit(fp);
                }
                break;
            default:
                break;
        }
    }while(1);




}
