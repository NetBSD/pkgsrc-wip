# $NetBSD: Makefile,v 1.4 2013/04/08 02:20:18 othyro Exp $
#

DISTNAME=	Thabit-0.02
PKGNAME=	thabit-ttf-0.02
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arabeyes/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://www.arabeyes.org/project.php?proj=Khotot
COMMENT=	Thabit (from Arabic:fixed) is a fixed width OpenType font family
LICENSE=	ofl-v1.1

NO_CONFIGURE=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# none

FONTS_DIRS.ttf=		lib/X11/fonts/TTF

INSTALLATION_DIRS+=	share/doc/thabit-fonts ${FONTS_DIRS.ttf}

do-install:
	${INSTALL_DATA} ${WRKSRC}/README 		 \
		 ${DESTDIR}${PREFIX}/share/doc/thabit-fonts
	${INSTALL_DATA} ${WRKSRC}/Thabit.ttf		 \
		 ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/Thabit-Bold.ttf	  \
		 ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/Thabit-Oblique.ttf      \
		 ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/Thabit-Bold-Oblique.ttf \
		 ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
