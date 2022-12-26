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
    struct node *next;
}node;


struct node * createNode(int burst_time, int arrival_time, int priority)
{
	struct node* temp=NULL;
	
	temp=(struct node*)malloc(sizeof(node));
	temp->burst_time = burst_time;
    temp->arrival_time = arrival_time;
    temp->priority = priority;
	temp->next=NULL;
	return temp;
}

struct node* insertBack(struct node* head, int item)
{
	struct node* temp;
//	temp=createNode(item);
	
	temp->next=head;
	head=temp;
	return head;
}


int main(int argc, char* argv[]){

int input, opt, x;
char* in_file=NULL; char* out_file=NULL;
FILE *file=NULL;

while ((opt = getopt(argc, argv, "f:o:")) != -1) {
        switch(opt) {
        case 'f':
                in_file = optarg; 
                printf("%s",in_file);
            break;
        case 'o':
            out_file= optarg;
            printf("%s",out_file);
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
                    printf("2. First come,First served scheduling \n");
                    printf("3. Shortest-Job -First scheduling \n");
                    printf("4. priority scheduling \n");
                    printf("5. Round-Robin scheduling\n");
                
                
                  scanf("%d",&x);
               switch(x)
               {
                  
                    case 1:
                        printf(" are you sure you do not want to choose any scheduling method ?");
                        break;
                    case 2:
                        FCFS();  
                        break;
                    case 3:
                        SJF();
                        break;
                    case 4:
                        pr();
                    break;
                    case 5:
                        ROUNDROBIN();
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
        
    } while (input!=4);
   
    return 0;
}


//void Grantchart(Node *head ,int process)

void FCFS( ){
    printf("First come First Serve");
   // struct node*

    
}
void SJF(){
    printf("shortest Job first ");
}
void pr(){
    printf("priorityy scheduling");
}
void ROUNDROBIN(){
    printf("Round Robin scheduling");

}