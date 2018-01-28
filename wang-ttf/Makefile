# $NetBSD: Makefile,v 1.8 2012/10/07 20:11:06 asau Exp $

DISTNAME=	wang-ttf-1.3
PKGREVISION=	5
CATEGORIES=	fonts chinese
MASTER_SITES=	${MASTER_SITE_FREEBSD:=zh-wangttf/} \
		ftp://cle.linux.org.tw/pub/fonts/wangfonts/ \
		http://nirc.encntc.edu.tw/web/fonts/wang/v040326/ \
		http://apt.nc.hcc.edu.tw/pub/FreeSoftware/free_fonts/wangttf/ \
		http://apt.nc.hcc.edu.tw/pub/FreeSoftware/free_fonts/wangttf/WCL/
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

NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTS_DIRS.ttf+=	${PREFIX}/lib/X11/fonts/TTF
REQD_DIRS+=		${PREFIX}/lib/X11/fonts/TTF
DOCDIR=			${PREFIX}/share/doc/wang-ttf

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${FONTS_DIRS.ttf}
	for f in ${FONT_FILES}; do \
		${INSTALL_DATA} ${_DISTDIR}/$$f ${DESTDIR}${FONTS_DIRS.ttf}; \
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}
	for f in ${MISC_FILES}; do \
		${INSTALL_DATA} ${_DISTDIR}/$$f ${DESTDIR}${DOCDIR}; \
	done

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
