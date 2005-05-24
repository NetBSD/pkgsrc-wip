# $NetBSD: Makefile,v 1.4 2005/05/24 10:31:16 rillig Exp $
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

USE_TOOLS+=gmake
MAKEFILE=makefile

INSTALLATION_DIRS= lib include

do-install:
	${INSTALL_DATA} ${WRKSRC}/libpbl.a ${PREFIX}/lib/
	${INSTALL_DATA} ${WRKSRC}/pbl.h ${PREFIX}/include/

.include "../../mk/bsd.pkg.mk"
