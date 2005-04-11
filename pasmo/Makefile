# $NetBSD: Makefile,v 1.2 2005/04/11 21:14:43 tvierling Exp $
#

DISTNAME=		pasmo-0.5.1
CATEGORIES=		wip
MASTER_SITES=		http://www.arrakis.es/~ninsesabe/pasmo/
EXTRACT_SUFX=		.tgz

MAINTAINER=		ivaniclixx@gmail.com
HOMEPAGE=		http://www.arrakis.es/~ninsesabe/pasmo/
COMMENT=		Z80 cross assembler written in C++

WRKSRC=		${WRKDIR}/pasmo-0.5.1

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pasmo ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pasmo/
	${INSTALL} ${WRKSRC}/README ${PREFIX}/share/doc/pasmo/
	${INSTALL} ${WRKSRC}/pasmodoc.html ${PREFIX}/share/doc/pasmo/
	${INSTALL} ${WRKSRC}/NEWS ${PREFIX}/share/doc/pasmo/

.include "../../mk/bsd.pkg.mk"
