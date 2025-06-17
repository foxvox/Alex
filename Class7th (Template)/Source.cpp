#include <iostream> 
#include <string> 

using namespace std;
constexpr int SIZE = 10;

template <typename T>
class Container
{
public:
	T arr[SIZE]{};
	int index;
public:
	Container()
		: index{ 0 }
	{
		for (int i = 0; i < SIZE; ++i)
		{
			arr[i] = (i + 1) * 10;
		}
	}

	void Add(T data)
	{
		arr[index++] = data;
	}

	const T operator[](int cnt)
	{
		if (cnt >= 0 && cnt < SIZE)
		{
			return arr[cnt];
		}
		else
		{
			cout << "idx out of bounds!" << endl;
			return 0;
		}
	}
};

//template <typename T> 
//bool IsSame(T lhs, T rhs)
//{
//	return lhs == rhs; 
//}
//
//template<>
//bool IsSame(const char* lhs, const char* rhs)
//{
//	/*string left = (string)lhs;
//	string right = (string)rhs;
//
//	return left.length() == right.length(); */ 
//	return strlen(lhs) == strlen(rhs); 
//}

int main()

{
#pragma region Template 
	/*cout << "IsSame? : " << IsSame<int>(5, 7) << endl;
	cout << "IsSame? : " << IsSame<char>('B', 'B') << endl;
	cout << "IsSame? : " << IsSame<float>(14.5f, 7.5f) << endl; */
#pragma endregion 
#pragma region 템플릿특수화
	// 특정 자료형만 다른 형식으로 동작시키는 기능입니다. 
	// cout << "IsSame? " << IsSame<const char*>("하늘에뜬해", "사람의모습") << endl;
#pragma endregion 
	Container<int> con;
	con.Add(70);
	con.Add(80);

	for (int i = 0; i < SIZE; i++)
	{
		cout << "con[" << i << "] : " << con[i] << endl;
	}

	cout << con[15] << endl; 
}
