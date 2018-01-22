# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	systemsettings-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	KDE system settings
LICENSE=	gnu-gpl-v2 AND gnu-fdl-v1.2

.include "../../wip/kde5/plasma.mk"

CONFLICTS+=	kde-workspace4-[0-9]*

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/kcmutils/buildlink3.mk"
.include "../../www/khtml/buildlink3.mk"
.include "../../x11/kactivities-stats/buildlink3.mk"
.include "../../x11/kirigami2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
