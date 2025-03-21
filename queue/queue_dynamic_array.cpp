#include "queue_dynamic_array.h"
using namespace std;
arrayQueueType::arrayQueueType(int size) {
		if (size <= 0)
			maxSize = 100;
		else
			maxSize = size;
		Front = 0;
		arr = new int[maxSize+1];
		rear = maxSize - 1;
		length = 0;
}
int arrayQueueType::isEmpty()
{
	return length == 0;
}
bool arrayQueueType::isFull()
{
	return length == maxSize;
}
void arrayQueueType::addQueue(int Element)
{
	if (isFull())
	{
		cout << "Queue Full Can't Enqueue ...!";
	}
	else
	{
		rear = (rear + 1) % maxSize;
		arr[rear] = Element;
		length++;
	}


}
void arrayQueueType::deleteQueue()
{
	if (isEmpty())
	{
		cout << "Empty Queue Can't Dequeue ...!";
	}
	else
	{
		Front = (Front + 1) % maxSize;
		--length;

	}
}
int arrayQueueType::frontQueue()
{
	assert(!isEmpty());
	return arr[Front];
}

int arrayQueueType::rearQueue()
{
	assert(!isEmpty());
	return arr[rear];
}
void arrayQueueType::printQueue()
{
	if (!isEmpty()) {
		for (int i = Front; i != rear; i = (i + 1) % maxSize)
		{
			cout << arr[i] << " ";
		}
		cout << arr[rear];
	}
	else
		cout << "Empty Queue";
}


int arrayQueueType::queueSearch(int element) {
	int pos = -1;
	if (!isEmpty())
	{
		for (int i = Front; i != rear; i = (i + 1) % maxSize)
			if (arr[i] == element)
			{
				pos = i;
				break;
			}
		if (pos == -1)
		{
			if (arr[rear] == element)
				pos = rear;
		}
	}
	else
		cout << "Q is empty ! " << endl;
	return pos;
}

arrayQueueType::~arrayQueueType() {
	delete[]arr;
}
int main()
{
	arrayQueueType q1(5);
	q1.addQueue(10);
	q1.addQueue(20);
	q1.addQueue(30);
	q1.addQueue(40);
	q1.addQueue(50);
	q1.printQueue();
	return 0;
}
