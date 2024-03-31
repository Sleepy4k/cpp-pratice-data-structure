#include <iomanip>
#include <iostream>

using namespace std;

int main() {
  char op_081;
  float num1_081, num2_081;

  cout << "Enter operator (+, -, *, /): ";
  cin >> op_081;

  cout << "Enter two operands: ";
  cin >> num1_081 >> num2_081;

  switch (op_081) {
    case '+':
      cout << "Result: " << num1_081 + num2_081 << endl;
      break;

    case '-':
      cout << "Result: " << num1_081 - num2_081 << endl;
      break;

    case '*':
      cout << "Result: " << num1_081 * num2_081 << endl;
      break;

    case '/':
      if (num2_081 < 1) cout << "Division by zero is not allowed" << endl;
      else cout << "Result: " << fixed << setprecision(2) << num1_081 / num2_081 << endl;
      break;

    default:
      cout << "Invalid operator" << endl;
      break;
  }

  return 0;
}
