# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	plasma-integration-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	Integration of Qt application with KDE workspaces
LICENSE=	gnu-lgpl-v2 AND gnu-lgpl-v2.1

.include "../../wip/kde5/plasma.mk"

DEPENDS+=	noto-ttf-[0-9]*:../../fonts/noto-ttf
DEPENDS+=	Hack-ttf-[0-9]*:../../fonts/Hack-ttf
DEPENDS+=	breeze-[0-9]*:../../wip/breeze
DEPENDS+=	qqc2-desktop-style-[0-9]*:../../x11/qqc2-desktop-style

USE_TOOLS+=	msgmerge

REPLACE_PERL+=	src/platformtheme/*.pl

.include "../../devel/kio/buildlink3.mk"
.include "../../wip/kwayland/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
