#include <stdio.h>
#include <stdlib.h>
#include <cassert> 


typedef int Data;

class Stack
{
private:
	size_t number = 0;
	size_t size = 0;
	Data* info = 0;

public:
	Stack(size_t);     		// конструктор    
	Stack(Stack &);			// конструктор копирования
	~Stack();                       // деструктор
 
	void push(Data);     // поместить элемент в вершину стека
	Data pop();	     // удалить элемент из вершины стека и вернуть его
	void print();        // вывод стека на экран через пробел
	Data get(size_t);    // n-й элемент от вершины стека
	size_t get_size();   // получить размер стека
	int is_empty();      // возвращает ненулевое значение, если стек пуст, 0 - в противном случае
	void clear();	     // иницилизировать стек нулями
	size_t get_number(); // возвращает номер следующего элемента
	void summ();	     // суммирует два верхних элемента стека и кладет сумму сверху
	void summ_in_first();// суммирует два верхних элемента стека и кладет в нижний из них
};
 
 
Stack::Stack(size_t maxSize)
{		
	assert(maxSize);
	
	size = maxSize;

	assert(&number);

	info = (Data*)calloc(1, size*sizeof(Data));
	
	assert(info);

	number = 0;

}
 
Stack::~Stack()
{
	free (info);
}


Stack::Stack( struct Stack& origin)
{

	size = origin.get_size();
	assert(&number);

	info = (Data*)calloc(1, size*sizeof(Data));

	assert(info);

	size_t i = 0;
	for(; (i != origin.get_size() ) && ((&origin) -> info[i] != 0); i++)
	{
		info[i] = (&origin) -> info[i];

	}

	number = origin.get_number()+1;
}

size_t Stack::get_size()
{

	return size;

}


 
void Stack::push(Data n)
{

	if (number ==  size)
	{
		size++;
		info = (Data*)realloc(info, size*sizeof(Data));
		assert(info);		

	} 
		
	info[number] = n;
	number++;

}
 


Data Stack::pop()
{
	assert(number > 0); 

	number--;
	
	return info[number]; 
}


void Stack::print()
{
	size_t i = 0;

	for (i = 0; (i != size) && (info[i] != 0); i++)
	{
		printf("%d ", info[i]);

	}


} 

int Stack::is_empty()
{

	return number;


}


void Stack::clear()
{
	size_t i = 0;
	for(; i < number; i++)
	{
		info[i] = 0;

	}	

}

size_t Stack::get_number()
{
	return number;

}

void Stack::summ()
{
	if(number < 2)
	{
		printf("Have no 2 elements in this Stack:	");
		Stack::print();

	}
	else
	{

		if (number ==  size)
		{
			size++;
			info = (Data*)realloc(info, size*sizeof(Data));
			assert(info);
		}


		info[number] = info[number-1] + info[number-2];
		number++; 


	}
	


}

void Stack::summ_in_first()
{

	if(number < 2)
	{
		printf("Have no 2 elements in this Stack:       ");
		Stack::print();

	}
	else
	{
		info[number-2] += info[number-1]; 
		number -= 1;
		info[number] = 0;
	}

}


int main()
{
	Data temp = 0;

	Stack first_Stack(1);
	
	first_Stack.push(322);
//	first_Stack.summ();
	first_Stack.push(322);
//	first_Stack.summ();

	first_Stack.push(322);

	first_Stack.push(322);
	first_Stack.summ_in_first();
	first_Stack.push(322);







	temp = first_Stack.pop();
	printf("\n\n");
	printf("%d == 228 ????", temp);
	Stack second_Stack(first_Stack);
	first_Stack.print();
	printf("\n");
	second_Stack.print();
	second_Stack.push(23);
	printf("\n");
	second_Stack.print();

	temp = second_Stack.is_empty();
        printf("\n\n");
        printf("%d == 228 ????", temp);




	return 0;
}

