$NetBSD$

On big endian machines the build fails like this without the patch:
error: call of overloaded 'LittleShort()' is ambiguous

--- processor.cpp.orig	2016-01-07 20:33:31.000000000 +0000
+++ processor.cpp
@@ -944,8 +944,8 @@ void FProcessor::WriteVertices (FWadWrit
 
 	for (i = 0; i < count; ++i)
 	{
-		verts[i*2] = LittleShort(vertdata[i].x >> FRACBITS);
-		verts[i*2+1] = LittleShort(vertdata[i].y >> FRACBITS);
+		verts[i*2] = LittleShort((short)(vertdata[i].x >> FRACBITS));
+		verts[i*2+1] = LittleShort((short)(vertdata[i].y >> FRACBITS));
 	}
 	out.WriteLump ("VERTEXES", verts, sizeof(*verts)*count*2);
 	delete[] verts;
@@ -1011,7 +1011,7 @@ void FProcessor::WriteSides (FWadWriter
 		memcpy(Sides[i].toptexture, Level.Sides[i].toptexture, 8);
 		memcpy(Sides[i].bottomtexture, Level.Sides[i].bottomtexture, 8);
 		memcpy(Sides[i].midtexture, Level.Sides[i].midtexture, 8);
-		Sides[i].sector = LittleShort(Level.Sides[i].sector);
+		Sides[i].sector = LittleShort((unsigned short)(Level.Sides[i].sector));
 	}
 	out.WriteLump ("SIDEDEFS", Sides, Level.NumSides()*sizeof(*Sides));
 	delete[] Sides;
@@ -1116,10 +1116,10 @@ void FProcessor::WriteNodes2 (FWadWriter
 
 	for (i = 0; i < count; ++i)
 	{
-		nodes[0] = LittleShort(zaNodes[i].x >> 16);
-		nodes[1] = LittleShort(zaNodes[i].y >> 16);
-		nodes[2] = LittleShort(zaNodes[i].dx >> 16);
-		nodes[3] = LittleShort(zaNodes[i].dy >> 16);
+		nodes[0] = LittleShort((short)(zaNodes[i].x >> 16));
+		nodes[1] = LittleShort((short)(zaNodes[i].y >> 16));
+		nodes[2] = LittleShort((short)(zaNodes[i].dx >> 16));
+		nodes[3] = LittleShort((short)(zaNodes[i].dy >> 16));
 		nodes += 4;
 		const short *inodes = (short *)&zaNodes[i].bbox[0][0];
 		for (j = 0; j < 2*4; ++j)
@@ -1162,10 +1162,10 @@ void FProcessor::WriteNodes5 (FWadWriter
 		{
 			coord[j] = LittleShort(inodes[j]);
 		}
-		nodes[i].x = LittleShort(zaNodes[i].x >> 16);
-		nodes[i].y = LittleShort(zaNodes[i].y >> 16);
-		nodes[i].dx = LittleShort(zaNodes[i].dx >> 16);
-		nodes[i].dy = LittleShort(zaNodes[i].dy >> 16);
+		nodes[i].x = LittleShort((short)(zaNodes[i].x >> 16));
+		nodes[i].y = LittleShort((short)(zaNodes[i].y >> 16));
+		nodes[i].dx = LittleShort((short)(zaNodes[i].dx >> 16));
+		nodes[i].dy = LittleShort((short)(zaNodes[i].dy >> 16));
 		for (j = 0; j < 2; ++j)
 		{
 			nodes[i].children[j] = LittleLong(zaNodes[i].children[j]);
@@ -1247,8 +1247,8 @@ void FProcessor::WriteGLVertices (FWadWr
 
 	for (i = 0; i < count; ++i)
 	{
-		verts[i*2+1] = LittleShort(vertdata[i].x);
-		verts[i*2+2] = LittleShort(vertdata[i].y);
+		verts[i*2+1] = LittleShort((short)(vertdata[i].x));
+		verts[i*2+2] = LittleShort((short)(vertdata[i].y));
 	}
 	out.WriteLump ("GL_VERT", verts, sizeof(*verts)*(count*2+1));
 	delete[] verts;
@@ -1280,15 +1280,15 @@ void FProcessor::WriteGLSegs (FWadWriter
 		}
 		else
 		{
-			segdata[i].v1 = LittleShort(0x8000 | (WORD)(Level.GLSegs[i].v1 - Level.NumOrgVerts));
+			segdata[i].v1 = LittleShort((WORD)(0x8000 | (WORD)(Level.GLSegs[i].v1 - Level.NumOrgVerts)));
 		}
 		if (Level.GLSegs[i].v2 < (DWORD)Level.NumOrgVerts)
 		{
-			segdata[i].v2 = (WORD)LittleShort(Level.GLSegs[i].v2);
+			segdata[i].v2 = (WORD)LittleShort((WORD)Level.GLSegs[i].v2);
 		}
 		else
 		{
-			segdata[i].v2 = LittleShort(0x8000 | (WORD)(Level.GLSegs[i].v2 - Level.NumOrgVerts));
+			segdata[i].v2 = LittleShort((WORD)(0x8000 | (WORD)(Level.GLSegs[i].v2 - Level.NumOrgVerts)));
 		}
 		segdata[i].linedef = LittleShort((WORD)Level.GLSegs[i].linedef);
 		segdata[i].side = LittleShort(Level.GLSegs[i].side);
@@ -1333,7 +1333,7 @@ void FProcessor::WriteGLSegs5 (FWadWrite
 		{
 			segdata[i].v2 = LittleLong(0x80000000u | ((int)Level.GLSegs[i].v2 - Level.NumOrgVerts));
 		}
-		segdata[i].linedef = LittleShort(Level.GLSegs[i].linedef);
+		segdata[i].linedef = LittleLong(Level.GLSegs[i].linedef);
 		segdata[i].side = LittleShort(Level.GLSegs[i].side);
 		segdata[i].partner = LittleLong(Level.GLSegs[i].partner);
 	}
