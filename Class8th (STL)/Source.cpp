#include <iostream> 
#include <vector> 
#include <list> 
#include <string> 
#include <stack> 
#include <queue> 
using namespace std; 
int main()
{
#pragma region vector container 
	//vector<int> vec; 
	///*cout << vec.capacity() << endl;
	//vec.push_back(10);
	//cout << vec.capacity() << endl;
	//vec.push_back(20);
	//cout << vec.capacity() << endl;
	//vec.push_back(30); 
	//cout << vec.capacity() << endl;
	//vec.push_back(40); 	
	//cout << vec.capacity() << endl;
	//vec.push_back(50); 
	//cout << vec.capacity() << endl;*/ 
	//vec.reserve(10); 
	//
	//vec.push_back(10);	
	//vec.push_back(20);	
	//vec.push_back(30);	
	//vec.push_back(40);	
	//vec.push_back(50); 
	//
	//for (int i = 0; i < vec.size(); i++)
	//{
	//	cout << vec[i] << endl; 		
	//}
	//vec.pop_back(); 
	//cout << "pop_back() 후" << endl; 
	//for (int i = 0; i < vec.size(); i++)
	//{
	//	cout << vec[i] << endl;
	//}
#pragma endregion 
#pragma region list container 
	/*list<int> ls;

	ls.push_back(20);
	ls.push_back(30);
	ls.push_front(10);
	ls.pop_front();

	for (int el : ls)
	{
		cout << el << "\t";
	}
	ls.assign(7, 70);
	for (int el : ls)
	{
		cout << el << "\t";
	}
	cout << endl; */
#pragma endregion
#pragma region string container 
	/*string content = "League Of Lengend";
	cout << content << endl;
	content = "Battle Field";
	cout << content << endl;
	content.append(" 5");
	cout << content << endl; */
#pragma endregion 
#pragma region stack container 
	/*stack<int> st;
	st.push(10);
	st.push(20);
	st.push(30);
	st.push(40);
	st.push(50);

	cout << "st.size(): " << st.size() << endl;
	while (!st.empty())
	{
		cout << st.top() << endl;
		st.pop();
	}*/
#pragma endregion
#pragma region queue container 
	queue<int> qu;
	qu.push(10);
	qu.push(20);
	qu.push(30);
	qu.push(40);
	qu.push(50);
	cout << "qu.size(): " << qu.size() << endl;
	while (!qu.empty())
	{
		cout << qu.front() << endl;
		qu.pop();
	}
#pragma endregion 
}