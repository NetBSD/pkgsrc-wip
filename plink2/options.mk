# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.plink2
PKG_SUPPORTED_OPTIONS=	native sse42 avx2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mnative)
CFLAGS+=	-march=native
.endif

.if !empty(PKG_OPTIONS:Msse42)
CFLAGS+=	-msse4.2
.endif

.if !empty(PKG_OPTIONS:Mavx2)
CFLAGS+=	-mavx2 -mbmi -mbmi2 -mlzcnt
.endif
