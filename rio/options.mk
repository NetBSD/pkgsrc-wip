# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.rio
PKG_SUPPORTED_OPTIONS=	man
PKG_SUGGESTED_OPTIONS=	man

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	man

.if !empty(PKG_OPTIONS:Mman)
PLIST.man=		yes
BUILD_DEPENDS+=		scdoc>=1.11.0:../../textproc/scdoc
SCDOC=			${LOCALBASE}/bin/scdoc
INSTALLATION_DIRS+=	man/man1 man/man5
.endif
