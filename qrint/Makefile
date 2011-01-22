# $NetBSD: Makefile,v 1.1.1.1 2011/01/22 13:30:49 jihbed Exp $
#

DISTNAME=	qrint
PKGNAME=	${DISTNAME}-${VERSION}
CATEGORIES=	math
MASTER_SITES=	http://people.math.gatech.edu/~dieci/qrint/
EXTRACT_SUFX=	.zip

MAINTAINER=	jihbed.resarch@gmail.com
HOMEPAGE=	http://people.math.gatech.edu/~dieci/software-qrint.html
COMMENT=	TODO: Short description of the package
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
