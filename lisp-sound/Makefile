# $NetBSD$

DISTNAME=  	lisp-sound-0.2.1
CATEGORIES=	audio	
MASTER_SITES=	https://sourceforge.net/projects/lisp-sound/files/

MAINTAINER=	indur9@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/lisp-sound/
COMMENT= 	sound file modification system (AIF/AIFF, WAV based using AI)	
LICENSE=	Silverhawk

WRKSRC=		${WRKDIR}/lisp-sound-0.2.1/
USE_LANGUAGES=  LISP	

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lisp-sound ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
