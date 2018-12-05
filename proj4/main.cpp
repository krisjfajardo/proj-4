#include<iostream>
#include <cstdio>
#include <stdlib.h>
#define SIZE 10

using namespace std;

string upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string lowerCase = "abcdefghijklmnopqrstuvwxyz";

string numbers = "0123456789";

struct StudentRecord
{
int id;
string name;
string address;
double averageScore;
double pointer;
};

class STACK

{
private:
StudentRecord record[SIZE];
int top;
int size;

public:

STACK();

int push(StudentRecord);
StudentRecord pop();
int isEmpty();
int isFull();
void displayItems();
void fillData(StudentRecord*, int, STACK*);
void increaseStackCapacity(STACK *);

};

STACK::STACK()
{
    top=-1;
    size = SIZE;
}

int STACK::isEmpty()
{

    if(top==-1)
    return 1;

    else
    return 0;

}

int STACK::isFull()
{
    if(top==(SIZE-1))
    return 1;

    else
    return 0;

}

int STACK::push(StudentRecord data){
if(isFull()){
increaseStackCapacity(this);

}

++top;

record[top]=data;

return 1;

}

StudentRecord STACK::pop(){

StudentRecord temp;

temp=record[top];

--top;

return temp;

}

void STACK::fillData(StudentRecord * arr, int size, STACK *r){

for(int i = 0; i < size; i++){

if(!(r->isFull())){

r->push(arr[i]);

}

}

}

void STACK::displayItems(){

int i;

cout << top << endl;

for(i=(top); i>=0; i--){

cout << "Student Id: " << this->record[i].id << endl;

cout << "Name: " << this->record[i].name << endl;

cout << "Address: " << this->record[i].address << endl;

cout << "Average Score: " << this->record[i].averageScore << endl;

cout << endl;

}

// cout<<endl;

}

void STACK::increaseStackCapacity(STACK * obj){

STACK * newStack = new STACK();

for(int i = 0; i< size; i++){

newStack->record[i] = this->record[i];

}

obj = newStack;

size = size*2;

}

static void printArrayData(StudentRecord * dataArray, int size){

for(int i = 0; i < size; i++ ){

cout << "Student Id: " << dataArray[i].id << endl;

cout << "Name: " << dataArray[i].name << endl;

cout << "Address: " << dataArray[i].address << endl;

cout << "Average Score: " << dataArray[i].averageScore << endl;

cout << endl;

}

}

static void createData(StudentRecord * arr, int size)
{

    for(int i = 0; i < size; i++)
    {

        int start = rand()% 26;
        int len = rand()%10;
        int idVal = rand() %10 + 1;

        string studentName = upperCase.substr(start,len);
        string addressVal = lowerCase.substr(start,len);

        double avg = rand() % 90;
        double pointer = (rand() % 9 ) + 1;

        StudentRecord newRecord;
        newRecord.address = addressVal;
        newRecord.name = studentName;
        newRecord.averageScore = avg;
        newRecord.id = idVal;

        arr[i] = newRecord;

    }

}

int main(){

STACK * obj = new STACK();

StudentRecord recordArray[10];

createData(recordArray,10);

//dispaying data after array creation;

printArrayData(recordArray, 10);

//pushing all array data to Stack Object;

cout << "pushing all array data to Stack Object" << endl;

obj->fillData(recordArray, 10, obj);

cout << endl << endl;

cout << "Popping 5 records" << endl;

for(int i = 0; i < 5; i++){

//poping 5 records

//cout << "poping " << i << endl;

if(obj->isEmpty()){

break;

}else{

StudentRecord temp = obj->pop();

cout << "Popped record : " << endl;

cout << "Student Id: " << temp.id << endl;

cout << "Name: " << temp.name << endl;

cout << "Address: " << temp.address << endl;

cout << "Average Score: " << temp.averageScore << endl;

cout << "Pointer: " << temp.pointer << endl;

cout << endl;

}

}

cout << "Displaying remaining records" << endl << endl;

obj->displayItems();

}
