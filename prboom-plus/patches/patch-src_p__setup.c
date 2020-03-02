$NetBSD$

Loading maps using ZDoom extended nodes crashes on big endian machines
(because 32-bit values are imported with wrong byte order).

Note that the endianess conversion macros return 16-bit or 32-bit
signed values using data types short int and long int. Both data types
are allowed to be larger (implementation defined) and in this case
additional bits are sign extended. This patch mask such additional
bits if the target data type is unsigned.

If memory allocation returns NULL, do not continue (dereference the
NULL pointer and crash).

--- src/p_setup.c.orig	2016-01-10 18:01:30.000000000 +0000
+++ src/p_setup.c
@@ -1024,6 +1024,7 @@ static void CheckZNodesOverflow(int *siz
   }
 }
 
+// MB 2020-03-01: Fix endianess for 32-bit ZDoom nodes
 static void P_LoadZSegs (const byte *data)
 {
   int i;
@@ -1037,12 +1038,12 @@ static void P_LoadZSegs (const byte *dat
     seg_t *li = segs+i;
     const mapseg_znod_t *ml = (const mapseg_znod_t *) data + i;
 
-    v1 = ml->v1;
-    v2 = ml->v2;
+    v1 = (unsigned int)LittleLong(ml->v1) & 0xFFFFFFFFU;
+    v2 = (unsigned int)LittleLong(ml->v2) & 0xFFFFFFFFU;
 
     li->miniseg = false;
 
-    linedef = (unsigned short)LittleShort(ml->linedef);
+    linedef = (unsigned short)LittleShort(ml->linedef) & 0xFFFFU;
 
     //e6y: check for wrong indexes
     if ((unsigned int)linedef >= (unsigned int)numlines)
@@ -1098,6 +1099,8 @@ static void P_LoadZSegs (const byte *dat
   }
 }
 
+// MB 2020-03-01: Fix endianess for 32-bit ZDoom nodes
+// https://zdoom.org/wiki/Node#ZDoom_extended_nodes
 static void P_LoadZNodes(int lump, int glnodes)
 {
   const byte *data;
@@ -1112,18 +1115,18 @@ static void P_LoadZNodes(int lump, int g
 
   data = W_CacheLumpNum(lump);
   len =  W_LumpLength(lump);
-  
+
   // skip header
   CheckZNodesOverflow(&len, 4);
   data += 4;
 
   // Read extra vertices added during node building
   CheckZNodesOverflow(&len, sizeof(orgVerts));
-  orgVerts = *((const unsigned int*)data);
+  orgVerts = (unsigned int)LittleLong(*((const unsigned int*)data)) & 0xFFFFFFFFU;
   data += sizeof(orgVerts);
 
   CheckZNodesOverflow(&len, sizeof(newVerts));
-  newVerts = *((const unsigned int*)data);
+  newVerts = (unsigned int)LittleLong(*((const unsigned int*)data)) & 0xFFFFFFFFU;
   data += sizeof(newVerts);
 
   if (!samelevel)
@@ -1135,16 +1138,21 @@ static void P_LoadZNodes(int lump, int g
     else
     {
       newvertarray = calloc(orgVerts + newVerts, sizeof(vertex_t));
+      // MB 2020-03-01: Check whether memory allocation was successful
+      if (NULL == newvertarray)
+      {
+        I_Error("P_LoadZNodes: memory allocation failed");
+      }
       memcpy (newvertarray, vertexes, orgVerts * sizeof(vertex_t));
     }
 
     CheckZNodesOverflow(&len, newVerts * (sizeof(newvertarray[0].x) + sizeof(newvertarray[0].y)));
     for (i = 0; i < newVerts; i++)
     {
-      newvertarray[i + orgVerts].x = *((const unsigned int*)data);
+      newvertarray[i + orgVerts].x = (fixed_t)LittleLong(*((const unsigned int*)data));
       data += sizeof(newvertarray[0].x);
 
-      newvertarray[i + orgVerts].y = *((const unsigned int*)data);
+      newvertarray[i + orgVerts].y = (fixed_t)LittleLong(*((const unsigned int*)data));
       data += sizeof(newvertarray[0].y);
     }
 
@@ -1172,28 +1180,37 @@ static void P_LoadZNodes(int lump, int g
 
   // Read the subsectors
   CheckZNodesOverflow(&len, sizeof(numSubs));
-  numSubs = *((const unsigned int*)data);
+  numSubs = (unsigned int)LittleLong(*((const unsigned int*)data)) & 0xFFFFFFFFU;
   data += sizeof(numSubs);
 
   numsubsectors = numSubs;
   if (numsubsectors <= 0)
     I_Error("P_LoadZNodes: no subsectors in level");
   subsectors = calloc_IfSameLevel(subsectors, numsubsectors, sizeof(subsector_t));
+  // MB 2020-03-01: Check whether memory allocation was successful
+  if (NULL == subsectors)
+  {
+    I_Error("P_LoadZNodes: memory allocation failed");
+  }
 
   CheckZNodesOverflow(&len, numSubs * sizeof(mapsubsector_znod_t));
+  // MB 2020-03-01
+  // First segment number of each subsector is not stored
+  // First subsector starts at segment 0
+  // Subsequent subsectors starts with the next unused segment number (currSeg)
   for (i = currSeg = 0; i < numSubs; i++)
   {
     const mapsubsector_znod_t *mseg = (const mapsubsector_znod_t *) data + i;
 
     subsectors[i].firstline = currSeg;
-    subsectors[i].numlines = mseg->numsegs;
-    currSeg += mseg->numsegs;
+    subsectors[i].numlines = (int)LittleLong(mseg->numsegs);
+    currSeg += (unsigned int)LittleLong(mseg->numsegs) & 0xFFFFFFFFU;
   }
   data += numSubs * sizeof(mapsubsector_znod_t);
 
   // Read the segs
   CheckZNodesOverflow(&len, sizeof(numSegs));
-  numSegs = *((const unsigned int*)data);
+  numSegs = (unsigned int)LittleLong(*((const unsigned int*)data)) & 0xFFFFFFFFU;
   data += sizeof(numSegs);
 
   // The number of segs stored should match the number of
@@ -1205,6 +1222,11 @@ static void P_LoadZNodes(int lump, int g
 
   numsegs = numSegs;
   segs = calloc_IfSameLevel(segs, numsegs, sizeof(seg_t));
+  // MB 2020-03-01: Check whether memory allocation was successful
+  if (NULL == segs)
+  {
+    I_Error("P_LoadZNodes: memory allocation failed");
+  }
 
   if (glnodes == 0)
   {
@@ -1220,11 +1242,16 @@ static void P_LoadZNodes(int lump, int g
 
   // Read nodes
   CheckZNodesOverflow(&len, sizeof(numNodes));
-  numNodes = *((const unsigned int*)data);
+  numNodes = (unsigned int)LittleLong(*((const unsigned int*)data)) & 0xFFFFFFFFU;
   data += sizeof(numNodes);
 
   numnodes = numNodes;
   nodes = calloc_IfSameLevel(nodes, numNodes, sizeof(node_t));
+  // MB 2020-03-01: Check whether memory allocation was successful
+  if (NULL == nodes)
+  {
+    I_Error("P_LoadZNodes: memory allocation failed");
+  }
 
   CheckZNodesOverflow(&len, numNodes * sizeof(mapnode_znod_t));
   for (i = 0; i < numNodes; i++)
@@ -1233,17 +1260,17 @@ static void P_LoadZNodes(int lump, int g
     node_t *no = nodes + i;
     const mapnode_znod_t *mn = (const mapnode_znod_t *) data + i;
 
-    no->x = LittleShort(mn->x)<<FRACBITS;
-    no->y = LittleShort(mn->y)<<FRACBITS;
-    no->dx = LittleShort(mn->dx)<<FRACBITS;
-    no->dy = LittleShort(mn->dy)<<FRACBITS;
+    no->x = (fixed_t)LittleShort(mn->x)<<FRACBITS;
+    no->y = (fixed_t)LittleShort(mn->y)<<FRACBITS;
+    no->dx = (fixed_t)LittleShort(mn->dx)<<FRACBITS;
+    no->dy = (fixed_t)LittleShort(mn->dy)<<FRACBITS;
 
     for (j = 0; j < 2; j++)
     {
-      no->children[j] = (unsigned int)(mn->children[j]);
+      no->children[j] = (int)LittleLong(mn->children[j]);
 
       for (k = 0; k < 4; k++)
-        no->bbox[j][k] = LittleShort(mn->bbox[j][k])<<FRACBITS;
+        no->bbox[j][k] = (fixed_t)LittleShort(mn->bbox[j][k])<<FRACBITS;
     }
   }
 
