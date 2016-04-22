# $NetBSD$

DISTNAME=	xinput_calibrator-0.7.5
CATEGORIES=	x11
MASTER_SITES=	http://github.com/downloads/tias/xinput_calibrator/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.freedesktop.org/wiki/Software/xinput_calibrator/
COMMENT=	Generic touchscreen calibration program for X.Org
LICENSE=	x11 AND cc-by-sa-v3.0

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/inputproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
