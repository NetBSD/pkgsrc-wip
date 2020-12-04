# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kscreen-${PLASMAVER}
PKGREVISION=	1
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	KDE screen management software
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/plasma5.mk"

DEPENDS+=	qt5-qtgraphicaleffects-[0-9]*:../../x11/qt5-qtgraphicaleffects

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		qlc
SUBST_STAGE.qlc=	pre-configure
SUBST_MESSAGE.qlc=	Move to new KDE location
SUBST_FILES.qlc=	CMakeLists.txt
SUBST_SED.qlc=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_LOGGINGCATEGORIESDIR}:'

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../x11/plasma-framework/buildlink3.mk"
.include "../../wip/libkscreen/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
