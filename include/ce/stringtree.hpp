#pragma once

#include <string>
#include <utility>
#include <vector>

namespace ce {
  class stringTreeItem {
  protected:
    stringTree*     _root   = nullptr;
    std::string     _name   = "";
    stringTreeitem* _parent = nullptr;
    std::vector<stringTreeItem*> _children;
    
  public:
    std::string value;
    
    stringTreeItem(stringTree* croot = nullptr, stringTreeItem* cparent=nullptr);
    
    std::string const& name() const;
    stringTree*        root();
    stringTreeItem*    parent();
    std::vector<stringTreeItem*> const& children();
    
    void setRoot  (stringTree*     croot  = nullptr);
    void setParent(stringTreeRoot* parent = nullptr);
    void setName  (const std::string& cname = "");
    
    void addChild   (stringTreeItem* item = nullptr);
    void removeChild(stringTreeItem* item = nullptr);
    stringTreeItem* findChild(stringTreeItem* item = nullptr);
    stringTreeItem* findChild(const std::string& cname = "");
  }
    
    class stringTree {
    protected:
      stringTreeItem rootItem;
    public:
      stringTree();
      
      void addChild   (stringTreeItem* item = nullptr);
      void removeChild(stringTreeItem* item = nullptr);
      stringTreeItem* findChild(stringTreeItem* item = nullptr);
      stringTreeItem* findChild(const std::string& cname = "");
    }
}
