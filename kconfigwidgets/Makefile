# $NetBSD: Makefile,v 1.25 2016/01/10 20:01:05 markd Exp $

DISTNAME=	kconfigwidgets-${KF5VER}
CATEGORIES=	x11

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Widgets for KConfig
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

.include "../../wip/kf5/Makefile.common"

BUILD_DEPENDS+= kdoctools>=${KF5VER}:../../wip/kdoctools

USE_TOOLS+=	perl:run

REPLACE_PERL+=	src/preparetips5

.include "../../lang/python/tool.mk"
.include "../../wip/kauth/buildlink3.mk"
.include "../../wip/kcodecs/buildlink3.mk"
.include "../../wip/kconfig/buildlink3.mk"
.include "../../wip/kguiaddons/buildlink3.mk"
.include "../../wip/ki18n/buildlink3.mk"
.include "../../wip/kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
