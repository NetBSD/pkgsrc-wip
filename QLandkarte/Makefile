# $NetBSD: Makefile,v 1.3 2008/07/12 18:47:54 guigui2 Exp $
#

DISTNAME=	QLandkarte_0.7.3
PKGNAME=	QLandkarte-0.7.3

CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qlandkarte/}

MAINTAINER=	netbsd@guigui2.net
HOMEPAGE=	http://qlandkarte.sourceforge.net/
COMMENT=	QLandkarte is a Garmin GPS data visualization and managing tool

USE_LANGUAGES=	c++
USE_LIBTOOL=	yes
GNU_CONFIGURE=yes
USE_TOOLS+=	perl

CONFIGURE_ARGS= --with-qt-dir=${PREFIX}/qt4 \
                --with-extra-libs=${PREFIX}/lib \
                --with-extra-includes=${PREFIX}/include \
                --enable-release

pre-configure:
	perl -pi -e 's,\/usr,${PREFIX},g'\
		${WRKSRC}/src/src.pro
	perl -pi -e 's,!!QLANDKARTE_BINDIR!!,${PREFIX}/bin,g' \
                ${WRKSRC}/src/src.pro
	perl -pi -e 's,\$$\$$\{QLANDKARTE_LIBDIR\},\
                ${PREFIX}/lib/qlandkarte,g' \
                ${WRKSRC}/src/device/*/*.pro

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../misc/proj/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
