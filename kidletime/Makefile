# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kidletime-${KF5VER}
CATEGORIES=	x11

HOMEPAGE=	https://projects.kde.org/projects/frameworks/kidletime
COMMENT=	Monitoring user activity
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../wip/kf5/Makefile.common"

USE_TOOLS+=	pkg-config

.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
