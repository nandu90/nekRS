/*

The MIT License (MIT)

Copyright (c) 2017 Tim Warburton, Noel Chalmers, Jesse Chan, Ali Karakus

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/


#ifndef OGS_SCATTERMANY_TPP
#define OGS_SCATTERMANY_TPP 1

#include "ogs.hpp"

template <class T> 
void scatterMany(const  dlong Nscatter,
             const  int Nentries,
             const  dlong  stride,
             const  dlong sstride,
             const  dlong *  scatterStarts,
             const  dlong *  scatterIds,
             const  T     *  q,
                    T     *  scatterq) {

  for(int k=0;k<Nentries;++k){
    for(dlong s=0;s<Nscatter;++s){

      const dlong start = scatterStarts[s];
      const dlong end = scatterStarts[s+1];

      const T qs = q[s+k*stride];
        
      for(dlong n=start;n<end;++n){
        const dlong id = scatterIds[n];
        scatterq[id+k*sstride] = qs;
      }
    }
  }
}

#endif