# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	polkit-kde-agent-1-${PLASMAVER}
PKGNAME=	polkit-kde-agent-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	Daemon providing a polkit authentication UI for KDE
LICENSE=	gnu-gpl-v2

.include "../../wip/kde5/plasma.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../wip/kdoctools

USE_TOOLS+=	msgmerge pkg-config

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	${PREFIX}/share/examples/kde-polkit/polkit-kde-authentication-agent-1.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/polkit-kde-authentication-agent-1.desktop

.include "../../wip/kcrash/buildlink3.mk"
.include "../../wip/kdbusaddons/buildlink3.mk"
.include "../../wip/kiconthemes/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
