# $NetBSD: Makefile,v 1.2 2005/12/05 22:27:44 rillig Exp $
#

DISTNAME=		cb2bib-0.5.0
CATEGORIES=		misc
MASTER_SITES=		http://www.molspaces.com/dl/progs/

MAINTAINER=		dhowland@users.sourceforge.net
HOMEPAGE=		http://www.molspaces.com/cb2bib/
COMMENT=		Extract and organize bibliographic references

QTPREFIX=		${PREFIX}/qt3
CONFIGURE_ENV+=		QTDIR=${QTPREFIX:Q}

USE_DIRS+=              xdg-1.2
USE_TOOLS+=		gmake

# needed to find qmake
PATH:=                  ${PATH}:${QTPREFIX}/bin

SUBST_CLASSES+=         path
SUBST_STAGE.path=       post-patch
SUBST_FILES.path=       src/src.pro
SUBST_SED.path=          -e 's,xxPREFIXxx,${PREFIX},g'
SUBST_MESSAGE.path=      "Fixing hardcoded paths."

do-configure:
	cd ${WRKSRC} && ${SET_ENV} ${CONFIGURE_ENV} ./configure \
	--prefix ${PREFIX} --bindir ${PREFIX}/bin --datadir ${PREFIX}/share

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt3-tools=  build
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
