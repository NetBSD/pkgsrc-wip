# $NetBSD: Makefile,v 1.1.1.1 2010/02/10 11:50:46 obache Exp $
#

DISTNAME=	mplus_bitmap_fonts-2.2.4
PKGNAME=	${DISTNAME:S/_/-/g}
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=mplus-fonts/5030/}

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://mplus-fonts.sourceforge.jp/mplus-bitmap-fonts/index.html
COMMENT=	Simple and highly readable bitmap fonts
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
USE_TOOLS+=	perl gzip bdftopcf patch

REPLACE_PERL=	mkbold

NO_BUILD=	yes

FONTDIR=	${PREFIX}/lib/X11/fonts/mplus
FONTS_DIRS.x11=	${FONTDIR}

do-install:
	${RUN} cd ${WRKSRC}; \
	${SETENV} ${ALL_ENV} DESTDIR=${DESTDIR}${FONTDIR} \
		${SH} install_mplus_fonts

.include "../../mk/bsd.pkg.mk"
