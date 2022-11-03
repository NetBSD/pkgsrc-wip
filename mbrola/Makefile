# $NetBSD$

DISTNAME=	3.3
PKGNAME=	mbrola-${DISTNAME}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=numediart/}
GITHUB_PROJECT=	MBROLA
GITHUB_TAG=	refs/tags/3.3
DIST_SUBDIR=	${GITHUB_PROJECT}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/numediart/MBROLA/
COMMENT=	Speech synthesizer
LICENSE=	gnu-agpl-v3

WRKSRC=	${WRKDIR}/MBROLA-3.3

USE_TOOLS+=	gmake
BUILD_TARGET=

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
CFLAGS+=	-DTARGET_OS_NETBSD
.endif

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Bin/mbrola ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
