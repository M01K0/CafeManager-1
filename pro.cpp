#include<iostream>
#include<cstring>
using namespace std;
struct item{
	char name[15];
	double price;
}add,get;

// to insert new items
void insert(){
	system("cls");
	
	cout<<"enter food name\n";
	cin>>add.name;
	cout<<"enter food price\n";
	cin>>add.price;
	FILE *open;
	open=fopen("data.txt","a+");
	fprintf(open,"%s %lf",add.name,add.price);
	fclose(open);
	printf("inserted successfully\n");
}

// to return price for food
double getPrice(){
	char name[15];
	system("cls");
	cout<<"enter food name to get price\n";
	cin>>get.name;
	FILE *open;
	open=fopen("data.txt","r");
	while(fscanf(open,"%s %lf",&add.name,&add.price)!=EOF){
		if(strcmp(get.name,add.name)==0){
			return add.price;
		}
	}
	return 0;
		
}

// to generate bill
void generate(){
	int c=1,qty=0;char name[15];double totalprice=0,price=0,subprice=0;
	system("cls");
	while(c==1){	
	cout<<"enter food name to get price\n";
	cin>>get.name;
	cout<<"enter quantity\n";
	cin>>qty;
	FILE *open;
	open=fopen("data.txt","r");
	while(fscanf(open,"%s %lf",&add.name,&add.price)!=EOF){
		if(strcmp(get.name,add.name)==0){
			price=add.price;
		}
	}
	subprice=price*qty;
	totalprice=totalprice+subprice;
	
	cout<<"ITEM\t\tPrice\t\tSubprice\n";
	cout<<"---------------------------------------\n";
	cout<<get.name<<"\t\t"<<price<<"\t\t"<<subprice<<endl;
	cout<<"---------------------------------------\n";
	
	cout<<"DO you want to continue 1. cont 0. exit\n";
	cin>>c;
}
cout<<"---------------------------------------\n";		
cout<<"\tTOTAL:\t"<<totalprice<<endl;		
cout<<"---------------------------------------\n";		
		
	
}



int main(){
	int ch,def=1;
	
	while(def==1){
	system("cls");
	cout<<"MENU LIST\n1.Insert Food \n2.Get Price\n3.Generate Bill\n4.Exit\nEnter your choice";
	cin>>ch;
	switch(ch){
		case 1:
			insert();break;
			
		case 2:
			cout<<getPrice()<<endl;break;
		case 3:
			generate();break;
		case 4: exit(0);
	}
	cout<<"Do you want to continue 1. continue \t 2. exit \n Enter your choice\n";
	cin>>def;
}
	
	return 0;
}
