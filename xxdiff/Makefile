# $NetBSD: Makefile,v 1.7 2006/01/05 10:11:26 ghen Exp $

DISTNAME=		xxdiff-3.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xxdiff/}

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://xxdiff.sourceforge.net/
COMMENT=		Graphical file comparator and merge tool

USE_TOOLS+=		gmake
USE_TOOLS+=		bison
USE_TOOLS+=		flex
BUILD_DEPENDS+=		tmake>=1.7:../../devel/tmake

BUILD_DIRS=		src

#BUILDLINK_TRANSFORM+=	S:-lqt:-lqt.mt:

SUBST_CLASSES+=		libs
SUBST_STAGE.libs=	post-configure
SUBST_FILES.libs=	src/Makefile
SUBST_SED.libs=		-e 's,-lqt,-lqt-mt,'

do-configure:
	cd ${WRKSRC}/src && \
	tmake -o Makefile xxdiff.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/xxdiff ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/src/xxdiff.1 ${PREFIX}/${PKGMANDIR}/man1/

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
