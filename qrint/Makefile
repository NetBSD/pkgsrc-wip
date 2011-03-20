# $NetBSD: Makefile,v 1.2 2011/03/20 23:07:48 jihbed Exp $
#

DISTNAME=	qrint
PKGNAME=	${DISTNAME}-${VERSION}
CATEGORIES=	math
MASTER_SITES=	http://people.math.gatech.edu/~dieci/qrint/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://people.math.gatech.edu/~dieci/software-qrint.html
COMMENT=	Orthonormal integrators
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}

VERSION=	1.0
USE_LANGUAGES=	fortran

INSTALLATION_DIRS=	bin share/doc/qrint

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qrdrv.e ${DESTDIR}${PREFIX}/bin/qrint
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/qrint


.include "../../mk/bsd.pkg.mk"
