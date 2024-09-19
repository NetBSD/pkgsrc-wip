$NetBSD: patch-mono_utils_mono-compiler.h,v 1.3 2014/11/30 08:40:51 spz Exp $

Make sure that TLS variables are actually emitted, since the compiler
doesn't see all references.

