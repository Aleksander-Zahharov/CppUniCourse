#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath> 
#include <ctime>  // for time()
#include "container.h"

using namespace std;

int main()
{  
	cout << "============================== Stack Test ===========================" << endl;
	cout << "|=====> Push elements to s1 <=====|" << endl;
	// To Do
    Stack s1;
    srand(time(0));
    int count = 0;
    while (count < 5) {
        int num = s1.Gen_Random_Number();
        if (s1.isPrim(num)) {
            s1.push(num);
            count++;
        }
    }



    cout << "|=====> Sorting s1 elements into s2 <=====|" << endl;
    // To Do 
    Stack s2 = s1.Sort_Prim_Numbers(s1);

    cout << "|=====> Pop elements from s2 <=====|" << endl;
    //To Do 
    while (!s2.isEmpty()) {
        int val = s2.pop();
        cout << val;
        if (!s2.isEmpty()) cout << " ";
    }
    cout << endl;




	cout << "================================= End ===============================" << endl;


	cout << "============================== Queue Test ===========================" << endl;
	Queue<int> q1;
	cout << "|=====> Check Queue is empty <=====|" << endl;
	q1.DeQueue();  
	cout <<  "Done!! " << endl;
	cout << "|=====> Push elements to Queue <=====| " << endl;
	srand(time(0));
	q1.EnQueue(rand()%10);
	q1.EnQueue(rand()%10);
	q1.EnQueue(rand()%10);
	q1.EnQueue(rand()%10);
	q1.EnQueue(rand()%10);
	cout <<endl<< "Done!! " << endl;
	cout << "|=====> Check Queue is full <=====|" << endl;
	q1.EnQueue(60);
	cout << "Done!! " << endl;
	cout << "|=====> Display Queue elements <=====|" << endl;
	q1.PrintQueue();
	cout << "Done!! " << endl;
	cout << "|=====> Delete element <=====|" << endl;
	q1.DeQueue();
	cout << "Done!! " << endl;
	cout << "|=====> Display Queue elements <=====|" << endl;
	q1.PrintQueue();
	cout << "Done!! " << endl;
	cout << "|=====> Search in Queue <=====|" << endl;
	
	Queue<int> q2;
	for(int i = 0; i < MAX_SIZE; i++)
		q2.EnQueue(rand()%10);

	q2.PrintQueue();
	cout << "Enter a number to search: ";
	int num;
	cin >> num;
	q2.Search(num);
	cout << endl << "================================= End ===============================" << endl;

    // ===================== Circular Queue Test ======================
    cout << "====================== Circular Queue Test ======================" << endl;
    Queue<int> cq;
    cout << "|=====> Enqueue elements to full capacity <=====|" << endl;
    srand(time(0));
    for (int i = 0; i < MAX_SIZE; ++i) cq.EnQueue(rand() % 100);
    cout << endl;
    cout << "|=====> Dequeue two elements <=====|" << endl;
    cq.DeQueue();
    cq.DeQueue();
    cout << "|=====> Enqueue two more elements (wrap-around) <=====|" << endl;
    cq.EnQueue(101);
    cq.EnQueue(102);
    cout << endl;
    cout << "|=====> Display Circular Queue elements <=====|" << endl;
    cq.PrintQueue();
    cout << "Done!!" << endl;
    cout << "================================= End ===============================" << endl;
    
	cout << "=========================== Linked list Test ========================" << endl;
	Linkedlist list;
	list.addNode(10);
	list.addNode(20);
	list.addNode(30);
	list.addNode(40);
	list.addNode(50);
	list.addNode(60);
	list.addNode(70);
	list.addNode(80);
	list.addNode(90);
	cout << "Elements of the list are: ";
	list.printList();
	cout << "Length list is : " << list.lengthList() << endl;
	list.deleteNode_Index(2);
	cout << "Elements of the list are: ";
	list.printList();
	cout << "Length list is : " << list.lengthList() << endl;
	list.deleteNode_Index(2);
	cout << "Elements of the list are: ";
	list.printList();
	cout << "Length list is : " << list.lengthList() << endl;
	list.deleteNode_Data(40);
	cout << "Elements of the list are: ";
	list.printList();
	cout << "-----------------------------------------" << endl;
	list.isRange(200);
	list.searchNode(200);
	list.searchNode(10);
	cout << endl << "================================= End ===============================" << endl;
	
	system("pause");	// "Press any key to continue . . . "
	return 0;
}