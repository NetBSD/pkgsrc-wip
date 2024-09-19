# $NetBSD$

DISTNAME=	noto-cjk-1.004
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=googlei18n/}
GITHUB_PROJECT=	noto-cjk
GITHUB_TAG=	v1.004

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.google.com/get/noto/help/cjk
COMMENT=	Noto CJK fonts
LICENSE=	ofl-v1.1

USE_LANGUAGES=	# none
NO_BUILD=	yes

FONTDIR=	${PREFIX}/share/fonts/X11/OTF
FONTS_DIRS.otf=	${FONTDIR}

INSTALLATION_DIRS=	share/fonts/X11/OTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.otf ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
