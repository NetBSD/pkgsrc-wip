$NetBSD$

Fix endianess for import of extended nodes.
Merged in git commit 565f85dd0f224a6de805ec83d12665fdc96534bc.
https://github.com/fabiangreffrath/crispy-doom/commit/565f85dd0f224a6de805ec83d12665fdc96534bc

--- src/doom/p_extnodes.c.orig	2020-04-16 07:24:32.000000000 +0000
+++ src/doom/p_extnodes.c
@@ -102,9 +102,14 @@ void P_LoadSegs_DeePBSP (int lump)
 	mapseg_deepbsp_t *ml = data + i;
 	int side, linedef;
 	line_t *ldef;
+	int vn1, vn2;
 
-	li->v1 = &vertexes[ml->v1];
-	li->v2 = &vertexes[ml->v2];
+	// [MB] 2020-04-30: Fix endianess for DeePBSDP V4 nodes
+	vn1 = LONG(ml->v1);
+	vn2 = LONG(ml->v2);
+
+	li->v1 = &vertexes[vn1];
+	li->v2 = &vertexes[vn2];
 
 	li->angle = (SHORT(ml->angle))<<FRACBITS;
 
@@ -167,8 +172,9 @@ void P_LoadSubsectors_DeePBSP (int lump)
 
     for (i = 0; i < numsubsectors; i++)
     {
-	subsectors[i].numlines = (int)data[i].numsegs;
-	subsectors[i].firstline = (int)data[i].firstseg;
+	// [MB] 2020-04-30: Fix endianess for DeePBSDP V4 nodes
+	subsectors[i].numlines = (unsigned short)SHORT(data[i].numsegs);
+	subsectors[i].firstline = LONG(data[i].firstseg);
     }
 
     W_ReleaseLumpNum(lump);
@@ -210,7 +216,8 @@ void P_LoadNodes_DeePBSP (int lump)
 	for (j = 0; j < 2; j++)
 	{
 	    int k;
-	    no->children[j] = (unsigned int)(mn->children[j]);
+	    // [MB] 2020-04-30: Fix endianess for DeePBSDP V4 nodes
+	    no->children[j] = LONG(mn->children[j]);
 
 	    for (k = 0; k < 4; k++)
 		no->bbox[j][k] = SHORT(mn->bbox[j][k])<<FRACBITS;
@@ -228,6 +235,7 @@ void P_LoadNodes_DeePBSP (int lump)
 // - inlined P_LoadZSegs()
 // - added support for compressed ZDBSP nodes
 // - added support for flipped levels
+// [MB] 2020-04-30: Fix endianess for ZDoom extended nodes
 void P_LoadNodes_ZDBSP (int lump, boolean compressed)
 {
     byte *data;
@@ -305,10 +313,10 @@ void P_LoadNodes_ZDBSP (int lump, boolea
 
     // 1. Load new vertices added during node building
 
-    orgVerts = *((unsigned int*)data);
+    orgVerts = LONG(*((unsigned int*)data));
     data += sizeof(orgVerts);
 
-    newVerts = *((unsigned int*)data);
+    newVerts = LONG(*((unsigned int*)data));
     data += sizeof(newVerts);
 
     if (orgVerts + newVerts == (unsigned int)numvertexes)
@@ -325,11 +333,11 @@ void P_LoadNodes_ZDBSP (int lump, boolea
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
 
@@ -348,7 +356,7 @@ void P_LoadNodes_ZDBSP (int lump, boolea
 
     // 2. Load subsectors
 
-    numSubs = *((unsigned int*)data);
+    numSubs = LONG(*((unsigned int*)data));
     data += sizeof(numSubs);
 
     if (numSubs < 1)
@@ -362,15 +370,15 @@ void P_LoadNodes_ZDBSP (int lump, boolea
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
@@ -389,9 +397,12 @@ void P_LoadNodes_ZDBSP (int lump, boolea
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
@@ -437,7 +448,7 @@ void P_LoadNodes_ZDBSP (int lump, boolea
 
     // 4. Load nodes
 
-    numNodes = *((unsigned int*)data);
+    numNodes = LONG(*((unsigned int*)data));
     data += sizeof(numNodes);
 
     numnodes = numNodes;
@@ -456,8 +467,8 @@ void P_LoadNodes_ZDBSP (int lump, boolea
 
 	for (j = 0; j < 2; j++)
 	{
-	    no->children[j] = (unsigned int)(mn->children[j]);
-
+	    no->children[j] = LONG(mn->children[j]);
+	
 	    for (k = 0; k < 4; k++)
 		no->bbox[j][k] = SHORT(mn->bbox[j][k])<<FRACBITS;
 	}
