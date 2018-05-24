#pragma once

#include <string>
#include <utility>
#include <vector>

namespace ce {
  class stringTree;
  class stringTreeItem {
  protected:
    stringTree*     _root   = nullptr;
    std::string     _name   = "";
    stringTreeItem* _parent = nullptr;
    std::vector<stringTreeItem*> _children;
    
  public:
    std::string value;
    
    stringTreeItem(stringTree* croot = nullptr, stringTreeItem* cparent=nullptr);
    
    std::string const& name() const;
    stringTree*        root();
    stringTreeItem*    parent();
    std::vector<stringTreeItem*> const& children();
    
    void setRoot  (stringTree*     croot  = nullptr);
    void setParent(stringTreeItem* parent = nullptr);
    void setName  (const std::string& cname = "");
    
    void add   (stringTreeItem* item = nullptr);
    void add   (const std::string& cname = "", const std::string& cvalue = "");
    void remove(stringTreeItem* item = nullptr);
    bool exists(stringTreeItem* item = nullptr);
    stringTreeItem* find(const std::string& cname = "");
  };
    
  class stringTree {
  protected:
    stringTreeItem rootItem;
  public:
    stringTree();
    
    void add   (stringTreeItem* item = nullptr);
    void add   (const std::string& cname = "", const std::string& cvalue = "");
    void remove(stringTreeItem* item = nullptr);
    bool exists(stringTreeItem* item = nullptr);
    stringTreeItem* find(const std::string& cname = "");
  };
}
