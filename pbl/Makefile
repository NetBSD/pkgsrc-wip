# $NetBSD: Makefile,v 1.1.1.1 2004/01/26 14:49:35 oherrala Exp $
#

DISTNAME=	pbl_1_02
PKGNAME=	pbl-1.02
CATEGORIES=	databases devel
MASTER_SITES=	http://mission.base.com/peter/source/

MAINTAINER=	oherrala@ee.oulu.fi
HOMEPAGE=	http://mission.base.com/peter/source/
COMMENT=	The Program Base Library

PKG_INSTALLATION_TYPES= overwrite pkgviews

NO_BUILDLINK=	#defined
NO_CONFIGURE=	#defined

USE_GNU_TOOLS+=make
MAKEFILE=makefile

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libpbl.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/pbl.h ${PREFIX}/include/

.include "../../mk/bsd.pkg.mk"
