$NetBSD: patch-hfaxd_FileTransfer.c++,v 1.1 2012/04/10 10:22:45 ftigeot Exp $

--- hfaxd/FileTransfer.c++.orig	2010-09-15 14:43:15.000000000 +0000
+++ hfaxd/FileTransfer.c++
@@ -47,6 +47,16 @@
 #endif
 #endif /* CHAR_BIT */
 
+/*
+ * Copied from libtiff-3.9 as libtiff-4.0 does not provide it anymore.
+ */
+typedef struct {
+	uint16		tdir_tag;	/* see below */
+	uint16		tdir_type;	/* data type; see below */
+	uint32		tdir_count;	/* number of items; length in spec */
+	uint32		tdir_offset;	/* byte offset to field data */
+} OldClassicTIFFDirEntry;
+
 #define	HAVE_PSLEVEL2	false
 #define	HAVE_PCL5	false
 
@@ -146,26 +156,26 @@ HylaFAXServer::retrieveCmd(const char* n
  * a single IFD/image from a TIFF file.
  */
 typedef struct {
-    TIFFDirEntry	SubFileType;
-    TIFFDirEntry	ImageWidth;
-    TIFFDirEntry	ImageLength;
-    TIFFDirEntry	BitsPerSample;
-    TIFFDirEntry	Compression;
-    TIFFDirEntry	Photometric;
-    TIFFDirEntry	FillOrder;
-    TIFFDirEntry	StripOffsets;
-    TIFFDirEntry	Orientation;
-    TIFFDirEntry	SamplesPerPixel;
-    TIFFDirEntry	RowsPerStrip;
-    TIFFDirEntry	StripByteCounts;
-    TIFFDirEntry	XResolution;
-    TIFFDirEntry	YResolution;
-    TIFFDirEntry	Options;		// T4 or T6
-    TIFFDirEntry	ResolutionUnit;
-    TIFFDirEntry	PageNumber;
-    TIFFDirEntry	BadFaxLines;
-    TIFFDirEntry	CleanFaxData;
-    TIFFDirEntry	ConsecutiveBadFaxLines;
+    OldClassicTIFFDirEntry	SubFileType;
+    OldClassicTIFFDirEntry	ImageWidth;
+    OldClassicTIFFDirEntry	ImageLength;
+    OldClassicTIFFDirEntry	BitsPerSample;
+    OldClassicTIFFDirEntry	Compression;
+    OldClassicTIFFDirEntry	Photometric;
+    OldClassicTIFFDirEntry	FillOrder;
+    OldClassicTIFFDirEntry	StripOffsets;
+    OldClassicTIFFDirEntry	Orientation;
+    OldClassicTIFFDirEntry	SamplesPerPixel;
+    OldClassicTIFFDirEntry	RowsPerStrip;
+    OldClassicTIFFDirEntry	StripByteCounts;
+    OldClassicTIFFDirEntry	XResolution;
+    OldClassicTIFFDirEntry	YResolution;
+    OldClassicTIFFDirEntry	Options;		// T4 or T6
+    OldClassicTIFFDirEntry	ResolutionUnit;
+    OldClassicTIFFDirEntry	PageNumber;
+    OldClassicTIFFDirEntry	BadFaxLines;
+    OldClassicTIFFDirEntry	CleanFaxData;
+    OldClassicTIFFDirEntry	ConsecutiveBadFaxLines;
     uint32		link;			// offset to next directory
     uint32		xres[2];		// X resolution indirect value
     uint32		yres[2];		// Y resolution indirect value
@@ -211,7 +221,7 @@ HylaFAXServer::retrievePageCmd(const cha
 		uint32* sb;
 		TIFFGetField(tif, TIFFTAG_STRIPBYTECOUNTS, &sb);
 		file_size = sizeof (DirTemplate) +
-		    sizeof (TIFFHeader) + sizeof (uint16);
+		    sizeof (TIFFHeaderClassic) + sizeof (uint16);
 		for (tstrip_t s = 0, ns = TIFFNumberOfStrips(tif); s < ns; s++)
 		    file_size += sb[s];
 		reply(code, "%s for %s (%lu bytes).",
@@ -243,10 +253,10 @@ HylaFAXServer::openTIFF(const char* name
 	if (fd >= 0) {
 	    union {
 		char buf[512];
-		TIFFHeader h;
+		TIFFHeaderClassic h;
 	    } b;
 	    ssize_t cc = Sys::read(fd, (char*) &b, sizeof (b));
-	    if (cc > (ssize_t)sizeof (b.h) && b.h.tiff_version == TIFF_VERSION &&
+	    if (cc > (ssize_t)sizeof (b.h) && b.h.tiff_version == TIFFLIB_VERSION &&
 	      (b.h.tiff_magic == TIFF_BIGENDIAN ||
 	       b.h.tiff_magic == TIFF_LITTLEENDIAN)) {
 		(void) lseek(fd, 0L, SEEK_SET);		// rewind
@@ -300,12 +310,12 @@ HylaFAXServer::sendTIFFData(TIFF* tif, F
 }
 
 static void
-getLong(TIFF* tif, TIFFDirEntry& de)
+getLong(TIFF* tif, OldClassicTIFFDirEntry& de)
 {
     TIFFGetField(tif, de.tdir_tag, &de.tdir_offset);
 }
 static void
-getShort(TIFF* tif, TIFFDirEntry& de)
+getShort(TIFF* tif, OldClassicTIFFDirEntry& de)
 {
     uint16 v;
     TIFFGetField(tif, de.tdir_tag, &v);
@@ -325,7 +335,7 @@ HylaFAXServer::sendTIFFHeader(TIFF* tif,
 {
     static DirTemplate templ = {
 #define	TIFFdiroff(v) \
-    (uint32) (sizeof (TIFFHeader) + sizeof (uint16) + \
+    (uint32) (sizeof (TIFFHeaderClassic) + sizeof (uint16) + \
       (intptr_t) &(((DirTemplate*) 0)->v))
 	{ TIFFTAG_SUBFILETYPE,		TIFF_LONG,	1 },
 	{ TIFFTAG_IMAGEWIDTH,		TIFF_LONG,	1 },
@@ -350,7 +360,7 @@ HylaFAXServer::sendTIFFHeader(TIFF* tif,
 	0,					// next directory
 	{ 0, 1 }, { 0, 1 },			// x+y resolutions
     };
-#define	NTAGS	((TIFFdiroff(link)-TIFFdiroff(SubFileType)) / sizeof (TIFFDirEntry))
+#define	NTAGS	((TIFFdiroff(link)-TIFFdiroff(SubFileType)) / sizeof (OldClassicTIFFDirEntry))
     /*
      * Construct the TIFF header for this IFD using
      * the preconstructed template above.  We extract
@@ -359,14 +369,14 @@ HylaFAXServer::sendTIFFHeader(TIFF* tif,
      * of things about the contents of the TIFF file.
      */
     struct {
-	TIFFHeader h;
+	TIFFHeaderClassic h;
 	uint16	dircount;
 	u_char	dirstuff[sizeof (templ)];
     } buf;
     union { int32 i; char c[4]; } u; u.i = 1;
     buf.h.tiff_magic = (u.c[0] == 0 ? TIFF_BIGENDIAN : TIFF_LITTLEENDIAN);
-    buf.h.tiff_version = TIFF_VERSION;
-    buf.h.tiff_diroff = sizeof (TIFFHeader);
+    buf.h.tiff_version = TIFFLIB_VERSION;
+    buf.h.tiff_diroff = sizeof (TIFFHeaderClassic);
     buf.dircount = (uint16) NTAGS;
     getLong(tif, templ.SubFileType);
     getLong(tif, templ.ImageWidth);
@@ -394,7 +404,7 @@ HylaFAXServer::sendTIFFHeader(TIFF* tif,
     getShort(tif, templ.CleanFaxData);
     getLong(tif, templ.ConsecutiveBadFaxLines);
     if (buf.h.tiff_magic == TIFF_BIGENDIAN) {
-	TIFFDirEntry* dp = &templ.SubFileType;
+	OldClassicTIFFDirEntry* dp = &templ.SubFileType;
 	for (u_int i = 0; i < NTAGS; i++) {
 	    if (dp->tdir_type == TIFF_SHORT)
 		dp->tdir_offset <<= 16;
