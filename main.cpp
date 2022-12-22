#include <iostream>
using namespace std;

void FCFS();
void SJF();
void pr();
void ROUNDROBIN();
int main(int argc, char **argv){
     int input;
    int x;
    cout<<"*******Begining of Project********\n";
                  
    //TODO Collect command line arguement...
    //If -f and -o is missing throw error and quit program
    cout<<"CPU Scheduler MENU"<<endl;
   
    do
    {    
            cout<<"1:Scheduling Method(None)"<<endl;
            cout<<"2:Preemptive Mode (off)"<<endl;
            cout<<"3:Show Result"<<endl;
            cout<<"4:End of program"<<endl;
            cout<<"Please Enter your choice: ";
            cin>>input;
            switch(input)
            {
                case 1:
                   // cout<<"i seleted nnnn";
              cout<<"choose a scheduling Method: "<<endl;
                 cout<<"1. None: none of the scheduling Method is chosen"<<endl;
                 cout<<"2. First come,First served scheduling"<<endl;
                 cout<<"3. Shortest-Job -First scheduling"<<endl;
                 cout<<"4. priority scheduling"<<endl;
               cout<<"5. Round-Robin scheduling"<<endl;

                 cout<<"please enter the type of scheduling:"<<endl;
                  cin>>x;
               switch(x)
               {
                  
                    case 1:
                    FCFS();
                    case 2:
                    SJF();
                    case 3:
                    pr();
                    case 4:
                    ROUNDROBIN();
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
   if(input==1){
               
                 }
        /* code */
        
    } while (input!=4);
   
    return 0;
}

void FCFS( ){
    cout<<"First come First Serve"<<endl;
    
}
void SJF(){
    cout<<"shortest Job first "<<endl;
}
void pr(){
    cout<<"priorityy scheduling"<<endl;
}
void ROUNDROBIN(){
    cout<<"Round Robin scheduling"<<endl;

}