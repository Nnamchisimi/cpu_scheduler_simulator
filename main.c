#include <stdio.h>
#include<getopt.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
//functions
void FCFS();
void SJF();
void pr();
void ROUNDROBIN();
void Grantchart();
void toread_file();


// Linked list declaration

struct node{
    int burst_time;
    int arrival_time;
    int priority;
    int waiting_time;
    int id;
    
    struct node *next;
};

struct time{
    int waiting_time;int awt;
    struct time*next;
};


struct node * jobs=NULL;
struct node * createNode(int id, int burst_time, int arrival_time, int priority)

{
	struct node* temp=NULL;
	
	temp=(struct node*)malloc(sizeof(struct node));
	temp->burst_time = burst_time;
    temp->arrival_time = arrival_time;
    temp->priority = priority;
    temp->id = id;
	temp->next=NULL;
	return temp;
}

struct node* insertBack(struct node* head, int id, int burst_time, int arrival_time, int priority)
{
	struct node* temp, *ht;
    temp=createNode(id, burst_time,arrival_time,priority);
    if(head==NULL)
    {
        head=temp;
        return head;
    }
    ht= head;
    while(ht->next !=NULL)
    ht=ht-> next;
    ht->next=temp;
    return head;
//	temp=createNode(item);
	
}
void show( struct node *head)
{
    if(head==NULL)
        printf("\n enter list!!");
    struct node *temp=head;
    while(temp !=NULL)
    {
        printf("%d time waited: %d, %d\n", temp-> burst_time,temp->arrival_time,temp->priority);
        temp =temp-> next;
    }
    
printf("\n");
}

//print result
void printResult(struct node *head){
     struct node *tmp = head;
     printf("Hello");
     while (tmp !=NULL)
     {
        printf("P%d: %dms\n",tmp->id, tmp->arrival_time);
     }
     
}

struct node *deleteFront(struct node *head)
{
	struct node *temp;
	if(head==NULL)
	return head;
	
	temp=head;
	head=head->next;
	free(temp);
	
	return head;
}
void swap(struct node *a, struct node *b){
    int t;
    t=a->burst_time;
    a->burst_time=b->burst_time;
    b->burst_time=t;

    t=a->arrival_time;
    a->arrival_time=b->arrival_time;
    b->arrival_time=t;

    t=a->priority;
    a->priority=b->priority;
    b->priority=t;

    t=a->waiting_time;
    a->waiting_time=b->waiting_time;
    b->waiting_time=t;
    t=a->id;
    a->id=b->id;
    b->id=t;

}

void sort_burst_time(struct node *head) {
    int swapped;
    struct node *current;
    struct node *last = NULL;

    // Check if the list is empty or has only one node
    if (head == NULL )
        return;

    
   do {
         swapped = 0;
         current = head;
       
         while (current ->next!= last) {
        //      // Check if the current node's burst time is greater than the next node's burst time
              
             if (current->burst_time > current->next->burst_time) {
                // printf("we need swap\n");
                swap(current,current->next);
                 
                  swapped=1;
                  
                  }
                
                  current=current->next;
                       
                  }
                  last=current;
            
                
    
     } while (swapped);
     
   
}

void p(struct node *head){
    while(head!=NULL){
        printf("%d\n",head->burst_time);
        head=head->next;
    }
    
   
}


int main(int argc, char* argv[]){

int input, opt, x;
char* in_file=NULL; char* out_file=NULL;
FILE *file=NULL;
char single_line[1024];
int burst,arrival,priority;


while ((opt = getopt(argc, argv, "f:o:")) != -1) {
        switch(opt) {
        case 'f':
                in_file = optarg; 
                //printf("%s",in_file);
                

    
                if ((file = fopen(in_file, "r")) != NULL){  
                    int job_id =1;
                    while (fgets(single_line, 1024, file) != NULL) {
                        
                        sscanf(single_line,"%d:%d:%d\n",&burst,&arrival,&priority);
                        printf("%d:%d:%d\n",burst,arrival,priority);
                        jobs = insertBack(jobs,job_id++, burst, arrival, priority);
                    }
                    fclose(file);
                    
                }
            break;
        case 'o':
            out_file= optarg;
            //printf("%s",out_file);
            break;
        default:
            printf("Please provide input and output files");
        }
        }

   
   // file = fopen("input.txt", "r");
  

          printf("*******Begining of Project********\n");
                  
    //TODO Collect command line arguement...
    //If -f and -o is missing throw error and quit program
    printf("CPU Scheduler MENU \n");
   
    do
    {    printf("Please Enter your choice: \n");
          
            printf("1:Scheduling Method(None)\n");
            printf("2:Preemptive Mode (off)\n");
            printf("3:Show Result\n");
            printf("4:End of program\n");
              scanf("%d",&input);
            switch(input)
            {
                case 1:
                    printf("choose a scheduling Method: \n");
                    printf("1. None: none of the scheduling Method is chosen \n");
                    printf("2. First come,First served scheduling [non-preemptive]\n");
                    printf("3. Shortest-Job -First scheduling \n");
                    printf("4. Shortest-Job -First scheduling [non-preemptive]\n");
                    printf("5. priority scheduling \n");
                    printf("6. priority scheduling[non-preemptive] \n");
                    printf("7. Round-Robin scheduling\n");
                 
                  scanf("%d",&x);
                 // show(jobs);
                  
               switch(x)
               {
                  
                    case 1:
                        printf(" are you sure you do not want to choose any scheduling method ?");

                        break;
                    case 2:
                        FCFS();  
                        break;
                    case 3:
                        
                        break;
                    case 4:
                     SJF();
                     sort_burst_time(jobs);
                     show(jobs);
                     
                    
                      //struct node *sorted_list = sort_list(jobs);
                      //show(sorted_list);
                    break;
                    case 5:
                     
                     
                        
                        break;
                        case 6:
                         pr();
                        
                        
                        break;
                        case 7:
                        ROUNDROBIN();
                        
                        break;
                       
               }

                break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                exit;
                    break;
                default:
                    break;
                   
            }
        /* code */
        
    } while (input!=4);
   
    return 0;
}


//void Grantchart(Node *head ,int process)

void FCFS( ){
    printf("First come First Serve\n");
   // struct node*
   int result;
   struct node *tmp = jobs;
   int count=0,simi=0,twt=0;
    while(tmp !=NULL)
    {
        count+1;
        if(tmp->arrival_time == 0){
            tmp->waiting_time = 0;
            simi=tmp->burst_time;
            tmp->waiting_time=0;
            printf("P%d: %dms\n",tmp->id, tmp->waiting_time);
            twt=twt+tmp->waiting_time;
            tmp =tmp-> next;
        }
        tmp->waiting_time=simi-tmp->arrival_time;
        simi+=tmp->burst_time;
         printf("P%d: %dms\n",tmp->id, tmp->waiting_time);
         result=tmp->waiting_time;
         twt=twt+tmp->waiting_time;
        tmp =tmp-> next;
    }
    printf("Average waiting time: %.2fms\n",twt/5.0);
    
}
void SJF(){
    printf("shortest Job first ");
      sort_burst_time(jobs);
                     show(jobs);
  int total;
    int c=0,wt=0,twt=0,lbt=0;
    while(jobs!=NULL){
    if(jobs->arrival_time == 0){
            jobs->waiting_time = 0;
            
    

     
    }
    
}
}

void pr(){

    printf("priorityy scheduling");
}
void ROUNDROBIN(){
    int a;
 printf("please Enter time quantum: \n");
                    scanf("%d",&a);
                
}