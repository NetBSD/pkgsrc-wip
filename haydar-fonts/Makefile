# $NetBSD: Makefile,v 1.1.1.1 2010/06/21 21:15:47 jihbed Exp $
#

VERS=	20030228
DISTNAME=	haydar_fonts
PKGNAME=	haydar-ttf-${VERS}
CATEGORIES=	fonts
MASTER_SITES=	http://garr.dl.sourceforge.net/project/arabeyes/Fonts/haydar_fonts/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://garr.dl.sourceforge.net/project/arabeyes/Fonts/haydar_fonts/
COMMENT=	Free X11 fonts (BDF format) for HaydarLinux

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/fonts
NO_BUILD=	yes
USE_TOOLS+=	bdftopcf

USE_LANGUAGES=	# none

FONTS_DIR=	${PREFIX}/lib/X11/fonts/haydar-fonts
REQD_DIRS+=		${FONTS_DIR}/bdf

INSTALLATION_DIRS=	${FONTS_DIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/haydar-*.bdf 	${DESTDIR}${FONTS_DIR}


.include "../../mk/bsd.pkg.mk"
