$NetBSD: patch-extract.c,v 1.3 2015/11/11 12:47:27 wiz Exp $

Fixes for
* https://bugzilla.redhat.com/show_bug.cgi?id=CVE-2014-8139
* https://bugzilla.redhat.com/show_bug.cgi?id=CVE-2014-8140
* http://sf.net/projects/mancha/files/sec/unzip-6.0_overflow2.diff via
  http://seclists.org/oss-sec/2014/q4/1131 and
  http://seclists.org/oss-sec/2014/q4/507 and later version
  http://sf.net/projects/mancha/files/sec/unzip-6.0_overflow3.diff via
  http://www.openwall.com/lists/oss-security/2015/02/11/7

By carefully crafting a corrupt ZIP archive with "extra fields" that
purport to have compressed blocks larger than the corresponding
uncompressed blocks in STORED no-compression mode, an attacker can
trigger a heap overflow that can result in application crash or
possibly have other unspecified impact.

This patch ensures that when extra fields use STORED mode, the
"compressed" and uncompressed block sizes match.
* CVE-2015-7697 (from Debian)
  https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=802160
* integer underflow
  https://bugs.debian.org/cgi-bin/bugreport.cgi?bug=802160

Fix CVE-2019-13232
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part1.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part2.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part3.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-manpage.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part4.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part5.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-part6.patch
  https://src.fedoraproject.org/rpms/unzip/raw/rawhide/f/unzip-zipbomb-switch.patch



--- extract.c.orig	2009-03-14 02:32:52.000000000 +0100
+++ extract.c
@@ -1,5 +1,5 @@
 /*
-  Copyright (c) 1990-2009 Info-ZIP.  All rights reserved.
+  Copyright (c) 1990-2014 Info-ZIP.  All rights reserved.
 
   See the accompanying file LICENSE, version 2009-Jan-02 or later
   (the contents of which are also included in unzip.h) for terms of use.
@@ -298,6 +298,8 @@ char ZCONST Far TruncNTSD[] =
 #ifndef SFX
    static ZCONST char Far InconsistEFlength[] = "bad extra-field entry:\n \
      EF block length (%u bytes) exceeds remaining EF data (%u bytes)\n";
+   static ZCONST char Far TooSmallEFlength[] = "bad extra-field entry:\n \
+     EF block length (%u bytes) invalid (< %d)\n";
    static ZCONST char Far InvalidComprDataEAs[] =
      " invalid compressed data for EAs\n";
 #  if (defined(WIN32) && defined(NTSD_EAS))
@@ -319,6 +321,126 @@ static ZCONST char Far UnsupportedExtraF
   "\nerror:  unsupported extra-field compression type (%u)--skipping\n";
 static ZCONST char Far BadExtraFieldCRC[] =
   "error [%s]:  bad extra-field CRC %08lx (should be %08lx)\n";
+static ZCONST char Far NotEnoughMemCover[] =
+  "error: not enough memory for bomb detection\n";
+static ZCONST char Far OverlappedComponents[] =
+  "error: invalid zip file with overlapped components (possible zip bomb)\n \
+To unzip the file anyway, rerun the command with UNZIP_DISABLE_ZIPBOMB_DETECTION=TRUE environmnent variable\n";
+
+
+
+
+
+/* A growable list of spans. */
+typedef zoff_t bound_t;
+typedef struct {
+    bound_t beg;        /* start of the span */
+    bound_t end;        /* one past the end of the span */
+} span_t;
+typedef struct {
+    span_t *span;       /* allocated, distinct, and sorted list of spans */
+    size_t num;         /* number of spans in the list */
+    size_t max;         /* allocated number of spans (num <= max) */
+} cover_t;
+
+/*
+ * Return the index of the first span in cover whose beg is greater than val.
+ * If there is no such span, then cover->num is returned.
+ */
+static size_t cover_find(cover, val)
+    cover_t *cover;
+    bound_t val;
+{
+    size_t lo = 0, hi = cover->num;
+    while (lo < hi) {
+        size_t mid = (lo + hi) >> 1;
+        if (val < cover->span[mid].beg)
+            hi = mid;
+        else
+            lo = mid + 1;
+    }
+    return hi;
+}
+
+/* Return true if val lies within any one of the spans in cover. */
+static int cover_within(cover, val)
+    cover_t *cover;
+    bound_t val;
+{
+    size_t pos = cover_find(cover, val);
+    return pos > 0 && val < cover->span[pos - 1].end;
+}
+
+/*
+ * Add a new span to the list, but only if the new span does not overlap any
+ * spans already in the list. The new span covers the values beg..end-1. beg
+ * must be less than end.
+ *
+ * Keep the list sorted and merge adjacent spans. Grow the allocated space for
+ * the list as needed. On success, 0 is returned. If the new span overlaps any
+ * existing spans, then 1 is returned and the new span is not added to the
+ * list. If the new span is invalid because beg is greater than or equal to
+ * end, then -1 is returned. If the list needs to be grown but the memory
+ * allocation fails, then -2 is returned.
+ */
+static int cover_add(cover, beg, end)
+    cover_t *cover;
+    bound_t beg;
+    bound_t end;
+{
+    size_t pos;
+    int prec, foll;
+
+    if (beg >= end)
+    /* The new span is invalid. */
+        return -1;
+
+    /* Find where the new span should go, and make sure that it does not
+       overlap with any existing spans. */
+    pos = cover_find(cover, beg);
+    if ((pos > 0 && beg < cover->span[pos - 1].end) ||
+        (pos < cover->num && end > cover->span[pos].beg))
+        return 1;
+
+    /* Check for adjacencies. */
+    prec = pos > 0 && beg == cover->span[pos - 1].end;
+    foll = pos < cover->num && end == cover->span[pos].beg;
+    if (prec && foll) {
+        /* The new span connects the preceding and following spans. Merge the
+           following span into the preceding span, and delete the following
+           span. */
+        cover->span[pos - 1].end = cover->span[pos].end;
+        cover->num--;
+        memmove(cover->span + pos, cover->span + pos + 1,
+                (cover->num - pos) * sizeof(span_t));
+    }
+    else if (prec)
+        /* The new span is adjacent only to the preceding span. Extend the end
+           of the preceding span. */
+        cover->span[pos - 1].end = end;
+    else if (foll)
+        /* The new span is adjacent only to the following span. Extend the
+           beginning of the following span. */
+        cover->span[pos].beg = beg;
+    else {
+        /* The new span has gaps between both the preceding and the following
+           spans. Assure that there is room and insert the span.  */
+        if (cover->num == cover->max) {
+            size_t max = cover->max == 0 ? 16 : cover->max << 1;
+            span_t *span = realloc(cover->span, max * sizeof(span_t));
+            if (span == NULL)
+                return -2;
+            cover->span = span;
+            cover->max = max;
+        }
+        memmove(cover->span + pos + 1, cover->span + pos,
+                (cover->num - pos) * sizeof(span_t));
+        cover->num++;
+        cover->span[pos].beg = beg;
+        cover->span[pos].end = end;
+    }
+    return 0;
+}
 
 
 
