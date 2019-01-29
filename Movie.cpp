#include <iostream>
#include <fstream>
#include <locale>
#include <windows.h>
#include <cmath>
#include <vector>
#include <string.h>
#include <conio.h>
#include <cstdlib>
using namespace std;
class Movie;
string uppercaseIt(string s);

class basic{
	protected:
	string name,director,mact,macts,cast[15];
	bool avl;
	int year,pg,quan;
	double time,price;
	int clen;
	float imdb;
	bool horror,comedy,fantacy,romantic,crime,drama,westren,action,adventure,war,musical,biography,teen,mystry;
	
	public:
	basic(){
	for(int i=0; i<15; i++){
	cast[i]=" ";
	}
	name=""; director=""; year=0; time=0; pg=0; price=0; mact=""; macts=""; avl=1; quan=5;
	horror=0,comedy=0,fantacy=0,romantic=0,crime=0,drama=0,westren=0,action=0,adventure=0,war=0,musical=0,biography=0,teen=0,mystry=0;
	}
};

class Person{
	private:
	string name,Mname;
	int quan,dur;
	int pay;
	string adress;
	int contact;
	public:
		Person(){
			name=" ";
			Mname=" ";
			quan=0;
			dur=0;
			pay=0;
			adress=" ";
			contact=0;
		}
	friend void SerNs(vector<Person>& vec);
	friend void PerT(vector<Person>& vec);
	friend void returnP(Movie* ptr,int lim, vector<Person>& vec);
	friend void SerPer(vector<Person>& vec);
	friend void SellM(Movie* ptr,int lim, vector<Person>& vec);
	friend void readperson(vector<Person>& ptr);
	friend void saveperson(vector<Person>& ptr);
	
	void getperson(){
	cout<<"Name of Person: "<<name<<endl;
	cout<<"Name of Movie Bought: "<<Mname<<endl;
	cout<<"Quantity of movies bought: "<<quan<<endl;
	cout<<"Duration of rent is: "<<dur<<" Days"<<endl;
	if(pay<0){
	cout<<"Your debt is Rs"<<pay<<endl;	
	}
	else if(pay==0){
		cout<<"You have no debt "<<endl;
	}
	else if(pay>0){
		cout<<"Return Money is: "<<pay<<endl;
	}
	cout<<"Address: "<<adress<<endl;
	cout<<"Contact: "<<contact<<endl;
	}
	
};

class Movie: public basic{
protected:
	bool d3;
	static double account;
public:
	friend void returnP(Movie* ptr,int lim, vector<Person>& vec);
	friend void EditMovie(Movie* ptr, int lim);
	friend void saveacc(Movie* ptr, int lim);
	friend void savedata(Movie *ptr, int lim);
	friend void yearsandyears(Movie* ptr, int lim);
	friend void GenSer(Movie* ptr,int lim);
	friend void SellM(Movie* ptr,int lim, vector<Person>&);
	friend void AvlMovies(Movie* ptr, int lim);
	friend void readdata(Movie *ptr, int lim);
	friend void Reated(Movie* ptr, int lim);
	friend void MovieSearch(Movie* ptr, int lim);
	friend void actors(Movie* ptr, int lim);
	friend Movie* addmovie(Movie* ptr,int alen);
	friend void directorscut(Movie* ptr, int lim);
	Movie(){d3=0;}
	double getaccount(){ return account;
	}
	bool getavl(){ return avl;
	}
	
    void SetData();
	void GetData();
};
double Movie:: account=0;

void Movie:: SetData(){
	cout<<"                   Data Entry "<<endl;
	cout<<"Enter name of the movie : "; cin.ignore();  getline(cin,name);
	cout<<"Enter IMDB rating of the movie: "; cin>>imdb;
	cout<<"Enter PG ratings of the movie "; cin>>pg;
	cout<<"Enter name of the director "; cin.ignore(); getline(cin,director);
	cout<<"Enter Year of the movie "; cin>>year;
	cin.ignore();
	cout<<"Enter the main staring Actor "; getline(cin,mact);
	cout<<"Enter the main staring Actress "; getline(cin,macts);
	cout<<"Enter the number of cast members "; cin>>clen;
	if(clen>0){
	cout<<"Enter Cast :";
	}
	cin.ignore();
	for(int i=0; i<clen; i++){
	getline(cin,cast[i]);
	}
	cout<<"Enter running time of the movie in minutes: "; cin>>time;
	cout<<"Is the movie 3d? 1 for yes 0 for no: "; cin>>d3;
	cout<<"What is the genre of the movie: 1 for yes 0 for no: "<<endl;
	cout<<"Horror: "; cin>>horror; cout<<"Comedy: "; cin>>comedy; cout<<"Fantasy: "; cin>>fantacy; cout<<"Romantic: "; cin>>romantic; 
	cout<<"Crime: "; cin>>crime; cout<<"Drama: "; cin>>drama; cout<<"Westren: "; cin>>westren; cout<<"Action: "; cin>>action;
	cout<<"Adventure: "; cin>>adventure; cout<<"War: "; cin>>war; cout<<"Musical: "; cin>>musical; cout<<"Biography: "; cin>>biography;
	cout<<"Teen: "; cin>>teen; cout<<"Mystry: "; cin>>mystry;
	cout<<"Quantity of the available film is "; cin>>quan;
	cout<<"Price of the unit is: "; cin>>price;
	if(quan>0){
	avl=1;
	}
	else{
	avl=0;
	}
	}

