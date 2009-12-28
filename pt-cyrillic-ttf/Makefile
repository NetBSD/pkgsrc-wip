# $NetBSD: Makefile,v 1.1.1.1 2009/12/28 14:29:09 bubuchka Exp $
#

DISTNAME=	pt-cyrillic-ttf-1.0.20091225
CATEGORIES=	fonts
MASTER_SITES=	http://www.fontstock.com/public/
DISTFILES=	PTSans.zip # PTSerif.zip (not released yet)

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fonts.ru/public/
COMMENT=	Public fonts with Russia national alphabets support
#LICENSE=	http://fonts.ru/public/pt_openlicense.asp

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

FONTDIR=		${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf+=	${FONTDIR}
INSTALLATION_DIRS+=	${FONTDIR}

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
