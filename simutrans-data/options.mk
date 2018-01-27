# $NetBSD$

PKG_OPTIONS_VAR=		PKG_OPTIONS.simutrans-data
PKG_SUPPORTED_OPTIONS+=		pak64 pak128 pak128de pak64jp pak96hd
PKG_SUGGESTED_OPTIONS=		pak64
PLIST_VARS+=			pak64 pak128

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpak96hd)
DISTFILES=	-http://hd.simutrans.com/release/PakHD_v04B_100-0.zip
.endif

.if !empty(PKG_OPTIONS:Mpak64jp)
DISTFILES=	simupak64.japan-120-0-1.zip
.endif

.if !empty(PKG_OPTIONS:Mpak128de)
DISTFILES=	PAK128.german_0.9_120.x.zip
.endif

.if !empty(PKG_OPTIONS:Mpak64)
DISTFILES+=	simupak64-120-2.zip
DISTNAME=	simupak64-120-2
WRKSRC=		${WRKDIR}/simutrans
PLIST.pak64=	yes
.endif

.if !empty(PKG_OPTIONS:Mpak128)
DISTFILES=	pak128-2.6--ST120.zip
DISTNAME=	pak128-2.6
WRKSRC=		${WRKDIR}/pak128
PLIST.pak128=	yes
.endif