void Movie:: GetData(){
	cout<<"                   Movie Details "<<endl;
	if(avl==1){
	cout<<endl<<"Quantity of the available film is "<<quan<<endl<<endl;
	}
	else{cout<<endl<<"*THIS MOVIE IS NOT AVAILABLE*"<<endl<<endl;
	}
	cout<<"The name of the movie is : "<<name<<endl;
	cout<<endl<<"IMDB rating is: "<<imdb<<endl;
	cout<<"The director of the movie is "<<director<<endl;
	cout<<"Year of the movie is "<<year<<endl;
	cout<<"The staring actor of the movie is "<<mact<<endl;
	cout<<"The staring actress of the movie is "<<macts<<endl;
	if(clen>0){
	cout<<"Cast in this movie are :";
	}
	for(int i=0; i<clen; i++){
	cout<<cast[i]<<",";
	}
	if(clen>0){cout<<endl;}
	cout<<"This movie is: ";
	if(horror==1){cout<<"Horror,";} if(comedy==1){cout<<"Comedy,";} if(fantacy==1){cout<<"Fantacy,";} if(romantic==1){cout<<"Romantic,";}
	if(crime==1){cout<<"Crime,";} if(drama==1){cout<<"Drama,";} if(westren==1){cout<<"Westren,";} if(action==1){cout<<"Action,";}
	if(adventure==1){cout<<"adventure,";} if(war==1){cout<<"war,";} if(musical==1){cout<<"musical,";} if(biography==1){cout<<"biography,";}
	if(teen==1){cout<<"teen,";} if(mystry==1){cout<<"mystry,";}
	cout<<endl<<"This movie is "<<round(time/60)<<" hours long "<<endl;
	cout<<endl<<"This movie is PG "<<pg<<"+"<<endl;
	cout<<"Price of the movie is "<<price<<"rs"<<endl;
	if(d3==1){
	cout<<endl<<"*Available in 3d*"<<endl;
	}
	else{
	cout<<endl<<"*NOT Available in 3d*"<<endl;
	}
	}

void savedata(Movie *ptr, int lim){
	Movie *temp; temp=ptr; 
	ofstream file;
	file.open("Name.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file<<ptr->name;
	if(i!=lim-1){
			file<<endl;
		}
	}
	ptr++;
	} file.close(); ptr=temp;
    file.open("Dir.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file<<ptr->director;
	if(i!=lim-1){
			file<<endl;
		}
	}
	ptr++;
	} file.close(); ptr=temp;
	
	file.open("IMDB.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file<<ptr->imdb;
	if(i!=lim-1){
			file<<endl;
		}
	}
	ptr++;
	} file.close(); ptr=temp;
	
	file.open("Time.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file<<ptr->time;
	if(i!=lim-1){
			file<<endl;
		}
	}
	ptr++;
	} file.close(); ptr=temp;

	file.open("Pg.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file<<ptr->pg;
	if(i!=lim-1){
			file<<endl;
		}
	}
	ptr++;
	} file.close(); ptr=temp;
	
	file.open("Price.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file<<ptr->price;
	if(i!=lim-1){
			file<<endl;
		}
	}
	ptr++;
	} file.close(); ptr=temp;
	
	file.open("Quantity.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file<<ptr->quan;
	if(i!=lim-1){
			file<<endl;
		} 
	if(ptr->quan==0){
	ptr->avl=0;
	}
	}
	ptr++;
	} file.close(); ptr=temp;
	
	file.open("Actor.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file<<ptr->mact;
	if(i!=lim-1){
			file<<endl;
		}
	}
	ptr++;
	} file.close(); ptr=temp;
	
	file.open("Actress.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file<<ptr->macts;
	if(i!=lim-1){
			file<<endl;
		}
	}
	ptr++;
	} file.close(); ptr=temp;
	
	file.open("Bool.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file<<ptr->horror<<" "<<ptr->comedy<<" "<<ptr->fantacy<<" "<<ptr->romantic<<" "<<ptr->crime<<" "<<ptr->drama<<" "<<ptr->westren<<" ";
	file<<ptr->action<<" "<<ptr->adventure<<" "<<ptr->war<<" "<<ptr->musical<<" "<<ptr->biography<<" "<<ptr->teen<<" "<<ptr->mystry<<" ";
	file<<ptr->d3;
	if(i!=lim-1){
			file<<endl;
		}
	}
	ptr++;
	} file.close(); ptr=temp;
	
	file.open("CastLength.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file<<ptr->clen;
	if(i!=lim-1){
			file<<endl;
		}
	}
	ptr++;
	}
	file.close(); ptr=temp;
	
	file.open("Cast.txt");
	
	for(int i=0; i<lim; i++){int x=0;
	if(file.is_open()){
	while(x<ptr->clen){
	file<<ptr->cast[x]<<endl; x++;
	}
	}
	ptr++;
	}
	file.close();
	ptr=temp;
	
	file.open("Price.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file<<ptr->price;
	if(i!=lim-1){
			file<<endl;
		}
	}
	ptr++;
	} file.close();
	ptr=temp;
	
	file.open("Account.txt");
	if(file.is_open()){
	file<<ptr->account;
	} file.close();
	
	file.open("Year.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file<<ptr->year;
	if(i!=lim-1){
			file<<endl;
		}
	}
	ptr++;
	} file.close(); ptr=temp;
}

