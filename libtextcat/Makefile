# $NetBSD: Makefile,v 1.5 2010/07/09 20:53:18 jihbed Exp $
#

DISTNAME=	libtextcat-2.2
CATEGORIES=	textproc
MASTER_SITES=	http://software.wise-guys.nl/download/

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://software.wise-guys.nl/libtextcat/
COMMENT=	Libtextcat library the Cavnar & Trenkle

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

INCLUDEDIR=	${PREFIX}/include/libtextcat
SHAREDIR=	${PREFIX}/share/libtextcat

post-install:
	${INSTALL_DATA_DIR}  ${DESTDIR}${INCLUDEDIR}
	${INSTALL_DATA} ${WRKSRC}/src/textcat.h ${DESTDIR}${INCLUDEDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/libtextcat

.include "../../mk/bsd.pkg.mk"
