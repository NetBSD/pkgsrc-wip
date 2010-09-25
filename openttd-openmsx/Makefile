# $NetBSD: Makefile,v 1.3 2010/09/25 17:02:08 ggergely Exp $
#
PKGREVISION=	1

VERSION=	0.3.1
DISTNAME=	openmsx-${VERSION}-all
PKGNAME=	openttd-${DISTNAME:S/-all$//}
CATEGORIES=	games
MASTER_SITES=	http://binaries.openttd.org/extra/openmsx/${VERSION}/
EXTRACT_SUFX=	.zip

MAINTAINER=	elentirmo.gilgalad@gmail.com
HOMEPAGE=	http://openttd.org/
COMMENT=	Free and open source music data files for the game OpenTTD
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=  	share/openttd/data

WRKSRC=		${WRKDIR}/openmsx-${VERSION}
USE_LANGUAGES=	# none

NO_BUILD=    	YES
NO_CONFIGURE=	YES

OPENTTD_DATADIR= ${DESTDIR}${PREFIX}/share/openttd/data

do-install:
		${INSTALL_DATA} ${WRKSRC}/*.mid \
			${OPENTTD_DATADIR}
		${INSTALL_DATA} ${WRKSRC}/*.obm \
			${OPENTTD_DATADIR}


.include "../../mk/bsd.pkg.mk"
