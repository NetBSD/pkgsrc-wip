# $NetBSD$

DISTNAME=  	ROMBlast-0.1.9
CATEGORIES=	emulators	
MASTER_SITES=	https://sourceforge.net/projects/romblast/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/romblast/
COMMENT=	A ROM utility 
LICENSE=	GPLv2	

WRKSRC=		${WRKDIR}/ROMBlast
USE_LANGUAGES= 	awk	

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/romblast.awk ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
