# $NetBSD$

DISTNAME=  	zephyr-smalltalk-0.1.19
CATEGORIES=	devel	
MASTER_SITES=	https://sourceforge.net/projects/zephyr-smalltalk/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/zephyr-smalltalk/
COMMENT=	A Silverhawk Software smalltalk implementation	
LICENSE=	APSL2	

WRKSRC=		${WRKDIR}/zephyr-smalltalk
USE_LANGUAGES= 	C	

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zephyr-smalltalk ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
