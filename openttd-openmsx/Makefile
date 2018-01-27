# $NetBSD: Makefile,v 1.6 2012/10/03 21:32:47 asau Exp $
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

INSTALLATION_DIRS=	share/openttd/gm

WRKSRC=		${WRKDIR}/openmsx-${VERSION}
USE_LANGUAGES=	# none

NO_BUILD=	YES
NO_CONFIGURE=	YES

OPENTTD_GMDIR=	${DESTDIR}${PREFIX}/share/openttd/gm

do-install:
		${INSTALL_DATA} ${WRKSRC}/*.mid \
			${OPENTTD_GMDIR}
		${INSTALL_DATA} ${WRKSRC}/*.obm \
			${OPENTTD_GMDIR}


.include "../../mk/bsd.pkg.mk"
