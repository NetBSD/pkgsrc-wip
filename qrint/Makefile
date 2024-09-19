# $NetBSD: Makefile,v 1.3 2012/10/07 14:53:42 asau Exp $
#

DISTNAME=	qrint
PKGNAME=	${DISTNAME}-${VERSION}
CATEGORIES=	math
MASTER_SITES=	http://people.math.gatech.edu/~dieci/qrint/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	https://people.math.gatech.edu/~dieci/software-qrint.html
COMMENT=	Orthonormal integrators
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}

VERSION=	1.0
USE_LANGUAGES=	fortran

INSTALLATION_DIRS=	bin share/doc/qrint

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qrdrv.e ${DESTDIR}${PREFIX}/bin/qrint
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/qrint


.include "../../mk/bsd.pkg.mk"
