# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.gnucash
PKG_SUPPORTED_OPTIONS=	libdbi libofx python
PKG_SUGGESTED_OPTIONS=	libdbi libofx

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	dbi ofx

.if !empty(PKG_OPTIONS:Mlibofx)
PLIST.ofx=	yes
.include "../../finance/libofx/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ofx
.endif

.if !empty(PKG_OPTIONS:Mlibdbi)
CONFIGURE_ARGS+=	--enable-dbi
PLIST.dbi=	yes

# to make a configure test happy
BUILD_DEPENDS+=		libdbi-driver-sqlite3-[0-9]*:../../databases/libdbi-driver-sqlite3
.include "../../databases/libdbi/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dbi
.endif

.if !empty(PKG_OPTIONS:Mpython)
CONFIGURE_ARGS+=	--enable-python
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 # not yet ported as of 2.6.1
REPLACE_PYTHON+=	src/python/pycons/*.py src/python/pycons/pycons
PY_PATCHPLIST=		yes
PLIST_SRC+=		PLIST.python

DEPENDS+=		${PYPKGPREFIX}-gtk2-[0-9]*:../../x11/py-gtk2
# /usr/pkg/share/gnucash/python/pycons/console.py imports readline
DEPENDS+=		${PYPKGPREFIX}-readline-[0-9]*:../../devel/py-readline

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.else
CONFIGURE_ARGS+=	--disable-python
.endif
