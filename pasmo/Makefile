# $NetBSD: Makefile,v 1.3 2005/04/27 20:25:31 ivaniclixx Exp $
#

DISTNAME=		pasmo-0.5.2
CATEGORIES=		wip
MASTER_SITES=		http://www.arrakis.es/~ninsesabe/pasmo/
EXTRACT_SUFX=		.tgz

MAINTAINER=		ivaniclixx@gmail.com
HOMEPAGE=		http://www.arrakis.es/~ninsesabe/pasmo/
COMMENT=		Z80 cross assembler written in C++

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pasmo ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pasmo/
	${INSTALL} ${WRKSRC}/README ${PREFIX}/share/doc/pasmo/
	${INSTALL} ${WRKSRC}/pasmodoc.html ${PREFIX}/share/doc/pasmo/
	${INSTALL} ${WRKSRC}/NEWS ${PREFIX}/share/doc/pasmo/

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
