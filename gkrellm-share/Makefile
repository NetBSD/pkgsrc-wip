# $NetBSD: Makefile,v 1.7 2012/10/23 19:51:03 asau Exp $

.include "../../wip/gkrellm/Makefile.common"

GKRELLM_PKGBASE=	gkrellm-share

COMMENT=		GKrellM2 locale files

BUILD_DIRS=		po
INSTALLATION_DIRS=	share/gkrellm2

.if !empty(PKG_OPTIONS:Mnls)
USE_TOOLS+=		msgfmt
USE_PKGLOCALEDIR=	yes
INSTALL_MAKE_FLAGS=	LOCALEDIR=${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale
INSTALLATION_DIRS+=	${PKGLOCALEDIR}/locale
PLIST.nls=		yes
.endif
PLIST_VARS+=		nls
PRINT_PLIST_AWK+=	/^${PKGLOCALEDIR:S,/,\/,g}\/locale/ { $$0 = "$${PLIST.nls}" $$0 }

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/COPYRIGHT ${DESTDIR}${PREFIX}/share/gkrellm2

.include "../../mk/bsd.pkg.mk"
