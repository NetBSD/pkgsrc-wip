# $NetBSD$

DISTNAME=  	gcc-core-4.2.0	
CATEGORIES=	devel	
MASTER_SITES=	https://sourceforge.net/projects/cross-m68k-coff-gcc-4.2.0/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/cross-m68k-coff-gcc-4.2.0/
COMMENT=	C cross compiler for MC68000 (coff)	
LICENSE=	General Public License	

WRKSRC=		${WRKDIR}/cross-m68k-coff-gcc-4.2.0/
USE_LANGUAGES=  C	

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/m68k-coff-gcc ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
