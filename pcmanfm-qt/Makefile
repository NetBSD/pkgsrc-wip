# $NetBSD: Makefile,v 1.37 2024/04/06 08:06:44 wiz Exp $

DISTNAME=	pcmanfm-qt-2.0.0
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=lxqt/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/pcmanfm-qt/
COMMENT=	LXQt pcmanfm Qt frontend
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config perl
USE_LANGUAGES=	c c++

LDFLAGS.SunOS+=	-lsocket

AUTOSTART_CONF=		share/examples/autostart
SETTINGS_CONF=		share/examples/pcmanfm-qt/lxqt
PKG_SYSCONFSUBDIR=	xdg
MAKE_DIRS+=		${PKG_SYSCONFDIR}/autostart \
			${PKG_SYSCONFDIR}/pcmanfm-qt/lxqt

CONF_FILES+=		${AUTOSTART_CONF}/lxqt-desktop.desktop \
			${PKG_SYSCONFDIR}/autostart/lxqt-desktop.desktop
CONF_FILES+=		${SETTINGS_CONF}/settings.conf \
			${PKG_SYSCONFDIR}/pcmanfm-qt/lxqt/settings.conf

DEPENDS+=	lxqt-menu-data-[0-9]*:../../wip/lxqt-menu-data
TOOL_DEPENDS+=	lxqt-build-tools>=2.0.0:../../wip/lxqt2-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../wip/liblxqt/buildlink3.mk"
.include "../../wip/libfm-qt/buildlink3.mk"
.include "../../wip/layer-shell-qt6/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
