# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kde-cli-tools-${PLASMAVER}
CATEGORIES=	x11

HOMEPAGE=	https://www.kde.org/workspaces/plasmadesktop/
COMMENT=	Tools based on KDE Frameworks 5 to better interact with the system
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../wip/kde5/plasma.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge pkg-config

BUILDLINK_TRANSFORM+=	rm:-fvisibility=hidden

.include "../../devel/kcmutils/buildlink3.mk"
.include "../../x11/kactivities5/buildlink3.mk"
.include "../../x11/kdelibs4support/buildlink3.mk"
.include "../../security/kdesu/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
