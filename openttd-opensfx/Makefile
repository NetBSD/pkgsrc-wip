# $NetBSD: Makefile,v 1.1.1.1 2010/08/29 09:32:09 ggergely Exp $
#

VERSION=	0.2.3
DISTNAME=	opensfx-${VERSION}-all
PKGNAME=	openttd-${DISTNAME:S/-all$//}
CATEGORIES=	games
MASTER_SITES=	http://binaries.openttd.org/extra/opensfx/${VERSION}/
EXTRACT_SUFX=	.zip

MAINTAINER=	elentirmo.gilgalad@gmail.com
HOMEPAGE=	http://openttd.org/
COMMENT=	Free and open source sound data files for the game OpenTTD
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=  	share/openttd/data

WRKSRC=		${WRKDIR}/opensfx-${VERSION}
USE_LANGUAGES=	# none

NO_BUILD=		YES
NO_CONFIGURE=		YES

do-install:
# the readme is already bumped to the single tar version
# probably this method will work soon
#	 	${INSTALL_DATA} ${WRKSRC}/${DISTNAME:S/-all$//}.tar \
#  		${DESTDIR}${PREFIX}/share/openttd/data
	${INSTALL_DATA} ${WRKSRC}/opensfx.cat \
	   	${DESTDIR}${PREFIX}/share/openttd/data
	${INSTALL_DATA} ${WRKSRC}/opensfx.obs \
	   	${DESTDIR}${PREFIX}/share/openttd/data

.include "../../mk/bsd.pkg.mk"
