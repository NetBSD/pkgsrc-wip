# $NetBSD: Makefile,v 1.2 2012/10/03 18:15:31 asau Exp $

DISTNAME=	lateef.shaikh_fonts
PKGNAME=	naqsh-ttf-${VERS}
VERS=		20030228
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arabeyes/Fonts/lateef.shaikh_fonts/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
COMMENT=	Arabic font by Lateef Shaikh
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

NO_BUILD=	yes

FONTS_DIRS.ttf=		lib/X11/fonts/TTF

INSTALLATION_DIRS=	share/doc/naqsh-ttf ${FONTS_DIRS.ttf}

do-install:
	${INSTALL_DATA} ${WRKSRC}/License.txt 		 \
		 ${DESTDIR}${PREFIX}/share/doc/naqsh-ttf
	${INSTALL_DATA} ${WRKSRC}/Naqsh.ttf	 \
		 ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
