$NetBSD$

# Silence warnings

--- src/fnet3d.cpp.orig	2022-11-12 14:21:36 UTC
+++ src/fnet3d.cpp
@@ -42,7 +42,7 @@ fnet3d::fnet3d(bead3d *bd3d, int *id_vec, string tag0)
 
   int i,ndigit;
   vector<fnet>::iterator it_fnet;
-  vector<bead>::iterator it_bead;
+  // Unused vector<bead>::iterator it_bead;
   string fnet_tag,bead_tag,sdum;
   stringstream ss;
 
@@ -256,7 +256,7 @@ void fnet3d::fillEnclosedHole(int *id_vec)
   int i,j,k,istk,jstk,kstk,ih,del_stk,bdIndx;
   int tot_bead,nHole,iBead,kBead;
   int ib,jb,kb,iloc=-1,iFil,jFil,kFil,filLength,*filSeq; 
-  double rdum[2],rdum1[2],avgBdMass,avgDist;
+  double rdum[2],rdum1[2],avgBdMass; // Unused ,avgDist;
 
   vector<int> iSeq,jSeq,*edge,*delBead;
   vector<array<int,2>> *hole;
@@ -377,14 +377,14 @@ void fnet3d::fillEnclosedHole(int *id_vec)
 
       /******/
       /* Get details of top/bottom boundaries: avg bond length, linear fit */
-      avgDist=0; // calc avg bond length
+      // Unused avgDist=0; // calc avg bond length
       avgBdMass=fnet_stack[istk].beadMass[iSeq[0]]; // calc avg bead mass
       for (i=1;i<(int)iSeq.size();i++) {
 	for (k=0;k<2;k++) {
 	  rdum[k]=fnet_stack[istk].cm[iSeq[i-1]][k];
 	  rdum1[k]=fnet_stack[istk].cm[iSeq[i]][k];
 	}
-	avgDist+=getDistPos(rdum,rdum1,0);
+	// Unused avgDist+=getDistPos(rdum,rdum1,0);
 	avgBdMass+=fnet_stack[istk].beadMass[iSeq[i]]; 
       }
       avgBdMass+=fnet_stack[jstk].beadMass[jSeq[0]]; // calc avg bead mass      
@@ -393,11 +393,11 @@ void fnet3d::fillEnclosedHole(int *id_vec)
 	  rdum[k]=fnet_stack[jstk].cm[jSeq[i-1]][k];
 	  rdum1[k]=fnet_stack[jstk].cm[jSeq[i]][k];
 	}
-	avgDist+=getDistPos(rdum,rdum1,0);
+	// Unused avgDist+=getDistPos(rdum,rdum1,0);
 	avgBdMass+=fnet_stack[jstk].beadMass[jSeq[i]]; 	
       }
       // no. bonds= sequence size -1      
-      avgDist/=(((int)iSeq.size()-1)+((int)jSeq.size()-1)); 
+      // Unused avgDist/=(((int)iSeq.size()-1)+((int)jSeq.size()-1)); 
       avgBdMass/=((double)iSeq.size()+(double)jSeq.size());
       /*****/
       
@@ -614,7 +614,7 @@ int fnet3d::fnetTag2Id(string sdum)
 { /* Find id number for the fnet with tag sdum.
      Returns: id number or -1 if tag not found */
   int i,j;
-  vector<fnet>::iterator it_fnet;
+  // Unused vector<fnet>::iterator it_fnet;
   j=-1;
   for (i=0;i<nStack;i++) {
     if (fnet_stack[i].tag==sdum) {j=i; break;}
@@ -955,6 +955,10 @@ void fnet3d::measureWidth3D(int N, double arr[], int n
   for (j=0;j<2;j++) pos[j]=new double[totBead];
   bd_mass=new double[totBead]; 
 
+  // Hack just to make weight[] non-zero in getavgw()
+  for (i=0; i<totBead; ++i)
+    bd_mass[i]=1;
+
   ib=0; 
   for (istk=id_vec[0];istk<=id_vec[1];istk++) {
     if (!fnet_stack[istk].nBead) continue; // skip if no beads    
@@ -1079,7 +1083,7 @@ void fnet3d::measureWidth3D(int N, double arr[], int n
   }
   
   for (i=0;i<nStack;i++) delete[] plpts[i];
-  delete pvec; delete[] plpts;
+  delete [] pvec; delete[] plpts;
 }
 
 /************************************************************************/
@@ -1152,7 +1156,7 @@ void fnet3d::readData(string fname,string bd3d_tag0)
   stringstream ss;
   string bd3d_tag,bd_tag,line,ntag,ofname;
   ifstream fin;
-  vector<fnet>::iterator it_fnet; 
+  // Unused vector<fnet>::iterator it_fnet; 
   bool b3d_tag, nstk, flag;
   vector<bead3d>::iterator it_bead3d; 
   flag = b3d_tag = nstk = false;
@@ -1313,7 +1317,7 @@ void fnet3d::removeUnZbondedBeads(int *id_vec)
   vector<int> markbead; 
   multimap<int,int>::iterator it,zt;
   pair<multimap<int,int>::iterator,multimap<int,int>::iterator> it_range,zt_range;
-  vector<int>::iterator vt;
+  // Unused vector<int>::iterator vt;
   
   int delBead,updateBead; 
   multimap<int,int> renumber;
@@ -1432,7 +1436,7 @@ void fnet3d::smoothenZ(int segLength,int delZ, double 
   vector<int> znghb,iSeq,jSeq,zSeq; // flanking beads z-bonded from jstk--istk
   vector<int> checked; // bead ends already checked
   vector<pair<int,int>> jbz; // store zbonded beads [stk,bead index]
-  vector<pair<int,int>>:: iterator it;
+  // Unused vector<pair<int,int>>:: iterator it;
   multimap<int,int> jbz0,jbz1,ztemp;
 
   // for fitQuad0
