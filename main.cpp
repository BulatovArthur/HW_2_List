#include <iostream>
#include <cstdlib>

using namespace std;

struct List
{
	int a;
	List *next;
};

void Menu()
{
	cout << "Operations:" << endl;
	cout << "1. To Show" << endl;
	cout << "2. To Add" << endl;
	cout << "3. To Delete" << endl;
  	cout << "4. To Find" << endl;
  	cout << "5. To Replace" << endl;
  	cout << "6. To Sort" << endl;
  	cout << "7. To Delete The List" << endl;
	cout << "8. To Finish" << endl;
}

void Making_List(int *array, List **first, int argc)
{
	(*first) = new List;

	(*first)->a = *(array + 1);
	(*first)->next = nullptr;
	List *curr = *first;

	for (int i = 2; i < argc; i++)
	{
		curr->next = new List;
		curr = curr->next;
		curr->a = *(array + i);
		curr->next = nullptr;
	}
}

void Print(List *first)
{
	List *print = first;
	if (print == nullptr)
	{
		cout << "The list is empty." << endl;
		cout << endl;
	}
	else
	{
		do
		{
			cout << print->a;
			if (print->next)
				cout << " -> ";
			print = print->next;
		} while (print);
		cout << endl;
	}
}

void Add(List **first)
{
        cout << "Count of elements: ";
        int count;
        cin >> count;
        cout << "Enter elements: ";
        int *mas = new int[count];
        for (int i = 0; i < count; i++)
                cin >> mas[i];
	List *t = *first;
	List *t1 = t->next;
        while (t1)
        {
                t = t1;
                t1 = t1->next;
        }
	List *ins = t;
        for (int i = 0; i < count; i++)
        {
                ins->next = new List;
                ins = ins->next;
                ins->a = *(mas + i);
                ins->next = nullptr;
        }
	delete []mas;
}

void Delete(List **first)
{
	if ((*first) == nullptr)
	{
        	cout << "The list is empty." << endl;
		cout << endl;
	}
	else
	{
		cout << "Element for deleting: ";
		int b;
		cin >> b;
		List *t = *first;
		if (t->a == b)
		{
			*first = t->next;
			delete t;
			return;
		}
		List *t1 = t->next;
		while (t1)
		{
			if (t1->a == b)
			{
				t->next = t1->next;
				delete t1;
				return;
			}
			t = t1;
			t1 = t1->next;
		}
		cout << "The list don't have this element. Repeat again" << endl;
		cout << endl;
	}
}

void Find(List **first)
{
	List *curr = *first;
	int element = 0;
	int count = 0;
	bool logic_decision = false;
	cout << "Enter element to find: ";
	cin >> element;
	while (curr != nullptr)
	{
		if (curr->a == element)
		{
			cout << "Position: " << count << " ";
			logic_decision = true;
		}
		count++;
		curr = curr->next;
	}
	if (logic_decision == false)
		cout << "The list don't have this element.";
	cout << endl;
}

void Replace(List **first)
{
	int pos = 0, new_el;
	int i = 0;
	cout << "Position: ";
	cin >> pos;
	cout << "New element: ";
	cin >> new_el;
	bool el_abil = false;
	List *curr = (*first);
	while (curr != nullptr)
	{
		if (i == pos)
		{
			curr->a = new_el;
			el_abil = true;
		}
		curr = curr -> next;
		i++;
	}
	if (el_abil == false)
		cout << "Error. Repeat again.";
}

void Sort(List **first)
{
	for (List *curr = (*first); curr != nullptr; curr = curr->next)
	{
		for (List *curr1 = (*first); curr1 != nullptr; curr1 = curr1->next)
		{
			if ((curr->a) < (curr1->a))
				swap(curr->a,curr1->a);
		}
	}
}

void Free(List **first)
{
	if (*first == 0)
		return;
	List *p = *first;
	List *t;
	while (p)
	{
		t = p;
		p = p->next;
		delete t;
	}
	*first = nullptr;
}

int main(int argc, char *argv[])
{
	int *array = new int[argc-1];

	for (int i = 1; i < argc; i++)
		array[i] = atoi(argv[i]);

	List *first = nullptr;

	if (argc == 1)
		List *first = nullptr;
	else
		Making_List(array, &first, argc);
	int op = 0;
	string ex;
	while ((ex != "y") && (ex != "yes"))
	{
		Menu();
		cin >> op;
		switch(op)
		{
			case 1:
				Print(first);
				break;
			case 2:
				Add(&first);
				break;
			case 3:
				Delete(&first);
				break;
			case 4:
				Find(&first);
				break;
			case 5:
				Replace(&first);
				break;
			case 6:
				Sort(&first);
				break;
			case 7:
				Free(&first);
				delete []array;
				break;
			case 8:
				cout << "Are you ready?" << endl;
				cin >> ex;
				if (ex == "y")
					cout << "Good luck!";
				return 0;
			default:
				cerr << "Error" << endl;
		}
	}
	return 0;
}
