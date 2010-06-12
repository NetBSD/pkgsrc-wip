# $NetBSD: Makefile,v 1.1.1.1 2010/06/12 23:27:13 jihbed Exp $
#

DISTNAME=	ttf-sil-scheherazade_1.001.orig
PKGNAME=	sil-scheherazade-ttf-1.001
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/t/ttf-sil-scheherazade/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	http://scripts.sil.org/ArabicFonts
COMMENT=	Smart unicode font for arabic

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/ttf-sil-scheherazade-1.001
USE_LANGUAGES=	# none

NO_BUILD=	yes

DOCDIR=	${PREFIX}/share/doc/sil-scheherazade-ttf
FONTDIR=	${PREFIX}/lib/X11/fonts/TTF

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTDIR}
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ScheherazadeRegOT.ttf ${DESTDIR}${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
