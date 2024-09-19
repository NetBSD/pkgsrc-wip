$NetBSD$

--- src/VBox/Runtime/r3/posix/utf8-posix.cpp.orig	2016-03-04 19:30:04.000000000 +0000
+++ src/VBox/Runtime/r3/posix/utf8-posix.cpp
@@ -173,7 +173,7 @@ static int rtstrConvertCached(const void
         iconv_t hIconv = (iconv_t)*phIconv;
         if (hIconv == (iconv_t)-1)
         {
-#ifdef RT_OS_SOLARIS
+#if defined(RT_OS_SOLARIS) || defined(RT_OS_NETBSD)
             /* Solaris doesn't grok empty codeset strings, so help it find the current codeset. */
             if (!*pszInputCS)
                 pszInputCS = rtStrGetLocaleCodeset();
@@ -494,4 +494,3 @@ RTR3DECL(int)  RTStrCurrentCPToUtf8Tag(c
     }
     return rtStrConvertWrapper(pszString, cch, "", ppszString, 0, "UTF-8", 2, RTSTRICONV_LOCALE_TO_UTF8);
 }
-
