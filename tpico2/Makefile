# $NetBSD$

DISTNAME=  	tpico-2.0pl9
CATEGORIES=	devel	
MASTER_SITES=	https://sourceforge.net/projects/tpico2/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/tpico2/
COMMENT=	The Pico language interpreter, http://pico.vub.ac.be	
LICENSE=	BSD	

WRKSRC=		${WRKDIR}/tpico2
USE_LANGUAGES= 	C

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tpico2 ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
