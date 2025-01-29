# $NetBSD$

DISTNAME=  	ruby-fast-colonization-0.3.22	
CATEGORIES=	games	
MASTER_SITES=	https://sourceforge.net/projects/ruby-fast-colonization/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/ruby-fast-colonization/
COMMENT=	A Free Colonization game	
LICENSE=	GPLv2, Ruby	

WRKSRC=		${WRKDIR}/ruby-fast-colonization
USE_LANGUAGES= 	ruby	

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fastcol ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
