# $NetBSD: Makefile,v 1.3 2009/05/19 22:57:36 jihbed Exp $
#

DISTNAME=	libtextcat-2.2
CATEGORIES=	textproc
MASTER_SITES=	http://software.wise-guys.nl/download/

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	http://software.wise-guys.nl/libtextcat/
COMMENT=	Libtextcat library the Cavnar & Trenkle

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

SHAREDIR=	${PREFIX}/share/libtextcat

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${SHAREDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/libtextcat

.include "../../mk/bsd.pkg.mk"
