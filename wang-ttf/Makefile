# $NetBSD: Makefile,v 1.2 2004/12/28 14:41:04 thomasklausner Exp $

DISTNAME=	wang-ttf-1.3
PKGREVISION=	1
CATEGORIES=	fonts chinese
MASTER_SITES=	ftp://cle.linux.org.tw/pub/fonts/wangfonts/ \
		ftp://cle.linux.org.tw/pub/fonts/wangfonts/WCL/
DISTFILES=	${FONT_FILES} ${MISC_FILES}

MAINTAINER=	rxg@NetBSD.org
COMMENT=	Chinese TrueType fonts made by Dr. Hann-Tzong Wang

FONT_FILES=	wp010-05.ttf wp010-08.ttf wp110-05.ttf wp110-08.ttf \
		wp210-05.ttf wp210-08.ttf wp310-05.ttf wp310-08.ttf \
		wt001.ttf wt002.ttf wt003.ttf wt004.ttf wt005.ttf \
		wt006.ttf wt009.ttf wt011.ttf wt014.ttf wt021.ttf \
		wt024.ttf wt028.ttf wt034.ttf wt040.ttf wt064.ttf \
		wt071.ttf wtcc02.ttf wtcc15.ttf wtg-06cut1x.ttf \
		wthc06.ttf wts11.ttf wts43.ttf wts47.ttf wts55.ttf \
		WCL-01.ttf WCL-02.ttf WCL-03.ttf WCL-04.ttf WCL-05.ttf \
		WCL-06.ttf WCL-07.ttf WCL-08.ttf WCL-09.ttf WCL-10.ttf
MISC_FILES=	Changes.txt Changes-WCL.txt README.b5

DIST_SUBDIR=	wang-ttf
EXTRACT_ONLY=	# empty

USE_X11BASE=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTS_TTF_DIRS=	${PREFIX}/lib/X11/fonts/TTF
DOCDIR=		${PREFIX}/share/doc/wang-ttf

do-install:
	${INSTALL_DATA_DIR} ${FONTS_TTF_DIRS}
	for f in ${FONT_FILES}; do \
		${INSTALL_DATA} ${_DISTDIR}/$$f ${FONTS_TTF_DIRS}; \
	done
	${INSTALL_DATA_DIR} ${DOCDIR}
	for f in ${MISC_FILES}; do \
		${INSTALL_DATA} ${_DISTDIR}/$$f ${DOCDIR}; \
	done

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
