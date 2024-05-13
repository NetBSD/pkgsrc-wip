# $NetBSD$

.include "version.mk"

DISTNAME=	fontawesome-free-${FA_VERSION}-web
PKGNAME=	awesome6-ttf-${FA_VERSION}
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

FONTS_DIRS.ttf=	share/fonts/X11/TTF

INSTALLATION_DIRS=	${FONTS_DIRS.ttf}

do-install:
.for f in regular-400 solid-900 brands-400 v4compatibility
	${INSTALL_DATA} ${WRKSRC}/webfonts/fa-${f}.ttf			\
		${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}/fa6-${f}.ttf
.endfor

.include "../../mk/bsd.pkg.mk"