@@ -374,6 +496,44 @@ int extract_or_test_files(__G)    /* ret
     }
 #endif /* !SFX || SFX_EXDIR */
 
+    /* One more: initialize cover structure for bomb detection. Start with
+       spans that cover any extra bytes at the start, the central directory,
+       the end of central directory record (including the Zip64 end of central
+       directory locator, if present), and the Zip64 end of central directory
+       record, if present. */
+    if (uO.zipbomb == TRUE) {
+      if (G.cover == NULL) {
+        G.cover = malloc(sizeof(cover_t));
+        if (G.cover == NULL) {
+            Info(slide, 0x401, ((char *)slide,
+              LoadFarString(NotEnoughMemCover)));
+            return PK_MEM;
+        }
+        ((cover_t *)G.cover)->span = NULL;
+        ((cover_t *)G.cover)->max = 0;
+    }
+    ((cover_t *)G.cover)->num = 0;
+    if (cover_add((cover_t *)G.cover,
+                  G.extra_bytes + G.ecrec.offset_start_central_directory,
+                  G.extra_bytes + G.ecrec.offset_start_central_directory +
+                  G.ecrec.size_central_directory) != 0) {
+        Info(slide, 0x401, ((char *)slide,
+          LoadFarString(NotEnoughMemCover)));
+        return PK_MEM;
+    }
+    if ((G.extra_bytes != 0 &&
+         cover_add((cover_t *)G.cover, 0, G.extra_bytes) != 0) ||
+        (G.ecrec.have_ecr64 &&
+         cover_add((cover_t *)G.cover, G.ecrec.ec64_start,
+                   G.ecrec.ec64_end) != 0) ||
+        cover_add((cover_t *)G.cover, G.ecrec.ec_start,
+                  G.ecrec.ec_end) != 0) {
+        Info(slide, 0x401, ((char *)slide,
+          LoadFarString(OverlappedComponents)));
+        return PK_BOMB;
+      }
+    }
+
 /*---------------------------------------------------------------------------
     The basic idea of this function is as follows.  Since the central di-
     rectory lies at the end of the zipfile and the member files lie at the
@@ -498,6 +658,7 @@ int extract_or_test_files(__G)    /* ret
                     break;
                 }
             }
+            G.pInfo->zip64 = FALSE;
             if ((error = do_string(__G__ G.crec.extra_field_length,
                 EXTRA_FIELD)) != 0)
             {
@@ -591,7 +752,8 @@ int extract_or_test_files(__G)    /* ret
             if (error > error_in_archive)
                 error_in_archive = error;
             /* ...and keep going (unless disk full or user break) */
