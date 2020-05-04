$NetBSD$

On big endian machines the build fails like this without the patch:
error: call of overloaded 'LittleLong()' is ambiguous

--- wad.cpp.orig	2016-01-07 20:33:31.000000000 +0000
+++ wad.cpp
@@ -380,8 +380,8 @@ void FWadWriter::Close ()
 	{
 		int32_t head[2];
 
-		head[0] = LittleLong(Lumps.Size());
-		head[1] = LittleLong(ftell (File));
+		head[0] = LittleLong((int)Lumps.Size());
+		head[1] = LittleLong((int)ftell (File));
 
 		SafeWrite (&Lumps[0], sizeof(WadLump)*Lumps.Size());
 		fseek (File, 4, SEEK_SET);
@@ -396,7 +396,7 @@ void FWadWriter::CreateLabel (const char
 	WadLump lump;
 
 	strncpy (lump.Name, name, 8);
-	lump.FilePos = LittleLong(ftell (File));
+	lump.FilePos = LittleLong((int)ftell (File));
 	lump.Size = 0;
 	Lumps.Push (lump);
 }
@@ -406,7 +406,7 @@ void FWadWriter::WriteLump (const char *
 	WadLump lump;
 
 	strncpy (lump.Name, name, 8);
-	lump.FilePos = LittleLong(ftell (File));
+	lump.FilePos = LittleLong((int)ftell (File));
 	lump.Size = LittleLong(len);
 	Lumps.Push (lump);
 
