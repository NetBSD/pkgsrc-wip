# $NetBSD: Makefile,v 1.2 2010/08/08 10:57:18 jihbed Exp $
#

DISTNAME=	coxeter_3.0_beta3
PKGNAME=	coxeter-3.0
CATEGORIES=	math
MASTER_SITES=	http://math.univ-lyon1.fr/~ducloux/coxeter/coxeter3/french/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://math.univ-lyon1.fr/~ducloux/coxeter/coxeter3/english/coxeter3_e.html
COMMENT=	Computer program for the study of Coxeter group theory

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_FILE=	makefile
USE_TOOLS+=	gmake
USE_LANGUAGES=	c++

GCC_REQD+=	3.3.5
ONLY_FOR_PLATFORM= NetBSD-*-* Linux-*-* Solaris-*-*

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/coxeter ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
