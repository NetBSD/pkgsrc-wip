# $NetBSD: Makefile,v 1.1.1.1 2010/05/11 10:08:47 jihbed Exp $
#

DISTNAME=	sympow_1.019.orig
PKGNAME=	sympow-1.019
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/s/sympow/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.maths.bris.ac.uk/~mamjw/
COMMENT=	Special values of symmetric power elliptic curve L-functions
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=	${WRKDIR}/sympow-1.019
USE_TOOLS+=	pax
USE_LANGUAGES= c c++

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
