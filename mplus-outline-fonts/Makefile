# $NetBSD: Makefile,v 1.7 2010/11/05 01:37:51 obache Exp $
#

DISTNAME=	mplus-TESTFLIGHT-034
PKGNAME=	${DISTNAME:S/-TESTFLIGHT-/-outline-fonts-0pre/}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=mplus-fonts/6650/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://mplus-fonts.sourceforge.jp/mplus-outline-fonts/index-en.html
COMMENT=	M+ outline fonts
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty

NO_BUILD=	yes

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf+=	${FONTDIR}

INSTALLATION_DIRS+=	${FONTDIR}

do-install:
	${RUN} cd ${WRKSRC}; 					\
	for f in *.ttf; do					\
		${INSTALL_DATA} "$${f}" ${DESTDIR}${FONTDIR};	\
	done

.include "../../mk/bsd.pkg.mk"
