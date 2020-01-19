# $NetBSD: Makefile,v 1.1 2015/02/13 21:35:00 jihbed Exp $

DISTNAME=	kacst_one_5.0
PKGNAME=	kacst-one-5.0
CATEGORIES=	fonts
MASTER_SITES=	http://garr.dl.sourceforge.net/project/arabeyes/kacst_fonts/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://sourceforge.net/projects/arabeyes/files/kacst_fonts/
COMMENT=	TrueType font designed for Arabic language
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pax
NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTS_DIRS.ttf=		lib/X11/fonts/TTF

INSTALLATION_DIRS=	${FONTS_DIRS.ttf}

do-install:
	cd ${WRKSRC} && \
		pax -rw KacstOne*.*  ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
