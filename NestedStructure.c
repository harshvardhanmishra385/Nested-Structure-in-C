#include<stdio.h>
#include<string.h>

struct BOOK{
  char title[50];
  char author[50];
  float price;
};
typedef struct BOOK book;

struct STUDENT{
  char name[30];
  int roll;
  int year;
  char grade;
  book borrowed[3];
  int books_borrowed;
};
typedef struct STUDENT c;

void print_book(book *book);

void input_details(c*student){
  printf("ENTER THE DETAILS OF THE STUDENTS\n");
  printf("ENTER STUDENT NAME\n");
  fgets(student->name, sizeof(student->name), stdin);
  student->name[strcspn(student->name, "\n")] = 0;
  
  printf("ENTER STUDENT ROLL NUMBER\n");
  scanf("%d", &student->roll);
  
  printf("ENTER THE YEAR OF STUDENT IN COLLEGE\n");
  scanf("%d", &student->year);
  
  printf("ENTER THE GRADE OF THE STUDENT\n");
  scanf(" %c", &student->grade);
  
  printf("HOW MANY BOOKS HAS THE STUDENT BORROWED? (MAX 3)\n");
  scanf("%d", &student->books_borrowed);
  
  // Input validation
  if(student->books_borrowed > 3) student->books_borrowed = 3;
  if(student->books_borrowed < 0) student->books_borrowed = 0;
  
  // Clear buffer before fgets
  while(getchar() != '\n');
  
  // Take book details for each borrowed book
  for(int i = 0; i < student->books_borrowed; i++){
    printf("\nENTER DETAILS FOR BOOK %d\n", i+1);
    
    printf("ENTER BOOK TITLE\n");
    fgets(student->borrowed[i].title, sizeof(student->borrowed[i].title), stdin);
    student->borrowed[i].title[strcspn(student->borrowed[i].title, "\n")] = 0;
    
    printf("ENTER BOOK AUTHOR\n");
    fgets(student->borrowed[i].author, sizeof(student->borrowed[i].author), stdin);
    student->borrowed[i].author[strcspn(student->borrowed[i].author, "\n")] = 0;
    
    printf("ENTER BOOK PRICE\n");
    scanf("%f", &student->borrowed[i].price);
    while(getchar() != '\n');  // Clear buffer after scanf
  }
}

void print_student(c*student){
  printf("\n========================================\n");
  printf("STUDENT DETAIL\n");
  printf("NAME: %s , ROLL NO: %d from year %d, GOT %c REMARK\n", 
         student->name, student->roll, student->year, student->grade);
  
  printf("BOOKS BORROWED: %d\n", student->books_borrowed);
  printf("HERE ARE THE BOOKS BORROWED\n");
  
  for(int i = 0; i < student->books_borrowed; i++){
    print_book(&(student->borrowed[i]));
  }
  printf("========================================\n");
}

void print_book(book *book){
  printf("\n%s is written by %s, and is sold at %.2f", 
         book->title, book->author, book->price);
}

int main(){
  c student[3];
  
  for(int i = 0; i < 3; i++){
    printf("\n--- STUDENT %d ---\n", i+1);
    input_details(&student[i]);
  }
  
  printf("\n\n=========== ALL STUDENTS ===========\n");
  for(int i = 0; i < 3; i++){
    print_student(&student[i]);
  }
  
  return 0;
}