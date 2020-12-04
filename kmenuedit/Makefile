# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kmenuedit-${PLASMAVER}
PKGREVISION=	1
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	KDE menu editor
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../meta-pkgs/kde/plasma5.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	khotkeys>=${PLASMAVER}:../../wip/khotkeys

USE_TOOLS+=	msgmerge

SUBST_CLASSES+=		qlc
SUBST_STAGE.qlc=	pre-configure
SUBST_MESSAGE.qlc=	Move to new KDE location
SUBST_FILES.qlc=	CMakeLists.txt
SUBST_SED.qlc=		-e 's:{KDE_INSTALL_CONFDIR}:{KDE_INSTALL_LOGGINGCATEGORIESDIR}:'

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/kdelibs4support/buildlink3.mk"
#.include "../../wip/plasma-workspace/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
