# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kdewebkit-${KF5VER}
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	KDE Integration for QtWebKit
LICENSE=	gnu-lgpl-v2.1

.include "../../wip/kf5/Makefile.common"

USE_TOOLS+=	msgmerge

.include "../../wip/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtwebkit/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
