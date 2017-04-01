#include <stack>
#include <string>
#include "./std_lib_facilities.h"
using namespace std;
bool isOp(string& character);
bool isNum(string& s);
float calculate(stack<string>& numbers, string operators);

int main(){
  stack<string> equation;
  string input;
  cout << "Please enter an equation followed by a space and \";\" (CTRL+C to quit)" << endl;
  cout << "Example: 8 2 / 5 93 + 7 * - ;" << endl;
  bool flag = 0;
  while(1){
    float value = 0;
    cout << "\n> ";
    while(cin >> input && input != ";"){
      equation.push(input);
      if(!isOp(equation.top()) && !isNum(input)){
        cout << "Error, invalid input" << endl;
        flag = 1;
      }
      else if(isOp(equation.top())){
        string top = equation.top();
        equation.pop();
        value = calculate(equation, top);
      }
    }
    if(!flag){
      cout << "Answer is: " << value << endl;
    }
    else flag = 0;
  }
  return 0;
}

bool isOp(string& character){
  if(character == "+" || character == "-" || character == "*" || character == "/" || character == "%"){
    return 1;
  }
  else return 0;
}
bool isNum(string& s){
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

float calculate(stack<string>& nums, string op){
  float num1 = atof(nums.top().c_str());
  if(!nums.empty()) nums.pop();
  float num2 = atof(nums.top().c_str());
  if(!nums.empty()) nums.pop();
  float newValue;
  if(op == "+") {
    newValue = num1 + num2;
  }
  else if(op == "-") {
    newValue = num2 - num1;
  }
  else if(op == "*") {
    newValue = num1 * num2;
  }
  else if(op == "/"){
    newValue = num2 / num1;
  }
  else if(op == "%") {
    newValue = (int)num2 % (int)num1;
  }
  nums.push(to_string(newValue));
  return newValue;
}
