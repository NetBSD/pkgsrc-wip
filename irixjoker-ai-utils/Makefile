# $NetBSD$

DISTNAME=  	irixjoker-ai-utils-0.1.12
CATEGORIES=	devel
MASTER_SITES=	https://sourceforge.net/projects/irixjoker-ai-utils/files/

MAINTAINER=	indur9@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/irixjoker-ai-utils/
COMMENT= 	General purpose AI library (also includes machine learning and adaptive systems theory).	
LICENSE=	Nekoware

WRKSRC=		${WRKDIR}/irixjoker-ai-utils-0.1.12/
USE_LANGUAGES=  C++	

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/irxjoker-ai-utils ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
