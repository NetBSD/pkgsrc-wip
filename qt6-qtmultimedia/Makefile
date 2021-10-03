# $NetBSD$

DISTNAME=	qtmultimedia-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtmultimedia-${QTVERSION}
COMMENT=	Qt6 module with multimedia
CATEGORIES=	multimedia
LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

CONFIGURE_ARGS+=	-no-alsa

.include "options.mk"

.include "../../wip/qt6-qtbase/Makefile.common"


.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtdeclarative/buildlink3.mk"
.include "../../wip/qt6-qtshadertools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