void saveacc(Movie* ptr, int lim){
	ofstream file;
	
	file.open("Account.txt");
	if(file.is_open()){
	file<<ptr->account;
	} file.close();
	
	file.open("Quantity.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file<<ptr->quan;
	if(i!=lim-1){
			file<<endl;
		}
	if(ptr->quan==0){
	ptr->avl=0;
	}
	else{
	ptr->avl==1;
	}
	}
	ptr++;
	} file.close();
}
						//reading movie data here
void readdata(Movie *ptr, int lim){
	Movie *temp; temp=ptr; 
	ifstream file;
	file.open("Name.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	getline(file,ptr->name);
	}
	ptr++;} file.close();
	ptr=temp;

    file.open("Dir.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	getline(file,ptr->director);
	}
	ptr++;
	} file.close(); ptr=temp;
	
	file.open("IMDB.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file>>ptr->imdb;
	}
	ptr++;
	} file.close(); ptr=temp;
	
	file.open("Time.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file>>ptr->time;
	}
	ptr++;
	} file.close(); ptr=temp;

	file.open("Pg.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file>>ptr->pg;
	}
	ptr++;
	} file.close(); ptr=temp;
	
	file.open("Price.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file>>ptr->price;
	}
	ptr++;
	} file.close(); ptr=temp;
	
	file.open("Quantity.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file>>ptr->quan; 
	if(ptr->quan==0){
	ptr->avl=0;
	}
	}
	ptr++;
	} file.close(); ptr=temp;
	
	file.open("Actor.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	getline(file,ptr->mact);
	}
	ptr++;
	} file.close(); ptr=temp;
	
	file.open("Actress.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	getline(file,ptr->macts);
	}
	ptr++;
	} file.close(); ptr=temp;
	
	file.open("Bool.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file>>ptr->horror;
	file>>ptr->comedy;
	file>>ptr->fantacy;
	file>>ptr->romantic;
	file>>ptr->crime;
	file>>ptr->drama;
	file>>ptr->westren;
	file>>ptr->action;
	file>>ptr->adventure;
	file>>ptr->war;
	file>>ptr->musical;
	file>>ptr->biography;
	file>>ptr->teen;
	file>>ptr->mystry;
	file>>ptr->d3;
	}
	ptr++;
	} file.close(); ptr=temp;
	
	file.open("CastLength.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file>>ptr->clen;
	}
	ptr++;
	}
	file.close(); ptr=temp;
	
	file.open("Cast.txt");
	for(int i=0; i<lim; i++){ int x=0;
	if(file.is_open()){
	while(x<ptr->clen){
	getline(file,ptr->cast[x]); x++;
	}
	}
	ptr++;
	} 
	file.close();
	ptr=temp;
	
	file.open("Account.txt");
	if(file.is_open()){
	file>>ptr->account;
	} file.close();
	
	
	file.open("Price.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file>>ptr->price;
	}
	ptr++;
	} file.close();
	ptr=temp;
	
	file.open("Year.txt");
	for(int i=0; i<lim; i++){
	if(file.is_open()){
	file>>ptr->year;
	}
	ptr++;
	} file.close(); ptr=temp;
}

void readperson(vector<Person>& ptr){
	ifstream file;
	
	file.open("intPer.txt");
	for(int i=0;i<ptr.size();i++){
	if(file.is_open()){
	file>>ptr[i].quan;
	file>>ptr[i].pay;
	file>>ptr[i].contact;
	file>>ptr[i].dur;
	}
	} file.close();
		
	
	file.open("PersonName.txt");
	for(int i=0; i<ptr.size(); i++){
	if(file.is_open()){
	getline(file,ptr[i].name);
	}
	} file.close();
	
	file.open("PersonMovie.txt");
	for(int i=0; i<ptr.size(); i++){
	if(file.is_open()){
	getline(file,ptr[i].Mname);
	}
	} file.close();
	
	file.open("address.txt");
	for(int i=0; i<ptr.size(); i++){
	if(file.is_open()){
	getline(file,ptr[i].adress);
	}
	} file.close();
}

