# $NetBSD: Makefile,v 1.2 2005/11/15 09:26:58 ghen Exp $

DISTNAME=	xxdiff-3.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xxdiff/}

MAINTAINER=	geert.hendrickx@ua.ac.be
HOMEPAGE=	http://xxdiff.sourceforge.net/
COMMENT=	Graphical file comparator and merge tool

USE_TOOLS+=	gmake
USE_TOOLS+=	bison
USE_TOOLS+=	flex
BUILD_DEPENDS+=	tmake>=1.7:../../devel/tmake

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}/src

#BUILDLINK_TRANSFORM+=	S:-lqt:-lqt.mt:

SUBST_CLASSES+=		libs
SUBST_STAGE.libs=	post-configure
SUBST_FILES.libs=	Makefile
SUBST_SED.libs=		-e 's,-lqt,-lqt-mt,'

do-configure:
	cd ${WRKSRC} && \
	tmake -o Makefile xxdiff.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/xxdiff ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/xxdiff.1 ${PREFIX}/${PKGMANDIR}/man1/

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
BUILDLINK_DEPMETHOD.qt3-tools=	build
.include "../../mk/bsd.pkg.mk"
