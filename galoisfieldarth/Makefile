# $NetBSD: Makefile,v 1.2 2012/09/29 00:50:33 asau Exp $
#

DISTNAME=	GaloisFieldArithmetic-${VERSION}
CATEGORIES=	math
MASTER_SITES=	http://www.partow.net/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://www.partow.net/
COMMENT=	Galois Field Arithmetic Library
LICENSE=	cpl-1.0

VERSION=	2006
USE_LANGUAGES=	c++

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/GFPDerivTest ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/GaloisFieldOut ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/GaloisFieldTest ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/GaloisProto ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/GaloisShiftProto ${DESTDIR}${PREFIX}/bin


.include "../../mk/bsd.pkg.mk"
