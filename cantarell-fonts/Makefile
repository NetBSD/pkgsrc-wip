# $NetBSD: Makefile,v 1.2 2012/09/24 18:26:52 asau Exp $
#

DISTNAME=	cantarell-fonts-0.0.6
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/cantarell-fonts/0.0/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/CantarellFonts
COMMENT=	Contemporary Humanist sans serif designed for on-screen reading
LICENSE=	open-font-license

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	lib/X11/fonts/TTF

INSTALL_FONTS=		Cantarell-Bold.otf \
			Cantarell-Regular.otf

do-install:
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/otf/${f} ${DESTDIR}${FONTDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
