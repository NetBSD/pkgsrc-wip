# $NetBSD$

PKGNAME=	hackgen-ttf-2.2.1
DISTNAME=	HackGen_v${PKGVERSION_NOREV}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=yuru7/}
GITHUB_PROJECT=	HackGen
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	iku.iwasa@gmail.ccom
HOMEPAGE=	https://github.com/yuru7/HackGen
COMMENT=	Japanese programming font, composed of Hack and GenJyuu-Gothic
LICENSE=	ofl-v1.1

EXTRACT_DIR=	${WRKDIR}
EXTRACT_SUFX=	.zip

NO_BUILD=	yes
USE_LANGUAGES=	# none

FONTSDIR=	share/fonts/X11/TTF

INSTALLATION_DIRS=	${FONTSDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}/${PREFIX}/${FONTSDIR}

.include "../../mk/bsd.pkg.mk"
