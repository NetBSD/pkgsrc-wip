# $NetBSD$

DISTNAME=  	zephyr-lsmalltalk-0.1.9
CATEGORIES=	devel	
MASTER_SITES=	https://sourceforge.net/projects/zephyr-lsmalltalk/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/zephyr-lsmalltalk/
COMMENT=	A Silverhawk Software smalltalk implementation (LISP code)	
LICENSE=	GPLv2	

WRKSRC=		${WRKDIR}/zephyr-lsmalltalk
USE_LANGUAGES= 	C	

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zephyr-lsmalltalk ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
.include "../../mk/clisp.pkg.mk"
