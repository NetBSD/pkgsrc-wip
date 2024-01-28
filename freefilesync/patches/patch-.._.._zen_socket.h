$NetBSD$

Check for symbol existence before using them.

--- ../../zen/socket.h.orig	2024-01-07 18:25:42.000000000 +0000
+++ ../../zen/socket.h
@@ -44,12 +44,24 @@ std::wstring formatGaiErrorCode(int ec)
             ZEN_CHECK_CASE_FOR_CONSTANT(EAI_SOCKTYPE);
             ZEN_CHECK_CASE_FOR_CONSTANT(EAI_SYSTEM);
             ZEN_CHECK_CASE_FOR_CONSTANT(EAI_OVERFLOW);
+#ifdef EAI_INPROGRESS
             ZEN_CHECK_CASE_FOR_CONSTANT(EAI_INPROGRESS);
+#endif
+#ifdef EAI_CANCELED
             ZEN_CHECK_CASE_FOR_CONSTANT(EAI_CANCELED);
+#endif
+#ifdef EAI_NOTCANCELED
             ZEN_CHECK_CASE_FOR_CONSTANT(EAI_NOTCANCELED);
+#endif
+#ifdef EAI_ALLDONE
             ZEN_CHECK_CASE_FOR_CONSTANT(EAI_ALLDONE);
+#endif
+#ifdef EAI_INTR
             ZEN_CHECK_CASE_FOR_CONSTANT(EAI_INTR);
+#endif
+#ifdef EAI_IDN_ENCODE
             ZEN_CHECK_CASE_FOR_CONSTANT(EAI_IDN_ENCODE);
+#endif
         default:
             return replaceCpy(_("Error code %x"), L"%x", numberTo<std::wstring>(ec));
     }
