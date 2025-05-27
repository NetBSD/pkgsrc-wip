# $NetBSD$

DISTNAME=  	pico-web-database-0.4.12
CATEGORIES=	devel
MASTER_SITES=	https://sourceforge.net/projects/pico-web-database/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/pico-web-database/
COMMENT=	Web technology and functionality 
LICENSE=	GPL	

WRKSRC=		${WRKDIR}/pico-web-database
USE_LANGUAGES= 	Pico 

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tpico2-experimental ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
