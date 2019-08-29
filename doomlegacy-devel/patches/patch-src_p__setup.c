$NetBSD$

Typecast signed result from LE_SWAP16 macro to unsigned where required.
Only relevant for big endian machines.
Proposed by upstream for test.

Last hunk contains the former pkgsrc patch that was sent to upstream.

--- src/p_setup.c.orig	2019-08-21 09:16:38.000000000 +0000
+++ src/p_setup.c
@@ -348,6 +348,7 @@ void P_LoadVertexes (lumpnum_t lumpnum)
     // internal representation as fixed.
     for (i=0 ; i<numvertexes ; i++, li++, ml++)
     {
+        // signed
         li->x = LE_SWAP16(ml->x)<<FRACBITS;
         li->y = LE_SWAP16(ml->y)<<FRACBITS;
     }
@@ -404,6 +405,7 @@ void P_LoadSegs ( lumpnum_t lumpnum )
     for (i=0 ; i<numsegs ; i++, li++, ml++)
     {
         // [WDJ] Detect buggy wad, bad vertex number
+        // signed
         vn1 = LE_SWAP16(ml->v1);
         vn2 = LE_SWAP16(ml->v2);
         if( vn1 > numvertexes || vn2 > numvertexes )
@@ -429,7 +431,7 @@ void P_LoadSegs ( lumpnum_t lumpnum )
 
         li->angle = (LE_SWAP16(ml->angle))<<16;
         li->offset = (LE_SWAP16(ml->offset))<<16;
-        linedef = LE_SWAP16(ml->linedef);
+        linedef = (uint16_t)( LE_SWAP16(ml->linedef) );
         // [WDJ] Detect buggy wad, bad linedef number
         if( linedef > numlines ) {
             I_SoftError( "P_LoadSegs, linedef #%i, > numlines %i\n", linedef, numlines );
@@ -437,7 +439,7 @@ void P_LoadSegs ( lumpnum_t lumpnum )
         }
         ldef = &lines[linedef];
         li->linedef = ldef;
-        side = LE_SWAP16(ml->side);
+        side = (uint16_t)( LE_SWAP16(ml->side) );
         if( side != 0 && side != 1 )
         {
             // [WDJ] buggy wad
@@ -497,8 +499,8 @@ void P_LoadSubsectors( lumpnum_t lumpnum
 
     for (i=0 ; i<numsubsectors ; i++, ss++, ms++)
     {
-        ss->numlines = LE_SWAP16(ms->numsegs);
-        ss->firstline = LE_SWAP16(ms->firstseg);  // unsigned
+        ss->numlines = (uint16_t)( LE_SWAP16(ms->numsegs) );
+        ss->firstline = (uint16_t)( LE_SWAP16(ms->firstseg) );  // unsigned
         // cannot check if valid, segs not loaded yet
     }
 
@@ -679,6 +681,7 @@ void P_LoadSectors( lumpnum_t lumpnum )
     ss = sectors;
     for (i=0 ; i<numsectors ; i++, ss++, ms++)
     {
+        // signed
         ss->floorheight = LE_SWAP16(ms->floorheight)<<FRACBITS;
         ss->ceilingheight = LE_SWAP16(ms->ceilingheight)<<FRACBITS;
 
@@ -702,9 +705,10 @@ void P_LoadSectors( lumpnum_t lumpnum )
         ss->floorpic = P_AddLevelFlat (ms->floorpic);
         ss->ceilingpic = P_AddLevelFlat (ms->ceilingpic);
 
-        ss->lightlevel = LE_SWAP16(ms->lightlevel);
-        ss->special = LE_SWAP16(ms->special);
-        ss->tag = LE_SWAP16(ms->tag);
+        ss->lightlevel = (uint16_t)( LE_SWAP16(ms->lightlevel) );
+        // all values are unsigned, but special field is signed short
+        ss->special = (uint16_t)( LE_SWAP16(ms->special) );
+        ss->tag = (uint16_t)( LE_SWAP16(ms->tag) );  // unsigned
 
         ss->thinglist = NULL;
         ss->touching_thinglist = NULL; //SoM: 4/7/2000
@@ -789,7 +793,7 @@ void P_LoadNodes (int lump)
         no->dy = LE_SWAP16(mn->dy)<<FRACBITS;
         for (j=0 ; j<2 ; j++)
         {
-            no->children[j] = LE_SWAP16(mn->children[j]);
+            no->children[j] = (uint16_t)( LE_SWAP16(mn->children[j]) );
             for (k=0 ; k<4 ; k++)
                 no->bbox[j][k] = LE_SWAP16(mn->bbox[j][k])<<FRACBITS;
         }
@@ -843,8 +847,8 @@ void P_LoadThings (int lump)
         mt->x = LE_SWAP16(dmt->x);
         mt->y = LE_SWAP16(dmt->y);
         mt->angle   = LE_SWAP16(dmt->angle);
-        mt->type    = LE_SWAP16(dmt->type);
-        mt->options = LE_SWAP16(dmt->flags);
+        mt->type    = LE_SWAP16(dmt->type); // DoomEd number
+        mt->options = (uint16_t)( LE_SWAP16(dmt->flags) );  // bit flags
         mt->mobj = NULL; //SoM:
 
         if( gamedesc_id == GDESC_tnt && gamemap == 31)
@@ -897,9 +901,9 @@ void P_LoadLineDefs (int lump)
     ld = lines;
     for (i=0 ; i<numlines ; i++, mld++, ld++)
     {
-        ld->flags = (uint16_t) LE_SWAP16(mld->flags);
-        ld->special = LE_SWAP16(mld->special);
-        ld->tag = LE_SWAP16(mld->tag);
+        ld->flags = (uint16_t)( LE_SWAP16(mld->flags) );  // bit flags
+        ld->special = (uint16_t)( LE_SWAP16(mld->special) );
+        ld->tag = (uint16_t)( LE_SWAP16(mld->tag) );
         v1 = ld->v1 = &vertexes[ LE_SWAP16(mld->v1) ];
         v2 = ld->v2 = &vertexes[ LE_SWAP16(mld->v2) ];
         ld->dx = v2->x - v1->x;
@@ -942,8 +946,8 @@ void P_LoadLineDefs (int lump)
         // Set soundorg in P_GroupLines
 
         // NULL_INDEX = no sidedef
-        ld->sidenum[0] = LE_SWAP16(mld->sidenum[0]);
-        ld->sidenum[1] = LE_SWAP16(mld->sidenum[1]);
+        ld->sidenum[0] = (uint16_t)( LE_SWAP16(mld->sidenum[0]) );
+        ld->sidenum[1] = (uint16_t)( LE_SWAP16(mld->sidenum[1]) );
 
         // [WDJ] detect common wad errors and make playable, similar to prboom
         if( ld->sidenum[0] == NULL_INDEX )
@@ -1057,7 +1061,7 @@ void P_LoadSideDefs (int lump)
         sd->bottomtexture = R_TextureNumForName(msd->bottomtexture);
         sd->midtexture = R_TextureNumForName(msd->midtexture);
 
-        sd->sector = &sectors[LE_SWAP16(msd->sector)];
+        sd->sector = &sectors[ (uint16_t)( LE_SWAP16(msd->sector) )];
     }
 
     Z_Free (data);
@@ -1123,7 +1127,7 @@ void P_LoadSideDefs2(int lump)
       // Check if valid texture first, on failure check if valid colormap,
       // because we have func that can check texture without error.
 
-      uint16_t secnum = LE_SWAP16(msd->sector);
+      uint16_t secnum = (uint16_t)( LE_SWAP16(msd->sector) );
       // [WDJ] Check for buggy wad, like prboom
       if( secnum >= numsectors )
       {
@@ -1331,8 +1335,8 @@ void P_LoadBlockMap (int lump)
 
   blockmaphead[0] = LE_SWAP16(wadblockmaplump[0]);  // map orgin_x
   blockmaphead[1] = LE_SWAP16(wadblockmaplump[1]);  // map orgin_y
-  blockmaphead[2] = LE_SWAP16(wadblockmaplump[2]);  // number columns (x size)
-  blockmaphead[3] = LE_SWAP16(wadblockmaplump[3]);  // number rows (y size)
+  blockmaphead[2] = (uint16_t)( LE_SWAP16(wadblockmaplump[2]) );  // number columns (x size)
+  blockmaphead[3] = (uint16_t)( LE_SWAP16(wadblockmaplump[3]) );  // number rows (y size)
 
   bmaporgx = blockmaphead[0]<<FRACBITS;
   bmaporgy = blockmaphead[1]<<FRACBITS;
@@ -1348,7 +1352,10 @@ void P_LoadBlockMap (int lump)
   // read blockmap index array
   for (i=4 ; i<firstlist ; i++)  // for all entries in wad offset index
   {
-      uint32_t  bme = LE_SWAP16(wadblockmaplump[i]);  // offset
+      // [WDJ] LE_SWAP16 returns a 16 bit signed value on a big-endian machine,
+      // so must make it unsigned, otherwise it can get sign extended.
+      // Found by Michael Bauerle.
+      uint32_t  bme = (uint16_t)( LE_SWAP16(wadblockmaplump[i]) );  // offset
       // upon overflow, the bme will wrap to low values
       if ( (bme < firstlist)  // too small to be valid
            && (bme < 0x1000) && (prev_bme > 0xf000))  // wrapped
@@ -1384,8 +1391,9 @@ void P_LoadBlockMap (int lump)
   for (i=firstlist ; i<count ; i++)  // for all list entries in wad blockmap
   {
       // killough 3/1/98
-      // keep -1 (0xffff), but other values are unsigned
-      uint16_t  bme = LE_SWAP16(wadblockmaplump[i]);
+      // Unsigned except for -1, which will be read as 0xFFFF.
+      // [WDJ] LE_SWAP16 is signed on big-endian machines, so convert to prevent errors.
+      uint16_t  bme = (uint16_t)( LE_SWAP16(wadblockmaplump[i]) );
       blockmaphead[i] = (bme == 0xffff)? ((uint32_t) -1) : ((uint32_t) bme);
   }
 
