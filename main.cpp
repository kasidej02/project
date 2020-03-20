//Project Compro
#include<iostream>
#include<string>
#include<cstring>
#include<fstream>
#include<vector>
#include<cctype>
#include<ctime>
#include<cstdlib>
using namespace std;
int gameover=0;
int gamestart=0,howtoplay=0,leaderB=0;


struct Card{
	string type;
	string namecard;
	int score;
};

class unit{
		string name;
		string typeofp;
		vector<string> onhand;
		int money;
		int score;				
	public:			
		int betmoney(int); //ใส่เงินที่จะ bet
		void Addmoney(int); //จำนวนเงินที่เพิ่ม
		void removemoney(int);//จำนวนเงินที่ลด
		bool checkgameover();
		int Hit(vector<Card> &);//ใส่สำรับที่จะเอาการ์ดออกมา
		void newTurn();
		void create(string);//ใส่ hero หรือ bot
};


int betmoney(int);

void Addmoney(int);

void removemoney(int);

bool checkgameover();

void checkgamemode(int);

int Hit(vector<Card> &);

void newTurn();

void create(string);

int main(){
	int menu=0;	
	srand(time(0));
    cout<<"--------------------------------------------\n";
    cout<<setw(35)<<"I N F O M A T I O N S\n";
    cout<<"--------------------------------------------\n";
    cout<<"        Welcome to the 'Pirate's Sea'.\n        and you are one of pirates.\n";
    cout<<"        Because fighting on the sea \n";
    cout<<"         is the most important. \n";
    cout<<"          Hence you must protect\n";
    cout<<"          your ship from others. \n";
    cout<<"--------------------------------------------\n";
    for(int i=0;i<3;i++){
        cout<<endl;
    }
    cout<<"--------------------------------------------\n";
    cout<<setw(35)<<"W A R N I N G ! ! ! \n";
    cout<<"--------------------------------------------\n";
    cout<<"        Now doubt ship is coming.\n";
    cout<<"   Becareful and prepare for fighting \n";
	cout<<"--------------------------------------------\n";
	while (menu==0){
		unit player,bot;
		char player_action = '\0',monster_action = '\0';
		player.create("Player");
		bot.create("bot");
		cout<<"Type [1] to start game"<<endl;
		cout<<"Type [2] how to play the game"<<endl;
		cout<<"Type [3] check leader board"<<endl;
		int input_menu;
		cin>>input_menu;
		checkgamemode(input_menu);
		

		while(gamestart==1){
		
			vector<Card> cc;
			ifstream cards;
			cards.open("cards.txt");
			string ccard;
	
	
			while(getline(cards,ccard)){
				Card c;
				char desk[100];
				char name[100];
				sscanf(ccard.c_str(),"%[^;];%[^;];%d",desk,name,&c.score);
				c.type = desk;
				c.namecard = name;
				cc.push_back(c);
			}
			


			while(true){

				player.newTurn();
				bot.newTurn();
				cout << "[H] Hit [S] Stand [E] Exit";
				cout << "Enter your action: ";
				cin >> player_action;
				player_action = toupper(player_action);
				if(player_action == 'E'){
					//ไปร้านค้า
					//ไปstory
				} 










				if(checkgameover ()){
				cout << "*******************************************************\n";
				cout << "*                                                     *\n";
				cout << "*                   YOU LOSE!!!                       *\n";
				cout << "*                                                     *\n";
				cout << "*******************************************************\n";

					break; 
				}

			}
		





			
			
			
			
			
			
		}
		while(howtoplay==1){
			cout<<"ihi";
			
			
			
			
		}
		
		while(leaderB==1){
		cout<<"iejiwofjp";	
			
			
			
		}
		
		
		
		
		
		
		
		
		
		
		
	}
	
	
	
	

}



int unit::betmoney(int x){ //x cin from player
	if(x>money) return 0;
	else return x;
	
}



void unit::Addmoney(int x){ //x from function bet.
	money += x*2;
}




void unit::removemoney(int x){ //x from function bet.
	money -= x;
}




bool unit::checkgameover (){
	if(money<=0) return true;
	else return false;
}




void checkgamemode(int x){
	if(x==1) gamestart=1;
	else if(x==2) howtoplay=1;
	else if(x==3) leaderB=1;
	
}




int unit::Hit(vector<Card> &a){
	int i = rand()%a.size();
	string x = a[i].type ;
	string y = a[i].namecard;
	int z = a[i].score;
	onhand.push_back(x+y);
	a.erase(a.begin() + i);
	return z;	
}

void unit::newTurn(){
	onhand.clear();
	score = 0;
}





void unit::create(string t){
		if(t == "Player"){
			cout << "Please input your name: ";
			getline(cin,name);
			money = 500;
		}else if(t == "bot"){
			name = "more money";

		}
}
