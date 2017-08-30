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

//double pentax(double *ax,double *bx,int *ix){
//    int i,j;
//    double te1,te2,a,b,c,d,r,r1,fi,fi0,fi1,fi2,fi3;
//    FILE *fp1,*fp2,*fp3;
//    fp1=fopen("out-pentax1.txt","w");
//    fp2=fopen("out-pentax2.txt","w");
//    fp3=fopen("out-pentax3.txt","w");
//    
//    printf("-pentax\n");
//    printf("pi:%f\n",pi);
//    //     ax apex cote,fi
//    //     bx center cote,fi
//    //     ix apex points
//    te1=54.0;
//    te2=72.0;
//    //     angles for pentax
//    a=2.0/3.0*sqrt(3.0)*sin(te1/180.0*pi);
//    b=sqrt(1.0-a*a);
//    r=0.5/b;
//    c=0.5/sin(0.5*te2/180.0*pi);
//    fi=asin(c/r);
//    fi1=fi/pi*180.0;
//    fi=2.0*asin(0.5/r);
//    fi2=fi/pi*180.0;
//    d=c*cos(0.5*te2/180.0*pi);
//    r1=sqrt(r*r-0.5*0.5);
//    fi=asin(d/r1);
//    fi3=fi/pi*180.0;
//    //     apex cote,fi coordinates
//    for(i=0;i<5;i++){
//        ax[i+   +20]    =pi/2.5*((double)(i));
//        ax[i+5  +20]    =pi/2.5*((double)(i));
//        ax[i+10 +20]    =pi/2.5*((double)(i))+pi/5.0;
//        ax[i+15 +20]    =pi/2.5*((double)(i))+pi/5.0;
//        ax[i]           =pi-fi1/180.0*pi;
//        ax[i+5]         =pi-(fi1+fi2)/180.0*pi;
//        ax[i+10]        =(fi1+fi2)/180.0*pi;
//        ax[i+15]        =fi1/180.0*pi;
//    }
//    //C     center cote,fi coordinates
//    bx[0    +0]     =pi;
//    bx[0    +12]    =0.0;
//    for(i=0;i<5;i++){
//        bx[1+i  +0] =pi-(fi3+fi3)/180.0*pi;
//        bx[1+i  +12]=pi/2.5*((double)(i))+pi/5.0;
//        bx[6+i  +0] =pi-(fi1+fi2+fi1)/180.0*pi;
//        bx[6+i  +12]=pi/2.5*((double)(i));
//    }
//    bx[11   +0]=0.0;bx[11   +12]=0.0;
//    //C     1st
//    ix[0    +0]=1;
//    ix[0    +1]=2;
//    ix[0    +2]=3;
//    ix[0    +3]=4;
//    ix[0    +4]=5;
//    //C     2nd
//    ix[5    +0]=1;
//    ix[5    +1]=6;
//    ix[5    +2]=11;
//    ix[5    +3]=7;
//    ix[5    +4]=2;
//    //C     3rd
//    ix[10    +0]=2;
//    ix[10    +1]=7;
//    ix[10    +2]=12;
//    ix[10    +3]=8;
//    ix[10    +4]=3;
//    //C     4th
//    ix[15    +0]=3;
//    ix[15    +1]=8;
//    ix[15    +2]=13;
//    ix[15    +3]=9;
//    ix[15    +4]=4;
//    //C     5th
//    ix[20    +0]=4;
//    ix[20    +1]=9;
//    ix[20    +2]=14;
//    ix[20    +3]=10;
//    ix[20    +4]=5;
//    //C     6th
//    ix[25    +0]=5;
//    ix[25    +1]=10;
//    ix[25    +2]=15;
//    ix[25    +3]=6;
//    ix[25    +4]=1;
//    //C     7th
//    ix[30    +0]=6;
//    ix[30    +1]=15;
//    ix[30    +2]=20;
//    ix[30    +3]=16;
//    ix[30    +4]=11;
//    //C     8th
//    ix[35    +0]=7;
//    ix[35    +1]=11;
//    ix[35    +2]=16;
//    ix[35    +3]=17;
//    ix[35    +4]=12;
//    //C     9th
//    ix[40    +0]=8;
//    ix[40    +1]=12;
//    ix[40    +2]=17;
//    ix[40    +3]=18;
//    ix[40    +4]=13;
//    //C     10th
//    ix[45    +0]=9;
//    ix[45    +1]=13;
//    ix[45    +2]=18;
//    ix[45    +3]=19;
//    ix[45    +4]=14;
//    //C     11th
//    ix[50   +0]=10;
//    ix[50   +1]=14;
//    ix[50   +2]=19;
//    ix[50   +3]=20;
//    ix[50   +4]=15;
//    //C     12th
//    ix[55   +0]=16;
//    ix[55   +1]=20;
//    ix[55   +2]=19;
//    ix[55   +3]=18;
//    ix[55   +4]=17;
//    fi0=fi1+fi2+fi1+fi3+fi3;
//    //ちゃんと5角形ができているかテキストデータにして確認する.
//    for(i=0;i<12;i++){
//        fprintf(fp1, "%f ", bx[i+12]);
//        fprintf(fp1, "%f ", bx[i]-pi/2.0);
//        fputs("\n",fp1);
//    }
//    //ちゃんと5角形ができているかテキストデータにして確認する.
//    for(i=0;i<20;i++){
//        fprintf(fp2, "%f ", ax[i+20]);
//        fprintf(fp2, "%f ", ax[i]-pi/2.0);
//        fputs("\n",fp2);
//    }
//    //ちゃんと5角形ができているかテキストデータにして確認する.
//    for(i=0;i<12;i++){
//        for(j=0;j<5;j++){
//            fprintf(fp3, "%f ", ax[ix[i*5+j]-1+20]);
//            fprintf(fp3, "%f ", ax[ix[i*5+j]-1]-pi/2.0);
//            fputs("\n",fp3);
//            if (j==4){
//                fprintf(fp3, "%f ", ax[ix[i*5+0]-1+20]);
//                fprintf(fp3, "%f ", ax[ix[i*5+0]-1]-pi/2.0);
//                fputs("\n",fp3);
//            }
//        }
//    }
//    fclose(fp1);
//    fclose(fp2);
//    fclose(fp3);
//    return fi0;
//    
//}

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
