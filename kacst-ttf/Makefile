# $NetBSD: Makefile,v 1.2 2011/11/09 16:38:56 noud4 Exp $
#

DISTNAME=	kacst_fonts_2.01
PKGNAME=	kacst-ttf-2.01
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://garr.dl.sourceforge.net/project/arabeyes/kacst_fonts/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://sourceforge.net/projects/arabeyes/files/kacst_fonts/
COMMENT=	Truetype Arabic fonts created by KACST
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/KacstArabicFonts-2.01
USE_LANGUAGES=	# none
USE_TOOLS+=	pax
NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTS_DIRS.ttf=		lib/X11/fonts/TTF

INSTALLATION_DIRS=	${FONTS_DIRS.ttf}

do-install:
	cd ${WRKSRC} && \
		pax -rw Kacst*.ttf ${DESTDIR}${PREFIX}/${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
