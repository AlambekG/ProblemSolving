
#include "tree.h"

typedef typename Tree<int>::Position IntPos;
typedef typename Tree<string>::Position StringPos;

int main(){
 // out << "Construct T5 from file instance/instance5.in\n";
  Tree<int> T5("instances/instance3.in"); 
  T5.print();
  cout << endl;
  cout << vertexCover(T5) << endl;
}

