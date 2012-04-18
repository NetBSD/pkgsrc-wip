# $NetBSD: Makefile,v 1.8 2012/04/18 11:28:40 bubuchka Exp $
#

DISTNAME=	pt-cyrillic-ttf-2.005.20120328
CATEGORIES=	fonts
MASTER_SITES=	http://www.fontstock.com/public/
DISTFILES=	PTSans_OFL.zip PTSerifOFL.zip PTMonoOFL.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.paratype.com/public/
COMMENT=	Public fonts for minority languages of Russia
LICENSE=	open-font-license

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
NO_BUILD=	yes

WRKSRC=		${WRKDIR}

FONTDIR=		${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf+=	${FONTDIR}
INSTALLATION_DIRS+=	${FONTDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
