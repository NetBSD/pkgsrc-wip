# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	breeze-${PLASMAVER}
CATEGORIES=	graphics

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	Artwork, styles and assets for the Breeze visual style for the Plasma Desktop
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v3

.include "../../meta-pkgs/kde/plasma5.mk"

DEPENDS+=	breeze-icons>=5.19.0:../../graphics/breeze-icons

USE_TOOLS+=	msgmerge pkg-config

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/frameworkintegration/buildlink3.mk"
.include "../../wip/kdecoration/buildlink3.mk"
.include "../../devel/kwayland/buildlink3.mk"
.include "../../devel/kcmutils/buildlink3.mk"
.include "../../x11/kirigami2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
