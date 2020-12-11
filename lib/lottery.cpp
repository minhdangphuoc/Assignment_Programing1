#include <iostream>
#include <time.h>
#include <string>
int lottery[100][40];
std::string player_list[100];
const char raw_lottery_header[] =   "////////////////////////////////////////////////////////////\n"
                                    "//               ||Minh Dang Lottery Company||            //\n"
                                    "//                                                        //\n";
const char raw_lottery_footer[] =   "//                                                        //\n"
                                    "//                                                        //\n"
                                    "////////////////////////////////////////////////////////////\n";



//Function for checking the same numbers in an Array
/*int checkNum(int sample,int max,int player){
     for(int k=0;k<max;k++){    
            if (sample==lottery[player][k]){
                return 1;
            }
    }
    return 0;
}*/

int numberPlayers(){
    int head=0;
    while ( lottery[head][0]!=0)
    {
        head++;
    }
    return head;
    
}

void printLottery(int player){
    std::cout<<raw_lottery_header;
  //std::cout<<"//  NAME:0123456789  |00|00|00|00|00|00|00|  |00|00|00|   //";
    std::cout<<"//                                                        //\n";
}

void output_lottery(int number[7], int bonus_number[3]){
    for (int i=1;i<=7;i++){
        std::cout<<"|"<<number[i]<<"|";
    }
    
    std::cout<<" ";
    
    for (int i=1;i<=3;i++){
        std::cout<<"|"<<bonus_number[i]<<"|";
    }
    std::cout<<"\n";
}

void showPlayersList(){
    //char opt;
    //std::cout<<"Do you want to watch the player list and their lottery number";

    int head=0,s,t;
    int number[7];
    int bonus_number[3];
    while ( lottery[head][0]!=0) {

        s=0;
        t=0;
        
        std::cout<<player_list[head]<<"   ";
        
        for (int i=1;i<=39;i++){
            while(lottery[head][i]>=10){
                    lottery[head][i]-=10;
                    bonus_number[t]=i;
                    t++;
            } 
        
            while (lottery[head][i]>0&&lottery[head][i]<=7){
                    lottery[head][i]--;
                    number[s]=i;
                    s++;
            }
        }
        
        for (int i=0;i<7;i++){
            std::cout<<"|"<<number[i]<<"|";
        }
        
        std::cout<<" ";
        
        for (int i=0;i<3;i++){
            std::cout<<"|"<<bonus_number[i]<<"|";
        }
        
        std::cout<<"\n";
        
        head++;   
    }

   
        
} 

//create 7 numbers and store in an array
void make7luckynumber(int player){
    int r_num;
    //Seed Random = time(0) to avoid the same lotteries 
    srand (time(NULL));
    // Start random numbers
    for (int i=1;i<=7;i++){
        r_num = (rand()%39 + 1);
        lottery[player][r_num]++;
        //std::cout<<r_num<<"\n";
    }

    for (int i=1;i<=3;i++){
        r_num = (rand()%39 + 1);
        lottery[player][r_num]+=10;
        //std::cout<<r_num<<"\n";
    }
}

void addNewPlayer(){
    int newplayer = numberPlayers();
    lottery[newplayer][0] = 1;
  	std::cin.get(); 
    std::cout<<"New player nickname: ";
    getline(std::cin, player_list[newplayer]);

    make7luckynumber(newplayer);

    //showPlayersList();
}

void clearAllPlayer(){

}

