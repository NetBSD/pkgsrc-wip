# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	ktextwidgets-${KF5VER}
CATEGORIES=	x11

HOMEPAGE=	https://projects.kde.org/projects/frameworks/ktextwidgets
COMMENT=	Advanced text editing widgets
LICENSE=	gnu-lgpl-v2 AND gnu-lgpl-v2.1

.include "../../wip/kf5/Makefile.common"

USE_TOOLS+=	msgmerge

.include "../../lang/python/tool.mk"
.include "../../wip/kcompletion/buildlink3.mk"
.include "../../wip/kiconthemes/buildlink3.mk"
.include "../../wip/kservice/buildlink3.mk"
.include "../../wip/sonnet/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
