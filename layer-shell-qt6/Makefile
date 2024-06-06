# $NetBSD$

DISTNAME=	layer-shell-qt-6.0.5
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_KDE:=plasma/6.0.5/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://invent.kde.org/plasma/layer-shell-qt
COMMENT=	Qt component to allow applications to use the Wayland wl-layer-shell protocol
LICENSE=	gnu-lgpl-v3 AND cc0-1.0-universal AND mit AND modified-bsd

TOOL_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/qt6-qtwayland/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
