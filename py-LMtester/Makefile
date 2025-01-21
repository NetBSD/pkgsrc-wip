# $NetBSD$

DISTNAME=  	py-LMtester-0.6.2
CATEGORIES= 	audio	
MASTER_SITES=	https://sourceforge.net/projects/py-lmtester/files/

MAINTAINER=	indur9@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/py-lmtester/
COMMENT= 	Python bindings to LMtester
LICENSE=	modified BSD	

WRKSRC=		${WRKDIR}/py-LMtester-0.6.2/
USE_LANGUAGES=  Python 

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/py-LMtester ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
