#include<iostream>
#include<vector>
#include<limits>
#include<cstdlib>
#include<random>
#include<time.h>


std::vector<std::string> user_name;
std::vector<std::string> user_address;
std::vector<std::string> user_account_type;
std::vector<long long> user_mobile;
std::vector<int> balance;
std::vector <int> account_num;
std::vector <int> pin;



int acc_num_gen  = 0;

std::string acc_type[2] = {"Savings account", "Premium account"};

int createnewacc(std::string name, std::string address,int account_type, long long mobile_num, int initial_deposit, int temp_pin );
void Greet();
void enter_info(){

    int account_type,initial_deposit,temp_pin;
    long long mobile_num;
    std::string name, address;


    std::cout<<"Please enter your name: ";
        std::cin.ignore();
        std::getline(std::cin, name);

    std::cout<<"Please enter your Mobile number: ";
        std::cin>>mobile_num;
        std::cin.ignore();

    std::cout<<"Please enter your address: ";
        std::getline(std::cin, address); 

    std::cout<<"\nPlease choose the type of account you would like\n1. for Regular savings account\n2. for premium savings account.\n";
        std::cin>>account_type;

    std::cout<<"Please enter the amount you like to initially deposit: ";
         std::cin>>initial_deposit;

    std::cout<<"Set PIN: ";
        std::cin>>temp_pin;


    std::cout<<"\n\n Congrats on opening an account in our bank, Below is your account info.\nSave the account details and use them to acess your account anytime!\n\nHappy banking~~\n\n";
    std::cout<<"\n\n\tAccount Number: "<<createnewacc(name, address, account_type, mobile_num, initial_deposit, temp_pin);
    //std::cout<<"\nfor testing purposes, The index in vector for this acc number is: "<<account_num.at(0);
   
    Greet();

}

int createnewacc(std::string name, std::string address,int account_type, long long mobile_num, int initial_deposit, int temp_pin){

    user_name.push_back(name);
    user_address.push_back(address);

    if (account_type == 1) {
        user_account_type.push_back(acc_type[0]);
    }
    else if(account_type == 2) {
        user_account_type.push_back(acc_type[1]);
    }

    user_mobile.push_back(mobile_num);
    balance.push_back(initial_deposit);

    
    srand(time(NULL));
    acc_num_gen = rand() % 50000;

    account_num.push_back(acc_num_gen);
    pin.push_back(temp_pin);
    return acc_num_gen;
    
}

void showaccountinfo(int input_account_num){

    int temp_pin;
    int fails = 0;

    int check = 0;

    for(int i = 0; i < account_num.size(); i++){

        if (input_account_num != account_num[i]){
            check++;

                if(check == account_num.size()) {

                     std::cout<<"Account not found! ";

                }
           
        }
       
        else if(input_account_num == account_num[i]){

            std::cout<<"Hello "<<user_name.at(i)<<", please verify that it's really you. \n\n";
            for(fails = 0; fails < 3 ;fails++){

            std::cout<<"Enter PIN: ";
            std::cin>>temp_pin;

            if(temp_pin == pin.at(i)) {

            std::cout<<"Account Holder's Name: "<<user_name.at(i)<<"\n";
            std::cout<<"Account Number: "<<account_num.at(i)<<"\n";
            std::cout<<"Account type: "<<user_account_type.at(i)<<"\n";
            std::cout<<"Current Balance: "<<balance.at(i)<<"\n";
            std::cout<<"User's Address: "<<user_address.at(i)<<"\n";
            break;

            }
            else if (temp_pin != pin.at(i)) {
                // fails++;
                std::cout<<"Incorrect pin. try again "<<fails + 1<<" Out of 3\n";
            }

            }
                if (fails == 3) {
                std::cout<<"FAILED TO VERIFY! try again later.";
            }
            
        }
    }
    
    Greet();

}

void checkbal(){

    int temp_pin,input_account_num;
    int fails = 0;
    int check = 0;

    std::cout<<"Please enter your Account Number: ";
    std::cin>>input_account_num;
  

    for(int i = 0; i < account_num.size(); i++){

        if (input_account_num != account_num[i]){
            check++;

                if(check == account_num.size()) {

                     std::cout<<"Account not found! ";

                }
           
        }
       
        else if(input_account_num == account_num[i]){

            std::cout<<"Hello "<<user_name.at(i)<<", please verify that it's really you. \n\n";
            for(fails = 0; fails < 3 ;fails++){

            std::cout<<"Enter PIN: ";
            std::cin>>temp_pin;

            if(temp_pin == pin.at(i)) {
                
                std::cout<<"Account Balance: "<<balance.at(i)<<"\n";
                break;

            }
            else if (temp_pin != pin.at(i)) {
                // fails++;
                std::cout<<"Incorrect pin. try again "<<fails + 1<<" Out of 3\n";
            }

            }
                if (fails == 3) {
                std::cout<<"FAILED TO VERIFY! try again later.";
            }
            
        }

    }
}

void Greet(){
    
    int user_input;

    std::cout<<"\n\n\nWelcome to the bank choose the operations below!!\n1.To access existing account.\n2.To open a new account.\n4. To check balance.\n";
    std::cout<<"> ";
    std::cin>>user_input;
    
    if(user_input == 1) {
        std::cout<<"Enter account number: ";
        std::cin>>user_input;
        showaccountinfo(user_input);
    }
    else if (user_input == 2) {
        enter_info();
    }
    else if (user_input == 4) {
        checkbal();

    }


}

int main(){

    createnewacc("dummy_1", "some", 1 , 771093324, 12000, 1010);
    createnewacc("dummy_2", "some",2 , 771093324, 12000, 2020);
    createnewacc("dummy_3", "some",1 , 771093324, 12000, 3030);
    std::cout<<account_num.at(0)<<"\n";
    std::cout<<account_num.at(1)<<"\n";
    std::cout<<account_num.at(2)<<"\n";

    Greet();

}
