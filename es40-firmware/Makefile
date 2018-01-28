# $NetBSD: Makefile,v 1.3 2012/09/28 22:07:34 asau Exp $
#

DISTNAME=	es40
PKGNAME=	${DISTNAME}-firmware-7.3
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.hp.com/pub/alphaserver/firmware/current_platforms/v7.3_release/ES40_series/ES40/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://h18002.www1.hp.com/alphaserver/es40/
COMMENT=	AlphaServer ES40 firmware image
#LICENSE=	unknown

RESTRICTED=		No redistribution allowed
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

NO_BUILD=		yes
INSTALLATION_DIRS=	share/es40-firmware

do-install:
	${INSTALL_DATA} ${WRKDIR}/cl67srmrom.exe \
	  ${DESTDIR}${PREFIX}/share/es40-firmware

.include "../../mk/bsd.pkg.mk"
