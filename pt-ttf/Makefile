# $NetBSD: Makefile,v 1.3 2012/10/05 13:52:03 asau Exp $
#

DISTNAME=	pt-ttf-2.004.20120328
CATEGORIES=	fonts
MASTER_SITES=	http://www.fontstock.com/public/
DISTFILES=	PTSansOFL.zip PTSerifOFL.zip PTMonoOFL.zip

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	http://www.paratype.com/public/
COMMENT=	Public fonts for minority languages of Russia
LICENSE=	open-font-license

USE_LANGUAGES=	# none
NO_BUILD=	yes

WRKSRC=		${WRKDIR}

FONTDIR=		${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf+=	${FONTDIR}
INSTALLATION_DIRS+=	${FONTDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
