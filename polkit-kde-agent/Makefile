# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	polkit-kde-agent-1-${PLASMAVER}
PKGNAME=	polkit-kde-agent-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	Daemon providing a polkit authentication UI for KDE
LICENSE=	gnu-gpl-v2

.include "../../wip/kde5/plasma.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	post-patch
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{AUTOSTART_INSTALL_DIR}:{KDE_INSTALL_AUTOSTARTEXDIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg/autostart
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/autostart/polkit-kde-authentication-agent-1.desktop \
		${PKG_SYSCONFDIR}/xdg/autostart/polkit-kde-authentication-agent-1.desktop

.include "../../devel/kcrash/buildlink3.mk"
.include "../../sysutils/kdbusaddons/buildlink3.mk"
.include "../../graphics/kiconthemes/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
