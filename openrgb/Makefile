# $NetBSD$

DISTNAME=	OpenRGB-release_0.9
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITLAB:=CalcProgrammer1/OpenRGB/-/archive/release_0.9/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	https://openrgb.org/
COMMENT=	Control RGB LED lights
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	c c++

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QTDIR}/bin/qmake \
	    -unix -recursive OpenRGB.pro \
	    ${MAKE_ENV} \
	    QMAKE_CFLAGS=${CFLAGS:Q} \
	    QMAKE_CXXFLAGS=${CXXFLAGS:Q} \
	    QMAKE_LFLAGS=${LDFLAGS:Q}

.include "../../mk/bsd.prefs.mk"


.include "../../comms/libhidapi/buildlink3.mk"
.include "../../security/mbedtls/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
