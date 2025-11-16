# $NetBSD$

DISTNAME=  	nraku-2025
CATEGORIES=	lang	
MASTER_SITES=	https://sourceforge.net/projects/nraku/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/nraku/
COMMENT=	Raku(do) compiler system and sources (formerly perl6)	
LICENSE=	Artistic License 2.0	

WRKSRC=		${WRKDIR}/nraku-2025
USE_LANGUAGES= 	C, NQP	

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nraku-2025 ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
