/*
1. Lottery machine.  Make a command line application that draws lottery numbers. 7 numbers and 3 bonus numbers. 
The numbers are between 1 and 39. At the end, the application will sort the numbers from biggest to smallest. 
First the regular numbers and then the bonus numbers. 
You can also include lottery tickets from few users and define prize money for different results. 
For example, 5 numbers correct, 5+1 correct, 6 correct, 6+1 correct and all seven correct.
You can also add a feature that draws random lottery numbers for the user. 
After the actual lottery draw the application tells how many numbers were correct and how much money the user won. 
Text based user interface is defined by the student.
*/
/*
1. Lotteries maker - finish
2. Players list - finish
3. Summary terminal - limited same with player list
4. Winners and prize rules
5. Clear all players
6. Winner prizes textbase graphic
*/
#include <iostream>
#include "lib/lottery.h"
#include <string>
#include <stdlib.h>

const std::string rules[2] = {  "╔═══════════════════════════════════════════════════════╗\n"
                                "║       -Numbers Only-           -With Bonus Number-    ║\n"
                                "║          3: 10.000$                3+1: 12.000$       ║\n"
                                "║          4: 12.000$                5+1: 15.000$       ║\n"
                                "║          5: 20.000$                5+1: 23.000$       ║\n"
                                "║          6: 25.000$                6+1: 30.000$       ║\n"
                                "║          7: 50.000$                7+1: 99.999$       ║\n" 
                                "╚═══════════════════════════════════════════════════════╝\n", 
                                "///////////////////////////////////////////////////////////\n"
                                "//       -Numbers Only-      //   -With Bonus Number-    //\n"
                                "//         3: 10.000$        //      3+1: 12.000$        //\n"
                                "//         4: 12.000$        //      5+1: 15.000$        //\n"
                                "//         5: 20.000$        //      5+1: 23.000$        //\n"
                                "//         6: 25.000$        //      6+1: 30.000$        //\n"
                                "//         7: 50.000$        //      7+1: 99.999$        //\n"    
                                "///////////////////////////////////////////////////////////\n"};






const std::string menu[2] =     {"╔══════════════════════════════════════════╗"
                        "\n║Choose your options below:                ║"
                        "\n║1. Buy a lottery                          ║"
                        "\n║2. Show a list of players                 ║"
                        "\n║3. Show who win the prizes                ║"
                        "\n║4. Show the rules                         ║"
                        "\n║5. Clear all players                      ║"
                        "\n║6. Exit the program                       ║"
                        "\n╚══════════════════════════════════════════╝"
                        "\nYour option: ","/////////////////////////////////////////////"
                        	"\n//Choose your options below:               //"
                        	"\n//1. Buy a lottery                         //"
                        	"\n//2. Show a list of players                //"
                        	"\n//3. Show who win the prizes               //"
                        	"\n//4. Show the rules                        //"
                            "\n//5. Clear all players                     //"
                            "\n//6. Exit the program                      //"
                        	"\n/////////////////////////////////////////////"
                        	"\nYour option: "};

void showOptions(int OSmode){
    
    if (system("CLS")) system("clear");

    char opt,x;
    std::cout<<menu[OSmode];
    std::cin>>opt;
    
    if (system("CLS")) system("clear");

    switch (opt)
    {
    case '1': 
        if (numberPlayers()<=100){
            do {
                addNewPlayer();
                do {
                    std::cout<<"\nDo you want to buy more lottery (y/n): ";
                    std::cin>>opt;
                    //std::cout<<"\n"<<opt<<"\n";
                    if (!(opt=='y'||opt=='Y'||opt=='n'||opt=='N')) std::cout<<"\nError input, type again\n";
                } while (!(opt=='y'||opt=='Y'||opt=='n'||opt=='N'));
                if (system("CLS")) system("clear");
            } while (opt=='y'||opt=='Y');
        } else {
            std::cout<<"Full of players. \nPlease clear all players before buying more lotteries.\nPress enter to continue.";
            std::cin.ignore();
            std::cin.get();
        }
        break;
    case '2':
        std::cout<<"\nNow: "<< numberPlayers()<<(numberPlayers()>=2?" players":" player")<<std::endl; 
        showPlayersList();
        std::cout<<"\n";
        
        //Pause for showing the player list
        std::cout<<"Press enter key to continue. ";
        //std::cin.get();
        std::cin.ignore();
        std::cin.get();
        
        break;
    case '4':
        std::cout<<rules[OSmode];
        //Pause for showing the player list
        std::cout<<"Press enter key to continue. ";
        //std::cin.get();
        std::cin.ignore();
        std::cin.get();
        break;

    case '3':
        if(numberPlayers()>0){
            show_the_winners();
        } else {
            std::cout<<"No lottery. Please buy some lotteries.\n";
        }

        //Pause for showing 
        std::cout<<"Press enter key to continue. ";
        //std::cin.get();
        std::cin.ignore();
        std::cin.get();
        break;
        break;

    case '5':
        clear_all_players();
        std::cout<<"All player have been cleared.\n";
        //Pause for showing the player list
        std::cout<<"Press enter key to continue. ";
        //std::cin.get();
        std::cin.ignore();
        std::cin.get();
        break;

    case '6':
        std::cout<<"Good Bye, See you again.\n";
        //Pause for showing the player list
        std::cout<<"Press enter key to exit. ";
        //std::cin.get();
        std::cin.ignore();
        std::cin.get();
        system("exit");
        exit (0);
        break;
    
    default:
        std::cout<<"Error input\n";
        //Pause for showing the player list
        std::cout<<"Press enter key to continue. ";
        //std::cin.get();
        std::cin.ignore();
        std::cin.get();
        break;
    }
    
    if (system("CLS")) system("clear");

    showOptions(OSmode);
}


void OS_select(){
    char opt;
    std::cout<<"Choose your main OS:\n1. Window with CMD\n2. Linux/Macos with terminal\nYour option: ";
    std::cin>>opt;

    switch (opt)
    {
    case '1':
        showOptions(1);    
        break;
    case '2':
        showOptions(0);  
        break;

    default:
        std::cout<<"\nError input\n";
        
        OS_select();
    }

}

int main(){    
    //if user want to create a lottery, call make7luckynumber()
    if (system("CLS")) system("clear");
    OS_select();  
    
}