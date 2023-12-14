# $NetBSD$

DISTNAME=  	ruby-fast-colonization-0.3.22	
CATEGORIES=	games	
MASTER_SITES=	https://sourceforge.net/projects/ruby-fast-colonization/files/

MAINTAINER=	zara.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/ruby-fast-colonization/
COMMENT=	A Colonization game	
LICENSE=	GPLv2	

WRKSRC=		${WRKDIR}/ruby-fast-colonization
USE_LANGUAGES= 	ruby	

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fastcol ${DESTDIR}${PREFIX}/bin

.include "../../devel/ruby-SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
