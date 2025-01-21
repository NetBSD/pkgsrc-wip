# $NetBSD$

DISTNAME=  	LMtester-0.6.12
CATEGORIES=	audio	
MASTER_SITES=	https://sourceforge.net/projects/lmtester/files/

MAINTAINER=	indur9@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/lmtester/
COMMENT= 	sound file modification system (AIF/AIFF based using AI)	
LICENSE=	Silverhawk

WRKSRC=		${WRKDIR}/LMtester-0.6.12/
USE_LANGUAGES=  C++	

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xdg ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
