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
1. Lotteries maker
2. Players list
3. Summary terminal
4. Winners and prize rules
5. Lottery textbase graphic searching
6. Clear all players
7. Winner prizes textbase graphic
*/
#include <iostream>
#include "lib/lottery.h"

const char menu[] = "Choose your options below:\n1.Convert hexadecimal to decimal"
                      "\n2.Convert binary to octal "
                      "\n3.Convert binary to hexadecimal"
                      "\n4.Convert hexadecimal to binary "
                      "\n5.Convert Octal to binary"
                      "\nYour option:";

void showOptions(){
    char opt;
    std::cout<<"Do you want to add a player ";
    std::cin>>opt;
    do {
        addNewPlayer();
        std::cout<<"Do you want to add more player ";
        std::cin>>opt;
    } while (opt=='y'||opt=='Y');
    std::cout<<"Now: "<< numberPlayers()<<std::endl;
    showPlayersList();

}

int main(){    
    //if user want to create a lottery, call make7luckynumber()
    showOptions();    
    
    return 0;
}