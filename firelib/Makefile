# $NetBSD: Makefile,v 1.1.1.1 2004/11/26 21:39:22 daprice Exp $
#

DISTNAME=		firelib-1.0.1
CATEGORIES=		wip
MASTER_SITES=		http://fire.org/firelib//

MAINTAINER=		mchittur@cs.nmsu.edu
HOMEPAGE=		http://fire.org/firelib//
COMMENT=		Library for predicting fire spread rate, intensity, and more

WRKSRC=			${WRKDIR}

MAKEFILE=		makefile

do-build:
	cd  ${WRKSRC} && ${MAKE} -f ${MAKEFILE}
	cd  ${WRKSRC} && ${AR} cru libfire.a fireLib.o
	cd  ${WRKSRC} && ${RANLIB} libfire.a

do-install:
	${INSTALL_LIB} ${WRKSRC}/libfire.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/fireLib.h ${PREFIX}/include
	${INSTALL_PROGRAM} ${WRKSRC}/fireSim ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/firelib/
	${INSTALL_DATA} ${WRKSRC}/firelib.ps ${PREFIX}/share/doc/firelib/firelib.ps
	${INSTALL_DATA} ${WRKSRC}/license.txt ${PREFIX}/share/doc/firelib/license.txt

.include "../../mk/bsd.pkg.mk"