void saveperson(vector<Person>& ptr){
	ofstream file;
	
	file.open("intPer.txt");
	for(int i=0;i<ptr.size();i++){
	if(file.is_open()){
	file<<ptr[i].quan<<" ";
	file<<ptr[i].pay<<" ";
	file<<ptr[i].contact<<" ";
	file<<ptr[i].dur<<endl;
	}
	} file.close();
	
	file.open("PersonName.txt");
	for(int i=0; i<ptr.size(); i++){
	if(file.is_open()){
	file<<ptr[i].name;
	if(i!=ptr.size()-1){
			file<<endl;
		}
	}
	} file.close();
	
	file.open("PersonMovie.txt");
	for(int i=0; i<ptr.size(); i++){
	if(file.is_open()){
	file<<ptr[i].Mname;
	if(i!=ptr.size()-1){
			file<<endl;
		}
	}
	} file.close();
	
	file.open("address.txt");
	for(int i=0; i<ptr.size(); i++){
	if(file.is_open()){
	file<<ptr[i].adress<<endl;
	}
	} file.close();
}

Movie* addmovie(Movie* ptr,int alen){
 	int nlen=alen+1;
 	Movie *ptr2,*temp,*temp2;
 	temp=ptr;
 	ptr2=new Movie[nlen];
 	temp2=ptr2;
	ptr2->account=ptr->account;
	for(int i=0; i<alen; i++){
 	ptr2->name=ptr->name;
	ptr2->director=ptr->director;
	ptr2->year=ptr->year;
	ptr2->mact=ptr->mact;
	ptr2->macts=ptr->macts;
	ptr2->clen=ptr->clen;
	for(int i=0; i<ptr->clen; i++){
	ptr2->cast[i]=ptr->cast[i];
	}
	ptr2->quan=ptr->quan;
	ptr2->price=ptr->price;
	ptr2->imdb=ptr->imdb;
	ptr2->time=ptr->time;
	ptr2->pg=ptr->pg;
	ptr2->avl=ptr->avl;
	
	ptr2->horror=ptr->horror;
	ptr2->comedy=ptr->comedy;
	ptr2->fantacy=ptr->fantacy;
	ptr2->romantic=ptr->romantic;
	ptr2->crime=ptr->crime;
	ptr2->drama=ptr->drama;
	ptr2->westren=ptr->westren;
	ptr2->action=ptr->action;
	ptr2->adventure=ptr->adventure;
	ptr2->war=ptr->war;
	ptr2->musical=ptr->musical;
	ptr2->biography=ptr->biography;
	ptr2->teen=ptr->teen;
	ptr2->mystry=ptr->mystry;
	ptr2->d3=ptr->d3;
	
	ptr++; ptr2++;
	}
 delete []temp;
 ptr2=temp2; ptr2=ptr2+alen;
 ptr2->SetData();
 system("cls");
 return temp2;
 }
 
void EditMovie(Movie* ptr, int lim){
 	string x;
 	int check=0;
 	cin.ignore();
 	cout<<"Enter the name of the movie you want to see: ";
 	getline(cin,x);
 	for(int i=0; i<lim; i++){
 	if(uppercaseIt(x).compare(uppercaseIt(ptr->name))==0){ check++;
	ptr->SetData();
	}
	ptr++;
	} 
	if(check==0){
	cout<<"No Record Found"<<endl;
	}
}

void MovieSearch(Movie* ptr, int lim){
 	string x;
 	int check=0;
 	cin.ignore();
 	cout<<"Enter the name of the movie you want to see: ";
 	getline(cin,x);
 	
	for(int i=0; i<lim; i++){
	if(uppercaseIt(x).compare(uppercaseIt(ptr->name))==0){ check++;
	cout<<"Getting data.."<<endl;
	ptr->GetData();
	
	}
	ptr++;
	}
	if(check==0){
	cout<<"No Record Found"<<endl;
	}
}

void directorscut(Movie* ptr, int lim){
 	string x;
 	int p=0,check=0;
 	cin.ignore();
	cout<<"Enter name of the movie's director you want to see: ";
	getline(cin,x);
 	for(int i=0; i<lim; i++){
 		if(uppercaseIt(x).compare(uppercaseIt(ptr->director))==0){
		check++;
 		if(p==0){cout<<"*"<<ptr->director<<" Movies* "<<endl; p++;}
		cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
		}
	ptr++;
	}
	if(check==0){
	cout<<"No Record Found"<<endl;
	}
}
 
void actors(Movie* ptr, int lim){
 	string x;
 	int p=0,check=0;
 	cout<<"Enter name of the staring Actor: ";
	cin.ignore();
	getline(cin,x);
 	for(int i=0; i<lim; i++){
 		if(uppercaseIt(x).compare(uppercaseIt(ptr->mact))==0){
		check++;
 		if(p==0){cout<<"*"<<ptr->mact<<" Movies* "<<endl; p++;}
		cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
		}
	ptr++;
	}
	if(check==0){
	cout<<"No Record Found"<<endl;
	}
}

