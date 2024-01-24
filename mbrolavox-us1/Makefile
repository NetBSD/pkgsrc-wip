# $NetBSD$

VOX=		us1
COMMITS=	16
PKGNAME=	mbrolavox-${VOX}-0.0.0.${COMMITS}
DISTNAME=	MBROLA-voices-0.0.0.${COMMITS}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=numediart/}
GITHUB_PROJECT=	MBROLA-voices
GITHUB_TAG=	fe05a0ccef6a941207fd6aaad0b31294a1f93a51

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/numediart/MBROLA-voices
COMMENT=	British English male voice for MBROLA
# the particular license of this voice is included in ${DESTDIR}${MHOME}${VOX}
LICENSE=	no-commercial-use

DEPENDS=	mbrola-[0-9]*:../../audio/mbrola

USE_TOOLS+=	pax

NO_BUILD=	yes

MHOME=	${PREFIX}/share/mbrola/voices

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${MHOME}
	cd ${WRKSRC}/data && pax -rw ${VOX} ${DESTDIR}${MHOME}

.include "../../mk/bsd.pkg.mk"
