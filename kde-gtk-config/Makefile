# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kde-gtk-config-${PLASMAVER}
CATEGORIES=	misc

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	Plasma5 GTK2 and GTK3 Configurator
LICENSE=	gnu-lgpl-v2.1

.include "../../wip/kde5/plasma.mk"

CMAKE_ARGS+=	-DBUILDLINK_DIR=${BUILDLINK_DIR}

DEPENDS+=	kde-cli-tools-[0-9]*:../../wip/kde-cli-tools

USE_TOOLS+=	msgmerge pkg-config

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	post-patch
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{CONFIG_INSTALL_DIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/cgcgtk3.knsrc \
		${PKG_SYSCONFDIR}/xdg/cgcgtk3.knsrc
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/cgctheme.knsrc \
		${PKG_SYSCONFDIR}/xdg/cgctheme.knsrc

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
