# $NetBSD: Makefile,v 1.2 2010/09/16 23:46:25 thomasklausner Exp $

DISTNAME=	lateef.shaikh_fonts
PKGNAME=	lateef-shaikh-ttf-${VERS}
VERS=		20030228
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arabeyes/Fonts/lateef.shaikh_fonts/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
#HOMEPAGE=	http://garr.dl.sourceforge.net/project/arabeyes/Fonts/lateef.shaikh_fonts/
COMMENT=	Arabic font by Lateef Shaikh

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
