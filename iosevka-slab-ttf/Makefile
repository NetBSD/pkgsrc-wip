# $NetBSD$

DISTNAME=	SuperTTC-IosevkaSlab-${PKGVERSION_NOREV}
PKGNAME=	iosevka-slab-ttf-33.2.7
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=be5invis/}
GITHUB_PROJECT=	Iosevka
GITHUB_RELEASE=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	iquiw@NetBSD.org
HOMEPAGE=	https://github.com/be5invis/Iosevka
COMMENT=	Slender typeface for code, from code
LICENSE=	ofl-v1.1

EXTRACT_DIR=	${WRKSRC}

NO_BUILD=	yes
USE_LANGUAGES=	# none

FONTSDIR=	share/fonts/X11/TTF

INSTALLATION_DIRS=	${FONTSDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.ttc ${DESTDIR}/${PREFIX}/${FONTSDIR}

.include "../../mk/bsd.pkg.mk"
