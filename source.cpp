#include<iostream>
#include<conio.h>
#include<string>
#include<iomanip>
float qu;
int pr,cr=0;
using namespace std;
class customer{
    protected:
	    string name,email;
	    string number;
public:
		void get1(){
			cout<<"CONTACT US:4455445544          "<<endl<<endl;
			cout<<setw(20);
			cout<<"          "<<"BAKES"<<endl<<endl<<endl;
			cout<<"          "<<"please enter your details to procced!"<<endl<<endl;
			cout<<"          "<<"enter the customer details:"<<endl;
			cout<<"          "<<"enter name:";
			getline(cin,name);
			cout<<"          "<<"enter email:";
			cin>>email;
			cout<<"          "<<"enter phone number:";
			cin>>number;
			cout<<endl;
		}

};
class menu:public virtual customer{
    protected:
	    int item[20];
	    int scase;
	    int nop=0,ttl=0;
public:
	void get2(){
			cout<<endl<<endl;
			cout<<"                            "<<"********************MENU**********************"<<endl;
			cout<<"          "<<"cakes:"<<"                                      "<<"sides:"<<endl;
		                     cout<<"          "<<"1. chocolate cake 1KG - RS500"<<"               "<<"3. chocolate cupcake - RS125"<<endl;
			cout<<"          "<<"2. strawberry cake 1KG - RS500"<<"              "<<"4. cream puffs- RS150"<<endl;
			cout<<"          "<<"0. exit from menu"<<endl;
			while(1){
				int j;
				j=nop;
				pr=nop;
				cout<<endl<<"          "<<"enter your choice: ";
				cin>>scase;
				switch(scase){
					case 1:
						item[j]=1;
						nop++;
					    break;
					case 2:
						item[j]=2;
						nop++;
						break;
					case 3:
						item[j]=3;
						nop++;
						break;
					case 4:
						item[j]=4;
						nop++;
						break;
					case 0:
						return;
					default:
						cout<<"          "<<"uh-oh please enter a correct choice"<<endl;
						break;
				}
			}
		}
		void operator++(){
			ttl++;
		                     cr++;
		}
};
class Delivery{
	protected:
		float amt;
		string add1,add2;
	public:
		Delivery(float p){
			amt=p;
			if(amt>=850){
                    //we check for 850 as we apply a discount of rs.150,hence to make the condition apply for orders >=1000.
	cout<<endl<<endl<<"                 "<<"*********NOTE:DELIVERY IS AVAILABLE FOR THIS ORDER*********"<<endl<<endl;
			}
		}
		
		
};


class total:public  menu,public Delivery,public virtual customer{	
protected:
		float amount=0,count=0,disc,disc2,disc3;
		int choice;
	public:
		void calculate(){
			int k;
			for(k=0;k<=nop;k++){
				if(item[k]==1){
					amount+=500;
				}
				else if(item[k]==2){
					amount+=500;
				}
				else if(item[k]==3){
					amount+=125;
				}
				else if(item[k]==4){
					amount+=150;
				}
			}
			qu=amount;
			disc3=amount;
			
		}
		total():Delivery(qu){ 	
		    
		         disc=150;
	                            disc2=amount;
	                            amount=disc2-disc;
					
		}
		void deliv(){
		rerun:
			if(amount>=850){
//we check for 850 as we apply a discount of rs.150,hence to make the condition apply for orders >=1000.
				int choice;
				cout<<endl;
				cout<<endl;
				cout<<"          "<<"choose your mode : "<<endl;
				cout<<"          "<<"                   1.delivery"<<endl;
				cout<<"          "<<"                   2.takeaway"<<endl;
				cout<<"          "<<"enter your choice: ";
				cin>>choice;
				cout<<endl<<endl;
				switch(choice){
				    case 1:
	     		  	                    cout<<"          "<<"enter address line 1: ";
                                                                                                      getline(cin,add1);
                                                                                                       getline(cin,add1);
				                    cout<<"          "<<"enter address line 2: ";
				                    getline(cin,add2);
				                    count++;
				                    break;
				    case 2:
				    	break;
				    default:
				    	cout<<"          "<<"please choose a correct choice."<<endl;
				    	goto rerun;
				}
			}
		 	
			
		}
		void func(){
		if(amount<=200){
			amount=amount+150;
		}
		cout<<endl<<"          "<<"the discounted amount to be paid is:"<<amount<<endl;
		}
};



