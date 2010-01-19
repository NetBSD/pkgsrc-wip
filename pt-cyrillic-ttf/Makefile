# $NetBSD: Makefile,v 1.2 2010/01/19 15:56:22 bubuchka Exp $
#

DISTNAME=	pt-cyrillic-ttf-1.0.20100112
CATEGORIES=	fonts
MASTER_SITES=	http://www.fontstock.com/public/
DISTFILES=	PTSans.zip # PTSerif.zip (still under construction)

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.paratype.ru/public/
COMMENT=	Public fonts with Russia national alphabets support
#LICENSE=	http://www.paratype.ru/public/pt_openlicense_eng.asp

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
