/********************************************************************************

	James' TimeTagger v. 1.0

	By James Vaughan
	Professor Ping Chen
	CS 3304 Data and Information Structures Tu 8:30
	Spring 2013

	JTT_Queue.h
	JTT Queue class header

	This class is the queue data structure for storing chars, strings, numbers,
	and other data types.

	It is a standard FIFO queue with push, top, pop, and empty functions.

	Basic operations:
		Constructor: Constructs an empty queue
		empty: Checks if queue is empty
		enqueue: Modifies a queue by adding a value at the back
		front: Accesses the front queue value; leaves queue unchanged
		dequeue: Modifies a queue by removing the value at the front
		display: Displays the queue elements from front to back
		erase: Erases all queue elements, makes queue empty again
	Class Invariant:
		1. The queue elements (if any) are stored in consecutive positions in
		myArray
		2. 0 <= myFront, myBack, QUEUE_CAPACITY
		3. Queue's size < QUEUE_CAPACITY

********************************************************************************/

#include <string>
using namespace std;



//
///*
//#include <iostream>
//
//using namespace std;
//
//#ifndef JTT_QUEUE
//#define JTT_QUEUE
//
//const int QUEUE_CAPACITY = 128;
//typedef int QueueElement;
//
//class JTT_Queue
//{
//Public:
//	/***** Function Members *****/
//	/***** Constructor *****/
//	JTT_Queue();
//	/*------------------------------------------------------------------
//	Construct a Queue object
//
//	Precondition: None.
//	Postcondition: An empty Queue object has been constructed; myFront
//	and myBack are initialized to -1 and myArray is an array with
//	QUEUE_CAPACITY elements of type QueueElement.
//	------------------------------------------------------------------*/
//
//	bool empty() const;
//	/*------------------------------------------------------------------
//	Check if queue is empty.
//	Precondition: None.
//	Postcondition: True is returned if the queue is empty and false is
//	returned otherwise.
//	------------------------------------------------------------------*/
//
//	void enqueue(const QueueElement & value);
//	/*------------------------------------------------------------------
//	Add a value to a queue.
//
//	Precondition: value is to be added to this queue
//	Postcondition: value is added to back of queue provided there is
//	space; otherwise, a queue-full message is displayed and
//	execution terminated.
//	------------------------------------------------------------------*/
//
//	void display(ostream & out) const;
//	/*------------------------------------------------------------------
//	Output the values stored in the queue
//
//	Precondition: ostream out is open
//	Postcondition: Queue's contents, from front to back, have been
//	output to out.
//	------------------------------------------------------------------*/
//
//	QueueElement front() const;
//	/*------------------------------------------------------------------
//	Retrieve value at front of queue (if any).
//
//	Precondition: Queue is nonempty.
//	Postcondition: Value at front of queue is returned, unless queue is
//	empty; in that case an error message is displayed and a "garbage
//	value" is returned.
//	------------------------------------------------------------------*/
//
//	void dequeue();
//	/*------------------------------------------------------------------
//	remove value at front of queue (if any).
//
//	Precondition: Queue is nonempty.
//	Postcondition: Value at front of queue has been removed, unless
//	queue is empty; in that case, an error message is displayed.
//	------------------------------------------------------------------*/
//
//private:
//	/***** Data Members *****/
//	int myFront,
//		myBack;
//	QueueElement myArray[QUEUE_CAPACITY];
//};// end of class declaration
//
//#endif
//
///*
//using namespace std;
//
//class JTT_Queue
//{
//	public:
//		void TestOutput();
//};
//
//*/
//
//*/