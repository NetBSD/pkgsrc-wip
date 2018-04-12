# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kscreen-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	KDE screen management software
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/plasma5.mk"

DEPENDS+=	qt5-qtgraphicaleffects-[0-9]*:../../x11/qt5-qtgraphicaleffects

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		xdg
SUBST_STAGE.xdg=	pre-configure
SUBST_MESSAGE.xdg=	Install via examples dir.
SUBST_FILES.xdg=	CMakeLists.txt
SUBST_SED.xdg=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_XDG_EX_DIR}:'

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdg
CONF_FILES+=	${PREFIX}/share/examples/kde-xdg/kscreen.categories \
		${PKG_SYSCONFDIR}/xdg/kscreen.categories

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../wip/libkscreen/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
