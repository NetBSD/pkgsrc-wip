$NetBSD$

Conditionalize extended line breaks on the ICU version in use
https://bugzilla.mozilla.org/show_bug.cgi?id=1317080


--- intl/lwbrk/nsJISx4051LineBreaker.cpp.orig	2016-11-12 13:03:54.568706590 +0100
+++ intl/lwbrk/nsJISx4051LineBreaker.cpp	2016-11-12 20:13:06.907895087 +0100
@@ -548,9 +548,11 @@
     /* CONDITIONAL_JAPANESE_STARTER = 37, [CJ] */ CLASS_CLOSE,
     /* HEBREW_LETTER = 38,                [HL] */ CLASS_CHARACTER,
     /* REGIONAL_INDICATOR = 39,           [RI] */ CLASS_CHARACTER,
+#if U_ICU_VERSION_MAJOR_NUM > 57
     /* E_BASE = 40,                       [EB] */ CLASS_BREAKABLE,
     /* E_MODIFIER = 41,                   [EM] */ CLASS_CHARACTER,
     /* ZWJ = 42,                          [ZWJ]*/ CLASS_CHARACTER
+#endif
   };
 
 #if ENABLE_INTL_API
