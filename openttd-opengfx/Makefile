# $NetBSD: Makefile,v 1.1.1.1 2010/08/29 09:28:34 ggergely Exp $
#


VERSION=	0.2.4
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

NO_BUILD=		YES
NO_CONFIGURE=		YES

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME:S/-all$//}.tar \
	   	${DESTDIR}${PREFIX}/share/openttd/data

.include "../../mk/bsd.pkg.mk"
