# $NetBSD: Makefile,v 1.10 2006/09/14 19:13:30 dhowland Exp $

DISTNAME=		xxdiff-3.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xxdiff/}

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://furius.ca/xxdiff/
COMMENT=		Graphical file comparator and merge tool

BUILD_DEPENDS+=		tmake>=1.7:../../devel/tmake

USE_LANGUAGES=		c c++
USE_TOOLS+=		bison flex gmake

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
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xxdiff
	${INSTALL_DATA} ${WRKSRC}/src/doc.html ${PREFIX}/share/doc/xxdiff/

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
