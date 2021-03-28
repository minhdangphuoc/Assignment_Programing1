#include <iostream>
#include <time.h>
#include <string>

struct
{
    int lottery[40],num_win,bonus_win;  
    std::string player_name;
} user[101]; //The 101 is a special player


//int lottery[100][40];
//std::string player_list[100];
const char raw_lottery_header[] =   "\n////////////////////////////////////////////////////////////\n"
                                    "//               ||Minh Dang Lottery Company||            //\n"
                                    "//                                                        //\n";
const char raw_lottery_footer[] =   "              //\n//                                                        //\n"
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
    while ( user[head].lottery[0]!=0)
    {
        head++;
    }
    return head;
    
}

void legal_name(std::string &str){
    if (str.length()>10){
        str = str.substr(0,10);
    }
}

void lottery_number_output(int player){
    int s=0,t=0;
    int number[7];
    int bonus_number[3];
    for (int count = 1; count<=39; count++){
        //
        if (user[player].lottery[count]==1){
            number[s]=count;
            s++;
        }
        //
        if (user[player].lottery[count]==2) {            
            bonus_number[t]=count;
            t++;
        }
    } 
    
    for (int i=0;i<7;i++){
        std::cout<<"|"<<(number[i]<=9?"0":"")<<number[i]<<"|";
    }
    
    std::cout<<"-";
    
    for (int i=0;i<3;i++){
        std::cout<<"|"<<(bonus_number[i]<=9?"0":"")<<bonus_number[i]<<"|";
    }
}

void printLottery(int player){
    legal_name(user[player].player_name);
    int s=0,t=0;
    int number[7];
    int bonus_number[3];
    
    std::cout<<raw_lottery_header;
    std::cout<<"// Buyer:"<<user[player].player_name;
    
    for (int i=0; i< 10-user[player].player_name.length();i++){
        std::cout<<" ";
    }
    std::cout<<"                                       //\n// ";
    
    //Lottery number output    
    lottery_number_output(player);
    
    std::cout<<raw_lottery_footer;
}

void clear_player(int player){
    for (int i=0; i<=39;i++){
            user[player].lottery[i]=0;
    }
}

//create 7 numbers and store in an array
void make7luckynumber(int player){
    int r_num;
    //Seed Random = time(0) to avoid the same lotteries 
    srand (time(NULL));
    // Start random numbers
    for (int i=1;i<=7;i++){
        do {
            r_num = (rand()%39 + 1);
            //std::cout<<r_num<<"\n";
        } while (user[player].lottery[r_num]!=0);
        
        user[player].lottery[r_num]=1;
    }

    for (int i=1;i<=3;i++){
        do {
            r_num = (rand()%39 + 1);
        }
        while (user[player].lottery[r_num]!=0);
            
        user[player].lottery[r_num]=2;
            //std::cout<<r_num<<"\n";
    }
}

void clear_all_players(){
    int head=0;
    while ( user[head].lottery[0]!=0) {
        clear_player(head);
        head++;   
    }
}

void show_sweet_prize_for_players(){
    int head=0;
    
    std::cout<<"Lucky number: ";
    lottery_number_output(100);

    std::cout<<"\n";

    std::cout<<"//////////////////////////////////////////////////////////////\n"<<"// Buyer       Num  Bonus    		Result              //\n";
    while ( user[head].lottery[0]!=0) {
        
        std::cout<<"// "<<user[head].player_name;

        for (int i=0; i< 10-user[head].player_name.length();i++){
            std::cout<<" ";
        }

        std::cout<<"   "<<user[head].num_win<<"     "<<user[head].bonus_win<<"      ";

        switch (user[head].num_win)
        {
        case 3:
            std::cout<<(user[head].bonus_win>0?"12.000$":"10.000$");
            std::cout<<"                         //\n";
            break;    
        case 4:
            std::cout<<(user[head].bonus_win>0?"15.000$":"12.000$");
            std::cout<<"                         //\n";
            break;
        
        case 5:
            std::cout<<(user[head].bonus_win>0?"23.000$":"20.000$");
            std::cout<<"                         //\n";
            break;
        
        case 6:
            std::cout<<(user[head].bonus_win>0?"30.000$":"25.000$");
            std::cout<<"                         //\n";
            break;
        case 7:
            std::cout<<(user[head].bonus_win>0?"99.999$":"50.000$");
            std::cout<<"                         //\n";
            break;

        default:
            std::cout<<"Getting better luck next time  //\n";
            break;
        }
        
        head++;   
    }
    std::cout<<"//////////////////////////////////////////////////////////////\n";

}

void create_the_winners(){
    
    //clear the special player
    clear_player(100);
    user[100].lottery[0] = 1;
    make7luckynumber(100);

    int s=0,t=0;
    int number[7];
    int bonus_number[3];
    for (int count = 1; count<=39; count++){
        //
        if (user[100].lottery[count]==1){
            number[s]=count;
            s++;
        }
        //
        if (user[100].lottery[count]==2) {            
            bonus_number[t]=count;
            t++;
        }
    }

    //After create the special list of numbers, this will find player's results
    int head=0;
    while ( user[head].lottery[0]!=0) {
        //reset num_win and bonus_win
        user[head].num_win=0;
        user[head].bonus_win=0;

        //Counting
        for (int count=0;count<7;count++){
            if (user[head].lottery[number[count]] == 1) user[head].num_win++;
        }

        for (int count=0;count<3;count++){
            if (user[head].lottery[number[count]] == 2) user[head].bonus_win++;
        }
        
        head++;   
    }

    show_sweet_prize_for_players();
}

void showPlayersList(){
    //char opt;
    //std::cout<<"Do you want to watch the player list and their lottery number";
    int head=0;
    while ( user[head].lottery[0]!=0) {
        printLottery(head);
        head++;   
    }
        
} 

void show_the_winners(){
    char opt;
    if(user[100].lottery[0]==0){
        create_the_winners();
    } else {
        do {
                std::cout<<"Seem that you had created the result before.\nDo you want to re-create it (y/n): ";
                std::cin>>opt;
                //std::cout<<"\n"<<opt<<"\n";
                if (!(opt=='y'||opt=='Y'||opt=='n'||opt=='N')) std::cout<<"\nError input, type again\n";
        } while (!(opt=='y'||opt=='Y'||opt=='n'||opt=='N'));
        if(system("CLS"))system("clear");
        if (opt=='y'||opt=='Y'){
            create_the_winners();
        }else{ show_sweet_prize_for_players();}
    }
}

void addNewPlayer(){
    int newplayer = numberPlayers();
    user[newplayer].lottery[0] = 1;
  	std::cin.get();     
    std::cout<<"New player nickname (1-10 digits): ";
    getline(std::cin, user[newplayer].player_name);

    make7luckynumber(newplayer);
    printLottery(newplayer);
    //showPlayersList();
}


