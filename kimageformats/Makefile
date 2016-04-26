# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kimageformats-${KF5VER}
CATEGORIES=	graphics

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Image format plugins for Qt5
LICENSE=	gnu-lgpl-v2.1

.include "../../wip/kf5/Makefile.common"

USE_TOOLS+=	pkg-config

.include "../../wip/karchive/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
