// -*- C++ -*-
//
// $Id: t_foo.cc,v 1.40 2004-07-27 05:38:10 edwards Exp $
//
/*! \file
 *  \brief Silly little internal test code
 */


#include "qdp.h"
#include "qdp_iogauge.h"

//using namespace std;

using namespace QDP;



int main(int argc, char *argv[])
{
  // Put the machine into a known state
  QDP_initialize(&argc, &argv);

  // Setup the layout
  const int foo[] = {8,8,4,4};
  multi1d<int> nrow(Nd);
  nrow = foo;  // Use only Nd elements
  Layout::setLattSize(nrow);
  Layout::create();

  XMLFileWriter xml("t_foo.xml");
//  xml.open("foo.xml");
  push(xml, "foo");

  write(xml,"nrow", nrow);
  write(xml,"logicalSize",Layout::logicalSize());

  QDP_PUSH_PROFILE(QDP::getProfileLevel());

#if 1
  {
    Real a, b, c;
    random(a); random(b); random(c);

    QDPIO::cout << "Simple scalars" << endl;
    b = a;
    c = a*b;
    QDPIO::cout << "Try again" << endl;
//    printExprTree(cout, c, OpAssign(), a*b); QDPIO::cout << endl;
    
    QDPIO::cout << "Try global sums" << endl;
    QDP_PUSH_PROFILE(QDP::getProfileLevel());
    c = sum(a);
    c = sum(a*a);
    c = norm2(a*a);
    QDP_POP_PROFILE();
    QDPIO::cout << "Done with simple scalars" << endl << endl << endl;
  }
#endif

  QDP_POP_PROFILE();

  QDP_PUSH_PROFILE(QDP::getProfileLevel());

#if 1
  {
    LatticeColorMatrix a,b,c;
    LatticeComplex cc, dd;
    Real fred;
    random(a); random(b); random(c);

    c = a*b;
    cc = trace(c);
    QDPIO::cout << "Here 1" << endl;
    dd = trace(a*b);
    QDPIO::cout << "Here 2" << endl;
    dd = trace(a*(b*1));
    QDPIO::cout << "Here 3" << endl;
    write(xml,"diff", Real(norm2(cc-dd)));

    c = adj(a)*b;
    cc = trace(c);
    QDPIO::cout << "Here 4" << endl;
    dd = trace(adj(a*b)*b*a*b);
    QDPIO::cout << "Here 5" << endl;
    write(xml,"diff", Real(norm2(cc-dd)));
    dd = localInnerProduct(a,b);
    QDPIO::cout << "Here 6" << endl;
    write(xml,"diff", Real(norm2(cc-dd)));

    QDPIO::cout << "Try global sums" << endl;
    fred = sum(real(trace(a)));
    fred = sum(real(trace(adj(a)*b)));
    fred = norm2(a);
    fred = norm2(a*b);
  }
#endif

  QDP_POP_PROFILE();

  QDP_PUSH_PROFILE(QDP::getProfileLevel());

#if 1
  {
    SpinMatrix S;
    random(S);

    LatticePropagator q;
    random(q);

    LatticePropagator di_quark;
    random(di_quark);

    SpinMatrix gamma_1 = zero;
    SpinMatrix gamma_5 = zero;
//    LatticeComplex ps_rho = trace(adj(gamma_5 * q * gamma_5) * gamma_1 * q * gamma_1);
//    LatticeComplex ps_rho = trace(adj(gamma_5 * q * gamma_5) * q * gamma_1);
    LatticeComplex ps_rho = trace(adj(gamma_5 * q) * gamma_1);
//    LatticeComplex ps_rho = localInnerProduct(gamma_5 * q, gamma_1);
//    Complex ps_rho = trace(adj(gamma_5 * q) * gamma_1);
//    LatticeComplex ps_rho = trace(adj(q) * gamma_1);
//    LatticeComplex ps_rho = localInnerProduct(q, gamma_1);

    QDPIO::cout << "Here 1" << endl;
    LatticeComplex b = trace(S * traceColor(q * di_quark));

    QDPIO::cout << "Here 2" << endl;
    di_quark = quarkContract13(q * Gamma(5), Gamma(5) * q);
    LatticeComplex c = trace(S * traceColor(q * traceSpin(di_quark)));

    QDPIO::cout << "Here 3" << endl;
    LatticeComplex d = trace(S * traceColor(q * traceSpin(quarkContract13(q * Gamma(5), 
									  Gamma(5) * q))));

    QDPIO::cout << "Here 4" << endl;
    write(xml,"diff", Real(norm2(c-d)));

    c = trace(q * di_quark);
    LatticeReal r = real(c);

    QDPIO::cout << "Here 5" << endl;
    LatticeReal s = real(trace(q * di_quark));
    
    QDPIO::cout << "Here 6" << endl;
    write(xml,"diff", Real(norm2(r-s)));

    QDPIO::cout << "Here 7" << endl;
    s = real(trace(adj(q) * di_quark * q));

    QDPIO::cout << "Here 8" << endl;
    s = real(trace(q * di_quark * q));

    QDPIO::cout << "Here 9" << endl;
    LatticeFermion psi, chi;
    random(psi); random(chi);
    Real InvTwoKappa = 0.5;
    chi = GammaConst<Ns,Ns*Ns-1>()*psi;
  }
#endif
  
  QDP_POP_PROFILE();

  pop(xml);
  xml.close();

  // Time to bolt
  QDP_finalize();

  exit(0);
}
