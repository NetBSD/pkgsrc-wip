# $NetBSD: Makefile,v 1.2 2012/10/05 11:12:55 asau Exp $

DISTNAME=	phonon-backend-xine-4.4.4
CATEGORIES=	multimedia
MASTER_SITES=	${MASTER_SITE_KDE:=phonon/phonon-backend-xine/4.4.4/src/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	https://phonon.kde.org
COMMENT=	Multimedia API for KDE and QT - xine backend
LICENSE=	gnu-lgpl-v2.1

# BUILD_MAKE_FLAGS+= VERBOSE=1

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CMAKE_ARG_PATH=	..
CONFIGURE_DIRS=	_build
#CMAKE_ARGS+=	-DWITH_PulseAudio:BOOL=OFF

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/
	${MKDIR} ${WRKSRC}/_build

BUILDLINK_ABI_DEPENDS.xine-lib?=       xine-lib>=1.1.19nb1
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../multimedia/phonon/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