class payment:virtual public  customer, public virtual menu{
	protected:
		string card,cvv,expdate,confirm,scase2;
	public:
		void get3(){
	cout<<endl<<endl<<"              "<<"**********************"<<"payment details"<<"*************************"<<endl<<endl;
			cout<<"          "<<"enter your card details for payment"<<endl;
			cout<<"          "<<"16 digit card number: ";
			cin>>card;
			cout<<"          "<<"enter cvv: ";
			cin>>cvv;
			cout<<"          "<<"enter expiry date: ";
			cin>>expdate;
			cout<<endl<<endl;
			label:
	cout<<"              "<<"*******************"<<"SECURE PAYMENT PAGE"<<"************************"<<endl<<endl;
			    cout<<"          "<<"SECURE OTP: EF4565 "<<endl<<endl;
			    cout<<"          "<<"enter otp to confirm payment: ";
			    cin>>confirm;
			if(confirm=="EF4565"){
				cout<<endl<<endl<<"                                   "<<"PAYMENT CONFIRMED"<<endl<<endl<<endl;
			}
			else{
				cout<<endl<<"                                   "<<"payment failed"<<endl<<endl;
				cout<<"          "<<"press Y to try again or N to cancel your order: ";
				cin>>scase2;
				cout<<endl<<endl;
				if(scase2=="Y"){
					goto label;
				}
				else{
					cout<<"      "<<"you have cancelled your order"<<endl<<endl;
					cout<<"      "<<"thank you for staying with us,please visit again"<<endl;
					exit(0);
				}
			}
		}
};
class billing: public total,virtual public customer{
	public:
		void billout(){
			int i,flag1=0,flag2=0,flag3=0,flag4=0;
			cout<<"              ";
			cout<<setw(38);
			cout.fill('*');
			cout<<"BILLING RECIEPT"<<"**********************"<<endl<<endl<<endl;
			cout<<" YOUR ORDER DETAILS:"<<endl<<endl;
			cout<<"          "<<"name: "<<name;
			cout<<"          "<<"email: "<<email<<endl<<endl;
			cout<<"          "<<"phone number: "<<number<<endl<<endl;
			cout<<"          "<<"order:"<<"             "<<"total number"<<endl;
			for(i=0;i<=nop;i++){
				if(item[i]==1){
					flag1++;
				}
				else if(item[i]==2){
					flag2++;
				}
				else if(item[i]==3){
					flag3++;
				}
				else if(item[i]==4){
					flag4++;
				}
			}
			if(flag1>0){
				cout<<"          "<<" chocolate cake        "<<flag1<<endl;
			}
			if(flag2>0){
				cout<<"          "<<" strawberry cake       "<<flag2<<endl;
			}
			if(flag3>0){
				cout<<"          "<<" chocolate cupcake     "<<flag3<<endl;
			}
			if(flag4>0){
				cout<<"          "<<" cream puffs(2pieces)  "<<flag4<<endl;
			}
		    cout<<endl<<"         "<<"TRANSACTION ID:QUEDGSYBD45465"<<endl;
		    cout<<endl;
			cout<<"          "<<"total amount payed: "<<amount<<endl;
		                     if(count==1){
		    	cout<<"          "<<"order will be delivered to:"<<endl;
		    	cout<<"                           "<<add1<<endl;
		    	cout<<"                           "<<add2<<endl;
			}
			else{
				cout<<"          "<<"pick up order in five days"<<endl;
			}
			cout<<endl<<endl<<"                            "<<"THANK YOU FOR SHOPPING WITH BAKES"<<endl;
		}
};


int main()
{
	billing a;
	a.get1();
	a.get2();
	menu e;
	for(int c=0;c<=pr;c++){
		++e;
	}
	cout<<endl<<endl<<"          "<<"total cart items: "<<cr-1<<endl;
	a.calculate();
	total();
	a.deliv();
	a.func();
                       payment b;
                       b.get3();
	a.billout();
	getch();
	return 0;
}