void Reated(Movie* ptr, int lim){
 	string x;
 	int check=0;
 	cin.ignore();
 	cout<<"Enter anything related to the movie: ";
	getline(cin,x);
	for(int i=0; i<lim; i++){
	if(uppercaseIt(x).compare(uppercaseIt(ptr->name))==0 || uppercaseIt(x).compare(uppercaseIt(ptr->director))==0 || uppercaseIt(x).compare(uppercaseIt(ptr->mact))==0 || uppercaseIt(x).compare(uppercaseIt(ptr->macts))==0){
	check++; 
	cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
	} int p=1;
	for(int k=0; k<ptr->clen; k++){
	if(uppercaseIt(x).compare(uppercaseIt(ptr->cast[k]))==0){check++;
	if(p==1){
	cout<<"This guy is the cast of ";
	p++;
	}	
	cout<<ptr->name;
	cout<<","<<endl;
	}
	}
	ptr++;
	}
	if(check==0){
		cout<<"No Record Found"<<endl;
		}
}

void yearsandyears(Movie* ptr, int lim){
 	int x=0,p=0,check=0;;
	the: cout<<"Enter Year you want to see movies of: ";
	cin>>x;
		try{
		if(x>2018 || x<1930){
			throw x;
		}
 	for(int i=0; i<lim; i++){
 		if(ptr->year>=x){ check++;
 		if(p==0){cout<<"*Movies After "<<x<<"*"<<endl; p++;
		}
	cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
		}
	ptr++;
 }
	if(check==0){
		cout<<"No Record Found"<<endl;
		}
}
catch(int x){
	cout<<x<<" is not a valid time period dude"<<endl;
	goto the;
}
}

string uppercaseIt(string s){
	string convorted;
	for (unsigned short i=0; i<s.length(); ++i){           //Case Insensitivity Methd
		convorted+=toupper(s[i]);
		}
		return convorted;
}

void SellM(Movie* ptr,int lim, vector<Person>& vec){
	int l=lim;
	Movie* temp; temp=ptr;
	string x;
	int k=0,check=0;
	cout<<"Enter the name of the movie you  want to buy"<<endl<<"Name: ";
 	cin.ignore();
	getline(cin,x);
 
	for(int i=0; i<lim; i++){
 	if(ptr->quan==0){
		ptr->avl==0;
	}
	if(ptr->avl==1 && uppercaseIt(x).compare(uppercaseIt(ptr->name))==0){
	check++;
	ptr->GetData();
	cout<<endl<<"Press 1 to buy: ";
	cin>>k;
	if(k==1){
		Person obj;
		cout<<"                     Please fill the buyer's details below details"<<endl<<endl;	
		cout<<"Enter name of the Person: ";
		cin.ignore();
		getline(cin,obj.name);
		cout<<"Enter the duration you want to rent for in days: ";
		cin>>obj.dur;
		here: cout<<"Enter quantity of the movie: ";
		cin>>obj.quan;
		
	if(obj.quan>ptr->quan){
	cout<<"Itni Zada Movies Dastyab Nhi "<<endl;
	goto here;
	}
		obj.Mname=ptr->name;
		cout<<"Enter the amount of the payment: ";
		cin>>obj.pay;
		int jfk=0;
		jfk=obj.pay-(ptr->price)*obj.quan;
		obj.pay=(ptr->price)*obj.quan;
		cout<<"Enter address: ";
		cin.ignore();
		getline(cin,obj.adress);
		cout<<"Enter contact number of the customer: ";
		cin>>obj.contact;
		cout<<endl<<endl;
	if(obj.quan<=ptr->quan){
		vec.push_back(obj);
		
	if(jfk<0){
	cout<<"Your have to give "<<jfk<<"Rs more"<<endl;	
	}
	else if(jfk==0){
		cout<<"You have no debt "<<endl;
	}
	else if(jfk>0){
		cout<<"Apnay Bakaya "<<jfk<<"Rs Wapis Lay Lejiye"<<endl;
	}
	ptr->quan=ptr->quan-obj.quan;
	ptr->account=ptr->account+obj.pay;
	cout<<"                     SOLD "<<obj.quan<<" DVD(s) "<<endl; 
	cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<", Price "<<ptr->price<<endl;
	break;
	}
	}
	}
	if(uppercaseIt(x).compare(uppercaseIt(ptr->name))==0 && ptr->avl==0){
	check++; 
	cout<<x<<" is not avaliable"<<endl;
	}
	ptr++;
	}
	if(check==0){
		cout<<"No Record Found"<<endl;
}
}

void AvlMovies(Movie* ptr, int lim){
	int check=0;
	for(int i=0;i<lim;i++){
		if(ptr->avl==1){check++;
			cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
		}
		ptr++;
	}
	cout<<endl;
	if(check==0){
		throw "We are Sorry no movies are available";
	}
			}

