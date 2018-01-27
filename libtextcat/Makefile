# $NetBSD: Makefile,v 1.7 2012/10/03 09:10:41 asau Exp $
#

DISTNAME=	libtextcat-2.2
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://software.wise-guys.nl/download/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://software.wise-guys.nl/libtextcat/
COMMENT=	Libtextcat library the Cavnar & Trenkle

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

INCLUDEDIR=	${PREFIX}/include/libtextcat
SHAREDIR=	${PREFIX}/share/libtextcat

HEADERS=	textcat.h common.h constants.h fingerprint.h utf8misc.h

post-install:
	${INSTALL_DATA_DIR}  ${DESTDIR}${INCLUDEDIR}
.for header in ${HEADERS}
	${INSTALL_DATA} ${WRKSRC}/src/${header} ${DESTDIR}${INCLUDEDIR}
.endfor
	${INSTALL_DATA_DIR} ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/libtextcat

.include "../../mk/bsd.pkg.mk"
