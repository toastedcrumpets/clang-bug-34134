struct A {
  template<class T>
  A(const T& a) { }

  A& operator=(const A& a) { return *this; }
  
  template<class T>
  auto operator=(const T& a) -> decltype(*this = A(a)) { return *this = A(a); } 
};

int main() {
  //Force the error
  &(A(12) = 12);
}
