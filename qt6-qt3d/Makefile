# $NetBSD$

DISTNAME=	qt3d-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qt3d-${QTVERSION}
COMMENT=	Qt6 3d
CATEGORIES=	graphics

QT_ADDLIB=	qt3d

CONFIGURE_ARGS+=	-system-assimp
CONFIGURE_ARGS+=	-no-fbxsdk

.include "../../wip/qt6-qtbase/Makefile.common"

.include "../../multimedia/assimp/buildlink3.mk"
.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtdeclarative/buildlink3.mk"
.include "../../wip/qt6-qtshadertools/buildlink3.mk"
.include "../../wip/qt6-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
