#include <iostream>
#include <string>
using namespace std;

int main() {
    string S, T;
    cin >> S >> T;

    string st = "";
    int m = T.size();
    for (int i=0;i<S.size();i++){
      char c = S[i];
      st += c;
      if (st.size() >= m && st.substr(st.size() - m) == T) {
        st.resize(st.size() - m);
      }
    }

    cout << st << "\n";
    return 0;
}
