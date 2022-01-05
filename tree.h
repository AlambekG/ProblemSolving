//  -----------------------------DO NOT MODIFY THIS PART  ----------------------------------

#ifndef LINKEDTREE
#define LINKEDTREE

#include <iostream>
#include <fstream>
#include <list>

using namespace std;

template <typename E>             // base element type
class Tree {
public:                           // public types
  class Position;
  typedef list<Position> PositionList;     // List of node positions type
  typedef typename list<Position>::iterator Iterator;   // Iterator type
protected:                       
  struct Node{                    // Node structure
    E elt;
    Node *parent;
    PositionList children;
    Node() : elt(), parent(NULL), children() {}
  };
public:
  class Position {                       // a node position
  friend class Tree;
  public:
    Position(Node* _v = NULL) : v(_v) {} // constructor
    E& operator*();                      // get element
    Position parent() const;             // get parent
    PositionList children() const;       //get node's children
    bool isRoot() const;                 // root node?
    bool isLeaf() const;                 // is it a leaf?
  private:
    Node* v;
  };
public:                           // public functions
  Tree() : _root(NULL),_n(0) {};   // default constructor, constructs an empty tree
  int size() const;               // number of nodes
  bool empty() const;             // is the tree empty?
  Position root() const;          // get the root
  Position addRoot(const E & e);  // add a root containing e to an empty tree
  Position insertAt(const Position & p, const E & e); // insert a child of the node at position p 
  PositionList positions() const; // get positions of all the nodes in preorder
  void print();                   // print elements in preorder in standard output
  Tree(string filename);          // constructs a tree from a file
  ~Tree();                        // Destructor
protected:
  void preorder(Position p, PositionList& pl) const;          // preorder utility
private:
  Node * _root;   // pointer to the root
  int _n;          // number of nodes
};

int vertexCover(const Tree<int> & T);   // weight of a minimum vertex cover of T

// ------------------------------- TYPE YOUR CODE BELOW ----------------------------------------

// Implementation of Position class
template <typename E>
E& Tree<E>::Position::operator*(){
  return v->elt;
}

template <typename E>
typename Tree<E>::Position Tree<E>::Position::parent() const{
  if(isRoot()) throw runtime_error("error");
  return Position(v->parent);
}

template <typename E>
typename Tree<E>::PositionList Tree<E>::Position::children() const{
  return v->children;
}

template <typename E>
bool Tree<E>::Position::isRoot() const{
  return v->parent == NULL;
}

template <typename E>
bool Tree<E>::Position::isLeaf() const{
  return v->children.size() == 0;
}

// implementation of Tree class
template <typename E>
int Tree<E>::size() const{
  return _n;
}

template <typename E>
bool Tree<E>::empty() const{
  return _n == 0;
}

template <typename E>
typename Tree<E>::Position Tree<E>::root() const{
  return Position(_root);
}

template <typename E>
typename Tree<E>::Position Tree<E>::addRoot(const E & e){
  if(!empty()) throw runtime_error("error");
  _root = new Node();
  _root->elt = e;
  _n = 1;
  return Position(_root);
}

template <typename E>
typename Tree<E>::Position Tree<E>::insertAt(const Position & p, const E & e){
  Node* temp = new Node();
  temp->elt = e;
  _n++;
  temp->parent = p.v;
  Position tp = Position(temp);
  p.v->children.push_back(tp);
  return tp;
}

template <typename E>
typename Tree<E>::PositionList Tree<E>::positions() const{
  PositionList l;
  preorder(Position(_root), l);
  return l;
}

template <typename E>
void Tree<E>::print(){
  PositionList l = positions();
  int n = l.size();
  for(auto i: l) {
    cout << *i;
    if(--n) cout << " ";
  }
  cout << endl;
}

template <typename E>
Tree<E>::Tree(string filename){
  ifstream file(filename);
  int n, i, ri; E v;
  file >> n;
  _n = 0;
  Position nodes[n];
  for(int j = 0; j < n; j++){
    file >> i >> v >> ri;
    if(ri == -1){
      nodes[j] = addRoot(v);
    }
    else{
      nodes[j] = insertAt(nodes[ri], v);
    }
  }
  file.close();
} 


template <typename E>
Tree<E>::~Tree(){
  PositionList l = positions();
  for(auto i: l) delete i.v;
  _root = NULL;
  _n = 0;
}

template <typename E>
void Tree<E>::preorder(Position p, PositionList& pl) const{
    pl.push_back(p);
    PositionList l = p.children();
    for(auto i: l) {
      preorder(i, pl);
    } 
}

class VC{
  public:
    int cv0, cv1;
    VC(){cv0 = 0; cv1 = 0;}
};

VC minVertexCover(Tree<int>::Position p){
  VC a; a.cv1 = *p;
  Tree<int>::PositionList l = p.children();
  for(auto i: l){
    VC b = minVertexCover(i); 
    a.cv0 += b.cv1;
    a.cv1 += min(b.cv0, b.cv1);
  }
  return a;
}

int vertexCover(const Tree<int> & T) {
  VC k = minVertexCover(T.root());
  return min(k.cv0, k.cv1);
}

#endif