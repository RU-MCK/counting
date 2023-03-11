#include <iostream>
#include <string>
using namespace std;

//Проверяем, что это число. Только числа выше нуля.
bool check_symbol(string str) {
  string right = "0123456789.";
  int count = 0, i;
  for (i = 0; (i < str.length()); i++) {
    for (int q = 0; (q < right.length()); q++) {
      if (str[i] == right[q]) {
        count++;
        continue;
      }
    }
  }
  if (count != i) {
    cout << "It is not fractional number!" << endl;
    cout << "Input fractional number " << endl;
    return false;
  }
  return true;
}
// Проверяем наличие точки и она одна
bool check_point(string str) {
  int count = 0;
  for (int i = 0; (i < str.length()); i++) {
    if (str[i] == '.') count++;
  }
  if (count != 1) {
    cout << "It is not fractional number!" << endl;
    cout << "Input fractional number " << endl;
    return false;
  }
  return true;
}
//--- Функция сортировки Selection sort
void sort(float array[],int size) {
  for (int i = 0; i < size -1; i++) {
    int min_index = i;
    for (int j = i + 1; j < size; j++) {
      if (array[j] < array[min_index])
        min_index = j;
    }
    if (min_index != i)
      swap(array[i], array[min_index]);
  }
}
void on_print(float array[],int size){
  for(int i = size-1; i >= 0; i--){
    cout << array[i] << "; ";
  }
}
int main() {
  const int sz = 3;
  float numbers[sz];
  int count = 0;
  cout << "Input " << sz << " fractional numbers: " << endl;
  do {
    string str;
    cin >> str;
    if (check_point(str) && check_symbol(str)) {
      numbers[count] = stof(str);
      count++;
    }
  } while (count < sz);
  sort(numbers,sz);
  on_print(numbers,sz);
}
