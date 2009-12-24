# $NetBSD: Makefile,v 1.1.1.1 2009/12/24 13:28:58 ryo-on Exp $
#

DISTNAME=	umefont-410
PKGNAME=	umefont-0.410
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=ume-font/22212/}

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://sourceforge.jp/projects/ume-font/wiki/FrontPage
COMMENT=	Ume 18 Japanese fonts (Mincho and Gothic) 
# LICENSE=	M+ FONTS License

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=    YES
NO_CONFIGURE=   YES
NO_BUILD=       YES

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	lib/X11/fonts/TTF \
			${DOCSDIR}
FONTS_DIRS.ttf= ${PREFIX}/lib/X11/fonts/TTF

INSTALL_FONTS=	ume-pgc4.ttf \
		ume-pgc5.ttf \
		ume-pgo4.ttf \
		ume-pgo5.ttf \
		ume-pgs4.ttf \
		ume-pgs5.ttf \
		ume-pmo3.ttf \
		ume-pms3.ttf \
		ume-tgc4.ttf \
		ume-tgc5.ttf \
		ume-tgo4.ttf \
		ume-tgo5.ttf \
		ume-tgs4.ttf \
		ume-tgs5.ttf \
		ume-tmo3.ttf \
		ume-tms3.ttf \
		ume-ugo4.ttf \
		ume-ugo5.ttf
INSTALL_DOCS=	license.html

USE_LANGUAGES=	# none

do-install:
.for fontfile in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${fontfile} ${DESTDIR}${FONTS_DIRS.ttf}
.endfor
.for docfile in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
