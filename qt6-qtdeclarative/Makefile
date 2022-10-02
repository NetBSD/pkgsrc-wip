# $NetBSD$

DISTNAME=	qtdeclarative-everywhere-src-${QTVERSION}
PKGNAME=	qt6-qtdeclarative-${QTVERSION}
COMMENT=	Qt6 module for declarative framework
CATEGORIES=	x11

LICENSE=	gnu-lgpl-v3 OR gnu-gpl-v2 OR gnu-gpl-v3

.include "../../wip/qt6-qtbase/Makefile.common"

PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6LabsAnimation.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6LabsFolderListModel.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6LabsQmlModels.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6LabsSettings.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6LabsSharedImage.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6LabsWavefrontMesh.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Qml.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QmlCore.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QmlLocalStorage.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QmlModels.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QmlWorkerScript.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QmlXmlListModel.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6Quick.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QuickControls2.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QuickControls2Impl.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QuickDialogs2.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QuickDialogs2QuickImpl.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QuickDialogs2Utils.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QuickLayouts.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QuickTemplates2.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QuickTest.pc
PKGCONFIG_OVERRIDE+=	lib/pkgconfig/Qt6QuickWidgets.pc

.include "../../lang/python/tool.mk"
.include "../../wip/qt6-qtbase/buildlink3.mk"
.include "../../wip/qt6-qtlanguageserver/buildlink3.mk"
.include "../../wip/qt6-qtshadertools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
