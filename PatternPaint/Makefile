# $NetBSD$

DISTNAME=	PatternPaint-2.1.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=Blinkinlabs/}

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://github.com/Blinkinlabs/PatternPaint
COMMENT=	Making beautiful light shows is as easy as drawing a picture
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c++
USE_LIBTOOL=	yes
EXTRACT_USING=	bsdtar
USE_TOOLS+=	bsdtar pkg-config

WRKSRC=		${WRKDIR}/${DISTNAME}/PatternPaint

CXXFLAGS+=	-std=c++11

INSTALLATION_DIRS=	bin

pre-build:
	cd ${WRKSRC} && ${BUILDLINK_PREFIX.qt5-qtbase}/qt5/bin/qmake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/PatternPaint ${DESTDIR}${PREFIX}/bin

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtserialport/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
