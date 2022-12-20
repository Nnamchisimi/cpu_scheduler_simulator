#include <iostream>
using namespace std;

int main(int argc, char **argv){
    cout<<"*******Begining of Project********\n";

    //TODO Collect command line arguement...
    //If -f and -o is missing throw error and quit program
    cout<<"CPU Scheduler MENU";
    int input;
    do
    {       cout<<"1:Scheduling Method(None)"<<endl;
            cout<<"2:Preemptive Mode (off)"<<endl;
            cout<<"3:Show Result"<<endl;
            cout<<"4:End of program"<<endl;
            cout<<"5:Enter your choice";
            cin>>input;
            switch(input)
            {
                case 1:
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
    } while (input!=2);
    

    return 0;
}
