# $NetBSD$

VOX=	en1
VER=	980910
PKGNAME=	mbrolavox-${VOX}-${VER}
GITHUB_PROJECT=	MBROLA-voices
GITHUB_TAG=	refs/heads/master
DISTNAME=	master
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=numediart/}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

WRKSRC=	${WRKDIR}/MBROLA-voices-master/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/numediart/MBROLA-voices
COMMENT=	British English male voice for MBROLA
LICENSE=	no-commercial-use

DEPENDS=	mbrola-[0-9]*:../../audio/mbrola

USE_TOOLS+=	pax

NO_BUILD=	yes

MHOME=	${PREFIX}/share/mbrola/voices

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${MHOME}
	cd ${WRKSRC}/data && pax -rw ${VOX} ${DESTDIR}${MHOME}

.include "../../mk/bsd.pkg.mk"
