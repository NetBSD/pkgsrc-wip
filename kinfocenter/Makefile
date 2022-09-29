# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kinfocenter-${PLASMAVER}
CATEGORIES=	sysutils

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	Utility that provides information about a computer system
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/plasma5.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	kcontrol/menus/CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_SYSCONFDIR}/xdg:{KDE_INSTALL_XDG_EX_DIR}:'

CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/menus/kinfocenter.menu \
		${PKG_SYSCONFDIR}/xdg/menus/kinfocenter.menu

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.pciutils+=	pciutils>=3.8
.include "../../sysutils/pciutils/buildlink3.mk"
.include "../../devel/kcmutils/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../x11/kdelibs4support/buildlink3.mk"
.include "../../devel/kwayland/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../x11/plasma-framework/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
