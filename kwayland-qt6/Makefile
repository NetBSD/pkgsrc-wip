# $NetBSD$

DISTNAME=	kwayland-6.0.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_KDE:=plasma/6.0.5/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://invent.kde.org/plasma/kwayland
COMMENT=	Qt-style Client and Server library wrapper for the Wayland libraries
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	plasma-wayland-protocols>=1.7:../../devel/plasma-wayland-protocols

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
# Don't do autotests.  Some builds are linux specific.
CMAKE_ARGS+=	-DBUILD_TESTING=no
CMAKE_ARGS+=	-DKF_IGNORE_PLATFORM_CHECK=true

.include "../../devel/wayland/platform.mk"
.if empty(PLATFORM_SUPPORTS_WAYLAND:M[Yy][Ee][Ss])
PKG_SKIP_REASON+=       "Platform does not support Wayland"
.endif

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} == "NetBSD"
# Work-around bad use-warning check in GNU ld 2.26
# Stolen from /usr/pkgsrc/meta-pkgs/kde/Makefile.common
BUILDLINK_TRANSFORM+=	rm:-Wl,--fatal-warnings
.endif

.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../devel/qt6-qtwayland/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
