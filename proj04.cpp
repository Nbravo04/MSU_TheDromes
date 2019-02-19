#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string;
#include<algorithm>
using std::sort;

// meta, strictly increase
// plain, non-strictly increase
// kata, strictly decrease
// nialp, non-strictly decrease
// non, none of the above

const string base_vals = "0123456789abcdefghijklmnopqrstuvwxyz";

//Functions
bool check_base (string n, int base){
  string t = n ;
  sort(t.begin(), t.end());
  char t_last = t.back();
  int t_val = base_vals.find(t_last);
  if (t_val > base)
    return 0;
  else
    return 1;
}

bool metadrome (string n, int base){
  int check_n = 0;
  if (check_base(n, base)){
    check_n = 1;
    for (int i=0; i < n.length()-1; i++){
      char x = n[i];
      char y = n[i+1];
      if (x >= y){
        check_n = 0;
        break;
      }
    }
  return check_n;
  }
  else
    return check_n;
}

bool plaindrome (string n, int base){
  int check_n = 0;
  if (check_base(n, base)){
    check_n = 1;
    for (int i=0; i < n.length()-1; i++){
      char x = n[i];
      char y = n[i+1];
      if (x > y){
        check_n = 0;
        break;
      }
    }
  return check_n;
  }
  else
    return check_n;
}

bool katadrome (string n, int base){
  int check_n = 0;
  if (check_base(n, base)){
    check_n = 1;
    for (int i=0; i < n.length()-1; i++){
      char x = n[i];
      char y = n[i+1];
      if (x <= y){
        check_n = 0;
        break;
      }
    }
  return check_n;
  }
  else
    return check_n;
}

bool nialpdrome (string n, int base){
  int check_n = 0;
  if (check_base(n, base)){
    check_n = 1;
    for (int i=0; i < n.length()-1; i++){
      char x = n[i];
      char y = n[i+1];
      if (x < y){
        check_n = 0;
        break;
      }
    }
  return check_n;
  }
  else
    return check_n;
}

string classify (string n, int base){
  string r_string = "nondrome";
  if (metadrome (n, base))
    r_string = "metadrome";
  else if (plaindrome(n, base))
    r_string = "plaindrome";
  else if (katadrome(n,base))
    r_string = "katadrome";
  else if (nialpdrome(n,base))
    r_string = "nialpdrome";
  return r_string;
}

//Main Program

int main (){
  string num;
  long base;
  cout << boolalpha;
  cin >> num >> base;
  cout << metadrome (num, base) << " "
       << plaindrome (num, base) << " "
       << katadrome (num, base) << " "
       << nialpdrome (num, base) << " "
       << classify(num, base) << endl;
}
