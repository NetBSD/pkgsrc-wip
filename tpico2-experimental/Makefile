# $NetBSD$

DISTNAME=  	tpico-2.0pl9.2.9
CATEGORIES=	lang	
MASTER_SITES=	https://sourceforge.net/projects/tpico2-experimental/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/tpico2-experimental/
COMMENT=	The Pico language interpreter with extensions such as SDL 1.2 and Curses libraries	
LICENSE=	BSD	

WRKSRC=		${WRKDIR}/tpico2-experimental
USE_LANGUAGES= 	C

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tpico2-experimental ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
