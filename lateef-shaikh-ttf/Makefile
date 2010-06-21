# $NetBSD: Makefile,v 1.1.1.1 2010/06/21 21:16:36 jihbed Exp $
#

VERS=	20030228
DISTNAME=	lateef.shaikh_fonts
PKGNAME=	lateef-shaikh-ttf-${VERS}
CATEGORIES=	fonts
MASTER_SITES=	http://garr.dl.sourceforge.net/project/arabeyes/Fonts/lateef.shaikh_fonts/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://garr.dl.sourceforge.net/project/arabeyes/Fonts/lateef.shaikh_fonts/
COMMENT=	Lateef Shaikh fonts

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

NO_BUILD=	yes

FONTS_DIRS.ttf=		lib/X11/fonts/TTF

INSTALLATION_DIRS=	share/doc/lateef-shaikh-ttf ${FONTS_DIRS.ttf}

do-install:
	${INSTALL_DATA} ${WRKSRC}/License.txt 		 \
		 ${DESTDIR}${PREFIX}/share/doc/lateef-shaikh-ttf
	${INSTALL_DATA} ${WRKSRC}/Naqsh.ttf	 \
		 ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
