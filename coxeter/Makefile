# $NetBSD: Makefile,v 1.3 2012/09/24 18:26:55 asau Exp $
#

DISTNAME=	coxeter_3.0_beta3
PKGNAME=	coxeter-3.0
CATEGORIES=	math
MASTER_SITES=	http://math.univ-lyon1.fr/~ducloux/coxeter/coxeter3/french/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://math.univ-lyon1.fr/~ducloux/coxeter/coxeter3/english/coxeter3_e.html
COMMENT=	Computer program for the study of Coxeter group theory

MAKE_FILE=	makefile
USE_TOOLS+=	gmake
USE_LANGUAGES=	c++

GCC_REQD+=		3.3.5
ONLY_FOR_PLATFORM=	NetBSD-*-* Linux-*-* SunOS-*-*

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/coxeter ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
