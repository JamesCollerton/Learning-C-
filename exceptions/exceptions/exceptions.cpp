#include <iostream>
#include <optional>
#include <variant>
// #include <expected>

using namespace std;

// This method throws an exception,
// which we'll catch in the method below
void throw_exception() {
  throw runtime_error("Everyone panic!");
}

// Here we call the exception-throwing method,
// catching what is thrown
void basic_exception() {

  try {
      throw_exception();
  } catch (runtime_error& e) {
      cerr << e.what() << endl;
  }

}

// Here we have a function used to parse an
// integer from a string. We can see the underlying
// method usually throws an exception. However,
// we can replace this with returning an empty
// optional
optional<int> parse_int(string s) {
  try {
    return stoi(s);
  } catch(const invalid_argument &e) {
    return {};
  }
}

// Here we call the parsing function, and
// see if the optional is populated. If it is
// then the parsing was successful, otherwise
// we can see it failed.
void optional_error_handling() {

  auto int_optional = parse_int("Error!");
  if(!int_optional.has_value()) {
    cout << "Everyone panic!" << endl;
  }

}

// This method returns an int if we can successfully
// parse one, otherwise it returns a string of the
// error
variant<int, string> variant_parse_int(string s) {
  try {
    return stoi(s);
  } catch(const invalid_argument &e) {
    return "Invalid input";
  }
}

void variant_exception() {

  // Here we try and parse the int, and check to see
  // what type is returned. If it's an error type (i.e.
  // a string) we deal with it.
  auto int_variant = variant_parse_int("Error!");
  if(holds_alternative<string>(int_variant)) {
    cout << "Everyone panic!" << endl;
    cout << "Variant value: " << get<string>(int_variant) << endl;
  }

}

// Below done on Godbolt to prevent needing to sort
// C++23 out on my machine with compiler x86-64 gcc 14.2 -std=c++2b

// #include <expected>
// #include <iostream>

// using namespace std;

// // This version of integer parsing can return two things: a
// // successful value, or an error.
// expected<int, std::string> parse_int(string s) {
//   try {
//     return stoi(s);
//   } catch(const invalid_argument &e) {
//     return unexpected("Invalid input");
//   }
// }

// // Here we check to see if there is a value
// // (success) or if there is an error (failure). 
// // Note, this is different to variant as we
// // have explicit success and error cases, we don't
// // need to know/ guess which is which.
// int main() {

//   auto n = parse_int("Uh oh!");
//   if(!n.has_value()) {
//     cout << n.error() << endl;
//   }

//   return 0;
// }

int main() {

  auto n = parse_int("1");

  // Here we can call functions on any valid results
  // in the 'expected'. If there are none, these functions
  // get skipped.
  auto m = n.transform([](auto a){return a * a;})
            .transform([](auto a){return a + a;});

  if(m.has_value()) {
    cout << m.value() << endl;
  }

  return 0;
}

// export BAZEL_CXXOPTS="-std=c++2b"
int main() {

  std::cout << __cplusplus << '\n';

  basic_exception();
  optional_error_handling();
  variant_exception();
  // expected_exception();

  return 0;
}