#include <RcppArmadillo.h>
#include <set>
using namespace arma;
using namespace std;
//[[Rcpp::depends(RcppArmadillo)]]

//[[Rcpp::export]]
int Tstar(vec X,vec Y){
  set<int> test_dup;
  int n=X.size();
  int i,j,k,l;
  int Tn=0;
  for (i=0;i<n;i++) {
    for (j=0;j<n;j++) {
      for (k=0;k<n;k++) {
        for (l=0;l<n;l++) {
          test_dup.clear();
          test_dup.insert(i);
          test_dup.insert(j);
          test_dup.insert(k);
          test_dup.insert(l);
          if(test_dup.size() == 4) {
            Tn+=sign(X(i)-X(j))*sign(X(k)-X(l))*sign(Y(i)-Y(j))*sign(Y(k)-Y(l));
          }
        }
      }
    }
  }
  return(Tn);
 }