void GenSer(Movie* ptr,int lim){
	cout<<"1 for Horror Movies"<<endl;
	cout<<"2 for Comedy Movies"<<endl;
	cout<<"3 for Fantacy Movies"<<endl;
	cout<<"4 for Romantic Movies"<<endl;
	cout<<"5 for Romantic Comedy Movies"<<endl;
	cout<<"6 for Crime Movies"<<endl;
	cout<<"7 for Drama Movies"<<endl;
	cout<<"8 for Westren Movies"<<endl;
	cout<<"9 for Action Movies"<<endl;
	cout<<"10 for Advanture Movies"<<endl;
	cout<<"11 for War Movies"<<endl;
	cout<<"12 for Action Crime Movies"<<endl;
	cout<<"13 for War Drama Movies"<<endl;
	cout<<"14 for War Action Movies"<<endl;
	cout<<"15 for Musical Movies"<<endl;
	cout<<"16 for Biography Movies"<<endl;
	cout<<"17 for Teen Movies"<<endl;
	cout<<"18 for Mystry Movies"<<endl;
	
	int x=0;
	cout<<"What genre you want to search for "; cin>>x;
	switch(x){
		case 1:{ cout<<"                           *Horror Movies*"<<endl;
			for(int i=0;i<lim;i++){
			if(ptr->horror==1){
			cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
		} ptr++;
	}
			break;
		}
		case 2:{	cout<<"                           *Comedy Movies*"<<endl;
			for(int i=0;i<lim;i++){
		if(ptr->comedy==1){
			cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
		} ptr++;
	}
			break;
		}
		case 3:{cout<<"                           *Fantacy Movies*"<<endl;
			for(int i=0;i<lim;i++){
		if(ptr->fantacy==1){
			cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
		} ptr++;
	}
			break;
		}
		case 4:{cout<<"                           *Romantic Movies*"<<endl;
			for(int i=0;i<lim;i++){
		if(ptr->romantic==1){
			cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
		} ptr++;
	}
			break;
		}
		case 5:{cout<<"                           *Romantic Comedy Movies*"<<endl;
			for(int i=0;i<lim;i++){
		if(ptr->romantic==1 && ptr->comedy==1){
			cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
		} ptr++;
	}
			break;
		}
		case 6:{ cout<<"                           *Crime Movies* "<<endl;
			for(int i=0;i<lim;i++){
		if(ptr->crime==1){
			cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
		} ptr++;
	}
			break;
		}
		case 7:{cout<<"                           *Drama Movies*"<<endl;
			for(int i=0;i<lim;i++){
		if(ptr->drama==1){
			cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
		} ptr++;
	}
			break;
		}
		case 8:{cout<<"                           *Westren Movies*"<<endl;
			for(int i=0;i<lim;i++){
		if(ptr->westren==1){
			cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
		} ptr++;
	}
			break;
		}
		case 9:{cout<<"                           *Action Movies*"<<endl;
			for(int i=0;i<lim;i++){
		if(ptr->action==1){
			cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
		} ptr++;
	}
			break;
		}
		case 10:{cout<<"                           *Advanture Movies*"<<endl;
			for(int i=0;i<lim;i++){
		if(ptr->adventure==1){
			cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
		} ptr++;
	}
			break;
		}
		case 11:{cout<<"                           *War Movies*"<<endl;
			for(int i=0;i<lim;i++){
		if(ptr->war==1){
			cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
		} ptr++;
	}
			break;
		}
		case 12:{cout<<"                           *Action Crime Movies*"<<endl;
			for(int i=0;i<lim;i++){
		if(ptr->action==1 && ptr->crime==1){
			cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
		} ptr++;
	}
			break;
		}
		case 13:{cout<<"                           *War Drama Movies*"<<endl;
			for(int i=0;i<lim;i++){
		if(ptr->war==1 && ptr->drama==1){
			cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
		} ptr++;
	}
			break;
		}
		case 14:{
			for(int i=0;i<lim;i++){
		if(ptr->war==1 && ptr->action==1){
			cout<<"                           *War Action Movies*"<<endl;
			cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
		} ptr++;
	}
			break;
		}
		case 15:{cout<<"                           *Musical Movies*"<<endl;
			for(int i=0;i<lim;i++){
		if(ptr->musical==1){
			cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
		} ptr++;
	}
			break;
		}
		case 16:{cout<<"                           *Biography Movies*"<<endl;
			for(int i=0;i<lim;i++){
		if(ptr->biography==1){
			cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
		} ptr++;
	}
			break;
		}
		case 17:{cout<<"                           *Teen Movies*"<<endl;
			for(int i=0;i<lim;i++){
		if(ptr->teen==1){
			cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
		} ptr++;
	}
			break;
		}
		case 18:{cout<<"                           *Mystry Movies*"<<endl;
			for(int i=0;i<lim;i++){
		if(ptr->mystry==1){
			cout<<ptr->name<<", "<<ptr->year<<", "<<" IMDB: "<<ptr->imdb<<endl;
		} ptr++;
	}
			break;
		}
		
	}
	 cout<<endl;
}

