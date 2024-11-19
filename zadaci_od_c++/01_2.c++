// 2.	Нaпиши С++ програм со две посебни функции кои едноставно ја триплираат вредноста на променливата count дефинирана
//  во main. Овие функции се:
// a.	Функцијата tripleCallByValue која предава копија од count, ја триплира нејзината вредност и ја враќа новата вредност
// b.	Функцијата tripleCallByReference која ja предава count како референцен параметар, ја триплира самата променлива и ја 
// враќа новата вредност на count

#include<iostream>
using namespace std;
int tripleCallByValue(int count)
{
    return count*count*count;
}
int tripleCallByReference(int &count)
{
    return count*count*count;
}
int main()
{
    int count;
    cout<<"vreni vrednost koja sakas da se triplira"<<endl;
    cin>>count;
    cout<<"vrednost na count "<<count<<endl;
    cout<<"vrednost na count po tripleCallByValue "<<tripleCallByValue(count)<<endl;
    cout<<"vrednota na count po tripleCallByReference "<<tripleCallByReference(count);


}
