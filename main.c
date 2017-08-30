//
//  main.c
//  Triangx
//
//  Created by Satoko Saita on 2017/08/22.
//  Copyright © 2017年 Satoko Saita. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include "paramt.h"
//#include "para3d.h" //level 0

//void setcon1();
void coodp1(int itest,int ipointcal,int nx);
double pentax(double *ax,double *bx,int *ix);
void triangle(int itest, double ax[20][2],double bx[12][2],int ix[12][5],double apex1[iprv][2], int icon1[iprv][6],int isn1[iprv][3]);
int main() {
    // insert code here...
    float xcl[iprv][4];
    float v[iprv];
    float s1[iprv][iprf],sb1[iprv];
    float t1[iprv][3][3][iprf],tb1[iprv][3][3];
    float r[iprz],rc[iprz];
    //xcl(i,4,j)  coordinate of ij point
    //v(i,j)      volume of ij cell
    //s(i,nfc,j)  area of ij surface
    //sb(i,j)     area of ij bottom surface
    //t(i,3,3,6,j)surface normal ij surface
    //tb(i,3,3,j) surface normal ij bottom surface
    FILE *fp1,*fp2,*fp3;
    int nfc=iprf;   //外部結合の定義
    int nz=iprz-1;  //外部結合の定義
    int norder=ipro;//外部結合の定義
    //     nfc interface number / connection icon(nv,nfc)
    //     nv calculated by coodp1 from norder
    //     nu calculated by trinumb from norder
    //     nz
    fp1=fopen("pentd1","w");
    fp2=fopen("pentd2","w");
    fp3=fopen("pentd3","w");
    
    printf("iprv:%d, iprf:%d\n",iprv,iprf);
    printf("nfc:%d, nz:%d, norder:%d\n",nfc,nz,norder);
    
    coodp1(0,2,norder);
    
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    
    return 0;
}

void coodp1(int itest,int ipointcal,int nx){
    //include 'redcom.f'
    //     ax apex cote,fi
    //     bx center cote,fi
    //     ix apex points
    double apex1[iprv][2],apex2[iprv][2];
    int icon1[iprv][6],icon2[iprv][6],isn1[iprv][3],isn2[iprv][3];
    double fi0;
    //     nx ... order of division ... iprv
    //     itest=0 / no printout
    //     ipointcal=0 / only next point number cal. (nx-1 out)
    //***
    //     te(i),fi(i) coordinate of i point
    //     icon(i,j)   connection from i point
    //     ifc(i,j,4)  MUSCL further connection from i and j line
    //     ra(i,j,4)   connection ratio for ifc
    //     itri(k,3,2) triangle number
    //
    //     r(k)        radial coodinate
    //***
    //    pentax (20 apex + 12 center, total 32 points)
    fi0=pentax(ax,bx,ix);
    if(itest==1) printf("coodp1.**coord0 angle pentax fi0:%f",fi0);
    //    1-st triangles (32)
    //call triangle(itest,ax,bx,ix,apex1,icon1,isn1)
    //CC    higher triangles for triangm (up to nx order)
    //npoint=32
    //do 10 iorder=2,nx
    //jorder=iorder
    //write(6,101) jorder
    //101 format(1h ,'order=',i2)
    //nold=npoint
    //C     I1=0 / only point number cal.
    //I1=1
    //if(ipointcal.eq.0.and.iorder.eq.nx) i1=0
    //call devidem(nx,itest,i1,nold,nnew,
    //             1             apex1,icon1,isn1,apex2,icon2,isn2)
    //npoint=nnew
    //if(I1.eq.0) npoint=nold
    //do 11 j=1,6
    //do 12 i=1,npoint
    //icon(i,j)=icon2(i,j)
    //icon1(i,j)=icon2(i,j)
    //12 continue
    //if(j.gt.1) go to 11
    //do 13 i=1,npoint
    //te(i)=apex2(i,1)
    //fi(i)=apex2(i,2)
    //apex1(i][0]=apex2(i,1)
    //apex1(i][1]=apex2(i,2)
    //isn1(i][0]=isn2(i,1)
    //isn1(i][1]=isn2(i,2)
    //isn1(i][2]=isn2(i,3)
    //isn(i][0]=isn2(i,1)
    //isn(i][1]=isn2(i,2)
    //isn(i][2]=isn2(i,3)
    //13 continue
    //11 continue
    //10 continue
    //CC    point number
    //nv=npoint
    //CC    cal. MUSCL connection
    //if(ipointcal.ge.1) call fcon(itest)
    //write(6,101) jorder
    //CC    triangles number
    //if(ipointcal.ge.1) call trinumb(nx,itest,ipointcal)
    //write(6,101) jorder
    return;
}


void triangle(int itest, double ax[20][2],double bx[12][2],int ix[12][5],double apex1[iprv][2], int icon1[iprv][6],int isn1[iprv][3]){
    //double apex1[iprv][2],icon1[iprv,6],isn[iprv][3];
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
        apex1[knewcx[j]][0]=bx[j][0];
        apex1[knewcx[j]][1]=bx[j][1];
        for(i=0;i<5;i++){
            icon1[knewcx[j]][i]=knewax[ix[j][i]];
            isn1[knewcx[j]][0]=j;
            isn1[knewcx[j]][1]=0;
            isn1[knewcx[j]][2]=0;
        }
        icon1[knewcx[j]][5]=0;
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
//    C**************************************************triangle**
//                C     27-31(apex 16-20)
//                do 30 j=1,20
//                apex1(knewax(j),1)=ax(j,1)
//                apex1(knewax(j),2)=ax(j,2)
//                C     search connection from j
//                call compen(ix,j,i1,i2,i3,i4,i5,i6)
//                icon1(knewax(j),1)=knewcx(i1)
//                icon1(knewax(j),3)=knewcx(i3)
//                icon1(knewax(j),5)=knewcx(i5)
//                icon1(knewax(j),2)=knewax(i2)
//                icon1(knewax(j),4)=knewax(i4)
//                icon1(knewax(j),6)=knewax(i6)
//                isn1(knewax(j),1)=i1
//                isn1(knewax(j),2)=i3
//                isn1(knewax(j),3)=i5
//                30 continue
//                C     test out
//                do 40 i=1,32
//                if(itest.ne.1) go to 40
//                write(6,100) i,(icon1(i,j),j=1,6)
//                100 format(1h ,'triangle.connection',i3,6i5)
//                40 continue
//                return
//                end
