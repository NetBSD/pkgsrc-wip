# $NetBSD: Makefile,v 1.1.1.1 2005/11/05 23:28:40 dhowland Exp $
#

DISTNAME=		highlight-2.4.3
CATEGORIES=		textproc
MASTER_SITES=		http://www.andre-simon.de/zip/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://www.andre-simon.de/
COMMENT=		Converts source code to formatted text with syntax highlighting

MAKEFILE=		makefile
MAKE_ARGS+=		all-localgetopt
USE_PKGINSTALL=		yes
USE_TOOLS+=		gmake

OWN_DIRS=		${PKG_SYSCONFDIR}/highlight
CONF_FILES=		${PREFIX}/share/highlight/etc/extensions.conf \
			${PKG_SYSCONFDIR}/highlight/extensions.conf
CONF_FILES+=		${PREFIX}/share/highlight/etc/scriptre.conf \
			${PKG_SYSCONFDIR}/highlight/scriptre.conf

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	post-patch
SUBST_FILES.etc=	highlight/datadir.cpp
SUBST_SED.etc=		-e 's,/etc/highlight/,${PREFIX}/etc/highlight/,g'
SUBST_MESSAGE.etc=	"Fixing hardcoded paths."

post-build:
	cd ${WRKSRC}/man && ${TOOLS_PLATFORM.gunzip} highlight.1.gz

.include "../../mk/bsd.pkg.mk"
