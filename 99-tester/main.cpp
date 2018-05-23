#include <iostream>
#include <ce/stringtree.hpp>

int main(int argc, char *argv[]) {
  ce::stringTree st;
  ce::stringTreeItem* item = new ce::stringTreeItem();
  item->setName("Coolio");
  item->value = "value or something";
  st.addChild(item);

  std::cout<<"Item : "<<st.findChild(item->name())->value<<"\n";
  
  return 0;
}
