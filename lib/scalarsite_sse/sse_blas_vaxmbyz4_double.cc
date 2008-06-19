// $Id: sse_blas_vaxmbyz4_double.cc,v 1.1 2008-06-18 16:02:11 bjoo Exp $

/*! @file
 *  @brief Generic Scalar VAXPY routine
 *
 */

#include "scalarsite_sse/sse_blas_vaxmbyz4_double.h"
#include <xmmintrin.h>
namespace QDP {



  void vaxmbyz4(REAL64 *z,REAL64 *a,REAL64 *x, REAL64 *b, REAL64 *y, int n_4vec)
{
  __m128d a_sse;
  __m128d b_sse;
 
  __m128d tmp1;
  __m128d tmp2;
  __m128d tmp3;
  __m128d tmp4;

  __m128d x1;
  __m128d y1;
  __m128d z1;

  __m128d x2;
  __m128d y2;
  __m128d z2;

  __m128d x3;
  __m128d y3;
  __m128d z3;

  // Load the scalar into low bytes of scalar
  a_sse = _mm_load_sd(a);
  b_sse = _mm_load_sd(b);

  // cross components into tmp 
  // Zero tmp
  tmp1 = _mm_xor_pd(tmp1, tmp1);
  tmp1 = _mm_shuffle_pd(a_sse, a_sse, 0x1);
  a_sse = _mm_add_pd(a_sse, tmp1);

  tmp2 = _mm_xor_pd(tmp2, tmp2);
  tmp2 = _mm_shuffle_pd(b_sse, b_sse, 0x1);
  b_sse = _mm_add_pd(b_sse, tmp2);


  // Do n_3vec 3vectors.
  double *x_p=x;
  double *y_p=y;
  double *z_p=z;


  
  for(int i=0; i < n_4vec; i++) { 

    y1 = _mm_load_pd(y_p);
    x1 = _mm_load_pd(x_p);
    z1 = _mm_mul_pd(a_sse,x1);
    tmp1 = _mm_mul_pd(b_sse,y1);
    z1 = _mm_sub_pd(z1,tmp1);
    _mm_store_pd(z_p, z1);

    y2 = _mm_load_pd(y_p+2);
    x2 = _mm_load_pd(x_p+2);
    z2 = _mm_mul_pd(a_sse,x2);
    tmp2 = _mm_mul_pd(b_sse,y2);
    z2 = _mm_sub_pd(z2,tmp2);
    _mm_store_pd(z_p+2, z2);
   

    y3 = _mm_load_pd(y_p+4);
    x3 = _mm_load_pd(x_p+4);
    z3 = _mm_mul_pd(a_sse,x3);
    tmp3 = _mm_mul_pd(b_sse,y3);
    z3 = _mm_sub_pd(z3,tmp3);
    _mm_store_pd(z_p+4, z3);


    y1 = _mm_load_pd(y_p+6);
    x1 = _mm_load_pd(x_p+6);
    z1 = _mm_mul_pd(a_sse,x1);
    tmp1 = _mm_mul_pd(b_sse,y1);
    z1 = _mm_sub_pd(z1,tmp1);
    _mm_store_pd(z_p+6, z1);

    y2 = _mm_load_pd(y_p+8);
    x2 = _mm_load_pd(x_p+8);
    z2 = _mm_mul_pd(a_sse,x2);
    tmp2 = _mm_mul_pd(b_sse,y2);
    z2 = _mm_sub_pd(z2,tmp2);
    _mm_store_pd(z_p+8, z2);
   
    y3 = _mm_load_pd(y_p+10);
    x3 = _mm_load_pd(x_p+10);
    z3 = _mm_mul_pd(a_sse,x3);
    tmp3 = _mm_mul_pd(b_sse,y3);
    z3 = _mm_sub_pd(z3,tmp3);
    _mm_store_pd(z_p+10, z3);


    y1 = _mm_load_pd(y_p+12);
    x1 = _mm_load_pd(x_p+12);
    z1 = _mm_mul_pd(a_sse,x1);
    tmp1 = _mm_mul_pd(b_sse,y1);
    z1 = _mm_sub_pd(z1,tmp1);
    _mm_store_pd(z_p+12, z1);

    y2 = _mm_load_pd(y_p+14);
    x2 = _mm_load_pd(x_p+14);
    z2 = _mm_mul_pd(a_sse,x2);
    tmp2 = _mm_mul_pd(b_sse,y2);
    z2 = _mm_sub_pd(z2,tmp2);
    _mm_store_pd(z_p+14, z2);
   

    y3 = _mm_load_pd(y_p+16);
    x3 = _mm_load_pd(x_p+16);
    z3 = _mm_mul_pd(a_sse,x3);
    tmp3 = _mm_mul_pd(b_sse,y3);
    z3 = _mm_sub_pd(z3,tmp3);
    _mm_store_pd(z_p+16, z3);


    y1 = _mm_load_pd(y_p+18);
    x1 = _mm_load_pd(x_p+18);
    z1 = _mm_mul_pd(a_sse,x1);
    tmp1 = _mm_mul_pd(b_sse,y1);
    z1 = _mm_sub_pd(z1,tmp1);
    _mm_store_pd(z_p+18, z1);

    y2 = _mm_load_pd(y_p+20);
    x2 = _mm_load_pd(x_p+20);
    z2 = _mm_mul_pd(a_sse,x2);
    tmp2 = _mm_mul_pd(b_sse,y2);
    z2 = _mm_sub_pd(z2,tmp2);
    _mm_store_pd(z_p+20, z2);
   

    y3 = _mm_load_pd(y_p+22);
    x3 = _mm_load_pd(x_p+22);
    z3 = _mm_mul_pd(a_sse,x3);
    tmp3 = _mm_mul_pd(b_sse,y3);
    z3 = _mm_sub_pd(z3,tmp3);
    _mm_store_pd(z_p+22, z3);

    x_p+=24; y_p+=24; z_p+=24;

  }
}
}


