# $NetBSD: Makefile,v 1.3 2012/11/14 00:16:12 othyro Exp $
#

DISTNAME=	OneLOop-1.1
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	math
MASTER_SITES=	http://helac-phegas.web.cern.ch/helac-phegas/tar-files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://helac-phegas.web.cern.ch/helac-phegas/OneLOop.html
COMMENT=	Evaluate the one-loop scalar 1-point, 2-point, 3-point

MAKE_FILE=	makefile
USE_LANGUAGES=	fortran

INSTALLATION_DIRS=	lib

do-install:
	${INSTALL_LIB} ${WRKSRC}/libavh_olo.a ${DESTDIR}${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
