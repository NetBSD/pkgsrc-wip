# $NetBSD: Makefile,v 1.2 2010/09/25 16:54:38 ggergely Exp $
#


VERSION=	0.3.1
DISTNAME=	opengfx-${VERSION}-all
PKGNAME=	openttd-${DISTNAME:S/-all$//}
CATEGORIES=	games
MASTER_SITES=	http://binaries.openttd.org/extra/opengfx/${VERSION}/
EXTRACT_SUFX=	.zip

MAINTAINER=	elentirmo.gilgalad@gmail.com
HOMEPAGE=	http://openttd.org/
COMMENT=	Free and open source graphics data files for the game OpenTTD
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=  	share/openttd/data

WRKSRC=		${WRKDIR}/opengfx-${VERSION}
USE_LANGUAGES=	# none

NO_BUILD=     	YES
NO_CONFIGURE=	YES

OPENTTD_DATADIR= ${DESTDIR}${PREFIX}/share/openttd/data

do-install:
#	The single tar version has been dropped	for some reason
#	${INSTALL_DATA} ${WRKSRC}/${DISTNAME:S/-all$//}.tar \
#	   	${DESTDIR}${PREFIX}/share/openttd/data
	${INSTALL_DATA} ${WRKSRC}/*.grf \
		${OPENTTD_DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.obg \
		${OPENTTD_DATADIR}


.include "../../mk/bsd.pkg.mk"
