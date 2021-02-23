#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct person_data{
    char name[256];
    double weight;
    double height;
    double bmi;
    char result[256];
    struct person_data *next;
};




void main(void){
    struct person_data *head,*p;
    head=NULL;
    char r1[256]="痩せ型";
    char r2[256]="普通体重";
    char r3[256]="肥満(1度)";
    char r4[256]="肥満(2度)";
    char r5[256]="肥満(3度)";
    char r6[256]="肥満(4度)";
    while(1){
        p=malloc(sizeof(struct person_data));
        printf("name->");
        
        
        if(scanf("%s",p->name)==EOF){
            break;
        }
        printf("weight->");
        scanf("%lf",&p->weight);
        

        printf("height->");
        scanf("%lf",&p->height);
        p->bmi=p->weight/((p->height/100)*(p->height/100));
        if(p->bmi<18.5){
            strcpy(p->result,r1);
        }else if(18.5<=p->bmi && p->bmi<25.0){
            strcpy(p->result,r2);
        }else if(25.0<=p->bmi && p->bmi<30.0){
            strcpy(p->result,r3);
        }else if(30.0<=p->bmi && p->bmi<35.0){
            strcpy(p->result,r4);
        }else if(35.0<=p->bmi && p->bmi<40.0){
            strcpy(p->result,r5);
        }else{ 
            strcpy(p->result,r6);
        }

        p->next=head;
        head=p;
        
        
        
    }  
    p=head;
    printf("     名前       体重      身長      BMI        結果\n");

    printf("-----------------------------------------------\n");
    
    while(p!=NULL){
        printf("%10s%10.1f%10.1f%9.1f%15s",p->name,p->weight,p->height,p->bmi,p->result);
        printf("\n");
        p=p->next;
        
    }

}

