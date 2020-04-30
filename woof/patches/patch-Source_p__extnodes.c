$NetBSD$

Fix endianess for import of extended nodes.
https://github.com/fabiangreffrath/woof/commit/e5f7ae07c6cf6f8ab0dcd223b1dae2a133907333

--- Source/p_extnodes.c.orig	2020-04-14 06:39:44.000000000 +0000
+++ Source/p_extnodes.c
@@ -152,10 +152,15 @@ void P_LoadSegs_DeePBSP (int lump)
 
       int side, linedef;
       line_t *ldef;
+      int vn1, vn2;
+
+      // [MB] 2020-04-22: Fix endianess for DeePBSDP V4 nodes
+      vn1 = LONG(ml->v1);
+      vn2 = LONG(ml->v2);
 
       // [FG] extended nodes
-      li->v1 = &vertexes[ml->v1];
-      li->v2 = &vertexes[ml->v2];
+      li->v1 = &vertexes[vn1];
+      li->v2 = &vertexes[vn2];
 
       li->angle = (SHORT(ml->angle))<<16;
       li->offset = (SHORT(ml->offset))<<16;
@@ -189,8 +194,9 @@ void P_LoadSubsectors_DeePBSP (int lump)
 
   for (i=0; i<numsubsectors; i++)
     {
-      subsectors[i].numlines = (int)data[i].numsegs;
-      subsectors[i].firstline = (int)data[i].firstseg;
+      // [MB] 2020-04-22: Fix endianess for DeePBSDP V4 nodes
+      subsectors[i].numlines = (unsigned short)SHORT(data[i].numsegs);
+      subsectors[i].firstline = LONG(data[i].firstseg);
     }
 
   Z_Free (data);
@@ -222,7 +228,8 @@ void P_LoadNodes_DeePBSP (int lump)
       for (j=0 ; j<2 ; j++)
         {
           int k;
-          no->children[j] = (unsigned int)(mn->children[j]);
+          // [MB] 2020-04-22: Fix endianess for DeePBSDP V4 nodes
+          no->children[j] = LONG(mn->children[j]);
 
           for (k=0 ; k<4 ; k++)
             no->bbox[j][k] = SHORT(mn->bbox[j][k])<<FRACBITS;
@@ -241,6 +248,8 @@ void P_LoadNodes_DeePBSP (int lump)
 // - added support for compressed ZDBSP nodes
 // - added support for flipped levels
 
+// [MB] 2020-04-22: Fix endianess for ZDoom extended nodes
+
 void P_LoadNodes_ZDBSP (int lump, boolean compressed)
 {
     byte *data;
@@ -312,10 +321,10 @@ void P_LoadNodes_ZDBSP (int lump, boolea
 
     // 1. Load new vertices added during node building
 
-    orgVerts = *((unsigned int*)data);
+    orgVerts = LONG(*((unsigned int*)data));
     data += sizeof(orgVerts);
 
-    newVerts = *((unsigned int*)data);
+    newVerts = LONG(*((unsigned int*)data));
     data += sizeof(newVerts);
 
     if (orgVerts + newVerts == (unsigned int)numvertexes)
@@ -332,11 +341,11 @@ void P_LoadNodes_ZDBSP (int lump, boolea
     for (i = 0; i < newVerts; i++)
     {
 	newvertarray[i + orgVerts].r_x =
-	newvertarray[i + orgVerts].x = *((unsigned int*)data);
+	newvertarray[i + orgVerts].x = LONG(*((unsigned int*)data));
 	data += sizeof(newvertarray[0].x);
 
 	newvertarray[i + orgVerts].r_y =
-	newvertarray[i + orgVerts].y = *((unsigned int*)data);
+	newvertarray[i + orgVerts].y = LONG(*((unsigned int*)data));
 	data += sizeof(newvertarray[0].y);
     }
 
@@ -355,7 +364,7 @@ void P_LoadNodes_ZDBSP (int lump, boolea
 
     // 2. Load subsectors
 
-    numSubs = *((unsigned int*)data);
+    numSubs = LONG(*((unsigned int*)data));
     data += sizeof(numSubs);
 
     if (numSubs < 1)
@@ -369,15 +378,15 @@ void P_LoadNodes_ZDBSP (int lump, boolea
 	mapsubsector_zdbsp_t *mseg = (mapsubsector_zdbsp_t*) data + i;
 
 	subsectors[i].firstline = currSeg;
-	subsectors[i].numlines = mseg->numsegs;
-	currSeg += mseg->numsegs;
+	subsectors[i].numlines = LONG(mseg->numsegs);
+	currSeg += LONG(mseg->numsegs);
     }
 
     data += numsubsectors * sizeof(mapsubsector_zdbsp_t);
 
     // 3. Load segs
 
-    numSegs = *((unsigned int*)data);
+    numSegs = LONG(*((unsigned int*)data));
     data += sizeof(numSegs);
 
     // The number of stored segs should match the number of segs used by subsectors
@@ -396,9 +405,12 @@ void P_LoadNodes_ZDBSP (int lump, boolea
 	unsigned char side;
 	seg_t *li = segs + i;
 	mapseg_zdbsp_t *ml = (mapseg_zdbsp_t *) data + i;
+	unsigned int v1, v2;
 
-	li->v1 = &vertexes[ml->v1];
-	li->v2 = &vertexes[ml->v2];
+	v1 = LONG(ml->v1);
+	v2 = LONG(ml->v2);
+	li->v1 = &vertexes[v1];
+	li->v2 = &vertexes[v2];
 
 	linedef = (unsigned short)SHORT(ml->linedef);
 	ldef = &lines[linedef];
@@ -430,7 +442,7 @@ void P_LoadNodes_ZDBSP (int lump, boolea
 
     // 4. Load nodes
 
-    numNodes = *((unsigned int*)data);
+    numNodes = LONG(*((unsigned int*)data));
     data += sizeof(numNodes);
 
     numnodes = numNodes;
@@ -449,7 +461,7 @@ void P_LoadNodes_ZDBSP (int lump, boolea
 
 	for (j = 0; j < 2; j++)
 	{
-	    no->children[j] = (unsigned int)(mn->children[j]);
+	    no->children[j] = LONG(mn->children[j]);
 
 	    for (k = 0; k < 4; k++)
 		no->bbox[j][k] = SHORT(mn->bbox[j][k])<<FRACBITS;
