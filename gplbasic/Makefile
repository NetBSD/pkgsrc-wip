# $NetBSD: Makefile,v 1.3 2012/09/29 00:31:00 asau Exp $
#

DISTNAME=		gplbasic
PKGNAME=		gplbasic-0
CATEGORIES=		lang
MASTER_SITES=		http://www.xs4all.nl/~lennartb/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.xs4all.nl/~lennartb/basic.html
COMMENT=		Basic interpreter for Unix

BUILD_TARGET=	gplbasic
#USE_TOOLS+=	gmake
#WRKSRC=	${WRKDIR}/bastard_src-0.17

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gplbasic ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/gplbasic
	cd ${WRKSRC} && ${INSTALL_DATA} Design.txt Requirements.txt README \
		TODO BUGS ${DESTDIR}${PREFIX}/share/doc/gplbasic/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/gplbasic
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/gplbasic/bench
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/gplbasic/test
	${RM} -rf ${WRKSRC}/bench/CVS ${WRKSRC}/test/CVS
	${INSTALL_DATA} ${WRKSRC}/bench/* ${DESTDIR}${PREFIX}/share/gplbasic/bench/
	${INSTALL_DATA} ${WRKSRC}/test/* ${DESTDIR}${PREFIX}/share/gplbasic/test/

.include "../../mk/bsd.pkg.mk"
