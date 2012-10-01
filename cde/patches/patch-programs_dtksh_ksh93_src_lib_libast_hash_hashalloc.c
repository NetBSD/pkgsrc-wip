$NetBSD: patch-programs_dtksh_ksh93_src_lib_libast_hash_hashalloc.c,v 1.1 2012/10/01 06:41:29 jellehermsen Exp $

--- programs/dtksh/ksh93/src/lib/libast/hash/hashalloc.c.orig	2012-09-28 21:34:22.000000000 +0000
+++ programs/dtksh/ksh93/src/lib/libast/hash/hashalloc.c
@@ -214,7 +214,7 @@ hashalloc __PARAM__((Hash_table_t* ref, 
 			tab->flags |= HASH_STATIC;
 			break;
 		case HASH_va_list:
-#if defined(__FreeBSD__) && !defined(__LP64__)
+#if defined(CSRG_BASED) && !defined(__LP64__)
 			if (vp < &va[elementsof(va)]) *vp++ = ap;
 			ap = va_arg(ap, va_list);
 #else
@@ -230,7 +230,7 @@ hashalloc __PARAM__((Hash_table_t* ref, 
 		case 0:
 			if (vp > va)
 			{
-#if defined(__FreeBSD__) && !defined(__LP64__)
+#if defined(CSRG_BASED) && !defined(__LP64__)
 				ap = *--vp;
 #else
 				vp--;
