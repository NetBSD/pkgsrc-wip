# $NetBSD: Makefile,v 1.2 2012/10/07 16:23:21 asau Exp $
#

DISTNAME=	sympow_1.019.orig
PKGNAME=	sympow-1.019
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/s/sympow/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.maths.bris.ac.uk/~mamjw/
COMMENT=	Special values of symmetric power elliptic curve L-functions
#LICENSE=	# TODO: (see mk/license.mk)

WRKSRC=		${WRKDIR}/sympow-1.019
USE_TOOLS+=	pax
USE_LANGUAGES=	c c++

SYMPOW_DIRECTORY=	${PREFIX}/lib/sympow
DOCDIR=	${PREFIX}/share/doc/sympow

INSTALLATION_DIRS=	bin ${DOCDIR} ${SYMPOW_DIRECTORY}

pre-configure:
	cd ${WRKSRC} && ${SH} Configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sympow ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.gp ${DESTDIR}${SYMPOW_DIRECTORY}
	${INSTALL_DATA} ${WRKSRC}/new_data ${DESTDIR}${SYMPOW_DIRECTORY}
	cd ${WRKSRC} && pax -rw -pp datafiles ${DESTDIR}${SYMPOW_DIRECTORY}
	${INSTALL_DATA} ${WRKSRC}/COPYING  ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README  ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
