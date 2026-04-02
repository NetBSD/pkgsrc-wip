# $NetBSD: Makefile,v 1.50 2026/02/06 10:06:16 wiz Exp $

.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	lxqt-wayland-session-0.3.2
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-wayland-session/
COMMENT=	Files needed for the LXQt Wayland Session
LICENSE=	gnu-lgpl-v2.1 AND gnu-lgpl-v2 AND gnu-lgpl-v3 AND \
		mit AND modified-bsd AND cc-by-sa-v4.0

USE_TOOLS+=	pkg-config perl

REPLACE_SH=	lxqt-qdbus.in

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fix path
SUBST_FILES.path=	CMakeLists.txt
SUBST_VARS.path+=	PKG_SYSCONFDIR

TOOL_DEPENDS+=	lxqt-build-tools>=2.3.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools
DEPENDS+=	qtxdg-tools>=4.0.0:../../x11/qtxdg-tools
DEPENDS+=	xdg-user-dirs-[0-9]*:../../x11/xdg-user-dirs
DEPENDS+=	lxqt-session-[0-9]*:../../x11/lxqt-session

.include "../../x11/plasma6-layer-shell-qt/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
