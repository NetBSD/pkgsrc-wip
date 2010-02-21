# $NetBSD: Makefile,v 1.3 2010/02/21 12:41:02 ryo-on Exp $

DISTNAME=		mskbdb11
PKGNAME=		${DISTNAME:S/mskbd/misaki-fonts-/}
CATEGORIES=		fonts x11 japanese
MASTER_SITES=		http://www.geocities.jp/littlimi/arc/misaki/

MAINTAINER=		ryo_on@yk.rim.or.jp
HOMEPAGE=		http://www.geocities.jp/littlimi/misaki.htm
COMMENT=		8x8 dots X11 bitmap font for JIS X 0208
#LICENSE=		M-plus font license

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}
USE_X11BASE=		YES
NO_CONFIGURE=		YES
USE_TOOLS+=		bdftopcf gzip

DOCSDIR=		${PREFIX}/share/doc/${PKGBASE}
FONTDIR=		${PREFIX}/lib/X11/fonts/local
FONTS_DIRS.x11=		${FONTDIR}

INSTALLATION_DIRS=	lib/X11/fonts/local \
			${DOCSDIR}

INSTALL_FONTS=		misaki.bdf \
			misakimn.bdf \
			4x8.bdf \
			4x8_8859.bdf
INSTALL_DOCS=		msk_b11.txt \
			msk_bdf.txt

do-build:
.for filename in ${INSTALL_FONTS}
	bdftopcf  -o ${WRKSRC}/${filename:S/bdf/pcf/} ${WRKSRC}/${filename}
	${GZIP_CMD} ${WRKSRC}/${filename:S/bdf/pcf/}
.endfor

do-install:
.for filename in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${DESTDIR}${DOCSDIR}
.endfor
.for filename in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${filename:S/bdf/pcf.gz/} ${DESTDIR}${FONTDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
