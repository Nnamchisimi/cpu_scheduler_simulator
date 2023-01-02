#include <stdio.h>
#include<getopt.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>

void FCFS();
void SJF();
void PR();
void RR();
struct node* job=NULL;
struct node{
    int burst_time;
    int arrival_time;
    int priority;
    struct node *next;

   

    };
    struct node* createNode(int burst_time,int arrival_time,int priority)

    {
        struct node* tmp=NULL;
        tmp=(struct node* )malloc(sizeof(struct node));
        tmp->burst_time=burst_time;
        tmp->arrival_time=arrival_time;
        tmp->priority=priority;
        tmp->next=NULL;
        return tmp;
        
    }
    struct node* insertBack(struct node* head,int burst_time,int arrival_time,int priority){

        struct node* tmp, *ht;
        if(head==NULL)
        {
            head=tmp;
            return head;
        }
        ht=head;
        while(ht->next!=NULL)
        ht=ht->next;
        ht->next=tmp;
        return head;

    }
    void show(struct node *head)
    {
        if(head==NULL)
            printf("\n Enter list!! ");
            struct node *tmp=head;
            while (tmp!=NULL){
                printf("%d time waited: %d, %d\n", tmp->burst_time,tmp->arrival_time,tmp->priority);
                tmp=tmp->next;
            }
            printf("\n");
    }

    
    int main(int argc ,char *argv[]){
        int in ,opt,x;
        char* in_file=NULL; char* out_file=NULL;
        FILE *file=NULL;
        char line[1024];
        int burst ,arrival, priority;
        while((opt=getopt(argc,argv,"f:0:"))!=-1)
        {
            switch(opt){
                case 'f':
                in_file=optarg;
                if((file=fopen(in_file,"o"))!=NULL)
                {
                    while(fgets(line,1024,file)!=NULL){
                        sscanf(line,"%d:%d:%d:\n",&burst,&arrival,&priority);
                        printf("%d:%d:%d:\n",burst,arrival,priority);
                        job=insertBack(job,burst,arrival,priority);
                    }
                        fclose(file);
                }
                break;
                case 'o':
                out_file=optarg;
                break;
                default:
                printf("please provide input and output files ? ");

            }
        }
        printf("********Beginning of project********\n");
        printf("CPU SCHEDULER MENU\n");
        do
        {   printf("Please Enter Your Choice :\n");
            printf("1. Scheduling Method(NONE)\n");
            printf("2. PREEMPTIVE MODE(OFF)\n");
            printf("3. SHOW RESULT\n");
            printf("4. END OF PROGRAM\n");
            scanf("%d",&in);

            switch(in)
            {
                case 1:
                printf("choose a scheduling Method\n");
                printf("1. None of the scheduling Method is chosen!!\n");
                printf("2.First come First Served Scheduling\n");
                printf("3.Shortest Job -First Scheduling\n");
                printf("4.Priority Scheduling\n");
                printf("5.Round-Robin Schedulingn\n");
            
            scanf("%d",&x);
            show(job);
            switch(x)
            {
                case 1:
                printf("Are you sure you do not want to choose any scheduling method ? ");
                break;
                case 2 :
                FCFS();
                break;
                case 3:
                SJF();
                break;
                case 4:
                PR();
                break;
                case5:
                RR();
                break;
            }
            break;
        case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            default:
            break;


           }
        
            /* code */
        } while (in!=4);
        
        return 0;
    }
    void FCFS()
    {
        printf("First come First Served Scheduling\n");
    }
    void SJF(){
            printf("Shortest Job-First  Scheduling\n");
    }
    void PR(){
        printf("Priority  Scheduling\n");
    }
    void RR(){
            printf("Round-Robin Scheduling\n");
    }
