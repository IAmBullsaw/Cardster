#include "person.hpp"

Person::Person()
  :crying{false}
{}

void Person::cry() {
  crying = true;
}
bool Person::is_crying() {
  return crying;
}