void SerPer(vector<Person>& vec){
	cout<<"Enter name of the person you want to search: "; 
	string x;
	int check=0;
	cin.ignore();
	getline(cin,x);
	
	for(unsigned int i=0; i<vec.size();i++){
		if(uppercaseIt(x).compare(uppercaseIt(vec[i].name))==0){ check++;
			vec[i].getperson();
			break;
		}
	}
	if(check==0){
		cout<<"No result found"<<endl;
	}
}

void returnP(Movie* ptr,int lim, vector<Person>& vec){
	Movie* temp=ptr;
	cout<<"Enter name of the person returning money "; 
	string x;
	int check=0,pr=0;
	cin.ignore();
	getline(cin,x);
	
	bool cond=1;
	cout<<"Is the DVD in Good Condition? Enter 1 for yes or 0 for no: ";
	cin>>cond;
	try{
	if(cond==0){
		throw "This DVD can not be returned"; 
	}
	else{
	for(unsigned int i=0; i<vec.size(); i++){
		if(uppercaseIt(x).compare(uppercaseIt(vec[i].name))==0){ check++;
			for(int k=0; k<lim; k++){
				if(vec[i].Mname==ptr->name){
				pr=ptr->price;
				ptr->quan=ptr->quan+vec[i].quan;
				break;
			} ptr++;
		}
		ptr=temp;

		cout<<"Money to be returned is "<<vec[i].pay-vec[i].quan*pr*20/100<<"Rs"<<endl;
		
		ptr->account=(ptr->account-vec[i].pay)+vec[i].quan*pr*20/100;
		cout<<"Duration: "<<vec[i].dur<<" Days"<<endl;
		vec.erase(vec.begin()+i);
		}
	}
	if(check==0){
		cout<<"No result found"<<endl;
	}
}
}
catch(const char* msg){
	cout<<msg<<endl;
}
}

void Ifun(){
	STARTUPINFO SI = {0};
	PROCESS_INFORMATION PI = {0};
	
	BOOL bSucess = CreateProcess(TEXT("C:\\Program Files (x86)\\VideoLAN\\VLC\\vlc.exe"),NULL,NULL,NULL,FALSE,NULL,NULL,NULL,
	&SI,&PI);
	
	if(bSucess){
	cout<<"Movie Started: "<<endl;
	//cout<<"Process Id: "<<PI.dwProcessId<<endl;
	}
}

void PerT(vector<Person>& vec){
	cout<<"Enter Duration: ";
	int x;
	int check=0;
	cin>>x;
	for(unsigned int i=0; i<vec.size();i++){
		if(x>=vec[i].dur){ check++;
			if(check==1){
				cout<<endl<<"Duration of people with time more than "<<x<<" days"<<endl<<endl;
			}
			cout<<"Name: "<<vec[i].name; cout<<", Contact: "<<vec[i].contact<<", Movie: "<<vec[i].Mname<<", Quantity: "<<vec[i].quan<<endl<<endl;
		}
	}
	if(check==0){
		cout<<"No result found"<<endl;
	}
}

void SerNs(vector<Person>& vec){
		int check=0;
		for(unsigned int i=0; i<vec.size();i++){
			check++;
			if(check==1){
				cout<<"Here is a list of people: "<<endl<<endl;
			}
			cout<<"Name: "<<vec[i].name; cout<<", Contact: "<<vec[i].contact<<", Movie: "<<vec[i].Mname<<", Quantity: "<<vec[i].quan<<endl<<endl;
		}
	if(check==0){
		cout<<"No result found"<<endl;
	}
}

