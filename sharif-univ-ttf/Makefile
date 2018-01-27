# $NetBSD: Makefile,v 1.3 2012/11/12 16:26:52 othyro Exp $
#

VERS=		20030208
DISTNAME=	sharif.univ_ttf
PKGNAME=	sharif-univ-ttf-${VERS}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=arabeyes/}
EXTRACT_SUFX=	.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://sourceforge.net/projects/arabeyes/files/
COMMENT=	This font was created by Sharif University

WRKSRC=	${WRKDIR}

USE_LANGUAGES=	# none
NO_BUILD=	yes

FONTS_DIRS.ttf=		lib/X11/fonts/TTF

INSTALLATION_DIRS+=	${FONTS_DIRS.ttf}

post-extract:
	${MV} ${WRKSRC}/sharif.univ_ttf ${WRKSRC}/sharif-univ.ttf

do-install:
	${INSTALL_DATA} ${WRKSRC}/sharif-univ.ttf	${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
