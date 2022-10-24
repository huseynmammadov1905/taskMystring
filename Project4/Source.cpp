



#include <iostream>

using namespace std;

//MyString
//1)1 ci xarakter qaytaran method
//2)sonuncu xarakter qaytaran method 
//3) Append(const char* text)  
//4) s.rfind('a') 
//5)s.find('w')//6 xarakterin indexi qayitsin
//6)s.clear()//string silinsin delete edin

/*
1. IntArray class-i yaradin. Bu class massiv rolunu
oynamalidir.
Novbeti imkanlar olsun:
- Massivin evveline reqem elave eden method
- Massivin sonuna reqem elave eden method
- Massivi copy etmek imkani yaradin
- Print
*/
//int Size(const char* string) {
//	int size = 0;
//	for (int i = 0; string[i] != '\0'; i++)
//	{
//		size++;
//	}
//	return size;
//}
//
//class MyString {
//	char* String;
//public:
//
//	MyString() {
//		SetString("string");
//	}
//
//	MyString(const MyString& obj) {
//		SetString(obj.String);
//	}
//
//
//
//	//~MyString() {
//	//	delete[] String;
//	//}
//
//#pragma region Setter and Getter
//
//	char* GetString() { return String; }
//
//	void SetString(const char* String) {
//		delete this->String;
//		this->String = new char[strlen(String) + 1];
//		strcpy_s(this->String, strlen(String) + 1, String);
//	}
//
//#pragma endregion
//	char firstChar() {
//		return String[0];
//	}
//
//
//
//	char lastChar(){
//		int i = 0;
//		char t;
//		for (; String[i] != '\0'; i++)
//		{
//			t = String[i];
//		}
//		return t;
//	}
//
//	int RFind(char str) {
//		
//		for (int i = Size(String); i > 0; i--)
//		{
//			if (str == String[i])
//				return i;
//		}
//	}
//	int Find(char str) {
//		int size = Size(String);
//		for (int i = 0; i < size  ; i++)
//		{
//			if (str == String[i])
//				return i;
//		}
//	}
//	void Print() {
//		cout << "string : " << String << endl;
//	}
//	
//	void Append(const char* text) {
//		int textSize = Size(text);
//		int stringSize = Size(String);
//		int allSize = textSize + stringSize;
//		char* temp = new char[allSize]{};
//		int i = 0;
//		for (; i <= stringSize; i++)
//		{
//			temp[i] = String[i];
//		}
//		int j = stringSize;
//
//		for (int k = 0; k <= textSize; j++)
//		{
//			temp[j] = text[k];
//			k++;
//		}
//		SetString(temp);
//	}
//
//	void SClear() {
//		delete[] String;
//	}
//};
//int main(){
//	MyString t;
//	t.Print();
//	cout << t.firstChar() << endl;
//	cout << t.lastChar() << endl;
//	t.Append("salam");
//	t.Print();
//	cout << t.Find('a') << endl;
//	cout << t.RFind('a') << endl;
//	cout << t.firstChar() << endl;
//	cout << t.lastChar() << endl;
//	t.SClear();
//
//}

class IntArray {
	int size;

	int* arr;

public:

	IntArray() {
		size = 3;
		arr = new int[size] {1, 2, 3};
	}

	IntArray(int* arr, int size) {
		SetSize(size);
		SetArr(arr);
	}


	IntArray(IntArray& obj) {
		size = obj.size;
		SetArr(obj.arr);
	}

#pragma region Setter and Getter

	int* GetArr() { return arr; }
	int GetSize() { return size; }

	void SetSize(int size) {
		this->size = size;
	}


	void SetArr(int* arr) {
		delete[] this->arr;
		this->arr = arr;
	}

#pragma endregion

	void BeforeNum(int num) {
		int* temp = new int[size + 1]{};
		temp[0] = num;
		int i = 0;
		int j = i + 1;
		for (; i < size; i++)
		{
			temp[j] = arr[i];
			j++;
		}
		delete[] arr;
		size++;
		arr = temp;
		temp = nullptr;
	}

	void AfterNum(int num) {
		int* temp = new int[size + 1]{};

		temp[size] = num;
		for (int i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		delete[] arr;
		size++;
		arr = temp;
		temp = nullptr;
	}

	void PrintArr() {
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}cout << endl;
	}

};

int main() {

	IntArray t;

	t.BeforeNum(2);
	t.AfterNum(97);
	t.PrintArr();

}