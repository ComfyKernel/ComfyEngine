#include <ce/stringtree.hpp>

#include <iostream>

ce::stringTreeItem::stringTreeItem(ce::stringTree* croot, ce::stringTreeItem* cparent) {
  setRoot  (croot);
  setParent(cparent);
}

std::string const& ce::stringTreeItem::name() const {
  return _name;
}

ce::stringTree* ce::stringTreeItem::root() {
  return _root;
}

ce::stringTreeItem* ce::stringTreeItem::parent() {
  return _parent;
}

std::vector<ce::stringTreeItem*> const& ce::stringTreeItem::children() {
  return _children;
}

void ce::stringTreeItem::setRoot(ce::stringTree* croot) {
  _root = croot;
}

void ce::stringTreeItem::setParent(ce::stringTreeItem* cparent) {
  if(_parent) {
    _parent->remove(this);
  }

  _parent = cparent;
  if(!_parent) return;
  
  _parent->add(this);
}

void ce::stringTreeItem::setName(const std::string& name) {
  _name = name;
}

void ce::stringTreeItem::add(ce::stringTreeItem* item) {
  if(item->parent() != this) {
    item->setParent(this);
    return;
  }

  _children.push_back(item);
}

void ce::stringTreeItem::add(const std::string& cname, const std::string& cvalue) {
  ce::stringTreeItem* item = new ce::stringTreeItem(_root, this);
  item->setName(cname);
  item->value = cvalue;
  add(item);
}

void ce::stringTreeItem::remove(ce::stringTreeItem* item) {
  for(unsigned i = 0; i < _children.size(); ++i) {
    if(_children[i] == item) {
      _children[i]->setParent(nullptr);
      _children.erase(_children.begin() + i);
      return;
    }
  }

  std::cout<<"[stringTreeItem::remove] Could not find item!\n";
}

bool ce::stringTreeItem::exists(ce::stringTreeItem* item) {
  for(const auto& i : _children) {
    if(i == item)
      return true;
  }

  return false;
}

ce::stringTreeItem* ce::stringTreeItem::find(const std::string& cname) {
  // std::cout<<"Finding item '"<<cname<<"' in '"<<_name<<"' ("<<(void*)this<<")\n";  
  for(auto& i : _children) {
    if(i != nullptr) {
      if(i->_name == cname)
	return i;
      
      auto v = i->find(cname);
      if(v != this && v != i)
	return v;
    }
  }
  
  if(_parent == nullptr)
    return this;
  
  return _parent;
}

ce::stringTree::stringTree()
  : rootItem(nullptr, nullptr) {

}

void ce::stringTree::add(ce::stringTreeItem* item) {
  rootItem.add(item);
}

void ce::stringTree::add(const std::string& cname, const std::string& cvalue) {
  rootItem.add(cname, cvalue);
}

void ce::stringTree::remove(ce::stringTreeItem* item) {
  rootItem.remove(item);
}

bool ce::stringTree::exists(ce::stringTreeItem* item) {
  return rootItem.exists(item);
}

ce::stringTreeItem* ce::stringTree::find(const std::string& cname) {
  return rootItem.find(cname);
}
