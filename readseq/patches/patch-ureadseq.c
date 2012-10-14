$NetBSD: patch-ureadseq.c,v 1.1 2012/10/14 18:12:13 asau Exp $

Rename "getline" to "get_line" to avoid clash with new POSIX.

--- ureadseq.c.orig	1993-01-12 12:43:10.000000000 +0000
+++ ureadseq.c
@@ -136,7 +136,7 @@ Local void readline(FILE *f, char *s, lo
     }
 }
 
-Local void getline(struct ReadSeqVars *V)
+Local void get_line(struct ReadSeqVars *V)
 {
   readline(V->f, V->s, &V->linestart);
 }
@@ -215,7 +215,7 @@ Local void readLoop(short margin, boolea
 
   if (addfirst) addseq(V->s, V);
   do {
-    getline(V);
+    get_line(V);
     V->done = feof(V->f);
     V->done |= (*endTest)( &addend, &ungetend, V);
     if (V->addit && (addend || !V->done) && (strlen(V->s) > margin)) {
@@ -246,7 +246,7 @@ Local void readIG(struct ReadSeqVars *V)
 
   while (!V->allDone) {
     do {
-      getline(V);
+      get_line(V);
       for (si= V->s; *si != 0 && *si < ' '; si++) *si= ' '; /* drop controls */
       if (*si == 0) *V->s= 0; /* chop line to empty */
     } while (! (feof(V->f) || ((*V->s != 0) && (*V->s != ';') ) ));
@@ -272,13 +272,13 @@ Local void readStrider(struct ReadSeqVar
 { /* ? only 1 seq/file ? */
 
   while (!V->allDone) {
-    getline(V);
+    get_line(V);
     if (strstr(V->s,"; DNA sequence  ") == V->s)
       strcpy(V->seqid, (V->s)+16);
     else
       strcpy(V->seqid, (V->s)+1);
     while ((!feof(V->f)) && (*V->s == ';')) {
-      getline(V);
+      get_line(V);
       }
     if (feof(V->f)) V->allDone = true;
     else readLoop(0, true, endStrider, V);
@@ -298,16 +298,16 @@ Local void readPIR(struct ReadSeqVars *V
 
   while (!V->allDone) {
     while (! (feof(V->f) || strstr(V->s,"ENTRY")  || strstr(V->s,"SEQUENCE")) )
-      getline(V);
+      get_line(V);
     strcpy(V->seqid, (V->s)+16);
     while (! (feof(V->f) || strstr(V->s,"SEQUENCE") == V->s))
-      getline(V);
+      get_line(V);
     readLoop(0, false, endPIR, V);
 
     if (!V->allDone) {
      while (! (feof(V->f) || ((*V->s != 0)
        && (strstr( V->s,"ENTRY") == V->s))))
-        getline(V);
+        get_line(V);
       }
     if (feof(V->f)) V->allDone = true;
   }
@@ -327,13 +327,13 @@ Local void readGenBank(struct ReadSeqVar
   while (!V->allDone) {
     strcpy(V->seqid, (V->s)+12);
     while (! (feof(V->f) || strstr(V->s,"ORIGIN") == V->s))
-      getline(V);
+      get_line(V);
     readLoop(0, false, endGB, V);
 
     if (!V->allDone) {
      while (! (feof(V->f) || ((*V->s != 0)
        && (strstr( V->s,"LOCUS") == V->s))))
-        getline(V);
+        get_line(V);
       }
     if (feof(V->f)) V->allDone = true;
   }
@@ -364,11 +364,11 @@ Local void readNBRF(struct ReadSeqVars *
 {
   while (!V->allDone) {
     strcpy(V->seqid, (V->s)+4);
-    getline(V);   /*skip title-junk line*/
+    get_line(V);   /*skip title-junk line*/
     readLoop(0, false, endNBRF, V);
     if (!V->allDone) {
      while (!(feof(V->f) || (*V->s != 0 && *V->s == '>')))
-        getline(V);
+        get_line(V);
       }
     if (feof(V->f)) V->allDone = true;
   }
@@ -390,7 +390,7 @@ Local void readPearson(struct ReadSeqVar
     readLoop(0, false, endPearson, V);
     if (!V->allDone) {
      while (!(feof(V->f) || ((*V->s != 0) && (*V->s == '>'))))
-        getline(V);
+        get_line(V);
       }
     if (feof(V->f)) V->allDone = true;
   }
@@ -410,14 +410,14 @@ Local void readEMBL(struct ReadSeqVars *
   while (!V->allDone) {
     strcpy(V->seqid, (V->s)+5);
     do {
-      getline(V);
+      get_line(V);
     } while (!(feof(V->f) | (strstr(V->s,"SQ   ") == V->s)));
 
     readLoop(0, false, endEMBL, V);
     if (!V->allDone) {
       while (!(feof(V->f) |
          ((*V->s != '\0') & (strstr(V->s,"ID   ") == V->s))))
-      getline(V);
+      get_line(V);
     }
     if (feof(V->f)) V->allDone = true;
   }
@@ -437,13 +437,13 @@ Local void readZuker(struct ReadSeqVars 
   /*! 1st string is Zuker's Fortran format */
 
   while (!V->allDone) {
-    getline(V);  /*s == "seqLen seqid string..."*/
+    get_line(V);  /*s == "seqLen seqid string..."*/
     strcpy(V->seqid, (V->s)+6);
     readLoop(0, false, endZuker, V);
     if (!V->allDone) {
       while (!(feof(V->f) |
         ((*V->s != '\0') & (*V->s == '('))))
-          getline(V);
+          get_line(V);
       }
     if (feof(V->f)) V->allDone = true;
   }
@@ -486,7 +486,7 @@ Local void readPlain(struct ReadSeqVars 
   do {
     addseq(V->s, V);
     V->done = feof(V->f);
-    getline(V);
+    get_line(V);
   } while (!V->done);
   if (V->choice == kListSequences) addinfo(V->seqid, V);
   V->allDone = true;
@@ -512,7 +512,7 @@ Local void readUWGCG(struct ReadSeqVars 
   else if (si = strstr(V->seqid,"..")) *si = 0;
   do {
     V->done = feof(V->f);
-    getline(V);
+    get_line(V);
     if (!V->done) addseq((V->s), V);
   } while (!V->done);
   if (V->choice == kListSequences) addinfo(V->seqid, V);
@@ -531,7 +531,7 @@ Local void readOlsen(struct ReadSeqVars 
   if (V->addit) V->seqlen = 0;
   rewind(V->f); V->nseq= 0;
   do {
-    getline(V);
+    get_line(V);
     V->done = feof(V->f);
 
     if (V->done && !(*V->s)) break;
@@ -614,7 +614,7 @@ Local void readMSF(struct ReadSeqVars *V
   if (V->addit) V->seqlen = 0;
   rewind(V->f); V->nseq= 0;
   do {
-    getline(V);
+    get_line(V);
     V->done = feof(V->f);
 
     if (V->done && !(*V->s)) break;
@@ -683,7 +683,7 @@ Local void readPAUPinterleaved(struct Re
   domatch= (V->matchchar > 0);
 
   do {
-    getline(V);
+    get_line(V);
     V->done = feof(V->f);
 
     if (V->done && !(*V->s)) break;
@@ -764,7 +764,7 @@ Local void readPAUPsequential(struct Rea
   /* rewind(V->f); V->nseq= 0;  << do in caller !*/
   indata= true; /* call here after we find "matrix" */
   do {
-    getline(V);
+    get_line(V);
     V->done = feof(V->f);
 
     if (V->done && !(*V->s)) break;
@@ -849,7 +849,7 @@ Local void readPhylipInterleaved(struct 
   /* fprintf(stderr,"Phylip-ileaf: topnseq=%d  topseqlen=%d\n",V->topnseq, V->topseqlen); */
 
   do {
-    getline(V);
+    get_line(V);
     V->done = feof(V->f);
 
     if (V->done && !(*V->s)) break;
@@ -902,7 +902,7 @@ Local void readPhylipSequential(struct R
   while (isdigit(*si)) si++;
   skipwhitespace(si);
   V->topseqlen= atol(si);
-  getline(V);
+  get_line(V);
   while (!V->allDone) {
     V->seqlencount= 0;
     strncpy(V->seqid, (V->s), 10);
@@ -933,10 +933,10 @@ Local void readSeqMain(
     V->err = eFileNotFound;
   else {
 
-    for (l = skiplines_; l > 0; l--) getline( V);
+    for (l = skiplines_; l > 0; l--) get_line( V);
 
     do {
-      getline( V);
+      get_line( V);
       for (l= strlen(V->s); (l > 0) && (V->s[l] == ' '); l--) ;
     } while ((l == 0) && !feof(V->f));
 
@@ -961,7 +961,7 @@ Local void readSeqMain(
         char  *cp;
         /* rewind(V->f); V->nseq= 0; ?? assume it is at top ?? skiplines ... */
         while (!done) {
-          getline( V);
+          get_line( V);
           tolowerstr( V->s);
           if (strstr( V->s, "matrix")) done= true;
           if (strstr( V->s, "interleav")) interleaved= true;
@@ -993,7 +993,7 @@ Local void readSeqMain(
         break;
 
       case kFitch :
-        strcpy(V->seqid, V->s); getline(V);
+        strcpy(V->seqid, V->s); get_line(V);
         readFitch(V);
         break;
 
@@ -1001,7 +1001,7 @@ Local void readSeqMain(
         do {
           gotuw = (strstr(V->s,"..") != NULL);
           if (gotuw) readUWGCG(V);
-          getline(V);
+          get_line(V);
         } while (!(feof(V->f) || V->allDone));
         break;
       }
