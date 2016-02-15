# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kiconthemes-${KF5VER}
CATEGORIES=	graphics

HOMEPAGE=	https://projects.kde.org/projects/frameworks/kiconthemes
COMMENT=	Support for icon themes
LICENSE=	gnu-lgpl-v2.1

.include "../../wip/kf5/Makefile.common"

USE_TOOLS+=	msgmerge

.include "../../lang/python/tool.mk"
.include "../../wip/kconfigwidgets/buildlink3.mk"
.include "../../wip/kitemviews/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
#BUILDLINK_DEPMETHOD.qt5-qttools= build
#.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
