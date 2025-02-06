# $NetBSD$

DISTNAME=  	lisp-scripts-0.1.4
CATEGORIES=	devel	
MASTER_SITES=	https://sourceforge.net/projects/lisp-scripts/files/

MAINTAINER=	indur9@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/lisp-scripts/
COMMENT= 	Useful (admin) scripts programmed in Common Lisp
LICENSE=	GPL2	

WRKSRC=		${WRKDIR}/lisp-scripts-0.1.4/
USE_LANGUAGES=  LISP	

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lisp-scripts ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
