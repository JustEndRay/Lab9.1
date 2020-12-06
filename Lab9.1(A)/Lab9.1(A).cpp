#include <iostream>
#include <Windows.h>
#include <iomanip>
#include <string>

using namespace std;

#pragma pack(push, 1)

enum Speciality { ITIS, RE, KN, KI, PZ };
string speciality_str[] = { "Інформатика ",
                            "Радіоелектроніка", "Комп'ютерні науки",
                            "Комп'ютерна інженерія", "Програмне забезпечення" };

struct Students
{
    string surname;
    int course;
    Speciality speciality;
    int grade_physics;
    int grade_math;
    int computer_science;

};

#pragma pack(pop)

void Create(Students* S, const int N);
void List_of_students_with_good_grades(Students* S, const int N);
double Percentage_of_students_with_avarage_grade_higher_then_4_dot_5(Students* S, const int N);
void Print_first(Students* S, const int N);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int N;
    cout << "Введіть кількість студентів: "; cin >> N;

    Students* S = new Students[N];

    Create(S, N);
    Print_first(S, N);
    List_of_students_with_good_grades(S, N);
    cout << "Процент студентів, які мають середній бал вище за 4.5 = " << setprecision(2) << Percentage_of_students_with_avarage_grade_higher_then_4_dot_5(S, N) << "%";

    return 0;
}
void Create(Students* S, const int N)
{
    for (int i = 0; i < N; i++)
    {
        int speciality;
        cout << "Номер студента: " << i + 1 << endl;
        cin.get();
        cin.sync();
        cout << "Прізвище: "; getline(cin, S[i].surname); cout << endl;
        cout << "Курс: "; cin >> S[i].course; cout << endl;
        cout << "Спеціальність(0 - Інформатика, 1 - Радіоелектроніка, 2 - Комп'ютерні науки,";
        cout << "\n3 - Комп'ютерна інженерія, 4 - Програмне забезпечення): ";
        cin >> speciality;
        S[i].speciality = (Speciality)speciality;
        cout << "Оцінка з фізики: "; cin >> S[i].grade_physics; cout << endl;
        cout << "Оцінка з математики: "; cin >> S[i].grade_math; cout << endl;
        cout << "Оцінка з інформатики: "; cin >> S[i].computer_science; cout << endl;
        cout << endl;
    }

}
void List_of_students_with_good_grades(Students* S, const int N)
{
    cout << "Прізвища учнів, що вчаться на відмінно:" << endl;
    for(int i=0;i<N;i++)
    {
        if(S[i].grade_physics==5 && S[i].grade_math==5 && S[i].computer_science==5)
        {
            cout << S[i].surname <<  endl;
        }
    }
}
void Print_first(Students* S, const int N)
{
    cout << "=========================================================================================" << endl;
    cout << "|  №  |  Прізвище  |  курс  |  спеціальність  |  Фізика  |  Математика  |  Інформатика  |" << endl;
    cout << "-----------------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "|" << setw(3) << i + 1 << setw(3);
        cout << "|" << setw(4) << S[i].surname << setw(4);
        cout << "|" << setw(6) << S[i].course << setw(6);
        cout << "|" << setw(6) << speciality_str[S[i].speciality] << setw(6);
        cout << "|" << setw(6) << S[i].grade_physics << setw(6);
        cout << "|" << setw(6) << S[i].grade_math << setw(6);
        cout << "|" << setw(6) << S[i].computer_science << setw(6) << "|" << endl;
    }
    cout << "=========================================================================================" << endl << endl;
}
double Percentage_of_students_with_avarage_grade_higher_then_4_dot_5(Students* S, const int N)
{
    int k = 0;
    for (int i = 0; i < N; i++)
        if (((S[i].grade_physics + S[i].grade_math + S[i].computer_science)*1.0/3)>4.5)
            k++;
    return k / (N * 1.0) * 100;
}