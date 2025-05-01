# $NetBSD$

DISTNAME=  	MacEiffel-0.1.1
CATEGORIES=	lang	
MASTER_SITES=	https://sourceforge.net/projects/maceiffel/files/

MAINTAINER=	goon.mage@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/maceiffel/
COMMENT=	A small Eiffel compiler system	
LICENSE=	(Nethack) General Public License	

WRKSRC=		${WRKDIR}/MacEiffel
USE_LANGUAGES=  C	

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/MacEiffel ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
