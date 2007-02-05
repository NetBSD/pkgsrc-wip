# $NetBSD: Makefile,v 1.6 2007/02/05 00:37:11 ivaniclixx Exp $
#

DISTNAME=		pasmo-0.5.3
CATEGORIES=		devel
MASTER_SITES=		http://pasmo.euler.es/bin/
EXTRACT_SUFX=		.tgz

MAINTAINER=		ivaniclixx@gmail.com
HOMEPAGE=		http://www.arrakis.es/~ninsesabe/pasmo/
COMMENT=		Z80 cross assembler written in C++

USE_LANGUAGES=		c c++
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pasmo ${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pasmo/
	${INSTALL} ${WRKSRC}/README ${PREFIX}/share/doc/pasmo/
	${INSTALL} ${WRKSRC}/pasmodoc.html ${PREFIX}/share/doc/pasmo/
	${INSTALL} ${WRKSRC}/NEWS ${PREFIX}/share/doc/pasmo/

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
