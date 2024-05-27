# $NetBSD$

DISTNAME=  	FreeBASIC-1.10.1-source
CATEGORIES=	devel	
MASTER_SITES=	https://sourceforge.net/projects/freebasic2/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/freebasic2/
COMMENT=	A free BASIC compiler
LICENSE=	GPL	

WRKSRC=		${WRKDIR}/freebasic2
USE_LANGUAGES= 	C

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freebasic2 ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
