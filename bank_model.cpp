#include<iostream>
#include<vector>
#include<limits>
#include<cstdlib>
class BankAccount{
    public:

    std::vector <std::string> name_of_depositer;
    std::vector <std::string> address_of_depositer;
    std::vector <std::string> account_type;
    std::vector <int> balance_in_account;
    std::vector <int> num_of_transactions;
    std::vector <int> account_number;
    std::string temp_string_store;
    
    int existing_account = 1000;
    int temp_int_store;
    int failsafe = 100;

    /* int generatenum(){
        
    }*/

    void displaybalandinfo(){
        system("cls");
        std::cout<<"Enter Account Number: ";
        std::cin>>temp_int_store;
        if (temp_int_store > 0){
            for(int j = 0; j <= failsafe; j++){
                if (j == failsafe) {
                    std::cout<<"The Account Number you entered does not exist! ";
                }

                else if(temp_int_store == account_number[j]){
                    std::cout<<"Account Holder's Name: "<<name_of_depositer[j]<<"\n";
                    std::cout<<"Account Holder's Address: "<<address_of_depositer[j]<<"\n";
                }
            }
        }
    }

    void deposit(){

    }
    void withdraw(){

    }
    void change_adderess(){

    }

    void addnew(){

        std::cout<<"Enter User Name: ";
        std::cin>>temp_string_store;
        name_of_depositer.push_back(temp_string_store);

        std::cout<<"\nEnter the Address of User: ";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::getline(std::cin, temp_string_store);
        address_of_depositer.push_back(temp_string_store);


        std::cout<<"\nChoose account type:\n1.for Regular savings\n2.for Premium savings\n";
        std::cin>>temp_int_store;

        if(temp_int_store == 1) {
            account_type.push_back("Savings account");
        }
        else if(temp_int_store == 2) {
            account_type.push_back("Premium savings account");
        }
        else {
            std::cout<<"Error try again!";
        }

        std::cout<<"\n\n";
        std::cout<<"Initial deposit amount: ";
        std::cin>>temp_int_store;
        balance_in_account.push_back(temp_int_store);

        std::cout<<"\n\n Congrats on opening an account in our bank, Below is your account info.\nSave the account details and use them to acess your account anytime!\n\nHappy banking~~\n\n";
        account_number.push_back(existing_account+1);

        std::cout<<"\n";
        std::cout<<"\n\n\t ACCOUNT NUMBER: "<<account_number.back();
        greet();

        //std::cout<<"Name of depositer: "<<name_of_depositer[0]<<"\n"; //for tesing purposes
        //std::cout<<"Address of depositer: "<<address_of_depositer[0]; //for tesing purposes

    }

    void greet(){
    char user_input;
    std::cout<<"\nPlease choose an operation below.\n\n";
    std::cout<<"N to add new account.\nV. to view Existing users info.\n";
    std::cout<<"> ";
    std::cin>>user_input;
    if(user_input == 'n' || 'N'){

         addnew();

    }
    else if (user_input == 'v' || 'V'){
        displaybalandinfo();
    }
    } 
};



int main(){
    BankAccount ba;
    
    ba.greet();
   
}