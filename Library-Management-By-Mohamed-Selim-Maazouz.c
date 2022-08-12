#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//work made by Mohamed Selim Maazouz

//creation of the structure book 
typedef struct book book ;
struct book {
	
	char name [20];  
	char author [20];
	int pgnbr  ; 
	int available;
};


//creation of the list
typedef struct library {
	book val ;
	struct library *next;
	
}library;


//initialisation of the list
struct library * list = NULL ; 














//function add head()
addhead() {
	
	struct library *element = (struct library*) malloc(sizeof(struct library));
	
	printf("type the name of the book \n");
	scanf("%s",&element->val.name);
	
	printf("type the name of The author \n");
	scanf("%s",&element->val.author);
	
	printf("type the number of pages \n");
	scanf("%d",&element->val.pgnbr);
	
	printf("type 1 for available or 0 for unavailable \n");
	scanf("%d",&element->val.available);
	
	
	
	element->next = list ;
	
	list= element ;
	
}


//function add tail();
addtail(){
	struct library * p = list;
while (p->next!=NULL){
 	p=p->next;
}

	struct library * element = (struct library*) malloc(sizeof(struct library));
	
	printf("type the name of the book \n");
	scanf("%s",&element->val.name);
	
	printf("type the name of The author\n");
	scanf("%s",&element->val.author);
	
	printf("type the number of pages \n");
	scanf("%d",&element->val.pgnbr);
	
	element->next = NULL ; 
	p->next = element ; 
	
}




//function add middle()
addmiddle(){
	
	struct library * p = list;
	
	int i =0;
	printf("give the index of the box to be added : ");
	
	int n ;
	scanf("%d",&n);
printf("%d",n);
	
	
	
	struct library * element = (struct library*) malloc(sizeof(struct library));
	
	printf("type the name of the book \n");
	scanf("%s",&element->val.name);
	
	printf("type the name of The author \n");
	scanf("%s",&element->val.author);
	
	printf("type the number of pages \n");
	scanf("%d",&element->val.pgnbr);
	
	printf("type 1 for available or 0 for unavailable \n");
	scanf("%d",&element->val.available);
	
	while((p->next !=NULL ) && (i<n) )
	{
		p=p->next ;
		i++;
	}
	element->next = p->next ;
	p->next = element ; 
	
}










//function delete()

deletehead(){
	
	struct library *element; 
	element = list; 
	list = list->next;
	free(element);
}




deletetail(){

	
struct library * p = list;
while (p->next->next!=NULL){
 	p=p->next;
}
struct library *element; 
	element = p->next; 
	p->next=NULL;
	free(element);


}




deletemiddle(){
	struct library * p = list;
	int i =0;
	printf("give the index of the box to be added : ");
	int n ;
	scanf("%d",&n);
	printf("%d",n);
	
	while((p->next !=NULL ) && (i<n) )
	{
		p=p->next ;
		i++;
	}

struct library *element; 
	element = p->next;
	p->next=p->next->next;
	free(element);
}





//function display() 
display() {

struct library * p = list;

while (p!=NULL){
	printf("%s \n",p->val.name);
 	printf("%s \n",p->val.author);
 	printf("%d \n",p->val.pgnbr);
 	printf("\n\n");
 	p=p->next;
}


}

//tree liste order by Titre 
treeList(){
		system("cls");
	if(list!=NULL){
	

	int test=0;
	struct library * p = list;
	book val1,val2;  
	while (test==0){
		
		test=1;
		while(p->next!=NULL){
			
			if (p->val.name > p->next->val.name){
				val1=p->val;
				val2=p->next->val;
				p->val=val2;
				p->next->val=val1;
				test=0;
			}
			p=p->next;
		}
			
	}
	printf("sort successfull \n\n");
	}
	else{
		printf("the list is empty \n\n");
	}
}



//convert String to int
int convertInt(const char* str){
    int number = 0;
    int i = 0;
    int isNegetive = 0;
    if(str[i] == '-'){
        isNegetive = 1;
        i++;
    }
    while (str[i] && (str[i] >= '0' && str[i] <= '9')){
        number = number * 10 + (str[i] - '0');
        i++;
    }
    if(isNegetive==1) number = -1 * number;
    return number;
}




//divide the string word by word and fill in the list on tail
stringSplit(char string [50]){

int i;
struct library *element = (struct library*) malloc(sizeof(struct library));

char  *token ;
token= strtok(string, " ");//strtok split the string word by word
for(i=0;i<sizeof(token);i++)
element->val.name[i]=token[i];

token = strtok(NULL, " ");//permet d'avancer ver la deuxième mot
for(i=0;i<sizeof(token);i++)
element->val.author[i]=token[i];

token = strtok(NULL, " ");
element->val.pgnbr=convertInt(token);

token = strtok(NULL, " ");
element->val.available=convertInt(token);


element->next=NULL;
		
struct library *p=list ;
	if(p==NULL)
	{
		element->next=list;
		list=element;
	}
	else
	{
		while (p->next != NULL)
		{
			p=p->next;
		}
		p->next=element;
	}
} 



//read a file line by line
 
FillListByFile(){
	char string [50];
	FILE* file = NULL;
	file = fopen("library.txt", "r");
	    if (file != NULL)
    {
    	
			
        while (fgets(string, 50, file) != NULL) 
        {			
        
      		stringSplit(string);//a function which takes as a parameter a file line in the form of a string
			   	
		}
 
        fclose(file);
    }
}




//save the list in a text file
saveFile(){
	struct library * p =list;
	FILE* file = NULL;
	file = fopen("library.txt", "w");
	while (p!=NULL){
		fputs(p->val.name,file);
		fputs(" ",file);
		fputs(p->val.author,file);
		fputs(" ",file);
		fprintf(file,"%d",p->val.pgnbr);
		fputs(" ",file);
		fprintf(file,"%d\n",p->val.available);
		p=p->next;
	}
	fclose(file);
}







int main(int argc, char *argv[]) {

	addhead();
	addtail();
	addtail();
	addtail();
	addmiddle();
	deletehead();
	deletetail();
	deletemiddle();
	printf("\n\n\n\n");
	treeList();
	FillListByFile();
	saveFile();
	
	display();
	
	return 0;
}
