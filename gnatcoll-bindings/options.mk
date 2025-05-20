# $NetBSD: options.mk,v 1.0 2024/05/13 15:00:00 dkazankov Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gnatcoll-bindings
PKG_SUPPORTED_OPTIONS=		gnatcoll-cpp gnatcoll-gmp gnatcoll-iconv gnatcoll-lzma gnatcoll-omp \
				gnatcoll-python gnatcoll-python3 gnatcoll-readline gnatcoll-syslog gnatcoll-zlib
PKG_OPTIONS_OPTIONAL_GROUPS=	shared-libs
PKG_OPTIONS_GROUP.shared-libs=	enable-shared-libs disable-shared-libs
PKG_SUGGESTED_OPTIONS=		gnatcoll-cpp gnatcoll-gmp gnatcoll-iconv gnatcoll-lzma gnatcoll-omp \
				gnatcoll-python3 gnatcoll-readline gnatcoll-syslog gnatcoll-zlib

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Menable-shared-libs)
MAKE_FLAGS+=				ENABLE_SHARED=yes
USE_GCC_RUNTIME=			yes
BUILDLINK_DEPMETHOD.xmlada=		full
BUILDLINK_DEPMETHOD.gprlib=		full
BUILDLINK_DEPMETHOD.gnatcoll-core=	full
.endif
.if !empty(PKG_OPTIONS:Mdisable-shared-libs)
MAKE_FLAGS+=				ENABLE_SHARED=no
.endif
.if empty(PKG_OPTIONS:Menable-shared-libs) && empty(PKG_OPTIONS:Mdisable-shared-libs)
USE_GCC_RUNTIME=			yes
BUILDLINK_DEPMETHOD.xmlada=		full
BUILDLINK_DEPMETHOD.gprlib=		full
BUILDLINK_DEPMETHOD.gnatcoll-core=	full
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-cpp)
BINDINGS+=	cpp
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-gmp)
.  include "../../devel/gmp/buildlink3.mk"
BINDINGS+=	gmp
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-iconv)
USE_GNU_ICONV=	yes
.  include "../../converters/libiconv/buildlink3.mk"
BINDINGS+=		iconv
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-lzma)
BINDINGS+=	lzma
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-omp)
BINDINGS+=	omp
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-python)
# Python 2 only binding
PYTHON_VERSIONS_ACCEPTED+=		27
.  include "../../lang/python/pyversion.mk"
BINDINGS+=	python
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-python3)
# Python 3 only binding
PYTHON_VERSIONS_INCOMPATIBLE+=		27
.  include "../../lang/python/pyversion.mk"
BINDINGS+=	python3
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-readline)
.  include "../../devel/readline/buildlink3.mk"
BINDINGS+=	readline
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-syslog)
BINDINGS+=	syslog
.endif

.if !empty(PKG_OPTIONS:Mgnatcoll-zlib)
.  include "../../devel/zlib/buildlink3.mk"
BINDINGS+=	zlib
.endif
