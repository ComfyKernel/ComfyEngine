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
    _parent->removeChild(this);
  }

  _parent = cparent;
  if(!_parent) return;
  
  _parent->addChild(this);
}

void ce::stringTreeItem::setName(const std::string& name) {
  _name = name;
}

void ce::stringTreeItem::addChild(ce::stringTreeItem* item) {
  if(item->parent() != this) {
    item->setParent(this);
    return;
  }

  _children.push_back(item);
}

void ce::stringTreeItem::removeChild(ce::stringTreeItem* item) {
  for(unsigned i = 0; i < _children.size(); ++i) {
    if(_children[i] == item) {
      _children[i]->setParent(nullptr);
      _children.erase(_children.begin() + i);
      return;
    }
  }

  std::cout<<"[stringTreeItem::removeChild] Could not find item!\n";
}

bool ce::stringTreeItem::childExists(ce::stringTreeItem* item) {
  for(const auto& i : _children) {
    if(i == item)
      return true;
  }

  return false;
}

ce::stringTreeItem* ce::stringTreeItem::findChild(const std::string& cname) {
  for(auto& i : _children) {
    if(i->name() == cname)
      return i;
  }

  return nullptr;
}

ce::stringTree::stringTree()
  : rootItem(nullptr, nullptr) {

}

void ce::stringTree::addChild(ce::stringTreeItem* item) {
  item->setParent(&rootItem);
  rootItem.addChild(item);
}

void ce::stringTree::removeChild(ce::stringTreeItem* item) {
  rootItem.removeChild(item);
}

bool ce::stringTree::childExists(ce::stringTreeItem* item) {
  return rootItem.childExists(item);
}

ce::stringTreeItem* ce::stringTree::findChild(const std::string& cname) {
  return rootItem.findChild(cname);
}
