# $NetBSD: options.mk,v 1.0 2024/05/13 15:00:00 dkazankov Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnatcoll-bindings
PKG_SUPPORTED_OPTIONS=	cpp gmp iconv lzma omp python python3 readline syslog zlib
PKG_SUGGESTED_OPTIONS=	cpp gmp iconv lzma omp python3 readline syslog zlib

.include "../../mk/bsd.fast.prefs.mk"

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcpp)
BINDINGS+=	cpp
.endif

.if !empty(PKG_OPTIONS:Mgmp)
.  include "../../devel/gmp/buildlink3.mk"
BINDINGS+=	gmp
.endif

.if !empty(PKG_OPTIONS:Miconv)
.  include "../../converters/libiconv/buildlink3.mk"
BINDINGS+=	iconv
.endif

.if !empty(PKG_OPTIONS:Mlzma)
BINDINGS+=	lzma
.endif

.if !empty(PKG_OPTIONS:Momp)
BINDINGS+=	omp
.endif

.if !empty(PKG_OPTIONS:Mpython)
PYTHON_VERSIONS_ACCEPTED+=	27
.  include "../../lang/python27/buildlink3.mk"
BINDINGS+=	python
.endif

.if !empty(PKG_OPTIONS:Mpython3)
PYTHON_VERSIONS_ACCEPTED+=	312 311 310 39 38
.  include "../../lang/python312/buildlink3.mk"
BINDINGS+=	python3
.endif

.if !empty(PKG_OPTIONS:Mreadline)
.  include "../../devel/readline/buildlink3.mk"
BINDINGS+=	readline
.endif

.if !empty(PKG_OPTIONS:Msyslog)
BINDINGS+=	syslog
.endif

.if !empty(PKG_OPTIONS:Mzlib)
.  include "../../devel/zlib/buildlink3.mk"
BINDINGS+=	zlib
.endif
