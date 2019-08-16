# $NetBSD$

VERSION=	2.0.0
PKGNAME=	ibm-plex-ttf-${VERSION}
GITHUB_PROJECT=	plex
DISTNAME=	TrueType
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=IBM/}
GITHUB_RELEASE=	v${VERSION}
EXTRACT_SUFX=	.zip
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	ng0@NetBSD.org
HOMEPAGE=	https://github.com/IBM/plex/
COMMENT=	IBM plex typeface (TrueType)
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none
NO_BUILD=	yes

FONTSDIR=		${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=		${FONTSDIR}
INSTALLATION_DIRS=	share/fonts/X11/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/*/*.ttf  ${DESTDIR}${FONTSDIR}


.include "../../mk/bsd.pkg.mk"