-            if (G.disk_full > 1 || error_in_archive == IZ_CTRLC) {
+            if (G.disk_full > 1 || error_in_archive == IZ_CTRLC ||
+                error == PK_BOMB) {
                 /* clear reached_end to signal premature stop ... */
                 reached_end = FALSE;
                 /* ... and cancel scanning the central directory */
@@ -1060,6 +1222,13 @@ static int extract_or_test_entrylist(__G
 
         /* seek_zipf(__G__ pInfo->offset);  */
         request = G.pInfo->offset + G.extra_bytes;
+        if (uO.zipbomb == TRUE) {
+          if (cover_within((cover_t *)G.cover, request)) {
+            Info(slide, 0x401, ((char *)slide,
+              LoadFarString(OverlappedComponents)));
+            return PK_BOMB;
+          }
+        }
         inbuf_offset = request % INBUFSIZ;
         bufstart = request - inbuf_offset;
 
@@ -1255,8 +1424,17 @@ static int extract_or_test_entrylist(__G
         if (G.lrec.compression_method == STORED) {
             zusz_t csiz_decrypted = G.lrec.csize;
 
-            if (G.pInfo->encrypted)
+            if (G.pInfo->encrypted) {
+                if (csiz_decrypted <= 12) {
+                    /* handle the error now to prevent unsigned overflow */
+                    Info(slide, 0x401, ((char *)slide,
+                      LoadFarStringSmall(ErrUnzipNoFile),
+                      LoadFarString(InvalidComprData),
+                      LoadFarStringSmall2(Inflate)));
+                    return PK_ERR;
+                }
                 csiz_decrypted -= 12;
+            }
             if (G.lrec.ucsize != csiz_decrypted) {
                 Info(slide, 0x401, ((char *)slide,
                   LoadFarStringSmall2(WrnStorUCSizCSizDiff),
@@ -1591,6 +1769,20 @@ reprompt:
             return IZ_CTRLC;        /* cancel operation by user request */
         }
 #endif
+        if (uO.zipbomb == TRUE) {
+          error = cover_add((cover_t *)G.cover, request,
+                            G.cur_zipfile_bufstart + (G.inptr - G.inbuf));
+          if (error < 0) {
+            Info(slide, 0x401, ((char *)slide,
+                                LoadFarString(NotEnoughMemCover)));
+            return PK_MEM;
+          }
+          if (error != 0) {
+            Info(slide, 0x401, ((char *)slide,
+                                LoadFarString(OverlappedComponents)));
+            return PK_BOMB;
+          }
+        }
 #ifdef MACOS  /* MacOS is no preemptive OS, thus call event-handling by hand */
         UserStop();
 #endif
@@ -1992,6 +2184,37 @@ static int extract_or_test_member(__G)  
     }
 
     undefer_input(__G);
+
+    if (uO.zipbomb == TRUE) {
+      if ((G.lrec.general_purpose_bit_flag & 8) != 0) {
+        /* skip over data descriptor (harder than it sounds, due to signature
+         * ambiguity)
+         */
+#       define SIG 0x08074b50
+#       define LOW 0xffffffff
+        uch buf[12];
+        unsigned shy = 12 - readbuf((char *)buf, 12);
+        ulg crc = shy ? 0 : makelong(buf);
+        ulg clen = shy ? 0 : makelong(buf + 4);
+        ulg ulen = shy ? 0 : makelong(buf + 8); /* or high clen if ZIP64 */
+        if (crc == SIG &&                       /* if not SIG, no signature */
+            (G.lrec.crc32 != SIG ||             /* if not SIG, have signature */
+             (clen == SIG &&                    /* if not SIG, no signature */
+              ((G.lrec.csize & LOW) != SIG ||   /* if not SIG, have signature */
+               (ulen == SIG &&                  /* if not SIG, no signature */
+                (G.pInfo->zip64 ? G.lrec.csize >> 32 : G.lrec.ucsize) != SIG
+                                                /* if not SIG, have signature */
+                )))))
+                   /* skip four more bytes to account for signature */
+                   shy += 4 - readbuf((char *)buf, 4);
+        if (G.pInfo->zip64)
+            shy += 8 - readbuf((char *)buf, 8); /* skip eight more for ZIP64 */
+        if (shy)
+            error = PK_ERR;
+
+      }
+    }
+
     return error;
 
 } /* end function extract_or_test_member() */
@@ -2023,7 +2246,8 @@ static int TestExtraField(__G__ ef, ef_l
         ebID = makeword(ef);
         ebLen = (unsigned)makeword(ef+EB_LEN);
 
-        if (ebLen > (ef_len - EB_HEADSIZE)) {
+        if (ebLen > (ef_len - EB_HEADSIZE))
+        {
            /* Discovered some extra field inconsistency! */
             if (uO.qflag)
                 Info(slide, 1, ((char *)slide, "%-22s ",
@@ -2032,6 +2256,16 @@ static int TestExtraField(__G__ ef, ef_l
               ebLen, (ef_len - EB_HEADSIZE)));
             return PK_ERR;
         }
+        else if (ebLen < EB_HEADSIZE)
+        {
+            /* Extra block length smaller than header length. */
+            if (uO.qflag)
+                Info(slide, 1, ((char *)slide, "%-22s ",
+                  FnFilter1(G.filename)));
+            Info(slide, 1, ((char *)slide, LoadFarString(TooSmallEFlength),
+              ebLen, EB_HEADSIZE));
+            return PK_ERR;
+        }
 
         switch (ebID) {
             case EF_OS2:
@@ -2217,6 +2451,7 @@ static int test_compr_eb(__G__ eb, eb_si
     ulg eb_ucsize;
     uch *eb_ucptr;
     int r;
+    ush method;
 
     if (compr_offset < 4)                /* field is not compressed: */
         return PK_OK;                    /* do nothing and signal OK */
@@ -2226,6 +2461,13 @@ static int test_compr_eb(__G__ eb, eb_si
          eb_size <= (compr_offset + EB_CMPRHEADLEN)))
         return IZ_EF_TRUNC;               /* no compressed data! */
 
+    method = makeword(eb + (EB_HEADSIZE + compr_offset));
+    if ((method == STORED) &&
+        (eb_size - compr_offset - EB_CMPRHEADLEN != eb_ucsize))
+	return PK_ERR;			  /* compressed & uncompressed
+					   * should match in STORED
+					   * method */
+
     if (
 #ifdef INT_16BIT
         (((ulg)(extent)eb_ucsize) != eb_ucsize) ||
@@ -2701,6 +2943,12 @@ __GDEF
     int repeated_buf_err;
     bz_stream bstrm;
 
+    if (G.incnt <= 0 && G.csize <= 0L) {
+        /* avoid an infinite loop */
+        Trace((stderr, "UZbunzip2() got empty input\n"));
+        return 2;
+    }
+
 #if (defined(DLL) && !defined(NO_SLIDE_REDIR))
     if (G.redirect_slide)
         wsize = G.redirect_size, redirSlide = G.redirect_buffer;
@@ -2808,7 +3056,7 @@ __GDEF
 #endif
 
     G.inptr = (uch *)bstrm.next_in;
-    G.incnt = (G.inbuf + INBUFSIZ) - G.inptr;  /* reset for other routines */
+    G.incnt -= G.inptr - G.inbuf;       /* reset for other routines */
 
 uzbunzip_cleanup_exit:
     err = BZ2_bzDecompressEnd(&bstrm);
