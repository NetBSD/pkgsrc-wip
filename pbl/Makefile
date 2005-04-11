# $NetBSD: Makefile,v 1.3 2005/04/11 21:14:43 tvierling Exp $
#

DISTNAME=	pbl_1_03
PKGNAME=	pbl-1.03
CATEGORIES=	databases devel
MASTER_SITES=	http://mission.base.com/peter/source/

MAINTAINER=	oherrala@ee.oulu.fi
HOMEPAGE=	http://mission.base.com/peter/source/
COMMENT=	The Program Base Library

PKG_INSTALLATION_TYPES= overwrite pkgviews

NO_CONFIGURE=	#defined

USE_GNU_TOOLS+=make
MAKEFILE=makefile

INSTALLATION_DIRS= lib include

do-install:
	${INSTALL_DATA} ${WRKSRC}/libpbl.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/pbl.h ${PREFIX}/include/

.include "../../mk/bsd.pkg.mk"
