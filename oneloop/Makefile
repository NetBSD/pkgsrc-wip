# $NetBSD: Makefile,v 1.2 2012/10/03 21:32:46 asau Exp $
#

DISTNAME=	OneLOop-1.1
PKGNAME=	oneloop-1.1
CATEGORIES=	physics
MASTER_SITES=	http://helac-phegas.web.cern.ch/helac-phegas/tar-files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://helac-phegas.web.cern.ch/helac-phegas/OneLOop.html
COMMENT=	Evaluate the one-loop scalar 1-point, 2-point, 3-point

MAKE_FILE= makefile
USE_LANGUAGES=	fortran

INSTALLATION_DIRS=	lib

do-install:
	${INSTALL_LIB} ${WRKSRC}/libavh_olo.a ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
