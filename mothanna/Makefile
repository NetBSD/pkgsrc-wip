# $NetBSD: Makefile,v 1.1.1.1 2009/08/27 17:47:37 jihbed Exp $
#

DISTNAME=	Mothanna-0.02
PKGNAME=	mothanna-0.02
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arabeyes/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://www.arabeyes.org/project.php?proj=Khotot
COMMENT=	Mothanna is a sans-serif like Arabic OpenType font
#LICENSE=	LICENSE

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

NO_CONFIGURE=		yes
NO_BUILD=		yes
USE_LANGUAGES=	# none

FONTS_DIRS.ttf=		lib/X11/fonts/TTF

INSTALLATION_DIRS+=	share/doc/thabit ${FONTS_DIRS.ttf}

do-install:
	${INSTALL_DATA} ${WRKSRC}/README 		 \
		 ${DESTDIR}${PREFIX}/share/doc/thabit
	${INSTALL_DATA} ${WRKSRC}/Mothanna.ttf		 \
		 ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/Mothanna-Bold.ttf	  \
		 ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/Mothanna-Oblique.ttf      \
		 ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/Mothanna-Bold-Oblique.ttf \
		 ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
