# $NetBSD: Makefile,v 1.5 2013/04/08 02:20:18 othyro Exp $
#

PT_TTF_REV=	20121212
DISTNAME=	pt-ttf-2.004.${PT_TTF_REV}	# as derived from TTF files
DIST_SUBDIR=	pt-ttf-${PT_TTF_REV}
CATEGORIES=	fonts
MASTER_SITES=	http://www.fontstock.com/public/
DISTFILES=	PTSansOFL.zip PTSerifOFL.zip PTMonoOFL.zip

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	https://www.paratype.com/public/
COMMENT=	Public fonts for minority languages of Russia
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none
NO_BUILD=	yes

WRKSRC=		${WRKDIR}

FONTDIR=		${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf+=	${FONTDIR}
INSTALLATION_DIRS+=	${FONTDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
