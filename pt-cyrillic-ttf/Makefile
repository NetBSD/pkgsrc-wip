# $NetBSD: Makefile,v 1.6 2010/12/30 10:31:31 bubuchka Exp $
#

DISTNAME=	pt-cyrillic-ttf-2.005.20101224
CATEGORIES=	fonts
MASTER_SITES=	http://www.fontstock.com/public/
DISTFILES=	PTSans_OFL.zip PTSerifOFL.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.paratype.com/public/
COMMENT=	Public fonts for minority languages of Russia
LICENSE=	open-font-license

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
