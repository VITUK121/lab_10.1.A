#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <string.h>

using namespace std;

#pragma region enums
enum Majors {RI=1, IK, PZ, AI, KN, SA};
enum Subjects {Physics=1, Math, IT};
#pragma endregion enums

#pragma region student_struct
#pragma pack(push, 1) //less memory using
struct Student {
	string return_prizv() {
		return this->prizv;
	}
	unsigned short return_course() {
		return this->course;
	}
	string return_major() {
		switch (this->major) {
			case RI:
				return "RI";
			case IK:
				return "IK";
			case PZ:
				return "PZ";
			case AI:
				return "AI";
			case KN:
				return "KN";
			case SA:
				return "SA";
		}
	}
	unsigned short return_physics() {
		return this->physics;
	}
	unsigned short return_math() {
		return this->math;
	}
	unsigned short return_it() {
		return this->it;
	}
	void fill_class(int i) {
		int temp;
		cout << "Студент №" << i + 1 << endl;
		cout << "Прізвище: "; cin >> this->prizv;
		cout << "Курс: "; cin >> this->course;
		cout << "Спеціальність (RI=1, IK=2, PZ=3, AI=4, KN=5, SA=6): "; cin >> temp;
		this->major = (Majors)temp;
		cout << "Оцінка з фізики: "; cin >> this->physics;
		cout << "Оцінка з математики: "; cin >> this->math;
		cout << "Оцінка з інформатики: "; cin >> this->it;
	}
private:
	string prizv;
	unsigned short course;
	Majors major;
	unsigned short physics;
	unsigned short math;
	unsigned short it;
};
#pragma pack(pop)    // return old config 
#pragma endregion student_struct

#pragma region functions
void fill_arr(Student* arr, int n) {
	for (int i = 0; i < n; i++) {
		arr[i] = Student();
		arr[i].fill_class(i);
		cout << endl;
	}
}	

int calc_n(int n) {
	int res = 0;
	while (n != 0) {
		n /= 10;
		res++;
	}
	return res;
}

int lenOfLongestPrizv(Student* arr, int n) {
	int res = -1;
	for (int i = 0; i < n; i++) {
		if (static_cast<int>(arr[i].return_prizv().length()) > res) {
			res = static_cast<int>(arr[i].return_prizv().length());
		}
	}
	return res;
}

void printHeader(Student* arr, int n) {
	int width = lenOfLongestPrizv(arr, n);
	(width <= 8) ? (width = 8) : (NULL);
	int maxDigits = calc_n(n);

	cout << "=======================================================================";
	for (int i = 0; i < (maxDigits-1)+(width-8); i++) {
		cout << "=";
	}
	cout << endl;

	cout << "|" << setw(maxDigits) << right << "№";
	cout << "|" << setw(width) << left << "Прізвище" << "| Курс | Спеціальність | Фізика | Математика | Інформатика | " << endl;

	cout << "-----------------------------------------------------------------------";
	for (int i = 0; i < (maxDigits - 1) + (width - 8); i++) {
		cout << "-";
	}
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << "|" << setw(maxDigits) << right << i + 1;
		cout << "|" << setw(width) << left << arr[i].return_prizv();
		cout << "|" << setw(6) << left << arr[i].return_course();
		cout << "|" << setw(15) << left << arr[i].return_major();
		cout << "|" << setw(8) << left << arr[i].return_physics();
		cout << "|" << setw(12) << left << arr[i].return_math();
		cout << "|" << setw(13) << left << arr[i].return_it();
		cout << setw(13) << "|" << endl;
	}

	cout << "-----------------------------------------------------------------------";
	for (int i = 0; i < (maxDigits - 1) + (width - 8); i++) {
		cout << "-";
	}
	cout << endl;
}

int counter(Student* arr, int n) {
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i].return_physics() == 4 || arr[i].return_physics() == 5) {
			result++;
		}
	}
	return result;
}

float average(Student* arr, int n, Subjects subject) {
	unsigned short sum = 0;
	for (int i = 0; i < n; i++) {
		switch (subject) {
		case 1:
			sum += arr[i].return_physics();
			break;
		case 2:
			sum += arr[i].return_math();
			break;
		case 3:
			sum += arr[i].return_it();
			break;
		default:
			cout << "Wrong subject" << endl;
			return -1;
		}
	}
	return sum / (float)n;
}
#pragma endregion functions

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n;
	cout << "Введіть кількість студентів: "; cin >> n;

	Student* arr = new Student[n];
	fill_arr(arr, n);

	printHeader(arr, n);

	cout << "Середнє арифметичне з фізики: " << average(arr, n, Physics) << endl;
	cout << "Середнє арифметичне з математики: " << average(arr, n, Math) << endl;
	cout << "Середнє арифметичне з інформатики: " << average(arr, n, IT) << endl << endl;

	cout << "Кількість студентів, які отримали 4 або 5 з фізики: " << counter(arr, n) << endl;
	delete[] arr;
}