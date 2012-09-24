# $NetBSD: Makefile,v 1.2 2012/09/24 16:56:38 asau Exp $
#

VERS=	 	20051229
DISTNAME=	arabeyes-qr.ttf
PKGNAME=	arabeyes-qr-ttf-${VERS}
CATEGORIES=	fonts
MASTER_SITES=	http://garr.dl.sourceforge.net/project/arabeyes/Quran/Fonts/
EXTRACT_SUFX=	.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://garr.dl.sourceforge.net/project/arabeyes/Quran/Fonts/
COMMENT=	Fonts to be used to display the Qur\'an text

WRKSRC=	${WRKDIR}
USE_LANGUAGES=	# none

NO_BUILD=	yes
FONTS_DIRS.ttf=		lib/X11/fonts/TTF

INSTALLATION_DIRS+=	${FONTS_DIRS.ttf}

do-install:
	${INSTALL_DATA} ${WRKSRC}/arabeyes-qr.ttf	 \
		 ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
