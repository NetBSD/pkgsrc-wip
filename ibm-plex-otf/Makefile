# $NetBSD$

PKGNAME=	ibm-plex-otf-2.0.0
GITHUB_PROJECT=	plex
DISTNAME=	OpenType
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=IBM/}
GITHUB_RELEASE=	v2.0.0
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://github.com/IBM/plex/
COMMENT=	IBM plex typeface (OpenType)
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none
NO_BUILD=	yes

FONTSDIR=		${PREFIX}/share/fonts/X11/OTF
FONTS_DIRS.ttf=		${FONTSDIR}
INSTALLATION_DIRS=	share/fonts/X11/OTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/*/*.otf  ${DESTDIR}${FONTSDIR}


.include "../../mk/bsd.pkg.mk"