int main(){
	
	ifstream checklen;
	int alen=0;
	string line;
	checklen.open("Name.txt");
	while(!checklen.eof()){
	getline(checklen,line);
    alen++;
	}
	checklen.close();
	
	Movie *ptr,*temp;
	ptr=new Movie[alen];
	temp=ptr;
	readdata(ptr,alen);
	cout<<"Size of Movie Objects in Array in bytes "<<sizeof(Movie)<<endl;
	cout<<"Size of Movie Pointer of Class in bytes "<<sizeof(Movie*)<<endl;
	
	std::vector<Person> vec;
	int vlen=0;
	checklen.open("PersonName.txt");
	while(!checklen.eof()){
	getline(checklen,line);
    vlen++;
	}
	checklen.close();
	Person obj;
	for(int i=0; i<vlen; i++){
		vec.push_back(obj);
	}
	readperson(vec);
	cout<<"Size of Person Objects in Vector in bytes "<<sizeof(vector<Person>)<<endl;      
	string pass=" ";
	int ch=0;
	cout<<"                                     							Hello Administrator"<<endl;
	hi: cout<<"                                     						  Enter Passward to continiue: ";
	cin>>pass;
	if(pass=="420420"){
	system("cls");
	cout<<alen<<" Movies in store"<<endl;
	cout<<"                                     								Welcome!"<<endl<<endl;		
	}
	else{
		ch++;
		if(ch<3){
		cout<<"                                     						  You typed incorrect Passward"<<endl ;
		cout<<"                                     							 "<<3-ch<<" Tries remaining"<<endl;
		goto hi;
		}
		cout<<"                                     							Your Password was Incoreect 3 times";
		exit (EXIT_FAILURE);
	}
		
	int opt=0;
	do{
    cout << "                                      								*MENU*" <<endl<<endl;
    cout << "\n 											1) Search Movie by Name";
	cout<<" \n\n 											2) Search Movie Through Actor Name";
	cout<<" \n\n 											3) Search Movies by Director";
	cout<<" \n\n 											4) Search by Release Year"; 
	cout<<" \n\n 											5) Names of Available Movie";
	cout<<" \n\n 											6) See Movies by Genre";
	cout<<" \n\n 											7) Search Related Person";
	cout<<" \n\n 											8) Sell Movies";
	cout<<" \n\n 											9) Add a New Movie to Shop";
	cout<<" \n\n 											10) Save Movies Data to HDD";
	cout<<" \n\n 											11) See account";
	cout<<" \n\n 											12) Edit Movie";
	cout<<" \n\n 											13) Search Customer Details";
	cout<<" \n\n 											14) Returning DVDs";
	cout<<" \n\n 											15) See the people who have DVDs and more";
	cout<<" \n\n 											16) Exit";
	cout<<" \n\n 											Option ";
	cin >> opt;
    
  	if(opt==1){ 
	  		system("cls");
  			cout <<"                       	***** Search Movie ***** "<<endl;
			MovieSearch(ptr,alen);
			cout<<endl<<endl<<"Press 1 to Play: ";
			int play=0;
			cin>>play;
			if(play==1){
			Ifun();}
		}
	else if(opt==2){ 
			system("cls");
			cout <<"                       	***** Search Movie Through Actor Name ***** "<<endl;
			actors(ptr, alen);
			cout<<endl<<endl<<"Press 1 to Play: ";
			int play=0;
			cin>>play;
			if(play==1){
			Ifun();}
		}
	else if(opt==3){ 
			system("cls");
			cout <<"                       	***** Search Movies by Director ***** "<<endl;
			directorscut(ptr,alen);
		}
	else if(opt==4){
			system("cls");
			cout <<"                       	***** Search Movies by Year ***** "<<endl;
			yearsandyears(ptr,alen);
		}
	else if(opt==5){ 
			system("cls");
			cout << "                       	***** Names of Available Movies ***** "<<endl;
			try{
			AvlMovies(ptr,alen);
			}
			catch(const char* dis){
				cout<<dis<<endl;
			}
		}
	else if(opt==6){ 
			system("cls");		cout << "                       	***** See Movie by Geners ***** "<<endl;	
			GenSer(ptr,alen);
		}
	else if(opt==7){ 
			system("cls");
			cout <<"                       	***** Seach anyone for movies ***** "<<endl;
			Reated(ptr,alen);
		}
	else if(opt==8){
			system("cls");
			cout <<"                           ***** Sell Movie ***** "<<endl;
			SellM(ptr,alen,vec);
		}
	else if(opt==9){
			system("cls");
			cout <<"                           ***** Add Movie ***** "<<endl;
			ptr=addmovie(ptr,alen);
			temp=ptr;
			alen++;
		}
	else if(opt==10){
			system("cls");
			cout <<"                       	*Saving... It May Take Some Time...* "<<endl;
	 		saveperson(vec);
			savedata(ptr,alen);
			Sleep(1000);
			system("cls");
			cout<<"                         *SAVED*"<<endl<<endl;
	 }
	else if(opt==11){ 
			system("cls");
			cout<<"                       	Checking Internet Connection....";
			Sleep(300);
			system("cls");
			cout<<"                       	Getting Access....";
			Sleep(300);
			system("cls");
		
			cout <<"                       	Your money in account is "<<endl;
			cout<<ptr->getaccount();
		}
	else if(opt==12){
			system("cls");
			cout <<"                       	Editing Movie "<<endl;
			EditMovie(ptr, alen);
			}
	else if(opt==13){
		system("cls");
		SerPer(vec);
	}
	else if(opt==14){
		system("cls");
		returnP(ptr,alen,vec);
	}
	else if(opt==15){
		int k=0;
		system("cls");
		cout<<"								Press 1 for search by time and 2 to see list of names of booked people: ";
		cin>>k;
		if(k==1){
		PerT(vec);
		}
		else if(k==2){
			SerNs(vec);
		}
	}
	else if(opt==16){
			system("cls");
			cout <<" 											*Saving All Data Before Shutting Down* "<<endl;
	 		saveperson(vec);
			savedata(ptr,alen);
			Sleep(600);
			system("cls");
			cout<<" 											Thanks For Visiting Hope You Come again "<<endl;
			return 0;
		}
}while(opt!=0);
}
