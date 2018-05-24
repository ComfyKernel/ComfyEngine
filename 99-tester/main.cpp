#include <iostream>
#include <ce/stringtree.hpp>

int main(int argc, char *argv[]) {
  ce::stringTree st;
  std::cout<<"Adding Item\n";
  
  st.add("Coolio", "Cool Value");

  std::cout<<"Finding Item\n";

  ce::stringTreeItem* item = st.find("Coolio");

  std::cout<<"Item : "<<item->value<<"\n";

  item = st.find("Doesn't Exist");
  
  std::cout<<"Item : "<<item->value<<"\n";
  
  return 0;
}
