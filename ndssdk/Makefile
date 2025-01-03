# $NetBSD$

DISTNAME=	ndssdk-1.8.0.1
CATEGORIES=	devel
MASTER_SITES=	https://sourceforge.net/projects/ndssdk/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/ndssdk/
COMMENT=	Nintendo DS C Compiler, tools and libraries
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}/ndssdk-1.8.0.1
USE_LANGUAGES=	c

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ndssdk ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
