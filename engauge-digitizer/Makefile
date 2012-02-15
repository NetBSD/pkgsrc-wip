# $NetBSD: Makefile,v 1.1.1.1 2012/02/15 15:07:12 slitvinov Exp $
#

DISTNAME=	digit-src-4_1
PKGNAME=	engauge-digitilizer-4.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=digitizer/files/Engauge%20Digitizer/digitizer-4.1/}

MAINTAINER=	slitvinov@gmail.com
HOMEPAGE=	http://digitizer.sourceforge.net/
COMMENT=	Converts an image file with graph or map into numbers
LICENSE=	gnu-gpl-v2


PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/engauge
USE_LANGUAGES=	c++

USE_TOOLS+=	gmake
QMAKE=		${QTDIR}/bin/qmake

do-configure:
	cd ${WRKSRC} && \
	${QMAKE} -unix digitizer.pro ${CONFIG_OPTIONS} ${MAKE_ENV}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/engauge ${PREFIX}/bin


# needs qcanvas.h
# http://doc.qt.nokia.com/qq/qq21-portingcanvas.html#portingfromqcanvastographicsview
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
