# $NetBSD$

.include "version.mk"

DISTNAME=	fontawesome-free-${FA_VERSION}-desktop
PKGNAME=	awesome6-otf-${FA_VERSION}
CATEGORIES=	fonts
MASTER_SITES=	https://use.fontawesome.com/releases/v${FA_VERSION}/
EXTRACT_SUFX=	.zip

MAINTAINER=	mdehling@gmail.com
HOMEPAGE=	https://fontawesome.com/
COMMENT=	The iconic font and CSS toolkit
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none
NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTS_DIRS.otf=	share/fonts/X11/OTF

INSTALLATION_DIRS=	${FONTS_DIRS.otf}

do-install:
	${INSTALL_DATA} ${WRKSRC}/otfs/*.otf				\
		${DESTDIR}${PREFIX}/${FONTS_DIRS.otf}

.include "../../mk/bsd.pkg.mk"
