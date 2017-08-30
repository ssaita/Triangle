//
//  triangle.c
//  Triangx_NK
//
//  Created by Satoko Saita on 2017/08/31.
//  Copyright © 2017年 SaitaSatoko. All rights reserved.
//
#include <stdio.h>
#include <math.h>
#include "paramt.h"
void triangle(int itest, double *ax,double *bx,int *ix,double apex[iprv][2], int icon[iprv][6],int *isn);

int main(){
    int itest=0;
    double apex[iprv][2];
    int icon[iprv][6],isn[iprv*3];
    triangle(itest, ax,bx,ix,apex,icon,isn);
    
}


void triangle(int itest, double *ax,double *bx,int *ix,double apex[iprv][2], int icon[iprv][6],int *isn){
//    double apex1[iprv][2],icon1[iprv,6],isn[iprv][3];
    int i,j;
    int knewax[20],knewcx[12];
    //C     input data
    //C     ax(20,2) cote and fi for old apex points (1-20)
    //C     bx(12,2) cote and fi for old pentax centers (1-12)
    //C     ix(12,5) old apex points (1-20) surounding a old center (1-12)
    //C
    //C     new sequence number (1-32) for (12center + 20apex)
    //CC    from old number ix(12,5)
    //CC    1(center 1)........................5 connection from 12 center
    //C     7-11(center 2-6)
    //C     22-26(7-11)
    //C     32(center 12)
    for(i=0;i<5;i++){
        //C     appex(1-20)
        knewax[i]=i+1;
        knewax[i+5]=i+5+6;
        knewax[i+10]=i+10+6;
        knewax[i+15]=i+15+11;
        //C     center(2-11)
        knewcx[i+1]=i+1+5;
        knewcx[i+6]=i+6+15;
    }
    knewcx[0]=1;
    knewcx[11]=12+20;
    for(j=0;j<12;j++){
        apex[knewcx[j]][0]=bx[j];
        apex[knewcx[j]][1]=bx[j+12];
        for(i=0;i<5;i++){
            icon[knewcx[j]][i]=knewax[ix[j*5+i]];
            isn[knewcx[j]]=j;
            isn[knewcx[j]+iprv]=0;
            isn[knewcx[j]+iprv*2]=0;
        }
        icon[knewcx[j]][5]=0;
    }
    //C     2-6(apex 1-5)......................6 connection from 20 apex
    //C     12-21(apex 6-15)
    //C     21-26(center(7-11)
    //C     27-31(apex 16-20)
    /*
     for(j=0;j<20;j++){
     apex1[knewax[j]][0]=ax[j][0];
     apex1[knewax[j]][1]=ax[j][1];
     //C     search connection from j
     //call compen(ix,j,i1,i2,i3,i4,i5,i6)
     icon1[knewax[j]][0]=knewcx[i1];
     icon1[knewax[j]][2]=knewcx[i3];
     icon1[knewax[j]][4]=knewcx[i5];
     icon1[knewax[j]][1]=knewax[i2];
     icon1[knewax[j]][3]=knewax[i4];
     icon1[knewax[j]][5]=knewax[i6];
     isn1[knewax[j]][0)=i1;
     isn1[knewax[j]][1)=i3;
     isn1[knewax[j]][2)=i5;
     
     }
     
     30 continue
     C     test out
     do 40 i=1,32
     if(itest.ne.1) go to 40
     write(6,100) i,(icon1(i,j),j=1,6)
     100 format(1h ,'triangle.connection',i3,6i5)
     40 continue
     */
    return;
    //    10 continue
    
}
