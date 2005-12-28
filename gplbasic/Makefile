# $NetBSD: Makefile,v 1.1.1.1 2005/12/28 00:46:04 bencollver Exp $
#

DISTNAME=		gplbasic
PKGNAME=		gplbasic-0
CATEGORIES=		lang
MASTER_SITES=		http://www.xs4all.nl/~lennartb/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.xs4all.nl/~lennartb/basic.html
COMMENT=		Basic interpreter for Unix

BUILD_TARGET=		gplbasic
#USE_TOOLS+=		gmake
#WRKSRC=			${WRKDIR}/bastard_src-0.17

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gplbasic ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gplbasic
	cd ${WRKSRC} && ${INSTALL_DATA} Design.txt Requirements.txt README \
		TODO BUGS ${PREFIX}/share/doc/gplbasic/
	${INSTALL_DATA_DIR} ${PREFIX}/share/gplbasic
	${INSTALL_DATA_DIR} ${PREFIX}/share/gplbasic/bench
	${INSTALL_DATA_DIR} ${PREFIX}/share/gplbasic/test
	${RM} -rf ${WRKSRC}/bench/CVS ${WRKSRC}/test/CVS
	${INSTALL_DATA} ${WRKSRC}/bench/* ${PREFIX}/share/gplbasic/bench/
	${INSTALL_DATA} ${WRKSRC}/test/* ${PREFIX}/share/gplbasic/test/
.include "../../mk/bsd.pkg.mk"
