# $NetBSD: Makefile,v 1.2 2004/11/11 17:46:50 oherrala Exp $
#

DISTNAME=	pbl_1_03
PKGNAME=	pbl-1.03
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

INSTALLATION_DIRS= lib include

do-install:
	${INSTALL_DATA} ${WRKSRC}/libpbl.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/pbl.h ${PREFIX}/include/

.include "../../mk/bsd.pkg.mk"
