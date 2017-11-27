#include <stdio.h>
#include <stdlib.h>
#include <cassert>
#include <math.h> 
#define __ALL__ 1
#define __INV__ 2
#define canary 1337

typedef float Data;

class Stack
{
private:
	int canary1 = canary;
	size_t number = 0;
	size_t size = 0;
	Data* info = 0;

public:
	Stack(size_t);     		// конструктор    
	Stack(Stack &);			// конструктор копирования
	~Stack();                       // деструктор
 	
	void check();	     // проверка стека
	void push(Data);     // поместить элемент в вершину стека
	Data pop();	     // удалить элемент из вершины стека и вернуть его
	void dump(int);	     // вывод стека на экран через пробел
	Data get(size_t);    // n-й элемент от вершины стека
	size_t get_size();   // получить размер стека
	int is_empty();      // возвращает ненулевое значение, если стек пуст, 0 - в противном случае
	void clear();	     // иницилизировать стек нулями
	size_t get_number(); // возвращает номер следующего элемента
	void summ();	     // суммирует два верхних элемента стека и кладет сумму сверху
	void summ_in_first();// суммирует два верхних элемента стека и кладет в нижний из них
	void kv_yr();	     // верхний A, второй B, третий C, корни два следующих элемента стека

private:
	int canary2 = canary;
};

void Stack::check()
{
	assert(size);
	assert(&number);
	assert(size > 0);
	assert(info);
	assert(canary1 = canary);
	assert(canary2 = canary);

}
 
Stack::Stack(size_t maxSize):
	number(0), size(maxSize)
{		


	info = (Data*)calloc(1, size*sizeof(Data));
	
	Stack::check();

}
 
Stack::~Stack()
{
	free (info);
}


Stack::Stack( struct Stack& origin):


	number(origin.get_number()+1), size(origin.get_size())
{

	info = (Data*)calloc(1, size*sizeof(Data));

	Stack::check();


	size_t i = 0;
	for( i = 0 ; (i != origin.get_size() ) && ((&origin) -> info[i] != 0); i++)
	{
		info[i] = (&origin) -> info[i];

	}
	
}

size_t Stack::get_size()
{
	Stack::check();

	
	return size;

}


 
void Stack::push(Data n)
{
	Stack::check();


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
	Stack::check();


	assert(number > 0); 

	number--;
	
	return info[number]; 
}


void Stack::dump(int type)
{
	Stack::check();


	size_t i = 0;

	if(type == 1)
	{

		for (i = 0; (i != size) && (info[i] != 0); i++)
		{
			printf("%f ", info[i]);

		}
	}
	

	if(type == 2)
	{
		i = number-1;
		for (; i != 0; i--)
		{
			printf("%f ", info[i]);
		}
		printf("%f ", info[0]);
	}



}

int Stack::is_empty()
{
	Stack::check();


	return number;


}


void Stack::clear()
{
	Stack::check();


	size_t i = 0;
	for(; i < number; i++)
	{
		info[i] = 0;

	}	

}

size_t Stack::get_number()
{
	Stack::check();


	return number;

}

void Stack::summ()
{
	Stack::check();


	if(number < 2)
	{
		printf("Have no 2 elements in this Stack:	");
		Stack::dump(__ALL__);

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
	Stack::check();



	if(number < 2)
	{
		printf("Have no 2 elements in this Stack:       ");
		Stack::dump(__ALL__);

	}
	else
	{
		info[number-2] += info[number-1]; 
		number -= 1;
		info[number] = 0;
	}

}

void Stack::kv_yr()
{
	Stack::check();

	if(number < 3)
	{
		printf("Have no 3 elements in this Stack:	");
		Stack::dump(__ALL__);

	}

	float x1 = 0, x2 = 0, a = info[number-1], b = info[number-2], c = info[number-3];
	float D = b*b - 4*a*c;

	printf("\n%f  %f  %f\n", a, b, c);

	if( D < 0 )
	{
		printf("No roots, D = %f", D);
	}
	if( D == 0)
	{
		x1 = (-b+sqrt(D))/(2*a);
		x2 = x1;
	}
	if(D > 0)
	{
		x1 = (-b+sqrt(D))/(2*a);
		x2 = (-b-sqrt(D))/(2*a);
	}
	Stack::push(x1);
	Stack::push(x2);
}


int main()
{
	Data temp = 0;

	Stack first_Stack(1);
	
	first_Stack.push(2);
	first_Stack.summ();
	first_Stack.push(2);
	first_Stack.summ();

	first_Stack.push(1);

	first_Stack.push(-2);
	first_Stack.push(1);


	first_Stack.kv_yr();




	temp = first_Stack.pop();
	printf("\n\n");
	printf("%f == 1 ????\n", temp);
	Stack second_Stack(first_Stack);
	first_Stack.dump(__ALL__);
	printf("\n");
	second_Stack.dump(__INV__);
	second_Stack.push(23);
	printf("\n");
	second_Stack.dump(__ALL__);

	temp = second_Stack.is_empty();
        printf("\n\n");
        printf("%f == 6 ????\n\n", temp);



	return 0;
}

