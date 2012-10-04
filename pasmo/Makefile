# $NetBSD: Makefile,v 1.7 2012/10/04 19:34:55 asau Exp $
#

DISTNAME=		pasmo-0.5.3
CATEGORIES=		devel
MASTER_SITES=		http://pasmo.euler.es/bin/
EXTRACT_SUFX=		.tgz

MAINTAINER=		ivaniclixx@gmail.com
HOMEPAGE=		http://www.arrakis.es/~ninsesabe/pasmo/
COMMENT=		Z80 cross assembler written in C++

USE_LANGUAGES=		c c++

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pasmo ${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/pasmo/
	${INSTALL} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/pasmo/
	${INSTALL} ${WRKSRC}/pasmodoc.html ${DESTDIR}${PREFIX}/share/doc/pasmo/
	${INSTALL} ${WRKSRC}/NEWS ${DESTDIR}${PREFIX}/share/doc/pasmo/

USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
