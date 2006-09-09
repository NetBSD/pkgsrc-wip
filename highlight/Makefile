# $NetBSD: Makefile,v 1.8 2006/09/09 02:49:32 obache Exp $
#

DISTNAME=		highlight-2.4.7
CATEGORIES=		textproc
MASTER_SITES=		http://www.andre-simon.de/zip/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://www.andre-simon.de/
COMMENT=		Converts source code to formatted text with syntax highlighting

USE_TOOLS+=		gmake
USE_LANGUAGES=		c++
MANCOMPRESSED=		yes

MAKE_FILE=		makefile

PKG_SYSCONFSUBDIR=	highlight

EGDIR=			${PREFIX}/share/examples/highlight
CONF_FILES=		${EGDIR}/extensions.conf		\
			${PKG_SYSCONFDIR}/extensions.conf	\
			${EGDIR}/scriptre.conf			\
			${PKG_SYSCONFDIR}/scriptre.conf

SUBST_CLASSES+=		etc
SUBST_MESSAGE.etc=	Fixing hardcoded paths.
SUBST_STAGE.etc=	post-patch
SUBST_FILES.etc=	highlight/datadir.cpp
SUBST_SED.etc=		-e 's,/etc/highlight,${PKG_SYSCONFDIR},g'

.include "../../devel/libgetopt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
