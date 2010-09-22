# $NetBSD: Makefile,v 1.1.1.1 2010/09/22 21:30:06 ryo-on Exp $
#

DISTNAME=	motoya-fonts-20100923
CATEGORIES=	fonts japanese
MASTER_SITES=	http://ryo-on.users.sourceforge.net/distrib/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryo_on@yk.rim.or.jp
HOMEPAGE=	http://www.motoya.co.jp/
COMMENT=	Motoya Cider and Mulberry fonts
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
USE_X11BASE=	YES
NO_BUILD=	YES

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALLATION_DIRS=	lib/X11/fonts/TTF

INSTALL_FONTS=	MTLc3m.ttf \
		MTLmr3m.ttf

do-install:
.for filename in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${filename} ${DESTDIR}${FONTDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
