# $NetBSD: Makefile,v 1.1.1.1 2010/06/21 21:19:36 jihbed Exp $
#

VERS=	20030208
DISTNAME=	sharif.univ_ttf
PKGNAME=	sharif-univ-ttf-${VERS}
CATEGORIES=	fonts
MASTER_SITES=	http://garr.dl.sourceforge.net/project/arabeyes/Fonts/sharif.univ/
EXTRACT_SUFX=	.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://sourceforge.net/projects/arabeyes/files/
COMMENT=	This font was created by Sharif University

WRKSRC=	${WRKDIR}
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
NO_BUILD=		yes

FONTS_DIRS.ttf=		lib/X11/fonts/TTF

INSTALLATION_DIRS+=	${FONTS_DIRS.ttf}

post-extract:
	${MV} ${WRKSRC}/sharif.univ_ttf ${WRKSRC}/sharif-univ.ttf

do-install:
	${INSTALL_DATA} ${WRKSRC}/sharif-univ.ttf	${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
