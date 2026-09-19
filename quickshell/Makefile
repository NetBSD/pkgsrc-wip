# $NetBSD$

DISTNAME=	quickshell-0.3.1
CATEGORIES=	wayland
MASTER_SITES=	https://git.outfoxxed.me/quickshell/quickshell/archive/
DISTFILES=	v${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	kikadf@NetBSD.org
HOMEPAGE=	https://quickshell.org/
COMMENT=	Building blocks for your desktop
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/quickshell

CMAKE_GENERATOR=	ninja

CMAKE_CONFIGURE_ARGS+=	-DDISTRIBUTOR="pkgsrc"
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_CONFIGURE_ARGS+=	-DCRASH_HANDLER=OFF
CMAKE_CONFIGURE_ARGS+=	-DINSTALL_QMLDIR="${QTDIR}"
CMAKE_CONFIGURE_ARGS+=	-DSERVICE_PIPEWIRE=OFF

.include "../../devel/cmake/build.mk"
.include "../../devel/CLI11/buildlink3.mk"
.include "../../devel/jemalloc/buildlink3.mk"
.include "../../devel/qt6-qtwayland/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/qt6-qtshadertools/buildlink3.mk"
.include "../../graphics/qt6-qtsvg/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../security/polkit/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
