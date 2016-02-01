$NetBSD$

--- src/dlls/mscorpe/pewriter.cpp.orig	2016-01-28 19:04:13.000000000 +0000
+++ src/dlls/mscorpe/pewriter.cpp
@@ -1544,7 +1544,7 @@ void PEWriter::setSectionIndex(IMAGE_SEC
             h->SectionIndex = VAL32(m_iSeedSections + DWORD(s - SpecialNames));
             break;
         }
-        s++;
+//        s++;
     }
 
 }
