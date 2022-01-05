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

// ***TREE POSITION CLASS METHODS****
// ***********************************

 // get element 
template <typename E>
E& Tree<E> :: Position :: operator*(){
    return v->elt;
}                  
// get parent 
template <typename E>
typename Tree<E>::Position Tree<E>::Position::parent() const{
     if (v->parent == NULL) throw runtime_error("dosn't have parent");
     return Position(v->parent);
} 
//get node's children  
template <typename E>
typename Tree<E>::PositionList Tree<E>::Position::children() const{
    return PositionList(v->children);
}   
// root node? 
template <typename E>
bool Tree<E>::Position::isRoot() const{
    if(v->parent == NULL)return true;
    return false; 
} 
// is it a leaf?       
template <typename E>
bool Tree<E>::Position::isLeaf() const{
    if(v->children.size() == 0) return true;
    return false;
}

//  ***********TREE METHODS***************
//***************************************************

// number of nodes
template <typename E>
int Tree<E>::size() const{
    return _n;
}    
// is the tree empty?    
template <typename E>    
bool Tree<E>::empty() const{
    if(size() == 0)
       return true;
    return false;
}        
// get the root  
template <typename E>
typename Tree<E>::Position Tree<E>::root() const{
    return Position(_root); 
} 

// add a root containing e to an empty tree   
template <typename E>   
typename Tree<E>::Position Tree<E>::addRoot(const E& e){ 
    if (_root != NULL) throw runtime_error("can't add root");
    _root = new Node;
    _root->elt = e;
    _n = 1;
    return Position(_root);
}  
// insert a child of the node at position p 
template <typename E>
typename Tree<E> :: Position Tree<E> :: insertAt(const Position & p, const E & e){
    Node* x = new Node;
    x->elt = e;
    x->parent = p.v;
    p.v->children.push_back(x);
    _n ++;
    return Position(p.v->children.back());
} 

// get positions of all the nodes in preorder
template <typename E>
typename Tree<E>::PositionList Tree<E>::positions() const {
    PositionList pl;
    preorder(root(), pl);
    return PositionList(pl);
}

 // print elements in preorder in standard output
template <typename E>
void Tree<E>::print(){
    PositionList pl;
    preorder(root(), pl);
    for(Iterator it = pl.begin(); it != pl.end(); ++it){
           cout << *(*it) << ' ';
    }
}                  
// constructs a tree from a file
 
template <typename E>
Tree<E>::Tree(string filename){
    _root = NULL;
    _n = 0;
    ifstream file(filename);
    int n, self, parent; 
    E elt;

    file >> n;
    Position numbs[n];
    for(int i = 0;i < n;i ++){
         file >> self >> elt >> parent;
         if(self == 0){
             numbs[self] = addRoot(elt);
         }
         else{
             numbs[self] = insertAt(numbs[parent], elt);
         }
    }
    file.close();
}
// Destructor        
template <typename E>
Tree<E>::~Tree() {
    PositionList pl = positions();
    for(Iterator it = pl.begin(); it != pl.end(); ++it){
         delete (*it).v; 
    }
    _root = NULL;
}
// preorder utility
template <typename E>
void Tree<E>::preorder(Position p, PositionList& pl) const{
     
      pl.push_back(p); 
      for(Iterator it = p.v->children.begin(); it != p.v->children.end(); ++it){
           preorder(*it, pl);
      }
}

int fun(typename Tree<int>::Position p,int flag){ 
  
     Tree<int>::PositionList pl = p.children();

      if(flag == 0){
           int sm = 0; 
           for(typename Tree<int>::Iterator it = pl.begin(); it != pl.end(); ++it){
                 typename Tree<int>::Position pp = *it; 
                 if((*it).isLeaf()) sm += *(*it);
                 else  sm += fun(*it, 1);
           } 
           return sm;
      }
      else{
           int sm = int(*(p));
           for(typename Tree<int>::Iterator it = pl.begin(); it != pl.end(); ++it){
                 if(!(*it).isLeaf()){
                     int a = fun(*it, 0);
                     int b = fun(*it, 1);
                     if(a < b) sm += a;
                     else sm += b;
                 }
           }
           return sm;
      }
}

// weight of a minimum vertex cover of T
int vertexCover(const Tree<int> & T){
    int a = fun(T.root(), 0);
    int b = fun(T.root(), 1);
    if(a < b) return a;
    else return b;
}

#endif



