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
int mymoney=0,gameover=0;
int gamestart=0,howtoplay=0,leaderB=0;


struct Card{
	string type;
	string namecard;
	int score;
};


int betmoney (int);

void Addmoney(int,int &);

void removemoney(int,int &);

void checkmoney ();

void checkgamemode(int);

int main(){
	int menu=0;	
	srand(time(0));
	while (menu==0){
		cout<<"Type 1 to start game"<<endl;
		cout<<"Type 2 how to play the game"<<endl;
		cout<<"Type 3 check leader board"<<endl;
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
				//cout<< c.score << "\n";
			}
			int i=rand()%52;
			cout<<cc[i].score<<endl;
			break;
			
			
			
			
			
			
		}
		while(howtoplay==1){
			cout<<"ihi";
			
			
			
			
		}
		
		while(leaderB==1){
		cout<<"iejiwofjp";	
			
			
			
		}
		
		
		
		
		
		
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}
int betmoney (int x){ //x cin from player
	if(x>mymoney) return 0;
	else return x;
	
}



void Addmoney(int x,int &y){ //x from function bet.,y = mymoney
	y += x*2;
}




void removemoney(int x,int &y){ //x from function bet.,y = mymoney
	y -= x;
}




void checkmoney (){
	if(mymoney<=0) gameover=1;
}




void checkgamemode(int x){
	if(x==1) gamestart=1;
	else if(x==2) howtoplay=1;
	else if(x==3) leaderB=1;
	
}




int Hit(vector<Card> &a,vector<string> &b){
	int i = rand()%a.size();
	//cout<< i <<"\n";
	string x = a[i].type ;
	string y = a[i].namecard;
	int z = a[i].score;
	b.push_back(x+y);
	a.erase(a.begin() + i);
	return z;	
}