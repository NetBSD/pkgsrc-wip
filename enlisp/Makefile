# $NetBSD$

DISTNAME=  	enlisp-21.4.5
CATEGORIES=	lang	
MASTER_SITES=	https://sourceforge.net/projects/enlisp/files/

MAINTAINER=	indur9@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/enlisp/
COMMENT= 	An elisp interpreter based on Emacs 21.4+
LICENSE=	GPL, Silverhawk

WRKSRC=		${WRKDIR}/enlisp-21.4.5/
USE_LANGUAGES=  C

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/enlisp ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
