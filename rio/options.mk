# $NetBSD$

PKG_OPTIONS_VAR=	PKG_OPTIONS.rio
PKG_SUPPORTED_OPTIONS=	manual
PKG_SUGGESTED_OPTIONS=	manual

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	man

.if !empty(PKG_OPTIONS:Mmanual)
PLIST.man=		yes
BUILD_DEPENDS+=		scdoc>=1.11.0:../../textproc/scdoc
SCDOC=			${PREFIX}/bin/scdoc
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5
.endif
