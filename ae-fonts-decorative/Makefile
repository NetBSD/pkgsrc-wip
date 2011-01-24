# $NetBSD: Makefile,v 1.1.1.1 2011/01/24 09:33:43 jihbed Exp $
#

DISTNAME=	ae_fonts_decorative-${VERSION}
PKGNAME=	ae-fonts-decorative-${VERSION}
CATEGORIES=	fonts
MASTER_SITES=	http://garr.dl.sourceforge.net/project/arabeyes/Fonts/ae_fonts/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://projects.arabeyes.org/project.php?proj=Khotot
COMMENT=	Other collection of PCF fonts that include Arabic glyphs
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

VERSION=	2.1
NO_BUILD=	yes
USE_LANGUAGES=	# none

FONT_FILES=	ae_AlArabiya.ttf ae_AlBattar.ttf ae_AlHor.ttf ae_AlManzomah.ttf 			\
			ae_Cortoba.ttf ae_Dimnah.ttf ae_Electron.ttf ae_Furat.ttf ae_Granada.ttf 	\
			ae_Graph.ttf ae_Hani.ttf ae_Hor.ttf ae_Japan.ttf ae_Jet.ttf ae_Kayrawan.ttf 	\
			ae_Khalid.ttf ae_Mashq-Bold.ttf ae_Mashq.ttf ae_Metal.ttf ae_Nada.ttf		\
			ae_Nagham.ttf ae_Nagham.ttf ae_Ostorah.ttf ae_Ouhod-Bold.ttf ae_Petra.ttf  \
			ae_Rasheeq-Bold.ttf ae_Rehan.ttf ae_Salem.ttf ae_Shado.ttf ae_Sharjah.ttf   \
			ae_Sindbad.ttf ae_Tarablus.ttf ae_Tholoth.ttf

FONTDIR=		${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf+=	${FONTDIR}

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTDIR}
	for a in ${FONT_FILES}; do \
		${INSTALL_DATA} ${WRKSRC}/$$a ${DESTDIR}${FONTDIR}/$$a; \
	done

.include "../../mk/bsd.pkg.mk"
